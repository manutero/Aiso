#!/bin/sh

module="p4"
device="aiso_device"
mode="664"

# instalar el modulo
/sbin/insmod $module.ko || exit 1

# reserva el numero mayor
major=$(awk "\$2==\"$module\" {print \$1}" /proc/devices)

# crear dispositvo en /dev
mknod /dev/$device c $major 0

# cambiar los permisos
chmod $mode /dev/$device
