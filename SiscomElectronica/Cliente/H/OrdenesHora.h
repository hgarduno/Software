#ifndef __ORDENESHORA_H__
#define __ORDENESHORA_H__
#include <SISCOMComunicaciones++.h>
#include <CSisDatosSemana.h>

class OrdenHora:public SiscomInformacion
{
public:
	OrdenHora(const char *,
		  const char *,
		  const char *,
		  const char *);
};

class OrdenesHora:public QPtrList<OrdenHora>
{
public:
	OrdenesHora();
	OrdenesHora &operator<<(OrdenHora *);

};

class OpOrdenesHora:public SiscomOperaciones
{
public:
	OpOrdenesHora(SiscomDatCom *,OrdenesHora *);
	void SiscomGeneraRegistros(const SiscomComunicaSrv *,
				   QPtrList<SiscomInformacion> *);
	void ObtenDatosSemanas(CSisDatosSemanas &);
private:
	void ObtenJornadaTrabajo(SiscomRegistrosPro2 &);
private:
	CSisDatosSemanas CSDtsSemanas;
	int intHoraInicio;
	int intHoraFin;
};




#endif
