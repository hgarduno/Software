#include <RNSistemaElFresno.h>
#include <stdlib.h>
typedef struct OperacionesClinica
{
	const char *chrPtrOperacion;
	StcLtaRegComSISCOM *(*EjecutaOperacion)(int ,const char *,StcLtaRegComSISCOM *,int *);
}StcOperacionesClinica;

typedef struct BusquedasPersonas
{
	int (*EsConsulta)(char **,char *);
	void (*ConsultaALasPersonas)(int ,const char *,const char *,StcLtaRegComSISCOM **);
}StcBusquedasPersonas;
const char *gchrPtrConsultaPersonas="select  * \
				     from    personas as a \
        				     inner join tipospersona as b using(tipoPersona) \
        				     left outer join apodos using(idPersona) \
				     ";
const char *gchrPtrFormatoRespuestaPersonas="%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s";
StcBusquedasPersonas gSBPCriterios[]={  {EsPorAPaterno,CnsAPaterno},	
					{EsPorNombre,CnsNombre},
					{EsPorApodo,CnsApodo},
					{EsPorRFC,CnsRFC},
					{EsPorFirma,CnsAPaterno},
					{EsConsultaPorTipoPersona,CnsAPaterno}
				     };


StcOperacionesClinica gSOpClinica[]={ 
					{"RegistraPersonas",RegistraPersonas},
					{"RegistraFamilias",RegistraFamilias},
					{"RegistraUnidades",RegistraUnidades},
					{"RegistraProductos",RegistraProductos},
					{"RegistraTiposPrecios",RegistraTiposPrecios},
					{"RegistraPreciosDelProducto",RegistraPreciosDelProducto},
					{"RegistraVenta",RegistraVenta},
					{"RegistraPedidos",RegistraPedidos},
					{"RegistraVehiculos",RegistraVehiculos},
					{"ConsultaFamilias",ConsultaFamilias},
					{"ConsultaClavesYDescripciones",ConsultaClavesYDescripciones},
					{"ConsultaUnidades",ConsultaUnidades},
					{"ConsultaVehiculos",ConsultaVehiculos},
					{"ConsultaTiposPrecios",ConsultaTiposPrecios},
					{"ConsultarPersonas",ConsultarPersonas},
					{"ConsultaPedidos",ConsultaPedidos},
					{"EjecutaCotizacion",EjecutaCotizacion},
					{"OperacionesChoferes",OperacionesChoferes},
					{"OperacionesPrecios",OperacionesPrecios},
					{"OperacionesPedidos",OperacionesPedidos},
					{"OperacionesEmpresas",OperacionesEmpresas},
					{"OperacionesCompras",OperacionesCompras},
					{"OperacionesVentasExpendio",OperacionesVentasExpendio},
					{"OperacionesFacturacion",OperacionesFacturacion},
					{"OperacionesPersonas2",OperacionesPersonas2},
					{"ActualizaPedido",ActualizaPedido}
				    };
int gintNOperaciones=26;
int gintNBusquedas=6;
int gintNumParRespuestaPersonas=20;
int EsConsultaPorTipoPersona(char **pchrPtrEntrada,char *pchrPtrConsulta)
{
	  if(!strcmp(pchrPtrEntrada[0],
		     "ConsultaPersonasPorTipoPersona"))
	  {
	     sprintf(pchrPtrConsulta,
	             " where TipoPersona in (select TipoPersona \
		     			   from TiposPersona  \
					   where NmbTipoPersona='%s');",
		     pchrPtrEntrada[1]);


	     return 1;
	  }
	  else
	  return 0;
}
int EsPorFirma(char **pchrPtrEntrada,char *pchrPtrConsulta)
{

	  if(!strcmp(pchrPtrEntrada[0],
		     "ConsultaPersonaPorFirma"))
	  {
	     sprintf(pchrPtrConsulta,
	             " where idPersona in (select idPersona from firmas where firma='%s');",
		     pchrPtrEntrada[1]);

	     return 1;
	  }
	  else
	  return 0;
}
int EsPorAPaterno(char **pchrPtrEntrada,char *pchrPtrConsulta)
{
	if(!pchrPtrEntrada[0][0] &&
	   pchrPtrEntrada[1][0]  &&
	   !pchrPtrEntrada[2][0]  &&
	   !pchrPtrEntrada[3][0]  &&
	   !pchrPtrEntrada[4][0]  )
	{
	    
	    sprintf(pchrPtrConsulta,
		    "where APaterno like '%%%s%%' and TipoPersona=%s",
		    pchrPtrEntrada[1],
		    (pchrPtrEntrada[5]? pchrPtrEntrada[5] : "1"));
	   return 1;
	}
	return 0;	
}
int EsPorApodo(char **pchrPtrParametros,char *pchrPtrConsulta)
{

}
int EsPorRFC(char **pchrPtrParametros,char *pchrPtrConsulta)
{

}

