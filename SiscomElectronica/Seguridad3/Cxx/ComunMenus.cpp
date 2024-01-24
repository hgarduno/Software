#include <ComunMenus.h>
#include <SiscomDesarrollo3Qt++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ComunMenus.h>

#include <zOperacionQAction.h> 
#include <zQAction.h> 
void DatosMenu(SiscomClaseIni *pSisClasIni,
                char *pchrPtrNmbMenu,
                char *pchrPtrTexto)
{
char lchrArrClase[256];
char lchrArrPrincipal[256];
pSisClasIni->Clase(lchrArrClase);
 SiscomDesarrollo3Qt::CadenasPorSeparador(lchrArrClase,
                                                 '.',
                                                 lchrArrPrincipal,
                                                 pchrPtrNmbMenu);
  pSisClasIni->Propiedad("Texto")->Valor(pchrPtrTexto);

}
zQAction *CreaQAction(const char *pchrPtrNmbAction)
{
   return new zQAction(pchrPtrNmbAction,"false","false");
}
void CreaOpcion(zMenu *pzMenu,
		SiscomClaseIni *pSisClasIni)
{   
char lchrArrNmbPopupMenu[256];
char lchrArrNmbAction[256];
char lchrArrNmbClase[256];
char lchrArrTexto[256];
SiscomVariableIni *lSisVarIni;
pSisClasIni->Clase(lchrArrNmbClase);
SiscomDesarrollo3Qt::CadenasPorSeparador(lchrArrNmbClase,
                                         '.',
                                         lchrArrNmbPopupMenu,
                                         lchrArrNmbAction);
pzMenu->AgregaQAction(CreaQAction(lchrArrNmbAction));
printf("\t%s\n",lchrArrNmbAction);
}
void ValorPropiedad(SiscomClaseIni *pSisClasIni,
                    const char *pchrPtrPropiedad,
                    char *pchrPtrValor)
{
SiscomVariableIni *lSisVarIni;

if((lSisVarIni=pSisClasIni->Propiedad(pchrPtrPropiedad)))
  lSisVarIni->Valor(pchrPtrValor);
else
{
 SiscomEscribeLog3Qt("No se encontrol la propiedad:%s",pchrPtrPropiedad);
}




}

void CreaMenu(zMenu *pzMenu,
	      SiscomClasesIni *pSisClasIni,
	      const char *pchrPtrNmbMenu,
	      const char *pchrPtrTexto)
{
char lchrArrNombrePrincipal[256];              
SiscomClasesIni lSisClassIniMenu;
SiscomClaseIni *lSisClasIni;
    pSisClasIni->ClasesPorNombre(pchrPtrNmbMenu,0,lSisClassIniMenu);
for(lSisClasIni=lSisClassIniMenu.first();
    lSisClasIni;
    lSisClasIni=lSisClassIniMenu.next())
{
  CreaOpcion(pzMenu,lSisClasIni);

}
}
int ArchivoMenus(zSiscomLineaComandos &pzSisLineaComandos)
{
int lintArchivo;
if((lintArchivo=open(pzSisLineaComandos["Salida"],
		    O_WRONLY|O_CREAT,
                     S_IRUSR | S_IWUSR)))
{
    return lintArchivo;
}
else
exit(0);
 

}
void CreaArchivoMenus(zSiscomConexion *pzSisConexion,zMenu *pzMenu)
{
zOperacionQAction lzQAction(pzSisConexion,pzMenu);
 SiscomRegistroLog2(pzMenu);
 SiscomRegistrosLog(pzMenu->QActions());
 lzQAction.Enviando();
}
