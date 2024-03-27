#!/bin/bash
archivo=$1

# Verificar la existencia del archivo
if [ ! -f "$archivo" ]; then
  echo "El archivo $archivo no existe"
  exit 1  # Devolver un código de error
fi

# Obtener los permisos del archivo
permisos=$(stat -c "%A" "$archivo")

# Función para interpretar los permisos
interpretar_permisos() {
    case $1 in
        "rwx") echo "Permisos de lectura, escritura y ejecución" ;;
        "rw-") echo "Permisos de lectura y escritura" ;;
        "r--") echo "Permisos de lectura" ;;
        "r-x") echo "Permisos de lectura y ejecución" ;;
        "r-x") echo "Permisos de escritura y ejecución" ;;
        "r--") echo "Permisos de escritura" ;;
        "r--") echo "Permisos de ejecución" ;;
        *) echo "Permisos desconocidos" ;;
    esac
}

# Crear función para obtener permisos detallados
get_permissions_verbose() {
    permisos_u=${permisos:1:3}
    permisos_g=${permisos:4:3}
    permisos_o=${permisos:7:3}

    resultado_usuarios=$(interpretar_permisos "$permisos_u")
    resultado_grupo=$(interpretar_permisos "$permisos_g")
    resultado_otros=$(interpretar_permisos "$permisos_o")

    echo "Los permisos asignados a los usuarios son: $resultado_usuarios"
    echo "Los permisos asignados al grupo son: $resultado_grupo"
    echo "Los permisos asignados a otros usuarios son: $resultado_otros"
}

# Llamar a la función para obtener permisos detallados
get_permissions_verbose

