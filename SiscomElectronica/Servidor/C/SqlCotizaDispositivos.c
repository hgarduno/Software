#include <SqlCotizaDispositivos.h>
#include <ComunElectronica2.h>
void SqlDefinicionTipoProducto(const char *pchrPtrIdExpendio,
			       const char *pchrPtrSql,
			      SArgsSiscom *pSAgsSiscom)
{
SiscomLog("%s",pchrPtrSql);
SqlAExpendioAsignaArgumento(pchrPtrIdExpendio,
			    "SqlTipoProducto",
			    pchrPtrSql,
			    pSAgsSiscom);
}
void SqlDatosBaseRegistroEntrada(const char *pchrPtrIdExpendio,
				 const char *pchrPtrSql,
				 SArgsSiscom *pSAgsSiscom)
{

SqlAExpendioAsignaArgumento(pchrPtrIdExpendio,
			    "SqlProductosEntrada",
			    pchrPtrSql,
			    pSAgsSiscom);
}

void SqlFaltanteProducto(const char *pchrPtrCveProducto,
			 SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select * 				\n\
	 from faltantes				\n\
	 where cveproducto='%s' and 		\n\
	 	idedofaltante=0", 
	 pchrPtrCveProducto);
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseAsignaArgumento("SqlProductoFaltante",
				   lchrArrSql,
				   pSAgsSiscom);
}
void SqlDefinicionProductoSiscom(const char *pchrPtrCveProducto,
			 	SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"select * 						\n\
	 from definiciontiposproducto 				\n\
	 where idproducto in(select idproducto 			\n\
	 		     from productoportipoproducto 	\n\
			     where cveproducto='%s');",
	 pchrPtrCveProducto);
SiscomLog("%s",lchrArrSql);
SiscomConsultaBaseAsignaArgumento("SqlFabricadoSiscom",
				   lchrArrSql,
				   pSAgsSiscom);
}

void SqlRegistraFaltante(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[128];
SiscomGeneraInsercionActualizacionReCorreArgEntrada(pSAgsSiscom,
						    "IdsFaltantes",
						    "SqlFaltantes",
						    lchrArrSql,
						    SqlInsertIntoFaltantes);
}

void SqlIncrementaVecesPedido(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[128];
SiscomGeneraInsercionActualizacionReCorreArgEntrada(pSAgsSiscom,
						    "IdsFaltantes",
						    "SqlFaltantes",
						    lchrArrSql,
						    SqlUpdateVecesFaltantes);
}
void SqlInsertIntoFaltantes(SArgsSiscom *pSAgsSiscom,
			    LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into Faltantes values(%s,0,'%s',1);",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdFaltante"),
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"));
}


void SqlInsertandoDetalleFaltante(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[128];
SiscomGeneraInsercionActualizacionReCorreArgEntrada(pSAgsSiscom,
						    "IdsFaltantes",
						    "SqlFaltantes",
						    lchrArrSql,
						    SqlInsertIntoDetalleFaltante);
}

void SqlInsertIntoDetalleFaltante(SArgsSiscom *pSAgsSiscom,
			    LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DetalleFaltante values(%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdFaltante"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Fecha"));
}

void SqlUpdateVecesFaltantes(SArgsSiscom *pSAgsSiscom,
			    LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update faltantes set veces=veces+1 where cveproducto='%s' and idfaltante=%s",
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdFaltante"));
SiscomLog("%s",pchrPtrSql);
}
