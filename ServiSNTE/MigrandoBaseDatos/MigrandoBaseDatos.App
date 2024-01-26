#!/bin/bash


LD_LIBRARY_PATH=$DirDesarrollo4/SiscomDesarrollo4:$DirDesarrollo4/SiscomDesarrollo4/PostgresSql:$DIRPOSTGRESQL/lib
PATH=$PATH:$DirDesarrollo4/ServiSNTE/MigrandoBaseDatos
LANG=es_MX.UTF-8


export LD_LIBRARY_PATH	\
	PATH		\
	LANG

#printf "Ambiente DIRPOSTGRESQL=%s \n" $DIRPOSTGRESQL 
#printf "         PATH=%s\n" $PATH


EstaLaOpcion()
{
lintRegreso=0
 while [[ $# -gt 0 ]]
  do
   argumento="$1"
	case "$argumento" in
	"-$OpcionABuscar" )
		lintRegreso=1
	;; 
    esac
	shift 
		done
		if [ $lintRegreso == 1 ]
		then
			echo 1
		else
			echo 0
		fi
}

ObtenParametroEntrada()
{
while [[ $# -gt 0 ]]	
do 
	case "$1" in
	 "-$Parametro")
	 	  shift 
		  	echo $1
		  ;;
	esac
	 shift
done

}


SeMataPsql()
{
OpcionABuscar=MataPsql
echo $(EstaLaOpcion $*)

}

SeEliminaBase()
{
OpcionABuscar=EliminaBase
echo $(EstaLaOpcion $*)
}
SeCreaBase()
{
OpcionABuscar=CreaBase
echo $(EstaLaOpcion $*)
}
SeRestauraBase()
{
OpcionABuscar=Restaura
echo $(EstaLaOpcion $*)
}

SeRespalda()
{
OpcionABuscar=Respalda
echo $(EstaLaOpcion $*)
}

EstaArchivo()
{
OpcionABuscar=Archivo
echo $(EstaLaOpcion $*)
}
EstaArchivoConfiguracion()
{
OpcionABuscar=ArchivoConf
echo $(EstaLaOpcion $*)
}

EstaTienda()
{
OpcionABuscar=Tienda
echo $(EstaLaOpcion $*)
}
MatandoSql()
{
  if [ "$(SeMataPsql $*)" == "1" ]
  then
  	killall -9 psql
  fi

}


CreandoBase()
{
 if [ "$(EstaTienda $*)" == "1" ]
 then
  	if [ "$(SeCreaBase $*)" == "1" ] 
  	then
		NumeroTienda=$(ObtenNumeroTienda $*)
		if [ "$NumeroTienda" != "" ]
		then
  			$DIRPOSTGRESQL/bin/createdb ServiSNTE.$NumeroTienda
		else
		   	echo 'Se Paso la Opcion Tienda vacia'
		fi
	fi
  else
  	if [ "$(SeCreaBase $*)" == "1" ]
	then
  	createdb ServiSNTE
	fi
  fi
}

EliminandoBase()
{
  if [ "$(EstaTienda $*)" == "1" ]
  then
  	if [ "$(SeEliminaBase $*)" == "1" ]
  	then
	   NumeroTienda=$(ObtenNumeroTienda $*)
	   if [ "$NumeroTienda" != "" ]
	   then
  		$DIRPOSTGRESQL/bin/dropdb ServiSNTE.$NumeroTienda
		#echo Eliminando Base tienda
	    else
	    	echo 'Se Paso la Opcion Tienda vacia'
	    fi
	 fi
   else
   	if [ "$(SeEliminaBase $*)" == "1" ]
	then
   	dropdb ServiSNTE
	fi
	#echo Eliminando base central
   fi
}
ObtenNumeroTienda()
{
   	Parametro=Tienda
        echo $(ObtenParametroEntrada $*)
}
ObtenNombreArchivo()
{
   	Parametro=Archivo
        echo $(ObtenParametroEntrada $*)

}
ObtenArchivoConfiguracion()
{
Parametro=ArchivoConf
echo $(ObtenParametroEntrada $*)
}
CorriendoMigracionBase()
{
   if [[ "$(EstaArchivo $*)" == "1"  && "$(EstaArchivoConfiguracion $*)" == "1" ]]
   then
 	ArchivoEntrada=$(ObtenNombreArchivo $*)
	ArchivoConfiguracion=$(ObtenArchivoConfiguracion $*)
	 NumeroTienda=$(ObtenNumeroTienda $*)
	 if [ "$NumeroTienda" != "" ]
	 then
		if [ "$(SeRestauraBase $*)" == "1" ]
		then	
	 	   MigrandoBaseDatos $ArchivoEntrada $ArchivoConfiguracion $NumeroTienda
		   printf "insert into tienda values(%s);\n" $NumeroTienda |$DIRPOSTGRESQL/bin/psql ServiSNTE.$NumeroTienda
		else
	 	   MigrandoBaseDatos $ArchivoEntrada $ArchivoConfiguracion $NumeroTienda
		fi
	  else
	  if [ "$(SeRestauraBase $*)" == "1" ]
		then
		   #Si no se pasa el Numero de tienda es Zacatenco (IdTienda 5)
	 	   MigrandoBaseDatos $ArchivoEntrada $ArchivoConfiguracion 
		  printf "insert into tienda values(%s);\n" 5 |$DIRPOSTGRESQL/bin/psql ServiSNTE  
		else
		   #Si no se pasa el Numero de tienda es Zacatenco (IdTienda 5)
		   printf "Ejecutando en la tienda de Zacatenco\n"
	 	   MigrandoBaseDatos $ArchivoEntrada $ArchivoConfiguracion 
		fi
	  	
	 fi
			
   fi
}


NombrePorFecha()
{
#Enero
#Febrero
#Marzo
#Abril
#Mayo
#Junio
#Julio
#Agosto
#Septiembre
#Octubre
#Noviembre
#Diciembre

Dia=$(date '+%A'|  sed -e s/^l/L/g -e s/^m/M/g -e s/^j/J/g -e s/^v/V/g -e s/^s/S/g -e s/^d/D/g -e s/á/a/g -e s/é/e/g)

Mes=$(date '+%B'|  sed -e s/^e/E/g -e s/^f/F/g -e s/^a/A/g -e s/^m/M/g -e s/^j/J/g -e s/^s/S/g -e s/^o/O/g -e s/^n/N/g -e s/^d/D/g)
NDia=$(date '+%d')
Anio=$(date '+%Y')
if [ "$1" != "" ]
then
printf "ServiSNTE_%s_%s_%s_%s.%s.sql\n" $Dia $NDia $Mes $Anio $1
else
printf "ServiSNTE_%s_%s_%s_%s.sql\n" $Dia $NDia $Mes $Anio 
fi

}
Respaldando()
{
  if [ "$(SeRespalda $*)" == "1" ]
  then
	NumeroTienda=$(ObtenNumeroTienda $*)
	if [ "$NumeroTienda" != "" ]
	then
		NombreArchivo=$(NombrePorFecha $NumeroTienda) 
		$DIRPOSTGRESQL/bin/pg_dump ServiSNTE.$NumeroTienda > RespaldosTiendas/$NombreArchivo
        	if [ -f RespaldosTiendas/$NombreArchivo.xz ]
        	then
             		rm RespaldosTiendas/$NombreArchivo.xz
         	else
			xz -z RespaldosTiendas/$NombreArchivo
    		fi
	else
		NombreArchivo=$(NombrePorFecha ) 
		pg_dump ServiSNTE > RespaldosTiendas/$NombreArchivo
		echo Generando RespaldosTiendas/$NombreArchivo.xz
		if [ -f RespaldosTiendas/$NombreArchivo.xz ]
		then
			rm RespaldosTiendas/$NombreArchivo.xz 
		else
		      xz -z RespaldosTiendas/$NombreArchivo
		fi
	fi
   fi	
}
ModoUso()
{
cat << ModoUso | more 
Script para leer la informacion del archivo md ServiSNTE, y generar 
las inserciones para la base de datos postgres
Modo Uso:

MigrandoBaseDatos.App 
			-MataPsql 
			-EliminaBase
			-CreaBase
			-Restaura
			-Archivo 
				El archivo exportado por access
			-ArchivoConf
				El archivo Ini del proceso con los scritps de tablas 
				y Procesos que se ejecutan durante la insercion
			-Tienda 
				Se pasa el numero de la tienda
			-Respalda

ModoUso

}
if [[ $# == 0 ]]
then
	ModoUso
else
MatandoSql $*
EliminandoBase $*
CreandoBase $*
CorriendoMigracionBase $*
Respaldando $*
fi
