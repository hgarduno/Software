#include <Clientes4.h>
#include <Facturando4.h>
#include <SqlClientes4.h>


#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>

#include <SiscomNormalizacion.h>

#include <ComunSiscomElectronica4.h>

#include <string.h>

void Direcciones(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlDireccionesPersonaEnvioIdPersona,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaDirecciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ClientesMayoreo(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlClientesMayoreo,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaClientesMayoreo,&lSiscomProDat);

SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}

void PublicoEnGeneral(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlClientePublicoEnGeneral,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaPublicoEnGeneral,&lSiscomProDat);

SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}

void DireccionEscuela(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlDireccionEscuela,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaDireccionEscuela,&lSiscomProDat);

SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}


void RegistraClientePersona(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
SiscomOperacionErrores lSisOpeErrores={0,
				       ElClienteYaSeRegistro,
				       BuscandoAUnClienteEnLaBase,
				       NombreNoCoincide,0};
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoRegistroCliente,&lSiscomProDat);
SiscomAgregaOperacion(GeneraIdPersonaCliente,&lSiscomProDat);
SiscomAgregaOperacion(NormalizaPersona,&lSiscomProDat);
SiscomAgregaOperacion(IdPersonaANormalizada,&lSiscomProDat);
SiscomAgregaOperacion(ClienteRegistrado,&lSiscomProDat);
SiscomAgregaOperacion(AsignaRFCPersonaCliente,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraClientePersona,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraPersonaNormalizada4,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraAlumnoEscuela4,&lSiscomProDat);
SiscomAgregaOperacion(SqlEnviaRegistroCliente,&lSiscomProDat);  
SiscomAgregaOperacion(RegistrandoClientePersona,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,lSisOpeErrores,lSiscomProDat);
}

void RegistraCelularAlumno(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoRegistroCliente,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraCelularAlumno,&lSiscomProDat);
SiscomAgregaOperacion(SqlEnviaRegistroCliente,&lSiscomProDat); 
SiscomAgregaOperacion(RegistrandoCelularAlumno,&lSiscomProDat);

SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RegistraCorreoAlumno(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoRegistroCliente,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraCorreoAlumno,&lSiscomProDat);
SiscomAgregaOperacion(SqlEnviaRegistroCliente,&lSiscomProDat); 
SiscomAgregaOperacion(RegistrandoCorreoAlumno,&lSiscomProDat);

SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void RegistraDireccionAlumno(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoRegistroCliente,&lSiscomProDat);
SiscomAgregaOperacion(AsignaIdDireccion,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraDireccionAlumno,&lSiscomProDat);
SiscomAgregaOperacion(SqlEnviaRegistroCliente,&lSiscomProDat);
SiscomAgregaOperacion(RegistrandoDireccionAlumno,&lSiscomProDat);

SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int AsignaIdDireccion(SiscomOperaciones *pSisOpePtrDato)
{

SiscomIdAsociadoAsociadosCampoEntrada("Envio","Direccion","IdDireccion0",pSisOpePtrDato);
return 0;
}
int RegistrandoClientePersona(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
  SiscomAsociadosArgumentoLog("SqlCliente",
  			      "SentenciasSql",
			      lchrArrBuffer,
			      pSiscomOpePtrDato);
  SiscomRegistroProtocoloLog(lchrArrBuffer,pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
  RegresandoIdPersonaCliente(pSiscomOpePtrDato);
  return 0;
}

int RegistrandoCorreoAlumno(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
  SiscomAsociadosArgumentoLog("SqlCliente",
  			      "SentenciasSql",
			      lchrArrBuffer,
			      pSiscomOpePtrDato);
  return 0;
}
int RegistrandoCelularAlumno(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
  SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
  SiscomAsociadoAsociadoLog("Envio","Celular",lchrArrBuffer,pSiscomOpePtrDato);
  SiscomAsociadosArgumentoLog("SqlCliente",
  			      "SentenciasSql",
			      lchrArrBuffer,
			      pSiscomOpePtrDato);
  return 0;
}
int RegistrandoDireccionAlumno(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];

SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
  SiscomAsociadosArgumentoLog("SqlCliente",
  			      "SentenciasSql",
			      lchrArrBuffer,
			      pSiscomOpePtrDato);
  return 0;
}


int GeneraIdPersonaCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdARegistrosAsociadosEntrada("Envio",
				   "IdPersona",
				   pSiscomOpePtrDato);

return 0;
}
int AsignaRFCPersonaCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char *lchrPtrRFC,
	*lchrPtrIdPersona;
if(!(lchrPtrRFC=(char *)SiscomCampoAsociadoEntradaOperacion("Envio","RFC",pSiscomOpePtrDato)))
{
lchrPtrIdPersona=(char *)SiscomCampoAsociadoEntradaOperacion("Envio","IdPersona",pSiscomOpePtrDato);
SiscomActualizaCampoAsociadoEntrada("Envio","RFC",lchrPtrIdPersona,pSiscomOpePtrDato);
}
return 0;
}

int RegresandoIdPersonaCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrRegPrim=0,
		   *lSiscomRegProLPtrRegAct=0;
SiscomAnexaRegistroPro(&lSiscomRegProLPtrRegPrim,
		       &lSiscomRegProLPtrRegAct,
		       lchrArrBuffer,
		       "Registrado,IdPersona,",
		       "0",
		        SiscomCampoAsociadoEntradaOperacion("Envio","IdPersona",pSiscomOpePtrDato));
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrRegPrim);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrRegPrim);
return 0;
}

int EnviaPublicoEnGeneral(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
LogSiscom("");
SiscomEnviaAsociadoRespuestaCliente("PublicoEnGeneral",lchrArrBuffer,pSiscomOpePtrDato);
}
int EnviaClientesMayoreo(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
LogSiscom("");
SiscomEnviaAsociadoRespuestaCliente("ClientesMayoreo",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}

int EnviaDirecciones(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
LogSiscom("____------_____");
SiscomEnviaAsociadoRespuestaCliente("SqlDirecciones",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}

void FormaRegistroBusquedaCliente(SiscomRegistroProL **pSiscomRegProLPtrPrim,
				  SiscomRegistroProL **pSiscomRegProLPtrAct)
{
char lchrArrBuffer[128];
SiscomAnexaRegistroPro(pSiscomRegProLPtrPrim,
		    pSiscomRegProLPtrAct,
		    lchrArrBuffer,
		    "Sql,SqlDirecciones,SqlTelefonos,SqlCorreos,",
		    (const char *)0,
		    (const char *)0,
		    (const char *)0,
		    (const char *)0);
}
int DatosCompletosValidos(SiscomOperaciones *pSisOpePtrDato)
{

if(SiscomCampoArgumentoPrim("Normalizado","Nombre",pSisOpePtrDato) &&
   SiscomCampoArgumentoPrim("Normalizado","APaterno",pSisOpePtrDato) &&
   SiscomCampoArgumentoPrim("Normalizado","AMaterno",pSisOpePtrDato))
  return 1;

}
int BuscaClienteCompleto(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrSql[512],
     lchrArrSqlDirecciones[256],
     lchrArrSqlCorreos[256],
     lchrArrSqlTelefonos[256];
SiscomRegistroProL *lSiscomRegProLPtrConsultaPrim=0,
		   *lSiscomRegProLPtrConsultaAct=0;
if(DatosCompletosValidos(pSiscomOpePtrDato))
{
FormaRegistroBusquedaCliente(&lSiscomRegProLPtrConsultaPrim,
			     &lSiscomRegProLPtrConsultaAct);
/*
sprintf(lchrArrSql,
	"select *			\n\
	 from personanormalizada	\n\
	 where nombre='%s' and 		\n\
	       apaterno='%s' and 	\n\
	       amaterno='%s'",
*/
sprintf(lchrArrSql,
"								\n\
select a.idpersona,						\n\
	a.nombre,						\n\
	a.apaterno,						\n\
	a.amaterno,						\n\
	idescuela,						\n\
	b.nombre as escuela  					\n\
from personanormalizada as a left outer join 			\n\
     alumnoescuela using(idpersona) left outer join 		\n\
     escuelas as b using(idescuela)  				\n\
where a.nombre='%s' and apaterno='%s' and amaterno='%s'",
	     SiscomCampoArgumentoPrim("Normalizado","Nombre",pSiscomOpePtrDato),
	     SiscomCampoArgumentoPrim("Normalizado","APaterno",pSiscomOpePtrDato),
	     SiscomCampoArgumentoPrim("Normalizado","AMaterno",pSiscomOpePtrDato));
ConsultasInformacionPersona(pSiscomOpePtrDato,
			    lchrArrSqlDirecciones,
			    lchrArrSqlCorreos,
			    lchrArrSqlTelefonos);
SiscomActualizaCampoAsignaMemoria2("Sql",lchrArrSql,lSiscomRegProLPtrConsultaPrim);
SiscomActualizaCampoAsignaMemoria2("SqlDirecciones",lchrArrSqlDirecciones,lSiscomRegProLPtrConsultaPrim);
SiscomActualizaCampoAsignaMemoria2("SqlCorreos",lchrArrSqlCorreos,lSiscomRegProLPtrConsultaPrim);
SiscomActualizaCampoAsignaMemoria2("SqlTelefonos",lchrArrSqlTelefonos,lSiscomRegProLPtrConsultaPrim);
SiscomAgregaArgumentoOperacion("ConsultaSql",
				lSiscomRegProLPtrConsultaPrim,
				lSiscomRegProLPtrConsultaAct,
				pSiscomOpePtrDato);
return 1;
}
else
return 0;
}
int ClientesPorNombre(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrSql[4192];
SiscomRegistroProL *lSiscomRegProLPtrConsultaPrim=0,
		   *lSiscomRegProLPtrConsultaAct=0;
if(SiscomCampoAsociadoEntradaOperacion("Envio","Nombre",pSiscomOpePtrDato) 	&&
   !SiscomCampoAsociadoEntradaOperacion("Envio","APaterno",pSiscomOpePtrDato) 	&&
   !SiscomCampoAsociadoEntradaOperacion("Envio","AMaterno",pSiscomOpePtrDato))
{
LogSiscom("---------------------------- Solo viene el Nombre --------------");
FormaRegistroBusquedaCliente(&lSiscomRegProLPtrConsultaPrim,
			     &lSiscomRegProLPtrConsultaAct);
sprintf(lchrArrSql,
	"									\n\
select a.nombre   || 								\n\
                ' '      ||							\n\
                a.apaterno ||							\n\
                ' '      ||							\n\
                a.amaterno as completo,						\n\
                a.nombre,							\n\
                a.apaterno,							\n\
                a.amaterno,							\n\
                a.idpersona,							\n\
                ' '      ||							\n\
                ' '      ||							\n\
                ' '      ||							\n\
                ''   as direcciones,						\n\
                '' as telefonos,							\n\
                '' as correos,							\n\
                f.nombre as escuela,						\n\
                f.idescuela 							\n\
from personas as a left outer join  					\n\
     personanormalizada as g using(idpersona) left outer join		\n\
     alumnoescuela as e using(idpersona) left outer join 		\n\
     escuelas as f using(idescuela)					\n\
where g.nombre like '%%%s%%'",
	 SiscomCampoArgumentoPrim("Normalizado","Nombre",pSiscomOpePtrDato));
SiscomActualizaCampoAsignaMemoria2("Sql",lchrArrSql,lSiscomRegProLPtrConsultaPrim);
SiscomAgregaArgumentoOperacion("ConsultaSql",
				lSiscomRegProLPtrConsultaPrim,
				lSiscomRegProLPtrConsultaAct,
				pSiscomOpePtrDato);
return 1;
}
else
return 0;
}
int NormalizaCadenaParaConsulta(const char *pchrPtrCadena,
				 unsigned char **pchrPtrSalida)
{
*pchrPtrSalida=0;
  if(pchrPtrCadena && *pchrPtrCadena)
  {
   SiscomNormaliza2(pchrPtrCadena, SiscomCaracteresCambiados(),pchrPtrSalida);
   return 1;
  }
  else
  {
  LogSiscom("3");
  return 0;
  }
}
int ClientesPorNombreAPaterno(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrSql[4192];
SiscomRegistroProL *lSiscomRegProLPtrConsultaPrim=0,
		   *lSiscomRegProLPtrConsultaAct=0;
const char *lchrPtrNombre,
	   *lchrPtrAPaterno,
	   *lchrPtrAMaterno;

lchrPtrNombre=SiscomCampoArgumentoPrim("Normalizado","Nombre",pSiscomOpePtrDato);
lchrPtrAPaterno=SiscomCampoArgumentoPrim("Normalizado","APaterno",pSiscomOpePtrDato);
lchrPtrAMaterno=SiscomCampoArgumentoPrim("Normalizado","AMaterno",pSiscomOpePtrDato);
LogSiscom("Buscando por nombre y apellido paterno");
if(lchrPtrNombre && lchrPtrAPaterno && !lchrPtrAMaterno)
{
FormaRegistroBusquedaCliente(&lSiscomRegProLPtrConsultaPrim,
			     &lSiscomRegProLPtrConsultaAct);
sprintf(lchrArrSql,
	"select distinct						\n\
		g.nombre   || 						\n\
	        ' ' 	 ||						\n\
		g.apaterno ||						\n\
		' '      ||						\n\
		g.amaterno as completo,					\n\
		g.nombre,						\n\
		g.apaterno,						\n\
		g.amaterno,						\n\
		g.idpersona,						\n\
		calle    || 						\n\
		' '      ||						\n\
		numero   || 						\n\
		' '      ||						\n\
		colonia  ||						\n\
		' '	 ||						\n\
		cp   as direccion,					\n\
		b.telefono,						\n\
		c.correo,						\n\
		f.nombre as escuela,					\n\
		f.idescuela 						\n\
	 from personaNormalizada as a left outer join 			\n\
	      personas as g using(idpersona)  left outer join		\n\
	      telefonos as b using(idpersona) left outer join		\n\
	      correos as c using(idpersona) left outer join		\n\
	      direcciones as d using(idpersona) left outer join		\n\
	      alumnoescuela as e using(idpersona) left outer join	\n\
	      escuelas as f using(idescuela)				\n\
	 where a.nombre like '%%%s%%' and 				\n\
	       a.apaterno like '%%%s%%' ",
	 lchrPtrNombre,
	 lchrPtrAPaterno);
SiscomActualizaCampoAsignaMemoria2("Sql",lchrArrSql,lSiscomRegProLPtrConsultaPrim);
SiscomAgregaArgumentoOperacion("ConsultaSql",
				lSiscomRegProLPtrConsultaPrim,
				lSiscomRegProLPtrConsultaAct,
				pSiscomOpePtrDato);
return 1;
}
else
return 0;
}


void FormandoClienteRegistrado(SiscomRegistroProL *pSiscomRegProLPtrPersona,
			       SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrDato=0;
if((lSiscomRegProLPtrDato=FormaRespuestaClienteRegistrado(1,
				pSiscomRegProLPtrPersona,
				pSiscomOpePtrDato)))
{
 SiscomAgregaCampoRegistro("Registrado","1",lSiscomRegProLPtrDato);
 pSiscomOpePtrDato->SiscomRegProLPtrPrimRes=lSiscomRegProLPtrDato;
}

}
/* Ciudad de Mexico 20 De Febrero 2017
 * Si el cliente se envio con todos los datos 
 * y no encontro la informacion 
 * Regresa 0 
 * Si encontro los datos regresa  1
 * Si no vienen los datos completos regresa -1
 */
int BuscandoClienteCompleto(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrCliente;
  if(BuscaClienteCompleto(pSiscomOpePtrDato))
  {
   SqlBuscandoClienteRegistrado(pSiscomOpePtrDato);
   lSiscomRegProLPtrCliente=SiscomObtenRegistrosCampoRespuesta("SqlPersona",pSiscomOpePtrDato);
   return lSiscomRegProLPtrCliente ? 1 : 0;
 }
 else
 return 0;
}
void CopiaSiscomOperacionesBaseDatos(SiscomOperaciones *pSisOpePtrEntrada,
			             SiscomOperaciones *pSisOpePtrSalida)
{
strcpy(pSisOpePtrSalida->chrArrBaseDatos,pSisOpePtrEntrada->chrArrBaseDatos);
strcpy(pSisOpePtrSalida->chrArrPuertoBaseDatos,pSisOpePtrEntrada->chrArrPuertoBaseDatos);
strcpy(pSisOpePtrSalida->chrArrDirIpSvrAccesoDatos,pSisOpePtrEntrada->chrArrDirIpSvrAccesoDatos);
pSisOpePtrSalida->intPuertoSvrAccesoDatos=pSisOpePtrEntrada->intPuertoSvrAccesoDatos;
}
void CompletandoDatosPersona(SiscomRegistroProL *pSisRegProLPtrCliente,
			     SiscomOperaciones *pSisOpePtrDato)
{
const char *lchrPtrIdPersona;
SiscomOperaciones lSisOpeReg;
char lchrArrBuffer[512];
memset(&lSisOpeReg,0,sizeof(SiscomOperaciones));
CopiaSiscomOperacionesBaseDatos(pSisOpePtrDato,&lSisOpeReg);
for(; pSisRegProLPtrCliente;pSisRegProLPtrCliente=pSisRegProLPtrCliente->SiscomRegProLPtrSig)
{
  lchrPtrIdPersona=SiscomObtenCampoRegistroProLChar("idpersona",pSisRegProLPtrCliente);
  SqlCompletaDatosPersona(lchrPtrIdPersona,&lSisOpeReg);
  SiscomRegistrosAlCampo("direcciones",
  			 SiscomObtenRegistrosCampoRespuesta("Direcciones",&lSisOpeReg),
			 0,
			 pSisRegProLPtrCliente);
  SiscomRegistrosAlCampo("telefonos",
  			 SiscomObtenRegistrosCampoRespuesta("Telefonos",&lSisOpeReg),
			 0,
			 pSisRegProLPtrCliente);
  SiscomRegistrosAlCampo("correos",
  			 SiscomObtenRegistrosCampoRespuesta("Correos",&lSisOpeReg),
			 0,
			 pSisRegProLPtrCliente);

SiscomRegistroProtocoloLog(lchrArrBuffer,SiscomObtenRegistrosCampoRespuesta("Telefonos",&lSisOpeReg));


}
}
/* Ciudad de Mexico 20 de Febrero del 2017 
 * Si se ejecuto la busqueda 
 * y encontro similares regresa 1 
 * si se ejecuto la consulta y no hay coincidencias regreso 0
 * Regresa -1 si no se ejecuto la consulta
 */
int BuscaClientesPorNombre(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
SiscomRegistroProL *lSiscomRegProLPtrCliente;
if(ClientesPorNombre(pSiscomOpePtrDato))
{
SqlBuscandoClienteRegistrado(pSiscomOpePtrDato);
lSiscomRegProLPtrCliente=SiscomObtenRegistrosCampoRespuesta("SqlPersona",pSiscomOpePtrDato);
if(lSiscomRegProLPtrCliente)
{
CompletandoDatosPersona(lSiscomRegProLPtrCliente,pSiscomOpePtrDato);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrCliente);
return lSiscomRegProLPtrCliente->intNRegistros;
}
else
{
  LogSiscom("Nombre no registrado ");
  return 0;
}
}
else
return 0;
}
/* CDMx 15 Diciembre 2017 
 * Se agrega la busqueda incluyendo nombre y un apellido,
 * se ha observado que para el caso en el que se busca 
 * por un nombre comun, que esta registrado mas de una 
 * vez se complica seleccionar el cliente, por lo que 
 * se agrega al nombre el apellido paterno 
 */

/* Siscom Zacatenco 
 * Sabado 23 Diciembre del 2023 
 *
 * Arreglando la funcionalidad , no detecta de forma correcta cuando llegan
 * nombre y apellido paterno
 */
int BuscaClientesPorNombreAPaterno(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrCliente;
if(ClientesPorNombreAPaterno(pSiscomOpePtrDato))
{
SqlBuscandoClienteRegistrado(pSiscomOpePtrDato);
lSiscomRegProLPtrCliente=SiscomObtenRegistrosCampoRespuesta("SqlPersona",pSiscomOpePtrDato);
return lSiscomRegProLPtrCliente->intNRegistros;
}
else
return 0;
}


int BuscandoAlCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
/*{
int lintRegresando;
   if((lintRegresando=BuscandoClienteCompleto(pSiscomOpePtrDato))==1)
   	return 1;
   else
   if(lintRegresando==0)
       return 0;		
   else
   if(lintRegresando==-1)
   {
	LogSiscom("NO Llego cliente completo");
        if((lintRegresando=BuscaClientesPorNombre(pSiscomOpePtrDato))==1)
	return 2;
	else
	if((lintRegresando=BuscaClientesPorNombreAPaterno(pSiscomOpePtrDato))==0)
	  return 3; 
	else
	if(lintRegresando==1)
	return 0;
	else
	{
	return -1;
	}
	LogSiscom("Los Datos %d",lintRegresando);
   }
}*/
int lintRegresando;
   if(BuscandoClienteCompleto(pSiscomOpePtrDato))
   return 1;
   /*  Siscom Zacatenco ..... 
    *  Sabado 23 de diciembre del 2023 
    *  La que iba a ser mi gran noche .........
    *  lo mejor es que existe la programacion 
    *
    *  Si hay mas de una coincidencia en en el nombre 
    *  regreso 4, si hay solo una coincidencia regreso 1
    *
    */
   if((lintRegresando=BuscaClientesPorNombre(pSiscomOpePtrDato))!=0)
    return lintRegresando > 1  ? 4 : 1; 
   else
   if((lintRegresando=BuscaClientesPorNombreAPaterno(pSiscomOpePtrDato))!=0)
    return lintRegresando > 1  ? 4 : 1; 
    else
    return 0;
}
void ConsultandoClienteRegistrado(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrCliente;
    LogSiscom("Cliente Registrado...");
    
if((lSiscomRegProLPtrCliente=SiscomObtenRegistrosCampoRespuesta("SqlPersona",
  				pSiscomOpePtrDato)))
{ 
    SqlDatosFisicaRegistrada(lSiscomRegProLPtrCliente,pSiscomOpePtrDato);
    FormandoClienteRegistrado(lSiscomRegProLPtrCliente,pSiscomOpePtrDato);
}
}

