#include <ComunElectronica2.h>
#include <Alumnos.h>
#include <SQLAlumnos.h>
#include <SqlCursos.h>
#include <SiscomAplicaciones.h>

#include <stdlib.h>
SiscomOperaciones2 *OpDatosAlumno()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendio3,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosConsultaAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlDatosAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlTelefonosAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlGrupoAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlCorreosAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ConsultaAlumno,lSOpOperaciones);
return lSOpOperaciones;
}

void ConsultaAlumno(SArgsSiscom *pSAgsSiscom)
{
SiscomContenidoSubRegistrosLog(pSAgsSiscom->LCSiscomPro2SREntrada);
pSAgsSiscom->LCSiscomPro2Regreso=SiscomArgumentoOperacionPrim("SqlAlumno",pSAgsSiscom);
SiscomSumaListas(pSAgsSiscom->LCSiscomPro2Regreso,
		 SiscomArgumentoOperacionPrim("SqlTelefonos",pSAgsSiscom));
SiscomSumaListas(pSAgsSiscom->LCSiscomPro2Regreso,
		 SiscomArgumentoOperacionPrim("SqlCorreos",pSAgsSiscom));
SiscomSumaListas(pSAgsSiscom->LCSiscomPro2Regreso,
		 SiscomArgumentoOperacionPrim("SqlGrupo",pSAgsSiscom));
pSAgsSiscom->intNumRegRegreso=SiscomArgumentosNumeroRegistros("SqlAlumno",pSAgsSiscom)+
			      SiscomArgumentosNumeroRegistros("SqlTelefonos",pSAgsSiscom)+
			      SiscomArgumentosNumeroRegistros("SqlCorreos",pSAgsSiscom)+
			      SiscomArgumentosNumeroRegistros("SqlGrupo",pSAgsSiscom);
SiscomLog("Resultados");
SiscomImprimeArgumento("SqlAlumno",pSAgsSiscom);
SiscomImprimeArgumento("SqlTelefonos",pSAgsSiscom);
SiscomLog("Regresando....");
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
}
void ArgumentosConsultaAlumno(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(4,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlAlumno",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlTelefonos",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"SqlCorreos",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(3,"SqlGrupo",pSAgsSiscom);

}

SiscomOperaciones2 *OPRegistraAlumno()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomValidaNombreVacio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomNormalizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomPersonaEnNormalizados,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomPersonasSimilares,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomDescartaRegistrosSimilares,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomGeneraIdPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersonaEnNormalizados,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraAlumnoExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLActualizaParaClienteElectronica,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraAlumnoEscuela,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraGrupoAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraCelularAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraTelefonoAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraCorreoAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLIniciaComprasCliente,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraAlumno,lSOpOperaciones);
return lSOpOperaciones;

}

SiscomOperaciones2 *OPRegistraAlumnoSiscom()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*200);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomValidaNombreVacio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomNormalizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomPersonaEnNormalizados,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomPersonasSimilares,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomDescartaRegistrosSimilares,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomGeneraIdPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersonaEnNormalizados,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraAlumnoExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLActualizaParaClienteElectronica,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraAlumnoEscuela,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraGrupoAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraCelularAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraTelefonoAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraCorreoAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLIniciaComprasCliente,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraCredencialAlumno,lSOpOperaciones);

SiscomAnexaOperacionAlArreglo2(RegistraAlumno,lSOpOperaciones);
return lSOpOperaciones;

}

SiscomOperaciones2 *OPRegistraAlumno2()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*200);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomValidaNombreVacio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomNormalizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomPersonaEnNormalizados,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomPersonasSimilares,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomDescartaRegistrosSimilares,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomGeneraIdPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersonaEnNormalizados,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraAlumnoExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLActualizaParaClienteElectronica,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraAlumnoEscuela,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraGrupoAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraCelularAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraTelefonoAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraCorreoAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLIniciaComprasCliente,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraAlumno,lSOpOperaciones);
return lSOpOperaciones;

}


