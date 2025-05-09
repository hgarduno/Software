#include <SiscomOperaciones.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomFuncionesComunes.h>
#include <SiscomInsercionesSql.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
/*

void SiscomAgrupaConsultaSistema(int pintDatosOrdenados,
				 const char *pchrPtrCampo,  
				 const char *pchrPtrArgRegServsSistema,
				 const char *pchrPtrArgRegCampoServsSistema,
				 const char *pchrPtrCampoSistema,
				 const char *pchrPtrCampoRespConsulta,
				char *pchrPtrNombreAsociado,
				char **pchrPtrCamposRegistroAgrupado,
				char **pchrPtrCamposRegistro,
				const char *pchrPtrArgSalida,
				SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrCampoSistema;
int lintNRegistros=0;
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrExpendios,
		   *lSiscomRegProLPtrConsulta;
SiscomRegistroProL *lSiscomRegProLPtrRegreso=0,
		  *lSiscomRegProLPtrUltimoProducto,
		  *lSiscomRegProLPtrAgrupadoPrim=0,
		  *lSiscomRegProLPtrAgrupadoAct=0;
SiscomRegistroProL *lSiscomRegProLPtrDatosOrdenadosPrim=0,
		   *lSiscomRegProLPtrDatosOrdenadosAct=0,
		   *lSiscomRegProLPtrEnvio;
lSiscomRegProLPtrExpendios=SiscomObtenArgumentoPrimAsociadoOperaciones(
				pchrPtrArgRegServsSistema,
				pchrPtrArgRegCampoServsSistema,
				pSiscomOpePtrDato);

for(;
    lSiscomRegProLPtrExpendios;
    lSiscomRegProLPtrExpendios=lSiscomRegProLPtrExpendios->SiscomRegProLPtrSig)
{
     lchrPtrCampoSistema=SiscomObtenCampoRegistroProLChar(pchrPtrCampoSistema,
     							lSiscomRegProLPtrExpendios);
     lSiscomRegProLPtrConsulta=SiscomRegistrosMaquinaConsulta(lchrPtrCampoSistema,
     							  pchrPtrCampoRespConsulta,
							  pSiscomOpePtrDato);
     lintNRegistros+=lSiscomRegProLPtrConsulta->intNRegistros;
     if(!lSiscomRegProLPtrRegreso)
      lSiscomRegProLPtrRegreso=lSiscomRegProLPtrConsulta;
      else
      {
      lSiscomRegProLPtrUltimoProducto=SiscomUltimoNodoLista(lSiscomRegProLPtrRegreso);
      lSiscomRegProLPtrUltimoProducto->SiscomRegProLPtrSig=lSiscomRegProLPtrConsulta;
      }

}
lSiscomRegProLPtrRegreso->intNRegistros=lintNRegistros;
if(!pintDatosOrdenados &&
    lSiscomRegProLPtrRegreso->intNRegistros>1)
{
 SiscomOrdenaRegistroProL(pchrPtrCampo,
 			  lSiscomRegProLPtrRegreso,
			  &lSiscomRegProLPtrDatosOrdenadosPrim,
			  &lSiscomRegProLPtrDatosOrdenadosAct);
lSiscomRegProLPtrEnvio=lSiscomRegProLPtrDatosOrdenadosPrim;
}
else
lSiscomRegProLPtrEnvio=lSiscomRegProLPtrRegreso;
SiscomAgrupaPorCampo(pchrPtrCampo,
		     pchrPtrNombreAsociado,
		     pchrPtrCamposRegistroAgrupado,
		     pchrPtrCamposRegistro,
		     lSiscomRegProLPtrEnvio,
		     &lSiscomRegProLPtrAgrupadoPrim,
		     &lSiscomRegProLPtrAgrupadoAct);
SiscomAgregaArgumentoOperacion(pchrPtrArgSalida,
				lSiscomRegProLPtrAgrupadoPrim,
				lSiscomRegProLPtrAgrupadoAct,
				pSiscomOpePtrDato);
}
*/
void SiscomAgregaArgumento(const char *pchrPtrNombre,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct,
			   SiscomArgumento **pSiscomArgPtrDato)
{
int lintNArgumento=0;
if(!*pSiscomArgPtrDato)
lintNArgumento=0;
if(!*pSiscomArgPtrDato)
{
(*pSiscomArgPtrDato)=(SiscomArgumento *)malloc(sizeof(SiscomArgumento)*2);
strcpy((*pSiscomArgPtrDato)->chrArrNombre,pchrPtrNombre);
(*pSiscomArgPtrDato)->SiscomRegProLPtrPrim=pSiscomRegProLPtrPrim;
(*pSiscomArgPtrDato)->SiscomRegProLPtrAct=pSiscomRegProLPtrAct;
(*pSiscomArgPtrDato)->intArgumentos=1;
}
else
{
lintNArgumento=(*pSiscomArgPtrDato)->intArgumentos;

(*pSiscomArgPtrDato)=(SiscomArgumento *)realloc(*pSiscomArgPtrDato,
						sizeof(SiscomArgumento)*(lintNArgumento+1));
strcpy(((*pSiscomArgPtrDato)+lintNArgumento)->chrArrNombre,pchrPtrNombre);
((*pSiscomArgPtrDato)+lintNArgumento)->SiscomRegProLPtrPrim=pSiscomRegProLPtrPrim;
((*pSiscomArgPtrDato)+lintNArgumento)->SiscomRegProLPtrAct=pSiscomRegProLPtrAct;
(*pSiscomArgPtrDato)->intArgumentos++;
}

}
const SiscomArgumento *SiscomObtenArgumento(const char *pchrPtrArgumento,
			  const SiscomArgumento *pSiscomArgPtrDat)
{
int lintContador,
    lintNArgumentos=pSiscomArgPtrDat->intArgumentos;
for(lintContador=0;lintContador<lintNArgumentos;lintContador++)
{
 if(!strcmp(pchrPtrArgumento,(pSiscomArgPtrDat+lintContador)->chrArrNombre))
    return (pSiscomArgPtrDat+lintContador);
}
return 0;
}
int SiscomObtenDatosArgumento(const char *pchrPtrArgumento,
			       const SiscomArgumento *pSiscomArgPtrDat,
			       SiscomRegistroProL **pSiscomRegProLPtrPrim,
			       SiscomRegistroProL **pSiscomRegProLPtrAct)
{
const SiscomArgumento *lSiscomArgPtrDat;
if((lSiscomArgPtrDat=SiscomObtenArgumento(pchrPtrArgumento,
					  pSiscomArgPtrDat)))
{
 *pSiscomRegProLPtrPrim=pSiscomArgPtrDat->SiscomRegProLPtrPrim;
 *pSiscomRegProLPtrAct=pSiscomArgPtrDat->SiscomRegProLPtrAct;
 return 1;
}
return 0;
}

void SiscomAgregaArgumentoOperacion(const char *pchrPtrNombre,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct,
			   SiscomOperaciones *pSiscomOpePtrDat)
{
SiscomAgregaArgumento(pchrPtrNombre,
		      pSiscomRegProLPtrPrim,
		      pSiscomRegProLPtrAct,
		      &pSiscomOpePtrDat->SiscomArgPtrDatos);
}

void SiscomIniciaDatosOperacion(int pintSocket,
				void *pvidPtrAncla,
				SiscomRegistroProL *pSiscomRegProLPtrPrim,
				SiscomRegistroProL *pSiscomRegProLPtrAct,
				SiscomOperaciones *pSiscomOpePtrDat)
{
pSiscomOpePtrDat->SiscomRegProLPtrPrimEnt=pSiscomRegProLPtrPrim;
pSiscomOpePtrDat->SiscomRegProLPtrActEnt=pSiscomRegProLPtrAct;
pSiscomOpePtrDat->intSocket=pintSocket;
pSiscomOpePtrDat->vidPtrAncla=pvidPtrAncla;
}

void SiscomAgregaOperacion(SiscomOperacion pSiscomOpePtrDat,
			   SiscomProcesos **pSiscomProPtrDat)
{
int lintNProcesos;
if(!*pSiscomProPtrDat)
{
   *pSiscomProPtrDat=(SiscomProcesos *)malloc(sizeof(SiscomProcesos));
   (*pSiscomProPtrDat)->intProcesos=1;
   (*pSiscomProPtrDat)->SiscomOpePtrProcesos=pSiscomOpePtrDat;
}
else
{
lintNProcesos=(*pSiscomProPtrDat)->intProcesos;
  *pSiscomProPtrDat=(SiscomProcesos *)realloc(
  					*pSiscomProPtrDat,
  					sizeof(SiscomProcesos)*(lintNProcesos+1));
  ((*pSiscomProPtrDat)+lintNProcesos)->SiscomOpePtrProcesos=pSiscomOpePtrDat;
  (*pSiscomProPtrDat)->intProcesos=++lintNProcesos;
}
}
/* Miercoles 9 de Mayo del 2012 
 * Para invocar de forma correcta esta funcion, se requiere colocar 
 * de forma manual el 0 en pSiscomProPtrDat->SiscomOpePtrProcesos 
 * para lo que se debera agregar una llamada a 
 * SiscomAgregaOperacion(0,&lSiscomProDat);
 */