int EsPorNombre(char **pchrPtrParametros,char *pchrPtrConsulta)
{

}
void CnsAPaterno(int pintPtoComAD,
		 const char *pchrPtrDirIpSvr,
		 const char *pchrPtrConsulta,
		 StcLtaRegComSISCOM **pSLRCSisConsulta)
{
char lchrArrBuffer[256];
char lchrArrConsulta[256];
	sprintf(lchrArrConsulta,
		"%s %s",
		gchrPtrConsultaPersonas,
		pchrPtrConsulta);	
	printf("CnsAPaterno:Se Consultara Por El Apellido Paterno:%s\n",
		lchrArrConsulta);
	EjecutaConsultaGenerica(pintPtoComAD,
				pchrPtrDirIpSvr,
				lchrArrConsulta,
				lchrArrBuffer,
				pSLRCSisConsulta);
				
	
}
void CnsNombre(int pintPtoComAD,
	       const char *pchrPtrDirIpSvr,
	       const char *pchrPtrConsulta,
	       StcLtaRegComSISCOM **pSLRCSisConsulta)
{





}
void CnsApodo(int pintPtoComAD,
	      const char *pchrPtrDirIpSvr,
	      const char *pchrPtrConsulta,
	      StcLtaRegComSISCOM **pSLRCSisConsulta)
{

}
void CnsRFC(int pintPtoComAD,
	    const char *pchrPtrDirIpSvr,
	    const char *pchrPtrConsulta,
	    StcLtaRegComSISCOM **pSLRCSisConsulta)
{

}


void RegistraGenerales(StcLtaRegComSISCOM **pSLRCSisDatPrim,
		       StcLtaRegComSISCOM **pSLRCSisDatActual,
		       StcLtaRegComSISCOM **pSLRCSisDat,
		       int *pintPtrNRegistros,
		       char *pchrPtrIdPersona,
		       int pintContador)
{
char lchrArrBuffer[512];
long llngIdPersona=SISCOMObtenNumeroUnico()+pintContador;
	sprintf(pchrPtrIdPersona,"%ld",llngIdPersona);
	SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisDatPrim,
		pSLRCSisDatActual,
		pintPtrNRegistros,
		lchrArrBuffer,
		"insert into TiposPersona values(%s,'%s','%s');",
		ObtenPerfil((*pSLRCSisDat)->chrPtrRegistro),
		ObtenNmbTipoPersona((*pSLRCSisDat)->chrPtrRegistro),
		ObtenDscTipoPersona((*pSLRCSisDat)->chrPtrRegistro));
	
	SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisDatPrim,
		pSLRCSisDatActual,
		pintPtrNRegistros,
		lchrArrBuffer,
		"insert into Personas values('%s','%s','%s','%s',%ld,%s);",
		ObtenNombre((*pSLRCSisDat)->chrPtrRegistro),
		ObtenAPaterno((*pSLRCSisDat)->chrPtrRegistro),
		ObtenAMaterno((*pSLRCSisDat)->chrPtrRegistro),
		ObtenRFC((*pSLRCSisDat)->chrPtrRegistro),
		llngIdPersona,
		ObtenPerfil((*pSLRCSisDat)->chrPtrRegistro));
	if(ObtenFirma((*pSLRCSisDat)->chrPtrRegistro)[0])
	SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisDatPrim,
		pSLRCSisDatActual,
		pintPtrNRegistros,
		lchrArrBuffer,
		"insert into Firmas values('%s',%ld);",
		ObtenFirma((*pSLRCSisDat)->chrPtrRegistro),
		llngIdPersona);
	if(ObtenApodo((*pSLRCSisDat)->chrPtrRegistro)[0])
	SISCOMAnexaRegistroFormateandoParaEnvio(
		pSLRCSisDatPrim,
		pSLRCSisDatActual,
		pintPtrNRegistros,
		lchrArrBuffer,
		"insert into Apodos values(%ld,'%s');",
		llngIdPersona,
		ObtenApodo((*pSLRCSisDat)->chrPtrRegistro));

		
	*pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig;

}

