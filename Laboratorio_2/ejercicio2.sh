#!/bin/bash
nombre_proceso=$1
id_proceso=$(pgrep -l "$nombre_proceso" | awk -v np="$nombre_proceso" '$2 == np {print $1}')
estado_proceso=$(ps aux | awk '$2 == '"$id_proceso"' {print $8}')

while true
do
    if ps -p $id_proceso > /dev/null
    then
        echo "El proceso $nombre_proceso con PID $id_proceso está en ejecución su estado es $estado_proceso "
    else
        echo "El proceso $nombre_proceso no está en ejecución, se procede a iniciarlo"
        $nombre_proceso & > /dev/null
        sleep 6
        id_proceso=$(pgrep -l "$nombre_proceso" | awk -v np="$nombre_proceso" '$2 == np {print $1}')
        estado_proceso=$(ps aux | awk '$2 == '"$id_proceso"' {print $8}')
        echo "El proceso fue levantado, su estado es $estado_proceso"

    fi

    sleep 7
done


