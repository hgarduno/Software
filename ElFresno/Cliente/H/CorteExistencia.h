#ifndef __CORTEEXISTENCIA_H__
#define __CORTEEXISTENCIA_H__
#include <SISCOMComunicaciones++.h>
#include <qptrlist.h>
#include <qwidget.h>
class SiscomDatCom;
class OpCorteExistencia
{
public:
	OpCorteExistencia(SiscomDatCom *);
	void FijaFechaCorte(const char *);

private:
	SiscomDatCom *SisDatCom;	
};

#endif