/*
Para el proceso de registro de Empresas se debera utilizar la misma
infraestructura, solo que en lugar de registrar a la tabla de 
personas los datos generales se inserta en empresa, de la 
interfaz se debera indicar que se esta registrando si una 
persona o una empresa

*/
void RegistraDirecciones(const char *pchrPtrIdPersona,
			 const char *pchrPtrIdEmpresa,
			 StcLtaRegComSISCOM **pSLRCSisDatPrim,
			 StcLtaRegComSISCOM **pSLRCSisDatActual,
			 StcLtaRegComSISCOM **pSLRCSisDat,
			 int *pintPtrNRegistros)
{
char lchrArrBuffer[2048];
		for(;
		     !SISCOMEsRegistroVacio((*pSLRCSisDat)->chrPtrRegistro);
		    *pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig)
		{
		SISCOMImprimeContenidoRegistro((*pSLRCSisDat)->chrPtrRegistro,
					       "RegistraDirecciones");
		SISCOMAnexaRegistroFormateandoParaEnvio(
			pSLRCSisDatPrim,
			pSLRCSisDatActual,
			pintPtrNRegistros,
			lchrArrBuffer,
			"insert into Direcciones values(%s,%s,'%s','%s','%s','%s','%s','%s','%s');",
			pchrPtrIdPersona,
			pchrPtrIdEmpresa,
			ObtenCalle((*pSLRCSisDat)->chrPtrRegistro),
			ObtenNumero((*pSLRCSisDat)->chrPtrRegistro),
			ObtenColonia((*pSLRCSisDat)->chrPtrRegistro),
			ObtenCP((*pSLRCSisDat)->chrPtrRegistro),
			ObtenMunicipio((*pSLRCSisDat)->chrPtrRegistro),
			ObtenEstado((*pSLRCSisDat)->chrPtrRegistro),
			ObtenReferencias((*pSLRCSisDat)->chrPtrRegistro));
		}
	*pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig;
}
void RegistraTelefonos(const char *pchrPtrIdPersona,
		       const char *pchrPtrIdEmpresa,
			 StcLtaRegComSISCOM **pSLRCSisDatPrim,
			 StcLtaRegComSISCOM **pSLRCSisDatActual,
			 StcLtaRegComSISCOM **pSLRCSisDat,
			 int *pintPtrNRegistros)
{
char lchrArrBuffer[2048];
		for(;
		     !SISCOMEsRegistroVacio((*pSLRCSisDat)->chrPtrRegistro);
		    *pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig)
		{
		SISCOMImprimeContenidoRegistro((*pSLRCSisDat)->chrPtrRegistro,
					       "RegistraTelefonos");
		SISCOMAnexaRegistroFormateandoParaEnvio(
			pSLRCSisDatPrim,
			pSLRCSisDatActual,
			pintPtrNRegistros,
			lchrArrBuffer,
			"insert into Telefonos values(%s,%s,'%s');",
			pchrPtrIdPersona,
			pchrPtrIdEmpresa,
			ObtenTelefono((*pSLRCSisDat)->chrPtrRegistro));
		}
	*pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig;
}
void RegistraCorreos(const char *pchrPtrIdPersona,
		       const char *pchrPtrIdEmpresa,
			 StcLtaRegComSISCOM **pSLRCSisDatPrim,
			 StcLtaRegComSISCOM **pSLRCSisDatActual,
			 StcLtaRegComSISCOM **pSLRCSisDat,
			 int *pintPtrNRegistros)
{
char lchrArrBuffer[2048];
		for(;
		     (*pSLRCSisDat) &&
		     !SISCOMEsRegistroVacio((*pSLRCSisDat)->chrPtrRegistro);
		    *pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig)
		{
		SISCOMImprimeContenidoRegistro((*pSLRCSisDat)->chrPtrRegistro,
					       "RegistraCorreos");
		SISCOMAnexaRegistroFormateandoParaEnvio(
			pSLRCSisDatPrim,
			pSLRCSisDatActual,
			pintPtrNRegistros,
			lchrArrBuffer,
			"insert into Correos values(%s,%s,'%s');",
			pchrPtrIdPersona,
			pchrPtrIdEmpresa,
			ObtenCorreoElectronico((*pSLRCSisDat)->chrPtrRegistro));
		}
	if(*pSLRCSisDat)
	*pSLRCSisDat=(*pSLRCSisDat)->LSRCSISCOMPtrSig;
}

