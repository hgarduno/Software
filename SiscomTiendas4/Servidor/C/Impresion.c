#include <Impresion.h>
#include <ServidorGeneral.h>
#include <dlfcn.h>

void Imprime(SArgsSiscom *pSAgsSiscom)
{
void (*Imprimiendo)(SArgsSiscom *pSAgsSiscom);
void *lvidPtrModulo;
SiscomLog("Imprimiendo ....");
SiscomLog("Se debera Cargar:%s -> %s",
	  gSSiscomConfiguracionSvr.chrPtrModuloImpresion,
	  gSSiscomConfiguracionSvr.chrPtrFuncionImpresion);
if((lvidPtrModulo=CargaImprimiendo((void **)&Imprimiendo)))
{
    Imprimiendo(pSAgsSiscom);
}
}
void *CargaImprimiendo(void **pvidPtrImprimiendo)
{
void *lvidPtrModulo;

if((lvidPtrModulo=dlopen(gSSiscomConfiguracionSvr.chrPtrModuloImpresion,RTLD_LAZY)))
{
  if(!(*pvidPtrImprimiendo=dlsym(lvidPtrModulo,gSSiscomConfiguracionSvr.chrPtrFuncionImpresion)))
  {
	SiscomLog("%s",dlerror());
	return 0;
  }
  else
  return lvidPtrModulo;

}
else
 SiscomLog("%s",dlerror());
return 0;
}
