#include <RNPrecios.h>

const char *ObtenProducto(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Precios_Producto];
}

const char *ObtenIdPersonaPrecios(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Precios_IdPersona];
}

const char *ObtenIdEmpresa(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Precios_IdEmpresa];
}

const char *ObtenPrecio(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Precios_Precio];
}

const char *ObtenNmbTipoPrecio(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Precios_NmbTipoPrecio];
}
const char *ObtenEdoRegistroPrecio(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Precios_EdoRegistroPrecio];
}
const char *ObtenIdPrecio(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Precios_IdPrecioPrecio];
}
void AnexaRegistroPrecios(char **pchrPtrRegistro,
			  int pintContador,
			  int *pintPtrNRegistros,
			  StcLtaRegComSISCOM **pSLRCSisDatPrim,
			  StcLtaRegComSISCOM **pSLRCSisActual)
{
char lchrArrBuffer[256];
	if(ObtenEdoRegistroPrecio(pchrPtrRegistro)[0]=='0')
	SISCOMAnexaRegistroFormateandoParaEnvio(
                        pSLRCSisDatPrim,
                        pSLRCSisActual,
                        pintPtrNRegistros,
                        lchrArrBuffer,
                        "insert into Precios values('%s',%s,%s,%ld,%s,'%s');",
			ObtenProducto(pchrPtrRegistro),
			ObtenIdPersonaPrecios(pchrPtrRegistro),
			ObtenIdEmpresa(pchrPtrRegistro),
                        SISCOMObtenNumeroUnico()+pintContador,
                        ObtenPrecio(pchrPtrRegistro),
                        ObtenNmbTipoPrecio(pchrPtrRegistro));
	if(ObtenEdoRegistroPrecio(pchrPtrRegistro)[0]=='2')
	SISCOMAnexaRegistroFormateandoParaEnvio(
                        pSLRCSisDatPrim,
                        pSLRCSisActual,
                        pintPtrNRegistros,
                        lchrArrBuffer,
                        "update Precios set Precio=%s where idPrecio=%s",
                        ObtenPrecio(pchrPtrRegistro),
                        ObtenIdPrecio(pchrPtrRegistro));
	
}
			  

StcLtaRegComSISCOM *RegistraPreciosDelProducto(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     StcLtaRegComSISCOM *pSLRCSisDat,
				     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0,
		   *lSLRCSisDatRegreso=0;
int lintContador;
int lintNRegistros=0;
long llngIdFamilia;	
char lchrArrBuffer[256];
*pintPtrNRegistros=0;

	for(lintContador=0;
	    pSLRCSisDat;
	    lintContador++,
	    pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig)
	{
	 	AnexaRegistroPrecios(pSLRCSisDat->chrPtrRegistro,
				     lintContador,
				     &lintNRegistros,
				     &lSLRCSisDatPrim,
				     &lSLRCSisDatActual);
				      	
	}
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADAltaGenericaElFresno.so",
                                      "ADComandosAlta",
                                      lintNRegistros,
                                      lSLRCSisDatPrim,
                                      &lSLRCSisDatRegreso,
                                      pintPtrNRegistros);	
	return GeneraRespuestaPrecios(pintPtrNRegistros);
}
StcLtaRegComSISCOM *ConsultaPrecios(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     StcLtaRegComSISCOM *pSLRCSisDat,
				     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0,
		   *lSLRCSisDatRegreso=0;
int lintContador;
int lintNRegistros=0;
long llngIdFamilia;	
char lchrArrBuffer[256];
	SISCOMAnexaRegistroFormateandoParaEnvio(
                        &lSLRCSisDatPrim,
                        &lSLRCSisDatActual,
                        &lintNRegistros,
                        lchrArrBuffer,
                        "select * from familias");
		
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADConsultaGenericaElFresno.so",
                                      "ADConsultas",
                                      lintNRegistros,
                                      lSLRCSisDatPrim,
                                      &lSLRCSisDatRegreso,
                                      pintPtrNRegistros);	
	return lSLRCSisDatRegreso;
}
StcLtaRegComSISCOM *GeneraRespuestaPrecios(int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0;

char lchrArrBuffer[256];
	*pintPtrNRegistros=0;
	SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisDatPrim,
                                               &lSLRCSisDatActual,
                                               pintPtrNRegistros,
                                               lchrArrBuffer,
                                               "%ld",
                                               0);

	return lSLRCSisDatPrim;
}
StcLtaRegComSISCOM *OperacionesPrecios(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     StcLtaRegComSISCOM *pSLRCSisDat,
				     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatRegreso=0;
StcOperacionesAlSistema lSOpChoferes[]={ {EsPreciosDelProducto,
					  PreciosDelProducto,
					  RespuestaPreciosDelProducto 
					 },
					 {EsAsignarTiposPreciosAProductosGen,
					  AsignarTiposPreciosAProductosGen,
					  RespuestaAsignarTiposPreciosAProductosGen
					 },
					 {EsAsignarTiposPreciosAProductosClienteDeGen,
				          AsignarTiposPreciosAProductosCLienteDeGen,
					  RespuestaAsignarTiposPreciosAProductosCLienteDeGen
					 },
					 {EsActualizaPrecio,
					  ActualizaPrecio,
					  RespuestaActualizaPrecio
					 }
					};
	SeleccionaYEjecutaOperacionAlSistema(pintPtoComAD,
					     pchrPtrDirIpSvr,
					     lSOpChoferes,
					     4,
					     pSLRCSisDat,
					     &lSLRCSisDatRegreso,
					     pintPtrNRegistros);

	return lSLRCSisDatRegreso;
}

