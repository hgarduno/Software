#include <SiscomModulo.h>
#include <SiscomDesarrollo3Qt++.h>
#include <string.h>
#include <dlfcn.h>
SiscomModulo::SiscomModulo(const char *pchrPtrModulo)
{
   strcpy(chrArrModulo,pchrPtrModulo);
   CargaModulo();
}
void SiscomModulo::Modulo(void **pvidPtrAncla)
{
	*pvidPtrAncla=vidPtrAncla;
}

void SiscomModulo::Funcion(const char *pchrPtrFuncion,
			    void **pvidPtrFuncion)
{
   if(vidPtrAncla &&
      (*pvidPtrFuncion=dlsym(vidPtrAncla,pchrPtrFuncion)))
   {

   }
   else
   SiscomEscribeLog3Qt("%s",dlerror());
}

void SiscomModulo::Modulo(char *pchrPtrModulo)
{
	strcpy(pchrPtrModulo,chrArrModulo);
}
void SiscomModulo::CargaModulo()
{
   if((vidPtrAncla=dlopen(chrArrModulo,RTLD_LAZY)))
   {

   }
   else
   {
      SiscomEscribeLog3Qt("NO se pudo cargar el modulo:%s Error:%s",
      			  chrArrModulo,
			  dlerror());
   }
}
int SiscomModulo::EstadoCarga()
{
   return vidPtrAncla ? 1 :0 ;
}
