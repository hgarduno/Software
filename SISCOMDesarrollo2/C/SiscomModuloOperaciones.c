/*! \file SiscomModuloOperaciones.c 
 *  \brief SISCOM Electronica.
 *         Archivo desarrolloda por Heli Garduno Esquivel 2007
 *	  
 *	  Archivo que contiene las funciones para manipular las operaciones
 *	  que se realizan, en el servidor SISCOM2
 *
 */



#include <SiscomModuloOperaciones.h>
#include <SiscomFuncionesComunes.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
void SiscomIniciaOperaciones(int pintNOperaciones,
			     SSiscomOperaciones **pSSiscomOp)
{


	if((*pSSiscomOp=(SSiscomOperaciones *)malloc(sizeof(SSiscomOperaciones )*
						     (pintNOperaciones+1))))
	{
	  (*pSSiscomOp)->intNumOperaciones=0;
	}

}
void SiscomAnexaOperacion(const char *pchrPtrNoOperacion,
			  void (*Operacion)(int,int),
			  SSiscomOperaciones **pSSiscomOp)
{
int lintNOperacion;
	lintNOperacion=(*pSSiscomOp)->intNumOperaciones;
	(*pSSiscomOp+lintNOperacion)->chrPtrOperacion=(char *)strdup(pchrPtrNoOperacion);
	(*pSSiscomOp+lintNOperacion)->Operacion=Operacion;
	(*pSSiscomOp)->intNumOperaciones++;

}

void SiscomAnexaOperacionesAlFinal(SSiscomOperaciones *pSSiscomOpAnexar,
				   SSiscomOperaciones **pSSiscomOpSalida)
{


}
/*
void SiscomAnexaOperacion2A(const char *pchrPtrOperacion,
			   void (**Operaciones)(SArgsSiscom *),
			   void (*Configuracion)(SArgsSiscom *),
			   int pintNPosicion,
			   SSiscomOperaciones2 **pSSOperaciones2)
{

int lintNumOperacion;

	if(!*pSSOperaciones2)
	{
	   *pSSOperaciones2=(SSiscomOperaciones2 *)malloc(sizeof(SSiscomOperaciones2 )*100);
	   (*pSSOperaciones2)->intNumOperaciones=0;
	   memset(*pSSOperaciones2,0,sizeof(SSiscomOperaciones2)*100);
	}
	else
	{
	 lintNumOperacion=(*pSSOperaciones2)->intNumOperaciones;
	}
	for(lintContador=0;
	    Operaciones[lintContador];
	    lintContador++)
	{

	}
	 lintNumOperacion=(*pSSOperaciones2)->intNumOperaciones;
	 ((*pSSOperaciones2)+lintNumOperacion)->SiscomOperaciones2=Operaciones;
	 ((*pSSOperaciones2)+lintNumOperacion)->chrPtrOperacion=pchrPtrOperacion;
	 (*pSSOperaciones2)->intNumOperaciones++;

}
*/
void SiscomAnexaOperacion2(const char *pchrPtrOperacion,
			   void (**Operaciones)(SArgsSiscom *),
			   SSiscomOperaciones2 **pSSOperaciones2)
{

int lintNumOperacion;

	if(!*pSSOperaciones2)
	{
	   *pSSOperaciones2=(SSiscomOperaciones2 *)malloc(sizeof(SSiscomOperaciones2 ));
	   (*pSSOperaciones2)->intNumOperaciones=1;
	   memset(*pSSOperaciones2,0,sizeof(SSiscomOperaciones2));
	}
	else
	{
	 lintNumOperacion=(*pSSOperaciones2)->intNumOperaciones;
	 *pSSOperaciones2=(SSiscomOperaciones2 *)realloc(*pSSOperaciones2,
	 						 sizeof(SSiscomOperaciones2 )*
							 (lintNumOperacion+1));
	}
	 lintNumOperacion=(*pSSOperaciones2)->intNumOperaciones;
	 ((*pSSOperaciones2)+lintNumOperacion)->SiscomOperaciones2=Operaciones;
	 ((*pSSOperaciones2)+lintNumOperacion)->chrPtrOperacion=strdup(pchrPtrOperacion);
	 (*pSSOperaciones2)->intNumOperaciones++;

}
SiscomOperaciones2 *SiscomOperaciones2CualEjecuta(const char *pchrPtrOperacion,
					       SSiscomOperaciones2 *pSSOperaciones2,
					       SiscomOperaciones2 pSOperaciones2Error,
					       SArgsSiscom *pSArgsSiscom)
{
int lintContador;
	for(lintContador=0;
	    lintContador<pSSOperaciones2->intNumOperaciones;
	    lintContador++)
	 if(!strcmp(pchrPtrOperacion,
	 	    (pSSOperaciones2+lintContador)->chrPtrOperacion))
	   return (pSSOperaciones2+lintContador)->SiscomOperaciones2;
	 return &pSOperaciones2Error;
}
/* Sabado 14 de Noviembre 
 * por lo de la inicializacion, pero no esta terminada
 */
SiscomOperaciones2 *SiscomIniciaMemoriaOperaciones2(int pintNOperaciones)
{
SiscomOperaciones2 *lSOpOperaciones;
if((lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*(pintNOperaciones+1))))
{
   

}

}

void SiscomOperaciones2Ejecuta(SiscomOperaciones2 *pSOperaciones2,
			       SArgsSiscom *pSArgsSiscom)
{
int lintContador;
	/* Ciudad de Mexico 7 De Agosto del 2021 
	 * En medio del Covid, y sigue vamos 1 año y medio  :( 
	 *
	 * Despues de almenos 12 años con este error 
	 *  Antes
	 *  (pSOperaciones2+lintContador) 
	 *
	 *  Y ahora 
	 *
	 *  *(pSOperaciones2+lintContador) -->> :) :) 
	 * 
	 */
	for(lintContador=0; *(pSOperaciones2+lintContador);lintContador++)
	{
	  if(!pSArgsSiscom->intCodigoRetorno)
          pSOperaciones2[lintContador](pSArgsSiscom);
	  else
	  {
	  SiscomLog("No se puede continuar con el proceso");
	  /* 
	   * Viernes 18 Enero 2008 Se agrego el manejador de errores
	   *
	   */
	  pSArgsSiscom->SiscomError[pSArgsSiscom->intCodigoRetorno](pSArgsSiscom);
	  return ;
	  }
	}
	/* Queretaro Martes 20 de Octubre 2015 
	 * se elimino esta parte ya que en todas
	 * las funciones , se tiene en el codigo
	 * que envie la informacion de regreso 
	 * al cliente, de esta estructura o 
	 * de forma explicita de argumentos, o 
	 * si se genereo por otro medio
	if(pSArgsSiscom->LCSiscomPro2Regreso)
	{
	SiscomEnviaAlServidor(pSArgsSiscom->intSocketCliente,
			      pSArgsSiscom->intNumRegRegreso,
			      "Respuesta",
			      pSArgsSiscom->LCSiscomPro2Regreso);
	} 
	*/
	/* Queretaro Martes 20 de Octubre del 2015
	 * se cierra el socket del cliente una vez que
	 * se ejecutan todas las operaciones 
	 */
	close(pSArgsSiscom->intSocketCliente);
}

