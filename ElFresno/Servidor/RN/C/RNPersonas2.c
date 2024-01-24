#include <RNPersonas2.h>
/*
 *
 *
StcCreaConsultasSISCOM gSCCnsSiscomPersonas2[]={
			{
			  "ConsultaOrdenesPorFecha",
			  CreaConsultaOrdenesPorFecha
			},
			{
			  "OrdenesParaFacturar",
			  CreaConsultaOrdenesAFacturar
			}
		    };

int gintNConsultasPersonas2=2;

void CreaConsultaOrdenesPorFecha(char **pchrPtrParametros,
			       StcLtaRegComSISCOM *pSLRCSisDat,
			       StcLtaRegComSISCOM **pSLRCSisRegreso,
			       int *pintPtrNRegreso,
			       char *pchrPtrConsulta)
{
}
void CreaConsultaOrdenesAFacturar(char **pchrPtrArgumentos,
				  StcLtaRegComSISCOM *pSLRCSisDat,
				  StcLtaRegComSISCOM **pSLRCSisRegreso,
				  int *pintNRegreso,
				  char *pchrPtrConsulta)
{

}
*/
const char *RNPersonas2RFC(StcLtaRegComSISCOM *pSLRCSisDatCom)
{
	return pSLRCSisDatCom->chrPtrRegistro[2];
}

const char *RNPersonas2Nombre(StcLtaRegComSISCOM *pSLRCSisDatCom)
{
	return pSLRCSisDatCom->chrPtrRegistro[3];
}

const char *RNPersonas2APaterno(StcLtaRegComSISCOM *pSLRCSisDatCom)
{
	return pSLRCSisDatCom->chrPtrRegistro[4];
}

const char *RNPersonas2AMaterno(StcLtaRegComSISCOM *pSLRCSisDatCom)
{
	return pSLRCSisDatCom->chrPtrRegistro[5];
}

const char *RNPersonas2Apodo(StcLtaRegComSISCOM *pSLRCSisDatCom)
{
	return pSLRCSisDatCom->chrPtrRegistro[6];
}

const char *RNPersonas2Calle(StcLtaRegComSISCOM *pSLRCSisDatCom)
{
	return pSLRCSisDatCom->chrPtrRegistro[7];
}

const char *RNPersonas2Numero(StcLtaRegComSISCOM *pSLRCSisDatCom)
{
	return pSLRCSisDatCom->chrPtrRegistro[8];
}

const char *RNPersonas2CP(StcLtaRegComSISCOM *pSLRCSisDatCom)
{
	return pSLRCSisDatCom->chrPtrRegistro[9];
}

const char *RNPersonas2Colonia(StcLtaRegComSISCOM *pSLRCSisDatCom)
{
	return pSLRCSisDatCom->chrPtrRegistro[10];
}

const char *RNPersonas2Municipio(StcLtaRegComSISCOM *pSLRCSisDatCom)
{
	return pSLRCSisDatCom->chrPtrRegistro[11];
}

const char *RNPersonas2Estado(StcLtaRegComSISCOM *pSLRCSisDatCom)
{
	return pSLRCSisDatCom->chrPtrRegistro[12];
}

const char *RNPersonas2Referencias(StcLtaRegComSISCOM *pSLRCSisDatCom)
{
	return pSLRCSisDatCom->chrPtrRegistro[13];
}
const char *RNPersonas2Telefono(StcLtaRegComSISCOM *pSLRCSisDatCom)
{
	return pSLRCSisDatCom->chrPtrRegistro[14];
}


