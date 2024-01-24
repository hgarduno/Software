#include <zXY.h>
#include <string.h>
zXY::zXY()
{

}
zXY::zXY(int pintX,int pintY):intX(pintX),
			      intY(pintY)
{


}
void zXY::Inicia()
{
   intXActual=intX;
   intYActual=intY;
}
void zXY::X(int pintX)
{
    intX=intXActual=pintX;
}
void zXY::Y(int pintY)
{
  intYActual=intY=pintY;
}

void zXY::IncrementaX()
{
  intXActual+=intIncrementoX;
}
void zXY::IncrementaY()
{
  intYActual+=intIncrementoY;
}
void zXY::Incrementa()
{  
   IncrementaX();
   IncrementaY();
}
int zXY::XActual()
{
   return intXActual;
}
int zXY::YActual()
{
  return intYActual;

}
void zXY::Modulo(const char *pchrPtrModulo)
{
  strcpy(chrArrModulo,pchrPtrModulo);
}

bool zXY::operator==(const char *pchrPtrModulo)
{
      return !strcmp(chrArrModulo,pchrPtrModulo);
}

void zXY::IncrementoX(int pintIncrementoX)
{
   intIncrementoX=pintIncrementoX;
}

void  zXY::IncrementoY(int pintIncrementoY)
{
    intIncrementoY=pintIncrementoY;
}
int zXY::X()
{
  return intX;
}

int zXY::Y()
{
   return intY;
}
int zXY::IncrementoX()
{
   return intIncrementoX;
}
int zXY::IncrementoY()
{
    return intIncrementoY;
}
zXYArreglo::zXYArreglo():intContador(0)
{
  zXYDatos=new zXY[10];
}

const zXYArreglo &zXYArreglo::operator<<(zXY &pXYDato)
{
      *(zXYDatos+intContador)=pXYDato;   
      intContador++;
return *this;
}

zXY *zXYArreglo::Modulo(const char *pchrPtrModulo)
{
int lintContador;
   for(lintContador=0;lintContador<intContador;lintContador++)
   if(*(zXYDatos+lintContador)==pchrPtrModulo)
   return zXYDatos+lintContador;


 return 0;
}

void zXYArreglo::Inicia()
{
int lintContador;
   for(lintContador=0;lintContador<intContador;lintContador++)
           (zXYDatos+lintContador)->Inicia();
}


void zXYArreglo::X(const char *pchrPtrModulo,int pintX)
{
zXY *lzXY=Modulo(pchrPtrModulo);
 lzXY->X(pintX);
}