void SiscomLeeEntradaOpSubRegistros(SArgsSiscom *pSAgsSiscom)
{
pSAgsSiscom->LCSiscomPro2Dat=0;;
	SiscomLeeConSubRegistros(pSAgsSiscom->intSocketCliente,
				 pSAgsSiscom->intNRegistrosDat,
				 &pSAgsSiscom->LCSiscomPro2DatConfig,
				 &pSAgsSiscom->LCSiscomPro2SREntrada);

}
void SiscomLeeEntradaOperaciones2(SArgsSiscom *pSArgsSisPtrDat)
{
	SiscomLeeInformacionProtocoloUltimoRegistro(
		pSArgsSisPtrDat->intSocketCliente,
		pSArgsSisPtrDat->intNRegistrosDat,
		&pSArgsSisPtrDat->LCSiscomPro2Dat,
		&pSArgsSisPtrDat->LCSiscomPro2DatUltimo);
}

void SiscomLeeEntradaOperaciones2ConConfiguracion(SArgsSiscom *pSArgsSisPtrDat)
{
	SiscomLeeInformacionProtocolo2(
		pSArgsSisPtrDat->intSocketCliente,
		pSArgsSisPtrDat->intNRegistrosDat,
		"Configuracion",
		&pSArgsSisPtrDat->LCSiscomPro2DatConfig,
		&pSArgsSisPtrDat->LCSiscomPro2Dat);
}
void SiscomCopiaArgumentosConsulta(SArgsSiscom *pSArgsSisPtrDat)
{
	SiscomCopiaDatosProtocoloCharChar(
		pSArgsSisPtrDat->LCSiscomPro2Dat,
		pSArgsSisPtrDat->intNRegistrosDat,
		"Parametro",
		&pSArgsSisPtrDat->chrPtrArgConsulta);

}
void SiscomCopiaArgumentosConsultaSubRegistros(SArgsSiscom *pSAgsSiscom)
{
  SiscomCopiaDatosPrincipalProtocoloSubRegCharChar(
  		pSAgsSiscom->LCSiscomPro2SREntrada,
		pSAgsSiscom->intNRegistrosDat,
		"Parametro",
		&pSAgsSiscom->chrPtrArgConsulta);
}
void SiscomAnexaArgumentoConsulta(const char *pchrPtrArgumento,
				  SArgsSiscom *pSAgsSiscom)
{
char **lchrPtrArgumentos=pSAgsSiscom->chrPtrArgConsulta;
char **lchrPtrPaso=lchrPtrArgumentos;
int lintNArgumentos;
	while(*lchrPtrArgumentos)
	 lchrPtrArgumentos++;
   *lchrPtrArgumentos=strdup(pchrPtrArgumento);
   lintNArgumentos=(lchrPtrArgumentos-lchrPtrPaso)+1; 
   lchrPtrPaso=(char **)realloc(lchrPtrPaso,(lintNArgumentos+1)*sizeof(char *));
   *(lchrPtrPaso+lintNArgumentos)=0;
   pSAgsSiscom->chrPtrArgConsulta=lchrPtrPaso;
}

int SiscomCuantasOperaciones(SiscomOperaciones2 *pSisOps2)
{
int lintContador;
	for(lintContador=0;
	    pSisOps2[lintContador];
	    lintContador++);
	 return lintContador;
}
void SiscomAnexaOperacionAlArreglo2(SiscomOperaciones2 pSisOperacion,
				    SiscomOperaciones2 *pSisOperaciones)
{
int lintContador;
	for(lintContador=0; pSisOperaciones[lintContador];lintContador++);
	 pSisOperaciones[lintContador]=pSisOperacion;
	 pSisOperaciones[lintContador+1]=0;
}

