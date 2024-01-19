#include <SiscomCamposProtocolo.h>
/* Martes 8 de Mayo del 2012
 * Se buscara en la lista de campos pchrPtrCampo
 * en el cual pchrPtrCampo, contiene registros asociados 
 * una vez localizado el campo, se buscara el campo pchrPtrCampoAsociado
 * de los registros asociados, si hay varios registros, se regresara 
 * solo el valor del primero.
 */
const char *SiscomCampoRegistroAsociado(const char *pchrPtrCampo,
			const char *pchrPtrCampoAsociado,
			const SiscomRegistroProL *pSiscomRegProLPtrActual)
{
SiscomRegistroProL *lSiscomRegProLPtrDat;
SiscomCampoProL *lSiscomCamProLPtrDat;
if((lSiscomRegProLPtrDat=SiscomObtenRegistrosCampoProL(
			   pchrPtrCampo,
			   (SiscomRegistroProL *)pSiscomRegProLPtrActual)))
{
if((lSiscomCamProLPtrDat=SiscomObtenCampoRegistroProL(
				pchrPtrCampoAsociado,
				lSiscomRegProLPtrDat)))
return lSiscomCamProLPtrDat->chrPtrDato ? 
       lSiscomCamProLPtrDat->chrPtrDato : 
       "";

}
			
return "";
}

const char *SiscomCampoRegistro(
		const char *pchrPtrCampo,
		const SiscomRegistroProL *pSiscomRegProLPtrActual)
{
SiscomCampoProL *lSiscomCamProLPtrDat=0;

if((lSiscomCamProLPtrDat=SiscomObtenCampoRegistroProL(
				pchrPtrCampo,
				(SiscomRegistroProL *)pSiscomRegProLPtrActual)))
{
return lSiscomCamProLPtrDat->chrPtrDato ? 
       lSiscomCamProLPtrDat->chrPtrDato : 
       "";

}
return "";
}


SiscomCampoProL *SiscomDuplicaEstructuraRegistro(const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomCampoProL *lSiscomCamProLPtrDato;
SiscomCampoProL *lSiscomCamProLPtrPrim=0,
		*lSiscomCamProLPtrAct=0;
lSiscomCamProLPtrDato=pSiscomRegProLPtrAct->SiscomCamProLPtrDato;
while(lSiscomCamProLPtrDato)
{
SiscomNodoCampoPro2(lSiscomCamProLPtrDato->chrPtrNmbCampo,
		    lSiscomCamProLPtrDato->chrPtrDato,
		    &lSiscomCamProLPtrPrim,
		    &lSiscomCamProLPtrAct);
lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
}
return lSiscomCamProLPtrPrim;
}
