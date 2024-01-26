#ifndef __QTPRINCIPALSERVISNTE_H__
#define __QTPRINCIPALSERVISNTE_H__
#include <stdio.h>
class QtSiscomServiSNTE;
class zSiscomMenus;
class zSiscomMenusVentana;
class zSiscomLineaComandos;
class QApplication;
class QFont;

zSiscomMenus *Administracion();
void CreaMenusVentana(zSiscomMenusVentana *pzSisMenusVentana);
void FirmandoteAlSistema(zSiscomMenusVentana *pzSisMenusVentana,QFont *);
FILE *AbreArchivoLog();
void ComunicacionPorArgumentos(zSiscomLineaComandos *,
		       	      char *pchrPtrDirIp,
		       	      int *pintPtrPuerto);

void ComunicacionPorVariablesAmbiente(char *pchrPtrDirIp,int *pintPtrPuerto);

void ComunicacionServidor(zSiscomLineaComandos *,char *pchrPtrDirIp, int *pintPtrPuerto);
void MuestraLibraryPaths(QApplication *);
void AsignaLibraryPaths(QApplication *,const char **pchrPtrArgv);
void EliminaLibraryPaths(QApplication *pQAppPrincipal);
void SeReAsignanLibraryPaths(zSiscomLineaComandos *pzSisLineaComandos,
			     QApplication *pQAppPrincipal);

int SeMaximiza(int pintArgc,char **pchrPtrArgv);

void CargaVentana(int pintArgc,
		   char **pchrPtrArgv,
		   QtSiscomServiSNTE *pQt3SiscomServiSNTE);

void VerificandoActualizacionDisponible();
#endif
