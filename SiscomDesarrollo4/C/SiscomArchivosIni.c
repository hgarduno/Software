#include <SiscomArchivosIni.h>
#include <SiscomFuncionesComunes.h>
#include <SiscomDesarrolloMacros.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int SiscomAsignaMemoriaNodoArreglo(const char *pchrPtrNombre,
				   SiscomVariablesIniL *pSiscomVILPtrInfo,
				   SiscomVariableIniArregloL **pSiscomVALPtrNodo)
{
 if((*pSiscomVALPtrNodo=(SiscomVariableIniArregloL *)malloc(sizeof(SiscomVariableIniArregloL))))
 {
   strcpy((*pSiscomVALPtrNodo)->chrArrNombre,pchrPtrNombre);
   (*pSiscomVALPtrNodo)->SiscomVILPtrDatos=pSiscomVILPtrInfo;
   (*pSiscomVALPtrNodo)->SiscomVIAPtrSig=0;

 }
}

int SiscomNodoVariableArregloIni(const char *pchrPtrNombre,
				 SiscomVariablesIniL *pSiscomVILPtrInfo,
				 SiscomVariableIniArregloL **pSiscomVIALPtrPrim,
				 SiscomVariableIniArregloL **pSiscomVIALPtrAct)
{
SiscomVariableIniArregloL *lSiscomVIALPtrDato;
SiscomAsignaMemoriaNodoArreglo(pchrPtrNombre,
			       pSiscomVILPtrInfo,
			       &lSiscomVIALPtrDato);
if(!*pSiscomVIALPtrPrim)
(*pSiscomVIALPtrPrim)=(*pSiscomVIALPtrAct)=lSiscomVIALPtrDato;
else
{
  (*pSiscomVIALPtrAct)->SiscomVIAPtrSig=lSiscomVIALPtrDato;
  (*pSiscomVIALPtrAct)=(*pSiscomVIALPtrAct)->SiscomVIAPtrSig;
}
}
				 
int SiscomVarIniAsignaMemoriaNodo(const SiscomVariableIni *pSiscomVIniPtrDato,
				SiscomVariablesIniL **pSiscomVILPtrDato)
{

  if(((*pSiscomVILPtrDato)=(SiscomVariablesIniL *)malloc(sizeof(SiscomVariablesIniL))))
  {
    (*pSiscomVILPtrDato)->SiscomVIni=*pSiscomVIniPtrDato;
    (*pSiscomVILPtrDato)->SiscomVIniLPtrSig=0;
    (*pSiscomVILPtrDato)->SiscomVIniLPtrAnt=0;
    return 0;
  }
  else
  return SiscomGeneraError(1,"No hay memoria para uno nodo mas");

}

int SiscomVarIniNodoVariableIni(const SiscomVariableIni *pSiscomVIniPtrDato,
				SiscomVariablesIniL **pSiscomVILPtrPrim,
				SiscomVariablesIniL **pSiscomVILPtrActual)
{
SiscomVariablesIniL *lSiscomVILPtrDato=0;
if(!SiscomVarIniAsignaMemoriaNodo(pSiscomVIniPtrDato,
				  &lSiscomVILPtrDato))
{
     if(!*pSiscomVILPtrPrim)
   (*pSiscomVILPtrPrim)=(*pSiscomVILPtrActual)=lSiscomVILPtrDato;
   else
   {
     (*pSiscomVILPtrActual)->SiscomVIniLPtrSig=(void *)lSiscomVILPtrDato;
     (*pSiscomVILPtrActual)=(void *)(*pSiscomVILPtrActual)->SiscomVIniLPtrSig;
   }
 return 0;
}
else
return SiscomGeneraError(1,"No hay memoria para un nodo mas");
}


