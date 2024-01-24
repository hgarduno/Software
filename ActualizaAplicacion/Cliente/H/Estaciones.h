#ifndef __ESTACIONES_H__
#define __ESTACIONES_H__
#include <SISCOMComunicaciones++.h>
#include <qptrlist.h>
class Estacion
{
public:
	Estacion(const char *,
		 const char *,
		 const char *,
		 const char *,
		 const char *,
		 const char *);

	const char *ObtenDirIp();
	const char *ObtenPtoCom();
	const char *ObtenDirTrabajo();
	const char *ObtenHome();
	const char *ObtenParametro();
	const char *ObtenEdoRegistro();
private:
	const char *chrPtrDirIp;
	const char *chrPtrPtoCom;
	const char *chrPtrDirTrabajo;
	const char *chrPtrHome;
	const char *chrPtrParametro;
	const char *chrPtrEdoRegistro;

};
class ListaEstaciones:public QPtrList<Estacion>
{
public:
	ListaEstaciones();
	void CreaListaEstacionesServidor(SiscomComunicaSrv *);
	

};
class Estaciones
{
public:
	Estaciones(SiscomDatCom *,
		   const char *,
		   const char *);
	Estaciones(SiscomDatCom *,
		   const char *,
		   ListaEstaciones *);
	const ListaEstaciones &ObtenEstacionesTrabajo();
private:
        SiscomComunicaSrv *SComunicaSrv;
        SiscomDatCom *SDatCom;
        SiscomRegistroPro2 SRegistroPro2;
	const char *chrPtrHome;
	const char *chrPtrDirTrabajo;
	const char *chrPtrOperacion;
	ListaEstaciones LstEstaciones;

	ListaEstaciones *LstEstaciones2;
private:
	void CreaRegistroComunicaciones();
	void IniciaRegistroComunicacion();
	void EnviaInformacionServidor();
	void ObtenEstaciones();
};
#endif
