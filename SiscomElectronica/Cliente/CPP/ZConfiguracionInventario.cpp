#include <ZConfiguracionInventario.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomCampo.h>

#include <errno.h>
#include <string.h>
ZConfiguracionInventario::ZConfiguracionInventario(const char *pchrPtrArchivo)
{
AbreArchivo(pchrPtrArchivo);
LeeConfiguracion();
}
void ZConfiguracionInventario::Campos(const char *pchrPtrCampo)
{
  	(*this) << new zSiscomCampo(pchrPtrCampo); 
}
void ZConfiguracionInventario::AbreArchivo(const char *pchrPtrArchivo)
{

if(!(FlePtrArchivo=fopen(pchrPtrArchivo,"r")))
{
    LogSiscom("NO Se pudo abrir %s (%s)",
    		pchrPtrArchivo,
		strerror(errno));
}

}
void ZConfiguracionInventario::DatosLinea(const char *pchrPtrDatoLinea,
					  char **pchrPtrNombre,
					  char **pchrPtrDato)
{
const char *lchrPtrDato;
char **lchrPtrCadenas;
LogSiscom("%s",pchrPtrDatoLinea);
zSiscomDesarrollo4::CadenasPorSeparador(pchrPtrDatoLinea,'|',&lchrPtrCadenas);
*pchrPtrNombre=*lchrPtrCadenas;
*pchrPtrDato=*(lchrPtrCadenas+1);

}
void ZConfiguracionInventario::ProcesaLinea(const char *pchrPtrLinea)
{
char **lchrPtrCampos,
	*lchrPtrDato,
	*lchrPtrNombre;
int lintContador=0,
	lintNCampos;
lintNCampos=zSiscomDesarrollo4::CadenasPorSeparador(pchrPtrLinea,'@',&lchrPtrCampos);
LogSiscomCadenas(lchrPtrCampos);
for(lintContador=0;lintContador<lintNCampos;lintContador++)
{
   DatosLinea(*(lchrPtrCampos+lintContador+1),&lchrPtrNombre,&lchrPtrDato);
   LogSiscom("%s->%s",lchrPtrNombre,lchrPtrDato);

}

}
void ZConfiguracionInventario::LeeConfiguracion()
{
char lchrArrLinea[128];
     while(!zSiscomDesarrollo4::LeeLinea(FlePtrArchivo,lchrArrLinea))
     {
     	zSiscomDesarrollo4::EliminaEspaciosInicio(lchrArrLinea);	
	if(lchrArrLinea[0]!='#')
	ProcesaLinea(lchrArrLinea);
     }
}
