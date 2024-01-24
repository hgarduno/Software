#include <SiscomRegistros3.h>
#include <SiscomDesarrollo3Qt++.h>
#include <stdlib.h>
SiscomRegistro3::SiscomRegistro3()
{

}
SiscomRegistro3::SiscomRegistro3(SiscomRegistro3 *pSisReg3)
{
SiscomCampo3 *lSisCampo3;
if(pSisReg3->Campos())
for(lSisCampo3=pSisReg3->SiscomColocaPrimerCampo();
    lSisCampo3;
    lSisCampo3=pSisReg3->SiscomSiguienteCampo())
{
	(*this) << new SiscomCampo3(lSisCampo3->SiscomNmbCampo(),
				    lSisCampo3->SiscomDato());
}
}
SiscomRegistro3::~SiscomRegistro3()
{
SCampo3Lst.setAutoDelete(true);
SCampo3Lst.clear();
}
void SiscomRegistro3::SiscomObtenCampos(SiscomCampo3Lst *pSisCampos3Datos)
{

	*pSisCampos3Datos=SCampo3Lst;
}
SiscomRegistro3 &SiscomRegistro3::operator<<(SiscomCampo3 *pSCampo3)
{
   SCampo3Lst << pSCampo3;
   return *this;
}

SiscomCampo3 *SiscomRegistro3::SiscomColocaPrimerCampo()
{
   return SCampo3Lst.first();
}
SiscomCampo3 *SiscomRegistro3::SiscomSiguienteCampo()
{
	return SCampo3Lst.next();
}
const char *SiscomRegistro3::operator[](const char *pchrPtrNmbCampo)
{
 return SCampo3Lst[pchrPtrNmbCampo];
}
int SiscomRegistro3::CampoAInt(const char *pchrPtrNmbCampo)
{
    return atoi(SCampo3Lst[pchrPtrNmbCampo]);
}
const char *SiscomRegistro3::operator[](int pintNCampo)
{
return SCampo3Lst[pintNCampo];
}
SiscomCampo3 *SiscomRegistro3::Campo3(const char *pchrPtrCampo)
{
	return SCampo3Lst.Campo3(pchrPtrCampo);
}
SiscomRegistro3 &SiscomRegistro3::operator+=(SiscomRegistro3 *pSisReg3Registro)
{
SiscomCampo3 *lSisCampo3;

	for(lSisCampo3=pSisReg3Registro->SiscomColocaPrimerCampo();
	    lSisCampo3;
	    lSisCampo3=pSisReg3Registro->SiscomSiguienteCampo())
	 if(!YaEstaElCampo(lSisCampo3))
	 (*this) << lSisCampo3; 
	return *this;
}
int SiscomRegistro3::YaEstaElCampo(SiscomCampo3 *pSisCampoDato)
{
SiscomCampo3 *lSisCampo3;
	for(lSisCampo3=SiscomColocaPrimerCampo();
	    lSisCampo3;
	    lSisCampo3=SiscomSiguienteCampo())
	  if((*lSisCampo3==pSisCampoDato))
	  return 1;
return 0;
}
int SiscomRegistro3::EstaElCampo(const char *pchrPtrCampo)
{
SiscomCampo3 *lSisCampo3;
	for(lSisCampo3=SiscomColocaPrimerCampo();
	    lSisCampo3;
	    lSisCampo3=SiscomSiguienteCampo())
	   if((*lSisCampo3)==pchrPtrCampo)
	   return 1;
return 0;

}
void SiscomRegistro3::SiscomActualizaCampo(const char *pchrPtrNmbCampo,
					   const char *pchrPtrDato)
{
SCampo3Lst.SiscomActualizaCampo(pchrPtrNmbCampo,pchrPtrDato);
}

int SiscomRegistro3::EsElRegistro(const char *pchrPtrRegistro)
{
return SCampo3Lst==pchrPtrRegistro;
}

