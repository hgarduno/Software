#include <SqlCancelacionFolios.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <stdio.h>

int SqlRegistraCancelacionFolio(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
SiscomRegistroProL *lSisRegProLPtrDat;
SiscomAgregaArgumentoInsercionSql("SqlInsertaCancelacionFolio",
				  pSiscomOpePtrDat->chrArrBaseDatos,
				  pSiscomOpePtrDat->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDat);

SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaCancelacionFolio",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     InsertToCancelacionFolios);
SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaCancelacionFolio",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateFolioVenta);
SiscomAgregaSentenciasSqlDelAsociado("SqlInsertaCancelacionFolio",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDat,
				     UpdateFolioActualFacturaPorCancelacion);

SiscomReplicaMaquinaLocal("SqlInsertaCancelacionFolio", lchrArrBuffer, 0, pSiscomOpePtrDat);
}


void InsertToCancelacionFolios(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into FolioCancelado values(%s,%s,%s,%s,'%s');",
	 SiscomObtenCampoRegistroProLChar("IdCancelacionFolio",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("FolioCancelado",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("FolioNuevo",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("Motivo",pSiscomRegProLPtrEnt));
}
void UpdateFolioVenta(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
   sprintf(pchrPtrSql,
   	   "update ventas set folio=%s where idventa=%s",
	 SiscomObtenCampoRegistroProLChar("FolioNuevo",pSiscomRegProLPtrEnt),
	 SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrEnt));
}
void UpdateFolioActualFacturaPorCancelacion(SiscomOperaciones *pSiscomOpePtrDatos,
		      SiscomRegistroProL *pSiscomRegProLPtrEnt,
		      char *pchrPtrSql)
{
   sprintf(pchrPtrSql,
   	   "update folioactual set folio=%s where idtipofolio=0",
	 SiscomObtenCampoRegistroProLChar("FolioNuevo",pSiscomRegProLPtrEnt));
}

