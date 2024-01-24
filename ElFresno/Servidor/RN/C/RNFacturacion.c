#include <RNFacturacion.h>
StcCreaConsultasSISCOM gSCCnsSiscomFacturacion[]={
			{
			  "ConsultaOrdenesPorFecha",
			  CreaConsultaOrdenesPorFecha
			},
			{
			  "OrdenesParaFacturar",
			  CreaConsultaOrdenesAFacturar
			}
		    };

int gintNConsultasFacturacion=2;

void CreaConsultaOrdenesPorFecha(char **pchrPtrParametros,
			       StcLtaRegComSISCOM *pSLRCSisDat,
			       StcLtaRegComSISCOM **pSLRCSisRegreso,
			       int *pintPtrNRegreso,
			       char *pchrPtrConsulta)
{
	sprintf(pchrPtrConsulta,
		"SELECT distinct a.idVenta,				\
				 a.FechaHora,				\
				 c.Nombre,				\
				 c.APaterno,				\
				 c.AMaterno,				\
				 c.IdPersona,				\
				 b.importe 				\
		  from	ventas as a 					\
		  	inner join importeorden as b  using(idVenta) 	\
			inner join personas as c on vendedor=idpersona  \
		  where cliente=%s and 					\
		        cast(a.FechaHora as date)>='%s' and		\
			cast(a.FechaHora as date)<='%s';",
		  pchrPtrParametros[0],
		  pchrPtrParametros[1],
		  pchrPtrParametros[2]);
}
void CreaConsultaOrdenesAFacturar(char **pchrPtrArgumentos,
				  StcLtaRegComSISCOM *pSLRCSisDat,
				  StcLtaRegComSISCOM **pSLRCSisRegreso,
				  int *pintNRegreso,
				  char *pchrPtrConsulta)
{
int lintContador;
char lchrArrPaso[1024];
char lchrArrCondicion[1024];
char lchrArrTotal[1024];
char lchrArrImporteIVA[1025];
char lchrArrImporteSinIVA[1024];
	SISCOMImprimeContenidoRegistro(pchrPtrArgumentos,"CreaConsultaOrdenesAFacturar");
	sprintf(pchrPtrConsulta,
		"select	a.CveProducto,					\
			b.DscProducto,					\
		        sum(a.Cantidad) as Cantidad,  			\
			a.Precio,					\
			sum(a.Importe)*%s  as Importe  			\
		 from	ventas as a 					\
		 	inner join productos as b using(CveProducto) 	\
		where  idVenta in(",
		pchrPtrArgumentos[0]);

		
		lchrArrCondicion[0]=0;
	for(lintContador=1;
	    pchrPtrArgumentos[lintContador];
	    lintContador++)
	{
	    if(pchrPtrArgumentos[lintContador+1])
	    sprintf(lchrArrPaso,"%s,",pchrPtrArgumentos[lintContador]);
	    else
	    sprintf(lchrArrPaso,"%s)",pchrPtrArgumentos[lintContador]);
	   strcat(lchrArrCondicion,lchrArrPaso); 
	}
	strcat(pchrPtrConsulta,lchrArrCondicion);	
	strcat(pchrPtrConsulta," group by a.CveProducto, \
					  b.DscProducto, \
					  a.Precio");
	sprintf(lchrArrTotal,
		" union							\
		 select 'Total',					\
			'',						\
			0,						\
			0,						\
			sum(a.Importe)*%s as Importe			\
		 from	ventas as a 					\
		 	inner join productos as b using(CveProducto) 	\
		where  idVenta in(%s",
		pchrPtrArgumentos[0],
		lchrArrCondicion);
	sprintf(lchrArrImporteIVA,
		" union							\
		 select 'IVA',					\
			'',						\
			0,						\
			0,						\
			sum(a.Importe)*0.15*%s as Importe			\
		 from	ventas as a 					\
		 	inner join productos as b using(CveProducto) 	\
		where  idVenta in(%s",
		pchrPtrArgumentos[0],
		lchrArrCondicion);
	sprintf(lchrArrImporteSinIVA,
		" union							\
		 select 'TotalSinIVA',					\
			'',						\
			0,						\
			0,						\
			sum(a.Importe)*0.85*%s as Importe			\
		 from	ventas as a 					\
		 	inner join productos as b using(CveProducto) 	\
		where  idVenta in(%s",
		pchrPtrArgumentos[0],
		lchrArrCondicion);
	printf("{%d}.-%s\n{%d}.-%s\n{%d}.-%s\n",
		strlen(lchrArrTotal),
		lchrArrTotal,
		strlen(lchrArrImporteIVA),
		lchrArrImporteIVA,
		strlen(lchrArrImporteIVA),
		lchrArrImporteSinIVA);
	strcat(pchrPtrConsulta,lchrArrTotal);
	strcat(pchrPtrConsulta,lchrArrImporteIVA);
	strcat(pchrPtrConsulta,lchrArrImporteSinIVA);

	printf("%d.-%s\n",
		strlen(pchrPtrConsulta),
		pchrPtrConsulta);

}
StcLtaRegComSISCOM *OperacionesFacturacion(int pintPtoCom,
					     const char *pchrPtrDirIpSvr,
					     StcLtaRegComSISCOM *pSLRCSisDat,
					     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisRegreso=0;

StcOperacionesAlSistema2SISCOM lSOASistemaSiscom[]=
		{
		 {
		   EsRegistroFacturacion,
		   RegistraFacturacion,
		   RespuestaGeneralFacturacion
		  },
		  {
		    EsConsultaFacturacion,
		    ConsultaFacturacion,
		    RespuestaGeneralFacturacion
		  }
		};

SISCOMImprimeContenidoCom2(stdout,
			   "OperacionesFacturacion",
			   '|',
			   '\n',
			   pSLRCSisDat);
	SISCOMSeleccionaYEjecutaOperacionAlSistema2(pintPtoCom,
						      pchrPtrDirIpSvr,
						      lSOASistemaSiscom,
						      2,
						      pSLRCSisDat,
						      &lSLRCSisRegreso,
						      pintPtrNRegistros);
	return lSLRCSisRegreso;
}
void AnexaRegistroFacturacion(StcLtaRegComSISCOM *pSLRCSisDat,
				int pintContador,
				const char *pchrPtrFirma,
				int *pintPtrNRegistros,
			        StcLtaRegComSISCOM **pSLRCSisPrim,
				StcLtaRegComSISCOM **pSLRCSisActual)
{
char lchrArrBuffer[512];
}
int EsRegistroFacturacion(int pintPtoComAD,
			    const char *pchrPtrDirIpSvr,
			    char **pchrPtrArgumentos,
			    char *pchrPtrConsulta,
			    StcLtaRegComSISCOM *pSLRCSisDat,
			    StcLtaRegComSISCOM **pSLRCSisRegreso,
			    int *pintPtrNRegreso)
{
StcLtaRegComSISCOM *lSLRCSisActual=0;
const char *lchrPtrFirma;
int lintContador;
	if(!strcmp(pchrPtrArgumentos[0],
		   "RegistraFacturacion"))
	{
	   return 1;
	}
	else
	return 0;
}					
void RegistraFacturacion(int pintPtoCom,
			   const char *pchrPtrDirIpSvr,
			   const char *pchrPtrConsulta,
			   StcLtaRegComSISCOM *pSLRCSisDat,
			   int pintNRegistros,
			   StcLtaRegComSISCOM **pSLRCSisRegreso,
			   int *pintPtrNRegistros)
{
	SISCOMEnviaInformacionAlSvrAD(pintPtoCom,	
				      pchrPtrDirIpSvr,
				      "hgarduno",
				      "hgarduno",
				      "libADAltaGenericaClinicas.so",
                                      "ADComandosAlta",
                                      pintNRegistros,
                                      pSLRCSisDat,
                                      pSLRCSisRegreso,
                                      pintPtrNRegistros);
}

