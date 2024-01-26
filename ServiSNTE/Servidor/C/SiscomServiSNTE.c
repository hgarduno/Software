#include <SiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomArchivosIni.h>

#include <dlfcn.h>

/*  Miercoles 25   Octubre 2015 
 *  Se inicia el desarrollo la nueva version del sistema 
 *  Siscom ServiSNTE 
 */

void ServidorSiscomServiSNTE(const char *pchrPtrDirIpCliente,
		     	void *pvidPtrAncla,
		     	int pintSocket)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		    *lSiscomRegProLPtrAct=0;
SiscomVersionProtocolo4(pintSocket);
SiscomLeeRegistrosSocket(pintSocket,
			 lchrArrBuffer,
			 &lSiscomRegProLPtrPrim,
			 &lSiscomRegProLPtrAct);
/*
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
*/
SiscomRegistrosAsociadosLog(lchrArrBuffer,"ModuloServidor",lSiscomRegProLPtrPrim);
EjecutaOperacion(pintSocket,
		 pvidPtrAncla,
		 lSiscomRegProLPtrPrim,
		 lSiscomRegProLPtrAct);
}
void EjecutaOperacion(int pintSocket,
		      void *pvidPtrAncla,
		      const SiscomRegistroProL *pSiscomRegProLPtrPrim,
		      const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
const char *lchrPtrFuncion;
const char *lchrPtrModulo;
void (*lvidPtrSiscomOperacion)(int pintSocket,
			void *pvidPtrAncla,
			const SiscomRegistroProL *pSiscomRegProLPtrPrim,
			const SiscomRegistroProL *pSiscomRegProLPtrAct);
lchrPtrFuncion=SiscomCampoRegistroAsociado("ModuloServidor",
					   "Funcion",
					   pSiscomRegProLPtrAct);
lchrPtrModulo=SiscomCampoRegistroAsociado("ModuloServidor",
					   "Modulo",
					   pSiscomRegProLPtrAct);
LogSiscom("Se ejecutara:(%s) (%s)",
	   lchrPtrFuncion,
	   lchrPtrModulo);
if((lvidPtrSiscomOperacion=(void (*)(int,
			       void *,
			       const SiscomRegistroProL *,
			       const SiscomRegistroProL *))dlsym(pvidPtrAncla,lchrPtrFuncion)))
{
  lvidPtrSiscomOperacion(pintSocket,
  		  pvidPtrAncla,
		  pSiscomRegProLPtrPrim,
		  pSiscomRegProLPtrAct);
}
else
LogSiscom("dlsym(%s)",dlerror());
}
