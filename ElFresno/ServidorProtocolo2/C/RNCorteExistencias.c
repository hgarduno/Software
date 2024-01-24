#include <RNCorteExistencias.h>
#include <ServidorGeneral.h>
#include <string.h>

extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;
StcConsultas gStcCnsCorteExistencias[]={ {EsConsultaFechasCorte,FormaConsultaFechasCorte}
			       };
int gintCnsCorteExistencias=1;

int EsConsultaFechasCorte(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"FechasCorte");
}
void FormaConsultaFechasCorte(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];

	sprintf(lchrArrConsulta,
		"select distinct '' as CveProducto,				\
			'' as DscProducto, 					\
			0 as unidad, 						\
			0 as idfamilia, 					\
			fechahoracorte, 					\
			0 as existencia, 					\
			idexpendio, 						\
			0 as cantidadvendida, 					\
			0 as inventario, 					\
			0 as cuadra 						\
		   from corteexistencia 					\
		   	inner join productos using(CveProducto)			\
		   where idExpendio=%s;",
		   pchrPtrEntrada[1]);
 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);
}
void AnalizaConsultaCorteExistencias(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsCorteExistencias;
	    lintContador++)
	   if(gStcCnsCorteExistencias[lintContador].Consulta(pchrPtrEntrada))
	   {
	      gStcCnsCorteExistencias[lintContador].FormaConsulta(pchrPtrEntrada,
	     						  pSOpServidor);
	      break;
	   }

	

}
void ConsultaCorteExistencias(int pintSocket,
		       int pintNRegistros)
{
SiscomOperacionesServidor lSOpServidor;
char **lchrPtrEntrada=0;

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
	AnalizaConsultaCorteExistencias(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);
	close(pintSocket);
}
void FormaCadenaOperacionSqlCorteExistencias(int lintContador,
			     LCamposSiscomPro2 *pLCSiscomPro2,
			     char *pchrPtrCadena)
{
	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Insertar"))
	{
	 sprintf(pchrPtrCadena,
	 	 "insert into CorteExistencias values(%d,%s,'%s');",
		 SiscomObtenNumeroUnico()+lintContador,
		 SiscomObtenDato(pLCSiscomPro2,"IdMateria"),
		 SiscomObtenDato(pLCSiscomPro2,"Nombre"));
	}

	

}
void CorteExistencias(int pintSocket,
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
char lchrArrCadenaSQL[1024];
char lchrArrFechaHoraHoy[30];
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
SiscomMensajesLog(gPtrFleArchivoLog,
		  "RegistraCorteExistencias");
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,lLCSiscomPro2);
  SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoraHoy);
  for(lintContador=0;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig,
	lintContador++)
  {
  	 FormaCadenaOperacionSqlCorteExistencias(lintContador,lLCSiscomPro2,lchrArrActualiza); 
	 sprintf(lchrArrCadenaSQL,
	 	 "update existencias set existencia=existencia-%s   \
		  where CveProducto='%s' and			    \
		       	IdExpendio=%s",
		  SiscomObtenDato(lLCSiscomPro2,"Cantidad"),
		  SiscomObtenDato(lLCSiscomPro2,"CveProducto"),
		  SiscomObtenDato(lLCSiscomPro2,"IdMatriz"));
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrCadenaSQL);
	  sprintf(lchrArrCadenaSQL,
	 	 "update existencias set existencia=existencia+%s   \
		  where CveProducto='%s' and			    \
		       	IdExpendio=%s",
		  SiscomObtenDato(lLCSiscomPro2,"Cantidad"),
		  SiscomObtenDato(lLCSiscomPro2,"CveProducto"),
		  SiscomObtenDato(lLCSiscomPro2,"IdExpendio"));
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrCadenaSQL);
	 sprintf(lchrArrCadenaSQL,
	 	 "insert into transfierematerial values('%s',%s,%s,'%s',%s,%s);",
		 lchrArrFechaHoraHoy,
		 SiscomObtenDato(lLCSiscomPro2,"IdMatriz"),
		 SiscomObtenDato(lLCSiscomPro2,"IdExpendio"),
		 SiscomObtenDato(lLCSiscomPro2,"CveProducto"),
		 SiscomObtenDato(lLCSiscomPro2,"Cantidad"),
		 SiscomObtenDato(lLCSiscomPro2,"IdEmpleado"));

	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrCadenaSQL);


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
void FijaFechaCorte(int pintSocket,
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
char lchrArrCadenaSQL[1024];
char lchrArrFechaHoraHoy[30];
char **lchrPtrEntrada;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
SiscomMensajesLog(gPtrFleArchivoLog,
		  "FijaFechaCorte");
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,lLCSiscomPro2);
  SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoraHoy);
  SiscomCopiaDatosProtocoloCharChar(lLCSiscomPro2,
  				    pintNRegistros,
				    "Parametro",
				    &lchrPtrEntrada);

  SiscomMensajesLog(gPtrFleArchivoLog,
  		    "FijaFechaCorte:Fijando Fecha Corte Expendio:%s",
		    lchrPtrEntrada[1]);
	 sprintf(lchrArrCadenaSQL,
	 	 "insert into corteexistencia	\
		  select CveProducto,		\
		  	 '%s',			\
			 existencia,		\
			 idExpendio 		\
	          from existencias		\
		  where idExpendio=%s",
		  lchrArrFechaHoraHoy,
		  lchrPtrEntrada[1]);
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrCadenaSQL);
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