void SiscomEjecutaProcesos(SiscomOperaciones *pSiscomOpePtrDat,
			   SiscomOperacionErrores pSiscomOpeErrores,
			   SiscomProcesos *pSiscomProPtrDat)
{

   while(pSiscomProPtrDat->SiscomOpePtrProcesos) 
   {
     if((pSiscomProPtrDat->intCodigoRetorno=pSiscomProPtrDat->SiscomOpePtrProcesos(pSiscomOpePtrDat)))
     {
         if(pSiscomOpeErrores &&
	    pSiscomOpeErrores[pSiscomProPtrDat->intCodigoRetorno])
	 {
	   pSiscomOpeErrores[pSiscomProPtrDat->intCodigoRetorno](pSiscomOpePtrDat);
	   break;
	 }
     }
     pSiscomProPtrDat++;
   }
}
void SiscomEnviaConsultaSqlAsignaArgumento(const char *pchrPtrDirIpSvr,
					   const char *pchrPtrBaseDatos,
					   const char *pchrPtrPuertoBaseDatos,
					   const char *pchrPtrSql,
					   const char *pchrPtrArgumento,
					   char *pchrPtrBuffer,
					   int pintPuertoSvr,
					   SiscomOperaciones *pSiscomOpePtrDatos)
{
char *lchrPtrEdoConexion;
SiscomArgumento *lSisArgPtrDato;
char lchrArrNombreConsulta[256];
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
 		   *lSiscomRegProLPtrAct=0,
		   *lSiscomRegProLPtrPrimReg=0,
		   *lSiscomRegProLPtrActReg=0,
		   *lSiscomRegProLPtrPrimArg,
		   *lSiscomRegProLPtrActArg;
		
sprintf(lchrArrNombreConsulta,"%s,",pchrPtrArgumento);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       "BaseDatos,"
		       "PuertoBaseDatos,"
		       "Operacion,",
		       pchrPtrBaseDatos,
		       pchrPtrPuertoBaseDatos,
		       "EjecutaConsulta");
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       lchrArrNombreConsulta,
		       (char *)0);
SiscomAnexaRegistrosAlCampo(pchrPtrArgumento,
			    lSiscomRegProLPtrAct,
			    pchrPtrBuffer,
			    "Sql,",
			    pchrPtrSql);
if((pSiscomOpePtrDatos->intSocketAD=SiscomConectateCliente(pchrPtrDirIpSvr,
				      pintPuertoSvr,
				      &lchrPtrEdoConexion))>0)
{
SiscomEnviaRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			   pchrPtrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomLeeRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			 pchrPtrBuffer,
			 &lSiscomRegProLPtrPrimReg,
			 &lSiscomRegProLPtrActReg);
/*
SiscomRegistrosAsociadosLog(pchrPtrBuffer,
			    pchrPtrArgumento,
			    lSiscomRegProLPtrActReg);
*/
/* Ciudad de Mexico Miercoles 21 de Diciembre del 2016 
 * Esta funcion, regresaba en un Registro Asociado pchrPtrArgumento, el 
 * resultado de la consulta pchrPtrArgumento, por lo que para llegar a los 
 * datos de la consulta se debia, primero obtener el Registro de respuesta 
 * pchrPtrArgumento, y despues los asociados de ese mismo nombre :(, ahora 
 * se asigna directo al argumento los registros asociados del regreso 
 */
lSiscomRegProLPtrPrimArg=SiscomObtenRegistrosCampoProL(pchrPtrArgumento,lSiscomRegProLPtrActReg);
SiscomAsignaRegistrosArgumentoOperaciones(lSiscomRegProLPtrPrimArg,
					  lSiscomRegProLPtrPrimArg,
					  pchrPtrArgumento,
					  pSiscomOpePtrDatos);
}
}


void SiscomEnviaConsultaSqlAsignaArgumento2(const char *pchrPtrDirIpSvr,
					   const char *pchrPtrBaseDatos,
					   const char *pchrPtrPuertoBaseDatos,
					   const char *pchrPtrServidorBD,
					   const char *pchrPtrUsuarioBD,
					   const char *pchrPtrPasswordBD, 
					   const char *pchrPtrSql,
					   const char *pchrPtrArgumento,
					   char *pchrPtrBuffer,
					   int pintPuertoSvr,
					   SiscomOperaciones *pSiscomOpePtrDatos)
{
char *lchrPtrEdoConexion;
SiscomArgumento *lSisArgPtrDato;
char lchrArrNombreConsulta[256];
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
 		   *lSiscomRegProLPtrAct=0,
		   *lSiscomRegProLPtrPrimReg=0,
		   *lSiscomRegProLPtrActReg=0,
		   *lSiscomRegProLPtrPrimArg,
		   *lSiscomRegProLPtrActArg;
		
sprintf(lchrArrNombreConsulta,"%s,",pchrPtrArgumento);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       "BaseDatos,"
		       "PuertoBaseDatos,"
		       "ServidorBaseDatos,"
		       "UsuarioBaseDatos,"
		       "PasswordBaseDatos,"
		       "Operacion,",
		       pchrPtrBaseDatos,
		       pchrPtrPuertoBaseDatos,
		       pchrPtrServidorBD,
		       pchrPtrUsuarioBD,
		       pchrPtrPasswordBD,
		       "EjecutaConsulta");
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       lchrArrNombreConsulta,
		       (char *)0);

SiscomAnexaRegistrosAlCampo(pchrPtrArgumento,
			    lSiscomRegProLPtrAct,
			    pchrPtrBuffer,
			    "Sql,",
			    pchrPtrSql);
if((pSiscomOpePtrDatos->intSocketAD=SiscomConectateCliente(pchrPtrDirIpSvr,
				      pintPuertoSvr,
				      &lchrPtrEdoConexion))>0)
{
SiscomEnviaRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			   pchrPtrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomLeeRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			 pchrPtrBuffer,
			 &lSiscomRegProLPtrPrimReg,
			 &lSiscomRegProLPtrActReg);
/*
SiscomRegistrosAsociadosLog(pchrPtrBuffer,
			    pchrPtrArgumento,
			    lSiscomRegProLPtrActReg);
*/
/* Ciudad de Mexico Miercoles 21 de Diciembre del 2016 
 * Esta funcion, regresaba en un Registro Asociado pchrPtrArgumento, el 
 * resultado de la consulta pchrPtrArgumento, por lo que para llegar a los 
 * datos de la consulta se debia, primero obtener el Registro de respuesta 
 * pchrPtrArgumento, y despues los asociados de ese mismo nombre :(, ahora 
 * se asigna directo al argumento los registros asociados del regreso 
 */
lSiscomRegProLPtrPrimArg=SiscomObtenRegistrosCampoProL(pchrPtrArgumento,lSiscomRegProLPtrActReg);
SiscomAsignaRegistrosArgumentoOperaciones(lSiscomRegProLPtrPrimArg,
					  lSiscomRegProLPtrPrimArg,
					  pchrPtrArgumento,
					  pSiscomOpePtrDatos);
}
}

/*
int SiscomEjecutaConsultaSql(const char *pchrPtrSql,
			     const char *pchrPtrNmbConsulta,
			     char *pchrPtrBuffer,
			     SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomCampoProL *lSiscomCamProLPtrDato=0,
		*lSiscomCamProLPtrDatoAct=0,
	 	*lSiscomCamProLPtrPaso,
		*lSiscomCamProLPtrCampo=0;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;

char *lchrPtrSql;
char *lchrPtrEdoConexion;
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       "BaseDatos,"
		       "PuertoBaseDatos,"
		       "Operacion,"
		       "EstadoOperacion,",
		       pSiscomOpePtrDatos->chrArrBaseDatos,
		       pSiscomOpePtrDatos->chrArrPuertoBaseDatos,
		       "EjecutaConsulta",
		       (const char *)0);

SiscomNodoCampoPro(pchrPtrNmbConsulta,
                   pchrPtrSql,
                   &lSiscomCamProLPtrDato,
                   &lSiscomCamProLPtrDatoAct);
SiscomNodoRegistroPro(lSiscomCamProLPtrPaso,
		      &lSiscomRegProLPtrPrim,
		      &lSiscomRegProLPtrAct);


  SiscomAnexaRegistrosAlCampo(pchrPtrNmbConsulta,
  			      lSiscomRegProLPtrAct,
			      pchrPtrBuffer,
			      "Sql,",
			      pchrPtrSql);


if((pSiscomOpePtrDatos->intSocketAD=SiscomConectateCliente(
				pSiscomOpePtrDatos->chrArrDirIpSvrAccesoDatos,
				pSiscomOpePtrDatos->intPuertoSvrAccesoDatos,
				&lchrPtrEdoConexion))>0)
{
SiscomEnviaRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			   pchrPtrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomLeeRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			 pchrPtrBuffer,
			 &pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes,
			 &pSiscomOpePtrDatos->SiscomRegProLPtrActRes);
}


}

*/