SiscomOperaciones2 *OpRegistraAlumnoCurso()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*200);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomValidaNombreVacio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomNormalizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomPersonaEnNormalizados,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomPersonasSimilares,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomDescartaRegistrosSimilares,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomGeneraIdPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomRegistraPersonaEnNormalizados,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraAlumnoExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLActualizaParaClienteElectronica,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraAlumnoEscuela,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraGrupoAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraCelularAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraTelefonoAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraCorreoAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraAlumno,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLIniciaComprasCliente,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraAlumnoInscrito,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlDecrementaDisponibles,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraAlumno,lSOpOperaciones);
return lSOpOperaciones;

}

SiscomOperaciones2 *OpInscribeClienteCurso()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*300);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraAlumnoInscrito,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlDecrementaDisponibles,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraAlumno,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OPAlumnosExpendio()
{

SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlAlumnosExpendio,lSOpOperaciones2);
return lSOpOperaciones2;
}
void RegistraAlumno(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta;
SiscomLog("Inicio");
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SisSQLPersona",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);
SiscomImprimeContenidoProtocolo2("",
                                 SiscomArgumentoOperacionPrim("SisSQLPersona",
				 pSAgsSiscom)); 
SiscomLog("Termino");
}

SiscomOperaciones2 *OpAlumnoYaRegistrado()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*200);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(AsignaCodigosErrorAlumnoCurso,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomValidaNombreVacio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomNormalizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomPersonaEnNormalizados,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomPersonasSimilares,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomDescartaRegistrosSimilares,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OpValidaCamposMinimosRegistroAlumno()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*200);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ValidaCamposMinimosRegistroAlumno,lSOpOperaciones);
return lSOpOperaciones;
}
void AsignaCodigosErrorAlumnoCurso(SArgsSiscom *pSAgsSiscom)
{
pSAgsSiscom->SiscomError[2]=AlumnoYaRegistrado;
}
void ArgumentosAlumnoRegistrado(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlAlumnoRegistrado",pSAgsSiscom);
}
void AlumnoYaRegistrado(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("Viendo si ya esta el alumno");
ArgumentosAlumnoRegistrado(pSAgsSiscom);
SiscomComunicacionMatriz(pSAgsSiscom);
SqlAlumnoRegistrado(pSAgsSiscom);
SiscomEnviaArgumentoCliente("SqlAlumnoRegistrado",pSAgsSiscom);
SiscomImprimeArgumento("SqlAlumnoRegistrado",pSAgsSiscom);

}
/* Lunes 9 de diciembre del 2013 
 * Al dia de hoy se tiene considerada solo la validacion
 * que los campos nombre, apaterno, amaterno no sean 
 * vacios, mas adelante se debera integrar mas validaciones
 * a cada uno de los datos
 */
