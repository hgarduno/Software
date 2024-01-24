#include <RNIniciaExpendio.h>
#include <RNPersonas.h>
#include <ServidorGeneral.h>

#include <ComunElectronica.h>
#include <ComunElectronica2.h>
#include <stdlib.h>

extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;
StcConsultas gStcCnsIniciaExpendio[]={ {EsConsultaIniciaExpendio,FormaConsultaIniciaExpendio}
			       };
int gintCnsIniciaExpendio=1;

int EsConsultaIniciaExpendio(char **pchrPtrEntrada)
{
	return 1;
}
void FormaConsultaIniciaExpendio(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[128];

	sprintf(lchrArrConsulta,
		"select *		\
		from empresas 		\
		where idEmpresa<0");
 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);


}
void AnalizaConsultaIniciaExpendio(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsIniciaExpendio;
	    lintContador++)
	   if(gStcCnsIniciaExpendio[lintContador].Consulta(pchrPtrEntrada))
	      gStcCnsIniciaExpendio[lintContador].FormaConsulta(pchrPtrEntrada,
	     						  pSOpServidor);

	

}
void ConsultaIniciaExpendio(int pintSocket,
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
	ElectronicaComunicacionExpendio(lSOpServidor.LCSiscomPro2Dat,
					&lSOpServidor.intPtoCom,
					lSOpServidor.chrPtrDirIpSvr);
	SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
					  pintNRegistros,
					  "Parametro",
					  &lchrPtrEntrada);
	AnalizaConsultaIniciaExpendio(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);

	close(pintSocket);
}


void IniciaExpendio(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
char lchrArrFechaHora[52];
const char *lchrPtrIdVendedor;
const char *lchrPtrNumFactura=0,
	   *lchrPtrFechaPago=0,
	   *lchrPtrIdExpendio=0,
	   *lchrPtrIdProveedor=0;
int lintNRegistros=0,
    lintSocketAD;
int lintIdVenta=SiscomObtenNumeroUnico();
float lfltImporte,
	lfltImporteCredito=0,
	lfltPrecio,
	lfltPrecioSinIva;
int lintPtoCom;
char lchrArrDirIpExpendio[40];
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
SiscomMensajesLog(gPtrFleArchivoLog,
		  "RegistraIniciaExpendio");
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,lLCSiscomPro2);
/*
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHora);
	EliminaTotalOrden(lLCSiscomPro2);
	lchrPtrIdVendedor= SiscomObtenDato(lLCSiscomPro2,"IdUnidad"); 
	ElectronicaComunicacionExpendio(lLCSiscomPro2,
					&lintPtoCom,
					lchrArrDirIpExpendio);
  for(;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
  {
  	ValorDelIva(lLCSiscomPro2,&lfltPrecio,&lfltPrecioSinIva);
  	lfltImporte=atof(SiscomObtenDato(lLCSiscomPro2,"Cantidad"))*
		    lfltPrecio;
	 sprintf(lchrArrActualiza,
	 	 "insert into compras values('%s','%s',%s,%f,%s,%s,%s,%s,'%s','%s',%f,%f);",
		 lchrArrFechaHora,
		 SiscomObtenDato(lLCSiscomPro2,"CveProducto"),
		 SiscomObtenDato(lLCSiscomPro2,"Cantidad"),
		 lfltImporte,
		 SiscomObtenDato(lLCSiscomPro2,"IdProveedor"),
		 "0",
		 lchrPtrIdVendedor,
		 SiscomObtenDato(lLCSiscomPro2,"IdExpendio"),
		 SiscomObtenDato(lLCSiscomPro2,"NmbPrecio"),
		 SiscomObtenDato(lLCSiscomPro2,"NumFactura"),
		 lfltPrecio,
		 lfltPrecioSinIva);
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
	sprintf(lchrArrActualiza,
		"update existencias set Existencia=Existencia+%s \
		 where CveProducto='%s' and			 \
		       idExpendio=%s",
		 SiscomObtenDato(lLCSiscomPro2,"Cantidad"),
		 SiscomObtenDato(lLCSiscomPro2,"CveProducto"),
		 SiscomObtenDato(lLCSiscomPro2,"IdExpendio"));

	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
	if(!strcmp(SiscomObtenDato(lLCSiscomPro2, "NmbPrecio"), "Credito"))
	{
  	lfltImporteCredito+=atof(SiscomObtenDato(lLCSiscomPro2,"Cantidad"))*
		    	    atof(SiscomObtenDato(lLCSiscomPro2,"Precio"));
	lchrPtrNumFactura=SiscomObtenDato(lLCSiscomPro2,"NumFactura");
	lchrPtrFechaPago=SiscomObtenDato(lLCSiscomPro2,"FechaPago");
	lchrPtrIdExpendio=SiscomObtenDato(lLCSiscomPro2,"IdExpendio");
	lchrPtrIdProveedor=SiscomObtenDato(lLCSiscomPro2,"IdProveedor");
	}

  }
  	if(lchrPtrNumFactura)
	{
	  sprintf(lchrArrActualiza,
	  	  "insert into cuentasPorPagar values('%s','%s',%f,%s,%s,'%s',%s);",
		  lchrPtrNumFactura,
		  lchrPtrFechaPago,
		  lfltImporteCredito,
		  lchrPtrIdExpendio,
		  lchrPtrIdVendedor,
		  lchrArrFechaHora,
		  lchrPtrIdProveedor);

	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);


	}
  SiscomImprimeContenidoProtocolo("",
  				  gPtrFleArchivoLog,
				  lLCSiscomPro2Ins);
  				  
	SiscomInformacionServidor(lintPtoCom,
	                          lchrArrDirIpExpendio,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Error Al Enviar:%s",
	                  lchrPtrEdoConexion);
	*/
}
