#include <SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros4.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
SiscomRegistro4::SiscomRegistro4()
{
}
SiscomRegistro4 &SiscomRegistro4::operator<<(SiscomRegistro3 *pSisReg3Dato)
{
char lchrArrNmbRegistro[2048];
if(!count())
{	
  SiscomAgregaRegistro();
  pSisReg3Dato->Registro(chrArrNmbRegistroP);
  AgregaDato(pSisReg3Dato);
}
else
{
   pSisReg3Dato->Registro(lchrArrNmbRegistro);
   if(!strcmp(lchrArrNmbRegistro,chrArrNmbRegistroP))
   SiscomAgregaRegistro();
   AgregaDato(pSisReg3Dato);
}
return (*this);
}


void SiscomRegistro4::SiscomAgregaRegistro()
{
  append(new SiscomRegistro3LstLst );
}
void SiscomRegistro4::SiscomAgregaRegistro(int pintNSubGrupo,
					   SiscomRegistro3 *pSisReg3Dato)
{
 current()->SiscomAgregaRegistro(pintNSubGrupo,pSisReg3Dato);

}
void SiscomRegistro4::ActualizaRegistro(int pintNSubGrupo,
					int pintRegistro,
					SiscomRegistro3 *pSisReg3Actualiza)
{
  current()->ActualizaRegistro(pintNSubGrupo,pintRegistro,pSisReg3Actualiza);
}
void SiscomRegistro4::EliminaGrupoRegistros(int pintNGrupo)
{
  remove(pintNGrupo);
}
void SiscomRegistro4::EliminaGrupoRegistros(int pintNRegistro,
					    int pintNGrupo)
{
SiscomRegistro3Lst *lSisReg3LstRegistros;
if((lSisReg3LstRegistros=RegistrosSubGrupo(pintNRegistro,pintNGrupo)))
	lSisReg3LstRegistros->clear();

}
void SiscomRegistro4::EliminaRegistroDelGrupo(int pintNRegistro,
					      int pintNGrupo,
					      int pintRegistro)
{
SiscomRegistro3Lst *lSisReg3LstRegistros;
if((lSisReg3LstRegistros=RegistrosSubGrupo(pintNRegistro,pintNGrupo)))
    lSisReg3LstRegistros->remove(pintRegistro);
}
void SiscomRegistro4::SiscomAgregaRegistros(int pintSubGrupo,
					    SiscomRegistro3Lst *pSisReg3LstDat)
{
current()->SiscomAgregaRegistros(pintSubGrupo,pSisReg3LstDat);
}
void SiscomRegistro4::SiscomAgregaRegistro(int pintIndice,
					   int pintNSubGrupo,
					   SiscomRegistro3 *pSisReg3Dato)
{
 at(pintIndice)->SiscomAgregaRegistro(pintNSubGrupo,pSisReg3Dato);
}

void SiscomRegistro4::AgregaDato(SiscomRegistro3 *pSisReg3Dato)
{
SiscomRegistro3LstLst *lSisReg3LstLstCual=current();
lSisReg3LstLstCual->AgregaRegistro(pSisReg3Dato);
}
void SiscomRegistro4::SiscomAgregaSubRegistro()
{
	current()->SiscomAgregaSubRegistro();
}
SiscomRegistro3LstLst *SiscomRegistro4::GrupoRegistros(int pintNGrupo)
{
	return at(pintNGrupo);
}
const char *SiscomRegistro4::CampoRegistroSubGrupo(int pintIndice,
						   int pintNSubGrupo,
						   int pintNRegistro,
						   const char *pchrPtrNmbCampo)
{
SiscomRegistro3 *lSisReg3Dato;
lSisReg3Dato=RegistroSubGrupo(pintIndice,
  			     pintNSubGrupo,
			     pintNRegistro);
if(lSisReg3Dato)
return (*lSisReg3Dato)[pchrPtrNmbCampo];
else
return "";
}
const char *SiscomRegistro4::CampoRegistroPrincipal(const char *pchrPtrCampo)
{
   return (*RegistroPrincipal())[pchrPtrCampo];
}

