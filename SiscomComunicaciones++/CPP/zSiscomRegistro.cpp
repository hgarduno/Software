#include <zSiscomCampo.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomFechaHora.h>
#include <zSiscomDesarrollo4.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
zSiscomRegistro::zSiscomRegistro()
{

}

void zSiscomRegistro::AgregaCampo(zSiscomCampo *pzSisCampoDato)
{
	Agrega(pzSisCampoDato);
}

void zSiscomRegistro::AgregaCamposDelRegistro(zSiscomRegistro *pzSiscomRDato)
{
    zSisNodoAct->zSisNodoSig=pzSiscomRDato->zSisNodoPrim; 
    zSisOperacionesListas::NNodos(NNodos()+pzSiscomRDato->NNodos());
}
void zSiscomRegistro::AgregaCampo(const char *pchrPtrCampo,
				  const unsigned char *pchrPtrDato)
{
      Agrega(new zSiscomCampo(pchrPtrCampo,pchrPtrDato));
}

void zSiscomRegistro::AgregaCampo(const char *pchrPtrCampo,
				  zSiscomRegistro *pzSisRegAsociado)
{
      Agrega(new zSiscomCampo(pchrPtrCampo,(const unsigned char *)0));
      AsociadoAlCampo(pchrPtrCampo,pzSisRegAsociado);
}

zSiscomRegistro::~zSiscomRegistro()
{
const unsigned char *lchrPtrDato;
if(NNodos())
{
zSiscomCampo *lzSisCampo;
for(lzSisCampo=Primer();
    lzSisCampo;
    lzSisCampo=Siguiente())
{
	lchrPtrDato=lzSisCampo->Dato();
	free((void *)lzSisCampo->Nombre());
	if(lchrPtrDato && 
	   *lchrPtrDato)
	free((void *)lzSisCampo->Dato());
	delete lzSisCampo;
}
}
}

zSiscomRegistro &zSiscomRegistro::operator<<(zSiscomCampo *pzSisCampo)
{
  	Agrega(pzSisCampo);
	return *this;
}

void zSiscomRegistro::AsociadosAlCampo(const char *pchrPtrCampo,
				       zSiscomRegistros *pzSisRegistros)
{
zSiscomCampo lzSisCampoBusca(pchrPtrCampo,(const unsigned char *)0);
zSiscomCampo *lzSisCampo=Nodo(lzSisCampoBusca);
lzSisCampo->Asociados(pzSisRegistros);
}
void zSiscomRegistro::AsociadoAlCampo(const char *pchrPtrCampo,
				      zSiscomRegistro *pzSisRegistro)
{
zSiscomRegistros *lzSisRegsAsociados ;
zSiscomCampo lzSisCampoBusca(pchrPtrCampo,(const unsigned char *)0);
zSiscomCampo *lzSisCampo=Nodo(lzSisCampoBusca);
if((lzSisRegsAsociados=lzSisCampo->Asociados()))
   (*lzSisRegsAsociados)<<pzSisRegistro;
else
{
   lzSisRegsAsociados=new zSiscomRegistros;
   (*lzSisRegsAsociados)<<pzSisRegistro;
   lzSisCampo->Asociados(lzSisRegsAsociados);
}
}
const unsigned char *zSiscomRegistro::Campo(const char *pchrPtrCampo)
{
zSiscomCampo *lzSisCampo;
zSiscomCampo lzSisCampoBusca(pchrPtrCampo,(const unsigned char *)0);
     if((lzSisCampo=Nodo(lzSisCampoBusca)))
return lzSisCampo->Dato();
else
return 0;
}
int zSiscomRegistro::EstaElCampoEnElRegistro(const char *pchrPtrCampo)
{
zSiscomCampo *lzSisCampo;
zSiscomCampo lzSisCampoBusca(pchrPtrCampo,(const unsigned char *)0);
     if((lzSisCampo=Nodo(lzSisCampoBusca)))
return 1;
else
return 0;
}

int zSiscomRegistro::CampoInt(const char *pchrPtrCampo)
{
  return CampoDato(pchrPtrCampo)->DatoInt(); 
}
float zSiscomRegistro::CampoFloat(const char *pchrPtrCampo)
{
  return CampoDato(pchrPtrCampo)->DatoInt(); 
}