void SiscomAnexaOperacionAlArreglo21(SiscomOperaciones2 pSisOperacion,
				    SiscomOperaciones2 *pSisOperaciones,
				    int *pintPtrNumOperacion)
{
  SiscomLog("La Operacion %x",pSisOperacion);
    *(pSisOperaciones+(*pintPtrNumOperacion))=pSisOperacion;
    (*pintPtrNumOperacion)++;
}
void SiscomAnexaOperacionAlArreglo(SiscomOperaciones2 pSisOp,
				   SiscomOperaciones2 **pSisOps2)
{
int lintNOperaciones=0;

	if(*pSisOps2)
	lintNOperaciones=SiscomCuantasOperaciones(*pSisOps2);
	if(!lintNOperaciones)
	*pSisOps2=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2));
	else
	 *pSisOps2=(SiscomOperaciones2 *)realloc(*pSisOps2,
	 					 sizeof(SiscomOperaciones2)*
						 (lintNOperaciones));
	
	(*pSisOps2)[lintNOperaciones]=pSisOp;
	(*pSisOps2)[lintNOperaciones+1]=0;
}
void SiscomAsignaMemoriaArgumentosOperaciones(int pintNumArgumentos,
					      SArgsSiscom *pSAgsSiscom)
{

pSAgsSiscom->SArgOperacion=(SArgumentoOperacion *)malloc(sizeof(SArgumentoOperacion)*
							 (pintNumArgumentos+1));
memset(pSAgsSiscom->SArgOperacion,
	sizeof(SArgumentoOperacion)*(pintNumArgumentos+1),
	0);

				
pSAgsSiscom->SArgOperacion->intNumArgumentos=pintNumArgumentos;				
}
void SiscomIniciaMemoriaArgumentoOperacion(int pintNArgumento,
					   const char *pchrPtrNombre,
					   SArgsSiscom *pSAgsSiscom)
{
	strcpy(((pSAgsSiscom->SArgOperacion)+pintNArgumento)->chrArrNombre,
		pchrPtrNombre);
	((pSAgsSiscom->SArgOperacion)+pintNArgumento)->LCSiscomPro2Act=0;
	((pSAgsSiscom->SArgOperacion)+pintNArgumento)->LCSiscomPro2Prim=0;
	((pSAgsSiscom->SArgOperacion)+pintNArgumento)->intNumRegistros=0;

}
LCamposSiscomPro2 *SiscomArgumentoOperacionPrim(const char *pchrPtrArgumento,
							SArgsSiscom *pSAgsSiscom)
{
int lintContador;

	for(lintContador=0;
	    lintContador<pSAgsSiscom->SArgOperacion->intNumArgumentos;
	    lintContador++)
	 if(!strcmp(((pSAgsSiscom->SArgOperacion)+lintContador)->chrArrNombre,
	 	    pchrPtrArgumento))
	  return ((pSAgsSiscom->SArgOperacion)+lintContador)->LCSiscomPro2Prim;
	  return 0;
}
LCamposSiscomPro2 *SiscomArgumentoOperacionAct(const char *pchrPtrArgumento,
							SArgsSiscom *pSAgsSiscom)
{
int lintContador;

	for(lintContador=0;
	    lintContador<pSAgsSiscom->SArgOperacion->intNumArgumentos;
	    lintContador++)
	 if(!strcmp(((pSAgsSiscom->SArgOperacion)+lintContador)->chrArrNombre,
	 	    pchrPtrArgumento))
	  return ((pSAgsSiscom->SArgOperacion)+lintContador)->LCSiscomPro2Act;
	  return 0;
}
void SiscomAsignaArgumentoOperacionPrim(const char *pchrPtrArgumento,
					LCamposSiscomPro2 *pLCSiscomPro2Prim,
					SArgsSiscom *pSAgsSiscom)
{
int lintContador;
	for(lintContador=0;
	    lintContador<pSAgsSiscom->SArgOperacion->intNumArgumentos;
	    lintContador++)
	{
	 if(!strcmp(((pSAgsSiscom->SArgOperacion)+lintContador)->chrArrNombre,
	 	    pchrPtrArgumento))
	  ((pSAgsSiscom->SArgOperacion)+lintContador)->LCSiscomPro2Prim=pLCSiscomPro2Prim;
	}

}
void SiscomAsignaArgumentoOperacionAct(const char *pchrPtrArgumento,
					LCamposSiscomPro2 *pLCSiscomPro2Act,
					SArgsSiscom *pSAgsSiscom)
{
int lintContador;
	for(lintContador=0;
	    lintContador<pSAgsSiscom->SArgOperacion->intNumArgumentos;
	    lintContador++)
	{
	 if(!strcmp(((pSAgsSiscom->SArgOperacion)+lintContador)->chrArrNombre,
	 	    pchrPtrArgumento))
	  ((pSAgsSiscom->SArgOperacion)+lintContador)->LCSiscomPro2Act=pLCSiscomPro2Act;
	}

}
int SiscomArgumentosNumeroRegistros(const char *pchrPtrArgumento,
				    SArgsSiscom *pSAgsSiscom)
{
int lintContador;
	for(lintContador=0;
	    lintContador<pSAgsSiscom->SArgOperacion->intNumArgumentos;
	    lintContador++)
	{
	 if(!strcmp(((pSAgsSiscom->SArgOperacion)+lintContador)->chrArrNombre,
	 	    pchrPtrArgumento))
	  return ((pSAgsSiscom->SArgOperacion)+lintContador)->intNumRegistros;
	}

}
void SiscomAsignaArgumentoNumeroRegistros(const char *pchrPtrArgumento,
					  int pintNumRegistros,
					  SArgsSiscom *pSAgsSiscom)
{
int lintContador;
	for(lintContador=0;
	    lintContador<pSAgsSiscom->SArgOperacion->intNumArgumentos;
	    lintContador++)
	{
	 if(!strcmp(((pSAgsSiscom->SArgOperacion)+lintContador)->chrArrNombre,
	 	    pchrPtrArgumento))
	  ((pSAgsSiscom->SArgOperacion)+lintContador)->intNumRegistros=pintNumRegistros;
	}

}
void AsignaEstadoInsercion(LCamposSiscomPro2 *pLCSiscomPro2SQL,
			   LCamposSiscomPro2 *pLCSiscomPro2RegSQL)
{
while(pLCSiscomPro2SQL)
{
	SiscomAsignaDatoCampo2(
		"EdoRegistro",
		SiscomObtenDato(pLCSiscomPro2RegSQL,"EdoRegistro"),
		pLCSiscomPro2SQL);
pLCSiscomPro2RegSQL=pLCSiscomPro2RegSQL->SCP2PtrSig;
pLCSiscomPro2SQL=pLCSiscomPro2SQL->SCP2PtrSig;
}
}
void SiscomEjecutaRegistroInformacion(SArgsSiscom *pSAgsSiscom,
				      const char *pchrPtrArgumento,
				      LCamposSiscomPro2 **pLCSiscomPro2Res,
				      int *pintPtrNRespuesta)
{
char *lchrPtrEdoConexion;
int lintSocket;
LCamposSiscomPro2 *lLCSiscomPro2Dat;
SiscomInformacionServidorConRespuesta(
	pSAgsSiscom->intPtoComAD,
	pSAgsSiscom->chrArrDirIpAD,
	"Inserciones",
	SiscomArgumentosNumeroRegistros(pchrPtrArgumento,pSAgsSiscom),
	(lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim(pchrPtrArgumento,pSAgsSiscom)),
	&lchrPtrEdoConexion,
	&lintSocket,
	pLCSiscomPro2Res,
	pintPtrNRespuesta);
AsignaEstadoInsercion(lLCSiscomPro2Dat,
		      *pLCSiscomPro2Res);
}