int SiscomRegistro3::Campos()
{
return SCampo3Lst.count();
}
void SiscomRegistro3::Registro(char *pchrPtrRegistro)
{
SiscomCampo3 *lSisCampo3;
*pchrPtrRegistro=0;
	for(lSisCampo3=SiscomColocaPrimerCampo();
	    lSisCampo3;
	    lSisCampo3=SiscomSiguienteCampo())
	 strcat(pchrPtrRegistro,lSisCampo3->SiscomNmbCampo());
}
SiscomRegistro3Lst::SiscomRegistro3Lst()
{

}
SiscomRegistro3Lst::~SiscomRegistro3Lst()
{

}
SiscomRegistro3Lst &SiscomRegistro3Lst::operator<<(SiscomRegistro3 *pSRegistro3)
{
	append(pSRegistro3);
	return *this;
}
SiscomRegistro3Lst &SiscomRegistro3Lst::operator<<(
			SiscomRegistro3Lst &pSisReg3LstOtro)
{
SiscomRegistro3 *lSisReg3Otro;
for(lSisReg3Otro=pSisReg3LstOtro.first();
    lSisReg3Otro;
    lSisReg3Otro=pSisReg3LstOtro.next())
	(*this) << lSisReg3Otro;
return *this;
}
SiscomRegistro3 *SiscomRegistro3Lst::operator[](int pintNProducto)
{
return  at(pintNProducto);
}
const char *SiscomRegistro3Lst::operator[](const char *pchrPtrNmbCampo)
{
return (*current())[pchrPtrNmbCampo];
}
int SiscomRegistro3Lst::operator++()
{
	next();
	return 0;
}
SiscomRegistro3Lst &SiscomRegistro3Lst::operator+=(SiscomCampo3 *pSCampo3)
{

(*current()) << pSCampo3;

return *this;
}
void SiscomRegistro3Lst::SiscomElimina()
{
setAutoDelete(true);
clear();
}
/*
 * Sabado 13 Agosto 2011
 * Es importante ver que si se requiere eliminar de una
 * lista registros, no es posible realizarlo por indice,
 * ya que al eliminar el por indice se reasignan las posiciones
 * del arreglo, por tal motivo es necesario eliminar de la
 * lista por referencia, primero se obtienen las referencias
 * de las posiciones que se desean eliminar, para posteriormente
 * eliminar los nodos por referencia, esto sobre todo al eliminar
 * una lista de productos en una tabla
 *
 */
const SiscomRegistro3Lst &SiscomRegistro3Lst::SiscomEliminaRegistros(const QMemArray<int> &pQMARegistros)
{
SiscomRegistro3Lst lSisReg3LstElimina;
SiscomRegistro3 *lSisReg3Elimina;
int lintContador;
int lintNRegistrosE=pQMARegistros.count();
for(lintContador=0;
    lintContador<lintNRegistrosE;
    lintContador++)
   lSisReg3LstElimina<<at(pQMARegistros[lintContador]);

for(lSisReg3Elimina=lSisReg3LstElimina.first();
    lSisReg3Elimina;
    lSisReg3Elimina=lSisReg3LstElimina.next())
 remove(lSisReg3Elimina);
return *this;
}
int SiscomRegistro3Lst::operator==(const char *pchrPtrRegistro)
{
SiscomRegistro3 *lSisReg3Dato=first();
return lSisReg3Dato && 
       lSisReg3Dato->EsElRegistro(pchrPtrRegistro);
}
SiscomRegistro3LstLst::SiscomRegistro3LstLst()
{

}
void SiscomRegistro3LstLst::AgregaRegistro(SiscomRegistro3 *pSisReg3Dato)
{
char lchrArrRegistro[1024];

   pSisReg3Dato->Registro(lchrArrRegistro);
   AgregaRegistro(lchrArrRegistro,pSisReg3Dato);
}
void SiscomRegistro3LstLst::SiscomAgregaRegistro(int pintNSubGrupo,
						 SiscomRegistro3 *pSisReg3Dato)
{
SiscomRegistro3Lst *lSisReg3LstSubGrupo=at(pintNSubGrupo);
if(lSisReg3LstSubGrupo)
{
 (*lSisReg3LstSubGrupo) << pSisReg3Dato;
}
 else
 {
 lSisReg3LstSubGrupo=new SiscomRegistro3Lst;
 (*lSisReg3LstSubGrupo)<<pSisReg3Dato;
 }

}
void SiscomRegistro3LstLst::ActualizaRegistro(int pintNSubGrupo,
					      int pintNRegistro,
					      SiscomRegistro3 *pSisReg3Actualiza)
{
SiscomRegistro3Lst *lSisReg3LstSubGrupo=at(pintNSubGrupo);
if(lSisReg3LstSubGrupo)
  lSisReg3LstSubGrupo->insert(pintNRegistro,pSisReg3Actualiza); 
}
void SiscomRegistro3LstLst::SiscomAgregaRegistros(int pintSubGrupo,
						  SiscomRegistro3Lst *pSisReg3LstDat)
{
SiscomRegistro3Lst *lSisReg3LstSubGrupo=at(pintSubGrupo);
if(lSisReg3LstSubGrupo)
 (*lSisReg3LstSubGrupo) << *pSisReg3LstDat;
 else
 {

 }
}
void SiscomRegistro3LstLst::SiscomAgregaSubRegistro()
{
append(new SiscomRegistro3Lst);
}
void SiscomRegistro3LstLst::AgregaRegistro(const char *pchrPtrRegistro,
					   SiscomRegistro3 *pSisReg3Dato)
{
SiscomRegistro3Lst *lSisReg3LstDato=first();;
if(lSisReg3LstDato)
{
	for(;
    		lSisReg3LstDato;
    		lSisReg3LstDato=next())
	{
	   if((*lSisReg3LstDato==pchrPtrRegistro))
	   {
	        (*lSisReg3LstDato) << pSisReg3Dato;
		return;
	   }
	}
     lSisReg3LstDato=new SiscomRegistro3Lst;
     (*lSisReg3LstDato)<<pSisReg3Dato;
     append(lSisReg3LstDato);
}
else
{
     lSisReg3LstDato=new SiscomRegistro3Lst;
     (*lSisReg3LstDato)<<pSisReg3Dato;
     append(lSisReg3LstDato);
}
}
				