void SiscomConsultaSqlAArgumentoOperaciones(const char *pchrPtrSql,
					    const char *pchrPtrArgumento,
					    char *pchrPtrBuffer,
					    SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomEnviaConsultaSqlAsignaArgumento(
	pSiscomOpePtrDatos->chrArrDirIpSvrAccesoDatos,
	pSiscomOpePtrDatos->chrArrBaseDatos,
	pSiscomOpePtrDatos->chrArrPuertoBaseDatos,
	pchrPtrSql,
	pchrPtrArgumento,
	pchrPtrBuffer,
	pSiscomOpePtrDatos->intPuertoSvrAccesoDatos,
	pSiscomOpePtrDatos);
}


/* Lunes 14 de Mayo del 2012 
 * En las funciones que se ejecutan en modo GestionEstatica del servidor
 * la funcion que se ejecutara sera de acuerdo a la configuracion del 
 * archivo ini. Las funciones se configuraran en la variable FuncionGestionEstatica
 * y se debera declarar como arreglo, por ejemplo para el caso de las consultas
 * a la base de datos, y de acuerdo a lo configurado en el ejemplo del 
 * servidor corriendo en modo GestionEstatica del directorio PruebasSiscomDesarrollo4
 * SiscomElectronica5046Ini, podemos observar que la funcion EjecutaOperacion
 * que el servidor de reglas de negocio que se utilizan en las funciones 
 * para accesar a la base de datos de esta seccion, seran resultas por la 
 * funcion SiscomOperacionBD. Ahora como el servidor se estara corriendo 
 * en modo gestion estatica al inicio del programa se cargaran las funciones 
 * de la bibliotaca liSiscomPostgresSql.so que tambien se indican en el ini.
 *
 * Esta operacion para el manejo de los accesos a la base de datos permitira 
 * cambiar el modulo libSiscomPostresSql.so y gestionar otra base de datos 
 *
 */
SiscomCampoProL *SiscomFormaCamposSql(const char *pchrPtrFormato,
				      char *pchrPtrBuffer)
{
char *lchrPtrBuffer=pchrPtrBuffer;
SiscomCampoProL *lSiscomCamProLPtrPrim=0,
		*lSiscomCamProLPtrAct=0;
     while(*pchrPtrFormato)
     {
 	if(*pchrPtrFormato=='%')
	{
	   *pchrPtrBuffer=0;
	   pchrPtrBuffer=lchrPtrBuffer;
	   SiscomNodoCampoPro(lchrPtrBuffer,
	   		      0,
			      &lSiscomCamProLPtrPrim,
			      &lSiscomCamProLPtrAct);
	}
	else
	{
	*pchrPtrBuffer=*pchrPtrFormato;
	*pchrPtrBuffer++;
	}
	*pchrPtrFormato++;
     }
return lSiscomCamProLPtrPrim;

}

/* Jueves 10 Mayo del 2012 
 * Se requiere escribir una funcion para enviar un lote de consultas SQL
 * la cual debera regresarse como registros asociados a cada campo, el 
 * nombre del campo debera ser el nombre de un argumento que se generara 
 * de forma automatica para poder acceder a los registros de cada consulta
 *
 * Se debe agregar a la estructura de Operaciones los datos del servidor 
 * de acceso a datos, pero las funciones deben poder tomar de los parametros
 * esta informacion
 *
 * Se debera pasar en pchrPtrFormato la cadena de la siguiente forma:
 *
 * Donde la x sera asignado al nomnbre del campo 
 *          s sera la cadana Sql que se enviara
 * 
 * SiscomConsultasSql(pchrPtrBuffer,
 * 		      pchrPtrDirIp,
 * 		      int pintPuerto,
 * 		      pSiscomRegProLPtrPrim,
 * 		      pSiscomRegProLPtrAct,
 * 		      "Direcciones%Telefonos%Usuarios%",
 * 		      "select * from direcciones",
 * 		      "select * from telefonos",
 * 		      "select * from usuarioss");
 *
 * Sabado 12 de Mayo del 2012 
 * Una vez que llega la informacion a las rutinas que accesan a la base
 * de datos la respuesta se debera formar mediante el nombre del campo
 * y el resultado ahora en lugar de las sentencia Sql para los registros
 * asociaciados seran los registros devueltos por la consulta de base 
 * de datos.
 *
 *
 */
void SiscomConsultasSql(char *pchrPtrBuffer,
			const char *pchrPtrDirIp,
			const char *pchrPtrBaseDatos,
			const char *pchrPtrPuertoBase,
			int pintPuerto,
			SiscomRegistroProL **pSiscomRegProLPtrRegPrim,
			SiscomRegistroProL **pSiscomRegProLPtrRegAct,
			int *pintPtrSocket,
			const char *pchrPtrFormato,
			...)
{
SiscomCampoProL *lSiscomCamProLPtrDato=0,
	 	*lSiscomCamProLPtrPaso,
		*lSiscomCamProLPtrCampo;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;

char *lchrPtrSql;
char *lchrPtrEdoConexion;
char lchrArrBuffer[256];
va_list lvaListInfo;
va_start(lvaListInfo,pchrPtrFormato);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       "BaseDatos,"
		       "PuertoBaseDatos,"
		       "Operacion,"
		       "EstadoOperacion,",
		       pchrPtrBaseDatos,
		       pchrPtrPuertoBase,
		       "EjecutaConsulta",
		       (char *)0);

lSiscomCamProLPtrPaso=lSiscomCamProLPtrDato=SiscomFormaCamposSql(
						pchrPtrFormato,
						pchrPtrBuffer);

SiscomNodoRegistroPro(lSiscomCamProLPtrPaso,
		      &lSiscomRegProLPtrPrim,
		      &lSiscomRegProLPtrAct);
SiscomRegistroProtocoloLog(pchrPtrBuffer,lSiscomRegProLPtrPrim);
while(lSiscomCamProLPtrDato)
{
  lchrPtrSql=va_arg(lvaListInfo,char *);
  SiscomAnexaRegistrosAlCampo(lSiscomCamProLPtrDato->chrPtrNmbCampo,
  			      lSiscomRegProLPtrAct,
			      pchrPtrBuffer,
			      "Sql,",
			      lchrPtrSql);
  lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
}
va_end(lvaListInfo);
if((*pintPtrSocket=SiscomConectateCliente(pchrPtrDirIp,
				          pintPuerto,
					  &lchrPtrEdoConexion))>0)
{
SiscomEnviaRegistrosSocket(*pintPtrSocket,
			   pchrPtrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomLeeRegistrosSocket(*pintPtrSocket,
			 pchrPtrBuffer,
			 pSiscomRegProLPtrRegPrim,
			 pSiscomRegProLPtrRegAct);
}
}


void SiscomConsultasSql2(char *pchrPtrBuffer,
			const char *pchrPtrDirIp,
			const char *pchrPtrBaseDatos,
			const char *pchrPtrPuertoBase,
			const char *pchrPtrServidorBD,
			const char *pchrPtrUsuario,
			const char *pchrPtrPassword,
			int pintPuerto,
			SiscomRegistroProL **pSiscomRegProLPtrRegPrim,
			SiscomRegistroProL **pSiscomRegProLPtrRegAct,
			int *pintPtrSocket,
			const char *pchrPtrFormato,
			...)
{
SiscomCampoProL *lSiscomCamProLPtrDato=0,
	 	*lSiscomCamProLPtrPaso,
		*lSiscomCamProLPtrCampo;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;

char *lchrPtrSql;
char *lchrPtrEdoConexion;
char lchrArrBuffer[256];
va_list lvaListInfo;
va_start(lvaListInfo,pchrPtrFormato);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       "BaseDatos,"
		       "PuertoBaseDatos,"
		       "ServidorBaseDatos,"
		       "UsuarioBaseDatos,"
		       "PasswordBaseDatos,"
		       "Operacion,"
		       "EstadoOperacion,",
		       pchrPtrBaseDatos,
		       pchrPtrPuertoBase,
		       pchrPtrServidorBD,
		       pchrPtrUsuario,
		       pchrPtrPassword,
		       "EjecutaConsulta",
		       (char *)0);

lSiscomCamProLPtrPaso=lSiscomCamProLPtrDato=SiscomFormaCamposSql(
						pchrPtrFormato,
						pchrPtrBuffer);

SiscomNodoRegistroPro(lSiscomCamProLPtrPaso,
		      &lSiscomRegProLPtrPrim,
		      &lSiscomRegProLPtrAct);
SiscomRegistroProtocoloLog(pchrPtrBuffer,lSiscomRegProLPtrPrim);
while(lSiscomCamProLPtrDato)
{
  lchrPtrSql=va_arg(lvaListInfo,char *);
  SiscomAnexaRegistrosAlCampo(lSiscomCamProLPtrDato->chrPtrNmbCampo,
  			      lSiscomRegProLPtrAct,
			      pchrPtrBuffer,
			      "Sql,",
			      lchrPtrSql);
  lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
}
va_end(lvaListInfo);
if((*pintPtrSocket=SiscomConectateCliente(pchrPtrDirIp,
				          pintPuerto,
					  &lchrPtrEdoConexion))>0)
{
SiscomEnviaRegistrosSocket(*pintPtrSocket,
			   pchrPtrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomLeeRegistrosSocket(*pintPtrSocket,
			 pchrPtrBuffer,
			 pSiscomRegProLPtrRegPrim,
			 pSiscomRegProLPtrRegAct);
}
}




