#include <SqlTiendaLinea.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
void SqlConsultaOrdenesTiendaLinea(SiscomOperaciones *pSisOpePtrDato,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"					\n\
	select ordenid,				\n\
	ordenfecha,				\n\
	ordenpreciototal,			\n\
	clienteid,				\n\
	clientenombre,				\n\
	clienteapellido,			\n\
	clientecelular,				\n\
	direccioncalle,				\n\
	direccionnoexterior,			\n\
	direccionnointerior,			\n\
	direccioncp,				\n\
	direccionestado,			\n\
	ordenmetodopago,			\n\
	ordenpuntoentrega,			\n\
	ordenstatus,				\n\
	itemid,					\n\
	productocodigo,				\n\
	productostock,				\n\
	itemcantidad				\n\
from siscom_ordenes inner join			\n\
	siscom_ordenes_items using (ordenid)	\n\
order by ordenid");

}
int SqlPedidosTiendaLinea(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[8192],lchrArrSql[1024];
SiscomRegistroProL *lSisRegProLPtrPrimReg=0,
		   *lSisRegProLPtrActReg=0;
int lintSocketAd;
SqlConsultaOrdenesTiendaLinea(pSisOpePtrDato,lchrArrSql);
SiscomConsultasSql2(lchrArrBuffer,
		    pSisOpePtrDato->chrArrDirIpSvrAccesoDatos,
		    "ecommerce",
		    "5435",
		    "www.siscomelectronicastore.com",
		    "siscomita",
		    "siscomita2021*",
		    pSisOpePtrDato->intPuertoSvrAccesoDatos,
		    &lSisRegProLPtrPrimReg,
		    &lSisRegProLPtrActReg,
		    &lintSocketAd,
		    "Ordenes%",
		    lchrArrSql);

SiscomAgregaArgumentoOperacion("PedidosTiendaLinea",
				lSisRegProLPtrPrimReg,
				lSisRegProLPtrActReg,
                                pSisOpePtrDato);
return 1;
}
