#include <SqlCorteCajaSucursal.h>
#include <CorteCaja.h>

#include <stdlib.h>
#include <string.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>

int SqlRegistraCorteCajaSucursal(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256],lchrArrSql[512];
SiscomAgregaSentenciasSqlDelAsociado("SqlCorteCaja",
				     "Envio",
				     lchrArrBuffer,
				     lchrArrSql,
				     pSisOpePtrDato,
				     InsertToCorteCajaSucursal);
return 0;
}

int SqlRegistraCambioCaja(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256],
        lchrArrSql[256];
SiscomAgregaSentenciaSqlArgumento("SqlCorteCaja",
				  "CajaCambio",
				  lchrArrBuffer,
				  lchrArrSql,
				  pSisOpePtrDato,
				  InsertIntoCambioCaja);

SiscomAgregaSentenciasSqlRegistros("SqlCorteCaja",
				   lchrArrBuffer,
				   lchrArrSql,
				   EfectivoCambioCaja(pSisOpePtrDato),
				   pSisOpePtrDato,
				   InsertIntoDenominacionesCambioCaja);
return 0;
}

int SqlActualizaCambioCaja(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256],
        lchrArrSql[256];
SiscomAgregaSentenciaSqlArgumento("SqlCorteCaja",
				  "CajaCambio",
				  lchrArrBuffer,
				  lchrArrSql,
				  pSisOpePtrDato,
				  UpdateCambioCaja);

SiscomAgregaSentenciasSqlRegistros("SqlCorteCaja",
				   lchrArrBuffer,
				   lchrArrSql,
				   EfectivoCambioCaja(pSisOpePtrDato),
				   pSisOpePtrDato,
				   UpdateDenominacionesCambioCaja);
return 0;
}

int SqlEnviaRegistroCambioCaja(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256];
SiscomEnviaRegistrosAlServidorBD("SqlCorteCaja",
                                  lchrArrBuffer,
                                  pSisOpePtrDato);

return 0;
}

int SqlCajaConCambio(SiscomOperaciones *pSisOpePtrDato,
		     char *pchrPtrIdCajaCambio)
{
char lchrArrSql[256],
	lchrArrBuffer[256];
SiscomOperaciones lSisOpeDatos;
SiscomRegistroProL *lSisRegProLPtrCajaCambio;
memset(&lSisOpeDatos,0,sizeof(SiscomOperaciones));
lSisOpeDatos=*pSisOpePtrDato;
sprintf(lchrArrSql,
	"select *		\n\
	 from cambiocaja	\n\
	 where fecha='%s';",
	SiscomCampoArgumentoAct("DCorteCaja","Fecha",pSisOpePtrDato));
SiscomConsultasSqlOperaciones(lchrArrBuffer,
			      &lSisOpeDatos,
			      "CajaConCambio%",
			      lchrArrSql);
lSisRegProLPtrCajaCambio=SiscomObtenRegistrosCampoProL("CajaConCambio",lSisOpeDatos.SiscomRegProLPtrPrimRes);
if(lSisRegProLPtrCajaCambio)
{
  strcpy(pchrPtrIdCajaCambio,
  	 SiscomObtenCampoRegistroProLChar("idcambiocaja",lSisRegProLPtrCajaCambio));
	 return 1;
}
else
	return 0;
}
int SqlCambiosCaja(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"select * 			\n\
	 from cambiocaja");

SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSisOpePtrDato,
		   "CambiosCaja%",
		   lchrArrSql);
return 0;
}
void SqlPagaCon(SiscomOperaciones *pSisOpePtrDato,
		char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"					\n\
	select sum(pagacon) as importe 		\n\
	from importeorden as a inner join	\n\
	     pagacon as b using(idventa) 	\n\
	 where a.fecha::date>='%s' and 		\n\
	       a.fecha::date<='%s' and		\n\
 	pagacon is not null",
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSisOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSisOpePtrDato));
}

void SqlTransferenciasRegistradas(SiscomOperaciones *pSisOpePtrDato,
		char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"					\n\
select sum(importe) as importe 			\n\
from	importeorden inner join 		\n\
	pagotransferencia using(idventa) 	\n\
where fecha::date>='%s' and 			\n\
      fecha::date<='%s'",
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSisOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSisOpePtrDato));
}

void SqlPagoConTarjetaRegistrados(SiscomOperaciones *pSisOpePtrDato,
		char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"					\n\
select sum(importe) as importe 			\n\
from	importeorden inner join 		\n\
	pagotarjeta using(idventa) 		\n\
where fecha::date>='%s' and 			\n\
      fecha::date<='%s'",
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSisOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSisOpePtrDato));
}

void SqlTotalVentasCorteCaja(SiscomOperaciones *pSisOpePtrDato,
			     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"							\n\
select sum(importe) as importe					\n\
from	importeorden left outer join 				\n\
        pagotransferencia using(idventa) left outer join	\n\
	apartado using(idventa)					\n\
where fecha::date>='%s' 	and 				\n\
	fecha::date<='%s'",
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSisOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSisOpePtrDato));
}

