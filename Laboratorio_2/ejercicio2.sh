#!/bin/bash

# Verifica si se proporciona un nombre de proceso como argumento
if [ -z "$1" ]; then
    echo "Por favor, proporcione el nombre del proceso como argumento."
    exit 1
fi

nombre_proceso=$1

# Obtiene el ID del proceso
id_proceso=$(pgrep -l "$nombre_proceso" | awk -v np="$nombre_proceso" '$2 == np {print $1}')

# Obtiene el estado del proceso
estado_proceso=$(ps aux | awk '$2 == '"$id_proceso"' {print $8}')

# Bucle principal
while true
do
    # Verifica si el proceso está en ejecución
    if ps -p $id_proceso > /dev/null
    then
        echo "El proceso $nombre_proceso con PID $id_proceso está en ejecución, su estado es $estado_proceso"
    else
        echo "El proceso $nombre_proceso no está en ejecución, se procede a iniciarlo"
        # Inicia el proceso y redirige la salida estándar y de error a /dev/null
        $nombre_proceso & > /dev/null
        sleep 6
        # Actualiza el ID y estado del proceso
        id_proceso=$(pgrep -l "$nombre_proceso" | awk -v np="$nombre_proceso" '$2 == np {print $1}')
        estado_proceso=$(ps aux | awk '$2 == '"$id_proceso"' {print $8}')
        echo "El proceso fue levantado, su estado es $estado_proceso"
    fi

    sleep 7
done


