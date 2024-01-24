#ifndef __VEHICULOSPROT2_H__
#define __VEHICULOSPROT2_H__
#include <SISCOMComunicaciones++.h>
#include <Vehiculos.h>
class VehiculoProt2:public SiscomInformacion
{

public:
	VehiculoProt2(const char *,
		      const char *,
		      const char *);

};
class Vehiculos2:public QPtrList<Vehiculo>
{
public:
	Vehiculos2();
	void GeneraRegistros(const SiscomComunicaSrv *);
private:
};

#endif