char *SiscomEjecutaRegistroInformacion2(int pintPtoComAd,
					const char *pchrPtrDirIpAd,
				     SArgsSiscom *pSAgsSiscom,
				      const char *pchrPtrArgumento,
				      LCamposSiscomPro2 **pLCSiscomPro2Res,
				      int *pintPtrNRespuesta)
{
char *lchrPtrEdoConexion;
int lintSocket;
LCamposSiscomPro2 *lLCSiscomPro2Dat;
SiscomInformacionServidorConRespuesta(
	pintPtoComAd,
	pchrPtrDirIpAd,
	"Inserciones",
	SiscomArgumentosNumeroRegistros(pchrPtrArgumento,pSAgsSiscom),
	(lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim(pchrPtrArgumento,pSAgsSiscom)),
	&lchrPtrEdoConexion,
	&lintSocket,
	pLCSiscomPro2Res,
	pintPtrNRespuesta);
if(!lchrPtrEdoConexion)
AsignaEstadoInsercion(lLCSiscomPro2Dat,
		      *pLCSiscomPro2Res);
return lchrPtrEdoConexion;
}
void SiscomObtenInformacionArgumento(const char *pchrPtrArgumento,
				     SArgsSiscom *pSAgsSiscom,
				     LCamposSiscomPro2 **pLCSiscomPro2Prim,
				     LCamposSiscomPro2 **pLCSiscomPro2Act,
				     int *pintPtrNRegistros)
{
	if(pLCSiscomPro2Prim)
	*pLCSiscomPro2Prim=SiscomArgumentoOperacionPrim(pchrPtrArgumento,pSAgsSiscom);
	if(pLCSiscomPro2Act)
	*pLCSiscomPro2Act=SiscomArgumentoOperacionAct(pchrPtrArgumento,pSAgsSiscom);
	if(pintPtrNRegistros)
	*pintPtrNRegistros=SiscomArgumentosNumeroRegistros(pchrPtrArgumento,pSAgsSiscom);
}
void SiscomAsignaInformacionArgumento(const char *pchrPtrArgumento,
				      SArgsSiscom *pSAgsSiscom,
				      LCamposSiscomPro2 *pLCSiscomPro2Prim,
				      LCamposSiscomPro2 *pLCSiscomPro2Act,
				      int pintNRegistros)
{
	SiscomAsignaArgumentoOperacionAct(pchrPtrArgumento,pLCSiscomPro2Act,pSAgsSiscom);
	SiscomAsignaArgumentoOperacionPrim(pchrPtrArgumento,pLCSiscomPro2Prim,pSAgsSiscom);
	SiscomAsignaArgumentoNumeroRegistros(pchrPtrArgumento,pintNRegistros,pSAgsSiscom);
}
void SiscomEjecutaConsultaYResponde(SArgsSiscom *pSAgsSiscom,
			            const char *pchrPtrConsultaSQL)
{
LCamposSiscomPro2 *lLCSiscomPro2Regreso=0;
int lintNRegRespuesta=0;
	SiscomConsultaBaseDatosSinDatosConexion(
		pchrPtrConsultaSQL,
		pSAgsSiscom->chrArrDirIpAD,
		pSAgsSiscom->intPtoComAD,
		&lLCSiscomPro2Regreso,
		&lintNRegRespuesta);
	if(lLCSiscomPro2Regreso)
	SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
			      lintNRegRespuesta,
			      "Respuesta",
			      lLCSiscomPro2Regreso);
	else
	SiscomLog("SiscomEjecutaConsultaYResponde:La consulta no genero Informacion");
}



void SiscomGeneraInsercionActualizacion(SArgsSiscom *pSAgsSiscom,
				  const char *pchrPtrArgumento,
				  void (*GeneraSQL)(LCamposSiscomPro2 *,
				  		    LCamposSiscomPro2 **,
				  		    LCamposSiscomPro2 **,
						    int *))
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct;
int lintNRegistros;
SiscomObtenInformacionArgumento(pchrPtrArgumento,
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
GeneraSQL(pSAgsSiscom->LCSiscomPro2Dat,
	  &lLCSiscomPro2SQLPrim,
	  &lLCSiscomPro2SQLAct,
	  &lintNRegistros);
SiscomAsignaInformacionArgumento(pchrPtrArgumento,
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);
}

void SiscomGeneraInsercionActualizacionCiclo(SArgsSiscom *pSAgsSiscom,
				  const char *pchrPtrArgumento,
				  void (*GeneraSQL)(LCamposSiscomPro2 *,
				  		    LCamposSiscomPro2 **,
				  		    LCamposSiscomPro2 **,
						    int *))
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct;
int lintNRegistros;
LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
SiscomObtenInformacionArgumento(pchrPtrArgumento,
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
while(lLCSiscomPro2Dat)
{
GeneraSQL(lLCSiscomPro2Dat,
	  &lLCSiscomPro2SQLPrim,
	  &lLCSiscomPro2SQLAct,
	  &lintNRegistros);
SiscomAsignaInformacionArgumento(pchrPtrArgumento,
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);
lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;
}
}

void SiscomGeneraInsercionActualizacion2(SArgsSiscom *pSAgsSiscom,
				  const char *pchrPtrArgumento,
				  void (*GeneraSQL)(LCamposSiscomPro2 *,
				  		    LCamposSiscomPro2 *,
				  		    LCamposSiscomPro2 **,
				  		    LCamposSiscomPro2 **,
						    int *))
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct;
int lintNRegistros;
SiscomObtenInformacionArgumento(pchrPtrArgumento,
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
GeneraSQL(pSAgsSiscom->LCSiscomPro2Dat,
	  pSAgsSiscom->LCSiscomPro2DatUltimo,
	  &lLCSiscomPro2SQLPrim,
	  &lLCSiscomPro2SQLAct,
	  &lintNRegistros);
SiscomAsignaInformacionArgumento(pchrPtrArgumento,
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);



}
void SiscomGeneraInsercionActualizacion2A(SArgsSiscom *pSAgsSiscom,
				  const char *pchrPtrArgumentoEnt,
				  const char *pchrPtrArgumentoSal,
				  void (*GeneraSQL)(LCamposSiscomPro2 *,
				  		    LCamposSiscomPro2 **,
				  		    LCamposSiscomPro2 **,
						    int *))
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct=0;
LCamposSiscomPro2 *lLCSiscomPro2DatEntPrim=0,
		  *lLCSiscomPro2DatEntAct=0;
int lintNRegistros,
    lintNRegistrosEnt;
SiscomObtenInformacionArgumento(pchrPtrArgumentoEnt,
				pSAgsSiscom,
				&lLCSiscomPro2DatEntPrim,
				&lLCSiscomPro2DatEntAct,
				&lintNRegistrosEnt);
SiscomObtenInformacionArgumento(pchrPtrArgumentoSal,
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
GeneraSQL(lLCSiscomPro2DatEntPrim,
	  &lLCSiscomPro2SQLPrim,
	  &lLCSiscomPro2SQLAct,
	  &lintNRegistros);
SiscomAsignaInformacionArgumento(pchrPtrArgumentoSal,
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);
}

void SiscomGeneraInsercionActualizacionReCorreArgEntrada(SArgsSiscom *pSAgsSiscom,
				  const char *pchrPtrArgumentoEnt,
				  const char *pchrPtrArgumentoSal,
				  char *pchrPtrBufferSql,
				  void (*GeneraSQL)(SArgsSiscom *,
				  		    LCamposSiscomPro2 *,
						    char *))
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct=0;
LCamposSiscomPro2 *lLCSiscomPro2DatEntPrim=0,
		  *lLCSiscomPro2DatEntAct=0;
int lintNRegistros,
    lintNRegistrosEnt;
