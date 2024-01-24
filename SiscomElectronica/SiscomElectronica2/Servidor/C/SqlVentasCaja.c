#include <SqlVentasCaja.h>
void SqlVentasPorCajaFecha(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[1024];

sprintf(lchrArrSql,
	"							\n\
select sum(total) as total,					\n\
       sum(Recibio-cambio) as validacion,			\n\
	fecha::date as fechahora,				\n\
	descripcion,						\n\
	0 as totalventas,					\n\
	(select count(*)					\n\
	 from cortecaja 					\n\
	 where idcaja=cajas.idcaja 	and 			\n\
	       cortecaja.fechahora::date>='%s' 	and		\n\
	       cortecaja.fechahora::date<='%s' ) as edoreporte,	\n\
	(select sum(importecorte)				\n\
	 from cortecaja 					\n\
	 where idcaja=cajas.idcaja 	and 			\n\
	       cortecaja.fechahora::date>='%s' 	and		\n\
	       cortecaja.fechahora::date<='%s' ) as totalcortes,\n\
	(select sum(total)					\n\
	 from ventascaja					\n\
	 where fecha::date>='%s' and				\n\
	       fecha::date<='%s') as totalvendido		\n\
from ventascaja as a inner join					\n\
     cajas using(idcaja)					\n\
where a.fecha::date>='%s'  and					\n\
      a.fecha::date<='%s' 					\n\
group by a.fecha::date,						\n\
	 descripcion,						\n\
	 cajas.idcaja						\n\
order by descripcion,						\n\
 	  fecha::date",
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[3],
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[3],
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[3],
pSAgsSiscom->chrPtrArgConsulta[2],
pSAgsSiscom->chrPtrArgConsulta[3]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSql);
}


void SqlObtenCajasRegistradas(SArgsSiscom *pSAgsSiscom,
			      LCamposSiscomPro2 **pLCSiscomPro2Reg,
			      int *pintPtrNRegistros)
{
SiscomConsultaBaseSinEnvio("select *	\n\
			    from cajas",
			    pSAgsSiscom,
			    pintPtrNRegistros,
			    pLCSiscomPro2Reg);
}
int SqlObtenEstadoActualCaja(const char *pchrPtrFechaHoy,
			     SArgsSiscom *pSAgsSiscom,
			     LCamposSiscomPro2 *pLCSiscomPro2Dat,
			     LCamposSiscomPro2 **pLCSiscomPro2EdoActual)
{
char lchrArrSql[256];
int lintNRegistros;
sprintf(lchrArrSql,
	"				\n\
select  idcaja,				\n\
	descripcion,			\n\
	importe				\n\
from cajas inner join 			\n\
     estadocaja using(idcaja)		\n\
where idcaja=%s and 			\n\
      fecha='%s'",
SiscomObtenDato(pLCSiscomPro2Dat,"idcaja"),
pchrPtrFechaHoy);
SiscomConsultaBaseSinEnvio(lchrArrSql,
			   pSAgsSiscom,
			   &lintNRegistros,
			   pLCSiscomPro2EdoActual);
	
return lintNRegistros;
}
void AgregaRegistroVacioCaja(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			     SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2DatPrim=0,
		 *lLCSiscomPro2DatAct=0;
int lintNRegistros=0;
SiscomAnexaRegistroPro2(&lLCSiscomPro2DatPrim,
			&lLCSiscomPro2DatAct,
			&lintNRegistros,
			"idcaja,descripcion,importe",
			SiscomObtenDato(pLCSiscomPro2Dat,"idcaja"),
			SiscomObtenDato(pLCSiscomPro2Dat,"descripcion"),
			"0");
SiscomSumaListaCampos(&pSAgsSiscom->LCSiscomPro2Regreso,
		 lLCSiscomPro2DatPrim);
}
void SqlCajasRegistradas(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=0;
LCamposSiscomPro2 *lLCSiscomPro2DatEdoActual=0;
int lintNRegistros;
char lchrArrFechaHoy[25];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFechaHoy);
 SqlObtenCajasRegistradas(pSAgsSiscom,
 			  &lLCSiscomPro2Dat,
			  &lintNRegistros);
