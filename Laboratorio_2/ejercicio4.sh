#!/bin/bash

# Archivos de registro 
archivo_log="registro_cambios_log.txt"
touch $archivo_log

while inotifywait -e create,modify,delete /home/jocs/UCR/IE-0117-; do
    echo "$(date) - Se detectó un cambio en el directorio" >> $archivo_log
done
