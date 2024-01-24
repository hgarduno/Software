#include <RNEmpresas.h>

StcCreaConsultas gSCConsultas[]={ {"Expendios",
				   GeneraConsultaExpendios
				  },
				  {
				    "Proveedores",
				    GeneraConsultaProveedores
				  },
				  {
				    "Matriz",
				    GeneraConsultaMatriz
				   },
				  {
				    "DatosDeLaEmpresa",
				    GeneraConsultaDatosDeLaEmpresa
				  },
				  { 
				    "ConsultaPorRazonSocial",
				    GeneraConsultaPorRazonSocial
				  }

				};

int gintCreaConsultas=5;

char *RN_EMPRESA_ObtenRazonSocial(StcLtaRegComSISCOM *pSLRCSisDat)
{
	return pSLRCSisDat->chrPtrRegistro[2];
}
char *RN_EMPRESA_ObtenRFC(StcLtaRegComSISCOM *pSLRCSisDat)
{
	return pSLRCSisDat->chrPtrRegistro[3];
}
char *RN_EMPRESA_ObtenIdEmpresa(StcLtaRegComSISCOM *pSLRCSisDat)
{
	return pSLRCSisDat->chrPtrRegistro[4];
}
char *RN_EMPRESA_ObtenCalle(StcLtaRegComSISCOM *pSLRCSisDat)

{
	return pSLRCSisDat->chrPtrRegistro[5];
}

char *RN_EMPRESA_ObtenNumero(StcLtaRegComSISCOM *pSLRCSisDat)

{
	return pSLRCSisDat->chrPtrRegistro[6];
}
char *RN_EMPRESA_ObtenColonia(StcLtaRegComSISCOM *pSLRCSisDat)

{
	return pSLRCSisDat->chrPtrRegistro[7];
}

char *RN_EMPRESA_ObtenCP(StcLtaRegComSISCOM *pSLRCSisDat)

{
	return pSLRCSisDat->chrPtrRegistro[8][0] ?
	       pSLRCSisDat->chrPtrRegistro[8] :
	       (char *)"0";
}
char *RN_EMPRESA_ObtenMunicipio(StcLtaRegComSISCOM *pSLRCSisDat)

{
	return pSLRCSisDat->chrPtrRegistro[9];
}
char *RN_EMPRESA_ObtenEstado(StcLtaRegComSISCOM *pSLRCSisDat)

{
	return pSLRCSisDat->chrPtrRegistro[10];
}
char *RN_EMPRESA_ObtenReferencias(StcLtaRegComSISCOM *pSLRCSisDat)

{
	return pSLRCSisDat->chrPtrRegistro[11];
}
char *RN_EMPRESA_ObtenConNombre(StcLtaRegComSISCOM *pSLRCSisDat)

{
	return pSLRCSisDat->chrPtrRegistro[12];
}
char *RN_EMPRESA_ObtenConAPaterno(StcLtaRegComSISCOM *pSLRCSisDat)

{
	return pSLRCSisDat->chrPtrRegistro[13];
}
char *RN_EMPRESA_ObtenConAMaterno(StcLtaRegComSISCOM *pSLRCSisDat)

{
	return pSLRCSisDat->chrPtrRegistro[14];
}
char *RN_EMPRESA_ObtenConRFC(StcLtaRegComSISCOM *pSLRCSisDat)

{
	return pSLRCSisDat->chrPtrRegistro[15];
}
char *RN_EMPRESA_ObtenConTipoPersona(StcLtaRegComSISCOM *pSLRCSisDat)

{
	return pSLRCSisDat->chrPtrRegistro[16];
}
char *RN_EMPRESA_ObtenConIdPersona(StcLtaRegComSISCOM *pSLRCSisDat)

