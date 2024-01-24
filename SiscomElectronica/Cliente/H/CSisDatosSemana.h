#ifndef __CSISDATOSEMANA_H__
#define __CSISDATOSEMANA_H__
#include <SISCOMComunicaciones++.h>
class CSisDatoHora
{
public:
	CSisDatoHora(const char *,const char *,const char *);
	const char *ObtenHora();
	const char *ObtenImporteChar();
	float ObtenImporte();
	

private:
	const char *chrPtrHora;
	const char *chrPtrImporte;
	const char *chrPtrOrdenes;
	float fltImporte;
	float fltOrdenes;
};

class CSisDatoHoras:public QPtrList<CSisDatoHora>
{
public:
	CSisDatoHoras();
	float *ObtenImportes(int *);
	CSisDatoHoras & operator <<(CSisDatoHora *);
};
class CSisDatoDia
{
public:
	CSisDatoDia(const char *,const char *);
	void AnexaDatoDia(CSisDatoHora *);
	void PonImporteDia(const char *);
	const char *ObtenDia();
	float ObtenImporteDia();
	const char *ObtenImporteDiaChar();
	const char *ObtenFecha();
	CSisDatoHoras &ObtenDatosHoras();
private:
	const char *chrPtrDia;
	CSisDatoHoras CSDatHoras;
	float fltImporteDia;
	const char *chrPtrImporteDia;
	const char *chrPtrFecha;
};
class CSisDatosDias:public QPtrList<CSisDatoDia>
{
public:
	CSisDatosDias();
	CSisDatosDias &operator<<(CSisDatoDia *);

};
class CSisDatosSemana
{
public:
	CSisDatosSemana(const char *,
		   const char *,
		   const char *,
		   const char *);
	void AnexaDia(CSisDatoDia *);
	void PonImporteSemana(const char *);
	const char *ObtenInicioSemana();
	const char *ObtenFinSemana();
	const char *ObtenImporteSemana();
	CSisDatosDias &ObtenDias();

private:
	const char *chrPtrFecha;
	const char *chrPtrInicioSemana;
	const char *chrPtrFinSemana;
	const char *chrPtrNoSemana;
	const char *chrPtrImporteSemana;
	CSisDatosDias CSDatosDias;
};

class CSisDatosSemanas:public QPtrList<CSisDatosSemana>
{
public:
	CSisDatosSemanas();
	CSisDatosSemanas &operator <<(CSisDatosSemana *);

};

#endif