const unsigned char *zSiscomRegistro::operator[](const char *pchrPtrCampo)
{
    return Campo(pchrPtrCampo);
}
const char *zSiscomRegistro::CampoConstChar(const char *pchrPtrCampo)
{
   return (const char *)Campo(pchrPtrCampo);   
}
zSiscomCampo *zSiscomRegistro::CampoDato(const char *pchrPtrCampo)
{
zSiscomCampo *lzSisCampo;
zSiscomCampo lzSisCampoBusca(pchrPtrCampo,(const unsigned char *)0);
     if((lzSisCampo=Nodo(lzSisCampoBusca)))
return lzSisCampo;
else
return 0;
}
zSiscomRegistros *zSiscomRegistro::AsociadosDelCampo(const char *pchrPtrCampo)
{
zSiscomCampo *lzSisCampo;
zSiscomCampo lzSisCampoBusca(pchrPtrCampo,(const unsigned char *)0);
     if((lzSisCampo=Nodo(lzSisCampoBusca)))
return lzSisCampo->Asociados();
else
return 0;

}
/* Queretaro, Martes 5 de Enero del 2016 
 * Cuando el campo asociado tiene solo un registro ....
 */
zSiscomRegistro *zSiscomRegistro::AsociadoDelCampo(const char *pchrPtrCampo)
{
zSiscomRegistros *lzSisRegAsociados;
if((lzSisRegAsociados=AsociadosDelCampo(pchrPtrCampo)))
return lzSisRegAsociados->Primer();
else
return 0;
}
void zSiscomRegistro::ActualizaCampo(const char *pchrPtrCampo,
				     const unsigned char *pchrPtrDato)
{
zSiscomCampo lzSisCampoBusca(pchrPtrCampo);
zSiscomCampo *lzSisCampo;
     if((lzSisCampo=Nodo(lzSisCampoBusca)))
	lzSisCampo->Dato(pchrPtrDato);
     else
     LogSiscom("No se encontrol el campo %s",pchrPtrCampo);
}
void zSiscomRegistro::ActualizaCampo(const char *pchrPtrCampo,int pintDato)
{
char lchrArrDato[12];
 sprintf(lchrArrDato,"%d",pintDato);
 ActualizaCampo(pchrPtrCampo,(const unsigned char *)lchrArrDato);
}
void zSiscomRegistro::ActualizaCampo(const char *pchrPtrCampo,
				     zSiscomRegistro *pzSisRegCampo)
{
zSiscomCampo lzSisCampoBusca(pchrPtrCampo);
zSiscomCampo *lzSisCampo;
     if((lzSisCampo=Nodo(lzSisCampoBusca)))
	lzSisCampo->Dato(pzSisRegCampo);
     else
     LogSiscom("No se encontrol el campo %s",pchrPtrCampo);
}
void zSiscomRegistro::ActualizaCampo(const char *pchrPtrCampo,
				     zSiscomRegistros *pzSisRegsCampo)
{
zSiscomCampo lzSisCampoBusca(pchrPtrCampo);
zSiscomCampo *lzSisCampo;
     if((lzSisCampo=Nodo(lzSisCampoBusca)))
	lzSisCampo->Dato(pzSisRegsCampo);
     else
     LogSiscom("No se encontrol el campo %s",pchrPtrCampo);
}


void zSiscomRegistro::ActualizaCampoAsociado(const char *pchrPtrAsociado,
					     const char *pchrPtrCampo,
					     const unsigned char *pchrPtrDato)
{
zSiscomRegistro *lzSisRegAsociado;
if((lzSisRegAsociado=AsociadoDelCampo(pchrPtrAsociado)))
 lzSisRegAsociado->ActualizaCampo(pchrPtrCampo,pchrPtrDato);
else
LogSiscom("No se encontro el Campo Asociado %s",pchrPtrAsociado);

}
int zSiscomRegistro::EsElValorCampo(const char *pchrPtrCampo,
				    const char *pchrPtrValor)
{
const char *lchrPtrDato=(const char *)Campo(pchrPtrCampo);
return (lchrPtrDato &&
    !strcmp(lchrPtrDato,pchrPtrValor));
}
zSiscomRegistro &zSiscomRegistro::operator=(zSiscomRegistro &pzSiscomRegistro)
{
zSiscomCampo *lzSiscomCampo;
for(lzSiscomCampo=pzSiscomRegistro.Primer(); 
    lzSiscomCampo;
    lzSiscomCampo=pzSiscomRegistro.Siguiente())
 (*this) << lzSiscomCampo;
return *this;

}
zSiscomRegistro *zSiscomRegistro::Copia(zSiscomRegistro *pzSiscomRegistro)
{
zSiscomCampo *lzSiscomCampo;
for(lzSiscomCampo=pzSiscomRegistro->Primer(); 
    lzSiscomCampo;
    lzSiscomCampo=pzSiscomRegistro->Siguiente())
 (*this) << new zSiscomCampo(lzSiscomCampo->Nombre(),lzSiscomCampo->Dato());
return this;

}

