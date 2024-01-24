#ifndef __SQLSALIDAMATERIAL_H__
#define __SQLSALIDAMATERIAL_H__
#include <SiscomDesarrollo2.h>

void SqlRegistraSalidaMaterial(SArgsSiscom *pSAgsSiscom);
void SqlRegistraDetalleSalidaMaterial(SArgsSiscom *pSAgsSiscom);
void SqlActualizaInventario(SArgsSiscom *pSAgsSiscom);

void SqlSentenciaInsertSalidaMaterial(
		const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
		SArgsSiscom *pSAgsSiscom,
		LCamposSiscomPro2 **pLCSiscomPro2PrimReg,
		LCamposSiscomPro2 **pLCSiscomPro2ActReg,
		int *pintPtrNRegRegreso);

void SqlSentenciaInsertDetalleSalidaMaterial(
		LCamposSiscomPro2 *pLCSiscomPro2Dat,
		SArgsSiscom *pSAgsSiscom,
		char *pchrPtrSql);
void SqlSentenciaActualizaExistencias(
		LCamposSiscomPro2 *pLCSiscomPro2Dat,
		SArgsSiscom *pSAgsSiscom,
		char *pchrPtrSql);
#endif
