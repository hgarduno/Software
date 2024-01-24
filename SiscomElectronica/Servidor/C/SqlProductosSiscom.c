#include <SqlProductosSiscom.h>
#include <SiscomInsercionesSql.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomDesarrolloMacros.h>

#include <string.h>
#include <stdlib.h>


int SqlRegistroCompraProductosSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrSql[256];
sprintf(lchrArrSql,"select * 			\n\
		    from CompraProductosSiscom 	\n\
		    where fecha='%s';",
	 SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "RegistroCompProdSiscom%",
		   lchrArrSql);
return 0;
}
int SqlComprandoProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128],
	lchrArrBufferSql[128];

SiscomAgregaSentenciasSqlCampoAsociado("SqlProductoSiscom",
					"Envio",
					"Productos",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					UpdateExistenciaDefinicionProductoSiscom);

SiscomAgregaSentenciasSqlDelAsociado("SqlProductoSiscom",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrBufferSql,
				     pSiscomOpePtrDato,
				     UpdateExistenciaProductoSiscom);


SiscomAgregaSentenciasSqlDelAsociado("SqlProductoSiscom",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrBufferSql,
				     pSiscomOpePtrDato,
				     InsertToCompraProductoSiscom);

SiscomAgregaSentenciasSqlDelAsociado("SqlProductoSiscom",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrBufferSql,
				     pSiscomOpePtrDato,
				     InsertToProductosSiscomComprados);

SiscomAgregaSentenciasSqlCampoAsociado("SqlProductoSiscom",
					"Envio",
					"Productos",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToDetalleCompraProductoSiscom);
SiscomAgregaSentenciasSqlCampoAsociado("SqlProductoSiscom",
					"Envio",
					"Productos",
					lchrArrBuffer,
					lchrArrBufferSql,
					pSiscomOpePtrDato,
					InsertToOrigenProductoSiscom);

SiscomEnviaRegistrosAlServidorBD("SqlProductoSiscom",lchrArrBuffer,pSiscomOpePtrDato); 
return 0;
}

void UpdateExistenciaDefinicionProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql)
{
if(!SiscomComparaCadenaCampoRegistroProL("Expendio","Origen",pSiscomRegProLPtrDato))
sprintf(pchrPtrSql,
	"update existencias set existencia=existencia-%s*%s where cveproducto='%s';",
	 SiscomObtenCampoRegistroProLChar("cantidad",pSiscomRegProLPtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","CantidadAComprar",pSiscomOpePtrDato),
	 SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrDato));
if(!SiscomComparaCadenaCampoRegistroProL("Bodega","Origen",pSiscomRegProLPtrDato))
sprintf(pchrPtrSql,
	"update MaterialBodega set existencia=existencia-%s*%s where cveproducto='%s';",
	 SiscomObtenCampoRegistroProLChar("cantidad",pSiscomRegProLPtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","CantidadAComprar",pSiscomOpePtrDato),
	 SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrDato));


}
void UpdateExistenciaProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update existencias set existencia=existencia+%s where cveproducto='%s';",
	 SiscomObtenCampoRegistroProLChar("CantidadAComprar",pSiscomRegProLPtrDato),
	 SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDato));
}

void InsertToCompraProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into CompraProductosSiscom values(%s,'%s')",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdCompra",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato));

}

void InsertToProductosSiscomComprados(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into ProductosSiscomComprados values(%s,%s,%s);",
	 SiscomObtenCampoRegistroProLChar("IdCompra",pSiscomRegProLPtrDato),
	 SiscomObtenCampoRegistroProLChar("IdProducto",pSiscomRegProLPtrDato),
	 SiscomObtenCampoRegistroProLChar("CantidadAComprar",pSiscomRegProLPtrDato));
}

void InsertToDetalleCompraProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DetalleCompraProductoSiscom values(%s,%s,'%s',%s*%s);",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdCompra",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDato),
	 SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrDato),
	 SiscomObtenCampoRegistroProLChar("cantidad",pSiscomRegProLPtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","CantidadAComprar",pSiscomOpePtrDato));
}

void InsertToOrigenProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDato,
			 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into OrigenProductoSiscom values(%s,'%s','%s');",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdCompra",pSiscomOpePtrDato),
	 SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrDato),
	 SiscomObtenCampoRegistroProLChar("Origen",pSiscomRegProLPtrDato));
}

int SqlExistenciasDefinicionProducto(const char *pchrPtrCondicion,
				     SiscomOperaciones *pSiscomOpePtrDato)
{
int lintTamBuffer;
char *lchrPtrBuffer;
const char *lchrPtrSelect="select * from existenciaexpendiobodegas";
char *lchrPtrSql;
lintTamBuffer=strlen(pchrPtrCondicion)+strlen(lchrPtrSelect)+1;
lchrPtrBuffer=malloc(lintTamBuffer);
lchrPtrSql=malloc(lintTamBuffer);
sprintf(lchrPtrSql,
	"%s %s",lchrPtrSelect,pchrPtrCondicion);
SiscomConsultasSqlOperaciones(lchrPtrBuffer,
		   pSiscomOpePtrDato,
		   "ExisDefinicionProd%",
		   lchrPtrSql);
return 0;
}