int SiscomEsLineaValidaParaElIni(const char *pchrPtrLinea)
{
return *pchrPtrLinea &&
       *pchrPtrLinea!='#';

}
int SiscomEsVariableDeArreglo(const char *pchrPtrLinea)
{
const char *lchrPtrRegreso;
  return (lchrPtrRegreso=strchr(pchrPtrLinea,'[')) &&
         strchr(lchrPtrRegreso+1,']');

}
void SiscomAgregaLineaALasLineas(const char *pchrPtrLinea,
				 int pintNLineas,
				 char ***pchrPtrLineas)
{
	if(!pintNLineas)
	{
	 *pchrPtrLineas=(char **)malloc(sizeof(char **)*2);
	  *((*pchrPtrLineas)+pintNLineas)=strdup(pchrPtrLinea);
	}
	else
	{
	   *pchrPtrLineas=(char **)realloc(*pchrPtrLineas,sizeof(char **)*(pintNLineas+1));
	   *((*pchrPtrLineas)+pintNLineas)=strdup(pchrPtrLinea);
	}
}

void SiscomObtenVariable(const char *pchrPtrLinea,
			 SiscomVariableIni *pSiscomVIPtrRegreso)
{
char *lchrPtrNmbVariable=pSiscomVIPtrRegreso->chrArrNombre;
char *lchrPtrValorVariable=pSiscomVIPtrRegreso->chrArrDato;
short int lintEsNmbVariable=1;
	while(*pchrPtrLinea)
	{
	   if(*pchrPtrLinea=='=')
	   {
	 	lintEsNmbVariable=0;	
		pchrPtrLinea++;
	   }
		if(lintEsNmbVariable)
		{
		  *lchrPtrNmbVariable=*pchrPtrLinea;
		  lchrPtrNmbVariable++;
		}
		if(!lintEsNmbVariable)
		{
		 *lchrPtrValorVariable=*pchrPtrLinea;
		 lchrPtrValorVariable++;
		}
	   pchrPtrLinea++;
	}
    *lchrPtrValorVariable=0;
    *lchrPtrNmbVariable=0;
}
void SiscomObtenVariablesAsignacion(int pintNLineas,
				    char **pchrPtrVariables,
				    SiscomVariablesIniL **pSiscomVILPtrPrim,
				    SiscomVariablesIniL **pSiscomVILPtrActual)
{
SiscomVariableIni lSiscomVIVariable;
*(pchrPtrVariables+pintNLineas)=0;
   while(*pchrPtrVariables)
   {
	SiscomObtenVariable(*pchrPtrVariables,&lSiscomVIVariable);
	SiscomVarIniNodoVariableIni(&lSiscomVIVariable,
				    pSiscomVILPtrPrim,	
				    pSiscomVILPtrActual);
	/* Miercoles 9 de mayo del 2012 
	 * hay que arreglar esta funcion, ya que truena cuando se libera 
	 * esta parte de la memoria 
	 */
	/*free(*pchrPtrVariables); */
	pchrPtrVariables++;
   }
}


