#include <SqlCircuitoImpreso.h>
#include <stdio.h>
#include <SiscomInsercionesSql.h>

int SqlEstadosImpresosSE(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[256];
sprintf(lchrArrSql,
	"					\n\
	select * 				\n\
	from estadoscircuitoimpreso 		\n\
	order by idestado ");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSiscomOpePtrDato,
		   "EstadosImpresos%",
		   lchrArrSql);

}
/* Tepotzotlan Mexico 
 * Miercoles 26 de Julio del 2017
 * se elimino la condicion de solo los registrados,
 * para poder tener una lista completa por estatus
 * y visualizar 
 */
int SqlCircuitosImpresosPendientes(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[2048],
	lchrArrSql[2048];
sprintf(lchrArrSql,
	"										\n\
select  a.*,										\n\
	e.nombre,									\n\
	e.apaterno,									\n\
	e.nombre || 									\n\
	' '	 ||									\n\
	e.apaterno as NombreCompleto,							\n\
	g.archivo,									\n\
	g.memoria,									\n\
	h.telefono,									\n\
	f.fecha::date,									\n\
	f.fecha::time as hora,								\n\
	c.descripcion									\n\
from circuitoimpreso as a inner join 							\n\
	ultimoestadocircuitoimpreso as b using(idimpreso) inner join 			\n\
	estadoscircuitoimpreso as c using(idestado) inner join				\n\
	estadocircuitoimpreso as d on (b.idimpreso=d.idimpreso and 			\n\
				       b.idestado=d.idestado) inner join		\n\
	personas e using(idpersona) inner join						\n\
        fechaentregaimpreso as f on a.idimpreso=f.idimpreso inner join			\n\
        circuitoimpresoinformacion as g on a.idimpreso=g.idimpreso left outer join	\n\
	telefonos as h on a.idpersona=h.idpersona					\n\
where c.idestado != 2");
SiscomConsultasSqlOperaciones(lchrArrBuffer,
                   pSiscomOpePtrDato,
                   "ImpresosRegistrados%",
                   lchrArrSql);
return 0;
}
int SqlCircuitosImpresosPorFechaEstado(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[2048],
	lchrArrSql[2048];
sprintf(lchrArrSql,
	"										\n\
select  a.*,										\n\
	e.nombre,									\n\
	e.apaterno,									\n\
	e.nombre || 									\n\
	' '	 ||									\n\
	e.apaterno as NombreCompleto,							\n\
	g.archivo,									\n\
	g.memoria,									\n\
	h.telefono,									\n\
	f.fecha::date,									\n\
	f.fecha::time as hora								\n\
from circuitoimpreso as a inner join 							\n\
	ultimoestadocircuitoimpreso as b using(idimpreso) inner join 			\n\
	estadoscircuitoimpreso as c using(idestado) inner join				\n\
	estadocircuitoimpreso as d on (b.idimpreso=d.idimpreso and 			\n\
				       b.idestado=d.idestado) inner join		\n\
	personas e using(idpersona) inner join						\n\
        fechaentregaimpreso as f on a.idimpreso=f.idimpreso inner join			\n\
        circuitoimpresoinformacion as g on a.idimpreso=g.idimpreso left outer join	\n\
	telefonos as h on a.idpersona=h.idpersona					\n\
where a.idimpreso in(select idimpreso							\n\
                     from estadocircuitoimpreso						\n\
                     where idestado=%s and						\n\
                           fecha::date>='%s' and					\n\
                           fecha::date<='%s') and 					\n\
      b.idestado=%s",
SiscomCampoAsociadoEntradaOperacion("Envio","IdEstado",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","IdEstado",pSiscomOpePtrDato));

SiscomConsultasSqlOperaciones(lchrArrBuffer,
                   pSiscomOpePtrDato,
                   "ImpresosRegistrados%",
                   lchrArrSql);
return 0;
}
int SqlCircuitoImpresoActualizaEdo(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];
SiscomAgregaSentenciasSqlDelAsociado("SqlCircuitoImpreso",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToEstadoCircuitoImpreso);
SiscomAgregaSentenciasSqlDelAsociado("SqlCircuitoImpreso",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     UpdateToUltimoEstado);

SiscomEnviaRegistrosAlServidorBD("SqlCircuitoImpreso",lchrArrBuffer,pSiscomOpePtrDato);
}

int SqlRegistraCircuitoImpreso(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrSql[1024];

SiscomAgregaSentenciasSqlDelAsociado("SqlCircuitoImpreso",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToCircuitoImpreso);
SiscomAgregaSentenciasSqlDelAsociado("SqlCircuitoImpreso",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToCircuitoImpresoInformacion);
SiscomAgregaSentenciasSqlDelAsociado("SqlCircuitoImpreso",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToFechaEntregaImpreso);
SiscomAgregaSentenciasSqlDelAsociado("SqlCircuitoImpreso",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToEstadoCircuitoImpreso);
SiscomAgregaSentenciasSqlDelAsociado("SqlCircuitoImpreso",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSiscomOpePtrDato,
				     InsertToUltimoEstadoCircuitoImpreso);

SiscomEnviaRegistrosAlServidorBD("SqlCircuitoImpreso",lchrArrBuffer,pSiscomOpePtrDato);
				
return 0;
}

void InsertToCircuitoImpreso(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into CircuitoImpreso values(%s,%s,%s,'%s');",
	SiscomObtenCampoRegistroProLChar("IdImpreso",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdVenta",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Cliente",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("CveProducto",pSiscomRegProLPtrDato));
}
void InsertToCircuitoImpresoInformacion(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into CircuitoImpresoInformacion values(%s,'%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdImpreso",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Archivo",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Memoria",pSiscomRegProLPtrDato));
}

void InsertToFechaEntregaImpreso(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"insert into FechaEntregaImpreso values(%s,'%s');",
	SiscomObtenCampoRegistroProLChar("IdImpreso",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("FechaHoraEntrega",pSiscomRegProLPtrDato));

}
void InsertToEstadoCircuitoImpreso(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{

sprintf(pchrPtrSql,
	"insert into EstadoCircuitoImpreso values(%s,%s,'%s');",
	SiscomObtenCampoRegistroProLChar("IdImpreso",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdEstado",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("FechaHora",pSiscomRegProLPtrDato));
}
void InsertToUltimoEstadoCircuitoImpreso(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into UltimoEstadoCircuitoImpreso values(%s,%s);",
	SiscomObtenCampoRegistroProLChar("IdImpreso",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdEstado",pSiscomRegProLPtrDato));
}
void UpdateToUltimoEstado(SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrDato,
		      char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update UltimoEstadoCircuitoImpreso set IdEstado=%s where idimpreso=%s;",
	SiscomObtenCampoRegistroProLChar("IdEstado",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdImpreso",pSiscomRegProLPtrDato));
}