SiscomRegistro3  *SiscomRegistro4::RegistroPrincipal()
{
SiscomRegistro3LstLst *lSisReg3LstLst;
SiscomRegistro3Lst *lSisReg3LstRegistro;
  if((lSisReg3LstLst=current()))
  {
      if((lSisReg3LstRegistro=lSisReg3LstLst->first()))
	  return lSisReg3LstRegistro->first();
  }
  return 0;
}

const char *SiscomRegistro4::CampoRegistroPrincipal(int pintNRegistro,const char *pchrPtrCampo)
{
   return (*RegistroPrincipal(pintNRegistro))[pchrPtrCampo];
}
SiscomRegistro3  *SiscomRegistro4::RegistroPrincipal(int pintNRegistro)
{
SiscomRegistro3LstLst *lSisReg3LstLst;
SiscomRegistro3Lst *lSisReg3LstRegistro;
  if((lSisReg3LstLst=at(pintNRegistro)))
  {
      if((lSisReg3LstRegistro=lSisReg3LstLst->first()))
	  return lSisReg3LstRegistro->first();
  }
  return 0;
}

void SiscomRegistro4::SiscomActualizaCampoSubRegistro(int pintIndice,
						      int pintNSubGrupo,
						      int pintNRegistro,
						      const char *pchrPtrNmbCampo,
						      const char *pchrPtrDato)
{
RegistroSubGrupo(pintIndice,
		 pintNSubGrupo,
		 pintNRegistro)->SiscomActualizaCampo(pchrPtrNmbCampo,pchrPtrDato);
}
int SiscomRegistro4::CampoRegistroSubGrupoInt(int pintIndice,
						   int pintNSubGrupo,
						   int pintNRegistro,
						   const char *pchrPtrNmbCampo)
{
const char *lchrPtrRegreso;
 if((lchrPtrRegreso=(*RegistroSubGrupo(pintIndice,
  			     pintNSubGrupo,
			     pintNRegistro))[pchrPtrNmbCampo]))
	return atoi(lchrPtrRegreso);
else
return -1; 
}
float SiscomRegistro4::CampoRegistroSubGrupoFloat(int pintIndice,
						   int pintNSubGrupo,
						   int pintNRegistro,
						   const char *pchrPtrNmbCampo)
{
const char *lchrPtrRegreso;
if((lchrPtrRegreso=(*RegistroSubGrupo(pintIndice,
  			     pintNSubGrupo,
			     pintNRegistro))[pchrPtrNmbCampo]))
return atof(lchrPtrRegreso);
else
return -1.0;
}
SiscomRegistro3 *SiscomRegistro4::RegistroSubGrupo(int pintNDato,
						   int pintNSubGrupo,
						   int pintNRegistro)
{
SiscomRegistro3LstLst *lSisReg3LstLstDato=at(pintNDato);
SiscomRegistro3Lst *lSisReg3LstSubGrupo=lSisReg3LstLstDato->at(pintNSubGrupo);
return lSisReg3LstSubGrupo ? (*lSisReg3LstSubGrupo)[pintNRegistro]:0;
}
SiscomRegistro3Lst *SiscomRegistro4::RegistrosSubGrupo(int pintNDato,
						   int pintNSubGrupo)
{
SiscomRegistro3LstLst *lSisReg3LstLstDato=at(pintNDato);
SiscomRegistro3Lst *lSisReg3LstSubGrupo=lSisReg3LstLstDato->at(pintNSubGrupo);
return lSisReg3LstSubGrupo;
}
int SiscomRegistro4::Registros()
{
SiscomRegistro3LstLst *lSisReg3LstLstDat;
SiscomRegistro3Lst *lSisReg3LstDat;
int lintContador=0;
for(lSisReg3LstLstDat=first();
    lSisReg3LstLstDat;
    lSisReg3LstLstDat=next())
{
  for(lSisReg3LstDat=lSisReg3LstLstDat->first();
      lSisReg3LstDat;
      lSisReg3LstDat=lSisReg3LstLstDat->next())
   lintContador+=lSisReg3LstDat->count();
}

return lintContador;
}
void SiscomRegistro4::SiscomLimpia()
{
SiscomRegistro3LstLst *lSisReg3LstLstDat;
SiscomRegistro3Lst *lSisReg3LstDat;
for(lSisReg3LstLstDat=first();
    lSisReg3LstLstDat;
    lSisReg3LstLstDat=next())
{
  for(lSisReg3LstDat=lSisReg3LstLstDat->first();
      lSisReg3LstDat;
      lSisReg3LstDat=lSisReg3LstLstDat->next())
	lSisReg3LstDat->SiscomElimina(); 
   lSisReg3LstLstDat->clear();
}
clear();
}
/*
 * Domingo 14 De Agosto 2011
 * Se agrega esta funcion que tendra la funcionalidad
 * del strcmp, solo que vs un dato en especifico
 *
 */
