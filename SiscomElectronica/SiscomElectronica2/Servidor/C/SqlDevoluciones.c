#include <SqlDevoluciones.h>
void SqlEliminaProductosVenta(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
	pSAgsSiscom,
	"SqlDevoluciones",
	SqlGeneraEliminaProductosVenta);
}
void SqlGeneraEliminaProductosVenta(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			      LCamposSiscomPro2 **pLCSiscomPro2Prim,
			      LCamposSiscomPro2 **pLCSiscomPro2Act,
			      int *pintPtrNRegistros)
{
char lchrArrSql[256];
LCamposSiscomPro2 *lLCSiscomPro2Dat=pLCSiscomPro2Dat;
for(;
	lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
{
sprintf(lchrArrSql,
	"delete from ventas where idventa=%s and cveproducto='%s';",
	SiscomObtenDato(lLCSiscomPro2Dat,"IdVenta"),
	SiscomObtenDato(lLCSiscomPro2Dat,"CveProducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
}

void SqlActualizaVentaCaja(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion2(
		pSAgsSiscom,
		"SqlDevoluciones",
		SqlGeneraActualizaVentaCaja);
}
void SqlGeneraActualizaVentaCaja(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				LCamposSiscomPro2 *pLCSiscomPro2Ultimo,
			      LCamposSiscomPro2 **pLCSiscomPro2Prim,
			      LCamposSiscomPro2 **pLCSiscomPro2Act,
			      int *pintPtrNRegistros)
{
char lchrArrSql[1024];
LCamposSiscomPro2 *lLCSiscomPro2Dat=pLCSiscomPro2Ultimo;
sprintf(lchrArrSql,
	"update ventascaja set total=total-%s,recibio=recibio-%s where idventa=%s and idcaja=%s;",
	 SiscomObtenDato(lLCSiscomPro2Dat,"TotalADevolver"),
	 SiscomObtenDato(lLCSiscomPro2Dat,"TotalADevolver"),
	 SiscomObtenDato(lLCSiscomPro2Dat,"IdVenta"),
	 SiscomObtenDato(lLCSiscomPro2Dat,"IdCaja"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
		     pLCSiscomPro2Act,
		     pintPtrNRegistros,
		     "ComandoSQL,EdoRegistro",
		     lchrArrSql,
		     "");
}

void SqlActualizaImporteOrden(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion2(
		pSAgsSiscom,
		"SqlDevoluciones",
		SqlGeneraActualizaImporteOrden);
}
void SqlGeneraActualizaImporteOrden(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				LCamposSiscomPro2 *pLCSiscomPro2Ultimo,
			      LCamposSiscomPro2 **pLCSiscomPro2Prim,
			      LCamposSiscomPro2 **pLCSiscomPro2Act,
			      int *pintPtrNRegistros)
{
char lchrArrSql[1024];
LCamposSiscomPro2 *lLCSiscomPro2Dat=pLCSiscomPro2Ultimo;
sprintf(lchrArrSql,
	"update importeorden set importe=importe-%s where idventa=%s ;",
	 SiscomObtenDato(lLCSiscomPro2Dat,"TotalADevolver"),
	 SiscomObtenDato(lLCSiscomPro2Dat,"IdVenta"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
		     pLCSiscomPro2Act,
		     pintPtrNRegistros,
		     "ComandoSQL,EdoRegistro",
		     lchrArrSql,
		     "");
}



void SqlActualizaExistencia(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
	pSAgsSiscom,
	"SqlDevoluciones",
	SqlGeneraActualizaExistencia);

}
void SqlGeneraActualizaExistencia(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			      LCamposSiscomPro2 **pLCSiscomPro2Prim,
			      LCamposSiscomPro2 **pLCSiscomPro2Act,
			      int *pintPtrNRegistros)
{
char lchrArrSql[1024];
LCamposSiscomPro2 *lLCSiscomPro2Dat=pLCSiscomPro2Dat;
for(;
	lLCSiscomPro2Dat;
	lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
{
sprintf(lchrArrSql,
	"update existencias set existencia=existencia+%s where cveproducto='%s' and idexpendio=%s",
	 SiscomObtenDato(lLCSiscomPro2Dat,"Cantidad"),
	 SiscomObtenDato(lLCSiscomPro2Dat,"CveProducto"),
	 SiscomObtenDato(lLCSiscomPro2Dat,"IdExpendio"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
		     pLCSiscomPro2Act,
		     pintPtrNRegistros,
		     "ComandoSQL,EdoRegistro",
		     lchrArrSql,
		     "");
}
}