int SqlDatosCierreCorteSucursal(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[512],
	lchrArrSqlPagaCon[256],
	lchrArrSqlTransferencias[256],
	lchrArrSqlVentasTotales[256],
	lchrArrSqlPagosTarjeta[256];
SqlPagaCon(pSisOpePtrDato,lchrArrSqlPagaCon);
SqlTransferenciasRegistradas(pSisOpePtrDato,lchrArrSqlTransferencias);
SqlTotalVentasCorteCaja(pSisOpePtrDato,lchrArrSqlVentasTotales);
SqlPagoConTarjetaRegistrados(pSisOpePtrDato,lchrArrSqlPagosTarjeta);
SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSisOpePtrDato,
		   "PagaConP%"
		   "TransferenciasP%"
		   "VentasTotalesP%"
		   "PagosTarjetaP%",
		   lchrArrSqlPagaCon,
		   lchrArrSqlTransferencias,
		   lchrArrSqlVentasTotales,
		   lchrArrSqlPagosTarjeta);
return 0;
}
int SqlCambioCaja(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[512],
	lchrArrSql[512];
sprintf(lchrArrSql,
	"select idcambiocaja,			\n\
		valor,				\n\
		cantidad,			\n\
		valor*cantidad as importe	\n\
	 from denominacionescambiocaja 		\n\
	 where idcambiocaja=%s",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdCambioCaja",pSisOpePtrDato));

SiscomConsultasSqlOperaciones(lchrArrBuffer,
		   pSisOpePtrDato,
		   "CambioCaja%",
		   lchrArrSql);
return 0;
}

void InsertIntoCambioCaja(SiscomOperaciones *pSisOpePtrDato,
			     SiscomRegistroProL *pSisRegProLPtrDato,
			     char *pchrPtrSql)
{
char lchrArrBuffer[256];

sprintf(pchrPtrSql,
	"insert into CambioCaja values(%s,'%s',%s);",
	SiscomCampoArgumentoAct("DCorteCaja","IdCambioCaja",pSisOpePtrDato),
	SiscomCampoArgumentoAct("DCorteCaja","Fecha",pSisOpePtrDato),
	SiscomObtenCampoRegistroProLChar("Total",pSisRegProLPtrDato));
}
void InsertIntoDenominacionesCambioCaja(SiscomOperaciones *pSisOpePtrDato,
			     SiscomRegistroProL *pSisRegProLPtrDato,
			     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into DenominacionesCambioCaja values(%s,%s,%s);",
	SiscomCampoArgumentoAct("DCorteCaja","IdCambioCaja",pSisOpePtrDato),
	SiscomObtenCampoRegistroProLChar("Valor",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Cantidad",pSisRegProLPtrDato));
}
void InsertToCorteCajaSucursal(SiscomOperaciones *pSisOpePtrDato,
			       SiscomRegistroProL *pSisRegProLPtrDato,
			       char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into CorteCajaSucursal(IdCorte,		\n\
				      Fecha,		\n\
				      Transferencias,	\n\
				      Tarjeta,		\n\
				      DineroEntro,	\n\
				      Billetes,		\n\
				      Gastos,		\n\
				      Cambio,		\n\
				      Diferencia,	\n\
				      FechaFin,		\n\
				      HoraCorte)	\n\
	values(%s,'%s',%s,%s,%s,%s,%s,%s,%s,'%s','%s');",
	SiscomObtenCampoRegistroProLChar("IdCorte",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("FechaInicio",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Transferencias",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Tarjeta",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("DineroEntroCaja",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Billetes",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("TotalGastos",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("CambioDiaAnterior",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("CalculandoCorte",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("FechaFin",pSisRegProLPtrDato),
	"21:00");
}
void UpdateCambioCaja(SiscomOperaciones *pSisOpePtrDato,
			     SiscomRegistroProL *pSisRegProLPtrDato,
			     char *pchrPtrSql)
{
char lchrArrBuffer[256];

sprintf(pchrPtrSql,
	"update CambioCaja set Importe=%s where idCambioCaja=%s",
	SiscomObtenCampoRegistroProLChar("Total",pSisRegProLPtrDato),
	SiscomCampoArgumentoAct("DCorteCaja","IdCambioCaja",pSisOpePtrDato));
}
void UpdateDenominacionesCambioCaja(SiscomOperaciones *pSisOpePtrDato,
			     SiscomRegistroProL *pSisRegProLPtrDato,
			     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update DenominacionesCambioCaja set Cantidad=%s \n\
	where idCambioCaja=%s and 			\n\
	      Valor=%s",
	SiscomObtenCampoRegistroProLChar("Cantidad",pSisRegProLPtrDato),
	SiscomCampoArgumentoAct("DCorteCaja","IdCambioCaja",pSisOpePtrDato),
	SiscomObtenCampoRegistroProLChar("Valor",pSisRegProLPtrDato));
}
