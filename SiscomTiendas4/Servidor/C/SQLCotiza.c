#include <SQLCotiza.h>
#include <string.h>
#include <stdlib.h>
void SQLDatosProducto(SArgsSiscom *pSAgsSiscom)
{
char *lchrPtrSQL;
char lchrArrSQLInicio[256];
LCamposSiscomPro2 *lLCSiscomPro2Dat;
LCamposSiscomPro2 *lLCSiscomPro2Reg;
int lintNRespuesta;
/*
 *
 * Se debe cambiar el in de la busqueda en la base de 
 * datos por un or, ya que si el producto no esta 
 * registrado en el inventario la consulta no regresara
 * nada 
 *
 */
/*
 * Miercoles 23 de enero 2008 Queretaro
 * El problema que se detecto en esta rutina esta en 
 * el hecho de que aunque en la interfaz se selecciono
 * un precio diferente para cada producto de la cotizacion
 * por la forma en la que se estructura la sentencia
 * SQL tomara siempre el primer precio.
 *
 * 
 sprintf(lchrArrSQLInicio,
"					\
select *,				\
	'' as SePuedeVender,		\
	'' as Importe			\
from	preciosproducto  inner join 	\
	inventario using(idproducto)	\
where idprecio=%s   and			\
      idexpendio=%s and			\
      idproducto in(			\
",
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPrecio"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdExpendio"));
*
*
*/

sprintf(lchrArrSQLInicio,
"							\
select *,						\
	'' as SePuedeVender,				\
	'' as Importe					\
from	preciosproducto  inner join 			\
	inventario using(idproducto) inner join 	\
	producto using(idproducto)			\
where");

lchrPtrSQL=(char *)malloc(strlen(lchrArrSQLInicio));
strcpy(lchrPtrSQL,lchrArrSQLInicio);
for(lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
     lLCSiscomPro2Dat;
     lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
{

	if(lLCSiscomPro2Dat->SCP2PtrSig)
	/*
	 *  Correxion para el manejo del precio seleccionado
	 *  en cada producto
	  sprintf(lchrArrSQLInicio,
	  	  "%s,",
		  SiscomObtenDato(lLCSiscomPro2Dat,"IdProducto"));
	*/
	sprintf(lchrArrSQLInicio,
		"(idprecio=%s 	and				\
		  idexpendio=%s	and				\
		  idproducto=%s) or ",
		SiscomObtenDato(lLCSiscomPro2Dat,"IdPrecio"),
		SiscomObtenDato(lLCSiscomPro2Dat,"IdExpendio"),
		SiscomObtenDato(lLCSiscomPro2Dat,"IdProducto"));

	else
	/*
	 *  Correxion para el manejo del precio seleccionado
	 *  en cada producto
	 sprintf(lchrArrSQLInicio,
	 	 "%s);",
		 SiscomObtenDato(lLCSiscomPro2Dat,"IdProducto"));
	 */
	sprintf(lchrArrSQLInicio,
		"(idPrecio=%s	and 				\
		 idexpendio=%s	and				\
		 idproducto=%s)",
		SiscomObtenDato(lLCSiscomPro2Dat,"IdPrecio"),
		SiscomObtenDato(lLCSiscomPro2Dat,"IdExpendio"),
		SiscomObtenDato(lLCSiscomPro2Dat,"IdProducto"));

	lchrPtrSQL=(char *)realloc(lchrPtrSQL,
				   strlen(lchrPtrSQL)+
				   strlen(lchrArrSQLInicio)+2);
	strcat(lchrPtrSQL,lchrArrSQLInicio);
}
SiscomConsultaBaseDatosSinDatosConexion(
	  lchrPtrSQL,
          pSAgsSiscom->chrArrDirIpAD,
          pSAgsSiscom->intPtoComAD,
          &lLCSiscomPro2Reg,
          &lintNRespuesta);
  SiscomAsignaInformacionArgumento("DatosCotiza",
                              pSAgsSiscom,
                              lLCSiscomPro2Reg,
                              0,
                              lintNRespuesta);
SiscomContenidoProtocolo(lLCSiscomPro2Reg);
free(lchrPtrSQL);
}