/* Tepotzotlan Jueves 21 diciembre del 2017 
 * En la interfaz de registro de cliente para pedido, se tiene
 * la funcionalidad de solo capturar el nombre, o apellido paterno
 * para ver si hay alguna coincidencia, en el caso de que no se 
 * encuentre, el sistema registraba el nombre, con los datos nulos
 * por lo que se integra esta funcionalidad para diferenciar 
 * en el proceso que no hay ningun nombre en la base de datos 
 * que coincida con el introducido.
 */
int SeBuscoPorNombre(SiscomOperaciones *pSiscomOpePtrDato)
{

return (SiscomCampoAsociadoEntradaOperacion("Envio","Nombre",pSiscomOpePtrDato) 	&&
        !SiscomCampoAsociadoEntradaOperacion("Envio","APaterno",pSiscomOpePtrDato) 	&&
        !SiscomCampoAsociadoEntradaOperacion("Envio","AMaterno",pSiscomOpePtrDato));
}
int ClienteRegistrado(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[4192]; 
int lintBuscandoCliente;

  SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);

 /*
  if((lintBuscandoCliente=BuscandoAlCliente(pSiscomOpePtrDato))==1)
  {
    ConsultandoClienteRegistrado(pSiscomOpePtrDato);
    return 1;
  }
  else
  if(lintBuscandoCliente==2)
    return 2;
  else
  if(lintBuscandoCliente==0)
  {
   LogSiscom("Ya se capturaron los datos completos, se continua con el registro");
   return 0;
  }
   else
   {
   LogSiscom("Cliente No Registrado %d ",lintBuscandoCliente);
   ArmaRespuestaNombreNoCoincide(pSiscomOpePtrDato);
   return 3;
   }
 */
  if((lintBuscandoCliente=BuscandoAlCliente(pSiscomOpePtrDato))==1)
  {
   LogSiscom("El Cliente ya esta ....");
   LogSiscom("lo consulto .... ....");
   ConsultandoClienteRegistrado(pSiscomOpePtrDato);
   return 1;
  }
  else
  if(lintBuscandoCliente==4)
  return 2;
  else
  if(lintBuscandoCliente==1)
  return 1;


