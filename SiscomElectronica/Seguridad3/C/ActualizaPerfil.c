#include <ActualizaPerfil.h>
#include <OperacionesSeguridad.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


void ActualizaPerfil(StcSiscomOpciones *pStcPtrSisOpciones)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrPrimPer=0,
		   *lSisRegProLPtrActPer=0,
		   *lSisRegProLPtrDatosPerfil;
LogSiscom("Se actualiza un perfil");
PerfilesSeguridad3(pStcPtrSisOpciones,&lSisRegProLPtrPrimPer,&lSisRegProLPtrActPer);
ObtenPerfil(lSisRegProLPtrPrimPer,&lSisRegProLPtrDatosPerfil);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrDatosPerfil);
}
void PerfilesSeguridad3(StcSiscomOpciones *pStcSisPtrOpciones,
			SiscomRegistroProL **pSisRegProLPtrPrimPer,
			SiscomRegistroProL **pSisRegProLPtrActPer)
{
int lintArchivo;
char lchrArrBuffer[128];
if((lintArchivo=open(SiscomOpcionAChar("Archivo",pStcSisPtrOpciones),S_IRUSR | S_IWUSR)))
{
   SiscomVersionProtocolo4(lintArchivo);
   SiscomLeeRegistrosSocket(lintArchivo,
   			    lchrArrBuffer,
			    pSisRegProLPtrPrimPer,
			    pSisRegProLPtrActPer);
  close(lintArchivo);
}
}
void ObtenPerfil(SiscomRegistroProL *pSisRegProLPtrDatos,
		 SiscomRegistroProL **pSisRegProLPtrPerfil)
{
SiscomRegistroProL *lSisRegProLPtrEnvio;
if((lSisRegProLPtrEnvio=SiscomObtenRegistrosCampoProL("Envio",pSisRegProLPtrDatos)))
   *pSisRegProLPtrPerfil=SiscomObtenRegistrosCampoProL("Perfil",lSisRegProLPtrEnvio);
}

void ConsultaPerfiles(StcSiscomOpciones *pStcPtrSisOpciones)
{
char lchrArrBuffer[128];
int lintSocket;
SiscomRegistroProL *lSisRegProLPtrPerPrim=0,
		   *lSisRegProLPtrPerAct=0;
if((lintSocket=Conectate(pStcPtrSisOpciones,
			 "libSiscomElectronica4.so",
			 "PerfilesAplicacion")))
{
LogSiscom("Consultando Perfiles Aplicacion");
/*SiscomLeeRegistrosSocket(lintSocket,lchrArrBuffer,&lSisRegProLPtrPerPrim,&lSisRegProLPtrPerAct);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrPerPrim);*/
}

}
