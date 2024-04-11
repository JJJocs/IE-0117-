#!/bin/bash
nombre_proceso=$1
id_proceso=$(pgrep -l "$nombre_proceso" | awk -v np="$nombre_proceso" '$2 == np {print $1}')
echo "1.  $nombre_proceso, 2. $id_proceso"
