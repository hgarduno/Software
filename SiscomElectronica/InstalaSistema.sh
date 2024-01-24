#!/bin/sh -e

ArchivosServidor=












ModoUso()
{
cat << EOF
Crea La instalacion del Sistema SiscomElectronica:

-a Directorio de instalacion




EOF


}









while getopts "a:b:c:d:f:g:" opcion
do 
	case "${opcion}"
	in
	a)
		DirectorioInstacion=$OPTARG
		;;
	*)
		ModoUso
		;;
	esac
done