void EjecutaConsultaGenerica(int pintPtoComAD,
			     const char *pchrPtrDirIpSvr,
			     char *pchrPtrConsulta,
			     char *pchrPtrBuffer,
			     StcLtaRegComSISCOM **pSLRCSisResultado)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
                   *lSLRCSisDatActual=0,
                   *lSLRCSisDatRegreso=0;
int lintContador;
int lintNRegistros=0,
    lintNRegistrosReg;
	SISCOMAnexaRegistroLEnvio(&lSLRCSisDatPrim,
				  &lSLRCSisDatActual,
				  1,
				  "%s",
				  pchrPtrConsulta);
	lintNRegistros++;


        SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADConsultaGenericaElFresno.so",
                                      "ADConsultas",
                                      lintNRegistros,
                                      lSLRCSisDatPrim,
                                      pSLRCSisResultado,
                                      &lintNRegistrosReg);       

}
void ConsultaPersonas(int pintPtoComAD,
			       const char *pchrPtrDirIpAD,
			       const char *pchrPtrAPaterno,
			       StcLtaRegComSISCOM **pSLRCSisDatPersonas)
{
char lchrArrCadConsulta[256];
char lchrArrBuffer[256];
} 
void SeleccionaYEjecutaConsulta(int pintPtoComAD,
			        const char *pchrPtrDirIpSvr,
				char **pchrPtrParametros,
				StcLtaRegComSISCOM **pSLRCSisConsulta)
{
int lintContador;
char lchrArrConsulta[1024];	
	for(lintContador=0;
	    lintContador<gintNBusquedas;
	    lintContador++)
	 if(gSBPCriterios[lintContador].EsConsulta(pchrPtrParametros,lchrArrConsulta))
	   gSBPCriterios[lintContador].ConsultaALasPersonas(pintPtoComAD,
							    pchrPtrDirIpSvr,
							    lchrArrConsulta,
							    pSLRCSisConsulta);
							    
	


}
void FormaCadenaBusquedaPersonas(StcLtaRegComSISCOM *pSLRCSisPersonas,
				 char *pchrPtrCondicion)
{
char lchrArrDato[125];

	sprintf(pchrPtrCondicion,
		"where idPersona in(");
	for(;
	    pSLRCSisPersonas;
	     pSLRCSisPersonas=pSLRCSisPersonas->LSRCSISCOMPtrSig)
	{
	 if(!pSLRCSisPersonas->LSRCSISCOMPtrSig)
	     sprintf(lchrArrDato,
		     "%s)",
		      pSLRCSisPersonas->chrPtrRegistro[0]);  
	 else
	    sprintf(lchrArrDato,
		    "%s,",
		    pSLRCSisPersonas->chrPtrRegistro[0]);
	  strcat(pchrPtrCondicion,lchrArrDato); 
	}
	 

		

}
void AnexaRegistroVacioRespuestaPersonas(StcLtaRegComSISCOM **pSLRCSisPrimRespuesta,
					 StcLtaRegComSISCOM **pSLRCSisActualRespuesta)
{
	SISCOMAnexaRegistroLEnvio(pSLRCSisPrimRespuesta,
                                  pSLRCSisActualRespuesta,
                                  gintNumParRespuestaPersonas,
                                  gchrPtrFormatoRespuestaPersonas,
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
				  "",
				  "");



}
void AnexaDirecciones(const char *pchrPtrIdPersona,
	   StcLtaRegComSISCOM *pSLRCSisEntrada,
	   StcLtaRegComSISCOM **pSLRCSisPrimRespuesta,
	   StcLtaRegComSISCOM **pSLRCSisActualRespuesta,
	   int *pintPtrNRegistros)
{

	for(;
		pSLRCSisEntrada;
		pSLRCSisEntrada=pSLRCSisEntrada->LSRCSISCOMPtrSig)
	
	if(!strcmp(pchrPtrIdPersona,
		   pSLRCSisEntrada->chrPtrRegistro[0]))
	{
	SISCOMAnexaRegistroLEnvio(pSLRCSisPrimRespuesta,
                                  pSLRCSisActualRespuesta,
                                  gintNumParRespuestaPersonas,
                                  gchrPtrFormatoRespuestaPersonas,
				  "",
				  "",
				  "",
				  "",
				  "",
				  "",
				  "",
				  "",
				  "",
				  pSLRCSisEntrada->chrPtrRegistro[2],
				  pSLRCSisEntrada->chrPtrRegistro[3],
				  pSLRCSisEntrada->chrPtrRegistro[4],
				  pSLRCSisEntrada->chrPtrRegistro[5],
				  pSLRCSisEntrada->chrPtrRegistro[6],
				  pSLRCSisEntrada->chrPtrRegistro[7],
				  pSLRCSisEntrada->chrPtrRegistro[8],
				  "",
				  "",
				  "",
				  "");
	 (*pintPtrNRegistros)++;
	}
	AnexaRegistroVacioRespuestaPersonas(pSLRCSisPrimRespuesta,
					    pSLRCSisActualRespuesta);
	 (*pintPtrNRegistros)++;

}				 
void AnexaCorreos(const char *pchrPtrIdPersona,
	   StcLtaRegComSISCOM *pSLRCSisEntrada,
	   StcLtaRegComSISCOM **pSLRCSisPrimRespuesta,
	   StcLtaRegComSISCOM **pSLRCSisActualRespuesta,
	   int *pintPtrNRegistros)
{
	for(;
		pSLRCSisEntrada;
		pSLRCSisEntrada=pSLRCSisEntrada->LSRCSISCOMPtrSig)
	
	if(!strcmp(pchrPtrIdPersona,
		   pSLRCSisEntrada->chrPtrRegistro[0]))
	{
	SISCOMAnexaRegistroLEnvio(pSLRCSisPrimRespuesta,
                                  pSLRCSisActualRespuesta,
                                  gintNumParRespuestaPersonas,
                                  gchrPtrFormatoRespuestaPersonas,
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
				  pSLRCSisEntrada->chrPtrRegistro[2],
				  "",
				  "");
	(*pintPtrNRegistros)++;
	}
	AnexaRegistroVacioRespuestaPersonas(pSLRCSisPrimRespuesta,
					    pSLRCSisActualRespuesta);
	(*pintPtrNRegistros)++;


}				 