int SiscomObtenNombreVariableArreglo(const char **pchrPtrCadenas,
				             char *pchrPtrNombre)
{
const char *lchrPtrLineaInicioVariable=*pchrPtrCadenas;
	while(*lchrPtrLineaInicioVariable)
	{
	    if(*lchrPtrLineaInicioVariable=='[' &&
	       *(lchrPtrLineaInicioVariable+1)==']')
	    {
		*pchrPtrNombre=0;
		return 1;
	    }
	    else
	    {
		*pchrPtrNombre=*lchrPtrLineaInicioVariable;
		pchrPtrNombre++;
		lchrPtrLineaInicioVariable++;
	    }

	}
return 0;
}
int SiscomFinalizaVariableArreglo(const char *pchrPtrLineaVariable)
{
  return *pchrPtrLineaVariable=='[' &&
         *(pchrPtrLineaVariable+1)==']' ;
}
const char *SiscomIniciaNombreVariableArreglo(const char *pchrPtrLinea)
{
	while(*pchrPtrLinea!='[')
	   pchrPtrLinea++; 
  return ++pchrPtrLinea;
}
const char *SiscomObtenNombreIndiceArreglo(const char *pchrPtrLinea,	
					   char *pchrPtrNombre)
{
	while(*pchrPtrLinea!=']')
	{
	   *pchrPtrNombre=*pchrPtrLinea;
	   pchrPtrNombre++;
	   pchrPtrLinea++;
	}
  *pchrPtrNombre=0;
 return ++pchrPtrLinea;
}
void SiscomObtenDatoDelIndiceArreglo(const char *pchrPtrLinea,
				     char *pchrPtrDato)
{
	if(*pchrPtrLinea=='=')
	{
	  pchrPtrLinea++;
		while(*pchrPtrLinea)
		{
	   	  *pchrPtrDato=*pchrPtrLinea;
		  pchrPtrDato++;
		  pchrPtrLinea++;
		}
	   *pchrPtrDato=0;
	 }

}
void SiscomObtenVariableArreglo(const char *pchrPtrLinea,
				SiscomVariableIni *pSiscomVIPtrDato)
{
pchrPtrLinea=SiscomIniciaNombreVariableArreglo(pchrPtrLinea);
pchrPtrLinea=SiscomObtenNombreIndiceArreglo(pchrPtrLinea,
					    pSiscomVIPtrDato->chrArrNombre);
SiscomObtenDatoDelIndiceArreglo(pchrPtrLinea,
			        pSiscomVIPtrDato->chrArrDato);
}
const char **SiscomObtenInformacionArreglo(const char **pchrPtrCadenas,
				SiscomVariableIniArregloL **pSiscomVIALPtrPrim,
				SiscomVariableIniArregloL **pSiscomVIALPtrAct)
{
char lchrArrNombre[50];
SiscomVariableIni lSiscomVIDato;
SiscomVariablesIniL *lSiscomVILPtrPrim=0;
SiscomVariablesIniL *lSiscomVILPtrAct=0;
int lintNElementosArreglo=0;
    if(SiscomObtenNombreVariableArreglo(pchrPtrCadenas,lchrArrNombre))
    {
	 pchrPtrCadenas++;
	 while(!SiscomFinalizaVariableArreglo(*pchrPtrCadenas))
	 {
	     SiscomObtenVariableArreglo(*pchrPtrCadenas,&lSiscomVIDato);
	     SiscomVarIniNodoVariableIni(&lSiscomVIDato,
	     				 &lSiscomVILPtrPrim,
					 &lSiscomVILPtrAct);
	     /*
	     LogSiscom("(%s)=(%s)",
	     		lSiscomVIDato.chrArrNombre,
			lSiscomVIDato.chrArrDato);
	     */
	     pchrPtrCadenas++;
	     lintNElementosArreglo++;
	 }
     
       SiscomNodoVariableArregloIni(lchrArrNombre,
       				    lSiscomVILPtrPrim,
				    pSiscomVIALPtrPrim,
				    pSiscomVIALPtrAct);
	(*pSiscomVIALPtrAct)->intNDatosArreglo=lintNElementosArreglo;
    }
return ++pchrPtrCadenas;
}

void SiscomObtenVariablesArreglo(int pintNLineas,
    			 	 char **pchrPtrVariables,
				 SiscomVariableIniArregloL **pSiscomVIALPtrPrim,
				 SiscomVariableIniArregloL **pSiscomVIALPtrAct)
				  
