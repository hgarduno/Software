/*! \file ControladorOrdenes.h
 * Archivo que contiene la funcionalidad para el control
 * de las ordenes realizadas en el proceso de venta, cotizacion
 *
 * Autor: Heli Garduno Esquivel
 * Fecha: 2007-06-06
 *
 */

#ifndef __CONTROLADORORDENES_H__
#define __CONTROLADORORDENES_H__
#include <ProductosE.h>
#include <Personas.h>
#include <SISCOMComunicaciones++.h>

class IdentificadorOrden:public SiscomInformacion
{
public:
	IdentificadorOrden(const char *,
			   const char *);

};

class IdentificadorOrdenes:public QPtrList<IdentificadorOrden>
{
public:
	IdentificadorOrdenes();
	IdentificadorOrdenes &operator<<(IdentificadorOrden *);
};

class OpIdentificadorOrdenes:public SiscomOperaciones
{
public:
	OpIdentificadorOrdenes(SiscomDatCom *,IdentificadorOrdenes *);
	void SiscomGeneraRegistros(const SiscomComunicaSrv *,
	                                   QPtrList<SiscomInformacion> *);

};


class GeneralOrden:public SiscomInformacion
{
public:
	GeneralOrden(const char *,
		     const char *,
		     const char *,
		     const char *,
		     Persona *);
	Persona *ObtenCliente();
private:
	Persona *PCliente;
};

class GeneralesOrden:public QPtrList<GeneralOrden>
{
public:
	GeneralesOrden();
	GeneralesOrden &operator<<(GeneralOrden *);
};

class OpGeneralesOrden:public SiscomOperaciones
{
public:
	OpGeneralesOrden(SiscomDatCom *,
			 SiscomParametrosConsulta *);
	void SiscomGeneraRegistros(const SiscomComunicaSrv *,
				   QPtrList<SiscomInformacion> *);
		
};
class OpProductosOrdenes:public SiscomOperaciones
{
public:
	OpProductosOrdenes(SiscomDatCom *,IdentificadorOrdenes *);
	OpProductosOrdenes(SiscomDatCom *,SiscomParametrosConsulta *);
	void SiscomGeneraRegistros(const SiscomComunicaSrv *,
	                                   QPtrList<SiscomInformacion> *);
private:
	ProductosE PProductos;
};

#endif
