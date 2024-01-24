#include <Servicios.h>
#include <ComunElectronica2.h>
#include <SqlServicios.h>
#include <SqlClientes.h>
#include <string.h>
#include <stdlib.h>
#include <SqlServicios.h>
SiscomOperaciones2 *OpServicios()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(200,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlServicios,lSOpOperaciones2);
return lSOpOperaciones2;
}

SiscomOperaciones2 *OpRegistraAlumnoServicio()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*200);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosAlumnoServicio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(GeneraIdRegistroServicio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(AsignaHoraEntrada,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraAlumnoServicio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(AsignaAAlArgumento,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(AsignaCampoIdPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlDatosGeneralesCliente,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraAlumnoServicio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegresaInformacionRegistro,lSOpOperaciones);
return lSOpOperaciones;
}


SiscomOperaciones2 *OpAlumnosServicioSinRegSalida()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*200);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlAlumnosSinRegistroSalida,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraAlumnoServicio,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OpRegistraSalidaServicio()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*200);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosAlumnoServicio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(AsignaHoraSalida,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlActualizaAlumnoServicioHoraSalida,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraAlumnoServicio,lSOpOperaciones);
return lSOpOperaciones;
}

void RegistraAlumnoServicio(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta=0;
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SqlAlumnoServicio",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);
}

void RegresaInformacionRegistro(SArgsSiscom *pSAgsSiscom)
{
char lchrArrNombreCompleto[126];
SiscomPonPrimerRegistroArgumento("SqlPersonalesAlumno",pSAgsSiscom);
sprintf(lchrArrNombreCompleto,
	"%s %s %s",
	SiscomObtenCampoArgumento("SqlPersonalesAlumno","nombre",pSAgsSiscom),
	SiscomObtenCampoArgumento("SqlPersonalesAlumno","apaterno",pSAgsSiscom),
	SiscomObtenCampoArgumento("SqlPersonalesAlumno","amaterno",pSAgsSiscom));
SiscomAnexaRegistroRegreso(pSAgsSiscom,
			   "IdRegistroServicio,IdPersona,HoraEntrada,Nombre",
			    SiscomCampoDatosEntrada("IdRegistroServicio",pSAgsSiscom),
			    "0",
			    SiscomCampoDatosEntrada("HoraEntrada",pSAgsSiscom),
			    lchrArrNombreCompleto);
SiscomEnviaRegreso(pSAgsSiscom);
}
void GeneraIdRegistroServicio(SArgsSiscom *pSAgsSiscom)
{

SiscomGeneraIdRegistro(pSAgsSiscom,"IdRegistroServicio");
}

void ArgumentosAlumnoServicio(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlAlumnoServicio",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlPersonalesAlumno",pSAgsSiscom);
}


void AsignaHoraEntrada(SArgsSiscom *pSAgsSiscom)
{
char lchrArrHora[12];
SiscomObtenHoraActualChar(lchrArrHora);
SiscomAsignaDatoCampo2("HoraEntrada",lchrArrHora,pSAgsSiscom->LCSiscomPro2Dat);
}

void AsignaHoraSalida(SArgsSiscom *pSAgsSiscom)
{
char lchrArrHora[12];
SiscomObtenHoraActualChar(lchrArrHora);
SiscomAsignaDatoCampo2("HoraSalida",lchrArrHora,pSAgsSiscom->LCSiscomPro2Dat);
}

void AsignaCampoIdPersona(SArgsSiscom *pSAgsSiscom)
{
 pSAgsSiscom->Condicion=CampoIdPersona;
}
void AsignaAAlArgumento(SArgsSiscom *pSAgsSiscom)
{
pSAgsSiscom->AAlArgumento=AAlArgumentoPersonales;
}
const char *CampoIdPersona(SArgsSiscom *pSAgsSiscom)
{
return SiscomCampoDatosEntrada("IdAlumno",pSAgsSiscom);
}
const char *AAlArgumentoPersonales(SArgsSiscom *pSAgsSiscom)
{
return "SqlPersonalesAlumno";
}
