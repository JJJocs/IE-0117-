#!/bin/bash

# Función para imprimir el menú de ayuda
print_help() {
    echo "Menú de Ayuda:"
    echo "a) -h: Imprimir este menú de ayuda"
    echo "b) -m MODE: Modo de funcionamiento del informe. Las opciones disponibles son: servidor_web, base_de_datos, proceso_batch, aplicación, monitoreo."
    echo "c) -d DATE: Especifica la fecha en el formato año-mes-día (ejemplo: 2024-03-08)."
}

# Función para generar el informe con el formato requerido
generate_report() {
    # Lógica para manejar los diferentes casos
    if [ -n "$mode" ] && [ -n "$date" ]; then
        echo "Generar informe con errores del modo '$mode' registrados en la fecha '$date':"
        grep "^$date.*$mode" "$nombreDocumento" | grep "ERROR" | while read -r line; do
            # Formatear el informe con la fecha, hora del error y descripción del error
            error_date=$(echo "$line" | awk '{print $1}')
            error_time=$(echo "$line" | awk '{print $2}')
            error_description=$(echo "$line" | awk -F '] ' '{print $NF}')
            echo "Fecha: $error_date"
            echo "Hora del Error: $error_time"
            echo "Descripción del Error: $error_description"
        done
    elif [ -n "$mode" ]; then
        echo "Generar informe con errores del modo '$mode' registrados en todas las fechas:"
        grep "\[$mode\]" "$nombreDocumento" | grep "ERROR"
    elif [ -n "$date" ]; then
        echo "Generar informe con todos los errores ocurridos en la fecha '$date', independientemente del modo:"
        grep "^$date" "$nombreDocumento" | grep "ERROR"
    else
        echo "No se especificaron opciones para generar el informe."
    fi
}

# Función principal
main() {
    # Procesar argumentos del script
    while getopts ":hm:d:" option; do
        case $option in
            h)  # Opción de ayuda
                print_help
                if [ "$#" -eq 1 ]; then
                   exit 0  # Salir después de imprimir el menú de ayuda si no hay más argumentos
                fi
                ;;
            m)  # Opción de modo de funcionamiento
                mode="$OPTARG"
                ;;
            d)  # Opción de fecha
                date="$OPTARG"
                ;;
            \?) # Opción inválida
                echo "Opción inválida: -$OPTARG" >&2
                print_help >&2
                exit 1
                ;;
        esac
    done

    # Llamar a la función para generar el informe
    generate_report
}


#Solicitud de archivo de registro
if [ "$mode" != "h" ]; then
    echo "Ingresa el nombre del documento donde se ubican los registros"
    read -r nombreDocumento
    if [ ! -f "$nombreDocumento" ]; then
        echo "El archivo $nombreDocumento no existe."
        exit 1
    fi
elif [ "$mode" == "h" ]; then
     print_help

fi
# Llamar a la función principal
main "$@"