void AnexaTelefonos(const char *pchrPtrIdPersona,
	   StcLtaRegComSISCOM *pSLRCSisEntrada,
	   StcLtaRegComSISCOM **pSLRCSisPrimRespuesta,
	   StcLtaRegComSISCOM **pSLRCSisActualRespuesta,
	   int *pintPtrNRegistros)
{
	for(;
		pSLRCSisEntrada;
		pSLRCSisEntrada=pSLRCSisEntrada->LSRCSISCOMPtrSig)
	
	if(!strcmp(pchrPtrIdPersona,
		   pSLRCSisEntrada->chrPtrRegistro[0]))
	{
	SISCOMAnexaRegistroLEnvio(pSLRCSisPrimRespuesta,
                                  pSLRCSisActualRespuesta,
                                  gintNumParRespuestaPersonas,
                                  gchrPtrFormatoRespuestaPersonas,
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
				  pSLRCSisEntrada->chrPtrRegistro[2],
				  "",
				  "",
				  "");
	(*pintPtrNRegistros)++;
	}
	AnexaRegistroVacioRespuestaPersonas(pSLRCSisPrimRespuesta,
					    pSLRCSisActualRespuesta);
	(*pintPtrNRegistros)++;


}				 
void AnexaGenerales(StcLtaRegComSISCOM *pSLRCSisPersona,
	   StcLtaRegComSISCOM **pSLRCSisPrimRespuesta,
	   StcLtaRegComSISCOM **pSLRCSisActualRespuesta,
	   int *pintPtrNRegistros)
{

	SISCOMAnexaRegistroLEnvio(pSLRCSisPrimRespuesta,
                                  pSLRCSisActualRespuesta,
                                  gintNumParRespuestaPersonas,
                                  gchrPtrFormatoRespuestaPersonas,
				  pSLRCSisPersona->chrPtrRegistro[0],
				  pSLRCSisPersona->chrPtrRegistro[1],
				  pSLRCSisPersona->chrPtrRegistro[2],
				  pSLRCSisPersona->chrPtrRegistro[3],
				  pSLRCSisPersona->chrPtrRegistro[4],
				  pSLRCSisPersona->chrPtrRegistro[5],
				  pSLRCSisPersona->chrPtrRegistro[6],
				  pSLRCSisPersona->chrPtrRegistro[7],
				  pSLRCSisPersona->chrPtrRegistro[8],
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
	(*pintPtrNRegistros)++;
		

}  


StcLtaRegComSISCOM *EnviaPersonasConsultadas(int pintPtoComAD,
					     const char *pchrPtrDirIpSvr,
					     const char *pchrPtrCondicionBusqueda,
					     StcLtaRegComSISCOM *pSLRCSisPersonas,
					     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDirecciones=0,
		   *lSLRCSisTelefonos=0,
		   *lSLRCSisApodos=0,
		   *lSLRCSisCorreos=0,
		   *lSLRCSisPrimRespuesta=0,
		   *lSLRCSisActualRespuesta=0;
/*
 * Viernes 5 de septiembre 2008
 *
 * Se tiene que revisar muy bien esta consulta
 * ya que genera una cadena, que conforme aumenta
 * la informacion en la tabla de personas 
 * se va incrementando, ahorita para que corra
 * se hace la salvajada de poner 10000
 */

char lchrArrBuffer[1024],
     lchrArrConsulta[10000];

	sprintf(lchrArrConsulta,
		"select * from direcciones %s",
		pchrPtrCondicionBusqueda);

	EjecutaConsultaGenerica(pintPtoComAD,
				pchrPtrDirIpSvr,
				lchrArrConsulta,
				lchrArrBuffer,
				&lSLRCSisDirecciones);
	sprintf(lchrArrConsulta,
		"select * from telefonos %s",
		pchrPtrCondicionBusqueda);
	EjecutaConsultaGenerica(pintPtoComAD,
				pchrPtrDirIpSvr,
				lchrArrConsulta,
				lchrArrBuffer,
				&lSLRCSisTelefonos);
		sprintf(lchrArrConsulta,
		"select * from correos %s",
		pchrPtrCondicionBusqueda);
	EjecutaConsultaGenerica(pintPtoComAD,
				pchrPtrDirIpSvr,
				lchrArrConsulta,
				lchrArrBuffer,
				&lSLRCSisCorreos);
		sprintf(lchrArrConsulta,
		"select * from apodos %s",
		pchrPtrCondicionBusqueda);
	EjecutaConsultaGenerica(pintPtoComAD,
				pchrPtrDirIpSvr,
				lchrArrConsulta,
				lchrArrBuffer,
				&lSLRCSisApodos);


	
	
	SISCOMImprimeContenidoCom2(stdout,
				   "Direcciones",
				  '|',
				  '\n',
				   lSLRCSisDirecciones);

	SISCOMImprimeContenidoCom2(stdout,
				   "Correos",
				  '|',
				  '\n',
				   lSLRCSisCorreos);
	SISCOMImprimeContenidoCom2(stdout,
				   "Apodos",
				  '|',
				  '\n',
				   lSLRCSisApodos);
	SISCOMImprimeContenidoCom2(stdout,
				   "Telefonos",
				  '|',
				  '\n',
				   lSLRCSisTelefonos);

	*pintPtrNRegistros=0;	
	for(;
	     pSLRCSisPersonas;
	     pSLRCSisPersonas=pSLRCSisPersonas->LSRCSISCOMPtrSig)
	{
		AnexaGenerales(pSLRCSisPersonas,
				 &lSLRCSisPrimRespuesta,
				 &lSLRCSisActualRespuesta,
				 pintPtrNRegistros);
			        
		AnexaDirecciones(pSLRCSisPersonas->chrPtrRegistro[0],
				 lSLRCSisDirecciones,
				 &lSLRCSisPrimRespuesta,
				 &lSLRCSisActualRespuesta,
				 pintPtrNRegistros);
		AnexaTelefonos(pSLRCSisPersonas->chrPtrRegistro[0],
				 lSLRCSisTelefonos,
				 &lSLRCSisPrimRespuesta,
				 &lSLRCSisActualRespuesta,
				 pintPtrNRegistros);
		AnexaCorreos(pSLRCSisPersonas->chrPtrRegistro[0],
				 lSLRCSisCorreos,
				 &lSLRCSisPrimRespuesta,
				 &lSLRCSisActualRespuesta,
				 pintPtrNRegistros);
	}

	SISCOMImprimeContenidoCom2(stdout,
				   "Respuesta ->",
				   '|',
				   '\n',
				   lSLRCSisPrimRespuesta);
	return lSLRCSisPrimRespuesta;
}
StcLtaRegComSISCOM *ConsultarPersonas(int pintPtoComAD,
				    const char *pchrPtrDirIpAD,
				    StcLtaRegComSISCOM *pSLRCSisDatCom,
				    int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisPersonas=0;
char **lchrPtrParametros;	
char lchrArrCondicionBusqueda[10000];

	SISCOMCopiaACharCharDeComunicaciones(pSLRCSisDatCom,
					     1,
					     &lchrPtrParametros);
	SeleccionaYEjecutaConsulta(pintPtoComAD,
					   pchrPtrDirIpAD,
					   lchrPtrParametros,
					   &lSLRCSisPersonas);
	SISCOMImprimeContenidoCom2(stdout,
				  "ConsultarPersonas",
				  '|',
				  '\n',
				   lSLRCSisPersonas);
	FormaCadenaBusquedaPersonas(lSLRCSisPersonas,lchrArrCondicionBusqueda);
	printf("La Busqueda %s\n",lchrArrCondicionBusqueda);
	return EnviaPersonasConsultadas(pintPtoComAD,
					pchrPtrDirIpAD,
					lchrArrCondicionBusqueda,
					lSLRCSisPersonas,
					pintPtrNRegistros);
	

}
StcLtaRegComSISCOM *RegistraPersonas(int pintPtoComAD,
				    const char *pchrPtrDirIpAD,
				    StcLtaRegComSISCOM *pSLRCSisDatCom,
				    int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatEnvioPrim=0,
		   *lSLRCSisDatEnvioActual=0,
		   *lSLRCSisDatRegreso=0,
		   *lSLRCSisDatRespuestaPrim=0,
		   *lSLRCSisDatRespuestaActual=0;
int lintNRegistros=0;
int lintNRegistrosRes=0;
char lchrArrBuffer[256];
char lchrArrIdPersona[25],
     lchrArrIdEmpresa[25];
int lintContador;

	strcpy(lchrArrIdEmpresa,"0");;
	*pintPtrNRegistros=0;
	SISCOMImprimeContenidoCom(stdout,
				  '|',
				  '\n',
				  pSLRCSisDatCom);

	for(lintContador=0;
	    pSLRCSisDatCom;
	    lintContador++)
	
{

		SISCOMImprimeContenidoRegistro(pSLRCSisDatCom->chrPtrRegistro,
					       "RegistraPersonas");
	      RegistraGenerales(&lSLRCSisDatEnvioPrim,
				&lSLRCSisDatEnvioActual,
				&pSLRCSisDatCom,
				&lintNRegistros,
				lchrArrIdPersona,
				lintContador);
	    RegistraDirecciones(lchrArrIdPersona,
				    lchrArrIdEmpresa,
				    &lSLRCSisDatEnvioPrim,
				    &lSLRCSisDatEnvioActual,
				    &pSLRCSisDatCom,
				    &lintNRegistros);
	   RegistraTelefonos(lchrArrIdPersona,
			     lchrArrIdEmpresa,
				    &lSLRCSisDatEnvioPrim,
				    &lSLRCSisDatEnvioActual,
				    &pSLRCSisDatCom,
				    &lintNRegistros);
	   RegistraCorreos(lchrArrIdPersona,
			   lchrArrIdEmpresa,
				    &lSLRCSisDatEnvioPrim,
				    &lSLRCSisDatEnvioActual,
				    &pSLRCSisDatCom,
				    &lintNRegistros);
	}
	SISCOMImprimeContenidoCom(stdout,
				  '|',
				  '\n',
				  lSLRCSisDatEnvioPrim);
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
				      pchrPtrDirIpAD,
				      "hgarduno",
				      "hgarduno",
				      "libADAltaGenericaElFresno.so",
				      "ADComandosAlta",
				      lintNRegistros,
				      lSLRCSisDatEnvioPrim,
				      &lSLRCSisDatRegreso,
				      pintPtrNRegistros);

	/* Aqui se debera colocar la validacion de la insercion */

	SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisDatRespuestaPrim,
					       &lSLRCSisDatRespuestaActual,
					       &lintNRegistrosRes,
					       lchrArrBuffer,
					       "%s",
					       lchrArrIdPersona);
	*pintPtrNRegistros=1;
	return lSLRCSisDatRespuestaPrim;

}


StcLtaRegComSISCOM *EjecutaOperaciones(int pintPtoComAD,
				       const char *pchrPtrDirIpSvrAD,
				       StcLtaRegComSISCOM *pSLRCSisDatCom,
				       int *pintPtrNRegSalida)
{
int lintContador;
	for(lintContador=0;lintContador<gintNOperaciones;lintContador++)
	if(!strcmp(gSOpClinica[lintContador].chrPtrOperacion,pSLRCSisDatCom->chrPtrRegistro[0]))
	{
	 pSLRCSisDatCom=pSLRCSisDatCom->LSRCSISCOMPtrSig;
	 return gSOpClinica[lintContador].EjecutaOperacion(pintPtoComAD,
			 				   pchrPtrDirIpSvrAD,
							   pSLRCSisDatCom,
							   pintPtrNRegSalida);
	}

	return 0;
}
int RNOperacionesElFresno(int pintSCliente,
		       int pintTuberia[],
		       int pintPtoComAD,
		       char *pchrPtrDirIpSvrAD)
{

	SISCOMEjecutaConsultaSvrSiscomYEnviaAlClienteSinEnvioAD(pintSCliente,
								pintPtoComAD,
								pchrPtrDirIpSvrAD,
								EjecutaOperaciones);
}

