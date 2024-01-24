#include <SqlTransferenciasExpendioAExpendio.h>
#include <TransferenciasExpendioAExpendio.h>
#include <SiscomReplicacion.h>
#include <SiscomInsercionesSql.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomDesarrolloMacros.h>
#include <string.h>
#include <stdio.h>
int SqlTransferenciasOtrosExpendios(SiscomOperaciones *pSiscomOpePtrDatos)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];

sprintf(lchrArrSql,
	"select a.*,								\n\
		b.razonsocial as origen,					\n\
		c.razonsocial as destino					\n\
	 from transfierematerial as a inner join 				\n\
	      empresas as b on(a.idempresaorigen=b.idempresa) inner join	\n\
	      empresas as c on(a.idempresadestino=c.idempresa) 			\n\
	 where idtransferencia in (select idtransferencia 			\n\
	 			   from transferencias 				\n\
				   where fechahora::date='%s'); ",
	 SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDatos));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDatos,
		   "Productos%",
		   lchrArrSql);
}
int SqlExistenciaExpendioOrigenDestino(SiscomRegistroProL *pSisRegProLPtrExpendios,
				       SiscomOperaciones *pSiscomOpePtrDatos)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
sprintf(lchrArrSql,
	"select a.*,						\n\
		b.precio,					\n\
		c.razonsocial					\n\
	 from existencias as a  inner join 			\n\
	      precios as b  using(cveproducto) inner join	\n\
	      empresas as c on a.idexpendio=c.idempresa 	\n\
	 where cveproducto='%s'",
	 SiscomCampoAsociadoEntradaOperacion("Envio","CveProducto",pSiscomOpePtrDatos));
pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes=0;
SiscomConsultasSqlSistema("Expendio",
			   "idempresa",
			   1,
			   pSisRegProLPtrExpendios,
			   0,
			   ErrorConexionExpendioTransferencia,
			   0,
			   lchrArrBuffer,
			   pSiscomOpePtrDatos,
			   "Existencia%",
			   lchrArrSql);
}
int SqlRegistraTransferenciaExpendioOrigen(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrBufferSql[256];

SiscomAgregaSentenciasSqlDelAsociado("SqlExpendioOrigen",
				       "Envio",
				       lchrArrBuffer,
				       lchrArrBufferSql,
				       pSiscomOpePtrDato, 
				       InsertIntoTransferencia);
SiscomAgregaSentenciasSqlCampoAsociado("SqlExpendioOrigen",
				       "Envio",
				       "Productos",
				       lchrArrBuffer,
				       lchrArrBufferSql,
				       pSiscomOpePtrDato,
				       InsertIntoTransfiereMaterial);
SiscomAgregaSentenciasSqlCampoAsociado("SqlExpendioOrigen",
				       "Envio",
				       "Productos",
				       lchrArrBuffer,
				       lchrArrBufferSql,
				       pSiscomOpePtrDato,
				       UpdateToExistencias);
}
int SqlRegistraTransferenciaExpendioDestino(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrBufferSql[256];
SiscomAgregaSentenciasSqlDelAsociado("SqlExpendioDestino",
				       "Envio",
				       lchrArrBuffer,
				       lchrArrBufferSql,
				       pSiscomOpePtrDato,
				       InsertIntoTransferencia);
SiscomAgregaSentenciasSqlCampoAsociado("SqlExpendioDestino",
				       "Envio",
				       "Productos",
				       lchrArrBuffer,
				       lchrArrBufferSql,
				       pSiscomOpePtrDato,
				       InsertIntoTransfiereMaterial);
SiscomAgregaSentenciasSqlCampoAsociado("SqlExpendioDestino",
				       "Envio",
				       "Productos",
				       lchrArrBuffer,
				       lchrArrBufferSql,
				       pSiscomOpePtrDato,
				       UpdateToExistenciasDestino);
}
void InsertIntoTransferencia(SiscomOperaciones *pSiscomOpePtrDato,
			          SiscomRegistroProL *pSiscomRegProLPtrDatos,
				  char *pchrPtrSql)
{
  sprintf(pchrPtrSql,
  	  "insert into Transferencias values(%s,%s,0,'%s');",
	  SiscomObtenCampoRegistroProLChar("ExpendioO",pSiscomRegProLPtrDatos),
	  SiscomObtenCampoRegistroProLChar("IdTransferencia",pSiscomRegProLPtrDatos),
	  SiscomObtenCampoRegistroProLChar("FechaHora",pSiscomRegProLPtrDatos));
}

void InsertIntoTransfiereMaterial(SiscomOperaciones *pSiscomOpePtrDato,
			          SiscomRegistroProL *pSiscomRegProLPtrDatos,
				  char *pchrPtrSql)
{
  sprintf(pchrPtrSql,
  	  "insert into TransfiereMaterial values('%s',%s,%s,'%s',%s,%s,%s);",
	  SiscomCampoAsociadoEntradaOperacion("Envio","FechaHora",pSiscomOpePtrDato),
	  SiscomCampoAsociadoEntradaOperacion("Envio","ExpendioO",pSiscomOpePtrDato),
	  SiscomCampoAsociadoEntradaOperacion("Envio","ExpendioD",pSiscomOpePtrDato),
	  SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDatos),
	  SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDatos),
	  SiscomCampoAsociadoEntradaOperacion("Envio","IdEmpleado",pSiscomOpePtrDato),
	  SiscomCampoAsociadoEntradaOperacion("Envio","IdTransferencia",pSiscomOpePtrDato));
}
void UpdateToExistencias(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDatos,
			char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update existencias set existencia=existencia-%s where cveproducto='%s' and idexpendio=%s;",
	  SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDatos),
	  SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDatos),
	  SiscomCampoAsociadoEntradaOperacion("Envio","ExpendioO",pSiscomOpePtrDato));
}
void UpdateToExistenciasDestino(SiscomOperaciones *pSiscomOpePtrDato,
			 SiscomRegistroProL *pSiscomRegProLPtrDatos,
			char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update existencias set existencia=existencia+%s where cveproducto='%s' and idexpendio=%s;",
	  SiscomObtenCampoRegistroProLChar("Cantidad",pSiscomRegProLPtrDatos),
	  SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDatos),
	  SiscomCampoAsociadoEntradaOperacion("Envio","ExpendioD",pSiscomOpePtrDato));
}

