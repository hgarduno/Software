#ifndef __ZLINEACOMANDOSEJECUTAMODULOSE_H__
#define __ZLINEACOMANDOSEJECUTAMODULOSE_H__
#include <zSiscomLineaComandos.h>
class QFont;
class zLineaComandosEjecutaModuloSe:public zSiscomLineaComandos
{
public:
	zLineaComandosEjecutaModuloSe(int pintArgc,char **pchrPtrArgv);
	int SeCargaModulo();
	const char *Biblioteca();
	const char *Modulo();
	int TipoLetra();
	const char *Letra();
	int TamanoLetra();
	int SePuedeCambiarLetra();

};

#endif
