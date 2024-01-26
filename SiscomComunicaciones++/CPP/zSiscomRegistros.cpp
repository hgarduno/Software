#include <zSiscomRegistros.h>
#include <zSiscomCampo.h>
#include <zSiscomRegistro.h>
#include <zSiscomFechaHora.h>
#include <zSiscomDesarrollo4.h>
#include <string.h>
#include <stdlib.h>
zSiscomRegistros::zSiscomRegistros()
{


}
zSiscomRegistros &zSiscomRegistros::operator<<(zSiscomRegistro *pzSisRegistro)
{
	Agrega(pzSisRegistro);
	return *this;
}
int zSiscomRegistros::BuscaCampoRegistro(zSiscomRegistro *pzSisRegistro,
						      const char *pchrPtrCampo,
						      const unsigned char *pchrPtrDato)
{
zSiscomCampo *lzSisCampo;
for(lzSisCampo=pzSisRegistro->Primer();
     lzSisCampo;
     lzSisCampo=pzSisRegistro->Siguiente())
{
   if(!strcmp(lzSisCampo->Nombre(),pchrPtrCampo) &&
      !strcmp((const char *)lzSisCampo->Dato(),(const char *)pchrPtrDato))
    return 1;
}
return 0;     
}
zSiscomRegistro *zSiscomRegistros::PorCampoDato(const char *pchrPtrCampo,
						const unsigned  char *pchrPtrDato)
{
zSiscomRegistro *lzSisRegistro;
for(lzSisRegistro=Primer();
    lzSisRegistro;
    lzSisRegistro=Siguiente())
{
   if(BuscaCampoRegistro(lzSisRegistro,pchrPtrCampo,pchrPtrDato))
	return lzSisRegistro;
}
return 0;
}

zSiscomRegistros &zSiscomRegistros::operator=(zSiscomRegistros &pzSisRegsDatos)
{
zSiscomRegistro *lzSisRegDato;
for(lzSisRegDato=pzSisRegsDatos.Primer();
    lzSisRegDato;
    lzSisRegDato=pzSisRegsDatos.Siguiente())
    (*this) << lzSisRegDato;

return *this;
}
zSiscomRegistro *zSiscomRegistros::operator[](int pintNRegistro)
{
zSiscomRegistro *lzSisRegDato;
int lintContador;
for(lzSisRegDato=Primer(),lintContador=0;
    lzSisRegDato;
    lzSisRegDato=Siguiente(), lintContador++)
 if(lintContador==pintNRegistro)
  return lzSisRegDato;
return 0;
}

