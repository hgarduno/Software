#include <Consultas.h>
#include <ComunClinicas3.h>
#include <SQLConsultas.h>
#include <SQLEvolucionConsulta.h>
#include <SQLExpedientes.h>
#include <SQLServicios.h>

#include <stdlib.h>
#include <string.h>

SiscomOperaciones2 *OPRecetasPaciente()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRecetasPaciente,lSOpOperaciones); 
return lSOpOperaciones;
}
SiscomOperaciones2 *OPExpediente()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLExpediente,lSOpOperaciones); 
return lSOpOperaciones;
}
SiscomOperaciones2 *OPRecetaConsulta()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRecetaConsulta,lSOpOperaciones); 
return lSOpOperaciones;
}

SiscomOperaciones2 *OPObservacionesConsulta()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLObservacionesConsulta,lSOpOperaciones); 
return lSOpOperaciones;
}
SiscomOperaciones2 *OPConsultaActualMedico()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLConsultasActualMedico,lSOpOperaciones); 
return lSOpOperaciones;
}
SiscomOperaciones2 *OPConsultas()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SeleccionaConsulta,lSOpOperaciones); 
return lSOpOperaciones;
}
SiscomOperaciones2 *OPConsultasPendientesMedico()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLConsultasPendientesMedico,lSOpOperaciones); 
return lSOpOperaciones;
}
SiscomOperaciones2 *OPActualizaEstadoConsulta()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosConsultas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(FechaRegistro,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLCambiaEdoConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraEvolucionConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraConsultas,lSOpOperaciones);
return lSOpOperaciones;

}

SiscomOperaciones2 *OPTerminaConsulta()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosConsultas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLTerminaConsulta,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLServiciosProductosConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLEdoConsultaTermina,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(RegistraConsultas,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OPMaterialServicioHospitalizacion()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosConsultas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistroEliminaServiciosMaterial,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLServiciosProductosConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistroProductoServicio,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(RegistraConsultas,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPMaterialHospSesion()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosConsultas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistroProductoServicio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraConsultas,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OPMaterialHospitalizado()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLMaterialHospitalizado,lSOpOperaciones); 
return lSOpOperaciones;
}
SiscomOperaciones2 *OPRegistraReceta()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosConsultas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(FechaRegistro,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EliminaCaracteresInvalidosReceta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraReceta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraConsultas,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OPActualizaReceta()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosConsultas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(FechaRegistro,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLActualizaReceta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraConsultas,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPRegistraExpediente()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosConsultas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(FechaRegistro,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EliminaCaracteresInvalidosObservaciones,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraExpediente,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraConsultas,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OPActualizaObservaciones()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosConsultas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(FechaRegistro,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EliminaCaracteresInvalidosObservaciones,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLActualizaObservaciones,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraConsultas,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPConsulta()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosConsultas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(GeneraIdConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(FechaRegistro,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EliminaCaracteresInvalidosObservaciones,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraEvolucionConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraConsultas,lSOpOperaciones);
return lSOpOperaciones;

}
void FechaRegistro(SArgsSiscom *pSAgsSiscom)
{
char lchrArrFechaHora[20];
if(!SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Fecha")[0])
{
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHora);
SiscomAsignaDatoCampo2("Fecha",lchrArrFechaHora,pSAgsSiscom->LCSiscomPro2Dat);
}
else
{
SiscomMensajesLog2("Se Capturo la fecha en la interfaz");
}
}
void GeneraIdConsulta(SArgsSiscom *pSAgsSiscom)
{

LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
char lchrArrIdConsulta[12];
  SiscomObtenNumeroUnicoChar(lchrArrIdConsulta);
  SiscomAsignaDatoCampo2("IdConsulta",	
  			 lchrArrIdConsulta,
			 lLCSiscomPro2Dat);
}
void ArgumentosConsultas(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"Consultas",pSAgsSiscom);
}

void RegistraConsultas(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta;
SiscomMensajesLog2("RegistraConsultas");
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "Consultas",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);


SiscomImprimeContenidoProtocolo2("",
				 pSAgsSiscom->LCSiscomPro2Dat);

SiscomImprimeContenidoProtocolo2("",
                                 SiscomArgumentoOperacionPrim("Consultas",
				 pSAgsSiscom));
SiscomMensajesLog2("RegistraConsultas:Termino");
}
int EsLaConsultaSolicitada(StcTiposConsultas *pSTConsulta,
			   char **pchrPtrArgsConsulta)
{

return !strcmp(pSTConsulta->chrPtrConsulta,pchrPtrArgsConsulta[TipoConsulta]);

}
void SolicitudNoDefinida(SArgsSiscom *pSAgsSiscom)
{
SiscomMensajesLog2("SolicitudNoDefinida");
SiscomImprimeContenidoProtocolo2("",pSAgsSiscom->LCSiscomPro2Dat);

}
SQLConsulta ObtenTipoConsulta(StcTiposConsultas *pSTConsulta,
			      char **pchrPtrArgsConsulta)
{
int lintContador;

for(lintContador=0;
    (pSTConsulta+lintContador)->chrPtrConsulta;
    lintContador++)
if(EsLaConsultaSolicitada((pSTConsulta+lintContador),pchrPtrArgsConsulta))
return (pSTConsulta+lintContador)->SQLConsulta;
return SolicitudNoDefinida;

}
void SeleccionaConsulta(SArgsSiscom *pSAgsSiscom)
{
StcTiposConsultas lSTConsultas[]={ 
	{"ConsultasHoyPorEstado",SQLConsultasRegistradasHoyEnEspera},
	{"ConsultasMedicoHoy",SQLConsultasMedicoHoy}
	};
ObtenTipoConsulta(lSTConsultas,pSAgsSiscom->chrPtrArgConsulta)(pSAgsSiscom);
}
void EliminaCaracteresInvalidos(const char *pchrPtrCampo,
				SArgsSiscom *pSAgsSiscom)
{
const char *lchrPtrCaracteres="'\"";
char *lchrPtrDato=(char *)SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,pchrPtrCampo);
if(strcmp(lchrPtrDato,"No Se Encontro El Campo"))
SiscomEliminaCaracteres(lchrPtrCaracteres,lchrPtrDato);
}
void EliminaCaracteresInvalidosObservaciones(SArgsSiscom *pSAgsSiscom)
{
EliminaCaracteresInvalidos("Observaciones",pSAgsSiscom);
}

void EliminaCaracteresInvalidosReceta(SArgsSiscom *pSAgsSiscom)
{
EliminaCaracteresInvalidos("Receta",pSAgsSiscom);
}