SiscomObtenInformacionArgumento(pchrPtrArgumentoEnt,
				pSAgsSiscom,
				&lLCSiscomPro2DatEntPrim,
				&lLCSiscomPro2DatEntAct,
				&lintNRegistrosEnt);
SiscomObtenInformacionArgumento(pchrPtrArgumentoSal,
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
for(;
    lLCSiscomPro2DatEntPrim;
    lLCSiscomPro2DatEntPrim=lLCSiscomPro2DatEntPrim->SCP2PtrSig)
{
GeneraSQL(pSAgsSiscom,lLCSiscomPro2DatEntPrim,pchrPtrBufferSql);
SiscomAnexaRegistroPro2(
		&lLCSiscomPro2SQLPrim,
		&lLCSiscomPro2SQLAct,
		&lintNRegistros,
		"ComandoSQL,EdoRegistro",
		pchrPtrBufferSql,
		"");
}
SiscomAsignaInformacionArgumento(pchrPtrArgumentoSal,
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);
}


void SiscomEnviaServidorArgumento(SArgsSiscom *pSAgsSiscom,
				  const char *pchrPtrArgumento)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta;
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 pchrPtrArgumento,
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);
SiscomContenidoProtocolo(lLCSiscomPro2Reg);
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      1,
		      "Respuesta",
		      pSAgsSiscom->LCSiscomPro2Dat);

}

void SiscomMemoriaOperaciones2(int pintNOperaciones,
			       SiscomOperaciones2 **pSisOperaciones2)
{

*pSisOperaciones2=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*pintNOperaciones);

/*
 *
 *
 * Tepotzotlan Mexico Sabado 20 de septiembre 2008
 * En el proceso de integracion del manejo de mansajes remotos
 * para la interfaz grafica (Prototipo gaseras , sistema base
 * SiscomTiendas4 ), al asignar memoria para el arreglo de apuntadores
 * a funciones, y no iniciarse a cero cada uno de los elementos
 * a la hora de realizar la asignacion de cada una de las funciones
 * para el proceso, se realiza una validacion vs 0, lo cual impedia
 * la asignacion del valor correcto, por tal motivo se agrego la 
 * inicializacion a cero de cada uno de los elementos de la matriz.
 *
 */

 memset(*pSisOperaciones2,0,sizeof(SiscomOperaciones2)*pintNOperaciones);
}

void SiscomGeneraIdRegistro(SArgsSiscom *pSAgsSiscom,
			    const char *pchrPtrNmbCampo)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
char lchrArrIdRegistro[12];
  SiscomObtenNumeroUnicoChar(lchrArrIdRegistro);
  SiscomAsignaDatoCampo2(pchrPtrNmbCampo,	
  			 lchrArrIdRegistro,
			 lLCSiscomPro2Dat);
}

void SiscomConsultaBaseSinEnvio(const char *pchrPtrSql,
				SArgsSiscom *pSAgsSiscom,
			        int *pintPtrNRegistros,
				LCamposSiscomPro2 **pLCSiscomPro2Reg)
{

SiscomConsultaBaseDatosSinDatosConexion(
		pchrPtrSql,
		pSAgsSiscom->chrArrDirIpAD,
		pSAgsSiscom->intPtoComAD,
		pLCSiscomPro2Reg,
		pintPtrNRegistros);
}

void SiscomConsultaBaseSinEnvio2(const char *pchrPtrSql,
				SArgsSiscom *pSAgsSiscom)
{
SiscomConsultaBaseDatosSinDatosConexion(
		pchrPtrSql,
		pSAgsSiscom->chrArrDirIpAD,
		pSAgsSiscom->intPtoComAD,
		&pSAgsSiscom->LCSiscomPro2Regreso,
		&pSAgsSiscom->intNumRegRegreso);
}

void SiscomEnviaRegreso2(SArgsSiscom *pSAgsSiscom,
			 const char *pchrPtrRespuesta)
{
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      pSAgsSiscom->intNumRegRegreso,
		      pchrPtrRespuesta,
		      pSAgsSiscom->LCSiscomPro2Regreso);
}
void SiscomEnviaRegreso(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      pSAgsSiscom->intNumRegRegreso,
		      "Respuesta",
		      pSAgsSiscom->LCSiscomPro2Regreso);
}

void SiscomEnviaArgumentoCliente(const char *pchrPtrArgumento,
				 SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2ArgPrim,
		  *lLCSiscomPro2ArgAct;
int lintNRegArgumento;
SiscomObtenInformacionArgumento(pchrPtrArgumento,
				pSAgsSiscom,
				&lLCSiscomPro2ArgPrim,
				&lLCSiscomPro2ArgAct,
				&lintNRegArgumento);
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      lintNRegArgumento,
		      "Respuesta",
		      lLCSiscomPro2ArgPrim);
}


void SiscomEnviaArgumentosCliente(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;

int lintNRegArgumento;
int lintContador;
for(lintContador=0; 
    lintContador<pSAgsSiscom->SArgOperacion->intNumArgumentos;
    lintContador++)
{
  if((lLCSiscomPro2Dat=((pSAgsSiscom->SArgOperacion)+lintContador)->LCSiscomPro2Prim))
  {
      while(lLCSiscomPro2Dat)
      {
	SiscomCreaListaCamposPro2(lLCSiscomPro2Dat->SCSiscomPro2,
				  &pSAgsSiscom->LCSiscomPro2Regreso,
				  &pSAgsSiscom->LCSiscomPro2RegAct);
	pSAgsSiscom->intNumRegRegreso++;
	lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;
      }

  }

}
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
 		      pSAgsSiscom->intNumRegRegreso,
 		      "Respuesta",
   		      pSAgsSiscom->LCSiscomPro2Regreso);
}
/* Miercoles 25 de Septiembre del 2013 
 * La funcion envia pchrPtrArgumento para ejecutar inserts/update's, y actualizara
 * de regreso el campo EdoRegistro
 */