return 0;
}
void ArmaRespuestaNombreNoCoincide(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
/* Tepotzotlan Mexico a 21 de Diciembre 2017
 * Si se envio un nombre para el cual no se tiene coincidencia
 * en la base de datos, se realiza el proceso de registro 
 * para un cliente nuevo
 */
pSiscomOpePtrDato->SiscomRegProLPtrPrimRes=0;
pSiscomOpePtrDato->SiscomRegProLPtrActRes=0;

SiscomAnexaRegistroPro(&pSiscomOpePtrDato->SiscomRegProLPtrPrimRes,
		       &pSiscomOpePtrDato->SiscomRegProLPtrActRes,
		       lchrArrBuffer,
		       "Mensaje,Registrado,",
		       "Nombre NO Coincide en la base",
		       "3");

}
int ElClienteYaSeRegistro(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
}
int NombreNoCoincide(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);

}
int BuscandoAUnClienteEnLaBase(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[4192];
LogSiscom("-----");
SiscomRegistroProL *lSiscomRegProLPtrRegPrim=0,
		   *lSiscomRegProLPtrRegAct=0,
		   *lSiscomRegProLPtrClientes=0;
SiscomAnexaRegistroPro(&lSiscomRegProLPtrRegPrim,
		       &lSiscomRegProLPtrRegAct,
		       lchrArrBuffer,
		       "Registrado,Clientes,",
		       "2",
		       (const char *)0);
lSiscomRegProLPtrClientes=SiscomObtenRegistrosCampoRespuesta("SqlPersona",pSiscomOpePtrDato);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrClientes);
SiscomRegistrosAlCampo("Clientes",
			lSiscomRegProLPtrClientes,
			lSiscomRegProLPtrClientes,
			lSiscomRegProLPtrRegPrim);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrRegPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrRegPrim);