void SiscomConsultasSqlOperaciones(char *pchrPtrBuffer,
				   SiscomOperaciones *pSiscomOpePtrDatos,
				   const char *pchrPtrFormato,
				   ...)

{
SiscomCampoProL *lSiscomCamProLPtrDato=0,
	 	*lSiscomCamProLPtrPaso,
		*lSiscomCamProLPtrCampo;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;

char *lchrPtrSql;
char *lchrPtrEdoConexion;
va_list lvaListInfo;
va_start(lvaListInfo,pchrPtrFormato);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       "BaseDatos,"
		       "PuertoBaseDatos,"
		       "Operacion,"
		       "EstadoOperacion,",
		       pSiscomOpePtrDatos->chrArrBaseDatos,
		       pSiscomOpePtrDatos->chrArrPuertoBaseDatos,
		       "EjecutaConsulta",
		       (const char *)0);
lSiscomCamProLPtrPaso=lSiscomCamProLPtrDato=SiscomFormaCamposSql(
						pchrPtrFormato,
						pchrPtrBuffer);
SiscomNodoRegistroPro(lSiscomCamProLPtrPaso,
		      &lSiscomRegProLPtrPrim,
		      &lSiscomRegProLPtrAct);
while(lSiscomCamProLPtrDato)
{
  lchrPtrSql=va_arg(lvaListInfo,char *);
  SiscomAnexaRegistrosAlCampo(lSiscomCamProLPtrDato->chrPtrNmbCampo,
  			      lSiscomRegProLPtrAct,
			      pchrPtrBuffer,
			      "Sql,",
			      lchrPtrSql);
  lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
}
va_end(lvaListInfo);
if((pSiscomOpePtrDatos->intSocketAD=SiscomConectateCliente(
				pSiscomOpePtrDatos->chrArrDirIpSvrAccesoDatos,
				pSiscomOpePtrDatos->intPuertoSvrAccesoDatos,
				&lchrPtrEdoConexion))>0)
{
SiscomEnviaRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			   pchrPtrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomLeeRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			 pchrPtrBuffer,
			 &pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes,
			 &pSiscomOpePtrDatos->SiscomRegProLPtrActRes);
}
}


void SiscomConsultasSqlOperaciones2(char *pchrPtrBuffer,
				   char **pchrPtrConsultas,
				   char **pchrPtrNombres,
				   SiscomOperaciones *pSiscomOpePtrDatos)

{
SiscomCampoProL *lSiscomCamProLPtrDato=0,
		*lSiscomCamProLPtrDatoAct=0,
	 	*lSiscomCamProLPtrPaso,
		*lSiscomCamProLPtrCampo=0;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;

char *lchrPtrSql;
char *lchrPtrEdoConexion;
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       "BaseDatos,"
		       "PuertoBaseDatos,"
		       "Operacion,"
		       "EstadoOperacion,",
		       pSiscomOpePtrDatos->chrArrBaseDatos,
		       pSiscomOpePtrDatos->chrArrPuertoBaseDatos,
		       "EjecutaConsulta",
		       (const char *)0);
lSiscomCamProLPtrPaso=lSiscomCamProLPtrDato=SiscomFormaRegistro(pchrPtrNombres,
							        &lSiscomCamProLPtrDato,
								&lSiscomCamProLPtrDatoAct);
SiscomNodoRegistroPro(lSiscomCamProLPtrPaso,
		      &lSiscomRegProLPtrPrim,
		      &lSiscomRegProLPtrAct);
while(*pchrPtrConsultas)
{
  SiscomAnexaRegistrosAlCampo(*pchrPtrNombres,
  			      lSiscomRegProLPtrAct,
			      pchrPtrBuffer,
			      "Sql,",
			      *pchrPtrConsultas);
  lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
  pchrPtrConsultas++;
  pchrPtrNombres++;
}
if((pSiscomOpePtrDatos->intSocketAD=SiscomConectateCliente(
				pSiscomOpePtrDatos->chrArrDirIpSvrAccesoDatos,
				pSiscomOpePtrDatos->intPuertoSvrAccesoDatos,
				&lchrPtrEdoConexion))>0)
{
SiscomEnviaRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			   pchrPtrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomLeeRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			 pchrPtrBuffer,
			 &pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes,
			 &pSiscomOpePtrDatos->SiscomRegProLPtrActRes);
}
}





/* Sabado 12 de mayo del 2012 
 * Funcion que debe tomar como argumentos variables las sentencias Sql 
 * que debera ejecutar el servidor y debera crear de forma interna los 
 * argumentos a los que se asignaran los resulados de las consultas a la
 * base de datos
 * SiscomConsultasSqlAArgumentos(char *pchrPtrBuffer,
 * 				 SiscomOperaciones *pSiscomOpePtrDatos,
 * 				 const char *pchrPtrFormato,
 * 				 ...);
 *
 * SiscomConsultaSqlAArgumentos(pchrPtrBuffer,
 * 				pSiscomOpePtrDatos,
 * 				"Direcciones%Telefonos%Usuarios",
 * 				"select * from direcciones",
 * 				"select * from telefonos",
 * 				"select * from usuarios");
 */
/* Miercoles 16 de Mayo del 2012
 * Con el manejo de los registros asociados, debere evaluar si es necesario
 * desarrollar el manejo de argumentos
 */

SiscomRegistroProL *SiscomRegistroProLObtenArgumentoPrim(
			const char *pchrPtrArgumento,
			const SiscomArgumento *pSiscomArgumentos)
{
const SiscomArgumento *lSiscomArgDato;
lSiscomArgDato=SiscomObtenArgumento(pchrPtrArgumento,pSiscomArgumentos);
return lSiscomArgDato->SiscomRegProLPtrPrim;
}

SiscomRegistroProL *SiscomRegistroProLObtenArgumentoAct(
			const char *pchrPtrArgumento,
			const SiscomArgumento *pSiscomArgumentos)
{
const SiscomArgumento *lSiscomArgDato;
if((lSiscomArgDato=SiscomObtenArgumento(pchrPtrArgumento,pSiscomArgumentos)))
return lSiscomArgDato->SiscomRegProLPtrAct;
else
LogSiscom("No se encontro el argumento:%s",pchrPtrArgumento);
}

SiscomRegistroProL *SiscomObtenArgumentoPrimOperaciones(
			const char *pchrPtrNombre,
			SiscomOperaciones *pSiscomOpePtrDatos)
{
if(pSiscomOpePtrDatos->SiscomArgPtrDatos)
return SiscomRegistroProLObtenArgumentoPrim(pchrPtrNombre,
			pSiscomOpePtrDatos->SiscomArgPtrDatos);
else
return 0;

}


SiscomRegistroProL *SiscomObtenArgumentoPrimAsociadoOperaciones(const char *pchrPtrArgumento,
				const char *pchrPtrCampo,
				SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSiscomRegProLReg=SiscomObtenArgumentoPrimOperaciones(pchrPtrArgumento,
									    pSiscomOpePtrDatos);
if(lSiscomRegProLReg)
return SiscomObtenRegistroPrimCampoProL(pchrPtrCampo,lSiscomRegProLReg);
else
return 0;

}
const char *SiscomCampoArgumentoPrim(const char *pchrPtrArgumento,
				     const char *pchrPtrCampo,
				     SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim;
if((lSiscomRegProLPtrPrim=SiscomObtenArgumentoPrimOperaciones(pchrPtrArgumento,
							      pSiscomOpePtrDato)))
return SiscomObtenCampoRegistroProLChar(pchrPtrCampo,lSiscomRegProLPtrPrim);
else
return 0;
}
const char *SiscomCampoArgumentoAct(const char *pchrPtrArgumento,
				     const char *pchrPtrCampo,
				     SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrAct;
if((lSiscomRegProLPtrAct=SiscomObtenArgumentoActOperaciones(pchrPtrArgumento,
							      pSiscomOpePtrDato)))
return SiscomObtenCampoRegistroProLChar(pchrPtrCampo,lSiscomRegProLPtrAct);
else
return 0;
}


SiscomRegistroProL *SiscomObtenArgumentoActOperaciones(
			const char *pchrPtrNombre,
			SiscomOperaciones *pSiscomOpePtrDatos)
{
return SiscomRegistroProLObtenArgumentoAct(pchrPtrNombre,
			pSiscomOpePtrDatos->SiscomArgPtrDatos);

}

SiscomRegistroProL *SiscomObtenRegistrosCampoRespuesta(const char *pchrPtrCampo,
						       SiscomOperaciones *pSiscomOpePtrDatos)
{

return SiscomObtenRegistrosCampoProL(pchrPtrCampo,
				     pSiscomOpePtrDatos->SiscomRegProLPtrActRes);

}

SiscomRegistroProL *SiscomObtenRegistrosCampoEntrada(const char *pchrPtrCampo,
						       SiscomOperaciones *pSiscomOpePtrDatos)
{

return SiscomObtenRegistrosCampoProL(pchrPtrCampo,
				     pSiscomOpePtrDatos->SiscomRegProLPtrActEnt);

}

