#include <SistemaAccesoDatos.h>
#include <ServidorGeneral.h>
#include <POSTGRESQLControlador.h>
#include <string.h>
/*
FILE *gPtrFleArchivoLog;
*/

StcSiscomConfiguracion gSSiscomConfiguracionSvr;
void AccesoDatos(int pintSocket/*,
		 StcSiscomConfiguracion pSSiscomConfiguracionSvr,
		 LCamposSiscomPro2 **pLCSiscomPro2*/)
{
SSiscomOperaciones *lSSiscomOp=0;
int lintContador;
char *lchrPtrOperacion=0;
int lintNRegistros;
	/*gSSiscomConfiguracionSvr=pSSiscomConfiguracionSvr;  */
        OperacionesSistemaGeneral(&lSSiscomOp);
	/* Tepotzotlan Mexico a 13 de Marzo 
	 * se integra el encabezado de la version
	 * del protocolo para poder trabajar en 
	 * el desarrollo del sistema de siscomElectronica 
	 * con la version 4 
	 */
	/*SiscomVersionProtocolo(pintSocket);  */
        SiscomLeeNumeroRegistros(pintSocket,
                                 &lintNRegistros);
        SiscomLeeOperacion(pintSocket,
                           &lchrPtrOperacion);
        for(lintContador=0;
            lintContador<lSSiscomOp->intNumOperaciones;
            lintContador++)
        if(!strcmp((lSSiscomOp+lintContador)->chrPtrOperacion,
                   lchrPtrOperacion))
        {
             (lSSiscomOp+lintContador)->Operacion(pintSocket,lintNRegistros);
             return ;
        }
        SiscomMensajesLog(gPtrFleArchivoLog,
			  "AccesoDatos Actualiza:Operacion {%s} No Soportada",
                           lchrPtrOperacion);
}
void OperacionesSistemaGeneral(SSiscomOperaciones **pSSiscomOp)
{

        SiscomIniciaOperaciones(4,pSSiscomOp);
        SiscomAnexaOperacion("Inserciones",
                             EjecutaInserciones,
                             pSSiscomOp);
        SiscomAnexaOperacion("InsercionesBaseDatos",
                             EjecutaInsercionesBaseDatos,
                             pSSiscomOp);
        SiscomAnexaOperacion("Consultas",
                             EjecutaConsultas,
                             pSSiscomOp);
        SiscomAnexaOperacion("ConsultasBaseDatos",
                             EjecutaConsultasBaseDatos,
                             pSSiscomOp);
}
void EjecutaInserciones(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
	ControladorComandoSQL(gSSiscomConfiguracionSvr.chrPtrBaseDatos,
			      gSSiscomConfiguracionSvr.chrPtrPtoBD,
			      lLCSiscomPro2);
	SiscomEnviaAlServidor(pintSocket,
	                      pintNRegistros,
			      "Respuesta",
			      lLCSiscomPro2);
SiscomContenidoProtocolo(lLCSiscomPro2);
}
void EjecutaInsercionesBaseDatos(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
const char *lchrPtrPtoBaseDatos;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
	lchrPtrPtoBaseDatos=!strcmp(SiscomObtenDato(lLCSiscomPro2,"PtoBaseDatos"),"0") ?
			    0 : SiscomObtenDato(lLCSiscomPro2,"PtoBaseDatos");

	ControladorComandoSQL(SiscomObtenDato(lLCSiscomPro2,"BaseDatos"),
			      lchrPtrPtoBaseDatos,
			      lLCSiscomPro2);
SiscomEnviaAlServidor(pintSocket,
	                      pintNRegistros,
			      "Respuesta",
			      lLCSiscomPro2);
SiscomContenidoProtocolo(lLCSiscomPro2);
}
void EjecutaConsultas(int pintSocket,
		      int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
int lintNColumnas,
    lintNRegistros;
LCamposSiscomPro2 *lLCSiscomPro2Res=0;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
	/*
	SiscomContenidoProtocolo(lLCSiscomPro2);
	*/
	 ControladorEjecutaConsulta(
				gSSiscomConfiguracionSvr.chrPtrBaseDatos,
                                gSSiscomConfiguracionSvr.chrPtrPtoBD,
                                lLCSiscomPro2,
                                &lintNColumnas,
                                &lintNRegistros,
                                &lLCSiscomPro2Res);
	/*
	SiscomContenidoProtocolo(lLCSiscomPro2Res);
	*/
	SiscomEnviaAlServidor(pintSocket,
			      lintNRegistros,
			      "ResultadoConsulta",
			      lLCSiscomPro2Res);
}
void EjecutaConsultasBaseDatos(int pintSocket,
		      int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
int lintNColumnas,
    lintNRegistros;
LCamposSiscomPro2 *lLCSiscomPro2Res=0;
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);

	 ControladorEjecutaConsulta(
	 			SiscomObtenDato(lLCSiscomPro2,"BaseDatos"),
                                SiscomObtenDato(lLCSiscomPro2,"PtoBaseDatos"),
                                lLCSiscomPro2,
                                &lintNColumnas,
                                &lintNRegistros,
                                &lLCSiscomPro2Res);
	SiscomEnviaAlServidor(pintSocket,
			      lintNRegistros,
			      "ResultadoConsulta",
			      lLCSiscomPro2Res);
	/*
	SiscomImprimeContenidoProtocolo("Prueba",
					gPtrFleArchivoLog,
					lLCSiscomPro2Res);

	SiscomContenidoProtocolo(lLCSiscomPro2Res);
	*/		      
}