return 0;
}
int EnviaDireccionEscuela(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomEnviaAsociadoRespuestaCliente("SqlDirecciones",lchrArrBuffer,pSiscomOpePtrDato);
}


void ConsultasInformacionPersona(SiscomOperaciones *pSiscomOpePtrDato,
				 char *pchrPtrSqlDirecciones,
				 char *pchrPtrSqlCorreos,
				 char *pchrPtrSqlTelefonos)
{

const char *lchrPtrIdPersona=SiscomCampoAsociadoEntradaOperacion("Envio","IdPersona",pSiscomOpePtrDato);
sprintf(pchrPtrSqlDirecciones,
	"select * 		\n\
	 from direcciones 	\n\
	 where idpersona=%s",
	 lchrPtrIdPersona);

sprintf(pchrPtrSqlCorreos,
	"select *		\n\
	 from correos		\n\
	 where idpersona=%s",
	 lchrPtrIdPersona);
sprintf(pchrPtrSqlTelefonos,
	"select * 		\n\
	from telefonos		\n\
	where idpersona=%s",
	lchrPtrIdPersona);
}


int IdPersonaANormalizada(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrDatos,
		   *lSisRegProLPtrNormalizado;
char *lchrPtrIdPersona;

if((lSisRegProLPtrDatos=SiscomObtenRegistrosCampoEntrada("Envio",pSisOpePtrDato)) &&
   (lSisRegProLPtrNormalizado=SiscomObtenArgumentoPrimOperaciones("Normalizado",pSisOpePtrDato)))
{
while(lSisRegProLPtrDatos)
{
lchrPtrIdPersona=(char *)SiscomObtenCampoRegistroProLChar("IdPersona",lSisRegProLPtrDatos);
SiscomActualizaCampoAsignaMemoriaRegistro("IdPersona",	
					  lchrPtrIdPersona,
					  lSisRegProLPtrNormalizado);
lSisRegProLPtrNormalizado=lSisRegProLPtrNormalizado->SiscomRegProLPtrSig;
lSisRegProLPtrDatos=lSisRegProLPtrDatos->SiscomRegProLPtrSig;
}
}

return 0;
}