void SiscomEnviaArgumentoParaRegistro(const char *pchrPtrArgumento,SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
LCamposSiscomPro2 *lLCSiscomPro2EnvioPrim=0,
		  *lLCSiscomPro2EnvioAct=0,
		  *lLCSiscomPro2Regreso=0;
int lintNRegsEnvio=0;
int lintNRegArgumento;
int lintContador;
int lintNRegRegreso;
char *lchrPtrEdoConexion;

  if((lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim(pchrPtrArgumento,pSAgsSiscom)))
  {
      while(lLCSiscomPro2Dat)
      {
	SiscomCreaListaCamposPro2(lLCSiscomPro2Dat->SCSiscomPro2,
				  &lLCSiscomPro2EnvioPrim,
				  &lLCSiscomPro2EnvioAct);
	lintNRegsEnvio++;
	lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;
      }
  }
SiscomInformacionServidorConRespuesta(pSAgsSiscom->intPtoComAD,
				      pSAgsSiscom->chrArrDirIpAD,
				      "Inserciones",
				      lintNRegsEnvio,
				      lLCSiscomPro2EnvioPrim,
				      &lchrPtrEdoConexion,
				      &pSAgsSiscom->intSocketAccesoDatos,
				      &lLCSiscomPro2Regreso,
				      &lintNRegRegreso);

SiscomAsignaEdoRegistroEnvio(lLCSiscomPro2Regreso,SiscomArgumentoOperacionPrim(pchrPtrArgumento,pSAgsSiscom));
}
void SiscomAsignaEdoRegistroEnvio(LCamposSiscomPro2 *pLCSiscomPro2Resp,
					LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
while(pLCSiscomPro2Dat)
{
   SiscomAsignaDatoCampo2("EdoRegistro",
   			  SiscomObtenDato(pLCSiscomPro2Resp,"EdoRegistro"),
			  pLCSiscomPro2Dat);
   pLCSiscomPro2Resp=pLCSiscomPro2Resp->SCP2PtrSig;
   pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig;
}
}
					
void SiscomEnviaArgumentosPorNombreParaRegistro(char *pchrPtrArgumentos[],
						SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
LCamposSiscomPro2 *lLCSiscomPro2EnvioPrim=0,
		  *lLCSiscomPro2EnvioAct=0;
int lintNRegsEnvio=0;
int lintNRegArgumento;
int lintContador;
char *lchrPtrEdoConexion;
for(lintContador=0; 
    pchrPtrArgumentos[lintContador];
    lintContador++)
{
  if((lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim(pchrPtrArgumentos[lintContador],pSAgsSiscom)))
  {
      while(lLCSiscomPro2Dat)
      {
	SiscomCreaListaCamposPro2(lLCSiscomPro2Dat->SCSiscomPro2,
				  &lLCSiscomPro2EnvioPrim,
				  &lLCSiscomPro2EnvioAct);
	lintNRegsEnvio++;
	lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;
      }
  }
}
SiscomInformacionServidorConRespuesta(pSAgsSiscom->intPtoComAD,
				      pSAgsSiscom->chrArrDirIpAD,
				      "Inserciones",
				      lintNRegsEnvio,
				      lLCSiscomPro2EnvioPrim,
				      &lchrPtrEdoConexion,
				      &pSAgsSiscom->intSocketAccesoDatos,
				      &pSAgsSiscom->LCSiscomPro2Regreso,
				      &pSAgsSiscom->intNRegistrosRes);
}