int SiscomRegistro4::SiscomCampoVsCadena(int pintNDato,
					 int pintNGrupo,
					 int pintNRegistro,
					 const char *pchrPtrNmbCampo,
					 const char *pchrPtrCadena)
{
return strcmp(CampoRegistroSubGrupo(pintNDato,
				    pintNGrupo,
				    pintNRegistro,
				    pchrPtrNmbCampo),
	       pchrPtrCadena);
}


int SiscomRegistro4::SiscomCampoVsCantidad(int pintNDato,
					 int pintNGrupo,
					 int pintNRegistro,
					 const char *pchrPtrNmbCampo,
					 float pfltCantidad)
{
return CampoRegistroSubGrupoFloat(pintNDato,
				  pintNGrupo,
				  pintNRegistro,
				  pchrPtrNmbCampo)==pfltCantidad;
}
int SiscomRegistro4::SiscomCampoVsCantidad(int pintNDato,
					 int pintNGrupo,
					 int pintNRegistro,
					 const char *pchrPtrNmbCampo,
					 int pintCantidad)
{
return CampoRegistroSubGrupoInt(pintNDato,
				  pintNGrupo,
				  pintNRegistro,
				  pchrPtrNmbCampo)==pintCantidad;
}

void SiscomContenidoRegistro4(const char *pchrPtrArchivo,
			      const char *pchrPtrFuncion,
			      int pintNLinea,
			      SiscomRegistro4 *pSisReg4Registro)
{							
SiscomRegistro3LstLst *lSisReg3LstLst; 
SiscomRegistro3Lst *lSisReg3LstRegistro;
SiscomRegistro3 *lSisReg3Dato;
SiscomCampo3 *lSisCampo3;
char lchrArrRegistro[1024];
char lchrArrPaso[128];
int lintPrimerCampo=0;
lchrArrRegistro[0]=0;
	memset(lchrArrRegistro,0,1024);
lchrArrPaso[0]=0;
for(lSisReg3LstLst=pSisReg4Registro->first();
    lSisReg3LstLst;
    lSisReg3LstLst=pSisReg4Registro->next())
{
  for(lSisReg3LstRegistro=lSisReg3LstLst->first();
      lSisReg3LstRegistro;
      lSisReg3LstRegistro=lSisReg3LstLst->next())
  {
     for(lSisReg3Dato=lSisReg3LstRegistro->first();
         lSisReg3Dato;
	 lSisReg3Dato=lSisReg3LstRegistro->next())
     {
	for(lSisCampo3=lSisReg3Dato->SiscomColocaPrimerCampo();
	    lSisCampo3;
	    lSisCampo3=lSisReg3Dato->SiscomSiguienteCampo())
	 {
	   if(!lintPrimerCampo)
	   {
	   strcpy(lchrArrRegistro,lSisCampo3->SiscomDato());
	   lintPrimerCampo=1;
	   }
	   else
	   sprintf(lchrArrPaso,"|%s",lSisCampo3->SiscomDato());
	   strcat(lchrArrRegistro,lchrArrPaso);
	 }
	SiscomMensajesLog3Qt(pchrPtrArchivo,
			     pchrPtrFuncion,
			     pintNLinea,
			     "%s",
			     lchrArrRegistro);
	memset(lchrArrRegistro,0,1024);
     }

  }

}
pSisReg4Registro->first();
}