const char *SiscomCampoAsociadoEntradaOperacion(const char *pchrPtrCampoAsociado,
						 const char *pchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSisRegProLAsociado;

if((lSisRegProLAsociado=SiscomObtenRegistrosCampoProL(
			  pchrPtrCampoAsociado,
			  pSiscomOpePtrDatos->SiscomRegProLPtrActEnt)))
 return SiscomObtenCampoRegistroProLChar(pchrPtrCampo,lSisRegProLAsociado);
else
{
return 0;
}
}

const char *SiscomCampoAsociadoRespuesta(const char *pchrPtrCampoAsociado,
						 const char *pchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSisRegProLAsociado;

if((lSisRegProLAsociado=SiscomObtenRegistrosCampoProL(
			  pchrPtrCampoAsociado,
			  pSiscomOpePtrDatos->SiscomRegProLPtrActRes)))
 return SiscomObtenCampoRegistroProLChar(pchrPtrCampo,lSisRegProLAsociado);
else
{
return 0;
}
}

SiscomRegistroProL *SiscomRegistroAsociadoEntradaOperacion(const char *pchrPtrCampoAsociado,
						 const char *pchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSisRegProLAsociado,
		   *lSiscomRegProLPtrRegistro;

if((lSisRegProLAsociado=SiscomObtenRegistrosCampoProL(
			  pchrPtrCampoAsociado,
			  pSiscomOpePtrDatos->SiscomRegProLPtrActEnt)))
{
  if((lSiscomRegProLPtrRegistro=SiscomObtenRegistrosCampoProL(pchrPtrCampo,lSisRegProLAsociado)))
  return lSiscomRegProLPtrRegistro;
  else
  return 0;
}
else
return 0;
}



const char *SiscomCampoAsociadoAsociadoEntradaOperacion(
					const char *pchrPtrCampoAsociado,
					const char *pchrPtrCampoAsociado1,
					const char *pchrPtrCampo,
					SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSisRegProLAsociado,
		   *lSiscomRegProLPtrAsociado1;

if((lSisRegProLAsociado=SiscomObtenRegistrosCampoProL(
			  pchrPtrCampoAsociado,
			  pSiscomOpePtrDatos->SiscomRegProLPtrActEnt)))
{
   if((lSiscomRegProLPtrAsociado1=SiscomObtenRegistrosCampoProL(
   					pchrPtrCampoAsociado1,
					lSisRegProLAsociado)))
   return SiscomObtenCampoRegistroProLChar(pchrPtrCampo,lSiscomRegProLPtrAsociado1);
}
else
{
return 0;
}
}

int SiscomCampoAsociadoAsociadoInt(const char *pchrPtrCampoAsociado,
				const char *pchrPtrCampoAsociado1,
				const char *pchrPtrCampo,
				SiscomOperaciones *pSiscomOpePtrDatos)
{
const char *lchrPtrDato;

if((lchrPtrDato=SiscomCampoAsociadoAsociadoEntradaOperacion(pchrPtrCampoAsociado,
							    pchrPtrCampoAsociado1,
							    pchrPtrCampo,
							    pSiscomOpePtrDatos)))
    return atoi(lchrPtrDato);
else
return -65000;
}
SiscomRegistroProL *SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion(const char *pchrPtrCampoAsociado,
							   const char *pchrPtrCampoAsociado1,
							   const char *pchrPtrCampo,
							   SiscomOperaciones *pSiscomOpePtrDatos)
{

SiscomRegistroProL *lSisRegProLAsociado,
		   *lSiscomRegProLPtrAsociado1;

if((lSisRegProLAsociado=SiscomObtenRegistrosCampoProL(
			  pchrPtrCampoAsociado,
			  pSiscomOpePtrDatos->SiscomRegProLPtrActEnt)))
{
   if((lSiscomRegProLPtrAsociado1=SiscomObtenRegistrosCampoProL(
   					pchrPtrCampoAsociado1,
					lSisRegProLAsociado)))
    return SiscomObtenRegistrosCampoProL(pchrPtrCampo,
    					 lSiscomRegProLPtrAsociado1);
    					 	
}
else
{
return 0;
}


}


float SiscomCampoAsociadoAsociadoEntradaOperacionFloat(
					const char *pchrPtrCampoAsociado,
					const char *pchrPtrCampoAsociado1,
					const char *pchrPtrCampo,
					SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSisRegProLAsociado,
		   *lSiscomRegProLPtrAsociado1;

if((lSisRegProLAsociado=SiscomObtenRegistrosCampoProL(
			  pchrPtrCampoAsociado,
			  pSiscomOpePtrDatos->SiscomRegProLPtrActEnt)))
{
   if((lSiscomRegProLPtrAsociado1=SiscomObtenRegistrosCampoProL(
   					pchrPtrCampoAsociado1,
					lSisRegProLAsociado)))
   return SiscomObtenCampoRegistroProLFloat(pchrPtrCampo,lSiscomRegProLPtrAsociado1);
}
else
{
return 0;
}
}


const char *SiscomCampoAsociadoAsociadoRespuestaOperacion(
					const char *pchrPtrCampoAsociado,
					const char *pchrPtrCampoAsociado1,
					const char *pchrPtrCampo,
					SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSisRegProLAsociado,
		   *lSiscomRegProLPtrAsociado1;

if((lSisRegProLAsociado=SiscomObtenRegistrosCampoProL(
			  pchrPtrCampoAsociado,
			  pSiscomOpePtrDatos->SiscomRegProLPtrActRes)))
{
   if((lSiscomRegProLPtrAsociado1=SiscomObtenRegistrosCampoProL(
   					pchrPtrCampoAsociado1,
					lSisRegProLAsociado)))
   return SiscomObtenCampoRegistroProLChar(pchrPtrCampo,lSiscomRegProLPtrAsociado1);
}
else
{
return 0;
}
}



int SiscomCampoAsociadoEntradaOperacionInt(const char *pchrPtrCampoAsociado,
						 const char *pchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos)
{
 return atoi(SiscomCampoAsociadoEntradaOperacion(pchrPtrCampoAsociado,pchrPtrCampo,pSiscomOpePtrDatos)); 
}
float SiscomCampoAsociadoEntradaOperacionFloat(const char *pchrPtrCampoAsociado,
						 const char *pchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos)
{
const char *lchrPtrCampo;
 if((lchrPtrCampo=SiscomCampoAsociadoEntradaOperacion(pchrPtrCampoAsociado,pchrPtrCampo,pSiscomOpePtrDatos)))
 return atof(lchrPtrCampo);
else
return 0.0;

}



SiscomRegistroProL *SiscomRegistrosAsociadoEntradaOperacion(const char *pchrPtrCampoAsociado,
						 SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSisRegProLAsociado;

if((lSisRegProLAsociado=SiscomObtenRegistrosCampoProL(
			  pchrPtrCampoAsociado,
			  pSiscomOpePtrDatos->SiscomRegProLPtrActEnt)))
  return lSisRegProLAsociado;

else
{
return 0;
}
}


SiscomRegistroProL *SiscomRegistrosAsociadoRespuestaOperacion(const char *pchrPtrCampoAsociado,
						 SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSisRegProLAsociado;

if((lSisRegProLAsociado=SiscomObtenRegistrosCampoProL(
			  pchrPtrCampoAsociado,
			  pSiscomOpePtrDatos->SiscomRegProLPtrActRes)))
  return lSisRegProLAsociado;

else
{
return 0;
}
}



const char *SiscomCampoAsociadoRespuestaOperacion(const char *pchrPtrCampoAsociado,
						 const char *pchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSisRegProLAsociado;

if((lSisRegProLAsociado=SiscomObtenRegistrosCampoProL(
			  pchrPtrCampoAsociado,
			  pSiscomOpePtrDatos->SiscomRegProLPtrActRes)))
 return SiscomObtenCampoRegistroProLChar(pchrPtrCampo,lSisRegProLAsociado);
else
{
return "Campo NO Encontrado SiscomCampoAsociadoEntradaOperacion";
}
}

SiscomRegistroProL *SiscomRegistroAsociadoRespuestaOperacion(const char *pchrPtrCampoAsociado,
						 const char *pchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSisRegProLAsociado;

if((lSisRegProLAsociado=SiscomObtenRegistrosCampoProL(
			  pchrPtrCampoAsociado,
			  pSiscomOpePtrDatos->SiscomRegProLPtrActRes)))
 return lSisRegProLAsociado;
else
{
LogSiscom("Campo NO Encontrado SiscomCampoAsociadoEntradaOperacion");
return (SiscomRegistroProL *)0;
}
}



int SiscomCampoAsociadoRespuestaOperacionInt(const char *pchrPtrCampoAsociado,
						 const char *pchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos)
{
   return atoi(SiscomCampoAsociadoRespuestaOperacion(pchrPtrCampoAsociado,pchrPtrCampo,pSiscomOpePtrDatos));
}
float SiscomCampoAsociadoRespuestaOperacionFloat(const char *pchrPtrCampoAsociado,
						 const char *pchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos)
{
return atof(SiscomCampoAsociadoRespuestaOperacion(pchrPtrCampoAsociado,pchrPtrCampo,pSiscomOpePtrDatos));

}


