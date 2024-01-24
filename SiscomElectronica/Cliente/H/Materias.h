#ifndef __MATERIAS_H__
#define __MATERIAS_H__
#include <SISCOMComunicaciones++.h>
#include <qptrlist.h>

class Materia:public SiscomInformacion
{
public:
	Materia(const char *,
		const char *,
		const char *,
		const char *pchrPtrEdoRegistro="Insertado");

};

class Materias:public QPtrList<Materia>
{
public:
	Materias();
	Materias &operator<<(Materia *);

};

class ConsultaMaterias
{
public:
	ConsultaMaterias(SiscomDatCom *,
			 const char *,
			 Materias &);
	void RegistraMaterias();
private:
	void GeneraMaterias(const SiscomComunicaSrv *,Materias &);
private:
	SiscomDatCom *SisDatCom;
	Materias MMaterias;
	const char *chrPtrIdEscuela;
};
#endif
