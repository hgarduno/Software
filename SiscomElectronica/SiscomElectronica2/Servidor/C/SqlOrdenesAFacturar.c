#include <SqlOrdenesAFacturar.h>
#include <string.h>
/*
 * 1284062882 
 * 1284074312
 * 1284048541
 * 1284047547
 *
 */

void FormaCondicionOrdenesPorFacturar(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				      char *pchrPtrCondicion)
{
char lchrArrPaso[128];
     	strcpy(pchrPtrCondicion,"IdVenta in("); 
	while(pLCSiscomPro2Dat)
	{
	  if(pLCSiscomPro2Dat->SCP2PtrSig)
	  sprintf(lchrArrPaso,
	  	  "%s,",
		  SiscomObtenDato(pLCSiscomPro2Dat,"NoOrden"));
	  else
	  sprintf(lchrArrPaso,
	  	  "%s",
		  SiscomObtenDato(pLCSiscomPro2Dat,"NoOrden"));
	  strcat(pchrPtrCondicion,lchrArrPaso);
	  pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig; 
	}
	strcat(pchrPtrCondicion,")");
}
				      

void SqlProductosOrdenes(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];
char lchrArrCondicion[1024];
const char *lchrPtrIdExpendio;
FormaCondicionOrdenesPorFacturar(pSAgsSiscom->LCSiscomPro2Dat,lchrArrCondicion);
lchrPtrIdExpendio=SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdExpendio");
sprintf(lchrArrSql,
	"select cveproducto,					\n\
		cantidad,					\n\
		importe,					\n\
		precio,						\n\
		0 as \"CantidadTotal\",				\n\
		0 as \"ImporteTotal\",				\n\
		0 as \"Total\",					\n\
		0 as \"IVA\",					\n\
		0 as \"TotalMIVA\",				\n\
		'' as \"ImporteConLetra\",			\n\
		'ProductosAFacturar' as \"Dato\"		\n\
	 from ventas						\n\
	 where idexpendio=%s and 				\n\
	       %s",
	 lchrPtrIdExpendio,
	 lchrArrCondicion);
SiscomConsultaBaseSinEnvio2(lchrArrSql,pSAgsSiscom);
SiscomLog("%s",lchrArrSql);
}