void ValidacionNombre(SArgsSiscom *pSAgsSiscom,
		     LCamposSiscomPro2 *pLCSiscomPro2RegAct)
{
if(*SiscomCampoDatosEntrada("Nombre",pSAgsSiscom) &&
   *SiscomCampoDatosEntrada("APaterno",pSAgsSiscom) &&
   *SiscomCampoDatosEntrada("AMaterno",pSAgsSiscom))
 SiscomAsignaDatoCampo2("ValidacionNombre","1",pLCSiscomPro2RegAct);
 else
 {
 SiscomAsignaDatoCampo2("ValidacionNombre","0",pLCSiscomPro2RegAct);
 SiscomAsignaDatoCampo2("Mensaje","Los Nombre, Apellido Paterno o Apellido Materno, no pueden estar vacios",pLCSiscomPro2RegAct);
 }
}
void ValidacionCorreoIgual(SArgsSiscom *pSAgsSiscom,
			   LCamposSiscomPro2 *pLCSiscomPro2RegAct)
{
if(!strcmp(SiscomCampoDatosEntrada("Correo",pSAgsSiscom),
	  SiscomCampoDatosEntrada("ReCorreo",pSAgsSiscom)))
 SiscomAsignaDatoCampo2("ValidacionCorreo","1",pLCSiscomPro2RegAct);
 else
 {
 SiscomAsignaDatoCampo2("ValidacionCorreo","0",pLCSiscomPro2RegAct);
 SiscomAsignaDatoCampo2("Mensaje","Los campos de correo y Re correo no son iguales",pLCSiscomPro2RegAct);
 }

}
int ValidacionTelefonosVacios(SArgsSiscom *pSAgsSiscom,
			      LCamposSiscomPro2 *pLCSiscomPro2RegAct)
{
const char *lchrPtrCelular=SiscomCampoDatosEntrada("Celular",pSAgsSiscom);
const char *lchrPtrTelefono=SiscomCampoDatosEntrada("Telefono",pSAgsSiscom);


if(*lchrPtrCelular &&
   !*lchrPtrTelefono)
{
   SiscomAsignaDatoCampo2("ValidacionTelefonos","1",pLCSiscomPro2RegAct);
   return 1;
}
  if(!*lchrPtrCelular &&
      *lchrPtrTelefono)
   {
   SiscomAsignaDatoCampo2("ValidacionTelefonos","1",pLCSiscomPro2RegAct);
   return 1;
   }
  else
  {
   SiscomAsignaDatoCampo2("ValidacionTelefonos","0",pLCSiscomPro2RegAct);
   SiscomAsignaDatoCampo2("Mensaje","Se requiere introducir por lo menos un telefono",pLCSiscomPro2RegAct);
   return 0;
  }
}
int ValidaSoloNumerosCadena(const char *pchrPtrCadena)
{
  while(*pchrPtrCadena)
  {
    if(isdigit(*pchrPtrCadena))
    pchrPtrCadena++;
    else
    return  0;

  }

return 1;
}
void ValidandoTelefonoSoloNumeros(const char *pchrPtrTelefono,
			    const char *pchrPtrMensaje,
			    LCamposSiscomPro2 *pLCSiscomPro2RegAct)
{
if(*pchrPtrTelefono) 
  if(ValidaSoloNumerosCadena(pchrPtrTelefono))
   SiscomAsignaDatoCampo2("ValidacionTelefonos","1",pLCSiscomPro2RegAct);
  else
  {
   SiscomAsignaDatoCampo2("ValidacionTelefonos","0",pLCSiscomPro2RegAct);
   SiscomAsignaDatoCampo2("Mensaje",pchrPtrMensaje,pLCSiscomPro2RegAct);
  }
}
void ValidacionTelefonosSoloNumeros(SArgsSiscom *pSAgsSiscom,
				    LCamposSiscomPro2 *pLCSiscomPro2RegAct)
{
const char *lchrPtrCelular=SiscomCampoDatosEntrada("Celular",pSAgsSiscom);
const char *lchrPtrTelefono=SiscomCampoDatosEntrada("Telefono",pSAgsSiscom);
  
ValidandoTelefonoSoloNumeros(lchrPtrCelular,
			     "El Telefono celular debe contener solo numeros",
			     pLCSiscomPro2RegAct);

ValidandoTelefonoSoloNumeros(lchrPtrTelefono,
			     "El Telefono debe contener solo numeros",
			     pLCSiscomPro2RegAct);

}
void ValidacionTelefonos(SArgsSiscom *pSAgsSiscom,
			 LCamposSiscomPro2 *pLCSiscomPro2RegAct)
{
  if(ValidacionTelefonosVacios(pSAgsSiscom,pLCSiscomPro2RegAct))
   ValidacionTelefonosSoloNumeros(pSAgsSiscom,pLCSiscomPro2RegAct);

}
void ValidaCamposMinimosRegistroAlumno(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0,
		 *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomAnexaRegistroPro2(&lLCSiscomPro2RegPrim,
			&lLCSiscomPro2RegAct,
			&lintNRegRegreso,
			"ValidacionNombre,	\
			 ValidacionCorreo,	\
			 ValidacionTelefonos,	\
			 Mensaje",
			 "",
			 "",
			 "",
			 "");

ValidacionNombre(pSAgsSiscom,lLCSiscomPro2RegAct);
ValidacionCorreoIgual(pSAgsSiscom,lLCSiscomPro2RegAct);
ValidacionTelefonos(pSAgsSiscom,lLCSiscomPro2RegAct);
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      lintNRegRegreso,
		      "Respuesta",
		      lLCSiscomPro2RegPrim);
}


