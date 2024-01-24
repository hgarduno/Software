#!/bin/sh -e


ArchivosSQL="$HOME/SISCOMClasesGenerales/SQL/TablasClasesGenerales.sql 	\
	    $HOME/Trampolin/SQL/TablasTrampolin.sql			\
	    $HOME/Trampolin/SQL/InsertaTiposPersona.sql			\
	    $HOME/Trampolin/SQL/InsertaDatos.sql			\
	    $HOME/Sepomex/SQL/InformacionSepomex.sql			\
	    $HOME/.Seguridad3/EsquemaSeguridad3.sql			\
	    $HOME/.Seguridad3/SQL/AlgunosObjetos.sql"

CopiaArchivosSQL()
{
echo $1    
if [ -d $1 ]
then
algo=0
else
mkdir $1 
fi

for X in $ArchivosSQL
do
cp $X $1/
done
}
CreaScriptBaseDatos()
{
printf "#!/bin/sh\n" > $1/CreaBaseDatos.sh
printf "killall -9 psql\n" >> $1/CreaBaseDatos.sh
printf "dropdb %s\n" $2 >> $1/CreaBaseDatos.sh
printf "createdb %s\n" $2 >> $1/CreaBaseDatos.sh
for X in $ArchivosSQL
do
printf "psql %s < %s\n" $2 `basename $X` >> $1/CreaBaseDatos.sh
done
chmod +x $1/CreaBaseDatos.sh
}

