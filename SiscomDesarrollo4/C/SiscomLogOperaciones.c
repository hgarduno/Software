#include <SiscomLogOperaciones.h>
#include <SiscomManejoLog.h>
#include <SiscomDesarrolloMacros.h>
void SiscomMuestraAsociadosArgumento(const char *pchrPtrArchivo,
				     const char *pchrPtrFuncion,
				     int pintNLinea,
				     const char *pchrPtrArgumento,
				     const char *pchrPtrAsociado,
				     char *pchrPtrBuffer,
				     SiscomOperaciones *pSiscomOpPtrDat)
{
SiscomRegistroProL *lSiscomRegProLPtrDat;
if((lSiscomRegProLPtrDat=SiscomObtenArgumentoPrimOperaciones(pchrPtrArgumento,
							pSiscomOpPtrDat)))
SiscomMuestraRegistrosAsociados(pchrPtrArchivo,
				pchrPtrFuncion,
				pintNLinea,
				pchrPtrBuffer,
				pchrPtrAsociado,
				lSiscomRegProLPtrDat);
else
LogSiscom("No se encontro el argumento %s",pchrPtrArgumento);
}


void SiscomMuestraArgumento(const char *pchrPtrArchivo,
				     const char *pchrPtrFuncion,
				     int pintNLinea,
				     const char *pchrPtrArgumento,
				     char *pchrPtrBuffer,
				     SiscomOperaciones *pSiscomOpPtrDat)
{
SiscomRegistroProL *lSiscomRegProLPtrDat;
lSiscomRegProLPtrDat=SiscomObtenArgumentoPrimOperaciones(pchrPtrArgumento,
							pSiscomOpPtrDat);

SiscomMuestraRegistrosProtocolo(pchrPtrArchivo,
				pchrPtrFuncion,
				pintNLinea,
				pchrPtrBuffer,
				lSiscomRegProLPtrDat);
}

void SiscomAsociadoRespuesta(const char *pchrPtrArchivo,
				     const char *pchrPtrFuncion,
				     int pintNLinea,
				     const char *pchrPtrAsociado,
				     char *pchrPtrBuffer,
				     SiscomOperaciones *pSiscomOpePtrDat)
{
SiscomRegistroProL *lSiscomRegProLPtrDat;
lSiscomRegProLPtrDat=pSiscomOpePtrDat->SiscomRegProLPtrPrimRes;
SiscomMuestraRegistrosAsociados(pchrPtrArchivo,
				pchrPtrFuncion,
				pintNLinea,
				pchrPtrBuffer,
				pchrPtrAsociado,
				lSiscomRegProLPtrDat);
}

void SiscomAsociadoEntrada(const char *pchrPtrArchivo,
				     const char *pchrPtrFuncion,
				     int pintNLinea,
				     const char *pchrPtrAsociado,
				     char *pchrPtrBuffer,
				     SiscomOperaciones *pSiscomOpePtrDat)
{
SiscomRegistroProL *lSiscomRegProLPtrDat;
lSiscomRegProLPtrDat=pSiscomOpePtrDat->SiscomRegProLPtrPrimEnt;
SiscomMuestraRegistrosAsociados(pchrPtrArchivo,
				pchrPtrFuncion,
				pintNLinea,
				pchrPtrBuffer,
				pchrPtrAsociado,
				lSiscomRegProLPtrDat);
}

void SiscomRegistroEntrada(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintNLinea,
			   char *pchrPtrBuffer,
			   SiscomOperaciones *pSiscomOpePtrDat)
{
  SiscomMuestraRegistrosProtocolo(pchrPtrArchivo,
  				  pchrPtrFuncion,
				  pintNLinea,
				  pchrPtrBuffer,
				  pSiscomOpePtrDat->SiscomRegProLPtrPrimEnt);
}

void SiscomRegistroRegreso(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintNLinea,
			   char *pchrPtrBuffer,
			   SiscomOperaciones *pSiscomOpePtrDat)
{
  SiscomMuestraRegistrosProtocolo(pchrPtrArchivo,
  				  pchrPtrFuncion,
				  pintNLinea,
				  pchrPtrBuffer,
				  pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);


}

void SiscomAsociadoAsociadoEntradaAlLog(const char *pchrPtrCampo,
				      const char *pchrPtrAsociado,
				      const char *pchrPtrArchivo,
				      const char *pchrPtrFuncion,
				      int pintNLinea,
				      char *pchrPtrBuffer,
				      SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrAsociado;

if((lSisRegProLPtrAsociado=SiscomRegistrosAsociadosCampoEntrada(pchrPtrCampo,
								pchrPtrAsociado,
								pSisOpePtrDato)))
SiscomMuestraRegistrosProtocolo(pchrPtrArchivo,
				pchrPtrFuncion,
				pintNLinea,
				pchrPtrBuffer,
				lSisRegProLPtrAsociado);

								


}