zSiscomRegistro *zSiscomRegistro::Registro(const char *pchrPtrFormato,
					       ...)
{
char lchrArrNmbCampo[512];
va_list lzArgumentos;
const char *lzCadenaFormato=pchrPtrFormato;
char  lzMen[1024];
unsigned char *lzParametroChar;
zSiscomRegistros *lzParametroSiscomRegistros;
int liPos=0;
zSiscomRegistro *lzSisRegistro=new zSiscomRegistro;
        va_start(lzArgumentos,pchrPtrFormato);
        do
        {
                if(*lzCadenaFormato=='%')
                {
                        *lzCadenaFormato++;
                        switch(*lzCadenaFormato)
                        {
                          case 's':
                                lzMen[liPos]=0;
                                lzParametroChar=va_arg(lzArgumentos,unsigned char *);
				                lzCadenaFormato++;
				                lzCadenaFormato=(char *)zSiscomDesarrollo4::CadenaEntreSeparadores(lzCadenaFormato,'[',']',lchrArrNmbCampo);
				                (*lzSisRegistro) << new zSiscomCampo(lchrArrNmbCampo,lzParametroChar);
                                liPos=0;
                          break;
                          case 'a':
                                lzMen[liPos]=0;
                                lzParametroSiscomRegistros=va_arg(lzArgumentos,zSiscomRegistros *);
				                lzCadenaFormato++;
				                lzCadenaFormato=(char *)zSiscomDesarrollo4::CadenaEntreSeparadores(lzCadenaFormato,'[',']',lchrArrNmbCampo);
				                (*lzSisRegistro) << new zSiscomCampo(lchrArrNmbCampo);
                                AsociadosAlCampo(lchrArrNmbCampo,lzParametroSiscomRegistros);
                                liPos=0;
                          break;
                        }
                     lzMen[0]=0;
                }
                else
                {
                        lzMen[liPos]=*lzCadenaFormato;
                        liPos++;
                }
         }while(*lzCadenaFormato++);
        lzMen[liPos]=0;
        va_end(lzArgumentos);
return lzSisRegistro;
}

zSiscomRegistro *zSiscomRegistro::Registro(zSiscomRegistro *pzSiscomRDato,
					   const char *pchrPtrFormato,
					       ...)
{
char lchrArrNmbCampo[512];
va_list lzArgumentos;
const char *lzCadenaFormato=pchrPtrFormato;
char  lzMen[1024];
unsigned char *lzParametroChar;
zSiscomRegistros *lzParametroSiscomRegistros;
int liPos=0;
zSiscomRegistro *lzSisRegistro=new zSiscomRegistro;
        va_start(lzArgumentos,pchrPtrFormato);
        do
        {
                if(*lzCadenaFormato=='%')
                {
                        *lzCadenaFormato++;
                        switch(*lzCadenaFormato)
                        {
                          case 's':
                                lzMen[liPos]=0;
                                lzParametroChar=va_arg(lzArgumentos,unsigned char *);
				                lzCadenaFormato++;
				                lzCadenaFormato=(char *)zSiscomDesarrollo4::CadenaEntreSeparadores(lzCadenaFormato,'[',']',lchrArrNmbCampo);
				                (*lzSisRegistro) << new zSiscomCampo(lchrArrNmbCampo,lzParametroChar);
                                liPos=0;
                          break;
                          case 'a':
                                lzMen[liPos]=0;
                                lzParametroSiscomRegistros=va_arg(lzArgumentos,zSiscomRegistros *);
				                lzCadenaFormato++;
				                lzCadenaFormato=(char *)zSiscomDesarrollo4::CadenaEntreSeparadores(lzCadenaFormato,'[',']',lchrArrNmbCampo);
				                (*lzSisRegistro) << new zSiscomCampo(lchrArrNmbCampo);
                                AsociadosAlCampo(lchrArrNmbCampo,lzParametroSiscomRegistros);
                                liPos=0;
                          break;
                        }
                     lzMen[0]=0;
                }
                else
                {
                        lzMen[liPos]=*lzCadenaFormato;
                        liPos++;
                }
         }while(*lzCadenaFormato++);
        lzMen[liPos]=0;
        va_end(lzArgumentos);
lzSisRegistro->AgregaCamposDelRegistro(pzSiscomRDato);
return lzSisRegistro;
}


const unsigned char *zSiscomRegistro::CampoAsociado(const char *pchrPtrAsociado,
						    const char *pchrPtrCampo)
{
zSiscomRegistro *lzSisRegistro;
if((lzSisRegistro=AsociadoDelCampo(pchrPtrAsociado)))
   return (*lzSisRegistro)[pchrPtrCampo]; 
else
return 0;
}
int zSiscomRegistro::CampoAsociadoInt(const char *pchrPtrAsociado,
				   const char *pchrPtrCampo)
{
   return atoi((const char *)CampoAsociado(pchrPtrAsociado,pchrPtrCampo));  

}
/* Tepotzotlan Mexico a Viernes 8 de Enero del 2015
 *
 * Se debe pensar la manera de generalizar esta funcion,
 * pasando una lista de argumentos variables, para poder 
 * accesar a varios campos asociados hasta llegar al campo
 * que se requiere accesar
 *
 */