Servidor()
{
if [ -d $1/Servidor ]
then
Algo=0
else
mkdir $1/Servidor
fi

ArchivosServidor="									\
		  $DIRDesarrolloHGE/ActualizaAplicacion/Servidor/libAccesoDatos.so	\
		  $DIRLIBSISCOM2/Servidor/ServidorGeneral				\
		  $DIRLIBSISCOM2/libSiscomDesarrollo2.so				\
		  $DIRLIBSISCOM2/libSiscomDesarrolloPostgresql.so			\
		  Servidor/libSiscomTrampolin.so					\
		  $DIRLIBSISCOM2/libSiscomSeguridad3Prot2.so				\
		  $DIRLIBSISCOM2/libSiscomSepomex.so					\
		  "

for X in $ArchivosServidor
do
cp $X $1/Servidor
done
cp $DIRPOSTGRESQL/lib/libpq.so* $1/Servidor
}
ArchivoIniAD()
{
cat << EOF > $1/Servidor/Configuracion.$3.ini

### Archivo De Configuracion para el Servidor
### Siscom Protocolo 2 

### Puerto En que atendera peticiones el servidor

PtoComunicaciones   =  $3

PtoAccesoDatos= 5000
DirIpAccesoDatos=127.0.0.1

Demonio=No
				
#### Biblioteca que contine la funcionalidad del servidor

LibServidor  =  libAccesoDatos.so
FuncionLibServidor = AccesoDatos

DirTrabajo=$1/Servidor


### base de datos a la que se conectara ,
### este parametro se debera pasar como parte
### de las operaciones a la base de datos.

BaseDatos   = $4


	#Informacion para los comentarios del archivo

# Se debe considerar este caso 	Informacion="Cualquier otro Dato que se Necesita"


# Ademas se debe considerar el echo de trabajar con variables como:
# Ambiente[]
#	     Ambiente[0]=LD_LIBRARY_PATH=/home/hgarduno/SISCOM:/QT/lib:
#	     Ambiente[1]=PATH=/home/hgarduno/Sistema
# []Ambiente


# La variable anterior se agrupara en una matriz de apuntadores a
# caracteres

ClienteFrecuente=Si
EOF
}
ArchivoIniRN()
{

cat << EOF > $1/Servidor/Configuracion.$2.ini

### Archivo De Configuracion para el Servidor
### Siscom Protocolo 2 

### Puerto En que atendera peticiones el servidor

PtoComunicaciones   = $2

PtoAccesoDatos= $3
DirIpAccesoDatos=127.0.0.1
#DirIpAccesoDatos=201.163.187.112

Demonio=No
				
#### Biblioteca que contine la funcionalidad del servidor

LibServidor  =  libSiscomTrampolin.so
FuncionLibServidor = Principal

DirTrabajo=$1/Servidor


### base de datos a la que se conectara ,
### este parametro se debera pasar como parte
### de las operaciones a la base de datos.

BaseDatos   =  $4


	#Informacion para los comentarios del archivo

# Se debe considerar este caso 	Informacion="Cualquier otro Dato que se Necesita"


# Ademas se debe considerar el echo de trabajar con variables como:
# Ambiente[]
#	     Ambiente[0]=LD_LIBRARY_PATH=/home/hgarduno/SISCOM:/QT/lib:
#	     Ambiente[1]=PATH=/home/hgarduno/Sistema
# []Ambiente


# La variable anterior se agrupara en una matriz de apuntadores a
# caracteres


#LibMemoriaComun=libSiscomTrampolinMemoriaComun.so

#FuncionLibMemoriaComun=IniciaMemoriaComun
#ClienteFrecuente=Si


# Para este caso el nombre de las bibliotecas se forman de dos partes
# separadas por @:
# la primera es un identificador
# la segunda el nombre de la biblioteca

#BibliotecasServidor[]
#		BibliotecasServidor[0]=0@libSeguridad3Expendios.so
#		BibliotecasServidor[0]=1@libSeguridad3Expendios.so
#		BibliotecasServidor[0]=2@libSeguridad3Expendios.so
#[]BibliotecasServidor


# Los nombres de las funciones se forman por el identificador de la
# biblioteca y el nombre de la funcion, el identificador de la biblioteca
# es el numero mediante el cual se va a relacionar la biblioteca y 
# la funcion 
#FuncionesServidor[]
		FuncionesServidor[0]=0@ConsultaSeguridad3Pro2Version2
#[]FuncionesServidor

EOF

}
IniciaServidor()
{
cat << EOF > $1/Servidor/GimnasiaSiscom 

#!/bin/sh

DirServidor=$1/Servidor

LD_LIBRARY_PATH=$1/Servidor
PATH=$1/Servidor:/usr/bin/cat:/bin/
BDSeguridad3=$4
export	LD_LIBRARY_PATH \
	PATH		\
	BDSeguridad3

start()
{

		ServidorGeneral \$DirServidor/Configuracion.$2.ini	
		ServidorGeneral \$DirServidor/Configuracion.$3.ini	
}
stop()
{
	kill -9 \`cat \$DirServidor/$2/ServidorSiscom.$2.pid\`
	kill -9 \`cat \$DirServidor/$3/ServidorSiscom.$3.pid\`
}
case "\$1" in
	start)
		start		

	;;
	stop)
		stop
	;;
	status)
		status
	;;
	restart)
		restart
	;;
	*)
	echo "Use ServidorSiscom start|stop|restart|status"
	exit 1
esac
EOF
chmod +x $1/Servidor/GimnasiaSiscom
}
CreaDirectoriosLog()
{

	if [ -d $1/Servidor/$2 ]
	then
	Algo=0
	else
	mkdir $1/Servidor/$2
	fi
	if [ -d $1/Servidor/$3 ]
	then
	Algo=0
	else
	mkdir $1/Servidor/$3
	fi
}
CopiaVeLog()
{
cat << EOF > $1/VeLog 

#!/bin/sh

tail -f $1/Servidor/\$1/Servidor.\$1.log

EOF

chmod +x $1/VeLog
}
DirectorioCliente()
{
if [ -d $1/Cliente ]
then
	Algo=0
else
mkdir $1/Cliente/
fi
}
CopiaInterfaz()
{
ArchivosCliente="Cliente/SiscomTrampolin				\
		 Cliente/SO/libPantallasSiscomTrampolin.so		\
		 Configuracion/SiscomTrampolin.xml			\
		 /QT/plugins/designer/libQCtrlPerfiles.so		\
		 /QT/plugins/designer/libQCtrlServidoresSiscom.so	\
		 /QT/plugins/designer/libQCtrlUsuarios.so		\
		 /QT/plugins/designer/libControlAparatoCompetencia.so	\
		 /QT/plugins/designer/libControlBuscaPersonas.so	\
		 /QT/plugins/designer/libControlBuscaPersonas2.so	\
		 /QT/plugins/designer/libControlClase.so		\
		 /QT/plugins/designer/libControlCompetencias.so		\
		 /QT/plugins/designer/libControlGimnasios.so		\
		 /QT/plugins/designer/libControlGrupo.so		\
		 /QT/plugins/designer/libControlNivel.so		\
		 /QT/plugins/designer/libControlTipoCompetencia.so	\
		 /QT/plugins/designer/libQSiscomSepomex++.so		\
		 /QT/plugins/designer/libControlFechaDesarrollo2.so	\
		 $DIRLIBSISCOM2/libSiscomSeguridad3Prot2++.so		\
		 $DIRLIBSISCOM2/libSepomexCliente.so			\
		 $DIRLIBSISCOM2/libSiscomClasesGenerales++.so		\
		 $DIRLIBSISCOM2/libSiscomComunicaciones++.so		\
		 $DIRLIBSISCOM2/libSiscomDesarrollo2.so			\
		 $DIRLIBSISCOM2/libSiscomSeguridad3Prot2++.so		\
		 $DIRLIBSISCOM2/libSISCOMComunControlesDesarrollo2.so	\
		 "
for X in $ArchivosCliente
do
cp $X $1/Cliente
done
cp /QT/lib/libqt-mt.so* $1/Cliente
}
ClienteGimnasia()
{
cat << EOF > $1/Gimnasia 

#!/bin/sh 

LD_LIBRARY_PATH=$1/Cliente

PATH=$1/Cliente
DirectorioConfiguracion=$1/Cliente
ArchivoConfiguracionModulos=SiscomTrampolin.xml
Aplicacion=SISCOMEscuelas
PtoComSvr2=2645
RutaIconos=/Cliente/Iconos
ArchivoServidores=$HOME/.SiscomEscuelas.txt

#IdExpendio=-1165435786
IdExpendio=-1165434773
DirIpSvr=127.0.0.1
PtoComSvr=$2

export LD_LIBRARY_PATH
export PATH
export DirectorioConfiguracion
export ArchivoConfiguracionModulos
export Aplicacion
export PtoComSvr2 
export RutaIconos
export ArchivoServidores 

export IdExpendio
export DirIpSvr
export PtoComSvr

ulimit -c 0

#SiscomTrampolin  Maximizada
SiscomTrampolin  $*

EOF

chmod +x $1/Gimnasia

}
ModoUso()
{
cat << EOF 
Crea Instalacion Del Sistema Gimnasia:

-a Directorio Instalacion
-b Nombre De la base de datos
-c Copia Archivos SQL
-d Crea Script de la base de datos
-g Copia Archivos Servidor
-e Pto Comunicaciones RN
-f Pto Comunicaciones AD

EOF

}
 

while getopts "a:b:c:d:e:f:g:h:i:" opcion 
do
        case "${opcion}"
	in
	a)
		DirectorioInstalacion=$OPTARG
		;;
	b)
		BaseDatos=$OPTARG
		;;
	c)
		CopiaArchivosSQL  $DirectorioInstalacion
		;;
	d)
		CreaScriptBaseDatos $DirectorioInstalacion $BaseDatos
		;;
	
	e)
		PtoRG=$OPTARG
		;;
	f)	
		PtoAD=$OPTARG
		;;
	g)
		Servidor $DirectorioInstalacion 
		ArchivoIniRN $DirectorioInstalacion $PtoRG $PtoAD $BaseDatos
		ArchivoIniAD $DirectorioInstalacion $PtoRG $PtoAD $BaseDatos
		IniciaServidor $DirectorioInstalacion $PtoRG $PtoAD $BaseDatos
		CreaDirectoriosLog $DirectorioInstalacion $PtoRG $PtoAD
		CopiaVeLog $DirectorioInstalacion
		;;
	i)
		DirectorioCliente $DirectorioInstalacion
		CopiaInterfaz $DirectorioInstalacion
		ClienteGimnasia $DirectorioInstalacion $PtoRG
		;;
	*)
		ModoUso
		;;
	esac
done

printf "Directorio Instalacion:%s\n" $DirectorioInstalacion
printf "Base De Datos [%s]\n" $BaseDatos