zSiscomRegistros &zSiscomRegistros::operator+=(zSiscomRegistros &pzSisRegsDatos)
{
zSiscomRegistro *lzSisRegDato;
for(lzSisRegDato=pzSisRegsDatos.Primer();
    lzSisRegDato;
    lzSisRegDato=pzSisRegsDatos.Siguiente())
    (*this) << lzSisRegDato;
return *this;
}
const char *zSiscomRegistros::CampoRegistro(int pintNRegistro,
					    const char *pchrPtrCampo)
{
zSiscomRegistro *lzSisRegRegreso;
if((lzSisRegRegreso=(*this)[pintNRegistro]))
return (const char *)(*lzSisRegRegreso)[pchrPtrCampo];
else
return 0;
}
int zSiscomRegistros::CampoRegistroInt(int pintNRegistro,
				       const char *pchrPtrCampo)
{
const char *lchrPtrDato;
if((lchrPtrDato=CampoRegistro(pintNRegistro,pchrPtrCampo)))
    return atoi(lchrPtrDato);
else
return -65000;
}
zSiscomRegistros &zSiscomRegistros::ListaCadenas(const char *pchrPtrNombreCampo,
						 char **pchrPtrCadenas)
{
zSiscomRegistro *lzSisRegRegistro;
    while(*pchrPtrCadenas)
    {
    	lzSisRegRegistro=new zSiscomRegistro;
	(*lzSisRegRegistro) << 
	new zSiscomCampo(pchrPtrNombreCampo,(const unsigned char *)(*pchrPtrCadenas));
	(*this) << lzSisRegRegistro;
	pchrPtrCadenas++;
    }
    return *this;
}
zSiscomRegistros &zSiscomRegistros::CadenaConSeparador(const char *pchrPtrNombreCampo,
							const char *pchrPtrCadena,
							char pchrSeparador)
{
char **lchrPtrCadenas;
if(zSiscomDesarrollo4::CadenasPorSeparador(pchrPtrCadena,pchrSeparador,&lchrPtrCadenas))
return ListaCadenas(pchrPtrNombreCampo,lchrPtrCadenas);
}
void SiscomRegistrosAlLog(const char *pchrPtrArchivo,
			  const char *pchrPtrFuncion,
			  int pintNoLinea,
			  zSiscomRegistros *pzSisRegistrosDat)
{
zSiscomRegistro *lzSisRegDato;
zSiscomCampo *lzSisCampo;
char lchrArrFecha[64];
if((lzSisRegDato=pzSisRegistrosDat->Primer()))
{
fprintf(gPtrFleArchivoLog,
	"(%s) ( %s %s %d ) ",
	zSiscomFechaHora::Actual3(lchrArrFecha),
	pchrPtrArchivo,
	pchrPtrFuncion,
	pintNoLinea);
for(lzSisCampo=lzSisRegDato->Primer();
    lzSisCampo;
    lzSisCampo=lzSisRegDato->Siguiente())
fprintf(gPtrFleArchivoLog,"%s ",lzSisCampo->Nombre());
fprintf(gPtrFleArchivoLog,"\n");
for(;
    lzSisRegDato;
    lzSisRegDato=pzSisRegistrosDat->Siguiente())
{
fprintf(gPtrFleArchivoLog,
        "(%s) ( %s %s %d ) ",
	zSiscomFechaHora::Actual3(lchrArrFecha),
	pchrPtrArchivo,
	pchrPtrFuncion,
	pintNoLinea);
for(lzSisCampo=lzSisRegDato->Primer();
    lzSisCampo;
    lzSisCampo=lzSisRegDato->Siguiente())
   fprintf(gPtrFleArchivoLog,"%s|",lzSisCampo->Dato() ? lzSisCampo->Dato() :(const unsigned char *)"");
fprintf(gPtrFleArchivoLog,"\n");
}
}
else
{
fprintf(gPtrFleArchivoLog,
	"(%s) ( %s %s %d ) Apuntador NULO\n",
	zSiscomFechaHora::Actual3(lchrArrFecha),
	pchrPtrArchivo,
	pchrPtrFuncion,
	pintNoLinea);

}
fflush(gPtrFleArchivoLog);
}

zSiscomRegistros *zSiscomRegistros::Respalda()
{
zSiscomRegistros *lzSisRegsRespaldo;
zSiscomRegistro *lzSisRegistro;
lzSisRegsRespaldo=new zSiscomRegistros;
for(lzSisRegistro=Primer();
    lzSisRegistro;
    lzSisRegistro=Siguiente())
 (*lzSisRegsRespaldo)<<lzSisRegistro;

return lzSisRegsRespaldo;
}
void zSiscomRegistros::EliminaCampo(const char *pchrPtrCampo)
{
zSiscomRegistro *lzSisRegRegreso;
const char *lchrPtrDato;
for(lzSisRegRegreso=Primer();lzSisRegRegreso;lzSisRegRegreso=Siguiente())
  lzSisRegRegreso->EliminaCampo(pchrPtrCampo);
}
zSiscomRegistro *zSiscomRegistros::BuscaRegistro(const char *pchrPtrCampo,
					         const char *pchrPtrDato)
{
zSiscomRegistro *lzSisRegRegreso;
const char *lchrPtrDato;
for(lzSisRegRegreso=Primer();lzSisRegRegreso;lzSisRegRegreso=Siguiente())
{
   if(lzSisRegRegreso->EstaElCampoEnElRegistro(pchrPtrCampo))
   {
     if((lchrPtrDato=(const char *)lzSisRegRegreso->Campo(pchrPtrCampo)))
     {
     if(!strcmp(lchrPtrDato,pchrPtrDato))
     return lzSisRegRegreso;
     }
   }
}

return 0;
}