SiscomContenidoProtocolo(lLCSiscomPro2Dat);
pSAgsSiscom->intNumRegRegreso=lintNRegistros;
pSAgsSiscom->LCSiscomPro2Regreso=0;
for(;
    lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
{
SiscomLog("Buscando Estado Actual");
  if(SqlObtenEstadoActualCaja(lchrArrFechaHoy,
  			      pSAgsSiscom,
  			      lLCSiscomPro2Dat,
  			      &lLCSiscomPro2DatEdoActual))
	SiscomSumaListaCampos(&pSAgsSiscom->LCSiscomPro2Regreso,
			      lLCSiscomPro2DatEdoActual);
  else
      AgregaRegistroVacioCaja(lLCSiscomPro2Dat,pSAgsSiscom);
}
}
int SqlObtenVentasPorCaja(const char *pchrPtrFechaHoy,
			  LCamposSiscomPro2 *pLCSiscomPro2Cajas,
			  SArgsSiscom *pSAgsSiscom,
			  LCamposSiscomPro2 **pLCSiscomPro2Ventas)
{
char lchrArrSql[2048];
int lintNRegistros;
sprintf(lchrArrSql,
	"								\n\
select sum(total) as totalventas,					\n\
       sum(recibio-cambio) as validacion,				\n\
       importe as importeinicial,					\n\
       '%s' as descripcion,						\n\
       0 as totalencaja,						\n\
       idcaja,								\n\
       (select sum(importecorte)					\n\
        from cortecaja							\n\
	where idcaja=%s and 						\n\
	      fechahora::date='%s') as totalcorte,			\n\
       (select count(*)							\n\
        from cortecaja							\n\
	where idcaja=%s and 						\n\
	fechahora::date='%s') as edoreporte				\n\
from ventascaja as a left  outer join 					\n\
     estadocaja as b using(idcaja) 					\n\
where a.fecha::date='%s' and 						\n\
      a.idcaja=%s	 and						\n\
      b.fecha='%s' 							\n\
group by idcaja,							\n\
	b.importe",
SiscomObtenDato(pLCSiscomPro2Cajas,"descripcion"),
SiscomObtenDato(pLCSiscomPro2Cajas,"idcaja"),
pchrPtrFechaHoy,
SiscomObtenDato(pLCSiscomPro2Cajas,"idcaja"),
pchrPtrFechaHoy,
pchrPtrFechaHoy,
SiscomObtenDato(pLCSiscomPro2Cajas,"idcaja"),
pchrPtrFechaHoy);
SiscomConsultaBaseSinEnvio(lchrArrSql,
			   pSAgsSiscom,
			   &lintNRegistros,
			   pLCSiscomPro2Ventas);
return lintNRegistros;
} 
void AgregaRegistroVacioVentaCaja(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			     SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2DatPrim=0,
		 *lLCSiscomPro2DatAct=0;
int lintNRegistros=0;
SiscomAnexaRegistroPro2(&lLCSiscomPro2DatPrim,
			&lLCSiscomPro2DatAct,
			&lintNRegistros,
			"idcaja,		\
			 descripcion,		\
			 totalventas,		\
			 validacion,		\
			 importeinicial,	\
			 totalencaja,		\
			 totalcorte,		\
			 edoreporte",
			SiscomObtenDato(pLCSiscomPro2Dat,"idcaja"),
			SiscomObtenDato(pLCSiscomPro2Dat,"descripcion"),
			"0",
			"0",
			"0",
			"0",
			"0",
			"0");
SiscomSumaListaCampos(&pSAgsSiscom->LCSiscomPro2Regreso,
		 lLCSiscomPro2DatPrim);
}
void SqlVentasPorCaja(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Cajas=0;
LCamposSiscomPro2 *lLCSiscomPro2Ventas=0;

int lintNCajas;
char lchrArrFechaHoy[25];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFechaHoy);
SqlObtenCajasRegistradas(pSAgsSiscom,
			 &lLCSiscomPro2Cajas,
			 &lintNCajas);
pSAgsSiscom->intNumRegRegreso=lintNCajas;
pSAgsSiscom->LCSiscomPro2Regreso=0;
SiscomContenidoProtocolo(lLCSiscomPro2Cajas);
for(;
	lLCSiscomPro2Cajas;
	lLCSiscomPro2Cajas=lLCSiscomPro2Cajas->SCP2PtrSig)
{
    if(SqlObtenVentasPorCaja(lchrArrFechaHoy,
    			     lLCSiscomPro2Cajas,
    			     pSAgsSiscom,
			     &lLCSiscomPro2Ventas))
	 SiscomSumaListaCampos(&pSAgsSiscom->LCSiscomPro2Regreso,
	 		       lLCSiscomPro2Ventas);
    else
    AgregaRegistroVacioVentaCaja(lLCSiscomPro2Cajas,pSAgsSiscom);

}
}


void SqlInsertaImporteCaja(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
                pSAgsSiscom,
		"SqlCajas",
		SqlGeneraInsertaImporteCaja);
}
void SqlGeneraInsertaImporteCaja(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[256];
char lchrArrFechaHoy[25];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFechaHoy);
sprintf(lchrArrSql,
	"insert into estadocaja values(%s,%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdCaja"),
	SiscomObtenDato(pLCSiscomPro2,"Importe"),
	lchrArrFechaHoy);
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
void SqlActualizaImporteCaja(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(
                pSAgsSiscom,
		"SqlCajas",
		SqlGeneraActualizaImporteCaja);

}
void SqlGeneraActualizaImporteCaja(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSql[256];
char lchrArrFechaHoy[25];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFechaHoy);
sprintf(lchrArrSql,
	"update estadocaja set importe=%s 	\n\
	 where idcaja=%s and			\n\
	       fecha='%s';",
	SiscomObtenDato(pLCSiscomPro2,"Importe"),
	SiscomObtenDato(pLCSiscomPro2,"IdCaja"),
	lchrArrFechaHoy);
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
