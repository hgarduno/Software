#include <SiscomProtocolo2SubRegistros.h>
#include <SiscomFuncionesComunes.h>
#include <SiscomProtocolo2.h>

#include <string.h>
#include <stdlib.h>

void SiscomPasaASubRegistrosLista(
			      LCamposSiscomPro2 *pLCSiscomPro2Dat,
			      LCamposSiscomPro2ConSubReg **pLCSiscomPro2SRPrimero)
{
int lintContador=0; 
char lchrArrNmbRegistroPrincipal[1024];
char lchrArrNmbRegistro[1024];
char *lchrPtrOperacion;
LCamposSiscomPro2ConSubReg *lLCSiscomPro2SRActual=0;
CamposSiscomPro2ConSubReg *lCSiscomPro2SRDat;
*pLCSiscomPro2SRPrimero=0;
while(pLCSiscomPro2Dat)
{
      NombreRegistro(pLCSiscomPro2Dat->SCSiscomPro2,lchrArrNmbRegistro);
      if(!lintContador)
      strcpy(lchrArrNmbRegistroPrincipal,lchrArrNmbRegistro);
      if(!strcmp(lchrArrNmbRegistroPrincipal,lchrArrNmbRegistro))
      {
  	MemoriaRegistroPrincipal(pLCSiscomPro2Dat->SCSiscomPro2,&lCSiscomPro2SRDat);
	SiscomListaSubRegistros(lCSiscomPro2SRDat,
				pLCSiscomPro2SRPrimero,
				&lLCSiscomPro2SRActual);
	lLCSiscomPro2SRActual->CSiscomPro2SReg->SCSiscomPro2=pLCSiscomPro2Dat->SCSiscomPro2;
      }
      else
	SiscomAgregaSubRegistro(lchrArrNmbRegistro,
				pLCSiscomPro2Dat->SCSiscomPro2,
				lLCSiscomPro2SRActual);
lintContador++;
pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig;
}
}
void SiscomLeeConSubRegistros(int pintSocket,
			      int pintNRegistros,
			      LCamposSiscomPro2 **pLCSiscomPro2RegCon,
			      LCamposSiscomPro2ConSubReg **pLCSiscomPro2SRPrimero)
{
int lintContador; 
char lchrArrNmbRegistroPrincipal[1024];
char lchrArrNmbRegistro[1024];
char *lchrPtrOperacion;
SCampoSiscomPro2 *lSCSiscomPro2Dat;
LCamposSiscomPro2ConSubReg *lLCSiscomPro2SRActual=0;
CamposSiscomPro2ConSubReg *lCSiscomPro2SRDat;
/*
 * Falta resolver la forma en la que se hara llegar al servidor
 * el numero de registros totales, incluyendo el registro de 
 * configuracion
  SiscomLeeRegistroConfiguracion(pintSocket,pLCSiscomPro2RegCon);
*/
for(lintContador=0;
    lintContador<pintNRegistros;
    lintContador++)
{
      SiscomLeeRegistroProtocolo2(pintSocket,
      				  &lSCSiscomPro2Dat);
      NombreRegistro(lSCSiscomPro2Dat,lchrArrNmbRegistro);
      /*
      SiscomImprimeContenidoRegistro("",gPtrFleArchivoLog,lSCSiscomPro2Dat);
      */
      if(!lintContador)
      strcpy(lchrArrNmbRegistroPrincipal,lchrArrNmbRegistro);
      if(!strcmp(lchrArrNmbRegistroPrincipal,lchrArrNmbRegistro))
      {
  	MemoriaRegistroPrincipal(lSCSiscomPro2Dat,&lCSiscomPro2SRDat);
	SiscomListaSubRegistros(lCSiscomPro2SRDat,
				pLCSiscomPro2SRPrimero,
				&lLCSiscomPro2SRActual);
	lLCSiscomPro2SRActual->CSiscomPro2SReg->SCSiscomPro2=lSCSiscomPro2Dat;
      }
      else
	SiscomAgregaSubRegistro(lchrArrNmbRegistro,
				lSCSiscomPro2Dat,
				lLCSiscomPro2SRActual);
	if(pintNRegistros>1 &&
	   lintContador<pintNRegistros-1)
	 SiscomLeeOperacion(pintSocket,&lchrPtrOperacion);
}
}
int SiscomBuscaSubRegistro(const char *pchrPtrNmbRegistro,
				    SCampoSiscomPro2 *pCSiscomPro2Dat,
				    LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				    LCamposSiscomPro2 **pLCSiscomPro2Prim,
				    LCamposSiscomPro2 **pLCSiscomPro2Act)
{
char lchrArrNmbRegistro[1024];
int lintContador=0;
while(SiscomSubRegistroPrim(lintContador,pLCSiscomPro2SRDat))
{
       if(EsElRegistroPorNombre(
       		pchrPtrNmbRegistro,
		SiscomSubRegistroPrim(lintContador,pLCSiscomPro2SRDat)))
	{
	(*pLCSiscomPro2Prim)=SiscomSubRegistroPrim(lintContador,pLCSiscomPro2SRDat);
	(*pLCSiscomPro2Act)=SiscomSubRegistroAct(lintContador,pLCSiscomPro2SRDat);
	return lintContador;
	}
lintContador++;
}
  *pLCSiscomPro2Prim=0;
  *pLCSiscomPro2Act=0;
  return -1;
}

