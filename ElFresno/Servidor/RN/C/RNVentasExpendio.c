#include <RNVentasExpendio.h>
#include <RNEmpresas.h>

StcCreaConsultas gSCConsultasVentasExpendios[]={ {"VentaExpendio",
				   GeneraConsultaVentaExpendio
				  }
				};

int gintCreaConsultasVentasExpendios=1;


void GeneraConsultaVentaExpendio(char **pchrPtrArgumentos,
			     StcLtaRegComSISCOM *pSLRCSisDat,
			     StcLtaRegComSISCOM **pSLRCSisRegreso,
			     int *pintPtrNRegistros,
			     char *pchrPtrConsulta)
{
	SISCOMImprimeContenidoRegistro(pchrPtrArgumentos,
				       "GeneraConsultaVentaExpendio");
	sprintf(pchrPtrConsulta,
		"select	sum(Cantidad),								\
			sum(Importe),								\
			DscProducto, 								\
			Precio,									\
			Existencia								\
		 from	ventas									\
			inner join productos as a using(CveProducto) 				\
			inner join existencias as b on (a.CveProducto=b.CveProducto and 	\
						       Ventas.idExpendio=b.IdExpendio) 		\
		 where cast(FechaHora as date)>='%s' and					\
		       cast(FechaHora as date)<='%s' and					\
		       Ventas.idExpendio=%s							\
		 group by DscProducto,								\
		 	  Precio,								\
			  Existencia								\
		 union										\
		 select	0,									\
			sum(Importe),								\
		        'Importe Total',							\
			0,									\
			0									\
		 from	ventas									\
		 where cast(FechaHora as date)>='%s' and					\
		       cast(FechaHora as date)<='%s' and					\
		       idExpendio=%s								\
		 order by 3",
		 pchrPtrArgumentos[3],
		 pchrPtrArgumentos[4],
		 pchrPtrArgumentos[2],
		 pchrPtrArgumentos[3],
		 pchrPtrArgumentos[4],
		 pchrPtrArgumentos[2]);
		printf("%s\n",pchrPtrConsulta);
}
StcLtaRegComSISCOM *OperacionesVentasExpendio(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     StcLtaRegComSISCOM *pSLRCSisDat,
				     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisRegreso=0;
StcOperacionesAlSistemaSISCOM lSOASistemaSiscom[]=
		{{
		  EsConsultaVentasExpendio,
		  ConsultaVentasExpendio,
		  RespuestaConsultaVentasExpendio 
		  }		
		};
	SISCOMImprimeContenidoCom(stdout,
				  '|',
				  '\n',
				  pSLRCSisDat);
	SISCOMSeleccionaYEjecutaOperacionAlSistema(pintPtoComAD,
						   pchrPtrDirIpSvr,
						   lSOASistemaSiscom,
						   1,
						   pSLRCSisDat,
						   &lSLRCSisRegreso,
						   pintPtrNRegistros);
	
	return lSLRCSisRegreso;

}
int EsConsultaVentasExpendio(char **pchrPtrArgumentos,
			char *pchrPtrConsulta,
			StcLtaRegComSISCOM *pSLRCSisDat,
			StcLtaRegComSISCOM **pSLRCSisRegreso,
			int *pintPtrNRegRegreso)
{
int lintContador;
	if(!strcmp(pchrPtrArgumentos[0],
	           "VentasExpendio"))
	{
	  printf("Si es la consulta VentasExpendio \n");
	   for(lintContador=0;
	      lintContador<gintCreaConsultasVentasExpendios;
	      lintContador++)
	   if(!strcmp(gSCConsultasVentasExpendios[lintContador].chrPtrNmbConsulta,
		      pchrPtrArgumentos[1]))
	      gSCConsultasVentasExpendios[lintContador].EjecutaCreaConsulta(
					pchrPtrArgumentos,
					pSLRCSisDat,
					pSLRCSisRegreso,
					pintPtrNRegRegreso,
					pchrPtrConsulta);

	    return 1;
	}
	else
	return 0;
}
void ConsultaVentasExpendio(int pintPtoComAD,
			const char *pchrPtrDirIpSvr,
			const char *pchrPtrConsulta,
			StcLtaRegComSISCOM *pSLRCSisDat,
			int pintNRegistros,
			StcLtaRegComSISCOM **pSLRCSisRegreso,
			int *pintPtrNRegreso)
{

	*pSLRCSisRegreso=ConsultaGenericaALaBaseElFresnoConNumeroRegistros(
				pintPtoComAD,
				pchrPtrDirIpSvr,
				pchrPtrConsulta,
				pintPtrNRegreso);
}
void RespuestaConsultaVentasExpendio(int pintPtoComAD,
				const char *pchrPtrDirIpSvr,
				int pintNRegistros,
				StcLtaRegComSISCOM *pSLRCSisDat,
				StcLtaRegComSISCOM **pSLRCSisRegreso,
				int *pintPtrNRegistrosRegreso)
{
	printf("RespuestaConsultaVentasExpendio:%d Registros Respuesta\n",
		pintNRegistros);
	SISCOMImprimeContenidoCom2(stdout,
				   "RespuestaConsultaVentasExpendio",
				   '|',
				   '\n',
				   pSLRCSisDat);	
	*pintPtrNRegistrosRegreso=pintNRegistros;
	*pSLRCSisRegreso=pSLRCSisDat;
}
void RespuestaGeneralVentasExpendio(int pintPtoComAD,
				const char *pchrPtrDirIpSvr,
				int pintNRegistros,
				StcLtaRegComSISCOM *pSLRCSisDat,
				StcLtaRegComSISCOM **pSLRCSisRegreso,
				int *pintPtrNRegistrosRegreso)
{

}
