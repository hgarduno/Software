/*! \file InventariosDia.cpp
 *
 * Archivo que contiene la informacion de los datos
 * que se utilizaran, en el control de los inventarios
 * programados
 *
 * Autor: Heli Garduno Esquivel
 * Fecha: 2007-05-30
 *
 */


#include <InventariosDia.h>

InventarioDia::InventarioDia(const char *pchrPtrFecha,
			     Persona *pPEmpleado)
{
	SRegistroPro2 						<<
	"Fecha"							<<
	"IdEmpleado"						<<
	"Nombre"						<<
	"APaterno"						<<
	"AMaterno";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2							     	<<
	SiscomCampoPro2("Fecha",pchrPtrFecha)				     	<<
	SiscomCampoPro2("IdEmpleado",pPEmpleado->SRegistrosPro2["IdPersona"])	<<
	SiscomCampoPro2("Nombre",pPEmpleado->SRegistrosPro2["Nombre"])	     	<<
	SiscomCampoPro2("APaterno",pPEmpleado->SRegistrosPro2["APaterno"])	<<
	SiscomCampoPro2("AMaterno",pPEmpleado->SRegistrosPro2["AMaterno"]);
	SRegistrosPro2.SiscomAnexaRegistro();
}

InventariosDia::InventariosDia()
{

}
InventariosDia &InventariosDia::operator<<(InventarioDia *pInventarioDia)
{
	append(pInventarioDia);
	return *this;
}

