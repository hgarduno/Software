#include <Gimnasios.h>
#include <RegistraPersona.h>
#include <RegistraDireccion.h>
#include <RegistraMedioComunicacion.h>
#include <RegistraGimnasio.h>
#include <ServidorGeneral.h>

#include <ConsultasGimnasio.h>
#include <ClasificaGimnastas.h>
#include <ResultadosCompetencia.h>
#include <Rondas.h>
#include <Rotaciones.h>
#include <stdlib.h>
#include <string.h>

void InsertaGimnasio(SArgsSiscom *pSAgsSiscom)
{
char *lchrPtrEdoConexion;
int lintSocket;
SiscomMensajesLog(gPtrFleArchivoLog,"InsertaGimnasio");
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,pSAgsSiscom->LCSiscomPro2Dat);
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom));
SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			  gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			  "Inserciones",
			  SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom),
			  SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
			  &lchrPtrEdoConexion,
			  &lintSocket);
}

SiscomOperaciones2 *GeneraOperacionesGimnasio()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;

lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);

SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(AsignaArgumentosOperaciones,lSOpPtrGimnasio); 
SiscomAnexaOperacionAlArreglo2(ArmaEnvioErrores,lSOpPtrGimnasio); 
SiscomAnexaOperacionAlArreglo2(NormalizaContacto,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(AsignaIdentificadores,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(RegistraPersona,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(RegistraDireccion,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(RegistraMedioComunicacion,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(RegistraGimnasio,lSOpPtrGimnasio);
SiscomAnexaOperacionAlArreglo2(InsertaGimnasio,lSOpPtrGimnasio);
return lSOpPtrGimnasio;
}
void AsignaIdentificadores(SArgsSiscom *pSAgsSiscom)
{
char lchrArrIdPersona[12];
char lchrArrIdGimnasio[12];

	SiscomObtenNumeroUnicoChar(lchrArrIdGimnasio);
	SiscomObtenNumeroUnicoChar(lchrArrIdPersona);
	SiscomAsignaDatoCampo2("IdGimnasio",lchrArrIdGimnasio,pSAgsSiscom->LCSiscomPro2Dat);
	SiscomAsignaDatoCampo2("IdPersona",lchrArrIdPersona,pSAgsSiscom->LCSiscomPro2Dat);
}
void AsignaArgumentosOperaciones(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("");
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"C_Normalizado",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"I_Gimnasio",pSAgsSiscom);
SiscomImprimeContenidoProtocolo("",
				gPtrFleArchivoLog,
				pSAgsSiscom->LCSiscomPro2Dat);
}

void NormalizaContacto(SArgsSiscom *pSAgsSiscom)
{
unsigned char *lchrPtrCambia=SiscomCaracteresCambiados();
LCamposSiscomPro2 *lLCSiscomPro2ContactoN=0;
SiscomNormalizaNombre(lchrPtrCambia,
		      pSAgsSiscom->LCSiscomPro2Dat,
		      &lLCSiscomPro2ContactoN);
SiscomAsignaArgumentoOperacionPrim("C_Normalizado",lLCSiscomPro2ContactoN,pSAgsSiscom); 
}

void ConsultaGimnasio(SArgsSiscom *pSAgsSiscom)
{
SSiscomOperaciones2 *lSSOperaciones=0;
SiscomOperaciones2 *lSOpPtrCnsGimnasios=0;
SiscomLog("");
SiscomLeeEntradaOperaciones2(pSAgsSiscom);
SiscomCopiaArgumentosConsulta(pSAgsSiscom);
ComunicacionAccesoDatos(pSAgsSiscom);
SiscomImprimeContenidoProtocolo("ConsultaGimnasio",gPtrFleArchivoLog,pSAgsSiscom->LCSiscomPro2Dat);
SiscomAnexaOperacion2("GimnasiosRegistrados",GimnasiosRegistrados(),&lSSOperaciones);
SiscomAnexaOperacion2("ClasesRegistradas",ClasesRegistradas(),&lSSOperaciones);
SiscomAnexaOperacion2("NivelesRegistrados",NivelesRegistrados(),&lSSOperaciones);
SiscomAnexaOperacion2("GruposRegistrados",GruposRegistrados(),&lSSOperaciones);
SiscomAnexaOperacion2("CompetenciasRegistradas",CompetenciasRegistradas(),&lSSOperaciones);
SiscomAnexaOperacion2("PersonasRegistradas",PersonasRegistradas(),&lSSOperaciones);
SiscomAnexaOperacion2("GimnastasCompetencia",GimnastasCompetencia(),&lSSOperaciones);
SiscomAnexaOperacion2("GimnastasCompetencia01",GimnastasCompetencia01(),&lSSOperaciones);
SiscomAnexaOperacion2("CalificacionGimnasta",CalificacionesGimnasta(),&lSSOperaciones);
SiscomAnexaOperacion2("ClasificaGimnastas",ClasificaGimnastas(),&lSSOperaciones);
SiscomAnexaOperacion2("TiposCompetencia",TiposCompetencia(),&lSSOperaciones);
SiscomAnexaOperacion2("AparatosCompetencia",AparatosCompetencia(),&lSSOperaciones);
SiscomAnexaOperacion2("CompetenciaGeneral",CompetenciaGeneral(),&lSSOperaciones);
SiscomAnexaOperacion2("ResultadosPorAparato",ResultadosPorAparato(),&lSSOperaciones);
SiscomAnexaOperacion2("MediosPersona",MediosPersona(),&lSSOperaciones);
SiscomAnexaOperacion2("DireccionesPersona",DireccionesPersona(),&lSSOperaciones);
SiscomAnexaOperacion2("CalificaRonda",CalificaRonda(),&lSSOperaciones);
SiscomAnexaOperacion2("EjecutaRotacion",OperacionesRotacion(),&lSSOperaciones);
SiscomAnexaOperacion2("RondasCompetencia",ORondasCompetencia(),&lSSOperaciones);
SiscomAnexaOperacion2("TablaResultados",TablaResultados(),&lSSOperaciones);
lSOpPtrCnsGimnasios=SiscomOperaciones2CualEjecuta(
				pSAgsSiscom->chrPtrArgConsulta[0],
				lSSOperaciones,
				ConsultaNoSoportada,
				pSAgsSiscom);
SiscomOperaciones2Ejecuta(lSOpPtrCnsGimnasios,pSAgsSiscom);
}
SiscomOperaciones2 *GeneraConsultasGimnasio()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;

lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(ConsultaGimnasio,lSOpPtrGimnasio);
return lSOpPtrGimnasio;

}

void ConsultaNoSoportada(SArgsSiscom *pSAgsSiscom)
{
SiscomMensajesLog(gPtrFleArchivoLog,"Consulta NO Soportada");
}

void ArmaEnvioErrores(SArgsSiscom *pSAgsSiscom)
{
	pSAgsSiscom->SiscomError[1]=EnviaError; 
					
}
void EnviaError(SArgsSiscom *pSArgsSiscom)
{
	if(pSArgsSiscom->LCSiscomPro2Regreso)
	SiscomEnviaAlServidor(pSArgsSiscom->intSocketCliente,
			      pSArgsSiscom->intNumRegRegreso,
			      "Respuesta",
			      pSArgsSiscom->LCSiscomPro2Regreso);
}

void ComunicacionAccesoDatos(SArgsSiscom *pSAgsSiscom)
{
strcpy(pSAgsSiscom->chrArrDirIpAD,gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos);
pSAgsSiscom->intPtoComAD=gSSiscomConfiguracionSvr.intPtoAccesoDatos;
}
