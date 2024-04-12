#!/bin/bash
ID=$1
info_proceso=$(ps aux | awk '$2 == "'$ID'" {print $0}')
nombre_proceso=$(ps -p $ID -o comm=)
parent_processID=$(ps -f $ID | awk '$2 == '"$ID"' {print $3}')
usuario_propietario=$(ps aux | awk '$2 == '"$ID"' {print $1}')
porcentaje_uso_cpu=$(ps aux | awk '$2 == '"$ID"' {print $3}')
consumo_memoria=$(ps aux | awk '$2 == '"$ID"' {print $4}')
estado=$(ps aux | awk '$2 == '"$ID"' {print $8}')
path=$(sudo readlink /proc/$ID/exe)




mostrar_informacion_proceso() {
    echo "La información del proceso asociado al ID: $ID es la siguiente:"
    echo "Nombre del proceso: $nombre_proceso"
    echo "ID del proceso: $ID"
    echo "Parent process ID: $parent_processID"
    echo "Usuario propietario: $usuario_propietario"
    echo "Porcentaje de uso de CPU : $porcentaje_uso_cpu"
    echo "Consumo de memoria: $consumo_memoria"
    echo "Estado (status): $estado"
    echo "Path del ejecutable: $path"
}

mostrar_informacion_proceso