#include <SiscomModulos.h>
#include <SiscomModulo.h>
SiscomModulos::SiscomModulos()
{


}
SiscomModulos &SiscomModulos::operator<<(SiscomModulo *pSisModulo)
{
	append(pSisModulo);
	return *this;
}
int SiscomModulos::operator==(const char *pchrPtrModulo)
{
SiscomModulo *lSisModulo;
char lchrArrModulo[256];
for(lSisModulo=first();
    lSisModulo;
    lSisModulo=next())
{
  lSisModulo->Modulo(lchrArrModulo);
  if(!strcmp(lchrArrModulo,pchrPtrModulo))
   return 1;
}
   
   return 0;
}

SiscomModulo *SiscomModulos::Modulo(const char *pchrPtrModulo)
{
SiscomModulo *lSisModulo;
char lchrArrModulo[256];
for(lSisModulo=first();
    lSisModulo;
    lSisModulo=next())
{
  lSisModulo->Modulo(lchrArrModulo);
  if(!strcmp(lchrArrModulo,pchrPtrModulo))
   return lSisModulo;
}
   
   return 0;
}