int EsPreciosDelProducto(char **pchrPtrArgumentos,
			       char *pchrPtrConsulta,
			       StcLtaRegComSISCOM *pSLRCSisDat,
			       StcLtaRegComSISCOM **pSLRCSisRegreso)
{
	if(!strcmp(pchrPtrArgumentos[0],
		   "PreciosDelProducto"))
	{
	   printf("EsPreciosDelProducto{%s,%s}\n",
		   pchrPtrArgumentos[1],
		   pchrPtrArgumentos[2]);
	   if(!pchrPtrArgumentos[2])
	   sprintf(pchrPtrConsulta,
		   "select *					\
		    from Precios  				\
			 inner join Personas using(idPersona)	\
		    where CveProducto='%s' \
		    order by idPersona,    \
		             NmbTipoPrecio desc",
		    pchrPtrArgumentos[1]);
	   else
		sprintf(pchrPtrConsulta,
		   "select *					\
		    from Precios  				\
			 inner join Personas using(idPersona)	\
		    where CveProducto='%s'  and			\
		          idPersona='%s' 			\
		    order by idPersona,    			\
		             NmbTipoPrecio desc",
		    pchrPtrArgumentos[1],
		    pchrPtrArgumentos[2]);
	  return 1;
	}
	
		return 0;	


}
		  
void PreciosDelProducto(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     const char *pchrPtrConsulta,
				     StcLtaRegComSISCOM *pSLRCSisDatEntrada,
				     StcLtaRegComSISCOM **pSLRCSisDatRegreso,
				     int *pintPtrNRegreso)
{
*pSLRCSisDatRegreso=ConsultaGenericaALaBaseElFresnoConNumeroRegistros(
	pintPtoComAD,
	 pchrPtrDirIpSvr,
	 pchrPtrConsulta,
	 pintPtrNRegreso);

	SISCOMImprimeContenidoCom2(stdout,
				   "PreciosDelProducto",
				   '|',
				   '\n',
				   *pSLRCSisDatRegreso);
}
void RespuestaPreciosDelProducto(int pintPtoComAD,
			            const char *pchrPtrDirIpSvr,
				    int pintNRegistros,
				    StcLtaRegComSISCOM *pSLRCSisDatEnt,
				    StcLtaRegComSISCOM **pSLRCSisDatRegreso,
				    int *pintPtrNRegistros)
{

	*pSLRCSisDatRegreso=pSLRCSisDatEnt;
	*pintPtrNRegistros=pintNRegistros;

}

