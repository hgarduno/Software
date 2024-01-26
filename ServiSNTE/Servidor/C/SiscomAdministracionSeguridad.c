#include <SiscomAdministracionSeguridad.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <ComunSiscomServiSNTE.h>

#include <SqlSiscomAdministracionSeguridad.h>

#include <string.h>
void SiscomCargaMenus(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
SiscomOperacionErrores lSiscomOpeErrores={0, ERRORUsuarioInvalido, 0 };
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   pvidPtrAncla,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(ComunicacionAccesoDatos,&lSiscomProDat);
SiscomAgregaOperacion(SqlUsuarioSistema,&lSiscomProDat); 
SiscomAgregaOperacion(SiscomValidaUsuarioFirmado,&lSiscomProDat); 
SiscomAgregaOperacion(SqlSiscomMenusSistema,&lSiscomProDat);
SiscomAgregaOperacion(SiscomEnviaMenusSistema,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,lSiscomOpeErrores,lSiscomProDat); 
}
int SiscomEnviaMenusSistema(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
SiscomRegistroProL *lSiscomRegProLPtrPopupMenus=0,
		   *lSiscomRegProLPtrPopupMenusPropiedades=0,
		   *lSiscomRegProLPtrMenusSistemaPrim=0,
		   *lSiscomRegProLPtrMenusSistemaAct=0;
/*
LogSiscom("--Antes----");
SiscomAsociadoRespuestaLog("PopupMenus",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("PopupMenusPropiedades",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("OpcionesPopupMenu",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("Menus",lchrArrBuffer,pSiscomOpePtrDato);
LogSiscom("--Despues---");
*/
for(lSiscomRegProLPtrPopupMenus=SiscomRegistrosAsociadoRespuestaOperacion("PopupMenus",
									  pSiscomOpePtrDato);
   lSiscomRegProLPtrPopupMenus;
   lSiscomRegProLPtrPopupMenus=SiscomSiguienteNodoRegistroProL(lSiscomRegProLPtrPopupMenus))
{
/*
  LogSiscom("Agregando %s",
  	    SiscomObtenCampoRegistroProLChar("nombre",lSiscomRegProLPtrPopupMenus));
*/
 CreaPopupMenu(lSiscomRegProLPtrPopupMenus,
	       &lSiscomRegProLPtrMenusSistemaPrim,
	       &lSiscomRegProLPtrMenusSistemaAct);
 AgregaPropiedadesPopupMenu(lSiscomRegProLPtrPopupMenus,
 			    pSiscomOpePtrDato,
			    lSiscomRegProLPtrMenusSistemaAct);
 AgregaMenusPopupMenu(lSiscomRegProLPtrPopupMenus,
 		      pSiscomOpePtrDato,
		      lSiscomRegProLPtrMenusSistemaAct);
}
/*
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrMenusSistemaPrim);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"Menus",lSiscomRegProLPtrMenusSistemaPrim);
*/
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			  lchrArrBuffer,
			  lSiscomRegProLPtrMenusSistemaPrim);
return 0;
}
/*
 * Jueves 08 de Octubre del 2015
 * Falta considerar el envio de los id's de cada menu
 * para el caso de las actualizaciones 
 *
 */