void SiscomEnviaArgumentosParaRegistro(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
LCamposSiscomPro2 *lLCSiscomPro2EnvioPrim=0,
		  *lLCSiscomPro2EnvioAct=0;
int lintNRegsEnvio=0;
int lintNRegArgumento;
int lintContador;
char *lchrPtrEdoConexion;
for(lintContador=0; 
    lintContador<pSAgsSiscom->SArgOperacion->intNumArgumentos;
    lintContador++)
{
  if((lLCSiscomPro2Dat=((pSAgsSiscom->SArgOperacion)+lintContador)->LCSiscomPro2Prim))
  {
      while(lLCSiscomPro2Dat)
      {
	SiscomCreaListaCamposPro2(lLCSiscomPro2Dat->SCSiscomPro2,
				  &lLCSiscomPro2EnvioPrim,
				  &lLCSiscomPro2EnvioAct);
	lintNRegsEnvio++;
	lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;
      }
  }
}
SiscomInformacionServidorConRespuesta(pSAgsSiscom->intPtoComAD,
				      pSAgsSiscom->chrArrDirIpAD,
				      "Inserciones",
				      lintNRegsEnvio,
				      lLCSiscomPro2EnvioPrim,
				      &lchrPtrEdoConexion,
				      &pSAgsSiscom->intSocketAccesoDatos,
				      &pSAgsSiscom->LCSiscomPro2Regreso,
				      &pSAgsSiscom->intNRegistrosRes);

}
int SiscomConsultaBaseAsignaArgumento(
		const char *pchrPtrArgumento,
		const char *pchrPtrSql,
		SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNumRegRes;
SiscomConsultaBaseDatosSinDatosConexion(
	pchrPtrSql,
	pSAgsSiscom->chrArrDirIpAD,
	pSAgsSiscom->intPtoComAD,
	&lLCSiscomPro2Reg,
	&lintNumRegRes);
SiscomAsignaArgumentoOperacionPrim(pchrPtrArgumento,lLCSiscomPro2Reg,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros(pchrPtrArgumento,lintNumRegRes,pSAgsSiscom);
return lintNumRegRes;
}

/* Viernes 20 de Septiembre del 2013 
 * Esta funcion agregara los campos de pLCSiscomPro2Dat al
 * campo de regreso de la estructura pSAgsSiscom
 * 
 */

void SiscomAnexaRegistroRegreso2(SArgsSiscom *pSAgsSiscom,
				 LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
SiscomCreaListaCamposPro2(pLCSiscomPro2Dat->SCSiscomPro2,
			  &pSAgsSiscom->LCSiscomPro2Regreso,
			  &pSAgsSiscom->LCSiscomPro2RegAct);
pSAgsSiscom->intNumRegRegreso++;
}

void SiscomAnexaRegistroRegreso(SArgsSiscom *pSAgsSiscom,
				const char *pchrPtrFormato,
				...)
{
va_list lVLArg;
char **lchrPtrNmbCampos;
char *lchrPtrBuffer=(char *)malloc(strlen(pchrPtrFormato)+1);
SCampoSiscomPro2 *lSCSiscomPro2;
int lintContador,
    lintNCampos;
pSAgsSiscom->intNumRegRegreso++;
	if((lintNCampos=SiscomAnalizaCadenas(pchrPtrFormato,
				',',
				lchrPtrBuffer,
				&lchrPtrNmbCampos)))
	{
	 EliminaCaracteresNoValidosCampos(lchrPtrNmbCampos);	 
	 lSCSiscomPro2=(SCampoSiscomPro2 *)malloc(sizeof(SCampoSiscomPro2)*(lintNCampos+1)); 
	 lSCSiscomPro2->intNumCampos=lintNCampos;
	 SiscomAsignaDatosCampoAlCampo(lchrPtrNmbCampos,lSCSiscomPro2);
	 va_start(lVLArg,pchrPtrFormato);
	 for(lintContador=0;
	     lintContador<lintNCampos;
	     lintContador++)
	  SiscomAsignaDatoCampo(lchrPtrNmbCampos[lintContador],
				lintNCampos,
				va_arg(lVLArg,char *),
				lSCSiscomPro2); 

	 SiscomCreaListaCamposPro2(lSCSiscomPro2,
				   &pSAgsSiscom->LCSiscomPro2Regreso,
				   &pSAgsSiscom->LCSiscomPro2RegAct);
	 va_end(lVLArg);
	}
}


void SiscomAnexaRegistroArgumento(
				const char *pchrPtrArgumento,
				SArgsSiscom *pSAgsSiscom,
				const char *pchrPtrFormato,
				...)
{
va_list lVLArg;
char **lchrPtrNmbCampos;
char *lchrPtrBuffer=(char *)malloc(strlen(pchrPtrFormato)+1);
SCampoSiscomPro2 *lSCSiscomPro2;
LCamposSiscomPro2 *lLCSiscomPro2ArgPrim,
		  *lLCSiscomPro2ArgAct,
		  *lLCSiscomPro2EdoPrim;
int lintNRegArgumento;
int lintContador,
    lintNCampos;

SiscomObtenInformacionArgumento(pchrPtrArgumento,
				pSAgsSiscom,
				&lLCSiscomPro2ArgPrim,
				&lLCSiscomPro2ArgAct,
				&lintNRegArgumento);
lLCSiscomPro2EdoPrim=lLCSiscomPro2ArgPrim;
lintNRegArgumento++;
	if((lintNCampos=SiscomAnalizaCadenas(pchrPtrFormato,
				',',
				lchrPtrBuffer,
				&lchrPtrNmbCampos)))
	{
	 EliminaCaracteresNoValidosCampos(lchrPtrNmbCampos);	 
	 lSCSiscomPro2=(SCampoSiscomPro2 *)malloc(sizeof(SCampoSiscomPro2)*(lintNCampos+1)); 
	 lSCSiscomPro2->intNumCampos=lintNCampos;
	 SiscomAsignaDatosCampoAlCampo(lchrPtrNmbCampos,lSCSiscomPro2);
	 va_start(lVLArg,pchrPtrFormato);
	 for(lintContador=0;
	     lintContador<lintNCampos;
	     lintContador++)
	  SiscomAsignaDatoCampo(lchrPtrNmbCampos[lintContador],
				lintNCampos,
				va_arg(lVLArg,char *),
				lSCSiscomPro2); 
	 SiscomCreaListaCamposPro2(lSCSiscomPro2,
				   &lLCSiscomPro2ArgPrim,
				   &lLCSiscomPro2ArgAct);
	 va_end(lVLArg);
	}
	SiscomAsignaInformacionArgumento(pchrPtrArgumento,
					 pSAgsSiscom,
					 lLCSiscomPro2ArgPrim,
					 lLCSiscomPro2ArgAct,
					 lintNRegArgumento);
}

void SiscomConsultaBaseDatos2(const char *pchrPtrBase,
			      const char *pchrPtrPuertoBD,
			      const char *pchrPtrSql,
			      SArgsSiscom *pSAgsSiscom)
{
char *lchrPtrOperacionRes;
char *lchrPtrEdoConexion;
int lintNRegistros=0;
int lintSocket;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
		  *lLCSiscomPro2InsAct=0;
		*lchrPtrEdoConexion=0;
		*lchrPtrOperacionRes=0;
	   pSAgsSiscom->LCSiscomPro2Regreso=0; 
	     SiscomAnexaRegistroPro2(
			&lLCSiscomPro2Ins,
                        &lLCSiscomPro2InsAct,
                        &lintNRegistros, 
			"ConsultaSQL,		\
			 BaseDatos,		\
			 PtoBaseDatos",
			pchrPtrSql,
			pchrPtrBase,
			pchrPtrPuertoBD);
	SiscomInformacionServidor(pSAgsSiscom->intPtoComAD,
				  pSAgsSiscom->chrArrDirIpAD,
				  "Consultas",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocket); 
	if(!*lchrPtrEdoConexion)
	{	
	SiscomLeeNumeroRegistros(lintSocket,
				 &pSAgsSiscom->intNumRegRegreso);
	SiscomLeeOperacion(lintSocket,
			   &lchrPtrOperacionRes);
	SiscomLeeInformacionProtocolo(lintSocket,
				      pSAgsSiscom->intNumRegRegreso,
				      &pSAgsSiscom->LCSiscomPro2Regreso);
	 if(pSAgsSiscom->LCSiscomPro2Regreso)
	  SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
	  			pSAgsSiscom->intNumRegRegreso,
				"Respuesta",
				pSAgsSiscom->LCSiscomPro2Regreso);
	}
}
float SiscomObtenCampoArgumentoFloat(const char *pchrPtrArgumento,
				      const char *pchrPtrCampo,
				      SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Act;
if((lLCSiscomPro2Act=SiscomArgumentoOperacionAct(pchrPtrArgumento,pSAgsSiscom)))
return atof(SiscomObtenDato(lLCSiscomPro2Act,pchrPtrCampo));
else
{
SiscomLog("NO se encontro el campo %s",pchrPtrCampo);
return 0;
}
}
LCamposSiscomPro2 *SiscomSiguienteRegistroArgumento(const char *pchrPtrArgumento,
				      SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Act;

if((lLCSiscomPro2Act=SiscomArgumentoOperacionAct(pchrPtrArgumento,pSAgsSiscom)))
{
lLCSiscomPro2Act=lLCSiscomPro2Act->SCP2PtrSig;
SiscomAsignaArgumentoOperacionAct(pchrPtrArgumento,
				  lLCSiscomPro2Act,
				  pSAgsSiscom);
return lLCSiscomPro2Act;
}
else
{
SiscomLog("No se encontro el argumento:%s",pchrPtrArgumento);
return 0;
}
}
void SiscomPonPrimerRegistroArgumento(const char *pchrPtrArgumento,
				      SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim;

if((lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim(pchrPtrArgumento,pSAgsSiscom)))
SiscomAsignaArgumentoOperacionAct(pchrPtrArgumento,lLCSiscomPro2Prim,pSAgsSiscom);
else
SiscomLog("No se encontro el argumento:%s",pchrPtrArgumento);
}
const char *SiscomObtenCampoArgumento(const char *pchrPtrArgumento,
				      const char *pchrPtrCampo,
				      SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Act;
if((lLCSiscomPro2Act=SiscomArgumentoOperacionAct(pchrPtrArgumento,pSAgsSiscom)))
return SiscomObtenDato(lLCSiscomPro2Act,pchrPtrCampo);


return 0;
}
float SiscomObtenCampoArgumentoFloat2(const char *pchrPtrArgumento,
				      const char *pchrPtrCampo,
				      SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Act;
if((lLCSiscomPro2Act=SiscomArgumentoOperacionAct(pchrPtrArgumento,pSAgsSiscom)))
return atof(SiscomObtenDato(lLCSiscomPro2Act,pchrPtrCampo));
return 0.0;
}
/* Domingo 31 Julio 2011 
 * Estas funciones deberan revisarse ya que
 * se tendria que recorrer el apuntador al 
 * siguiente elementeo, por fuera, lo que 
 * implicaria mover el campo de la estructura
 *
 * Todo esto para las funciones que tienen que
 * ver con los datos de entrada
 */