StcLtaRegComSISCOM *OperacionesPersonas2(int pintPtoCom,
					     const char *pchrPtrDirIpSvr,
					     StcLtaRegComSISCOM *pSLRCSisDat,
					     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisRegreso=0;

StcOperacionesAlSistema2SISCOM lSOASistemaSiscom[]=
		{
		 {
		   EsRegistroPersonas2,
		   RegistraPersonas2,
		   RespuestaGeneralPersonas2
		  },
		  {
		    EsConsultaPersonas2,
		    ConsultaPersonas2,
		    RespuestaGeneralPersonas2
		  }
		};

SISCOMImprimeContenidoCom2(stdout,
			   "OperacionesPersonas2",
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
void AnexaDireccion(const char *pchrPtrIdPersona,
		    StcLtaRegComSISCOM *pSLRCSisDat,
		    StcLtaRegComSISCOM **pSLRCSisRegreso,
		    int *pintPtrNRegreso)
{
StcLtaRegComSISCOM *lSLRCSisActual=0;
char lchrArrBuffer[1024];
	SISCOMAnexaRegistroFormateandoParaEnvio(
			pSLRCSisRegreso,
			&lSLRCSisActual,
			pintPtrNRegreso,
			lchrArrBuffer,
			"insert into Direcciones values(%s,0,'%s','%s','%s',%s,'%s','%s','%s');",
			pchrPtrIdPersona,
			RNPersonas2Calle(pSLRCSisDat), 
			RNPersonas2Numero(pSLRCSisDat), 
			RNPersonas2Colonia(pSLRCSisDat), 
			RNPersonas2CP(pSLRCSisDat), 
			RNPersonas2Municipio(pSLRCSisDat), 
			RNPersonas2Estado(pSLRCSisDat), 
			RNPersonas2Referencias(pSLRCSisDat));
}
void AnexaTelefono(const char *pchrPtrIdPersona,
		    StcLtaRegComSISCOM *pSLRCSisDat,
		    StcLtaRegComSISCOM **pSLRCSisRegreso,
		    int *pintPtrNRegreso)
{
StcLtaRegComSISCOM *lSLRCSisActual=0;
char lchrArrBuffer[1024];
	SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisRegreso,
		&lSLRCSisActual,
		pintPtrNRegreso,
		lchrArrBuffer,
		"insert into telefonos values(%s,0,'%s');",
		pchrPtrIdPersona,
		RNPersonas2Telefono(pSLRCSisDat));
}
void AnexaRegistroPersonas2(StcLtaRegComSISCOM *pSLRCSisDat,
				int pintContador,
				const char *pchrPtrFirma,
				int *pintPtrNRegistros,
			        StcLtaRegComSISCOM **pSLRCSisPrim,
				StcLtaRegComSISCOM **pSLRCSisActual)
{
char lchrArrBuffer[512];
}
int EsRegistroPersonas2(int pintPtoComAD,
			    const char *pchrPtrDirIpSvr,
			    char **pchrPtrArgumentos,
			    char *pchrPtrConsulta,
			    StcLtaRegComSISCOM *pSLRCSisDat,
			    StcLtaRegComSISCOM **pSLRCSisRegreso,
			    int *pintPtrNRegreso)
{
StcLtaRegComSISCOM *lSLRCSisActual=0;
char lchrArrBuffer[256];
	   *pintPtrNRegreso=0;
	if(!strcmp(pchrPtrArgumentos[0],
		   "ActualizaGenerales"))
	{
	   SISCOMImprimeContenidoRegistro(pchrPtrArgumentos,"EsRegistroPersonas2");
	   SISCOMAnexaRegistroFormateandoParaEnvio(
			  pSLRCSisRegreso,
			  &lSLRCSisActual,
			  pintPtrNRegreso,
			  lchrArrBuffer,
			  "update personas set Nombre='%s',		\
			  		       APaterno='%s',		\
					       AMaterno='%s',		\
					       rfc='%s'			\
			    where idPersona=%s;",
			    RNPersonas2Nombre(pSLRCSisDat),
			    RNPersonas2APaterno(pSLRCSisDat),
			    RNPersonas2AMaterno(pSLRCSisDat),
			    RNPersonas2RFC(pSLRCSisDat),
			    pchrPtrArgumentos[1]);
	   SISCOMAnexaRegistroFormateandoParaEnvio(
			  pSLRCSisRegreso,
			  &lSLRCSisActual,
			  pintPtrNRegreso,
			  lchrArrBuffer,
			  "insert into Apodos values(%s,'%s');",
			  pchrPtrArgumentos[1],
			  RNPersonas2Apodo(pSLRCSisDat));
	SISCOMAnexaRegistroFormateandoParaEnvio(
			  pSLRCSisRegreso,
			  &lSLRCSisActual,
			  pintPtrNRegreso,
			  lchrArrBuffer,
			  "update apodos set Apodo='%s'	\
			   where idPersona=%s",
			  RNPersonas2Apodo(pSLRCSisDat),
			  pchrPtrArgumentos[1]);

	   return 1;
	}
	else
	if(!strcmp(pchrPtrArgumentos[0],
		   "AnexaDireccion"))
	{
	 AnexaDireccion(pchrPtrArgumentos[1],
			pSLRCSisDat,
			pSLRCSisRegreso,
		        pintPtrNRegreso);
	  return 1;
	}
	else
	if(!strcmp(pchrPtrArgumentos[0],
		   "AnexaTelefono"))
	{
	  AnexaTelefono(pchrPtrArgumentos[1],
			pSLRCSisDat,
			pSLRCSisRegreso,
			pintPtrNRegreso);
	  return 1;
	}
	else
	return 0;
}					
void RegistraPersonas2(int pintPtoCom,
			   const char *pchrPtrDirIpSvr,
			   const char *pchrPtrConsulta,
			   StcLtaRegComSISCOM *pSLRCSisDat,
			   int pintNRegistros,
			   StcLtaRegComSISCOM **pSLRCSisRegreso,
			   int *pintPtrNRegistros)
{
	SISCOMImprimeContenidoCom(stdout,
				  '|',
				  '\n',
				  pSLRCSisDat);
	SISCOMEnviaInformacionAlSvrAD(pintPtoCom,	
				      pchrPtrDirIpSvr,
				      "hgarduno",
				      "hgarduno",
				      "libADAltaGenericaElFresno.so",
                                      "ADComandosAlta",
                                      pintNRegistros,
                                      pSLRCSisDat,
                                      pSLRCSisRegreso,
                                      pintPtrNRegistros);
}

void RespuestaGeneralPersonas2(int pintPtoCom,
				   const char *pchrPtrDirIpSvr,
				   int pintNRegistros,
				   StcLtaRegComSISCOM *pSLRCSisDat,
				   StcLtaRegComSISCOM **pSLRCSisRegreso,
				   int *pintPtrNRegistros)
{
	*pintPtrNRegistros=pintNRegistros;
	*pSLRCSisRegreso=pSLRCSisDat;

}
int EsConsultaPersonas2(int pintPtoCom,
			    const char *pchrPtrDirIpSvr,
			    char **pchrPtrArgumentos,
			    char *pchrPtrConsulta,
			    StcLtaRegComSISCOM *pSLRCSisDat,
			    StcLtaRegComSISCOM **pSLRCSisRegreso,
			    int *pintPtrNRegistros)
{
	/*
int lintContador;
	if(!strcmp(pchrPtrArgumentos[0],
		   "ConsultaPersonas2"))
	{
	  for(lintContador=0;
	      lintContador<gintNConsultasPersonas2;
	      lintContador++)
	   if(!strcmp(gSCCnsSiscomPersonas2[lintContador].chrPtrNmbConsulta,
		      pchrPtrArgumentos[1]))
	     gSCCnsSiscomPersonas2[lintContador].EjecutaCreaConsulta(
						pchrPtrArgumentos+2,
						pSLRCSisDat,
						pSLRCSisRegreso,
						pintPtrNRegistros,
						pchrPtrConsulta);

	   return 1;
	}
	else
	return 0;
	*/

	return 0;

}
void ConsultaPersonas2(int pintPtoCom,
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