void SiscomAgregaSubRegistro(const char *pchrPtrNmbRegistro,
			     SCampoSiscomPro2 *pCSiscomPro2Dat,
			     LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRActual)
{
LCamposSiscomPro2 *lLCSiscomPro2SubPrim=0,
		  *lLCSiscomPro2SubAct=0;
int lintNSubRegistro=0;
lintNSubRegistro=SiscomBuscaSubRegistro(pchrPtrNmbRegistro,
			  pCSiscomPro2Dat,
			  pLCSiscomPro2SRActual,
			  &lLCSiscomPro2SubPrim,
			  &lLCSiscomPro2SubAct);
SiscomCreaListaCamposPro2(pCSiscomPro2Dat,
			  &lLCSiscomPro2SubPrim,
			  &lLCSiscomPro2SubAct);

if(lintNSubRegistro==-1)
lintNSubRegistro=SiscomIncrementaNSubRegistro(pLCSiscomPro2SRActual)-1;

SiscomAsignaNodosSubRegistro(lintNSubRegistro,
			     pLCSiscomPro2SRActual,
			     lLCSiscomPro2SubPrim,
			     lLCSiscomPro2SubAct);
}
void MemoriaRegistroPrincipal(SCampoSiscomPro2 *pCSiscomPro2Dat,
			      CamposSiscomPro2ConSubReg **pCSiscomPro2SRDat)
{
*pCSiscomPro2SRDat=(CamposSiscomPro2ConSubReg *)malloc(
				sizeof(CamposSiscomPro2ConSubReg ));
   memset(*pCSiscomPro2SRDat,0,sizeof(CamposSiscomPro2ConSubReg));
   (*pCSiscomPro2SRDat)->SCSiscomPro2=pCSiscomPro2Dat;
}
void SiscomLeeRegistroConfiguracion(int pintSocket,
				    LCamposSiscomPro2 **pLCSiscomPro2RegCon)
{
LCamposSiscomPro2 *lLCSiscomPro2Dato=0;
SCampoSiscomPro2 *lSCSiscomPro2Reg=0;
SiscomLeeRegistroProtocolo2(pintSocket,&lSCSiscomPro2Reg);
SiscomCreaListaCamposPro2(lSCSiscomPro2Reg,
			  pLCSiscomPro2RegCon,
			  &lLCSiscomPro2Dato);
}