{ 
*(pchrPtrVariables+pintNLineas)=0;
 while(*(pchrPtrVariables=(char **)SiscomObtenInformacionArreglo((const char **)pchrPtrVariables,
			   pSiscomVIALPtrPrim,
			   pSiscomVIALPtrAct)))
 {
 }
}
int SiscomAnalizaArchivoIni(const char *pchrPtrArchivo,
			    SiscomDatosIni *pSiscomDIPtrRegreso)
{
FILE *lFlePtrArchivo;
char lchrArrLinea[256];
int lintEsVariableArreglo;
SiscomVariableIni lSiscomVIDato;
SiscomVariablesIniL *lSiscomVILPtrActual=0;
SiscomVariableIniArregloL *lSiscomVIALPtrActual=0;
char **lchrPtrLineasVariables;
char **lchrPtrLineasVarArreglo;
int lintNLineasAsignacion=0;
int lintNLineasArreglo=0;
memset(pSiscomDIPtrRegreso,0,sizeof(SiscomDatosIni));
if((lFlePtrArchivo=fopen(pchrPtrArchivo,"r")))
{
   while(SiscomLeeLineaArchivo(lFlePtrArchivo,lchrArrLinea)!=(char )EOF)
   {
     if(SiscomEsLineaValidaParaElIni(lchrArrLinea))
     {
       lintEsVariableArreglo=SiscomEsVariableDeArreglo(lchrArrLinea);
       if(SiscomEsLineaConAsignacion(lchrArrLinea) &&
          !lintEsVariableArreglo)
       {
       	  SiscomAgregaLineaALasLineas(lchrArrLinea,
	  			      lintNLineasAsignacion,
				      &lchrPtrLineasVariables);
          lintNLineasAsignacion++;	
       }
       if(lintEsVariableArreglo)
       {
	  SiscomAgregaLineaALasLineas(lchrArrLinea,
	  			      lintNLineasArreglo,
				      &lchrPtrLineasVarArreglo);
	  lintNLineasArreglo++;
       }
       				  
     }
   }
    SiscomObtenVariablesAsignacion(lintNLineasAsignacion,
    				   lchrPtrLineasVariables,
				   &pSiscomDIPtrRegreso->SiscomVILPtrVariables,
				   &lSiscomVILPtrActual);
    if(lintNLineasArreglo)
    SiscomObtenVariablesArreglo(lintNLineasArreglo,
    			 	lchrPtrLineasVarArreglo,
				&pSiscomDIPtrRegreso->SiscomVIALPtrArreglo,
				&lSiscomVIALPtrActual);
 
	/* Miercoles 9 de mayo del 2012 
	 * hay que arreglar esta funcion, ya que truena cuando se libera 
	 * esta parte de la memoria 
	 */
    /*free(lchrPtrLineasVariables); */
}
else
return SiscomGeneraError(2,"Error al abrir el archivo");
}


void ImprimeCadena(const char *pchrPtrCadena)
{
   while(*pchrPtrCadena)
   {
	 printf("(%d) (%c) (%x)\n",*pchrPtrCadena,*pchrPtrCadena,pchrPtrCadena);
 	pchrPtrCadena++;
   }



}
int SiscomEsLineaConAsignacion(const char *pchrPtrLinea)
{
  return strchr(pchrPtrLinea,'=') ? 1 :0 ;

}
int SiscomEsLaVariableNodoActual(
		const char *pchrPtrVariable,
		const SiscomVariablesIniL *pSiscomVILPtrDato)
{
return pSiscomVILPtrDato &&
       !strcmp(pchrPtrVariable,
       	       pSiscomVILPtrDato->SiscomVIni.chrArrNombre);

}

int SiscomObtenVariableIni(const char *pchrPtrNombre,
		      const SiscomDatosIni *pSiscomDIPtrDatos,
		      SiscomVariableIni *pSiscomVIPtrRegreso)
{
SiscomVariablesIniL *lSiscomVILPtrDatos=pSiscomDIPtrDatos->SiscomVILPtrVariables;
	while(lSiscomVILPtrDatos)
	{
	   if(SiscomEsLaVariableNodoActual(pchrPtrNombre,
	   				   lSiscomVILPtrDatos))
	   {
		*pSiscomVIPtrRegreso=lSiscomVILPtrDatos->SiscomVIni;
		return 1;
	   }
	  lSiscomVILPtrDatos=(void *)lSiscomVILPtrDatos->SiscomVIniLPtrSig;
	}
return 0;
}

int SiscomVariableIniAInt(const char *pchrPtrNombre,
			  const SiscomDatosIni *pSiscomDatIniPtrDatos)
{
SiscomVariableIni lSiscomVarIniRegreso;
if(SiscomObtenVariableIni(pchrPtrNombre,
			  pSiscomDatIniPtrDatos,
			  &lSiscomVarIniRegreso))
return atoi(lSiscomVarIniRegreso.chrArrDato);
else
LogSiscom("No se encontro la variable:%s",pchrPtrNombre);

}