void MenusAlPopupMenu(SiscomRegistroProL *pSiscomRegProLPtrPopupMenu,
		      SiscomRegistroProL *pSiscomRegProLPtrMenu,
		      SiscomOperaciones *pSiscomOpePtrDato,
		      SiscomRegistroProL *pSiscomRegProLPtrMenusSistemaAct,
		      SiscomRegistroProL **pSiscomRegProLPtrMenusPrim,
		      SiscomRegistroProL **pSiscomRegProLPtrMenusAct)
{
int lintEsEsteElMenu=0;
char lchrArrBuffer[128];
const char *lchrPtrIdPopupMenu,
	   *lchrPtrIdMenu;
SiscomRegistroProL *lSiscomRegProLPtrOpcionesPopupMenu;
SiscomRegistroProL *lSiscomRegProLPtrPropiedadesPrim=0,
		   *lSiscomRegProLPtrPropiedadesAct=0;
lSiscomRegProLPtrOpcionesPopupMenu=SiscomRegistrosAsociadoRespuestaOperacion("OpcionesPopupMenu",
										pSiscomOpePtrDato);
for(;
    lSiscomRegProLPtrOpcionesPopupMenu;
    lSiscomRegProLPtrOpcionesPopupMenu=SiscomSiguienteNodoRegistroProL(lSiscomRegProLPtrOpcionesPopupMenu))
{
   lchrPtrIdPopupMenu=SiscomObtenCampoRegistroProLChar("idmenu",pSiscomRegProLPtrPopupMenu);
   lchrPtrIdMenu=SiscomObtenCampoRegistroProLChar("idmenu",pSiscomRegProLPtrMenu);
   if(!SiscomComparaCadenaCampoRegistroProL(lchrPtrIdPopupMenu,
   					    "idpopupmenu",
					    lSiscomRegProLPtrOpcionesPopupMenu) &&
      !SiscomComparaCadenaCampoRegistroProL(lchrPtrIdMenu,
      					   "idmenuopcion",
					   lSiscomRegProLPtrOpcionesPopupMenu))
   {
   	/*
 	LogSiscom("\t\t\t %s %s %s %s",
		SiscomObtenCampoRegistroProLChar("idpopupmenu",lSiscomRegProLPtrOpcionesPopupMenu),
		SiscomObtenCampoRegistroProLChar("idmenuopcion",lSiscomRegProLPtrOpcionesPopupMenu),
	SiscomObtenCampoRegistroProLChar("nombre",lSiscomRegProLPtrOpcionesPopupMenu),
	SiscomObtenCampoRegistroProLChar("valor",lSiscomRegProLPtrOpcionesPopupMenu));
	*/
	SiscomAnexaRegistroPro(&lSiscomRegProLPtrPropiedadesPrim,
			       &lSiscomRegProLPtrPropiedadesAct,
			       lchrArrBuffer,
			       "Nombre,Valor,",
				SiscomObtenCampoRegistroProLChar("nombre",lSiscomRegProLPtrOpcionesPopupMenu),
				SiscomObtenCampoRegistroProLChar("valor",lSiscomRegProLPtrOpcionesPopupMenu));
	lintEsEsteElMenu=1;

   }
}
if(lintEsEsteElMenu)
{
/*
LogSiscom("\t\t%s %s",
	  SiscomObtenCampoRegistroProLChar("nombre",pSiscomRegProLPtrMenu),
	  SiscomObtenCampoRegistroProLChar("modulo",pSiscomRegProLPtrMenu));
*/
SiscomAnexaRegistroPro(pSiscomRegProLPtrMenusPrim,
		       pSiscomRegProLPtrMenusAct,
		       lchrArrBuffer,
		       "QAction,Modulo,Propiedades,",
	  	      SiscomObtenCampoRegistroProLChar("nombre",pSiscomRegProLPtrMenu),
	  	      SiscomObtenCampoRegistroProLChar("modulo",pSiscomRegProLPtrMenu),
		      (char *)0);
SiscomRegistrosAlCampo("Propiedades",
		       lSiscomRegProLPtrPropiedadesPrim,
		       lSiscomRegProLPtrPropiedadesAct,
		       *pSiscomRegProLPtrMenusAct);

}
}
void AgregaMenusPopupMenu(SiscomRegistroProL *pSiscomRegProLPtrPopupMenu,
				SiscomOperaciones *pSiscomOpePtrDato,
				SiscomRegistroProL *pSiscomRegProLPtrMenusSistemaAct)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrMenus;
SiscomRegistroProL *lSiscomRegProLPtrMenuPrim=0,
 		   *lSiscomRegProLPtrMenuAct=0,
		   *lSiscomRegProLPtrMenuQActionPrim=0,
		   *lSiscomRegProLPtrMenuQActionAct=0;
const char *lchrPtrIdPopupMenu;
lSiscomRegProLPtrMenus=SiscomRegistrosAsociadoRespuestaOperacion("Menus",pSiscomOpePtrDato);
/*
LogSiscom("%s %s",
	   SiscomObtenCampoRegistroProLChar("idmenu",pSiscomRegProLPtrPopupMenu),
	   SiscomObtenCampoRegistroProLChar("nombre",pSiscomRegProLPtrPopupMenu)); 
	   */
lchrPtrIdPopupMenu=SiscomObtenCampoRegistroProLChar("idmenu",pSiscomRegProLPtrPopupMenu);
for(;
    lSiscomRegProLPtrMenus;
    lSiscomRegProLPtrMenus=SiscomSiguienteNodoRegistroProL(lSiscomRegProLPtrMenus))
    MenusAlPopupMenu(pSiscomRegProLPtrPopupMenu,
    		     lSiscomRegProLPtrMenus,
		     pSiscomOpePtrDato,
		     pSiscomRegProLPtrMenusSistemaAct,
		     &lSiscomRegProLPtrMenuQActionPrim,
		     &lSiscomRegProLPtrMenuQActionAct);
