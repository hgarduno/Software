#include <SiscomFuncionesComunes.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomErrores.h>
#include <SiscomArchivosIni.h>
#include <SiscomProtocoloComunicaciones.h>
#include <Pruebas.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
FILE *gPtrFleArchivoLog;
SiscomError gSiscomErrorSistema;
int gintSocketProtocoloLog;
SiscomDatosIni gSiscomDatIni;

SiscomRegistroProL *gSiscomRegProLPtrMemoria;
int main(int pintArc,
	 char **pchrPtrArgv)
{
gPtrFleArchivoLog=stdout;
gSiscomRegProLPtrMemoria=0;
LogSiscom("Probando Las macros:%s %x %x",
	  "Heli Gaduno Esquivel",
	  1972,
	  gPtrFleArchivoLog);
PruebaFechaLocal();
PruebaArchivoIni(pchrPtrArgv);
PruebaSiscomProtocoloComunicaciones(pchrPtrArgv);
/*PruebaSiscomCargaModulo(pchrPtrArgv);
PruebaSiscomLeeProtocoloComunicaciones(pchrPtrArgv);
*/

/*PruebaEnvioSql(pchrPtrArgv); */
}

void PruebaFechaLocal()
{
char lchrArrFecha[25];

SiscomFechaLocal(lchrArrFecha);

printf("La fecha local:(%s)\n",lchrArrFecha);

}

void PruebaArchivoIni(char **pchrPtrArgv)
{
SiscomDatosIni lSiscomDIInformacion;
SiscomVariableIni lSiscomVIPrueba;
SiscomAnalizaArchivoIni(pchrPtrArgv[1],&lSiscomDIInformacion);

/*
SiscomMuestraVariablesIniArreglo(lSiscomDIInformacion.SiscomVIALPtrArreglo);


if(SiscomObtenVariableIni(pchrPtrArgv[2],
			&lSiscomDIInformacion,
			&lSiscomVIPrueba))
LogSiscom("El Dato:%s=%s",
	    lSiscomVIPrueba.chrArrNombre,
	    lSiscomVIPrueba.chrArrDato);
else
LogSiscom("No se encontro la variable:%s",
	   pchrPtrArgv[2]);

if(SiscomObtenVariableArregloIni("FechasNacimiento",
				 "Yoltzin",
				 &lSiscomDIInformacion,
				 &lSiscomVIPrueba))
{
LogSiscom("El Dato:%s=%s",
	    lSiscomVIPrueba.chrArrNombre,
	    lSiscomVIPrueba.chrArrDato);


}
else
LogSiscom("No se encontro la variable de arreglo");
*/
}


int AbreArchivo(const char *pchrPtrArchivo)
{
int lintFdArchivo;

if((lintFdArchivo=open(pchrPtrArchivo,O_WRONLY|O_CREAT,S_IRWXU))>0)
return lintFdArchivo;
else
return -1;


}
void PruebaSiscomProtocoloComunicaciones(char **pchrPtrArgv)
{
int lintIdArchivo;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[512];
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdExpendio,"
		       "RSocial,"
		       "Usuarios,"
		       "Direccion,"
		       "Telefonos,",
			"0",
			"Siscom Ecatepec",
			(char *)0,
			"En Algun lugar de la A.v. Central",
			(char *)0);

SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdExpendio,"
		       "RSocial,"
		       "Usuarios,"
		       "Direccion,"
		       "Telefonos,",
			"0",
			"Siscom Zacatenco",
			(char *)0,
			"Av. I.P.N. #2085 San Pedro Zacatenco, Del Gustavo A. Madero",
			(char *)0);

SiscomAnexaRegistrosAlCampo("Telefonos",
			    lSiscomRegProLPtrAct,
			    lchrArrBuffer,
			    "Telefono,",
			    "015558766421");
SiscomAnexaRegistrosAlCampo("Telefonos",
			    lSiscomRegProLPtrAct,
			    lchrArrBuffer,
			    "Telefono,",
			    "015557540823");
SiscomAnexaRegistrosAlCampo("Telefonos",
			    lSiscomRegProLPtrAct,
			    lchrArrBuffer,
			    "Telefono,",
			    "015558760146");
SiscomAnexaRegistrosAlCampo("Telefonos",
			    lSiscomRegProLPtrAct,
			    lchrArrBuffer,
			    "Telefono,",
			    "015558763417");
LogSiscom("Mostrando el registro, hay %d Registros",
	  lSiscomRegProLPtrPrim->intNRegistros);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
