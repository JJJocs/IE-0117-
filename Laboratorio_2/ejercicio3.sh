#!/bin/bash

# Verificar argumentos
if [ $# -eq 0 ]; then
    echo "Uso: $0 <nombre_del_ejecutable> [argumentos_del_ejecutable]"
    exit 1
fi

# Extraer el nombre del ejecutable y cualquier argumento
ejecutable=$1
argumentos_del_ejecutable=$2

# Archivos de registro y gráfica
archivo_log="archivo_log.txt"
archivo_grafica="grafico.plt"

# Crear o limpiar el archivo de registro y tocar el archivo de la gráfica
echo "Cargando datos..."
> $archivo_log
touch $archivo_grafica

# Comprobar si el archivo existe y es ejecutable
if [ ! -f "$ejecutable" ]; then
    echo "Error: El archivo '$ejecutable' no existe."
    exit 1
elif [ ! -x "$ejecutable" ]; then
    echo "Error: El archivo '$ejecutable' no tiene permisos de ejecución."
    exit 1
fi

# Ejecutar el comando con argumentos adicionales y capturar el PID
./$ejecutable $argumentos_del_ejecutable &
id_proceso=$!
echo "$id_proceso"
sleep 2
# Verificar si el proceso está corriendo
sleep 1
if ! ps -p $id_proceso $argumentos_del_ejecutable > /dev/null; then
    echo "Error: No se pudo iniciar el proceso '$ejecutable'."
    exit 1
fi


# Bucle para registrar datos
contador=0
while [ $contador -lt 10 ]; do
    if ! ps -p $id_proceso $argumentos_del_ejecutable > /dev/null; then
        echo "Error: Proceso '$ejecutable' terminado prematuramente."
        break
    fi

    # Recopilar datos de uso de CPU y memoria con sar
    datos_sar=$(sar -u 1 1 | tail -n 1)
    porcentaje_uso_cpu=$(echo $datos_sar | awk '{print $3}')
    consumo_memoria=$(echo $datos_sar | awk '{print $5}')
    fecha_hora=$(date +"%d-%m-%Y %H:%M:%S")
    
    # Registrar los datos si son válidos
    if [[ ! -z $porcentaje_uso_cpu && ! -z $consumo_memoria ]]; then
        echo "$fecha_hora $porcentaje_uso_cpu $consumo_memoria" >> $archivo_log
    fi

    sleep 0.2
    contador=$((contador+1))
done

# Script para la gráfica con gnuplot
cat <<EOM >$archivo_grafica
set terminal png
set output "grafico.png"

set xdata time
set timefmt "%d-%m-%Y %H:%M:%S"
set format x "%H:%M:%S"
set ylabel "Uso (%)"
set title "Uso de CPU y Memoria de $ejecutable"

plot "$archivo_log" using 1:3 title "CPU" with lines, \
     "$archivo_log" using 1:4 title "Memoria" with lines
EOM

# Generar gráfica con gnuplot
gnuplot $archivo_grafica