void RespuestaGeneralFacturacion(int pintPtoCom,
				   const char *pchrPtrDirIpSvr,
				   int pintNRegistros,
				   StcLtaRegComSISCOM *pSLRCSisDat,
				   StcLtaRegComSISCOM **pSLRCSisRegreso,
				   int *pintPtrNRegistros)
{
	*pintPtrNRegistros=pintNRegistros;
	*pSLRCSisRegreso=pSLRCSisDat;

}
int EsConsultaFacturacion(int pintPtoCom,
			    const char *pchrPtrDirIpSvr,
			    char **pchrPtrArgumentos,
			    char *pchrPtrConsulta,
			    StcLtaRegComSISCOM *pSLRCSisDat,
			    StcLtaRegComSISCOM **pSLRCSisRegreso,
			    int *pintPtrNRegistros)
{
int lintContador;
	if(!strcmp(pchrPtrArgumentos[0],
		   "ConsultaFacturacion"))
	{
	  for(lintContador=0;
	      lintContador<gintNConsultasFacturacion;
	      lintContador++)
	   if(!strcmp(gSCCnsSiscomFacturacion[lintContador].chrPtrNmbConsulta,
		      pchrPtrArgumentos[1]))
	     gSCCnsSiscomFacturacion[lintContador].EjecutaCreaConsulta(
						pchrPtrArgumentos+2,
						pSLRCSisDat,
						pSLRCSisRegreso,
						pintPtrNRegistros,
						pchrPtrConsulta);

	   return 1;
	}
	else
	return 0;

}
void ConsultaFacturacion(int pintPtoCom,
			   const char *pchrPtrDirIpSvr,
			   const char *pchrPtrConsulta,
			   StcLtaRegComSISCOM *pSLRCSisDat,
			   int pintNRegistros,
			   StcLtaRegComSISCOM **pSLRCSisRegreso,
			   int *pintPtrNRegistros)
{
char lchrArrBuffer[8192];
                                   
                                  
        SISCOMEnviaYRecibeCadenaFormateandoAD(
                        pintPtoCom,
                        pchrPtrDirIpSvr,
                        "hgarduno",                
                        "hgarduno",                
                        "libADConsultaGenericaElFresno.so",
                        "ADConsultas",             
                        pintPtrNRegistros,         
                        pSLRCSisRegreso,           
                        lchrArrBuffer,
                        "%s",
                        pchrPtrConsulta);
}



