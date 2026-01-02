#include <SqlDevoluciones.h>
#include <SiscomInsercionesSql.h>
#include <stdio.h> 
/*
 *
 *  delete from ventas where idventa=1611962464 and cveproducto='PROTO-102';||
    delete from ventas where idventa=1611962464 and cveproducto='LM35';||
    delete from ventas where idventa=1611962464 and cveproducto='SENSOR-ULTRASONICO';||
    delete from ventas where idventa=1611962464 and cveproducto='RUEDALOCA';||
    update ventascaja set total=total-175.00,recibio=recibio-175.00 where idventa=1611962464 and idcaja=0;||
     update existencias set existencia=existencia+1.00 where cveproducto='PROTO-102' and idexpendio=-1165857915||
update existencias set existencia=existencia+1.00 where cveproducto='LM35' and idexpendio=-1165857915||
update existencias set existencia=existencia+1.00 where cveproducto='SENSOR-ULTRASONICO' and idexpendio=-1165857915||
update existencias set existencia=existencia+1.00 where cveproducto='RUEDALOCA' and idexpendio=-1165857915||
update importeorden set importe=importe-175.00 where idventa=1611962464 ;||

 *
 */

int SqlDevolucionOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
     lchrArrSql[256];

  SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
  				       "Envio",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDato,
				       DeleteVentasDevolucion);

  SiscomAgregaSentenciasSqlCampoAsociado("SqlOrden",
  					 "Envio",
					 "Productos",
					 lchrArrBuffer,
					 lchrArrSql,
					 pSiscomOpePtrDato,
					 UpdateExistenciaDevolucion);
  SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
  				       "Envio",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDato,
				       DeletePagaConDevolucion);


  SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
  				       "Envio",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDato,
				       DeleteEscuelaOrdenDevolucion);

  SiscomAgregaSentenciasSqlDelAsociado("SqlOrden",
  				       "Envio",
				       lchrArrBuffer,
				       lchrArrSql,
				       pSiscomOpePtrDato,
				       DeleteImporteOrdenDevolucion);
  SiscomEnviaRegistrosAlServidorBD("SqlOrden",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}

void DeleteImporteOrdenDevolucion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"delete from importeorden where idventa=%s;",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato));

}
void DeleteVentasDevolucion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"delete from ventas where idventa=%s;",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato));

}

void UpdateExistenciaDevolucion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update existencias set existencia=existencia+%s where cveproducto='%s'",
	SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDato));
}



void DeletePagaConDevolucion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"delete from pagacon where idventa=%s;",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato));

}

void DeleteEscuelaOrdenDevolucion(SiscomOperaciones *pSiscomOpePtrDato,
				      SiscomRegistroProL *pSiscomRegProLPtrDato,
				      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"delete from escuelaorden where idventa=%s;",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato));
}
