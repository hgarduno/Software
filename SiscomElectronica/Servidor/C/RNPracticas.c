#include <RNPracticas.h>
#include <RNPersonas.h>
#include <RNCotizaDispositivos.h>
#include <ServidorGeneral.h>
#include <string.h>

extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;
StcConsultas gStcCnsPracticas[]={ {EsCotizaPractica,CotizaLaPractica},
				  {EsConsultaPracticas,FormaConsultaPracticas}
			       };
int gintCnsPracticas=2;
int EsCotizaPractica(char **pchrPtrEntrada)
{
	if(pchrPtrEntrada[0][0] &&
	   pchrPtrEntrada[1]    &&
	   pchrPtrEntrada[2]    &&
	   pchrPtrEntrada[2]    &&
	   pchrPtrEntrada[1][0] &&
	   pchrPtrEntrada[2][0] )
	 return 1;
	else 
	return 0;

}
int EsConsultaPracticas(char **pchrPtrEntrada)
{
	if(pchrPtrEntrada[0][0])
	return 1;
	else
	return 0;
}
void CotizaLaPractica(char **pchrPtrEntrada,
		    SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[256];
SiscomOperacionesServidor lSOpServidor;
LCamposSiscomPro2 *lLCSiscomPro2Actual=0,
                   *lLCSiscomCotizacion=0;
int lintNRegCotizados=0;
	memcpy(&lSOpServidor,
	       pSOpServidor,
	       sizeof(SiscomOperacionesServidor));
	sprintf(lchrArrConsulta,
		"select * from detallepractica \
		 where idpractica=%s",
		 pchrPtrEntrada[0]);
	
	 SiscomInformacionOperaciones("ConsultaSQL","Consultas",&lSOpServidor);
	 SiscomAnexaRegistroPro2(&lSOpServidor.LCSiscomPro2EPrim,
	                                  &lSOpServidor.LCSiscomPro2EAct,
					  &lSOpServidor.intNRegistros,
					  "ConsultaSQL", 
					  lchrArrConsulta);
	SiscomOperacionesServidores(&lSOpServidor);
	 pSOpServidor->LCSiscomPro2Dat=0;
	 SiscomMensajesLog(gPtrFleArchivoLog,"CotizaLaPractica");
	for(;
	     lSOpServidor.LCSiscomPro2;
	     lSOpServidor.LCSiscomPro2=lSOpServidor.LCSiscomPro2->SCP2PtrSig)
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2Dat,
				&lLCSiscomPro2Actual,
				&pSOpServidor->intNRegistros,
				"CveProducto, \
				 DscProducto, \
				 IdUnidad,    \
				 IdFamilia,   \
				 Precio,      \
				 NmbPrecio,   \
				 Cantidad,    \
				 Existencia,  \
				 IdCliente,   \
				 IdExpendio,  \
				 Importe,     \
				 SePuedeVender,\
				 NumJuegos",
				 SiscomObtenDato(lSOpServidor.LCSiscomPro2,"cveproducto"),
				 "",
				 "",
				 "",
				 "",
				 pchrPtrEntrada[2],
				 SiscomObtenDato(lSOpServidor.LCSiscomPro2,"cantidad"),
				 "",
				 "",
				 pchrPtrEntrada[1],
				 "",
				 "",
				 "1");
				 		 
	
	pSOpServidor->intNRegistros=0;
 	ConsultaProductosCotiza(0,pSOpServidor);
	SiscomOperacionesServidores(pSOpServidor);
	CotizaOrden(pSOpServidor->LCSiscomPro2Dat,
		    pSOpServidor->LCSiscomPro2,
		    1.0,
		    1.0,
		    &lLCSiscomCotizacion,
		    &lintNRegCotizados,
		    0);
	pSOpServidor->LCSiscomPro2=lLCSiscomCotizacion;
	pSOpServidor->intNRegistrosRes=lintNRegCotizados;
	pSOpServidor->LCSiscomPro2EPrim=0;
		
  		

}
void FormaConsultaPracticas(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[128];

	sprintf(lchrArrConsulta,
		"select *		\
		from practicas \
		where idmateria=%s",
		pchrPtrEntrada[0]);
 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);


}
void AnalizaConsultaPracticas(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsPracticas;
	    lintContador++)
	   if(gStcCnsPracticas[lintContador].Consulta(pchrPtrEntrada))
	   {
	      gStcCnsPracticas[lintContador].FormaConsulta(pchrPtrEntrada,
	     						  pSOpServidor);
	      break;
	   }

	

}
void ConsultaPracticas(int pintSocket,
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
	AnalizaConsultaPracticas(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);
	close(pintSocket);
}
void FormaCadenaOperacionSqlPracticas(int lintContador,
			     LCamposSiscomPro2 *pLCSiscomPro2,
			     char *pchrPtrCadena)
{

	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Insertar"))
	{
	 sprintf(pchrPtrCadena,
	 	 "insert into Practicas values(%ld,%s,'%s');",
		 SiscomObtenNumeroUnico()+lintContador,
		 SiscomObtenDato(pLCSiscomPro2,"IdMateria"),
		 SiscomObtenDato(pLCSiscomPro2,"Nombre"));
	}

		   


}
void RegistraPracticas(int pintSocket,
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
SiscomMensajesLog(gPtrFleArchivoLog,
		  "RegistraPracticas");
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,lLCSiscomPro2);
  for(lintContador=0;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig,
	lintContador++)
  {
  	 FormaCadenaOperacionSqlPracticas(lintContador,lLCSiscomPro2,lchrArrActualiza); 
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
  }
  	SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,lLCSiscomPro2Ins);
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Error Al Enviar:%s",
	                  lchrPtrEdoConexion);
}
int FormaCadenaOperacionSqlDetallePractica(int lintContador,
			     LCamposSiscomPro2 *pLCSiscomPro2,
			     char *pchrPtrCadena)
{
int lintRegreso=0;
	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Insertar"))
	{
	 sprintf(pchrPtrCadena,
	 	 "insert into DetallePractica values(%s,'%s',%s);",
		 SiscomObtenDato(pLCSiscomPro2,"IdPractica"),
		 SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
		 SiscomObtenDato(pLCSiscomPro2,"Cantidad"));
	  lintRegreso=1;
	}
	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Eliminar"))
	{
	  sprintf(pchrPtrCadena,
	  	  "delete from detallePractica	\
		   where CveProducto='%s' and idPractica=%s",
		  SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
		  SiscomObtenDato(pLCSiscomPro2,"IdPractica"));
	  return 1;

	}

		   
	return lintRegreso;

}
void RegistraDetallePractica(int pintSocket,
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
EliminaTotalOrden(lLCSiscomPro2);
SiscomMensajesLog(gPtrFleArchivoLog,
		  "RegistraDetallePractica");
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,lLCSiscomPro2);
  for(lintContador=0;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig,
	lintContador++)
  {
  	 if(FormaCadenaOperacionSqlDetallePractica(lintContador,lLCSiscomPro2,lchrArrActualiza))
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
  }
  	SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,lLCSiscomPro2Ins);
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Error Al Enviar:%s",
	                  lchrPtrEdoConexion);
}