SiscomRegistrosAlCampo("Menus",
			lSiscomRegProLPtrMenuQActionPrim,
			lSiscomRegProLPtrMenuQActionAct,
			pSiscomRegProLPtrMenusSistemaAct);
/*SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrMenuQActionPrim); */

}
void CreaPopupMenu(SiscomRegistroProL *pSiscomRegProLPtrPopupMenu,
		   SiscomRegistroProL **pSiscomRegProLPtrMenusSistemaPrim,
		   SiscomRegistroProL **pSiscomRegProLPtrMenusSistemaAct)
{
char lchrArrBuffer[256];
/*LogSiscom("Agregando %s",SiscomObtenCampoRegistroProLChar("nombre",pSiscomRegProLPtrPopupMenu)); */
SiscomAnexaRegistroPro(pSiscomRegProLPtrMenusSistemaPrim,
		       pSiscomRegProLPtrMenusSistemaAct,
		       lchrArrBuffer,
		       "IdPopupMenu,Nombre,Propiedades,Menus,",
			SiscomObtenCampoRegistroProLChar("idmenu",pSiscomRegProLPtrPopupMenu),
			SiscomObtenCampoRegistroProLChar("nombre",pSiscomRegProLPtrPopupMenu),
			(char *)0,
			(char *)0);
}

void AgregaPropiedadesPopupMenu(SiscomRegistroProL *pSiscomRegProLPtrPopupMenu,
				SiscomOperaciones *pSiscomOpePtrDato,
				SiscomRegistroProL *pSiscomRegProLPtrMenusSistemaAct)
{
SiscomRegistroProL *lSiscomRegProLPtrPropiedadesPrim=0,
   	           *lSiscomRegProLPtrPropiedadesAct=0,
		   *lSiscomRegProLPtrPropiedades;

char lchrArrBuffer[128];
const char *lchrPtrIdMenu;
lchrPtrIdMenu=SiscomObtenCampoRegistroProLChar("idmenu",pSiscomRegProLPtrPopupMenu);
lSiscomRegProLPtrPropiedades=SiscomRegistrosAsociadoRespuestaOperacion("PopupMenusPropiedades",
							pSiscomOpePtrDato);
for(;
    lSiscomRegProLPtrPropiedades;
    lSiscomRegProLPtrPropiedades=SiscomSiguienteNodoRegistroProL(lSiscomRegProLPtrPropiedades))
   if(!SiscomComparaCadenaCampoRegistroProL(lchrPtrIdMenu,"idmenu",lSiscomRegProLPtrPropiedades))
   SiscomAnexaRegistroPro(&lSiscomRegProLPtrPropiedadesPrim,
   			  &lSiscomRegProLPtrPropiedadesAct,
			  lchrArrBuffer,
			  "Nombre,Valor,",
     		SiscomObtenCampoRegistroProLChar("nombre",lSiscomRegProLPtrPropiedades),
		SiscomObtenCampoRegistroProLChar("valor",lSiscomRegProLPtrPropiedades));
SiscomRegistrosAlCampo("Propiedades",
			lSiscomRegProLPtrPropiedadesPrim,
			lSiscomRegProLPtrPropiedadesAct,
			pSiscomRegProLPtrMenusSistemaAct);
}

int SiscomValidaUsuarioFirmado(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
const char *lchrPtrPassword,
           *lchrPtrIdTipoPersona;
SiscomRegistroProL *lSiscomRegProLPtrRegreso;
lSiscomRegProLPtrRegreso=SiscomRegistrosAsociadoRespuestaOperacion("UsuarioSistema",pSiscomOpePtrDato);
lchrPtrPassword=SiscomCampoAsociadoEntradaOperacion("Envio","Password",pSiscomOpePtrDato);
if(!SiscomComparaCadenaCampoRegistroProL(lchrPtrPassword,"password",lSiscomRegProLPtrRegreso))
{
lchrPtrIdTipoPersona=SiscomObtenCampoRegistroProLChar("idtipopersona",lSiscomRegProLPtrRegreso);
LogSiscom("Usuario valido");
SiscomAgregaCampoAsociadoEntrada("IdTipoPersona",lchrPtrIdTipoPersona,"Envio",pSiscomOpePtrDato);
return 0;
}
else
return 1;
}

int ERRORUsuarioInvalido(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPrim=0,
		   *lSiscomRegProLAct=0;
SiscomAnexaRegistroPro(&lSiscomRegProLPrim,
		       &lSiscomRegProLAct,
		       lchrArrBuffer,
		       "EdoRegreso,Mensaje,",
		       "0",
		       "Usuario o password no Valido");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPrim);
return 1;
}
