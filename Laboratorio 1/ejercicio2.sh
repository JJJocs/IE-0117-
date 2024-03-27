#!/bin/bash

# Creación de variables
usuario=$1
grupo=$2
usuario_defaul=$USER

# Creación de usuario
if id "$usuario" &>/dev/null; then
   echo "El usuario $usuario ya existe"
else
   sudo adduser $usuario
fi

# Creación de grupo y añadidura de usuarios
if grep -q "^$grupo:" /etc/group; then
   echo "El grupo $grupo ya existe"
   sudo adduser jocs $grupo
   sudo adduser $usuario
else
   sudo addgroup $grupo
   sudo adduser $usuario_defaul $grupo
   sudo adduser $usuario $grupo
   
fi

#Administración de permisos de ejercicio1.sh
chmod +x ejercicio1.sh
chmod g+x ejercicio1.sh 
   
   
   
   
   
   
   
   
