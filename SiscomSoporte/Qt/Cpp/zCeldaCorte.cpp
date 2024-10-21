#include <zCeldaCorte.h>
#include <zSiscomCampo.h>

zCeldaCorte::zCeldaCorte(int pintFila,
		    int pintColumna,
		    const char *pchrPtrCampo,
		    const char *pchrPtrValor,
		    const char *pchrPtrColor):
		    intFila(pintFila),
		    intColumna(pintColumna)

{
  (*this) 	<< 
  new zSiscomCampo("Campo",(const unsigned char *)pchrPtrCampo) <<
  new zSiscomCampo("Valor",(const unsigned char *)pchrPtrValor)	<<
  new zSiscomCampo("Color",(const unsigned char *)pchrPtrColor);
}

zCeldaCorte::zCeldaCorte()
{

  (*this) << new zSiscomCampo("Campo") 
          << new zSiscomCampo("Fila") 
	  << new zSiscomCampo("Columna") 
	  << new zSiscomCampo("Valor")
	  << new zSiscomCampo("Editable")
	  << new zSiscomCampo("Color") ;
}
void zCeldaCorte::Campo(const char *pchrPtrCampo)
{
    ActualizaCampo("Campo",(const unsigned char *)pchrPtrCampo);
}

void zCeldaCorte::Fila(const char *pchrPtrFila)
{
    ActualizaCampo("Fila",(const unsigned char *)pchrPtrFila);
}
void zCeldaCorte::Columna(const char *pchrPtrColumna)
{
    ActualizaCampo("Columna",(const unsigned char *)pchrPtrColumna);
}
void zCeldaCorte::Valor(const char *pchrPtrValor)
{
    ActualizaCampo("Valor",(const unsigned char *)pchrPtrValor);
}
void zCeldaCorte::Color(const char *pchrPtrColor)
{
    ActualizaCampo("Color",(const unsigned char *)pchrPtrColor);
}
const char *zCeldaCorte::Campo()
{
   return (const char *)(*this)["Campo"];
}
const char *zCeldaCorte::Fila()
{
   return (const char *)(*this)["Fila"];
}
const char *zCeldaCorte::Columna()
{
   return (const char *)(*this)["Columna"];
}
int zCeldaCorte::Valor()
{
   return CampoInt("Valor");
}
int zCeldaCorte::Editable()
{
   return CampoInt("Editable");
}
const char *zCeldaCorte::Color()
{
    return (const char *)(*this)["Color"];
}
int zCeldaCorte::FilaInt()
{
  return intFila;
}
int zCeldaCorte::ColumnaInt()
{
  return intColumna;
}
