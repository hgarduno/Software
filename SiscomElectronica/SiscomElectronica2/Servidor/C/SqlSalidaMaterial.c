#include <SqlSalidaMaterial.h>

void SqlRegistraSalidaMaterial(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBuffer[128];
SiscomInsercionActualizacionEntradaSubRegistroAArgumento(pSAgsSiscom,
					"SqlSalidaMaterial",
					SqlSentenciaInsertSalidaMaterial);
}
void SqlSentenciaInsertSalidaMaterial(
		const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
		SArgsSiscom *pSAgsSiscom,
		LCamposSiscomPro2 **pLCSiscomPro2PrimReg,
		LCamposSiscomPro2 **pLCSiscomPro2ActReg,
		int *pintPtrNRegRegreso)
{
char lchrArrSql[128];
sprintf(lchrArrSql,
"insert into SalidaMaterial values(%s,%s,'%s');",
SiscomObtenCampoArgumento("DatosSalidaMaterial","IdRegistro",pSAgsSiscom),
SiscomCampoSubRegistro(0,"idmotivo",pLCSiscomPro2SRDat),
SiscomObtenCampoArgumento("DatosSalidaMaterial","Fecha",pSAgsSiscom));
SiscomAnexaRegistroPro2(
	pLCSiscomPro2PrimReg,
	pLCSiscomPro2ActReg,
	pintPtrNRegRegreso,
	"ComandoSQL,EdoRegistro",
	lchrArrSql,
	"");
}
void SqlRegistraDetalleSalidaMaterial(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[128];

SiscomInsercionActualizacionSubRegistros(
   1,
   pSAgsSiscom,
   "SqlSalidaMaterial",
    lchrArrSql,
    SqlSentenciaInsertDetalleSalidaMaterial);
}

void SqlActualizaInventario(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[128];
SiscomInsercionActualizacionSubRegistros(
   1,
   pSAgsSiscom,
   "SqlSalidaMaterial",
    lchrArrSql,
    SqlSentenciaActualizaExistencias);
}
void SqlSentenciaInsertDetalleSalidaMaterial(
		LCamposSiscomPro2 *pLCSiscomPro2Dat,
		SArgsSiscom *pSAgsSiscom,
		char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"insert into DetalleSalidaMaterial values(%s,'%s',%s);",
SiscomObtenCampoArgumento("DatosSalidaMaterial","IdRegistro",pSAgsSiscom),
SiscomObtenDato(pLCSiscomPro2Dat,"Clave"),
SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"));

}

void SqlSentenciaActualizaExistencias(
		LCamposSiscomPro2 *pLCSiscomPro2Dat,
		SArgsSiscom *pSAgsSiscom,
		char *pchrPtrSql)
{
sprintf(pchrPtrSql,
"update existencias set Existencia=Existencia-%s where CveProducto='%s' and IdExpendio=%s",
SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"),
SiscomObtenDato(pLCSiscomPro2Dat,"Clave"),
SiscomCampoSubRegistroPrincipalArgs("IdExpendio",pSAgsSiscom));
}
