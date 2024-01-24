#include <SiscomArchivoIni.h>
#include <SiscomDesarrollo3Qt++.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistro.h>


#include <zMenus.h> 
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ComunMenus.h>



SiscomClasesIni SisClassIni;
SiscomClasesIni SisClassIniMenus;
SiscomClasesIni SisClassIniArgs;
SiscomClaseIni *SisClasIniIconoAp;
FILE *gPtrFleArchivoLog3Qt;
FILE *gPtrFleArchivoLog;
zSiscomConexion *gzSiscomConexion;

int main(int pintArgc,
	 char **pchrPtrArgv)
{
zMenu lzMenu;
zSiscomLineaComandos lzSisLineaComandos(pintArgc,pchrPtrArgv);
zSiscomConexion lzSisConexion;
int lintArchivo;
char lchrArrNmbMenu[128],
	lchrArrTexto[128];
gPtrFleArchivoLog=gPtrFleArchivoLog3Qt=stdout;

SiscomVariableIni *lSisVarIni;
SiscomClaseIni *lSisClasIni;
SiscomArchivoIni *SisArchIni=new SiscomArchivoIni(lzSisLineaComandos["Archivo"]);;
SisArchIni->Clases().ClasesPorNombre("MenuPrincipal",SisClassIniMenus);
SisArchIni->Clases().ClasesPorNombre("Argumentos",SisClassIniArgs);
SisClassIni=SisArchIni->Clases();
if((lintArchivo=ArchivoMenus(lzSisLineaComandos)))
lzSisConexion.Socket(lintArchivo);
for(lSisClasIni=SisClassIniMenus.first();
    lSisClasIni;
    lSisClasIni=SisClassIniMenus.next())
{
 printf("%s \n",lchrArrNmbMenu);
 DatosMenu(lSisClasIni,lchrArrNmbMenu,lchrArrTexto);
 CreaMenu(&lzMenu,&SisClassIni,lchrArrNmbMenu,lchrArrTexto);
}

CreaArchivoMenus(&lzSisConexion,&lzMenu);

}