void SiscomAsignaRegistrosArgumentoOperaciones(SiscomRegistroProL *pSisRegProLPtrPrim,
					       SiscomRegistroProL *pSisRegProLPtrAct,
					       const char *pchrPtrArgumento,
					       SiscomOperaciones *pSiscomOpeDatos)
{
SiscomArgumento *lSisArgPtrDato;
if((lSisArgPtrDato=(SiscomArgumento *)SiscomObtenArgumento(pchrPtrArgumento,
				       pSiscomOpeDatos->SiscomArgPtrDatos)))
{
lSisArgPtrDato->SiscomRegProLPtrPrim=pSisRegProLPtrPrim;
lSisArgPtrDato->SiscomRegProLPtrAct=pSisRegProLPtrAct;
}

}
const char *SiscomObtenCampoAsociadoArgumento(const char *pchrPtrArgumento,
					      const char *pchrPtrRegistroAsociado,
					      const char *pchrPtrCampo,
					      SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSiscomRegProLPtrArgumento;
SiscomRegistroProL *lSiscomRegProLPtrRegistro;
if((lSiscomRegProLPtrArgumento=SiscomObtenArgumentoPrimOperaciones(pchrPtrArgumento,
								   pSiscomOpePtrDatos)))
{
 if((lSiscomRegProLPtrRegistro=SiscomObtenRegistrosCampoProL(pchrPtrRegistroAsociado,
 							     lSiscomRegProLPtrArgumento)))
 return SiscomObtenCampoRegistroProLChar(pchrPtrCampo,lSiscomRegProLPtrRegistro);

}
}

const char *SiscomObtenCampoArgumento4(const char *pchrPtrArgumento,
					      const char *pchrPtrCampo,
					      SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSiscomRegProLPtrArgumento;
if((lSiscomRegProLPtrArgumento=SiscomObtenArgumentoActOperaciones(pchrPtrArgumento,
								   pSiscomOpePtrDatos)))
 return SiscomObtenCampoRegistroProLChar(pchrPtrCampo,lSiscomRegProLPtrArgumento);
else
return 0;

}

int SiscomObtenCampoArgumentoInt(const char *pchrPtrArgumento,
					      const char *pchrPtrCampo,
					      SiscomOperaciones *pSiscomOpePtrDatos)
{
 return atoi(SiscomObtenCampoArgumento4(pchrPtrArgumento,pchrPtrCampo,pSiscomOpePtrDatos));
}
float SiscomObtenCampoArgumentoFloat(const char *pchrPtrArgumento,
					      const char *pchrPtrCampo,
					      SiscomOperaciones *pSiscomOpePtrDatos)
{
 return atof(SiscomObtenCampoArgumento4(pchrPtrArgumento,pchrPtrCampo,pSiscomOpePtrDatos));
}



int SiscomEnviaArgumentoCliente(const char *pchrPtrArgumento,
				char *pchrPtrBuffer,
				SiscomOperaciones *pSiscomOpPtrDatos)
{
SiscomRegistroProL *lSiscomRegProLRegreso;
if((lSiscomRegProLRegreso=SiscomObtenArgumentoPrimOperaciones(pchrPtrArgumento,
							      pSiscomOpPtrDatos)))
{
  SiscomEnviaRegistrosSocket(pSiscomOpPtrDatos->intSocket,
  			     pchrPtrBuffer,
			     lSiscomRegProLRegreso);
  return 1;
}
else
return 0;
}
int SiscomEnviaAsociadoRespuestaCliente(const char *pchrPtrAsociado,
				char *pchrPtrBuffer,
				SiscomOperaciones *pSiscomOpPtrDatos)
{
SiscomRegistroProL *lSiscomRegProLRegreso;
if((lSiscomRegProLRegreso=SiscomRegistrosAsociadoRespuestaOperacion(pchrPtrAsociado,
							      pSiscomOpPtrDatos)))
{
  SiscomEnviaRegistrosSocket(pSiscomOpPtrDatos->intSocket,
  			     pchrPtrBuffer,
			     lSiscomRegProLRegreso);
  return 1;
}
else
return 0;
}

int SiscomEnviaAsociadoEntradaCliente(const char *pchrPtrAsociado,
				char *pchrPtrBuffer,
				SiscomOperaciones *pSiscomOpPtrDatos)
{
SiscomRegistroProL *lSiscomRegProLRegreso;
if((lSiscomRegProLRegreso=SiscomRegistrosAsociadoEntradaOperacion(pchrPtrAsociado,
							      pSiscomOpPtrDatos)))
{
  SiscomEnviaRegistrosSocket(pSiscomOpPtrDatos->intSocket,
  			     pchrPtrBuffer,
			     lSiscomRegProLRegreso);
  return 1;
}
else
return 0;
}



int SiscomEnviaRegistrosRespuesta(SiscomOperaciones *pSiscomOpePtrDatos,char *pchrPtrBuffer)
{

  SiscomEnviaRegistrosSocket(pSiscomOpePtrDatos->intSocket,
  			     pchrPtrBuffer,
			     pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes);

}

int SiscomEnviaRegistrosEntrada(SiscomOperaciones *pSiscomOpePtrDatos,char *pchrPtrBuffer)
{

  SiscomEnviaRegistrosSocket(pSiscomOpePtrDatos->intSocket,
  			     pchrPtrBuffer,
			     pSiscomOpePtrDatos->SiscomRegProLPtrPrimEnt);

}

int SiscomFormaEnviaRegistroRespuesta(SiscomOperaciones *pSiscomOpePtrDatos,
				 char *pchrPtrBuffer,
				 const char *pchrPtrFormato,
				 ...)
{
SiscomCampoProL *lSiscomCamProLPtrDato=0,
		*lSiscomCamProLPtrPaso;
va_list lvaListInfo;
char *lchrPtrCampo;
va_start(lvaListInfo,pchrPtrFormato);
lSiscomCamProLPtrPaso=lSiscomCamProLPtrDato=SiscomFormaCamposFormato(pchrPtrFormato,pchrPtrBuffer);
while(lSiscomCamProLPtrDato)
{
lchrPtrCampo=va_arg(lvaListInfo,char *);
lSiscomCamProLPtrDato->chrPtrDato=lchrPtrCampo ? strdup(lchrPtrCampo):0;
lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
}
va_end(lvaListInfo);

SiscomNodoRegistroPro(lSiscomCamProLPtrPaso,
		      &pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes,
		      &pSiscomOpePtrDatos->SiscomRegProLPtrActRes);
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDatos,pchrPtrBuffer);

}

SiscomRegistroProL *SiscomRegistrosCampoO(const char *pchrPtrCampo,SiscomOperaciones *pSiscomOpPtrDatos)
{
 return SiscomObtenRegistrosCampoProL(pchrPtrCampo,pSiscomOpPtrDatos->SiscomRegProLPtrPrimRes);
}

void SiscomIdARegistrosAsociadosEntrada(const char *pchrPtrAsociado,
					const char *pchrPtrCampo,
					SiscomOperaciones *pSiscomOpPtrDatos)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;
lSiscomRegProLPtrDato=SiscomObtenRegistrosCampoProL(pchrPtrAsociado,
						    pSiscomOpPtrDatos->SiscomRegProLPtrPrimEnt);
SiscomIdUnicoRegistros(pchrPtrCampo,lSiscomRegProLPtrDato);
}

void SiscomIdAsociadosCampoEntrada(const char *pchrPtrCampo,
				   const char *pchrPtrAsociado,
				   const char *pchrPtrIdCampo,
				   SiscomOperaciones *pSiscomOpPtrDatos)
{
SiscomRegistroProL *lSiscomRegProLDatos;
if((lSiscomRegProLDatos=SiscomRegistrosAsociadosCampo(pchrPtrCampo,
						  pchrPtrAsociado,
						  pSiscomOpPtrDatos->SiscomRegProLPtrPrimEnt)))
SiscomIdUnicoRegistros(pchrPtrIdCampo,lSiscomRegProLDatos);
}


void SiscomIdAsociadoAsociadosCampoEntrada(const char *pchrPtrAsociado,
					   const char *pchrPtrAsociadoA,
					   const char *pchrPtrCampo,
					   SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSiscomRegProLPtrInfo,
		     *lSiscomRegProLPtrDato;

if((lSiscomRegProLPtrInfo=SiscomRegistrosAsociadoEntradaOperacion(pchrPtrAsociado,pSiscomOpePtrDatos)))
{
if((lSiscomRegProLPtrDato=SiscomObtenRegistrosCampoProL(pchrPtrAsociadoA,
						        lSiscomRegProLPtrInfo)))
SiscomIdUnicoRegistros(pchrPtrCampo,lSiscomRegProLPtrDato);
else
LogSiscom("No Se encontro el campo %s",pchrPtrAsociadoA);

}
else
LogSiscom("No Se encontro el campo %s",pchrPtrAsociado);

}

void SiscomAgregaCampoAsociadoEntrada(const char *pchrPtrNombre,
				      const char *pchrPtrCampo,
				      const char *pchrPtrAsociado,
				      SiscomOperaciones *pSiscomOpPtrDatos)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;
lSiscomRegProLPtrDato=SiscomRegistrosAsociadoEntradaOperacion(pchrPtrAsociado,
							pSiscomOpPtrDatos);