int SiscomVariableIniAChar(const char *pchrPtrNombre,
			  const SiscomDatosIni *pSiscomDatIniPtrDatos,
			  char *pchrPtrDato)
{
SiscomVariableIni lSiscomVarIniRegreso;
if(SiscomObtenVariableIni(pchrPtrNombre,
			  pSiscomDatIniPtrDatos,
			  &lSiscomVarIniRegreso))
{
strcpy(pchrPtrDato,lSiscomVarIniRegreso.chrArrDato);
return 1;
}
else
return 0;

}
/* --- No funciona asi, regreso la direccion de una variable ???
 * local ???
 *
 */
char *SiscomVariableIniAChar2(const char *pchrPtrNombre,
			  const SiscomDatosIni *pSiscomDatIniPtrDatos,
			  char *pchrPtrDato)
{
SiscomVariableIni lSiscomVarIniRegreso;
if(SiscomObtenVariableIni(pchrPtrNombre,
			  pSiscomDatIniPtrDatos,
			  &lSiscomVarIniRegreso))
{
strcpy(pchrPtrDato,lSiscomVarIniRegreso.chrArrDato);
return pchrPtrDato;
}
else
return 0;

}
int SiscomObtenVariableIni2(const char *pchrPtrNombre,
		      const SiscomVariablesIniL *pSiscomVILPtrDatos,
		      SiscomVariableIni *pSiscomVIPtrRegreso)
{
	while(pSiscomVILPtrDatos)
	{
	   if(SiscomEsLaVariableNodoActual(pchrPtrNombre,
	   				   pSiscomVILPtrDatos))
	   {
		*pSiscomVIPtrRegreso=pSiscomVILPtrDatos->SiscomVIni;
		return 1;
	   }
	  pSiscomVILPtrDatos=(void *)pSiscomVILPtrDatos->SiscomVIniLPtrSig;
	}
return 0;
}


int SiscomObtenVariablesArregloIni(const char *pchrPtrNombreArreglo,
				   const SiscomDatosIni *pSiscomDatIni,
				   SiscomVariableIni *pSisVarIniReg,
				   int *pintPtrNVariables)
{
const SiscomVariableIniArregloL *lSiscomVIALPtrDato=pSiscomDatIni->SiscomVIALPtrArreglo;
const SiscomVariablesIniL *lSiscomVarsIniLDato;
short int lintRegreso=0;
while(lSiscomVIALPtrDato)
{
  if(!strcmp(lSiscomVIALPtrDato->chrArrNombre,pchrPtrNombreArreglo))
  {
  	lSiscomVarsIniLDato=lSiscomVIALPtrDato->SiscomVILPtrDatos;
	lintRegreso=1;
	*pintPtrNVariables=0;
      while(lSiscomVarsIniLDato)
      {
	*pSisVarIniReg=lSiscomVarsIniLDato->SiscomVIni;
	pSisVarIniReg++;
	lSiscomVarsIniLDato=(void *)lSiscomVarsIniLDato->SiscomVIniLPtrSig;
	(*pintPtrNVariables)++;
      }
      break;
  }
 lSiscomVIALPtrDato=lSiscomVIALPtrDato->SiscomVIAPtrSig;
}
return lintRegreso;

}

int SiscomObtenVariableArregloIni(const char *pchrPtrNombreArreglo,
				  const char *pchrPtrVariable,
		      		  const SiscomDatosIni *pSiscomDIPtrDatos,
		      		  SiscomVariableIni *pSiscomVIPtrRegreso)
{
const SiscomVariableIniArregloL *lSiscomVIALPtrDato=pSiscomDIPtrDatos->SiscomVIALPtrArreglo;
while(lSiscomVIALPtrDato)
{
  if(!strcmp(lSiscomVIALPtrDato->chrArrNombre,pchrPtrNombreArreglo))
  {
	return SiscomObtenVariableIni2(pchrPtrVariable,
				lSiscomVIALPtrDato->SiscomVILPtrDatos,
				pSiscomVIPtrRegreso);
  }
 lSiscomVIALPtrDato=lSiscomVIALPtrDato->SiscomVIAPtrSig;
}
return 0;
}