void NombreRegistro(SCampoSiscomPro2 *pCSiscomPro2Dat,
		    char *pchrPtrNombre)
{
int lintContador;
int lintNCampos=pCSiscomPro2Dat->intNumCampos;
*pchrPtrNombre=0;
for(lintContador=0; 
    lintContador<lintNCampos;
    lintContador++)
strcat(pchrPtrNombre,(pCSiscomPro2Dat+lintContador)->chrPtrNmbCampo);
}
void NombreRegistroDeLaLista(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			     char *pchrPtrNmbRegistro)
{
   NombreRegistro(pLCSiscomPro2Dat->SCSiscomPro2,pchrPtrNmbRegistro);

}
int EsElRegistroPorNombre(const char *pchrPtrNmbRegistro,
			  LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
char lchrArrNmbRegistro[1024];
NombreRegistroDeLaLista(pLCSiscomPro2Dat,lchrArrNmbRegistro);
return !strcmp(pchrPtrNmbRegistro,lchrArrNmbRegistro);
}
void SiscomListaSubRegistros(CamposSiscomPro2ConSubReg *pCSiscomPro2SRDat,
				 LCamposSiscomPro2ConSubReg **pLCSiscomPro2SRPrim,
				 LCamposSiscomPro2ConSubReg **pLCSiscomPro2SRAct)
{
LCamposSiscomPro2ConSubReg *lLCSiscomPro2SRDat=0;
SiscomNodoSubRegistros(pCSiscomPro2SRDat,&lLCSiscomPro2SRDat);
if(!*pLCSiscomPro2SRPrim)
 *pLCSiscomPro2SRPrim=*pLCSiscomPro2SRAct=lLCSiscomPro2SRDat;
else
{
 (*pLCSiscomPro2SRAct)->LCSiscomPro2SRSig=lLCSiscomPro2SRDat;
 (*pLCSiscomPro2SRAct)=(*pLCSiscomPro2SRAct)->LCSiscomPro2SRSig;
}
}

void SiscomNodoSubRegistros(CamposSiscomPro2ConSubReg *pCSiscomPro2SRDat,
			    LCamposSiscomPro2ConSubReg **pLCSiscomPro2SRDat)
{
  *pLCSiscomPro2SRDat=(LCamposSiscomPro2ConSubReg *)malloc(sizeof(LCamposSiscomPro2ConSubReg));
    memset((*pLCSiscomPro2SRDat),0,sizeof(LCamposSiscomPro2ConSubReg ));
   (*pLCSiscomPro2SRDat)->CSiscomPro2SReg=pCSiscomPro2SRDat;
}
/*******************************************************************/
/*Domingo 21 de Agosto 2011 
 * Faltara integrar las funciones, para regresar int, float etc
 *
 *
 */
const char *SiscomCampoSubRegistro(int pintNSubRegistro,
				   const char *pchrPtrNmbCampo,
				   const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SubRegDat)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
lLCSiscomPro2Dat=SiscomSubRegistroAct(pintNSubRegistro,
				      pLCSiscomPro2SubRegDat);
return SiscomObtenDato(lLCSiscomPro2Dat,pchrPtrNmbCampo);

}

float SiscomCampoSubRegistroFloat(int pintNSubRegistro,
				  const char *pchrPtrNmbCampo,
				  const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SubRegDat)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
lLCSiscomPro2Dat=SiscomSubRegistroAct(pintNSubRegistro,
				      pLCSiscomPro2SubRegDat);
return SiscomObtenDatoFloat(lLCSiscomPro2Dat,pchrPtrNmbCampo);

}


int SiscomCampoSubRegistroInt(int pintNSubRegistro,
				  const char *pchrPtrNmbCampo,
				  const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SubRegDat)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
lLCSiscomPro2Dat=SiscomSubRegistroAct(pintNSubRegistro,
				      pLCSiscomPro2SubRegDat);
