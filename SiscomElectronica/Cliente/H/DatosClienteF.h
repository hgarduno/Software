#ifndef __DATOSCLIENTEF_H__
#define __DATOSCLIENTEF_H__
#include <SISCOMComunicaciones++.h>
#include <qptrlist.h>


class DatoClienteF:public SiscomInformacion
{
public:
	DatoClienteF(const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *);
	DatoClienteF(DatoClienteF *);
};

class DatosClienteFrec:public QPtrList<DatoClienteF>
{
public:
	DatosClienteFrec();
	DatosClienteFrec &operator<<(DatoClienteF *);

};

class OperacionesDatosClienteFrec
{
public:
	OperacionesDatosClienteFrec(SiscomDatCom *,
				 DatosClienteFrec &);
	void RegistraDatos();
	void ConsultaDatos(DatosClienteFrec &);
private:
	SiscomDatCom *SisDatCom;
	DatosClienteFrec DatClienteF;
private:
	void GeneraRegistrosConsultados(const SiscomComunicaSrv *,DatosClienteFrec &);


};
#endif
