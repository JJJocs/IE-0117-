#!/bin/bash

# Verifica si se proporciona un ID de proceso como argumento
if [ -z "$1" ]; then
    echo "Por favor, proporcione el ID del proceso como argumento."
    exit 1
fi

ID=$1

# Verifica si el proceso asociado al ID existe
if ! ps -p $ID > /dev/null; then
    echo "El proceso con el ID $ID no se encuentra."
    exit 1
fi

# Obtén información del proceso asociado al ID
nombre_proceso=$(ps -p $ID -o comm=)
parent_processID=$(ps -f $ID | awk '$2 == '"$ID"' {print $3}')
usuario_propietario=$(ps -o user= -p $ID)
porcentaje_uso_cpu=$(ps -p $ID -o %cpu=)
consumo_memoria=$(ps -p $ID -o %mem=)
estado=$(ps -p $ID -o stat=)
path=$(sudo readlink /proc/$ID/exe)

# Función para mostrar la información del proceso
mostrar_informacion_proceso() {
    echo "La información del proceso asociado al ID: $ID es la siguiente:"
    echo "Nombre del proceso: $nombre_proceso"
    echo "ID del proceso: $ID"
    echo "Parent process ID: $parent_processID"
    echo "Usuario propietario: $usuario_propietario"
    echo "Porcentaje de uso de CPU : $porcentaje_uso_cpu"
    echo "Consumo de memoria: $consumo_memoria"
    echo "Estado (status): $estado"
}

mostrar_informacion_proceso