SiscomAgregaCampoRegistro(pchrPtrNombre,
			  pchrPtrCampo,
			  lSiscomRegProLPtrDato);
}

void SiscomAgregaCampoAsociadoRespuesta(const char *pchrPtrNombre,
				      const char *pchrPtrCampo,
				      const char *pchrPtrAsociado,
				      SiscomOperaciones *pSiscomOpPtrDatos)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;
lSiscomRegProLPtrDato=SiscomRegistrosAsociadoRespuestaOperacion(pchrPtrAsociado,
							pSiscomOpPtrDatos);
SiscomAgregaCampoRegistro(pchrPtrNombre,
			  pchrPtrCampo,
			  lSiscomRegProLPtrDato);
}

/* Lunes 29 de Diciembre del 2014 
 * Recorre todos los registros de entrada del asociado 
 * asignandole el valor
 */
void SiscomActualizaCampoAsociadoEntrada(const char *pchrPtrAsociado,
					 const char *pchrPtrCampo,
					 char *pchrPtrValor,
					 SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;
lSiscomRegProLPtrDato=SiscomRegistrosAsociadoEntradaOperacion(pchrPtrAsociado,
							pSiscomOpePtrDato);

if(lSiscomRegProLPtrDato)
SiscomActualizaCampoAsignaMemoriaRegistro(pchrPtrCampo,
					  pchrPtrValor,
					  lSiscomRegProLPtrDato);
else
LogSiscom("NO Existe el campo %s",pchrPtrCampo);
}

void SiscomActualizaCampoAsociadoEntradaFloat(const char *pchrPtrAsociado,
					 const char *pchrPtrCampo,
					 float pfltValor,
					 SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;
char lchrArrValor[28];
sprintf(lchrArrValor,"%.2f",pfltValor);
if((lSiscomRegProLPtrDato=SiscomRegistrosAsociadoEntradaOperacion(pchrPtrAsociado,
							pSiscomOpePtrDato)))
SiscomActualizaCampoAsignaMemoriaRegistro(pchrPtrCampo,
					  lchrArrValor,
					  lSiscomRegProLPtrDato);
else
LogSiscom("NO Existe el campo %s",pchrPtrCampo);
}

void SiscomActualizaCampoAsociadoAsociadoEntrada(const char *pchrPtrAsociado,
						 const char *pchrPtrAsociadoA,
						 const char *pchrPtrCampo,
						 const char *pchrPtrDato,
						 SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrDato,
		   *lSiscomRegProLPtrOtroAsociado;

if((lSiscomRegProLPtrDato=SiscomRegistrosAsociadoEntradaOperacion(pchrPtrAsociado,
								  pSiscomOpePtrDato)))
{
  if((lSiscomRegProLPtrOtroAsociado=SiscomObtenRegistrosCampoProL(pchrPtrAsociadoA,
								  lSiscomRegProLPtrDato)))
  {
     SiscomActualizaCampoAsignaMemoriaRegistro(pchrPtrCampo,
     					       (char *)pchrPtrDato,
						lSiscomRegProLPtrOtroAsociado);
  }
}
}

void SiscomActualizaCampoArgumento(const char *pchrPtrArgumento,
					 const char *pchrPtrCampo,
					 char *pchrPtrValor,
					 SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSiscomRegProLPtrActual;
if((lSiscomRegProLPtrActual=SiscomObtenArgumentoActOperaciones(pchrPtrArgumento,pSiscomOpePtrDatos)))
{
 
SiscomActualizaCampoAsignaMemoriaRegistro(pchrPtrCampo,
					  pchrPtrValor,
					  lSiscomRegProLPtrActual);

}

}

void SiscomActualizaCampoFloatArgumentoActual(const char *pchrPtrArgumento,
					     const char *pchrPtrCampo,
			  		     const char *pchrPtrFormato,
			  		     float pfltDato,
					     SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSiscomRegProLPtrActual;
if((lSiscomRegProLPtrActual=SiscomObtenArgumentoActOperaciones(pchrPtrArgumento,pSiscomOpePtrDatos)))
 SiscomActualizaCampoFloatRegistroActual(pchrPtrCampo,
 					 pchrPtrFormato,
					 pfltDato,
					  lSiscomRegProLPtrActual);

}


void SiscomActualizaCampoArgumento2(const char *pchrPtrArgumento,
					 const char *pchrPtrCampo,
					 char *pchrPtrValor,
					 SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSiscomRegProLPtrActual;
if((lSiscomRegProLPtrActual=SiscomObtenArgumentoActOperaciones(pchrPtrArgumento,pSiscomOpePtrDatos)))
{
SiscomActualizaCampoRegistroActual(pchrPtrCampo,
					  pchrPtrValor,
					  lSiscomRegProLPtrActual);

}
else
LogSiscom("NO Esta el argumento :%s",pchrPtrArgumento);

}

void SiscomRegistroEnvioBaseDatosAArgumento(const char *pchrPtrOperacion,
				     const char *pchrPtrArgumento,
				     char *pchrPtrBuffer,
				     SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSiscomProLPtrArgumentoPrim=0,
		   *lSiscomProLPtrArgumentoAct=0;

SiscomRegistroEnvioBaseDatos(pSiscomOpePtrDatos->chrArrBaseDatos,
			     pSiscomOpePtrDatos->chrArrPuertoBaseDatos,
			     pchrPtrOperacion,
			     pchrPtrBuffer,
			     &lSiscomProLPtrArgumentoPrim,
			     &lSiscomProLPtrArgumentoAct);
SiscomAgregaArgumentoOperacion(pchrPtrArgumento,
			       lSiscomProLPtrArgumentoPrim,
			       lSiscomProLPtrArgumentoAct,
			       pSiscomOpePtrDatos);
}

void SiscomRegistroASentenciasSqlAArgumento(char *pchrPtrBuffer,
					    const char *pchrPtrSql,
					    const char *pchrPtrArgumento,
					    SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSiscomRegProLPtrActualSql;
lSiscomRegProLPtrActualSql=SiscomObtenArgumentoActOperaciones(pchrPtrArgumento,
							      pSiscomOpePtrDatos);
SiscomAnexaRegistrosAlCampo("SentenciasSql",
			     lSiscomRegProLPtrActualSql,
			     pchrPtrBuffer,
			     "Sql,Estado,",
			     pchrPtrSql,
			     (char *)0);
}


SiscomRegistroProL *SiscomRegistrosAsociadosCampoEntrada(const char *pchrPtrCampo,
						  const char *pchrPtrAsociado,
						  SiscomOperaciones *pSiscomOpePtrDato)
{
  return SiscomRegistrosAsociadosCampo(pchrPtrCampo,
  				       pchrPtrAsociado,
				       pSiscomOpePtrDato->SiscomRegProLPtrPrimEnt);
}

