#ifndef __PRACTICAS_H__
#define __PRACTICAS_H__
#include <SISCOMComunicaciones++.h>
#include <ProductosE.h>
#include <qptrlist.h>

class Practica:public SiscomInformacion
{
public:
	Practica(const char *,
		const char *,
		const char *,
		const char *pchrPtrEdoRegistro="Insertado");

};

class Practicas:public QPtrList<Practica>
{
public:
	Practicas();
	Practicas &operator<<(Practica *);

};

class ConsultaPracticas
{
public:
	ConsultaPracticas();
	ConsultaPracticas(SiscomDatCom *,
			  const char *,
			  const char *,
			  const char *,
			  ProductosE &);

	ConsultaPracticas(SiscomDatCom *,
			 const char *,
			 Practicas &);
	void RegistraPracticas(SiscomDatCom *,Practicas &);
	void RegistraDetallePractica(SiscomDatCom *,ProductosE &);
private:
	void GeneraPracticas(const SiscomComunicaSrv *,Practicas &);
	void GeneraPracticas(const SiscomComunicaSrv *,ProductosE &);
private:
};
#endif
