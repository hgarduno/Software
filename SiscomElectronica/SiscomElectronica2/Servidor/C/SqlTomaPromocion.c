#include <SqlTomaPromocion.h>
/*
 * Domingo 21 De Agosto 2011 
 * Bueno pues ahora a ver la forma en la que voy a 
 * llevar el control de las operaciones que se tendran
 * que realizar para que un cliente tome las promociones
 * a las que se ha hecho acreedor, por un lado debo almacenar
 * las promociones que decidio tomar el cliente, y 
 * con el total de puntos que toma descontarlo del total
 * disponible
 *
 */


void SqlSeguimientoPuntosClientes(SArgsSiscom *pSAgsSiscom)
{
SiscomInsercionActualizacionSql2(pSAgsSiscom,
				 0,
				 SqlSeguimientoPuntosClientesInserta);
}
void SqlSeguimientoPuntosClientesInserta(SArgsSiscom *pSAgsSiscom,
					 LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"insert into SeguimientoPuntosClientes values(%s,%s,%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"idpersona"),
	SiscomObtenCampoArgumento("Operacion","IdMovimiento",pSAgsSiscom),
	SiscomCampoSubRegistroArgs(2,"PuntosTotalesPromos",pSAgsSiscom),
	SiscomObtenCampoArgumento("Operacion","Fecha",pSAgsSiscom));

SiscomAnexaRegistroArgumento("SqlSeguimiento",
			     pSAgsSiscom,
			     "ComandoSQL,EdoRegistro",
			     lchrArrSql,
			     "");
}

void SqlDetalleOperacionPuntosClientes(SArgsSiscom *pSAgsSiscom)
{
SiscomInsercionActualizacionSql2(pSAgsSiscom,
				 1,
				 SqlDetalleOperacionPuntosClientesInserta);
}
void SqlDetalleOperacionPuntosClientesInserta(SArgsSiscom *pSAgsSiscom,
					 LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
char lchrArrSql[256];
const char *lchrPtrIdOperacion=SiscomObtenCampoArgumento("Operacion",	
							 "IdMovimiento",
							 pSAgsSiscom);
sprintf(lchrArrSql,
	"insert into DetalleOperacionPuntosClientes values(%s,%s,%s);",
	SiscomObtenCampoArgumento("Operacion","IdMovimiento",pSAgsSiscom),
	SiscomObtenDato(pLCSiscomPro2Dat,"idpromocion"),
	SiscomObtenDato(pLCSiscomPro2Dat,"puntos"));
SiscomAnexaRegistroArgumento("SqlSeguimiento",
			     pSAgsSiscom,
			     "ComandoSQL,EdoRegistro",
			     lchrArrSql,
			     "");
}
