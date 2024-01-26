#include <zSiscomRecibe.h>
#include <zSiscomCampo.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
zSiscomRecibe::zSiscomRecibe()
{

}
zSiscomRecibe::zSiscomRecibe(zSiscomConexion *pzSisConexion):
					zSisConexion(pzSisConexion)
{
}
zSiscomRegistros *zSiscomRecibe::Registros()
{
int lintRegistros=CaracteresInt(5);
int lintContador,
    lintCampos;
zSiscomRegistros *lzSisRegistros=new zSiscomRegistros;

for(lintContador=0;
    lintContador<lintRegistros;
    lintContador++)
{ 
  lintCampos=CaracteresInt(5);
  (*lzSisRegistros) << Registro(lintCampos); 
  CaracteresInt(5);
}
return lzSisRegistros;
}
zSiscomRegistro *zSiscomRecibe::Registro(int pintCampos)
{
zSiscomCampo *lzSisCampo;
zSiscomRegistro *lzSisRegistro=new zSiscomRegistro;
int lintContador;
for(lintContador=0;lintContador<pintCampos;lintContador++)
{
  lzSisCampo=Campo();
  Asociados(lzSisCampo);
 (*lzSisRegistro) << lzSisCampo;
}
return lzSisRegistro;
}
void zSiscomRecibe::Asociados(zSiscomCampo *pzSisCampo)
{
 if(CaracteresInt(1))
 {
 pzSisCampo->Asociados(Registros());
 Caracteres(5);
 }
}
zSiscomCampo *zSiscomRecibe::Campo()
{
zSiscomCampo *lzSisCampo;
char *lchrPtrNombre;
unsigned char *lchrPtrDato;
lzSisCampo=new zSiscomCampo;
lzSisCampo->Nombre((const char *)DatoCampo());
lzSisCampo->Dato(DatoCampo());
return lzSisCampo;
}
unsigned char *zSiscomRecibe::DatoCampo()
{
int lintTamano=CaracteresInt(5);
if(lintTamano!=0)
return Caracteres(lintTamano);
else
return 0;
}
unsigned char *zSiscomRecibe::Caracteres(int pintCaracteres)
{
int lintCaracteres;
unsigned char *lchrPtrBuffer=MemoriaLectura(pintCaracteres);
for(lintCaracteres=0;lintCaracteres<pintCaracteres;lintCaracteres++) 
read(zSisConexion->Socket(),lchrPtrBuffer+lintCaracteres,1);
*(lchrPtrBuffer+lintCaracteres)=0;
return lchrPtrBuffer;
}
unsigned char *zSiscomRecibe::MemoriaLectura(int pintCaracteres)
{
unsigned char *lchrPtrRegreso;
if((lchrPtrRegreso=(unsigned char *)malloc(pintCaracteres+1)))
   return lchrPtrRegreso;
return 0;
}
int zSiscomRecibe::CaracteresInt(int pintCaracteres)
{
unsigned char *lchrPtrRegreso;
int lintRegreso;
if((lchrPtrRegreso=Caracteres(pintCaracteres)))
{
   lintRegreso=atoi((const char *)lchrPtrRegreso);
   free(lchrPtrRegreso);
   return lintRegreso;
}
}
zSiscomRegistros *zSiscomRecibe::Respuesta()
{
 return Registros();
}
