#include <RNInventario.h>
#include <RNPersonas.h>
#include <ServidorGeneral.h>

extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;
StcConsultas gStcCnsInventario[]={ {EsConsultaInventario,FormaConsultaInventario}
			       };
int gintCnsInventario=1;

int EsConsultaInventario(char **pchrPtrEntrada)
{
	return 1;
}
void FormaConsultaInventario(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			"select * from escuelas");


}
void AnalizaConsultaInventario(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsInventario;
	    lintContador++)
	   if(gStcCnsInventario[lintContador].Consulta(pchrPtrEntrada))
	      gStcCnsInventario[lintContador].FormaConsulta(pchrPtrEntrada,
	     						  pSOpServidor);

	

}
void ConsultaInventario(int pintSocket,
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
	AnalizaConsultaInventario(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);

	close(pintSocket);
}
void SqlExistenciaActual(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select existencia 		\n\
	 from  existencias 		\n\
	 where cveproducto='%s' and 	\n\
	       idexpendio=%s",
	 SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"),
	 SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio"));

}
void AnexaRegistroPorDesajuste(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			      const char *pchrPtrFecha,
			      const char *pchrPtrHora,
			     LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			      LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			      int *pintPtrNRegistros)
{
char lchrArrSql[512];
char lchrArrExistenciaActual[256];

SqlExistenciaActual(pLCSiscomPro2Dat,lchrArrExistenciaActual);
sprintf(lchrArrSql,
	"insert into DesajusteInventario values(		\n\
				'%s',				\n\
				%s,				\n\
				(%s),				\n\
				%s,				\n\
				'%s',				\n\
				'%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"),
	SiscomObtenDato(pLCSiscomPro2Dat,"FechaPago"),
	lchrArrExistenciaActual,
	SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"),
	pchrPtrFecha,
	pchrPtrHora);
	 SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
	 			pLCSiscomPro2DatAct,	
				pintPtrNRegistros,
				 "ComandoSQL",
				 lchrArrSql);

}
void RegistraInventario(int pintSocket,
		        int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
char lchrArrFecha[25],
     lchrArrHora[25];
const char *lchrPtrIdVendedor;
int lintNRegistros=0,
    lintSocketAD;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
SiscomMensajesLog(gPtrFleArchivoLog,
		  "RegistraInventario");
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,lLCSiscomPro2);
SiscomObtenHoraActualChar(lchrArrHora);
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
  for(;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
  {
  	
	 sprintf(lchrArrActualiza,
	 	 "insert into inventario values('%s',%s,%s,%s,'%s','%s',%s);",
		 SiscomObtenDato(lLCSiscomPro2,"CveProducto"),
		 SiscomObtenDato(lLCSiscomPro2,"Cantidad"),
		 SiscomObtenDato(lLCSiscomPro2,"IdCliente"),
		 SiscomObtenDato(lLCSiscomPro2,"IdExpendio"),
		 lchrArrFecha,
		 lchrArrHora,
		 SiscomObtenDato(lLCSiscomPro2,"NumFactura"));
	 AnexaRegistroPorDesajuste(lLCSiscomPro2,
	 			   lchrArrFecha,
				   lchrArrHora,
	 			   &lLCSiscomPro2Ins,
				   &lLCSiscomPro2InsAct,
				   &lintNRegistros);
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
	sprintf(lchrArrActualiza,
		"update existencias set Existencia=%s \
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

  }
  SiscomImprimeContenidoProtocolo("",
  				  gPtrFleArchivoLog,
				  lLCSiscomPro2Ins);
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
