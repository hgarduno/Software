#ifndef __SEPOMEXESTADOS_H__
#define __SEPOMEXESTADOS_H__
#include<SISCOMComunicaciones++.h>
class SepomexEstado:public SiscomInformacion
{

public:
	SepomexEstado(const char *,
		       const char *);


};
class SepomexEstados:public QPtrList<SepomexEstado>
{
public:
	SepomexEstados();

	SepomexEstados &operator<<(SepomexEstado *);

};
class SepomexOpEstados:public SiscomOperaciones
{

public:
	SepomexOpEstados(SiscomDatCom *,
			 SiscomParametrosConsulta *);


private:
	void SiscomGeneraRegistros(const SiscomComunicaSrv *,
				   QPtrList<SiscomInformacion> *);


};


#endif