{
	return pSLRCSisDat->chrPtrRegistro[17];
}
char *RN_EMPRESA_ObtenTelefono(StcLtaRegComSISCOM *pSLRCSisDat)
{

	return pSLRCSisDat->chrPtrRegistro[18];
}
char *RN_EMPRESA_ObtenEsExpendio(StcLtaRegComSISCOM *pSLRCSisDat)
{

	return pSLRCSisDat->chrPtrRegistro[19];
}
void GeneraConsultaExpendios(char **pchrPtrArgumentos,
			     StcLtaRegComSISCOM *pSLRCSisDat,
			     StcLtaRegComSISCOM **pSLRCSisRegreso,
			     int *pintPtrNRegistros,
			     char *pchrPtrConsulta)
{

	strcpy(pchrPtrConsulta,
	       "select a.*,b.* from empresas as a left outer join matriz as b using(idEmpresa) where idEmpresa < 0;");	

}
void GeneraConsultaProveedores(char **pchrPtrArgumentos,
			     StcLtaRegComSISCOM *pSLRCSisDat,
			     StcLtaRegComSISCOM **pSLRCSisRegreso,
			     int *pintPtrNRegistros,
			     char *pchrPtrConsulta)
{

	strcpy(pchrPtrConsulta,
	       "select *,0 from empresas where idEmpresa > 0;");	

}
void GeneraConsultaMatriz(char **pchrPtrArgumentos,
			     StcLtaRegComSISCOM *pSLRCSisDat,
			     StcLtaRegComSISCOM **pSLRCSisRegreso,
			     int *pintPtrNRegistros,
			     char *pchrPtrConsulta)
{


	strcpy(pchrPtrConsulta,
	       "SELECT *,0 	\
		from empresas 	\
		where idEmpresa in(select 	\
				   idEmpresa 	\
				   from Matriz);");
	
}
void GeneraConsultaDatosDeLaEmpresa(char **pchrPtrArgumentos,
			     StcLtaRegComSISCOM *pSLRCSisDat,
			     StcLtaRegComSISCOM **pSLRCSisRegreso,
			     int *pintPtrNRegistros,
			     char *pchrPtrConsulta)
{


	sprintf(pchrPtrConsulta,
	       "SELECT *,0 	\
		from empresas 	\
		where idEmpresa=%s",
		pchrPtrArgumentos[2]); 
	
}
void GeneraConsultaPorRazonSocial(char **pchrPtrArgumentos,
				  StcLtaRegComSISCOM *pSLRCSisDat,
				  StcLtaRegComSISCOM **pSLRCSisRegreso,
				  int *pintPtrNRegistros,
				  char *pchrPtrConsulta)
{
	
	sprintf(pchrPtrConsulta,
	       "SELECT *,0 	\
		from empresas 	\
		where RazonSocial='%s'",
		pchrPtrArgumentos[2]); 


}
StcLtaRegComSISCOM *OperacionesEmpresas(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     StcLtaRegComSISCOM *pSLRCSisDat,
				     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisRegreso=0;
StcOperacionesAlSistemaSISCOM lSOASistemaSiscom[]=
		{{
		  EsRegistroProveedor,
		  RegistraProveedores,
		  RespuestaGeneralProveedores
		  },
		  {
		   EsConsultaEmpresas,
		   ConsultaEmpresas,
		   RespuestaConsultaEmpresas
		  },
		  {
		   EsRegistraMatriz,
		   RegistraMatriz,
		   RespuestaGeneralProveedores
		  }
		
		};
	SISCOMImprimeContenidoCom(stdout,
				  '|',
				  '\n',
				  pSLRCSisDat);
	SISCOMSeleccionaYEjecutaOperacionAlSistema(pintPtoComAD,
						   pchrPtrDirIpSvr,
						   lSOASistemaSiscom,
						   3,
						   pSLRCSisDat,
						   &lSLRCSisRegreso,
						   pintPtrNRegistros);
	
	return lSLRCSisRegreso;

}
int EsConsultaEmpresas(char **pchrPtrArgumentos,
			char *pchrPtrConsulta,
			StcLtaRegComSISCOM *pSLRCSisDat,
			StcLtaRegComSISCOM **pSLRCSisRegreso,
			int *pintPtrNRegRegreso)
{
int lintContador;
	if(!strcmp(pchrPtrArgumentos[0],
	           "ConsultaEmpresas"))
	{
	  for(lintContador=0;
	      lintContador<gintCreaConsultas;
	      lintContador++)
	   if(!strcmp(gSCConsultas[lintContador].chrPtrNmbConsulta,
		      pchrPtrArgumentos[1]))
	      gSCConsultas[lintContador].EjecutaCreaConsulta(
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
void FormaCondicionConsulta(StcLtaRegComSISCOM *pSLRCSisEmpresas,
			    char **pchrPtrCondicion)
{

char lchrArrCondicion[128];

		*pchrPtrCondicion=(char *)strdup("where idEmpresa in (");	
		for(;
		    pSLRCSisEmpresas;
		    pSLRCSisEmpresas=pSLRCSisEmpresas->LSRCSISCOMPtrSig)
		{
		    if(pSLRCSisEmpresas->LSRCSISCOMPtrSig)
		    {
		      sprintf(lchrArrCondicion,
			      "%s,",
			      pSLRCSisEmpresas->chrPtrRegistro[1]);
							 
		    } 
		    else
		    {
			sprintf(lchrArrCondicion,
			      "%s);",
			      pSLRCSisEmpresas->chrPtrRegistro[1]);
		    }
		       *pchrPtrCondicion=(char *)realloc(*pchrPtrCondicion,
							 strlen(*pchrPtrCondicion)+
							 strlen(lchrArrCondicion));
			strcat(*pchrPtrCondicion,
				lchrArrCondicion);
		}


}
void GeneraCadenaConsulta(const char *pchrPtrTabla,
			  const char *pchrPtrCondicion,
			  char **pchrPtrConsulta)
{
	*pchrPtrConsulta=(char *)malloc(strlen(pchrPtrTabla)+
					strlen(pchrPtrCondicion)+
					120);
	sprintf(*pchrPtrConsulta,
		"select * from %s %s",
		pchrPtrTabla,
		pchrPtrCondicion);
	

}
void GeneraConsultaContactos(const char *pchrPtrCondicion,
			     char **pchrPtrConsulta)
{
	
	*pchrPtrConsulta=(char *)malloc(strlen(pchrPtrCondicion)+
					120);
	sprintf(*pchrPtrConsulta,
		"select *				   \
		 from Contactos				   \
		      inner join Personas using(IdPersona) \
		 %s",
		 pchrPtrCondicion);
	
}
#define NumCampos 19
void AnexaRegistroVacioEmpresa(StcLtaRegComSISCOM **pSLRCSisRegreso,
			 StcLtaRegComSISCOM **pSLRCSisActual,
			 int *pintPtrNRegistros)
{
(*pintPtrNRegistros)++;
SISCOMAnexaRegistroLEnvio(pSLRCSisRegreso,
			  pSLRCSisActual,
			  NumCampos,
			  "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "");

}
void AnexaDatosGenerales(StcLtaRegComSISCOM *pSLRCSisEmpresa,
			 StcLtaRegComSISCOM **pSLRCSisRegreso,
			 StcLtaRegComSISCOM **pSLRCSisActual,
			 int *pintPtrNRegistros)
{

(*pintPtrNRegistros)++;
SISCOMAnexaRegistroLEnvio(pSLRCSisRegreso,
			  pSLRCSisActual,
			  NumCampos,
			  "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
			  pSLRCSisEmpresa->chrPtrRegistro[0],
			  pSLRCSisEmpresa->chrPtrRegistro[1],
			  pSLRCSisEmpresa->chrPtrRegistro[2],
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  pSLRCSisEmpresa->chrPtrRegistro[3]);
			  


}
void AnexaDireccionesEmpresa(StcLtaRegComSISCOM *pSLRCSisEmpresa,
		      StcLtaRegComSISCOM *pSLRCSisDirecciones,
			 StcLtaRegComSISCOM **pSLRCSisRegreso,
			 StcLtaRegComSISCOM **pSLRCSisActual,
			 int *pintPtrNRegistros)
{
	for(;
	    pSLRCSisDirecciones;
	    pSLRCSisDirecciones=pSLRCSisDirecciones->LSRCSISCOMPtrSig)
	if(!strcmp(pSLRCSisDirecciones->chrPtrRegistro[1],
		   pSLRCSisEmpresa->chrPtrRegistro[1]))
	{
	(*pintPtrNRegistros)++;
	SISCOMAnexaRegistroLEnvio(pSLRCSisRegreso,
			  pSLRCSisActual,
			  NumCampos,
			  "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
			  "",
			  "",
			  "",
			  pSLRCSisDirecciones->chrPtrRegistro[1],
			  pSLRCSisDirecciones->chrPtrRegistro[2],
			  pSLRCSisDirecciones->chrPtrRegistro[3],
			  pSLRCSisDirecciones->chrPtrRegistro[4],
			  pSLRCSisDirecciones->chrPtrRegistro[5],
			  pSLRCSisDirecciones->chrPtrRegistro[6],
			  pSLRCSisDirecciones->chrPtrRegistro[7],
			  pSLRCSisDirecciones->chrPtrRegistro[8],
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "");


	}

	AnexaRegistroVacioEmpresa(pSLRCSisRegreso,
				  pSLRCSisActual,
				  pintPtrNRegistros);

}
void AnexaContactosEmpresa(StcLtaRegComSISCOM *pSLRCSisEmpresa,
		         StcLtaRegComSISCOM *pSLRCSisContactos,
			 StcLtaRegComSISCOM **pSLRCSisRegreso,
			 StcLtaRegComSISCOM **pSLRCSisActual,
			 int *pintPtrNRegistros)
{
	for(;
	    pSLRCSisContactos;
	    pSLRCSisContactos=pSLRCSisContactos->LSRCSISCOMPtrSig)
	if(!strcmp(pSLRCSisContactos->chrPtrRegistro[1],
		   pSLRCSisEmpresa->chrPtrRegistro[1]))
	{
	(*pintPtrNRegistros)++;
	SISCOMAnexaRegistroLEnvio(pSLRCSisRegreso,
			  pSLRCSisActual,
			  NumCampos,
			  "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  pSLRCSisContactos->chrPtrRegistro[0],
			  pSLRCSisContactos->chrPtrRegistro[2],
			  pSLRCSisContactos->chrPtrRegistro[3],
			  pSLRCSisContactos->chrPtrRegistro[4],
			  pSLRCSisContactos->chrPtrRegistro[5],
			  pSLRCSisContactos->chrPtrRegistro[6],
			  "",
			  "");


	}

	AnexaRegistroVacioEmpresa(pSLRCSisRegreso,
				  pSLRCSisActual,
				  pintPtrNRegistros);


}	 
void AnexaTelefonosEmpresa(StcLtaRegComSISCOM *pSLRCSisEmpresa,
		      StcLtaRegComSISCOM *pSLRCSisTelefonos,
			 StcLtaRegComSISCOM **pSLRCSisRegreso,
			 StcLtaRegComSISCOM **pSLRCSisActual,
			 int *pintPtrNRegistros)
{
	for(;
	    pSLRCSisTelefonos;
	    pSLRCSisTelefonos=pSLRCSisTelefonos->LSRCSISCOMPtrSig)
	if(!strcmp(pSLRCSisTelefonos->chrPtrRegistro[1],
		   pSLRCSisEmpresa->chrPtrRegistro[1]))
	{
	(*pintPtrNRegistros)++;
	SISCOMAnexaRegistroLEnvio(pSLRCSisRegreso,
			  pSLRCSisActual,
			  NumCampos,
			  "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  "",
			  pSLRCSisTelefonos->chrPtrRegistro[2],
			  "");


	}

	AnexaRegistroVacioEmpresa(pSLRCSisRegreso,
				  pSLRCSisActual,
				  pintPtrNRegistros);



}
void FormaRespuestaEmpresas(StcLtaRegComSISCOM *pSLRCSisEmpresas,
			    StcLtaRegComSISCOM *pSLRCSisDirecciones,
			    StcLtaRegComSISCOM *pSLRCSisContactos,
			    StcLtaRegComSISCOM *pSLRCSisTelefonos,
			    StcLtaRegComSISCOM **pSLRCSisRegreso,
			    int *pintPtrNRegistrosReg)
{
StcLtaRegComSISCOM *lSLRCSisActual=0;
		for(;
		    pSLRCSisEmpresas;
		    pSLRCSisEmpresas=pSLRCSisEmpresas->LSRCSISCOMPtrSig)
		{
		    AnexaDatosGenerales(pSLRCSisEmpresas,
					pSLRCSisRegreso,
					&lSLRCSisActual,
					pintPtrNRegistrosReg);
		    AnexaDireccionesEmpresa(pSLRCSisEmpresas,
				     pSLRCSisDirecciones,
				     pSLRCSisRegreso,
				     &lSLRCSisActual,
					pintPtrNRegistrosReg);
		    AnexaTelefonosEmpresa(pSLRCSisEmpresas,
				     pSLRCSisTelefonos,
				     pSLRCSisRegreso,
				     &lSLRCSisActual,
					pintPtrNRegistrosReg);
		    AnexaContactosEmpresa(pSLRCSisEmpresas,
				     pSLRCSisContactos,
				     pSLRCSisRegreso,
				     &lSLRCSisActual,
					pintPtrNRegistrosReg);
		} 

	SISCOMImprimeContenidoCom2(stdout,
				   "Respuesta Consulta",
				   '|',
				   '\n',
				   *pSLRCSisRegreso);
}
void ConsultaEmpresas(int pintPtoComAD,
			const char *pchrPtrDirIpSvr,
			const char *pchrPtrConsulta,
			StcLtaRegComSISCOM *pSLRCSisDat,
			int pintNRegistros,
			StcLtaRegComSISCOM **pSLRCSisRegreso,
			int *pintPtrNRegreso)
{
StcLtaRegComSISCOM *lSLRCSisDatEmpresas=0;
StcLtaRegComSISCOM *lSLRCSisDatDirEmpresas=0;
StcLtaRegComSISCOM *lSLRCSisDatContactos=0;
StcLtaRegComSISCOM *lSLRCSisDatTelefonos=0;
int lintNRegistrosReg;
char *lchrPtrCondicion;
char *lchrPtrConsulta;
	*pintPtrNRegreso=0;
	lSLRCSisDatEmpresas=ConsultaGenericaALaBaseElFresno(
				pintPtoComAD,
				pchrPtrDirIpSvr,
				pchrPtrConsulta,
				&lintNRegistrosReg);
					
	SISCOMImprimeContenidoCom2(stdout,
				   "ConsultaEmpresas",	
				   '|',
				   '\n',
				    lSLRCSisDatEmpresas);
	if(lSLRCSisDatEmpresas)
	{
	  FormaCondicionConsulta(lSLRCSisDatEmpresas,
				 &lchrPtrCondicion);
	  GeneraCadenaConsulta("Direcciones",
			       (const char *)lchrPtrCondicion,	
			       &lchrPtrConsulta);
	  lSLRCSisDatDirEmpresas=ConsultaGenericaALaBaseElFresno(
				pintPtoComAD,
				pchrPtrDirIpSvr,
				lchrPtrConsulta,
				&lintNRegistrosReg);
	  free(lchrPtrConsulta);	
	  GeneraCadenaConsulta("Telefonos",
			       (const char *)lchrPtrCondicion,
			       &lchrPtrConsulta);
	   lSLRCSisDatTelefonos=ConsultaGenericaALaBaseElFresno(
				pintPtoComAD,
				pchrPtrDirIpSvr,
				lchrPtrConsulta,
				&lintNRegistrosReg);
	 free(lchrPtrConsulta);	
	  GeneraConsultaContactos(lchrPtrCondicion,
				  &lchrPtrConsulta);
	   lSLRCSisDatContactos=ConsultaGenericaALaBaseElFresno(
				pintPtoComAD,
				pchrPtrDirIpSvr,
				lchrPtrConsulta,
				&lintNRegistrosReg);
	   SISCOMImprimeContenidoCom2(stdout,
				      "Direcciones",
				      '|',
				      '\n',
				      lSLRCSisDatDirEmpresas);
	   SISCOMImprimeContenidoCom2(stdout,
				      "Contactos",
				      '|',
				      '\n',
				      lSLRCSisDatContactos);
	   SISCOMImprimeContenidoCom2(stdout,
				      "Telefonos",
				      '|',
				      '\n',
				      lSLRCSisDatTelefonos);
		
	   FormaRespuestaEmpresas(lSLRCSisDatEmpresas,
				        lSLRCSisDatDirEmpresas,
					lSLRCSisDatContactos,
					lSLRCSisDatTelefonos,
					pSLRCSisRegreso,
					pintPtrNRegreso);
	  
	}

}
void RespuestaConsultaEmpresas(int pintPtoComAD,
				const char *pchrPtrDirIpSvr,
				int pintNRegistros,
				StcLtaRegComSISCOM *pSLRCSisDat,
				StcLtaRegComSISCOM **pSLRCSisRegreso,
				int *pintPtrNRegistrosRegreso)
{
	SISCOMImprimeContenidoCom2(stdout,
				   "RespuestaConsultaEmpresas",
				   '|',
				   '\n',
				   pSLRCSisDat);	
	*pintPtrNRegistrosRegreso=pintNRegistros;
	*pSLRCSisRegreso=pSLRCSisDat;

}

void RegistraEmpresa(int pintContador,
		     StcLtaRegComSISCOM **pSLRCSisDat,
		     StcLtaRegComSISCOM **pSLRCSisPrim,
		     StcLtaRegComSISCOM **pSLRCSisActual,
		     int *pintPtrNRegistros,
		     char *pchrPtrIdEmpresa)
{
char lchrArrBuffer[256];
long llngIdEmpresa=SISCOMObtenNumeroUnico()+pintContador;

	llngIdEmpresa=!strcmp((char *)RN_EMPRESA_ObtenEsExpendio(*pSLRCSisDat),"1") ? -llngIdEmpresa : llngIdEmpresa;
	sprintf(pchrPtrIdEmpresa,
		"%ld",
		llngIdEmpresa);
	SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisPrim,
		pSLRCSisActual,
		pintPtrNRegistros,
		lchrArrBuffer,
		"insert into Empresas values('%s',%s,'%s');",
		RN_EMPRESA_ObtenRazonSocial(*pSLRCSisDat),
		pchrPtrIdEmpresa,
		RN_EMPRESA_ObtenRFC(*pSLRCSisDat));
	*pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig;
}
void RegistraDireccionesEmpresa(char *pchrPtrIdEmpresa,
		     	 StcLtaRegComSISCOM **pSLRCSisDat,
		     	 StcLtaRegComSISCOM **pSLRCSisPrim,
		     	 StcLtaRegComSISCOM **pSLRCSisActual,
			 int *pintPtrNRegistros)
{
char lchrArrBuffer[1024];
		for(;
		    !SISCOMEsRegistroVacio((*pSLRCSisDat)->chrPtrRegistro);
		    *pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig)
		{
		SISCOMAnexaRegistroFormateandoParaEnvio(
			pSLRCSisPrim,
			pSLRCSisActual,
			pintPtrNRegistros,
			lchrArrBuffer,
			"insert into Direcciones values(0,%s,'%s','%s','%s',%s,'%s','%s','%s');",
			pchrPtrIdEmpresa,
			RN_EMPRESA_ObtenCalle(*pSLRCSisDat),
			RN_EMPRESA_ObtenNumero(*pSLRCSisDat),
			RN_EMPRESA_ObtenColonia(*pSLRCSisDat),
			RN_EMPRESA_ObtenCP(*pSLRCSisDat),
			RN_EMPRESA_ObtenMunicipio(*pSLRCSisDat),
			RN_EMPRESA_ObtenEstado(*pSLRCSisDat),
			RN_EMPRESA_ObtenReferencias(*pSLRCSisDat));
		}

	*pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig;


}
void RegistraTelefonosEmpresa(char *pchrPtrIdEmpresa,
		     	 StcLtaRegComSISCOM **pSLRCSisDat,
		     	 StcLtaRegComSISCOM **pSLRCSisPrim,
		     	 StcLtaRegComSISCOM **pSLRCSisActual,
			 int *pintPtrNRegistros)
{
char lchrArrBuffer[1024];
		for(;
		    !SISCOMEsRegistroVacio((*pSLRCSisDat)->chrPtrRegistro);
		    *pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig)
		{
		SISCOMAnexaRegistroFormateandoParaEnvio(
			pSLRCSisPrim,
			pSLRCSisActual,
			pintPtrNRegistros,
			lchrArrBuffer,
			"insert into Telefonos values(0,%s,'%s');",
			pchrPtrIdEmpresa,
			RN_EMPRESA_ObtenTelefono(*pSLRCSisDat));
		}

	*pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig;


}
void RegistraContactosEmpresa(char *pchrPtrIdEmpresa,
		     	 StcLtaRegComSISCOM **pSLRCSisDat,
		     	 StcLtaRegComSISCOM **pSLRCSisPrim,
		     	 StcLtaRegComSISCOM **pSLRCSisActual,
			 int *pintPtrNRegistros)
{
char lchrArrBuffer[1024];
int lintContador;
long llngIdContacto;
		for(lintContador=1;
		    !SISCOMEsRegistroVacio((*pSLRCSisDat)->chrPtrRegistro);
		    *pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig,
		    lintContador++)
		{
		llngIdContacto=SISCOMObtenNumeroUnico()+lintContador;
		SISCOMAnexaRegistroFormateandoParaEnvio(
			pSLRCSisPrim,
			pSLRCSisActual,
			pintPtrNRegistros,
			lchrArrBuffer,
			"insert into Personas values('%s','%s','%s','%s',%ld,%s);",
			RN_EMPRESA_ObtenConNombre(*pSLRCSisDat),
			RN_EMPRESA_ObtenConAPaterno(*pSLRCSisDat),
			RN_EMPRESA_ObtenConAMaterno(*pSLRCSisDat),
			RN_EMPRESA_ObtenConRFC(*pSLRCSisDat),
			llngIdContacto,
			RN_EMPRESA_ObtenConTipoPersona(*pSLRCSisDat));
		SISCOMAnexaRegistroFormateandoParaEnvio(
			pSLRCSisPrim,
			pSLRCSisActual,
			pintPtrNRegistros,
			lchrArrBuffer,
			"insert into Contactos values(%ld,%s);",
			llngIdContacto,
			pchrPtrIdEmpresa);
		}

	*pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig;


}
int EsRegistroProveedor(char **pchrPtrArgumentos,
			char *pchrPtrConsulta,
			StcLtaRegComSISCOM *pSLRCSisDat,
			StcLtaRegComSISCOM **pSLRCSisInserciones,
			int *pintPtrNRegistros)
{
int lintContador;
StcLtaRegComSISCOM *lSLRCSisInsercionesActual=0;
char lchrArrIdEmpresa[20];
	*pintPtrNRegistros=0;
	if(!strcmp(pchrPtrArgumentos[0],
		   "RegistraEmpresa"))
	{
	  for(lintContador=0;
	      pSLRCSisDat;
	      pSLRCSisDat=pSLRCSisDat ? pSLRCSisDat->LSRCSISCOMPtrSig : 0,
	      lintContador++)
	 {
	  RegistraEmpresa(lintContador,
			    &pSLRCSisDat,
			    pSLRCSisInserciones,
			    &lSLRCSisInsercionesActual,
			    pintPtrNRegistros,
			    lchrArrIdEmpresa);
	  RegistraDireccionesEmpresa(lchrArrIdEmpresa,
			  	     &pSLRCSisDat,
				     pSLRCSisInserciones,
				     &lSLRCSisInsercionesActual,
				     pintPtrNRegistros);
	  RegistraTelefonosEmpresa(lchrArrIdEmpresa,
			  	     &pSLRCSisDat,
				     pSLRCSisInserciones,
				     &lSLRCSisInsercionesActual,
				     pintPtrNRegistros);
	  RegistraContactosEmpresa(lchrArrIdEmpresa,
			  	     &pSLRCSisDat,
				     pSLRCSisInserciones,
				     &lSLRCSisInsercionesActual,
				     pintPtrNRegistros);
	 }
	  return 1;
	}
	else
	 return 0;


}
void RegistraProveedores(int pintPtoComAD,
			const char *pchrPtrDirIpSvr,
			const char *pchrPtrConsulta,
			StcLtaRegComSISCOM *pSLRCSisDat,
			int pintNRegistros,
			StcLtaRegComSISCOM **pSLRCSisSalida,
			int *pintPtrNSalida)
{
	  SISCOMImprimeContenidoCom2(stdout,
			  	     "Inserciones",
				     '|',
				     '\n',
				     pSLRCSisDat);
	  SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
			  		pchrPtrDirIpSvr,
					"hgarduno",
					"hgarduno",
					"libADAltaGenericaElFresno.so",
					"ADComandosAlta",
					pintNRegistros,
					pSLRCSisDat,
					pSLRCSisSalida,
					pintPtrNSalida);

}
void RespuestaGeneralProveedores(int pintPtoComAD,
				const char *pchrPtrDirIpSvr,
				int pintNRegistros,
				StcLtaRegComSISCOM *pSLRCSisDat,
				StcLtaRegComSISCOM **pSLRCSisRegreso,
				int *pintPtrNRegistrosRegreso)
{

}
int EsRegistraMatriz(char **pchrPtrArgumentos,
			char *pchrPtrConsulta,
			StcLtaRegComSISCOM *pSLRCSisDat,
			StcLtaRegComSISCOM **pSLRCSisRegreso,
			int *pintNRegistros)
{
StcLtaRegComSISCOM *lSRLCSisDatActual=0;
char lchrArrBuffer[128];
	if(!strcmp(pchrPtrArgumentos[0],
		   "RegistraMatriz"))
	{
	  *pintNRegistros=0;
	  SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisRegreso,
		&lSRLCSisDatActual,
	        pintNRegistros,	
		lchrArrBuffer,
		"insert into Matriz values(%s)",
		pchrPtrArgumentos[1]);
		
	  return 1;
	}
	else
	return 0;

}
void RegistraMatriz(int pintPtoComAD,
			const char *pchrPtrDirIpSvr,
			const char *pchrPtrConsulta,
			StcLtaRegComSISCOM *pSLRCSisDat,
			int pintNRegistros,
			StcLtaRegComSISCOM **pSLRCSisDatRegreso,
			int *pintPtrNRegreso)
{

SISCOMImprimeContenidoCom(stdout,
			  '|',
			  '\n',
			  pSLRCSisDat);
SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
			  		pchrPtrDirIpSvr,
					"hgarduno",
					"hgarduno",
					"libADAltaGenericaElFresno.so",
					"ADComandosAlta",
					pintNRegistros,
					pSLRCSisDat,
					pSLRCSisDatRegreso,
					pintPtrNRegreso);


}

