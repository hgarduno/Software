#include <UbicacionMaterial.h>
#include <SqlUbicacionMaterial.h>
#include <SqlProductosSE.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void Estantes(int pintSocket,
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
SiscomAgregaOperacion(SqlEstantes,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoEstantes,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void UbicacionDeLaDescripcion(int pintSocket,
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
SiscomAgregaOperacion(SqlProductosSE,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoCajaProducto,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void AsignaCajaProducto(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoCajaMaterial,&lSiscomProDat);
SiscomAgregaOperacion(SqlAsignaCajaProducto,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoRegistroCajaMaterial,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void CajasMaterial(int pintSocket,
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
SiscomAgregaOperacion(SqlCajasMaterial,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoCajasMaterial,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RegistraCajaMaterial(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoCajaMaterial,&lSiscomProDat);
SiscomAgregaOperacion(AsignaIdCajaMaterial,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraCajaMaterial,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoRegistroCajaMaterial,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void AcondicionaCadena(const char *pchrPtrUbicacion,
		       char *pchrPtrSalida)
{
char lchrArrSinSaltos[128],
	lchrArrSinParentesis[128],
	lchrArrSinDosPuntos[128],
	lchrArrSinComa[128],
	lchrArrBuffer[128];
SiscomEliminaCaracterCadena('\n',(char *)pchrPtrUbicacion,lchrArrSinSaltos);
SiscomEliminaCaracterCadena(')',lchrArrSinSaltos,lchrArrSinParentesis);
SiscomEliminaCaracterCadena(':',lchrArrSinParentesis,lchrArrSinDosPuntos);
SiscomEliminaCaracterCadena(',',lchrArrSinDosPuntos,lchrArrSinComa);
SiscomEliminaEspaciosFinal(lchrArrSinComa);
SiscomEliminaEspaciosInicio4(lchrArrBuffer,lchrArrSinComa);  
strcpy(pchrPtrSalida,lchrArrSinComa);
}
int ObtenCadenaUbicacion(const char *pchrPtrUbicacion,
			  char *pchrPtrCadenaUbicacion)
{
const char *lchrPtrUbicacion=strstr(pchrPtrUbicacion,"Estante");
if(lchrPtrUbicacion)
{
 lchrPtrUbicacion+=7;
 AcondicionaCadena(lchrPtrUbicacion,pchrPtrCadenaUbicacion);
 return 1;
}
else
return 0;
}
const char *ObtenEstante(const char *pchrPtrCadenaUbicacion,
			 const char *pchrPtrUbicacion,
			 char *pchrPtrEstante)
{
int lintTamEstante=pchrPtrUbicacion-pchrPtrCadenaUbicacion;
 strncpy(pchrPtrEstante,pchrPtrCadenaUbicacion,lintTamEstante);
 *(pchrPtrEstante+lintTamEstante)=0;
 SiscomEliminaEspaciosFinal(pchrPtrEstante);
}
void ObtenCaja(const char *pchrPtrUbicacion,
	       char *pchrPtrCaja)
{
char lchrArrBuffer[128];
 strcpy(pchrPtrCaja,pchrPtrUbicacion);
SiscomEliminaEspaciosInicio4(lchrArrBuffer,pchrPtrCaja); 
   
}
void ObtenEstanteCajaProducto(SiscomRegistroProL *pSisRegProLPtrProducto,
		              const char *pchrPtrUbicacion,
			      char *pchrPtrEstante,
			      char *pchrPtrCaja)
{
char lchrArrCadenaUbicacion[256];
const char *lchrPtrCadenaUbicacion;
*pchrPtrEstante=*pchrPtrCaja=0;
 if(ObtenCadenaUbicacion(pchrPtrUbicacion,lchrArrCadenaUbicacion))
 {
      if((lchrPtrCadenaUbicacion=strstr(lchrArrCadenaUbicacion,"Caja")))
      {
      ObtenCaja(lchrPtrCadenaUbicacion+4,pchrPtrCaja);
      ObtenEstante(lchrArrCadenaUbicacion,lchrPtrCadenaUbicacion,pchrPtrEstante);
      }
      else
      strcpy(pchrPtrEstante,lchrArrCadenaUbicacion);
 }
}
void GenerandoUbicacionProducto(SiscomRegistroProL *pSisRegProPtrLProductos,
				SiscomRegistroProL **pSisRegProLPtrUbicacion)
{
const char *lchrPtrUbicacion;
char lchrArrEstante[128],lchrArrCaja[128],lchrArrBuffer[512];
SiscomRegistroProL *lSisRegProLPtrUbicacionAct=0;
int lintConUbicacion=0,lintNProductos=0;
for(;
     pSisRegProPtrLProductos;
     pSisRegProPtrLProductos=pSisRegProPtrLProductos->SiscomRegProLPtrSig)
{
   
   if((lchrPtrUbicacion=SiscomBuscaCadenaCampoRegistroProL("Bodega",
   							   "dscproducto",
							   pSisRegProPtrLProductos)))
   {
    lintConUbicacion++;
    ObtenEstanteCajaProducto(pSisRegProPtrLProductos,
    			     lchrPtrUbicacion,
			     lchrArrEstante,
			     lchrArrCaja);
    SiscomAnexaRegistroPro(pSisRegProLPtrUbicacion,
    			   &lSisRegProLPtrUbicacionAct,
			   lchrArrBuffer,
			   "CveProducto,Estante,Caja,IdEstante,IdCaja,",
    			    SiscomObtenCampoRegistroProLChar("cveproducto",
			    				     pSisRegProPtrLProductos),
			    lchrArrEstante,
			    lchrArrCaja,
			    (const char *)0,
			    (const char *)0);
   }
  lintNProductos++; 
}
LogSiscom("Se Encontraron %d Productos con ubicacion de %d Productos",
	   lintConUbicacion,
	   lintNProductos);
}
void AgregandoInsercionUbicacion(SiscomRegistroProL *pSisRegProLPtrProductos,
				  SiscomRegistroProL **pSisRegProLPtrSqlProductosPrim,
				  SiscomRegistroProL **pSisRegProLPtrSqlProductosAct)
{
char lchrArrBuffer[256],lchrArrSql[256];
InsertToUbicacionProducto(pSisRegProLPtrProductos,lchrArrSql);
SiscomAnexaRegistroPro(pSisRegProLPtrSqlProductosPrim,
		       pSisRegProLPtrSqlProductosAct,
		       lchrArrBuffer,
		       "Sql,Estado,",
		       lchrArrSql,
		       (char *)0);
}
void AgregandoCaja(int pintIdCaja,
		   SiscomRegistroProL *pSisRegProLPtrProductos,
		   SiscomRegistroProL **pSisRegProLPtrSqlProductosPrim,
		   SiscomRegistroProL **pSisRegProLPtrSqlProductosAct)
{
char lchrArrSql[256],lchrArrBuffer[256];
sprintf(lchrArrBuffer,"%d",pintIdCaja);
    SiscomActualizaCampoRegistroActual("IdCaja",lchrArrBuffer,pSisRegProLPtrProductos);
   InsertToCaja(pSisRegProLPtrProductos,lchrArrSql); 
   SiscomAnexaRegistroPro(pSisRegProLPtrSqlProductosPrim,
		          pSisRegProLPtrSqlProductosAct,
		          lchrArrBuffer,
		          "Sql,Estado,",
		          lchrArrSql,
		          (char *)0);
}
void AgregandoEstante(int pintIdEstante,
		   SiscomRegistroProL *pSisRegProLPtrProductos,
		   SiscomRegistroProL **pSisRegProLPtrSqlProductosPrim,
		   SiscomRegistroProL **pSisRegProLPtrSqlProductosAct)
{
char lchrArrSql[256],lchrArrBuffer[256];
sprintf(lchrArrBuffer,"%d",pintIdEstante);
    SiscomActualizaCampoRegistroActual("IdEstante",lchrArrBuffer,pSisRegProLPtrProductos);
   InsertToEstante(pSisRegProLPtrProductos,lchrArrSql); 
   SiscomAnexaRegistroPro(pSisRegProLPtrSqlProductosPrim,
		          pSisRegProLPtrSqlProductosAct,
		          lchrArrBuffer,
		          "Sql,Estado,",
		          lchrArrSql,
		          (char *)0);
}
const char *ObtenIdEstante(SiscomRegistroProL *pSisRegProLPtrProductoPorCaja,
			   SiscomRegistroProL *pSisRegProLPtrProductosPorEstante)
{
for(;
    pSisRegProLPtrProductosPorEstante;
    pSisRegProLPtrProductosPorEstante=pSisRegProLPtrProductosPorEstante->SiscomRegProLPtrSig)
if(!SiscomComparaCampoRegistrosProL("Estante",
				   pSisRegProLPtrProductoPorCaja,
				   pSisRegProLPtrProductosPorEstante))
return SiscomObtenCampoRegistroProLChar("IdEstante",pSisRegProLPtrProductosPorEstante);
LogSiscom("Estante *%s* NO Encontrado",
	  SiscomObtenCampoRegistroProLChar("Estante",pSisRegProLPtrProductoPorCaja));
return 0;
}
void EstanteALosProductosCaja(SiscomRegistroProL *pSisRegProLPtrProductosPorEstante,
			      SiscomRegistroProL *pSisRegProLPtrProductosPorCaja)
{
SiscomRegistroProL *lSisRegProLPtrProductos;
char *lchrPtrIdEstante;
if((lSisRegProLPtrProductos=SiscomObtenRegistrosCampoProL("Productos",
							  pSisRegProLPtrProductosPorCaja)))
{
  for(;
      lSisRegProLPtrProductos;
      lSisRegProLPtrProductos=lSisRegProLPtrProductos->SiscomRegProLPtrSig)
  {
    if(SiscomObtenCampoRegistroProLChar("Estante",lSisRegProLPtrProductos))
    {
    lchrPtrIdEstante=(char *)ObtenIdEstante(lSisRegProLPtrProductos,
    	 			    pSisRegProLPtrProductosPorEstante);
    SiscomActualizaCampoRegistroActual("IdEstante",
    					lchrPtrIdEstante,
				       	lSisRegProLPtrProductos);
    }
    else
    LogSiscom("Estante NULO");
  }
}

}
void AsignaIdsEstantes(SiscomRegistroProL *pSisRegProLPtrProductosPorEstante,
		       SiscomRegistroProL *pSisRegProLPtrProductosPorCaja)
{
char lchrArrBuffer[128];
for(;
    pSisRegProLPtrProductosPorCaja;
    pSisRegProLPtrProductosPorCaja=pSisRegProLPtrProductosPorCaja->SiscomRegProLPtrSig)
{
   EstanteALosProductosCaja(pSisRegProLPtrProductosPorEstante,
   			 pSisRegProLPtrProductosPorCaja);
}
}
void AgregandoProductosCaja(int pintIdCaja,
			    SiscomRegistroProL *pSisRegProLPtrProductos,
			    SiscomRegistroProL **pSisRegProLPtrSqlProductosPrim,
			    SiscomRegistroProL **pSisRegProLPtrSqlProductosAct)
{
char lchrArrBuffer[256],lchrArrSql[256];
SiscomRegistroProL *lSisRegProLPtrProductos;
   if((lSisRegProLPtrProductos=SiscomObtenRegistrosCampoProL("Productos",pSisRegProLPtrProductos)))
     for(;
         lSisRegProLPtrProductos;
	 lSisRegProLPtrProductos=lSisRegProLPtrProductos->SiscomRegProLPtrSig)
      {
        SiscomActualizaCampoIntRegistroActual("IdCaja",pintIdCaja,lSisRegProLPtrProductos);
	InsertToUbicacionProducto(lSisRegProLPtrProductos,lchrArrSql);
        SiscomAnexaRegistroPro(pSisRegProLPtrSqlProductosPrim,
		               pSisRegProLPtrSqlProductosAct,
		               lchrArrBuffer,
		               "Sql,Estado,",
		               lchrArrSql,
		               (char *)0);
      }
}
void GeneraSentenciasSqlUbicacion(SiscomRegistroProL *pSisRegProLPtrProductos,
				  SiscomRegistroProL **pSisRegProLPtrSqlProductosPrim,
				  SiscomRegistroProL **pSisRegProLPtrSqlProductosAct)
{
char lchrArrBuffer[256],lchrArrSql[256];
SiscomRegistroProL *lSisRegProLPtrProductos;
int lintIdCaja=100;
for(lintIdCaja=100/*,
    pSisRegProLPtrProductos=pSisRegProLPtrProductos->SiscomRegProLPtrSig*/;
     pSisRegProLPtrProductos;
     pSisRegProLPtrProductos=pSisRegProLPtrProductos->SiscomRegProLPtrSig,
     lintIdCaja++)
{
      AgregandoCaja(lintIdCaja,
      		    pSisRegProLPtrProductos,
		    pSisRegProLPtrSqlProductosPrim,
		    pSisRegProLPtrSqlProductosAct);
	AgregandoProductosCaja(lintIdCaja,
				pSisRegProLPtrProductos,
			       pSisRegProLPtrSqlProductosPrim,
			       pSisRegProLPtrSqlProductosAct);
}

}
void GeneraSentenciasSqlEstantes(SiscomRegistroProL *pSisRegProLPtrProductosPorEstante,
				  SiscomRegistroProL **pSisRegProLPtrSqlProductosPrim,
				  SiscomRegistroProL **pSisRegProLPtrSqlProductosAct)
{
int lintIdEstante;
for(lintIdEstante=0;
    pSisRegProLPtrProductosPorEstante;
    pSisRegProLPtrProductosPorEstante=pSisRegProLPtrProductosPorEstante->SiscomRegProLPtrSig,
    lintIdEstante++)
  AgregandoEstante(lintIdEstante,
  		   pSisRegProLPtrProductosPorEstante,
		   pSisRegProLPtrSqlProductosPrim,
		   pSisRegProLPtrSqlProductosAct);

}
				 
void AgrupaPorCaja(SiscomRegistroProL *pSisRegProLPtrProductos,
		   SiscomRegistroProL **pSisRegProLPtrProductosPorCaja)
{
char lchrArrBuffer[256];
SiscomRegistroProL  *lSisRegProLPtrProductosPorCajaAct=0,
		   *lSisRegProLPtrOrdenadosPrim=0,
		   *lSisRegProLPtrOrdenadosAct=0;
char *lchrPtrCamposRegistro[]={"Caja","IdCaja",0};
char *lchrPtrCampos[]={"CveProducto","Estante","Caja","IdEstante","IdCaja",0};

SiscomOrdenaRegistroProL("Caja",
			 pSisRegProLPtrProductos,
			 &lSisRegProLPtrOrdenadosPrim,
			 &lSisRegProLPtrOrdenadosAct);
SiscomAgrupaPorCampo("Caja",
		     "Productos",
		     lchrPtrCamposRegistro,
		     lchrPtrCampos,
		     lSisRegProLPtrOrdenadosPrim,
		     pSisRegProLPtrProductosPorCaja,
		     &lSisRegProLPtrProductosPorCajaAct);
}

void AgrupaPorEstante(SiscomRegistroProL *pSisRegProLPtrProductos,
		   SiscomRegistroProL **pSisRegProLPtrProductosPorEstante)
{
char lchrArrBuffer[128];
SiscomRegistroProL  *lSisRegProLPtrProductosPorEstanteAct=0,
		   *lSisRegProLPtrOrdenadosPrim=0,
		   *lSisRegProLPtrOrdenadosAct=0;
char *lchrPtrCamposRegistro[]={"Estante","IdEstante",0};
char *lchrPtrCampos[]={"CveProducto",0};
SiscomOrdenaRegistroProL("Estante",
			 pSisRegProLPtrProductos,
			 &lSisRegProLPtrOrdenadosPrim,
			 &lSisRegProLPtrOrdenadosAct);
SiscomAgrupaPorCampo("Estante",
		     "Productos",
		     lchrPtrCamposRegistro,
		     lchrPtrCampos,
		     lSisRegProLPtrOrdenadosPrim,
		     pSisRegProLPtrProductosPorEstante,
		     &lSisRegProLPtrProductosPorEstanteAct);
}
void EnviaRegistrosBaseDatos(SiscomRegistroProL *pSisRegProLPtrSqlUbicacion,
			     SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrRegEnvioBDPrim=0,
		   *lSisRegProLPtrRegEnvioBDAct=0;
SiscomRegistroEnvioBaseDatos(pSiscomOpePtrDato->chrArrBaseDatos,
			     pSiscomOpePtrDato->chrArrPuertoBaseDatos,
			     "EjecutaOperacion",
			     lchrArrBuffer,
			     &lSisRegProLPtrRegEnvioBDPrim,
			     &lSisRegProLPtrRegEnvioBDAct);

}
int EnviandoCajaProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSiscomRegProLPtrRegreso,
                   *lSisRegProLPtrUbicacion=0,
		   *lSisRegProLPtrSqlUbicacionPrim=0,
		   *lSisRegProLPtrSqlUbicacionAct=0,
		   *lSisRegProLPtrProductosPorCaja=0,
		   *lSisRegProLPtrProductosPorEstante=0;
lSiscomRegProLPtrRegreso=SiscomObtenRegistrosCampoRespuesta("Productos",pSiscomOpePtrDato);
GenerandoUbicacionProducto(lSiscomRegProLPtrRegreso,&lSisRegProLPtrUbicacion);
AgrupaPorCaja(lSisRegProLPtrUbicacion,&lSisRegProLPtrProductosPorCaja);
AgrupaPorEstante(lSisRegProLPtrUbicacion,&lSisRegProLPtrProductosPorEstante); 
GeneraSentenciasSqlEstantes(lSisRegProLPtrProductosPorEstante,
			     &lSisRegProLPtrSqlUbicacionPrim,
			     &lSisRegProLPtrSqlUbicacionAct);
AsignaIdsEstantes(lSisRegProLPtrProductosPorEstante,lSisRegProLPtrProductosPorCaja);
GeneraSentenciasSqlUbicacion(lSisRegProLPtrProductosPorCaja,
			     &lSisRegProLPtrSqlUbicacionPrim,
			     &lSisRegProLPtrSqlUbicacionAct);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrSqlUbicacionPrim); 
return 0;
}

int EnviandoRegistroCajaMaterial(SiscomOperaciones *pSiscomOpePtrDato)
{
 LogSiscom("");
}


int EnviandoCajasMaterial(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomEnviaAsociadoRespuestaCliente("CajaMaterial",
                                    lchrArrBuffer,
                                    pSiscomOpePtrDato);
return 0;
}


int EnviandoEstantes(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomEnviaAsociadoRespuestaCliente("Estantes",
                                    lchrArrBuffer,
                                    pSiscomOpePtrDato);

return 0;
}
int AsignaIdCajaMaterial(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdARegistrosAsociadosEntrada("Envio","IdCaja",pSiscomOpePtrDato);
return 0;
}

int ArgumentoCajaMaterial(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlCajaMaterial",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}
int ElCampoEsValido(const char *pchrPtrCampo,
		    SiscomRegistroProL *pSisRegProLPtrRegistro)
{
const char *lchrPtrCampo=SiscomObtenCampoRegistroProLChar(pchrPtrCampo,
							  pSisRegProLPtrRegistro);
LogSiscom("%s",lchrPtrCampo);
return lchrPtrCampo && *lchrPtrCampo ? 1 :0;

}
int EstaEstante(SiscomRegistroProL *pSisRegProLPtrProducto)
{
 return ElCampoEsValido("Estante",pSisRegProLPtrProducto);
}
int EstaCaja(SiscomRegistroProL *pSisRegProLPtrProducto)
{
 return ElCampoEsValido("Caja",pSisRegProLPtrProducto);
}
int EstaCajaYEstante(SiscomRegistroProL *pSisRegProLPtrProducto)
{
   return EstaCaja(pSisRegProLPtrProducto) &&
          EstaEstante(pSisRegProLPtrProducto) ;
}

int EstaEstantePorId(SiscomRegistroProL *pSisRegProLPtrProducto)
{
 return ElCampoEsValido("idestante",pSisRegProLPtrProducto);
}
int EstaCajaPorId(SiscomRegistroProL *pSisRegProLPtrProducto)
{
 return ElCampoEsValido("idcaja",pSisRegProLPtrProducto);
}
int EstaEstanteYCajaPorId(SiscomRegistroProL *pSisRegProLPtrProducto)
{
   return EstaCajaPorId(pSisRegProLPtrProducto) &&
          EstaEstantePorId(pSisRegProLPtrProducto) ;
}

void MuestraProductosPorCaja(const char *pchrPtrArchivo,
			     const char *pchrPtrFuncion,
			     int pintNoLinea,
			     SiscomRegistroProL *pSisRegProLPtrProdPorCaja)
{
const char *lchrPtrIdCaja;
SiscomRegistroProL *lSisRegProLPtrProductos;
for(;
    pSisRegProLPtrProdPorCaja;
    pSisRegProLPtrProdPorCaja=pSisRegProLPtrProdPorCaja->SiscomRegProLPtrSig)
{
lchrPtrIdCaja=SiscomObtenCampoRegistroProLChar("IdCaja",pSisRegProLPtrProdPorCaja) ;
lchrPtrIdCaja=lchrPtrIdCaja ? lchrPtrIdCaja : "";
SiscomMensajesLog4(pchrPtrArchivo,
		   pchrPtrFuncion,
		   pintNoLinea,
		   "Caja (%s) IdCaja (%s)",
		   SiscomObtenCampoRegistroProLChar("Caja",pSisRegProLPtrProdPorCaja),
		   lchrPtrIdCaja);
  lSisRegProLPtrProductos=SiscomObtenRegistrosCampoProL("Productos",
   							pSisRegProLPtrProdPorCaja);
  for(; 
      lSisRegProLPtrProductos;
      lSisRegProLPtrProductos=lSisRegProLPtrProductos->SiscomRegProLPtrSig)
  {
	SiscomMensajesLog4(
		pchrPtrArchivo,
		pchrPtrFuncion,
		pintNoLinea,
		"	%s	%s	%s	%s",
		SiscomObtenCampoRegistroProLChar("CveProducto",lSisRegProLPtrProductos),
		SiscomObtenCampoRegistroProLChar("Caja",lSisRegProLPtrProductos),
		SiscomObtenCampoRegistroProLChar("IdCaja",lSisRegProLPtrProductos),
		SiscomObtenCampoRegistroProLChar("Estante",lSisRegProLPtrProductos),
		SiscomObtenCampoRegistroProLChar("IdEstante",lSisRegProLPtrProductos));
  }
}
}