return SiscomObtenDatoInt(lLCSiscomPro2Dat,pchrPtrNmbCampo);

}
LCamposSiscomPro2 *SiscomSubRegistroPrim(int pintNSubRegistro,
				     const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat)
{
return pLCSiscomPro2SRDat->CSiscomPro2SReg->LCSiscomPro2SRPrim[pintNSubRegistro];
}
LCamposSiscomPro2 *SiscomSubRegistroAct(int pintNSubRegistro,
				     const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat)
{
return pLCSiscomPro2SRDat->CSiscomPro2SReg->LCSiscomPro2SRAct[pintNSubRegistro];
}
int SiscomNumeroCamposRegistroPrincipal(const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat)
{
  return pLCSiscomPro2SRDat->CSiscomPro2SReg->SCSiscomPro2->intNumCampos;
}
SCampoSiscomPro2 *SiscomCamposRegistroPrincipal(const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat)
{
  return pLCSiscomPro2SRDat->CSiscomPro2SReg->SCSiscomPro2;
}
int SiscomNSubRegistro(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat)
{
return pLCSiscomPro2SRDat->CSiscomPro2SReg->intNSubRegistro;
}
int SiscomIncrementaNSubRegistro(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat)
{
return ++pLCSiscomPro2SRDat->CSiscomPro2SReg->intNSubRegistro; 
}
void SiscomAsignaNodosSubRegistro(int pintNSubRegistro,
				  LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				  LCamposSiscomPro2 *pLCSiscomPro2Prim,
				  LCamposSiscomPro2 *pLCSiscomPro2Act)
{
pLCSiscomPro2SRDat->CSiscomPro2SReg->LCSiscomPro2SRPrim[pintNSubRegistro]=pLCSiscomPro2Prim;
pLCSiscomPro2SRDat->CSiscomPro2SReg->LCSiscomPro2SRAct[pintNSubRegistro]=pLCSiscomPro2Act;

}
void SiscomAsignaCampoRegistroPrincipal(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
					const char *pchrPtrNmbCampo,
					const char *pchrPtrDato)
{

SiscomAsignaDatoCampo2A(
	pchrPtrNmbCampo,
	pchrPtrDato,
	SiscomCamposRegistroPrincipal(pLCSiscomPro2SRDat));
}

void SiscomAsignaCampoSubRegistro(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				  int pintNSubRegistro,
				  const char *pchrPtrCampo,
				  const char *pchrPtrDato)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=SiscomSubRegistroPrim(pintNSubRegistro,
							  pLCSiscomPro2SRDat);

SiscomAsignaDatoCampo2(pchrPtrCampo,pchrPtrDato,lLCSiscomPro2Dat);
}
const char *SiscomCampoRegistroPrincipal(
		const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
		const char *pchrPtrNmbCampo)
{
return SiscomObtenDatoDelRegistro(
	 SiscomCamposRegistroPrincipal(pLCSiscomPro2SRDat),
	 pchrPtrNmbCampo,
	 0);


}


float SiscomCampoRegistroPrincipalFloat(
		const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
		const char *pchrPtrNmbCampo)
{
return atof(SiscomObtenDatoDelRegistro(
	 SiscomCamposRegistroPrincipal(pLCSiscomPro2SRDat),
	 pchrPtrNmbCampo,
	 0));


}
int SiscomCampoRegistroPrincipalInt(
		const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
		const char *pchrPtrNmbCampo)
{
return atoi(SiscomObtenDatoDelRegistro(
	 SiscomCamposRegistroPrincipal(pLCSiscomPro2SRDat),
	 pchrPtrNmbCampo,
	 0));


}