/*  Ciudad de Mexico a 23 de Junio del 2022 
 * Primer semestre post pandemia casi normal , sobre todo en Zacatenco :) :)
 *
 *  Toma como entrada los nombres de los campos del Asociado de entrada , en 
 *  del que se normalizaran las cadenas, se crea un registro asociado de salida
 *  para dejar las cadenas normalizadas
 */
void SiscomNormalizaCadenas(char **pchrPtrCampos,
			   const char *pchrPtrAsoEntrada,
			   const char *pchrPtrArgNormalizado,
			   SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrEnt,
		   *lSisRegProLPtrPrimSal=0,
		   *lSisRegProLPtrActSal=0;
if((lSisRegProLPtrEnt=SiscomObtenRegistrosCampoEntrada(pchrPtrAsoEntrada,pSiscomOpePtrDato)))
{
   for( ;lSisRegProLPtrEnt;lSisRegProLPtrEnt=lSisRegProLPtrEnt->SiscomRegProLPtrSig)
     SiscomNormalizaCamposPro2(pchrPtrCampos,
     				lSisRegProLPtrEnt,
				&lSisRegProLPtrPrimSal,
				&lSisRegProLPtrActSal);
SiscomAgregaArgumentoOperacion(pchrPtrArgNormalizado,
				lSisRegProLPtrPrimSal,
				lSisRegProLPtrActSal,
				pSiscomOpePtrDato);
}
}
void SiscomNormalizaCamposPro2(char **pchrPtrCampos,
			       SiscomRegistroProL *pSisRegProLPtrDato,
			       SiscomRegistroProL **pSisRegProLPtrPrim,
			       SiscomRegistroProL **pSisRegProLPtrAct)
{
SiscomRegistroProL *lSisRegProLPtrActSal=0;
unsigned char *lchrPtrNormalizado;
const char *lchrPtrCampo;
SiscomCampoProL *lSisCamProLPtrPrim=0,
		*lSisCamProLPtrAct=0;
  for(;*pchrPtrCampos;pchrPtrCampos++)
  {
    if((lchrPtrCampo=SiscomObtenCampoRegistroProLChar(*pchrPtrCampos,pSisRegProLPtrDato)))    
    {
    SiscomNormaliza2(lchrPtrCampo, SiscomCaracteresCambiados(),&lchrPtrNormalizado);
    SiscomNodoCampoPro2(*pchrPtrCampos,
    			lchrPtrNormalizado,
			&lSisCamProLPtrPrim,
			&lSisCamProLPtrAct);
    }
    else
    SiscomNodoCampoPro2(*pchrPtrCampos,
    			(const  char *)0,
			&lSisCamProLPtrPrim,
			&lSisCamProLPtrAct);

  }
SiscomNodoRegistroPro(lSisCamProLPtrPrim,pSisRegProLPtrPrim,pSisRegProLPtrAct);
}
/*  CDMX , Junio del 2022, primer semestre sin mucha pandemia, si con los efectos
 *  esperemos que la 5 ola , no haga estragos de nuevo  
 *
 * Toma el pchrPtreArgumento de pSisOpePtrDato, y agrega a todos los registros 
 * el campo pchrPtrCampo, el campo se inicializa a null
 */
void SiscomAgregaCampoArgumento(const char *pchrPtrCampo,
				const char *pchrPtrArg,
				SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrPrim;
if((lSisRegProLPtrPrim=SiscomObtenArgumentoPrimOperaciones(pchrPtrArg,pSisOpePtrDato)))
  SiscomAgregaCampoRegistros(pchrPtrCampo,(const char *)0,lSisRegProLPtrPrim);
else
LogSiscom("NO Esta el argumento %s",pchrPtrArg);

}
int NormalizaPersona(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
char *lchrPtrNombres[]={"Nombre","APaterno","AMaterno",0};
LogSiscom("Normalizando Persona");
SiscomNormalizaCadenas(lchrPtrNombres,"Envio","Normalizado",pSiscomOpePtrDato);
SiscomAgregaCampoArgumento("IdPersona","Normalizado",pSiscomOpePtrDato);
/*
SiscomArgumentoLog("Normalizado",lchrArrBuffer,pSiscomOpePtrDato); 
*/
return 0;
}
