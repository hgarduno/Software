#include <stdio.h> 
#include <unistd.h> 
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
typedef struct informacionRC
{
char *chrPtrDirRC;
char chrLetra;

}InformacionRC;


int errno;


void CreaEnlaces(InformacionRC *pInfRC)
{
char lchrArrPostgres[256],
	lchrArrServiSNTE[256],
	lchrArrEnlacePostgres[256],
	lchrArrEnlaceServiSNTE[256];

while(pInfRC->chrPtrDirRC)
{
  sprintf(lchrArrPostgres,"%s/%c10postgres",pInfRC->chrPtrDirRC,pInfRC->chrLetra);
  sprintf(lchrArrServiSNTE,"%s/%c91SiscomServiSNTE",pInfRC->chrPtrDirRC,pInfRC->chrLetra);
  sprintf(lchrArrEnlacePostgres,"ln -s /etc/init.d/postgres %s",lchrArrPostgres);
  sprintf(lchrArrEnlaceServiSNTE,"ln -s /etc/init.d/SiscomServiSNTE %s",lchrArrServiSNTE);
  printf("%s\n",lchrArrEnlacePostgres);
  printf("%s\n",lchrArrEnlaceServiSNTE); 
  system(lchrArrEnlacePostgres);
  system(lchrArrEnlaceServiSNTE);

pInfRC++;
}



}

void CreaPostgresRC()
{
char *lchrPtrPostgres="#!/bin/sh\n\
DirHomePostgres=/home/postgres\n\
VersionPostgres=9.4.6\n\
\n\
PGDATA=$DirHomePostgres/Bases\n\
\n\
PATH=$PATH:$DirHomePostgres/$VersionPostgres/bin \n\
\n\
\n\
export PGDATA\n\
export PATH\n\
start()\n\
{\n\
\n\
echo 'Iniciando el Demonio Postgres SQL'\n\
\n\
su - postgres  -c  \"export PATH=$PATH  ;		\\\n\
		   export PGDATA=$PGDATA ;		\\\n\
		   pg_ctl -w -t 10 start \"\n\
\n\
}\n\
\n\
stop()\n\
{\n\
echo 'Deteniendo el Demonio del Postgres SQL'\n\
\n\
su - postgres  -c  \"export PATH=$PATH  ;		\\\n\
		   export PGDATA=$PGDATA ;		\\\n\
		   pg_ctl  -t 10 stop \"\n\
\n\
}\n\
\n\
\n\
restart()\n\
{\n\
\n\
echo 'Reiniciando el Demonio Postgres SQL'\n\
\n\
}\n\
status()\n\
{\n\
\n\
echo 'el status del Demonio del Postgres SQL'\n\
\n\
}\n\
\n\
\n\
\n\
case \"$1\" in\n\
start)\n\
\n\
	start\n\
	;;\n\
stop)\n\
	stop\n\
	;;\n\
restart)\n\
	restart\n\
	;;\n\
status)\n\
	status\n\
	;;\n\
esac\n\
\n\
\n\
\n\
";
const char *lchrPtrArchivo="/etc/init.d/postgres";
int lintArchivo,lintRegreso,lintTamano;
lintArchivo=open(lchrPtrArchivo,O_CREAT|O_RDWR,S_IRWXU);
lintTamano=strlen(lchrPtrPostgres);
if((lintRegreso=write(lintArchivo,lchrPtrPostgres,lintTamano))!=lintTamano)
{
  printf("Error %d %s\n",lintRegreso,strerror(errno));


}

close(lintArchivo);
}
void CreaSiscomServiSNTE()
{
char *lchrPtrSiscomServiSNTE="#!/bin/sh\n\
\n\
Home=/home/hgarduno \n\
DIRPOSTGRESQL=/home/postgres/9.4.6\n\
PATH=$PATH:$Home/SoporteSiscomDesarrollo/Servidor/\n\
\n\
DirectorioConfiguracion=$Home/ConfiguracionServiSNTE/Servidor/\n\
ArchivosNomina=$Home/TransferenciasArchivosNomina\n\
\n\
LD_LIBRARY_PATH=$Home/SoporteSiscomDesarrollo/Servidor:$DIRPOSTGRESQL/lib:$Home/ServiSNTE/Servidor/\n\
\n\
\n\
export LD_LIBRARY_PATH 		\\\n\
	PATH			\\\n\
	DirectorioConfiguracion	\\\n\
	ArchivosNomina		\\\n\
	DIRPOSTGRESQL\n\
\n\
PuertoRN=6345\n\
PuertoAD=6346\n\
start() {\n\
echo \"Iniciando el sistema ServiSNTE (Cabeza Juarez)\"\n\
su - hgarduno -c \"\n\
		export LD_LIBRARY_PATH=$LD_LIBRARY_PATH\n\
		export PATH=$PATH\n\
		export DirectorioConfiguracion=$DirectorioConfiguracion\n\
		export ArchivosNomina=$ArchivosNomina\n\
		export DIRPOSTGRESQL=$DIRPOSTGRESQL\n\
		ServidorSiscom $DirectorioConfiguracion/SiscomServiSNTE$PuertoAD\\Ini\n\
		ServidorSiscom $DirectorioConfiguracion/SiscomServiSNTE$PuertoRN\\Ini\"\n\
echo \"Se Inicio de forma correcta el servidor\"\n\
}\n\
\n\
stop() {\n\
PidReglasNegocio=`cat $DirectorioConfiguracion/ServidorSiscom$PuertoRN\\Pid` \n\
PidAccesoDatos=`cat $DirectorioConfiguracion/ServidorSiscom$PuertoAD\\Pid`\n\
if [ $PidAccesoDatos ]\n\
then\n\
echo \"Deteniendo el proceso de acceso a datos ($PidAccesoDatos)\"\n\
kill -9 $PidAccesoDatos \n\
fi\n\
if [ $PidReglasNegocio ]\n\
then\n\
echo \"Deteniendo el proceso de Reglas del negocio ($PidReglasNegocio)\"\n\
kill -9 $PidReglasNegocio\n\
fi\n\
\n\
rm $DirectorioConfiguracion/ServidorSiscom$PuertoRN\\Pid\n\
rm $DirectorioConfiguracion/ServidorSiscom$PuertoAD\\Pid\n\
\n\
}\n\
\n\
case \"$1\" in\n\
start)\n\
\n\
	start\n\
	;;\n\
stop)\n\
	stop\n\
	;;\n\
esac\n\
\n\
\n\
\n\
";
const char *lchrPtrArchivo="/etc/init.d/SiscomServiSNTE";
int lintArchivo,lintRegreso,lintTamano;
lintArchivo=open(lchrPtrArchivo,O_CREAT|O_RDWR,S_IRWXU);
lintTamano=strlen(lchrPtrSiscomServiSNTE);
if((lintRegreso=write(lintArchivo,lchrPtrSiscomServiSNTE,lintTamano))!=lintTamano)
{
  printf("Error %d %s\n",lintRegreso,strerror(errno));
}
}
int main(int pintArgc,
	 char **pchrPtrArgv)
{
InformacionRC lInfRC[]={  
			 {"/etc/rc0.d",'K'},
			 {"/etc/rc1.d",'K'},
			 {"/etc/rc2.d",'S'},
			 {"/etc/rc3.d",'S'},
			 {"/etc/rc4.d",'S'},
			 {"/etc/rc5.d",'S'},
			 {"/etc/rc6.d",'K'},
			 {0,0}};



CreaPostgresRC();
CreaSiscomServiSNTE();
CreaEnlaces(lInfRC); 
}