const char *SiscomCampoDatosEntrada(const char *pchrPtrCampo,
				    SArgsSiscom *pSAgsSiscom)
{
return SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,pchrPtrCampo);
}
				  
float SiscomCampoDatosEntradaFloat(const char *pchrPtrCampo,
				    SArgsSiscom *pSAgsSiscom)
{
return SiscomObtenCampoAFloat(pSAgsSiscom->LCSiscomPro2Dat,pchrPtrCampo);
}


int SiscomRegistrosTotalesEnArgumentos(SArgsSiscom *pSAgsSiscom)
{
int lintContador; 
int lintNRegistros=0;
for(lintContador=0;
    lintContador<pSAgsSiscom->SArgOperacion->intNumArgumentos;
    lintContador++)
lintNRegistros+=((pSAgsSiscom->SArgOperacion)+lintContador)->intNumRegistros;

return lintNRegistros;
}

void SiscomRegistrosTAAsignaRegreso(SArgsSiscom *pSAgsSiscom)
{
pSAgsSiscom->intNumRegRegreso=SiscomRegistrosTotalesEnArgumentos(pSAgsSiscom);
}
void SiscomIncrementaContadorRegistrosRegreso(SArgsSiscom *pSAgsSiscom)
{
pSAgsSiscom->intNumRegRegreso++;
}

void SiscomCopiaArgumentosAArgumento(const char *pchrPtrArgSalida,
				     int pintNArgs,
				     SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2ArgPrim=0,
		  *lLCSiscomPro2ArgAct=0,
		  *lLCSiscomPro2Dat=0;

int lintNRegArgumento=0;
int lintContador;
int lintArgumentosACopiar;
if(!pintNArgs)
lintArgumentosACopiar=pSAgsSiscom->SArgOperacion->intNumArgumentos;
else
lintArgumentosACopiar=pintNArgs;
for(lintContador=0; 
    lintContador<lintArgumentosACopiar;
    lintContador++)
{
  if((lLCSiscomPro2Dat=((pSAgsSiscom->SArgOperacion)+lintContador)->LCSiscomPro2Prim))
  {
      while(lLCSiscomPro2Dat)
      {
	SiscomCreaListaCamposPro2(lLCSiscomPro2Dat->SCSiscomPro2,
				  &lLCSiscomPro2ArgPrim,
				  &lLCSiscomPro2ArgAct);
	lintNRegArgumento++;
	lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;
      }

  }

}
SiscomAsignaInformacionArgumento(pchrPtrArgSalida,
				 pSAgsSiscom,
				 lLCSiscomPro2ArgPrim,
				 lLCSiscomPro2ArgAct,
				 lintNRegArgumento);
}
SiscomCopiaAgrupadosAArgumento(const char *pchrPtrArgSalida,
			       LCamposSiscomPro2Agrupados *pLCSiscomPro2AgrDat,
			       SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2ArgPrim=0,
		  *lLCSiscomPro2ArgAct=0,
		  *lLCSiscomPro2Dat=0;

int lintNRegArgumento=0;
for(;
    pLCSiscomPro2AgrDat;
    pLCSiscomPro2AgrDat=pLCSiscomPro2AgrDat->LCSiscomPro2AgrupaS)
{
  lLCSiscomPro2Dat=pLCSiscomPro2AgrDat->LCSiscomPro2Prim;
  while(lLCSiscomPro2Dat)
  {
	SiscomCreaListaCamposPro2(lLCSiscomPro2Dat->SCSiscomPro2,
				  &lLCSiscomPro2ArgPrim,
				  &lLCSiscomPro2ArgAct);
	lintNRegArgumento++;
	lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;
  }

}

SiscomAsignaInformacionArgumento(pchrPtrArgSalida,
				 pSAgsSiscom,
				 lLCSiscomPro2ArgPrim,
				 lLCSiscomPro2ArgAct,
				 lintNRegArgumento);

}


const char *SiscomCadenaInsercionSql(SArgsSiscom *pSAgsSiscom,const char *pchrPtrFormato,...)
{
va_list lVLArg;
int lintContador=0,
    lintNRegistros=0,
    lintNRegRegreso=0;
char *lchrPtrArgumento,
	lchrPtrEdoConexion=0;
char lchrArrNumCampo[5];
LCamposSiscomPro2 *lLCSiscomPro2DatSqlEnvioPrim=0,
		  *lLCSiscomPro2DatSqlEnvioAct=0,
		  *lLCSiscomPro2Regreso=0;
	va_start(lVLArg,pchrPtrFormato);

	while(*pchrPtrFormato)
	{
	   if(*pchrPtrFormato=='%')
	   {
	   *pchrPtrFormato++;
	     switch(*pchrPtrFormato)
	     {
	     case 's':
			lchrPtrArgumento=va_arg(lVLArg,char *);
			lintContador++;
	     break;
	     }
	   }
	   *pchrPtrFormato++;
	   SiscomAnexaRegistroPro2(&lLCSiscomPro2DatSqlEnvioPrim,
				   &lLCSiscomPro2DatSqlEnvioAct,
				   &lintNRegistros,
				   "ComandoSQL,EdoRegistro",
				  lchrPtrArgumento,
				  "");
	}
	 va_end(lVLArg);
SiscomInformacionServidorConRespuesta(pSAgsSiscom->intPtoComAD,
				      pSAgsSiscom->chrArrDirIpAD,
				      "Inserciones",
				      lintNRegistros,
				      lLCSiscomPro2DatSqlEnvioPrim,
				      &lchrPtrEdoConexion,
				      &pSAgsSiscom->intSocketAccesoDatos,
				      &lLCSiscomPro2Regreso,
				      &lintNRegRegreso);
SiscomAsignaEdoRegistroEnvio(lLCSiscomPro2Regreso,lLCSiscomPro2DatSqlEnvioPrim);
return lchrPtrEdoConexion;
}