const unsigned char *zSiscomRegistro::CampoAsociadoAsociado(const char *pchrPtrAsociado,
							    const char *pchrPtrAsociadoA,
							    const char *pchrPtrCampo)
{
zSiscomRegistro *lzSisRegistro,*lzSisRegistroA;
if((lzSisRegistro=AsociadoDelCampo(pchrPtrAsociado)))
{
  if((lzSisRegistroA=lzSisRegistro->AsociadoDelCampo(pchrPtrAsociadoA)))
   return (*lzSisRegistroA)[pchrPtrCampo];
   else
   return 0;
}
else
return 0;

}
zSiscomRegistro *zSiscomRegistro::Duplica()
{
zSiscomRegistro *lzSisRegDuplicado;
lzSisRegDuplicado=DuplicaCampos(this);
return lzSisRegDuplicado;
}

zSiscomRegistro *zSiscomRegistro::DuplicaCampos(zSiscomRegistro *pzSisRegDato)
{
zSiscomCampo *lzSisPtrCampo;
zSiscomRegistro *lzSisRegDuplicado=new zSiscomRegistro;
  for(lzSisPtrCampo=pzSisRegDato->Primer(); lzSisPtrCampo; lzSisPtrCampo=pzSisRegDato->Siguiente())
  { 
        (*lzSisRegDuplicado) << new zSiscomCampo(lzSisPtrCampo);
       if(lzSisPtrCampo->Asociados())
       DuplicaAsociados(lzSisPtrCampo,lzSisRegDuplicado);

  }
return lzSisRegDuplicado;
}
void zSiscomRegistro::DuplicaAsociados(zSiscomCampo *pzSisCamDato,zSiscomRegistro *pzSisRegDato)
{
 zSiscomRegistros *lzSisRegsAs;
 zSiscomRegistro *lzSisRegAs;
 if((lzSisRegsAs=pzSisCamDato->Asociados()))
 {
 zSiscomRegistros *lzSisRegsAsociados=new zSiscomRegistros;
     for(lzSisRegAs=lzSisRegsAs->Primer();lzSisRegAs; lzSisRegAs=lzSisRegsAs->Siguiente())
  	  (*lzSisRegsAsociados) << DuplicaCampos(lzSisRegAs);           
      pzSisRegDato->AsociadosAlCampo(pzSisCamDato->Nombre(),lzSisRegsAsociados);
 }
}
void zSiscomRegistro::EliminaCampo(const char *pchrPtrCampo)
{
  zSiscomCampo *lzSisCampo=CampoDato(pchrPtrCampo);
  if(lzSisCampo)
  Elimina(lzSisCampo); 
}

int zSiscomRegistro::CampoVsCadena(const char *pchrPtrCampo,const char *pchrPtrCadena)
{
   return strcmp((const char *)Campo(pchrPtrCampo),pchrPtrCadena);
}

void SiscomRegistroAlLog2(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintNoLinea,
			   zSiscomRegistro *pzSisRegistroDat)
{
char lchrArrFechaHora[45];
zSiscomCampo *lzSisCampo;
if(pzSisRegistroDat)
{
fprintf(gPtrFleArchivoLog,
	"%s ( %s %s %d ) ",
	zSiscomFechaHora::Actual3(lchrArrFechaHora),
	pchrPtrArchivo,
	pchrPtrFuncion,
	pintNoLinea);
for(lzSisCampo=pzSisRegistroDat->Primer();
    lzSisCampo;
    lzSisCampo=pzSisRegistroDat->Siguiente())
fprintf(gPtrFleArchivoLog,"%s ",lzSisCampo->Nombre());
fprintf(gPtrFleArchivoLog,"\n");
fprintf(gPtrFleArchivoLog,"\t\t\t\t\t     ");
for(lzSisCampo=pzSisRegistroDat->Primer();
    lzSisCampo;
    lzSisCampo=pzSisRegistroDat->Siguiente())
   fprintf(gPtrFleArchivoLog,
           "%s |",
	   lzSisCampo->Dato() ? lzSisCampo->Dato() :(const unsigned char *)"");
fprintf(gPtrFleArchivoLog,"\n");
fflush(gPtrFleArchivoLog);
}
else
fprintf(gPtrFleArchivoLog,
	"%s ( %s %s %d ) %s\n",
	zSiscomFechaHora::Actual3(lchrArrFechaHora),
	pchrPtrArchivo,
	pchrPtrFuncion,
	pintNoLinea,
	"Registro Nulo");
}

