#include <ArmaArchivoConfiguracion.h>


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

FILE *gPtrFleArchivoLog;
int gintSocketProtocoloLog;
SiscomError gSiscomErrorSistema;

int errno;
int main(int pintArgc,
	 char **pchrPtrArgv)
{

 StcSiscomOpciones *lStcPtrSisOpciones;
 gPtrFleArchivoLog=stdout;
 Argumentos(pintArgc,pchrPtrArgv,&lStcPtrSisOpciones);
}

void Argumentos(int pintArgc,char **pchrPtrArgv,StcSiscomOpciones **pStcPtrSisOpciones)
{
StcSiscomOpciones lStcSisOpciones;
SiscomRegistroProL *lSisRegProLPtrRegistro;
char *lchrPtrComandos[]={"Rfc" ,
			"RazonSocial",
			"Calle",
			"Numero",
			"NumeroInt",
			"Colonia",
			"Delegacion",
			"Estado",
			"Pais",
			"Cp",
			"Archivo",
			"Prefijo",
			0};

    SiscomAnalizaOpciones(pchrPtrArgv,pintArgc,pStcPtrSisOpciones);

  if(!SiscomLineaComandosCompleta(lchrPtrComandos,*pStcPtrSisOpciones,&lStcSisOpciones)) 
  {
  	LogSiscom("Modo de Uso");
	printf("Modo de Uso:							\n"
		"Configuracion :						\n"
		"	-Rfc							\n"
		"	-RazonSocial						\n"
		"	-Calle							\n"
		"	-Numero							\n"
		"	-NumeroInt						\n"
		"	-Colonia						\n"
		"	-Delegacion						\n"
		"	-Estado							\n"
		"	-Pais							\n"
		"	-Cp							\n"
		"	-Archivo						\n"
		"       -Prefijo");
			
  }
  else
  {
     LogSiscom("Las opciones Completas");
     lSisRegProLPtrRegistro=FormandoRegistro(*pStcPtrSisOpciones);
     FormaArchivo(*pStcPtrSisOpciones,lSisRegProLPtrRegistro);

  }

}
void FormaArchivo(StcSiscomOpciones *pStcPtrSisOpciones,
		  SiscomRegistroProL *pSisRegProLPtrPrim)
{
int lintArchivo;
char lchrArrBuffer[128];
if((lintArchivo=open(SiscomOpcionAChar("Archivo",pStcPtrSisOpciones),
		     O_WRONLY|O_CREAT,
		     S_IRUSR | S_IWUSR)))
{
  LogSiscom("Abriendo el archivo ");
  write(lintArchivo,"000040000000000",15);
  SiscomEnviaRegistrosSocket(lintArchivo,lchrArrBuffer,pSisRegProLPtrPrim);
  close(lintArchivo);
}
else
LogSiscom("NO Se pudo abrir el archivo");
exit(0);


}
SiscomRegistroProL *FormandoRegistro(StcSiscomOpciones *pStcPtrSisOpciones)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrPrim=0,
		   *lSisRegProLPtrAct=0;
SiscomAnexaRegistroPro(&lSisRegProLPtrPrim,
		       &lSisRegProLPtrAct,
		       lchrArrBuffer,
		       "Rfc,"
		       "RazonSocial,"
		       "Calle,"
		       "Numero,"
		       "NumeroInt,"
		       "Colonia,"
		       "Delegacion,"
		       "Estado,"
		       "Pais,"
		       "Cp,"
		       "Prefijo,",
		       SiscomOpcionAChar("Rfc",pStcPtrSisOpciones),
		       SiscomOpcionAChar("RazonSocial",pStcPtrSisOpciones),
		       SiscomOpcionAChar("Calle",pStcPtrSisOpciones),
		       SiscomOpcionAChar("Numero",pStcPtrSisOpciones),
		       SiscomOpcionAChar("NumeroInt",pStcPtrSisOpciones),
		       SiscomOpcionAChar("Colonia",pStcPtrSisOpciones),
		       SiscomOpcionAChar("Delegacion",pStcPtrSisOpciones),
		       SiscomOpcionAChar("Estado",pStcPtrSisOpciones),
		       SiscomOpcionAChar("Pais",pStcPtrSisOpciones),
		       SiscomOpcionAChar("Cp",pStcPtrSisOpciones),
		       SiscomOpcionAChar("Prefijo",pStcPtrSisOpciones));
return lSisRegProLPtrPrim;
}
