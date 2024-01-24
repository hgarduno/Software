#ifndef __ESCUELAS_H__
#define __ESCUELAS_H__
#include <SISCOMComunicaciones++.h>
#include <qptrlist.h>

class Escuela:public SiscomInformacion
{
public:
	Escuela(const char *,
		const char *,
		const char *pchrPtrEdoRegistro="Insertado");

};

class Escuelas:public QPtrList<Escuela>
{
public:
	Escuelas();
	Escuelas &operator<<(Escuela *);

};

class ConsultaEscuelas
{
public:
	ConsultaEscuelas(SiscomDatCom *,	
			 Escuelas &);
	void RegistraEscuelas();
private:
	void GeneraEscuelas(const SiscomComunicaSrv *,Escuelas &);
private:
	SiscomDatCom *SisDatCom;
	Escuelas EEscuelas;
			  
};
#endif