/*******************************************************************/
void EncabezadoRegistroPrincipalLog(SCampoSiscomPro2 *pCSiscomPro2,
				    char *pchrPtrLinea)
{
int lintContador;
char lchrArrPaso[128];
int lintNCampos=pCSiscomPro2->intNumCampos;
for(lintContador=0;
    lintContador<lintNCampos;
    lintContador++,
    pCSiscomPro2++)
{
  if(!lintContador)
   strcpy(pchrPtrLinea,pCSiscomPro2->chrPtrNmbCampo);
  else
  {
   sprintf(lchrArrPaso,"|%s",pCSiscomPro2->chrPtrNmbCampo); 
  strcat(pchrPtrLinea,lchrArrPaso);
  }
}

}
void SiscomCamposPrincipalLog(const char *pchrPtrArchivo,
			      const char *pchrPtrFuncion,
			      int pintNLinea,
			      SCampoSiscomPro2 *pCSiscomPro2)
{
char lchrArrLinea[1024];
char lchrArrPaso[128];
int lintContador;
int lintNCampos=pCSiscomPro2->intNumCampos;
for(lintContador=0;
    lintContador<lintNCampos;
    lintContador++,
    pCSiscomPro2++)
{
  if(!lintContador)
   strcpy(lchrArrLinea,pCSiscomPro2->chrPtrDato);
  else
  {
   sprintf(lchrArrPaso,"|%s",pCSiscomPro2->chrPtrDato); 
  strcat(lchrArrLinea,lchrArrPaso);
  }
}
SiscomMensajesLog2A(pchrPtrArchivo,
		    pchrPtrFuncion,
		    pintNLinea,
		    "%s",
		    lchrArrLinea);
}
void ContenidoSubRegistros(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintNLinea,
			   LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=SiscomSubRegistroPrim(0,pLCSiscomPro2SRDat);
int lintContador=1;
	while(lLCSiscomPro2Dat)
	{
	  SiscomImprimeContenidoProtocolo2A(pchrPtrArchivo,
	  				    pchrPtrFuncion,
					    pintNLinea,
					    lLCSiscomPro2Dat);
	  lLCSiscomPro2Dat=SiscomSubRegistroPrim(lintContador,pLCSiscomPro2SRDat);;
	  lintContador++;
	}

}
void SiscomContenidoSubRegistros(const char *pchrPtrArchivo,
				 const char *pchrPtrFuncion,
				 int pintNLinea,
				 LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat)
{
int lintContador;
char lchrArrRegistro[1024];
int lintNCampos;
if(pLCSiscomPro2SRDat)
{
lintNCampos=SiscomNumeroCamposRegistroPrincipal(pLCSiscomPro2SRDat);
 EncabezadoRegistroPrincipalLog(SiscomCamposRegistroPrincipal(pLCSiscomPro2SRDat),
 				lchrArrRegistro);
}
for( ;
     pLCSiscomPro2SRDat;
     pLCSiscomPro2SRDat=pLCSiscomPro2SRDat->LCSiscomPro2SRSig)
{
SiscomMensajesLog2A(pchrPtrArchivo,
		    pchrPtrFuncion,
		    pintNLinea,
		    "%s",
		    lchrArrRegistro);
 SiscomCamposPrincipalLog(pchrPtrArchivo,
 			  pchrPtrFuncion,
			  pintNLinea,
			  SiscomCamposRegistroPrincipal(pLCSiscomPro2SRDat));
  ContenidoSubRegistros(pchrPtrArchivo,
  			pchrPtrFuncion,
			pintNLinea,
			pLCSiscomPro2SRDat);
  
}
}



int SiscomCopiaDatosPrincipalProtocoloSubRegCharChar(
				LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				int pintNRegistros,
				const char *pchrPtrCampo,
				char ***pchrPtrArgumentos)
{
int lintContador;
 *pchrPtrArgumentos=(char **)malloc(sizeof(char *)*(pintNRegistros+1));
  for(lintContador=0; 
      pLCSiscomPro2SRDat;
      pLCSiscomPro2SRDat=pLCSiscomPro2SRDat->LCSiscomPro2SRSig,
      lintContador++)
     (*pchrPtrArgumentos)[lintContador]=strdup(SiscomCampoRegistroPrincipal(
     						 pLCSiscomPro2SRDat,
						 pchrPtrCampo));
 (*pchrPtrArgumentos)[pintNRegistros]=0;
}