int EsAsignarTiposPreciosAProductosGen(char **pchrPtrArgumentos,
			       char *pchrPtrConsulta,
			       StcLtaRegComSISCOM *pSLRCSisDat,
			       StcLtaRegComSISCOM **pSLRCSisRegreso)
{


	return !strcmp(pchrPtrArgumentos[0],
		   "AsignaPreciosALosProductosGeneral");


}
void ConsultaTodosLosProductos(int pintPtoComAD,
			       const char *pchrPtrDirIpSvr,
			       int *pintPtrNRegistros,
				StcLtaRegComSISCOM **pSLRCSisProductos)
{
*pSLRCSisProductos=ConsultaGenericaALaBaseElFresnoConNumeroRegistros(
        pintPtoComAD,
         pchrPtrDirIpSvr,
         "select * from productos",
         pintPtrNRegistros);

        SISCOMImprimeContenidoCom2(stdout,
                                   "Productos",
                                   '|',
                                   '\n',
                                   *pSLRCSisProductos);
}
void ConsultaTodosLosTiposPrecios(int pintPtoComAD,
				  const char *pchrPtrDirIpSvr,
				  int *pintPtrNRegreso,
				  StcLtaRegComSISCOM **pSLRCSisTiposPrecios)
{
*pSLRCSisTiposPrecios=ConsultaGenericaALaBaseElFresnoConNumeroRegistros(
        pintPtoComAD,
         pchrPtrDirIpSvr,
         "select * from tipoprecio",
         pintPtrNRegreso);

        SISCOMImprimeContenidoCom2(stdout,
                                   "PreciosDelProducto",
                                   '|',
                                   '\n',
                                   *pSLRCSisTiposPrecios);

}
void ObtenDatosPublicoEnGeneral(int pintPtoComAD,
				const char *pchrPtrDirIpSvr,
				int *pintPtrNRegreso,
				StcLtaRegComSISCOM **pSLRCSisGeneral)
{
*pSLRCSisGeneral=ConsultaGenericaALaBaseElFresnoConNumeroRegistros(
        pintPtoComAD,
         pchrPtrDirIpSvr,
         "SELECT * from personas where rfc='GENERAL';",
         pintPtrNRegreso);

        SISCOMImprimeContenidoCom2(stdout,
                                   "General",
                                   '|',
                                   '\n',
                                   *pSLRCSisGeneral);

}		  
void AsignarTiposPreciosAProductosGen(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     const char *pchrPtrConsulta,
				     StcLtaRegComSISCOM *pSLRCSisDatEntrada,
				     StcLtaRegComSISCOM **pSLRCSisDatRegreso,
				     int *pintPtrNRegreso)
{
StcLtaRegComSISCOM *lSLRCSisProductos=0,
		   *lSLRCSisTiposPrecios=0,
		   *lSLRCSisTiposPreciosRes=0,
		   *lSLRCSisDatPublicoGeneral=0;
StcLtaRegComSISCOM *lSLRCSisEnvioPrim=0,
		   *lSLRCSisEnvioActual=0;
int lintNRegistrosEnvio=0;
char lchrArrBuffer[1024];
int lintContador=0;
	ConsultaTodosLosProductos(pintPtoComAD,
				  pchrPtrDirIpSvr,
				  pintPtrNRegreso,
				  &lSLRCSisProductos);
	ConsultaTodosLosTiposPrecios(pintPtoComAD,
				     pchrPtrDirIpSvr,
				     pintPtrNRegreso,
				     &lSLRCSisTiposPrecios);
	ObtenDatosPublicoEnGeneral(pintPtoComAD,
				   pchrPtrDirIpSvr,
				   pintPtrNRegreso,
				   &lSLRCSisDatPublicoGeneral);
	for(;
	     lSLRCSisProductos;
	     lSLRCSisProductos=lSLRCSisProductos->LSRCSISCOMPtrSig)
	 for(lSLRCSisTiposPreciosRes=lSLRCSisTiposPrecios;
	      lSLRCSisTiposPreciosRes;
	      lSLRCSisTiposPreciosRes=lSLRCSisTiposPreciosRes->LSRCSISCOMPtrSig)
	 {
	    SISCOMAnexaRegistroFormateandoParaEnvio(
			&lSLRCSisEnvioPrim,
			&lSLRCSisEnvioActual,
			&lintNRegistrosEnvio,
			lchrArrBuffer,
			"insert into Precios values('%s',%s,0,%ld,1,'%s')",
			lSLRCSisProductos->chrPtrRegistro[0],
			lSLRCSisDatPublicoGeneral->chrPtrRegistro[4],
			SISCOMObtenNumeroUnico()+lintContador++,
			lSLRCSisTiposPreciosRes->chrPtrRegistro[0]);

	 }

	SISCOMImprimeContenidoCom2(stdout,
				   "---",
				   '|',
				   '\n',
				   lSLRCSisEnvioPrim);
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADAltaGenericaElFresno.so",
                                      "ADComandosAlta",
                                      lintNRegistrosEnvio,
                                      lSLRCSisEnvioPrim,
                                      pSLRCSisDatRegreso,
                                      pintPtrNRegreso);
}
void RespuestaAsignarTiposPreciosAProductosGen(int pintPtoComAD,
			            const char *pchrPtrDirIpSvr,
				    int pintNRegistros,
				    StcLtaRegComSISCOM *pSLRCSisDatEnt,
				    StcLtaRegComSISCOM **pSLRCSisDatRegreso,
				    int *pintPtrNRegistros)
{

	*pSLRCSisDatRegreso=pSLRCSisDatEnt;
	*pintPtrNRegistros=pintNRegistros;

}