int SiscomObtenVariableArregloIniAInt(const char *pchrPtrNombreArreglo,
				  const char *pchrPtrVariable,
		      		  const SiscomDatosIni *pSiscomDIPtrDatos)
{
SiscomVariableIni lSiscomVarIniReg;
if(SiscomObtenVariableArregloIni(pchrPtrNombreArreglo,
			      pchrPtrVariable,
			      pSiscomDIPtrDatos,
			      &lSiscomVarIniReg))
return atoi(lSiscomVarIniReg.chrArrDato);
else
{
  return -10000;
}

}


int SiscomObtenVariableArregloIniAChar(const char *pchrPtrNombreArreglo,
				  const char *pchrPtrVariable,
		      		  const SiscomDatosIni *pSiscomDIPtrDatos,
				  char *pchrPtrDato)
{
SiscomVariableIni lSiscomVarIniReg;
if(SiscomObtenVariableArregloIni(pchrPtrNombreArreglo,
			      pchrPtrVariable,
			      pSiscomDIPtrDatos,
			      &lSiscomVarIniReg))
{
strcpy(pchrPtrDato,lSiscomVarIniReg.chrArrDato);
return 0;
}
else
{
  return -10000;
}

}
const char *SiscomObtenVariableArregloIniAChar2(const char *pchrPtrNombreArreglo,
				  const char *pchrPtrVariable,
		      		  const SiscomDatosIni *pSiscomDIPtrDatos,
				  char *pchrPtrDato)
{
  if(!SiscomObtenVariableArregloIniAChar(pchrPtrNombreArreglo,
  					 pchrPtrVariable,
					 pSiscomDIPtrDatos,
					 pchrPtrDato))
  return pchrPtrDato;
  else
  return "";
}

int SiscomObtenInformacionVariableArreglo(const char *pchrPtrNombreArreglo,
			       const SiscomDatosIni *pSiscomDatIniPtrDatos,
			       SiscomVariableIniArregloL **pSiscomVarIniArrLPtrDat)
{
const SiscomVariableIniArregloL *lSiscomVarIniArrLPtrDat;

lSiscomVarIniArrLPtrDat=pSiscomDatIniPtrDatos->SiscomVIALPtrArreglo;
*pSiscomVarIniArrLPtrDat=0;
while(lSiscomVarIniArrLPtrDat)
{
  if(!strcmp(lSiscomVarIniArrLPtrDat->chrArrNombre,pchrPtrNombreArreglo))
  {
    *pSiscomVarIniArrLPtrDat=(void *)lSiscomVarIniArrLPtrDat;
    return 1;
  }
}
return 0;
}


/*
 * Martes 15 Abril del 2014
 * Estas funciones se deberan agregar a la biblioteca SiscomDesarrollo4
 * en el manejo de archivos ini
 *

void SiscomCompletaVariableConVariables(int pintNVarsIni,
					SiscomVariableIni *pSisVarIni)
{
const char *lchrPtrDato;
char lchrArrSubVariable[256];
SiscomVariableIni *lSisVarIni=pSisVarIni;
SiscomVariableIni lSisVarAReemplazar;
   lchrPtrDato=pSisVarIni->chrArrDato;
   if(SiscomEsVariableConSubValorVariable(lchrPtrDato,lchrArrSubVariable))
   {
      LogSiscom("La Subvariable:%s",lchrArrSubVariable);
      SiscomObtenVariableArregloIni("Ambiente",
      				    lchrArrSubVariable,
				    lSisVarIni,
				    &lSisVarAReemplazar);
     LogSiscom("Se reemplazara :%s",lSisVarAReemplazar.chrArrDato);

   }
}
*/
const char *SiscomEsVariableConSubValorVariable(const char *pchrPtrValor,
					char *pchrPtrVariable)
{
const char *lchrPtrRegreso;
   if((lchrPtrRegreso=strchr(pchrPtrValor,'$')))
   {
    lchrPtrRegreso++;
    while(*lchrPtrRegreso!='/')
    {
	*pchrPtrVariable=*lchrPtrRegreso;
	lchrPtrRegreso++;
	pchrPtrVariable++;
    }
    *pchrPtrVariable=0;
   }
return lchrPtrRegreso ? lchrPtrRegreso : 0;
}
/*
 * Martes 15 de abril del 2014 
 * Previamente se leyeron las variables del arreglo,
 * se requiere pasar todos los datos del ini, para considerar el caso
 * de que alguna de las variables pueda hacer uso de otras de las variables
 * del ini
 */
