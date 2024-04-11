#!/bin/bash
ID=$1
info_proceso=$(ps aux | awk '$2 == "'$ID'" {print $0}')


echo "La información del proceso asociado al ID: $ID es la siguiente:"
echo "$info_proceso"
 
 
path=$(pwd $ID)
echo "El path del proceso con PID $ID es: $path"


