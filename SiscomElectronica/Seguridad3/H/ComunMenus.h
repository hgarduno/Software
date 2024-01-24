#ifndef __COMUNMENUS_H__
#define __COMUNMENUS_H__
#include <zSiscomLineaComandos.h>
#include <SiscomArchivoIni.h>
#include <zMenus.h>
#include <zSiscomConexion.h>
int ArchivoMenus(zSiscomLineaComandos &pzSisLineaComandos);
void CreaMenu(zMenu *,SiscomClasesIni *,const char *pchrPtrNmbMenu,const char *pchrPtrTexto);
void ValorPropiedad(SiscomClaseIni *pSisClasIni,const char *pchrPtrPropiedad,char *pchrPtrValor);
void CreaOpcion(zMenu *pzMenu,SiscomClaseIni *pSisClasIni);
void DatosMenu(SiscomClaseIni *pSisClasIni,char *pchrPtrNmbMenu,char *pchrPtrTexto);
void CreaArchivoMenus(zSiscomConexion *,zMenu *pzMenu);


#endif