const char *SiscomObtenDatoVariableArreglo(const SiscomDatosIni *pSisDatIni,
					   const SiscomVariableIni *pSisVarArrIni,
					   int pintNVarsIni,
					   const char *pchrPtrVariable,
					   char *pchrPtrRegreso)
{
int lintContador;
char lchrArrSubVariable[256];
char lchrArrDatoSubVariable[256];

const char *lchrPtrRegresito;
*pchrPtrRegreso=0;
for(lintContador=0;
    lintContador<pintNVarsIni;
    lintContador++,
    pSisVarArrIni++)
{
   if(!strcmp(pSisVarArrIni->chrArrNombre,pchrPtrVariable))
   {
      if((lchrPtrRegresito=SiscomEsVariableConSubValorVariable(pSisVarArrIni->chrArrDato,lchrArrSubVariable)))
      {
      SiscomVariableIniAChar(lchrArrSubVariable,pSisDatIni,lchrArrDatoSubVariable);
       strcpy(pchrPtrRegreso,lchrArrDatoSubVariable);
       strcat(pchrPtrRegreso,lchrPtrRegresito);
      }
      else
      strcpy(pchrPtrRegreso,pSisVarArrIni->chrArrDato);
   }
}
return *pchrPtrRegreso ? pchrPtrRegreso:"";
}
const char *SiscomObtenDatoVariableArreglo2(const SiscomDatosIni *pSisDatIni,
					   const char *pchrPtrArreglo,
					   const char *pchrPtrVariable,
					   char *pchrPtrRegreso)
{
int lintContador,
    lintNVarIniDatos;
char lchrArrSubVariable[256];
char lchrArrDatoSubVariable[256];
const char *lchrPtrRegresito;
SiscomVariableIni lSisVarsIniDatos[256],
		  *lSisVarsIniDatosPaso=lSisVarsIniDatos;
SiscomObtenVariablesArregloIni(pchrPtrArreglo,
			     pSisDatIni,
			     lSisVarsIniDatos,
			     &lintNVarIniDatos);

*pchrPtrRegreso=0;

for(lintContador=0;
    lintContador<lintNVarIniDatos;
    lintContador++,
    lSisVarsIniDatosPaso++)
{
   if(!strcmp(lSisVarsIniDatosPaso->chrArrNombre,pchrPtrVariable))
   {
      if((lchrPtrRegresito=SiscomEsVariableConSubValorVariable(lSisVarsIniDatosPaso->chrArrDato,lchrArrSubVariable)))
      {
      SiscomVariableIniAChar(lchrArrSubVariable,pSisDatIni,lchrArrDatoSubVariable);
       strcpy(pchrPtrRegreso,lchrArrDatoSubVariable);
       strcat(pchrPtrRegreso,lchrPtrRegresito);
      }
      else
      strcpy(pchrPtrRegreso,lSisVarsIniDatosPaso->chrArrDato);

   }


}

return *pchrPtrRegreso ? pchrPtrRegreso:"";
}

int SiscomObtenVariableArregloACharChar(const SiscomDatosIni *pSisDatIniConfig,
				 	const char *pchrPtrVariable,
					char ***pchrPtrVariables)
{
SiscomVariableIni lSisVarsIniDatos[256];
const SiscomVariableIni *lSisVarsIniDatosPaso=lSisVarsIniDatos;
int lintNVarsDatos,
    lintContador;
SiscomObtenVariablesArregloIni(pchrPtrVariable,
				pSisDatIniConfig,
				lSisVarsIniDatos,
				&lintNVarsDatos);
*pchrPtrVariables=(char **)malloc(sizeof(char *)*(lintNVarsDatos+1));
for(lintContador=0;
    lintContador<lintNVarsDatos;
    lintContador++,
    lSisVarsIniDatosPaso++)
*((*pchrPtrVariables)+lintContador)=strdup(lSisVarsIniDatosPaso->chrArrDato);
*((*pchrPtrVariables)+lintContador)=0;
}