int EsAsignarTiposPreciosAProductosClienteDeGen(char **pchrPtrParametros,
						char *pchrPtrConsulta,
						StcLtaRegComSISCOM *pSLRCSisDat,
						StcLtaRegComSISCOM **pSLRCSisDatSalida)
{
	if(!strcmp(pchrPtrParametros[0],
		   "AsignaPreciosALClienteDeGeneral"))
	{
	 strcpy(pchrPtrConsulta,pchrPtrParametros[1]);
	 return 1;
	}
	else
	return 0;
}
void AsignarTiposPreciosAProductosCLienteDeGen(int pintPtoComAD,
			const char *pchrPtrDirIpSvr,
			const char *pchrPtrConsulta,
			StcLtaRegComSISCOM *pSLRCSisDat,
			StcLtaRegComSISCOM **pSLRCSisDatRegreso,
			int *pintPtrNRegreso)
{
StcLtaRegComSISCOM *lSLRCSisProductos=0,
		   *lSLRCSisTiposPrecios=0,
		   *lSLRCSisTiposPreciosRes=0,
		   *lSLRCSisDatPublicoGeneral=0;
StcLtaRegComSISCOM *lSLRCSisEnvioPrim=0,
		   *lSLRCSisEnvioActual=0;
int lintNRegistrosEnvio=0;
char lchrArrBuffer[1024];
int lintContador=0;
	ConsultaTodosLosProductos(pintPtoComAD,pchrPtrDirIpSvr,pintPtrNRegreso,&lSLRCSisProductos);
	ConsultaTodosLosTiposPrecios(pintPtoComAD,pchrPtrDirIpSvr,pintPtrNRegreso,&lSLRCSisTiposPrecios);
	ObtenDatosPublicoEnGeneral(pintPtoComAD,pchrPtrDirIpSvr,pintPtrNRegreso,&lSLRCSisDatPublicoGeneral);
	for(;
	     lSLRCSisProductos;
	     lSLRCSisProductos=lSLRCSisProductos->LSRCSISCOMPtrSig)
	 for(lSLRCSisTiposPreciosRes=lSLRCSisTiposPrecios;
	      lSLRCSisTiposPreciosRes;
	      lSLRCSisTiposPreciosRes=lSLRCSisTiposPreciosRes->LSRCSISCOMPtrSig)
	 {
	    SISCOMAnexaRegistroFormateandoParaEnvio(
			&lSLRCSisEnvioPrim,
			&lSLRCSisEnvioActual,
			&lintNRegistrosEnvio,
			lchrArrBuffer,
			"insert into Precios values('%s',%s,0,%ld,1,'%s')",
			lSLRCSisProductos->chrPtrRegistro[0],
			pchrPtrConsulta,
			SISCOMObtenNumeroUnico()+lintContador++,
			lSLRCSisTiposPreciosRes->chrPtrRegistro[0]);

	 }

	SISCOMImprimeContenidoCom2(stdout,
				   "---",
				   '|',
				   '\n',
				   lSLRCSisEnvioPrim);
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADAltaGenericaElFresno.so",
                                      "ADComandosAlta",
                                      lintNRegistrosEnvio,
                                      lSLRCSisEnvioPrim,
                                      pSLRCSisDatRegreso,
                                      pintPtrNRegreso);

}
void RespuestaAsignarTiposPreciosAProductosCLienteDeGen(int pintPtoComAD,
				 const char *pchrPtrDirIpSvr,
				 int pintNRegistros,
				 StcLtaRegComSISCOM *pSLRCSisDat,
				 StcLtaRegComSISCOM **pSLRCSisDatReg,	
				 int *pintPtrNRegistrosReg)
{


}
int EsActualizaPrecio(char **pchrPtrArgumentos,
		      char *pchrPtrConsulta,
		      StcLtaRegComSISCOM *pSLRSisDat,
		      StcLtaRegComSISCOM **pSLRCSisRegreso)
{
StcLtaRegComSISCOM *lSLRCSisDatActual=0;
int lintNRegistros=0;
char lchrArrBuffer[256];
		if(!strcmp("ActualizaPrecio",
			   pchrPtrArgumentos[0]))
		{
		    SISCOMImprimeContenidoRegistro(pchrPtrArgumentos,"EsActualizaPrecio");
			SISCOMAnexaRegistroFormateandoParaEnvio(
					pSLRCSisRegreso,
					&lSLRCSisDatActual,
					&lintNRegistros,
					lchrArrBuffer,
					"update precios set precio=%s \
				 where idPersona=%s and \
				       NmbTipoPrecio='%s' and\
				       CveProducto='%s'",
				 pchrPtrArgumentos[3],
				 pchrPtrArgumentos[2],
				 pchrPtrArgumentos[1],
				 pchrPtrArgumentos[4]);
			 printf("EsActualizaPrecio:{%s}\n",
				lchrArrBuffer);
		    return 1;
		}
		else
		return 0;
		

}
void ActualizaPrecio(int pintPtoComAD,
			const char *pchrPtrDirIpSvr,
			const char *pchrPtrConsulta,
			StcLtaRegComSISCOM *pSLRCSisDatEnt,
			StcLtaRegComSISCOM **pSLRCSisDatSalida,
			int *pintPtrNRegSalida)
{
SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADAltaGenericaElFresno.so",
                                      "ADComandosAlta",
                                      1,
                                      pSLRCSisDatEnt,
                                      pSLRCSisDatSalida,
                                      pintPtrNRegSalida);

}
void RespuestaActualizaPrecio(int pintPtoComAD,
				 const char *pchrPtrDirIpSvr,
				 int pintNRegistros,
				 StcLtaRegComSISCOM *pSLRCSisDat,
				 StcLtaRegComSISCOM **pSLRCSisDatRegreso,	
				 int *pintPtrRegRegreso)
{


}