SiscomRegistroProL *lSiscomRegProLTelefonos;
lSiscomRegProLTelefonos=SiscomObtenRegistrosCampoProL("Telefonos",
						      lSiscomRegProLPtrAct);

LogSiscom("El Numero de telefonos:%d",lSiscomRegProLTelefonos->intNRegistros);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLTelefonos);
/*
if((lintIdArchivo=AbreArchivo(pchrPtrArgv[3]))>0)
{
*/
/*SiscomEnviaRegistrosSocket(STDOUT_FILENO,lchrArrBuffer,lSiscomRegProLPtrPrim); */
/*
LogSiscom("Abriendo el archivo:%s",pchrPtrArgv[3]);
SiscomEnviaRegistrosSocket(lintIdArchivo,lchrArrBuffer,lSiscomRegProLPtrPrim);
}
else
{
LogSiscom("No se pudo abrir el archivo:%s (%s)",
	  pchrPtrArgv[3],
	  strerror(errno));
close(lintIdArchivo);
}
*/
}

void PruebaSiscomLeeProtocoloComunicaciones(char **pchrPtrArgv)
{
int lintFdArchivo;
char lchrArrBuffer[1024];
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
if((lintFdArchivo=open(pchrPtrArgv[3],O_RDONLY))>0)
{
LogSiscom("Abriendo el archivo:%s %d",pchrPtrArgv[3],lintFdArchivo);
SiscomLeeRegistrosSocket(lintFdArchivo,
			 lchrArrBuffer,
			 &lSiscomRegProLPtrPrim,
			 &lSiscomRegProLPtrAct);
LogSiscom("Ahora leyendo del socket");
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
if(pchrPtrArgv[4])
SiscomRegistrosAsociadosLog(lchrArrBuffer,pchrPtrArgv[4],lSiscomRegProLPtrAct);
}


}

void PruebaSiscomInformacionModulo(char *pchrPtrBuffer,
				   SiscomRegistroProL *pSiscomProLPtrAct)
{
SiscomAnexaRegistrosAlCampo("ModuloServidor",
			    pSiscomProLPtrAct,
			    pchrPtrBuffer,
			    "Modulo,"
			    "Funcion,",
			    "libPruebasSiscomDesarrollo4.so",
			    "PruebasSiscomServidor");
}
void PruebaSiscomInformacionUsuario(char *pchrPtrBuffer,
				     SiscomRegistroProL *pSiscomProLPtrAct)
{
SiscomAnexaRegistrosAlCampo("Usuario",
			    pSiscomProLPtrAct,
			    pchrPtrBuffer,
			    "Firma,"
			    "Password,",
			    "hgarduno",
			    "heligardunoesquivel");
}


void PruebaSiscomCargaModulo(char **pchrPtrArgv)
{
int lintIdArchivo;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[512];
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "ModuloServidor,"
		       "Expendio,"
		       "Usuario,",
		       (char *)0,
		       "0",
		       (char *)0);
PruebaSiscomInformacionModulo(lchrArrBuffer,lSiscomRegProLPtrAct);
PruebaSiscomInformacionUsuario(lchrArrBuffer,lSiscomRegProLPtrAct);

SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"ModuloServidor",lSiscomRegProLPtrPrim);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"Usuario",lSiscomRegProLPtrPrim);
LogSiscom("Numeros %d Registros con %d Campos",
	  lSiscomRegProLPtrPrim->intNRegistros,
	  3);
if((lintIdArchivo=AbreArchivo("ModuloSiscom.Prueba"))>0)
{
 SiscomEnviaRegistrosSocket(lintIdArchivo,lchrArrBuffer,lSiscomRegProLPtrPrim);
 close(lintIdArchivo);
}

}

void PruebaEnvioSql(char **pchrPtrArgv)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
 	           *lSiscomRegProLPtrAct=0;
SiscomConsultasSql(lchrArrBuffer,
		   "127.0.0.1",
		   5045,
		   &lSiscomRegProLPtrPrim,
		   &lSiscomRegProLPtrAct,
		   "Direcciones%Telefonos%Usuarios%",
		   "select * from direcciones",
		   "select * from Telefonos",
		   "select * from usuarios");

SiscomRegistrosAsociadosLog(lchrArrBuffer,"Direcciones",lSiscomRegProLPtrPrim);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"Telefonos",lSiscomRegProLPtrPrim);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"Usuarios",lSiscomRegProLPtrPrim);


}