SiscomRegistro3Lst *SiscomRegistro3LstLst::operator[](int pintNGpoRegistro)
{
	return at(pintNGpoRegistro);
}

void SiscomContenidoRegistro3Log(const char *pchrPtrArchivo,
				 const char *pchrPtrFuncion,
				 int pintNLinea,
				 SiscomRegistro3 *pSisReg3Dato)
{
SiscomCampo3 *lSisCampo3;
if(pSisReg3Dato)
for(lSisCampo3=pSisReg3Dato->SiscomColocaPrimerCampo();
    lSisCampo3;
    lSisCampo3=pSisReg3Dato->SiscomSiguienteCampo())
{
SiscomMensajesLog3Qt(pchrPtrArchivo,
		     pchrPtrFuncion,
		     pintNLinea,
		     "{%s} (%s)",
		     lSisCampo3->SiscomNmbCampo(),
		     lSisCampo3->SiscomDato());
}
else
SiscomMensajesLog3Qt(pchrPtrArchivo,
		     pchrPtrFuncion,
		     pintNLinea,
		     "Registro NULO");
}
void EncabezadoRegistroLst(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintNLinea,
			   SiscomRegistro3 *pSRegistro3Dat)
{
char lchrArrEncabezado[1024];
char lchrArrPaso[128];
int lintContador;
SiscomCampo3 *lSisCampo3;

for(lSisCampo3=pSRegistro3Dat->SiscomColocaPrimerCampo(),
    lintContador=0;
    lSisCampo3;
    lSisCampo3=pSRegistro3Dat->SiscomSiguienteCampo(),
    lintContador++)
{
  sprintf(lchrArrPaso,"{ %s }",lSisCampo3->SiscomNmbCampo());
 if(!lintContador)
  strcpy(lchrArrEncabezado,lchrArrPaso); 
 else
  strcat(lchrArrEncabezado,lchrArrPaso);
}
SiscomMensajesLog3Qt(pchrPtrArchivo,
		     pchrPtrFuncion,
		     pintNLinea,
		     "%s",
		     lchrArrEncabezado);
}
void SiscomContenidoRegistroLstLog(const char *pchrPtrArchivo,
				   const char *pchrPtrFuncion,
				   int pintNLinea,
				   SiscomRegistro3Lst *pSRegistro3LstDat)
{
SiscomRegistro3 *lSRegistro3Dat;
SiscomCampo3 *lSisCampo3;
int lintContador;
int lintContadorC;
char lchrArrRegistro[1024];
char lchrArrPaso[1024];
if(pSRegistro3LstDat)
for(lSRegistro3Dat=pSRegistro3LstDat->first(),
    lintContador=0;
    lSRegistro3Dat;
    lSRegistro3Dat=pSRegistro3LstDat->next(),
    lintContador++)
{
   if(!lintContador)
   EncabezadoRegistroLst(pchrPtrArchivo,
   			 pchrPtrFuncion,
			 pintNLinea,
			 (*pSRegistro3LstDat)[0]);
 
   for(lSisCampo3=lSRegistro3Dat->SiscomColocaPrimerCampo(),
       lintContadorC=0;
       lSisCampo3;
       lSisCampo3=lSRegistro3Dat->SiscomSiguienteCampo(),
       lintContadorC++)
   {
	   sprintf(lchrArrPaso,"%s|",lSisCampo3->SiscomDato());
	if(!lintContadorC)
	   strcpy(lchrArrRegistro,lchrArrPaso);
	else
	   strcat(lchrArrRegistro,lchrArrPaso);
    
   }

	SiscomMensajesLog3Qt(pchrPtrArchivo,
			     pchrPtrFuncion,
			     pintNLinea,
			     "%s",lchrArrRegistro);
}
}
