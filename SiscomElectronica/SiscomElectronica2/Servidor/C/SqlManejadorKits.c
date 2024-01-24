#include <SqlManejadorKits.h>
void SqlRegistraProductosTipoProducto(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[128];
SiscomInsercionActualizacionSubRegistros(0,
					 pSAgsSiscom,
					 "SqlTipoProducto",
					 lchrArrSql,
					 SqlInsertIntoDefinicionTiposProducto);

}
void SqlRegistraTipoProducto(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBufferSql[128];
SiscomSqlInsercionesDatosEntrada(pSAgsSiscom,
				"SqlTipoProducto",
				lchrArrBufferSql,
				SqlInsertIntoProductoPorTipoProducto);

}
void SqlInsertIntoProductoPorTipoProducto(SArgsSiscom *pSAgsSiscom,
				 	  char *pchrPtrBufferSql,
					  LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
sprintf(pchrPtrBufferSql,
	"insert into ProductoPorTipoProducto values('%s',%s,%s);",
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdTipoProducto"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdProducto"));
}
void SqlInsertIntoDefinicionTiposProducto(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					   SArgsSiscom *pSAgsSiscom,
					   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DefinicionTiposProducto values(%s,'%s',%s);",
	SiscomCampoSubRegistroPrincipalArgs("IdProducto",pSAgsSiscom),
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"));
}
