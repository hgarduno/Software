#include <SqlCorteCaja.h>
void SqlInsertaDetalleCorteCaja(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
                pSAgsSiscom,
		"SqlCorteCaja",
		SqlGeneraInsertaDetalleCorteCaja);
}
void SqlGeneraInsertaDetalleCorteCaja(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[256];
const char *lchrPtrIdReporte=SiscomObtenDato(pLCSiscomPro2,"IdReporte");
for(;
     pLCSiscomPro2;
     pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
{
sprintf(lchrArrSql,
	"insert into DetalleCorteCaja values(%s,%s,%s,%s);",
	lchrPtrIdReporte,
	SiscomObtenDato(pLCSiscomPro2,"Importe"),
	SiscomObtenDato(pLCSiscomPro2,"Denominacion"),
	SiscomObtenDato(pLCSiscomPro2,"Cantidad"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}

void SqlInsertaCorteCaja(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
                pSAgsSiscom,
		"SqlCorteCaja",
		SqlGeneraInsertaCorteCaja);
}
void SqlGeneraInsertaCorteCaja(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[256];
char lchrArrFechaHora[25];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFechaHora);
sprintf(lchrArrSql,
	"insert into CorteCaja values(%s,%s,'%s',%s,%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdCaja"),
	SiscomObtenDato(pLCSiscomPro2,"IdReporte"),
	lchrArrFechaHora,
	SiscomObtenDato(pLCSiscomPro2,"IdEmpleado"),
	SiscomObtenDato(pLCSiscomPro2,"Total"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}



void SqlActualizaEstadoCaja(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
                pSAgsSiscom,
		"SqlCorteCaja",
		SqlGeneraActualizaEstadoCaja);

}
void SqlGeneraActualizaEstadoCaja(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"update EstadoCaja set Importe=%s-%s 	\n\
	 where idCaja=%s",
	SiscomObtenDato(pLCSiscomPro2,"ImporteActualCaja"),
	SiscomObtenDato(pLCSiscomPro2,"Total"),
	SiscomObtenDato(pLCSiscomPro2,"IdCaja"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

