#include <SqlPromocionesElectronica.h>

void SqlRegistraPromocion(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacionCiclo(
	pSAgsSiscom,
	"SqlPromocion",
	SqlInsertaPromocion);
}

void SqlInsertaPromocion(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSql[2048];

sprintf(lchrArrSql,
	"insert into promocion values(%s,'%s','%s','%s',%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdPromocion"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Nombre"),
	SiscomObtenDato(pLCSiscomPro2Dat,"FechaIni"),
	SiscomObtenDato(pLCSiscomPro2Dat,"FechaFin"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Puntos"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Descripcion"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
