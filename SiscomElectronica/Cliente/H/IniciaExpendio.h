#ifndef __INICIAEXPENDIOS_H__
#define __INICIAEXPENDIOS_H__
#include <SISCOMComunicaciones++.h>



class OpIniciaExpendios
{
public:
	OpIniciaExpendios(SiscomDatCom *);
	void IniciaBaseDatos(const char *);


private:

SiscomDatCom *SisDatCom;
};


#endif