SiscomRegistroProL *SiscomRegistrosAsociadosCampoRespuesta(const char *pchrPtrCampo,
						  const char *pchrPtrAsociado,
						  SiscomOperaciones *pSiscomOpePtrDato)
{
  return SiscomRegistrosAsociadosCampo(pchrPtrCampo,
  				       pchrPtrAsociado,
				       pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
}

void SiscomAsignaFechaHoraAsociadoEntrada(const char *pchrPtrAsociado,
					  const char *pchrPtrCampo,
					  SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;

if((lSiscomRegProLPtrDato=SiscomRegistrosAsociadoEntradaOperacion(pchrPtrAsociado,pSiscomOpePtrDato)))
SiscomAsignaFechaHoraCampo(pchrPtrCampo,lSiscomRegProLPtrDato);
}


void SiscomAsignaFechaAsociadoEntrada(const char *pchrPtrAsociado,
					  const char *pchrPtrCampo,
					  SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;

if((lSiscomRegProLPtrDato=SiscomRegistrosAsociadoEntradaOperacion(pchrPtrAsociado,pSiscomOpePtrDato)))
SiscomAsignaFechaCampo(pchrPtrCampo,lSiscomRegProLPtrDato);
}

void SiscomAsignaFechaAsociadoAsociadoEntrada(const char *pchrPtrAsociado,
					      const char *pchrPtrAsociado1,
					      const char *pchrPtrCampoFecha,
					      SiscomOperaciones *pSiscomOperaciones)
{
char lchrArrFecha[25];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
SiscomActualizaCampoAsociadoAsociadoEntrada(pchrPtrAsociado,
					    pchrPtrAsociado1,
					    pchrPtrCampoFecha,
					    lchrArrFecha,
					    pSiscomOperaciones);
}


void SiscomFechaAsociadosCampoEntrada(const char *pchrPtrCampo,
				      const char *pchrPtrAsociado,
				      const char *pchrPtrCampoFecha,
				      SiscomOperaciones *pSiscomOpPtrDatos)
{
SiscomRegistroProL *lSiscomRegProLDatos;
if((lSiscomRegProLDatos=SiscomRegistrosAsociadosCampo(pchrPtrCampo,
						  pchrPtrAsociado,
						  pSiscomOpPtrDatos->SiscomRegProLPtrPrimEnt)))
SiscomAsignaFechaCampo(pchrPtrCampoFecha,lSiscomRegProLDatos);
}
void SiscomRegistrosAlCampoAsociadoRespuesta(const char *pchrPtrAsociado,
				     const char *pchrPtrCampo,
				     const SiscomRegistroProL *pSisRegProLPtrDatoPrim,
				     const SiscomRegistroProL *pSisRegProLPtrDatoAct,
				     SiscomOperaciones *pSiscomOpPtrDatos)
{
SiscomRegistroProL *lSisRegProLPtrDatos;
lSisRegProLPtrDatos=SiscomRegistrosAsociadoRespuestaOperacion(pchrPtrAsociado,
								pSiscomOpPtrDatos);
SiscomRegistrosAlCampo(pchrPtrCampo,
			    pSisRegProLPtrDatoPrim,
			    pSisRegProLPtrDatoAct,
			    lSisRegProLPtrDatos);
}

void SiscomRegistrosAlCampoEntrada(const char *pchrPtrCampo,
				     const SiscomRegistroProL *pSisRegProLPtrDatoPrim,
				     const SiscomRegistroProL *pSisRegProLPtrDatoAct,
				     SiscomOperaciones *pSiscomOpPtrDatos)
{

SiscomRegistrosAlCampo(pchrPtrCampo,
			    pSisRegProLPtrDatoPrim,
			    pSisRegProLPtrDatoAct,
			    pSiscomOpPtrDatos->SiscomRegProLPtrActEnt);


}
				  
void SiscomCambiaAMayusculasCampoAsociadoEntrada(const char *pchrPtrAsociado,
					  const char *pchrPtrCampo,
					  SiscomOperaciones *pSiscomOpePtrDatos)
{
char *lchrPtrCampo=(char *)SiscomCampoAsociadoEntradaOperacion(pchrPtrAsociado,
						       pchrPtrCampo,
						       pSiscomOpePtrDatos);
SiscomAMayusculas(lchrPtrCampo);
}

int SiscomComparaCampoAsociadoEntradaCadena(const char *pchrPtrAsociado,
					     const char *pchrPtrCampo,
					     const char *pchrPtrCadena,
					     SiscomOperaciones *pSiscomOpePtrDatos)
{
const char *lchrPtrCampo=(char *)SiscomCampoAsociadoEntradaOperacion(pchrPtrAsociado,
								     pchrPtrCampo,
								     pSiscomOpePtrDatos);
return strcmp(lchrPtrCampo,pchrPtrCadena);
}

int SiscomComparaCamposAsociadoEntrada(const char *pchrPtrAsociado,
					     const char *pchrPtrCampo1,
					     const char *pchrPtrCampo2,
					     SiscomOperaciones *pSiscomOpePtrDatos)
{
const char *lchrPtrCampo1=SiscomCampoAsociadoEntradaOperacion(pchrPtrAsociado,
								     pchrPtrCampo1,
								     pSiscomOpePtrDatos);
const char *lchrPtrCampo2=SiscomCampoAsociadoEntradaOperacion(pchrPtrAsociado,
								     pchrPtrCampo2,
								     pSiscomOpePtrDatos);
return strcmp(lchrPtrCampo1,lchrPtrCampo2);

}

void SiscomAgregaCampoRegistroEntrada(const char *pchrPtrNombre,
				      const char *pchrPtrCampo,
				      SiscomOperaciones *pSiscomOpePtrDatos)
{
if(pSiscomOpePtrDatos->SiscomRegProLPtrActEnt->SiscomCamProLPtrDato)
SiscomAgregaCampoRegistro2(pchrPtrNombre,
			   pchrPtrCampo,
			   pSiscomOpePtrDatos->SiscomRegProLPtrActEnt);
else
SiscomAgregaCampoRegistro(pchrPtrNombre,
			 pchrPtrCampo,
			 pSiscomOpePtrDatos->SiscomRegProLPtrActEnt);

}
void SiscomAgregaCampoRegistroRespuesta(const char *pchrPtrNombre,
				      const char *pchrPtrCampo,
				      SiscomOperaciones *pSiscomOpePtrDatos)
{

if(!pSiscomOpePtrDatos->SiscomRegProLPtrActRes->SiscomCamProLPtrDato)
SiscomAgregaCampoRegistro2(pchrPtrNombre,
			   pchrPtrCampo,
			   pSiscomOpePtrDatos->SiscomRegProLPtrActRes);
else
SiscomAgregaCampoRegistro(pchrPtrNombre,
			   pchrPtrCampo,
			   pSiscomOpePtrDatos->SiscomRegProLPtrActRes);
}

int SiscomAnexaRegistroRespuesta(SiscomOperaciones *pSiscomOpePtrDatos)
{
   pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes=0;
   pSiscomOpePtrDatos->SiscomRegProLPtrActRes=0;
   SiscomAnexaRegistroPro3(&pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes,
   			   &pSiscomOpePtrDatos->SiscomRegProLPtrActRes);
}
int SiscomAnexaRegistroEntrada(SiscomOperaciones *pSiscomOpePtrDatos)
{
   SiscomAnexaRegistroPro3(&pSiscomOpePtrDatos->SiscomRegProLPtrPrimEnt,
   			   &pSiscomOpePtrDatos->SiscomRegProLPtrActEnt);
}

int SiscomActualizaCampoRespuesta(const char *pchrPtrCampo,
				  char *pchrPtrDato,
				  SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomActualizaCampoAsignaMemoria2(pchrPtrCampo,
				   pchrPtrDato,
				   pSiscomOpePtrDatos->SiscomRegProLPtrActRes);
}

int SiscomActualizaCampoRespuestaFloat(const char *pchrPtrCampo,
				 	const char *pchrPtrFormato,
					float pfltValor,
				  SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomActualizaCampoFloatRegistro(pchrPtrCampo,
				  pchrPtrFormato,
				  pfltValor,
				  pSiscomOpePtrDatos->SiscomRegProLPtrActRes);
}
int SiscomActualizaCampoEntrada(const char *pchrPtrCampo,
				  char *pchrPtrDato,
				  SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomActualizaCampoAsignaMemoria2(pchrPtrCampo,
				   pchrPtrDato,
				   pSiscomOpePtrDatos->SiscomRegProLPtrActEnt);
}
int SiscomActualizaCampoEntradaFloat(const char *pchrPtrCampo,
				     const char *pchrPtrFormato,
				     float pfltValor,
				  SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomActualizaCampoFloatRegistro(pchrPtrCampo,
				  pchrPtrFormato,
				  pfltValor,
				  pSiscomOpePtrDatos->SiscomRegProLPtrActEnt);
}

/* Domingo 14 de Agosto del 2016 
 * Funcion que obtiene los Registros asociados 
 * de pchrPtrAsociado, y ve si en estos registros
 * esta el campo pchrPtrCampo
 */

int SiscomEstaElCampoAsociado(const char *pchrPtrAsociado,
			      const char *pchrPtrCampo,
			      SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomRegistroProL *lSiscomRegProLPtrDatos;

if((lSiscomRegProLPtrDatos=SiscomRegistrosAsociadoEntradaOperacion(pchrPtrAsociado,
							pSiscomOpePtrDatos)))
return SiscomEstaElCampo4(pchrPtrCampo,lSiscomRegProLPtrDatos);
else
{
   LogSiscom("NO Se encontro el campo :%s",pchrPtrAsociado);
   return -1;
}

}

int SiscomNoRegistrosAsociado(const char *pchrPtrCampo,				
				      const char *pchrPtrAsociado,
				      SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrRegsAsociado;
if((lSiscomRegProLPtrRegsAsociado=SiscomRegistrosAsociadosCampoEntrada(pchrPtrCampo,
								 	pchrPtrAsociado,
									pSiscomOpePtrDato)))
{
return lSiscomRegProLPtrRegsAsociado->intNRegistros;
}
else
{
LogSiscom("NO Se Encontro el Campo %s Con Asociado %s",pchrPtrCampo,pchrPtrAsociado);
return -1;
}

}

int SiscomMultiplicaCamposACampoEntrada(const char *pchrPtrAsociado,
				 const char *pchrPtrCampoA,
				 const char *pchrPtrCampoB,
				 const char *pchrPtrResultado,
				 const char *pchrPtrCadenaFormato,
				 SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrRegsAsociado;
if((lSisRegProLPtrRegsAsociado=SiscomObtenRegistrosCampoEntrada(pchrPtrAsociado,
							 	pSiscomOpePtrDato)))	
  SiscomMultiplicaCamposACampo(pchrPtrCampoA,
  			       pchrPtrCampoB,
			       pchrPtrResultado,
			       pchrPtrCadenaFormato,
			       lSisRegProLPtrRegsAsociado);
else
LogSiscom("NO Se encontro el campo %s ",pchrPtrAsociado);
}

void SiscomArgumentoAPrimerActual(const char *pchrPtrArgumento,SiscomOperaciones *pSisOpePtrDatos)
{
SiscomRegistroProL *lSisRegProLPtrPrim;

lSisRegProLPtrPrim=SiscomObtenArgumentoPrimOperaciones(pchrPtrArgumento,pSisOpePtrDatos);

SiscomAsignaRegistrosArgumentoOperaciones(lSisRegProLPtrPrim,
					  lSisRegProLPtrPrim,
					  pchrPtrArgumento,
					  pSisOpePtrDatos);
		   


}
