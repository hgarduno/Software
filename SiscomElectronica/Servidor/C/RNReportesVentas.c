#include <RNReportesVentas.h>
#include <RNPersonas.h>
#include <RNCotizaDispositivos.h>
#include <ServidorGeneral.h>

#include <ComunElectronica.h>
#include <ComunElectronica2.h>
#include <string.h>

extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;
StcConsultas gStcCnsReportesVentas[]={ {EsConsultaReportesVentas,FormaConsultaReportesVentas}
			       };
int gintCnsReportesVentas=1;

int EsConsultaReportesVentas(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ReportesVentas");
}
void FormaConsultaReportesVentas(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[4096];
sprintf(lchrArrConsulta,"\
select	sum(cantidad) as cantidad,						\n\
	sum(importe) as importe,						\n\
	cast ('2007-01-01' as date) as Fecha,					\n\
	cveproducto,								\n\
	dscproducto,								\n\
	'DetalleVenta' as Reporte						\n\
from ventas inner join productos using (cveproducto)				\n\
where cast(fechahora as date)>='%s' and						\n\
      cast(fechahora as date)<='%s' and 					\n\
      idexpendio=%s		    and						\n\
      edoventa=0								\n\
group by cveproducto,								\n\
	 dscproducto								\n\
union										\n\
select 0 as cantidad,								\n\
      sum(importe) as importe,							\n\
	cast ('2007-01-01' as date) as Fecha,					\n\
	'',									\n\
	'Total Ventas',								\n\
	'DetalleVenta' as Reporte						\n\
from ventas									\n\
where cast(fechahora as date)>='%s' and						\n\
      cast(fechahora as date)<='%s' and 					\n\
      idexpendio=%s		    and						\n\
      edoventa=0								\n\
union										\n\
select sum(importe),								\n\
	0,									\n\
       cast(fechahora as date) as Fecha,					\n\
       '',									\n\
       '',									\n\
       'ImportePorDia' as Reporte						\n\
from ventas									\n\
where cast(fechahora as date)>='%s' and						\n\
      cast(fechahora as date)<='%s' and 					\n\
      idexpendio=%s		    and						\n\
      edoventa=0								\n\
group by 									\n\
	cast(fechahora as date)							\n\
union										\n\
select count(*),								\n\
	0,									\n\
       fechahora as Fecha,							\n\
       '',									\n\
       '',									\n\
       'OrdenesPorDia' as Reporte						\n\
from sqlordenes									\n\
where cast(fechahora as date)>='%s' and						\n\
      cast(fechahora as date)<='%s' and 					\n\
      idexpendio=%s		    and						\n\
      edoventa=0								\n\
group by cast(fechahora as date)						\n\
union										\n\
select count(*),								\n\
	0,									\n\
	fecha::date,								\n\
	nombre,									\n\
	'',									\n\
	'OrdenesPorEscuela' as Reporte						\n\
from escuelaorden as a inner join						\n\
     escuelas as b on a.idescuela=b.idescuela					\n\
where fecha::date>='%s' and 							\n\
      fecha::date<='%s' and 							\n\
      idexpendio=%s								\n\
group by fecha::date,nombre							\n\
union										\n\
select count(*),								\n\
	0,									\n\
	cast ('2007-01-01' as date) as Fecha,					\n\
	nombre,									\n\
	'',									\n\
	'TotalOrdenesPorEscuela' as Reporte					\n\
from escuelaorden as a inner join						\n\
     escuelas as b on a.idescuela=b.idescuela					\n\
where fecha::date>='%s' and 							\n\
      fecha::date<='%s' and 							\n\
      idexpendio=%s								\n\
group by nombre									\n\
order by 6,									\n\
	 3,									\n\
	 1									\n\
	 desc									\n\
",
pchrPtrEntrada[1],
pchrPtrEntrada[2],
pchrPtrEntrada[3],

pchrPtrEntrada[1],
pchrPtrEntrada[2],
pchrPtrEntrada[3],

pchrPtrEntrada[1],
pchrPtrEntrada[2],
pchrPtrEntrada[3],

pchrPtrEntrada[1],
pchrPtrEntrada[2],
pchrPtrEntrada[3],

pchrPtrEntrada[1],
pchrPtrEntrada[2],
pchrPtrEntrada[3],

pchrPtrEntrada[1],
pchrPtrEntrada[2],
pchrPtrEntrada[3]
);

 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);

	SiscomLog(
			  "%s",
			  lchrArrConsulta);

}
void AnalizaConsultaReportesVentas(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsReportesVentas;
	    lintContador++)
	   if(gStcCnsReportesVentas[lintContador].Consulta(pchrPtrEntrada))
	   {
	      gStcCnsReportesVentas[lintContador].FormaConsulta(pchrPtrEntrada,
	     						  pSOpServidor);
	      break;
	   }

	

}
void ConsultaReportesVentas(int pintSocket,
		       int pintNRegistros)
{
SiscomOperacionesServidor lSOpServidor;
char **lchrPtrEntrada=0;

	lSOpServidor.EjecutaProcesoAntes=0;
	SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				      gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				      &lSOpServidor);
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lSOpServidor.LCSiscomPro2Dat);
	SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
					  pintNRegistros,
					  "Parametro",
					  &lchrPtrEntrada);
	ElectronicaComunicacionExpendio2(lchrPtrEntrada[3],
					  &lSOpServidor.intPtoCom, 
					  lSOpServidor.chrPtrDirIpSvr,
					  0);
	SiscomLog("Expendio (%s) > (%s,%d)", 
		  lchrPtrEntrada[3],
		  lSOpServidor.chrPtrDirIpSvr,
		  lSOpServidor.intPtoCom);
	AnalizaConsultaReportesVentas(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomImprimeContenidoProtocolo("",
					gPtrFleArchivoLog,
					lSOpServidor.LCSiscomPro2);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);
	close(pintSocket);
}
void FormaCadenaOperacionSqlReportesVentas(int lintContador,
			     LCamposSiscomPro2 *pLCSiscomPro2,
			     char *pchrPtrCadena)
{

	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Insertar"))
	{
	 sprintf(pchrPtrCadena,
	 	 "insert into ReportesVentas values(%ld,%s,'%s');",
		 SiscomObtenNumeroUnico()+lintContador,
		 SiscomObtenDato(pLCSiscomPro2,"IdMateria"),
		 SiscomObtenDato(pLCSiscomPro2,"Nombre"));
	}

		   


}
void RegistraReportesVentas(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int     lintSocketAD,
        lintNRegistros=0,
	lintContador;

SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
SiscomLog(
		  "RegistraReportesVentas");
SiscomContenidoProtocolo(lLCSiscomPro2);
  for(lintContador=0;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig,
	lintContador++)
  {
  	 FormaCadenaOperacionSqlReportesVentas(lintContador,lLCSiscomPro2,lchrArrActualiza); 
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
  }
  	SiscomContenidoProtocolo(lLCSiscomPro2Ins);
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomLog(
			  "Error Al Enviar:%s",
	                  lchrPtrEdoConexion);
}
