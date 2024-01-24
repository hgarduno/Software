#ifndef __PERSONAS_H__
#define __PERSONAS_H__
#include <SISCOMComunicaciones++.h>
#include <MediosComunicacion.h>
#include <Direcciones.h>
#include <qptrlist.h>

/*! \file Personas.cpp
 *
 * Archivo que contiene la informacion de los datos
 * que se utilizaran, para el manejo de la informacion
 * general de las personas.
 *
 * Autor: Heli Garduno Esquivel
 * Fecha: ?????
 *
 */


#include <SISCOMComunicaciones++.h>

/*! \class Persona
 *  \brief Objeto que contiene la informacion de un producto
 *  	   para el manejo, en el control de inventarios
 *  \author Heli Garduno Esquivel
 *  \version 1.0
 *  \date 2007-05-30
 */
class Persona:public SiscomInformacion
{

	public:
	/*! Constructor General del objeto */

		Persona();
	/*! Sobre carga del constructor de la clase.
	 *  Al cual se le pasa cada uno de los datos 
	 *  generales de la persona.
	 *  En el caso del registro los campos se llaman de la siguiente forma:
	 *  	Nombre
	 *  	APaterno
	 *  	AMaterno
	 *  	RFC
	 *  	IdPersona
	 *  	TipoPersona
	 *  	Firma
	 *  	Password
	 *  	Departamento
	 *  	DscTipoPersona
	 *  	IdAplicacion
	 *  	EdoFirma
	 *  \param pchrPtrNombre Nombre de la persona
	 *  \param pchrPtrAPaterno Apellido paterno
	 *  \param pchrPtrAMaterno Apellido materno
	 *  \param pchrPtrRFC RFC
	 *  \param pchrPtrIdPersona Identificador unico
	 *                          que se asigna a la persona
	 *  \param pchrPtrTipoPersona Identificador unico que 
	 *  			      se le asigna al rol que la
	 *  			      persona desempena en el contexto
	 *  			      del sistema
	 *  \param pchrPtrFirma Si la persona es un empleado, a este 
	 *                      se le asigna una firma
	 *  \param pchrPtrPassword Password de la firma
	 *  \param pchrPtrDepartamento Si la persona es un empleado
	 *  			       contendra un departamento operativo
	 *  \param pchrPtrDscTipoPersona Descripcion del roll de la persona
	 *   				 en el sistema
	 *  \param pchrPtrIdAplicacion Para el manejo del sistema de Seguridad
	 *  			      SISCOM3, se requiere poder identificar 
	 *  			      la aplicacion que se registro en la 
	 *  			      base de datos, esta informacion se pasa
	 *  			      en este parametro.
	 *  \param pchrPtrEdoFirma Para saber que usuarios estan firmados en 
	 *  			   la aplicacion
	 */
		Persona(const char *pchrPtrNombre,
			const char *pchrPtrAPaterno,
			const char *pchrPtrAMaterno,
			const char *pchrPtrRFC,
			const char *pchrPtrIdPersona,
			const char *pchrPtrTipoPersona,
			const char *pchrPtrFirma="",
			const char *pchrPtrPassword="",
			const char *pchrPtrDepartamento="",
			const char *pchrPtrDscTipoPersona="",
			const char *pchrPtrIdAplicacion="",
			const char *pchrPtrEdoFirma="");
		Persona &operator<<(MedioComunicacion *);
		Persona &operator<<(Direccion *);
		Persona &operator>>(MediosComunicacion &);
		Persona &operator>>(Direcciones &);

		void AnexarMedioComunicacion(MedioComunicacion *);
		void AnexarMediosComunicacion(MediosComunicacion );
		void AnexarDireccion(Direccion *);
	private:
		MediosComunicacion MComunicacion;
		Direcciones DDirecciones;
};


class Personas:public QPtrList<Persona>
{
public:
	Personas();
	Personas &operator <<(Persona *);
	void GeneraRegistros(const SiscomComunicaSrv *);

};
class RegistroEnvioPersona:public SiscomInformacion
{
public:
	RegistroEnvioPersona(Persona *);
private:
Persona *PPersona;
private:
	void FormaRegistroEnvio();
	void AnexaGenerales();
	void AnexaDirecciones();
	void AnexaMediosComunicacion();
};
class RegistrosEnvioPersona:public QPtrList<RegistroEnvioPersona>
{
public:
	RegistrosEnvioPersona();
	RegistrosEnvioPersona &operator<<(RegistroEnvioPersona *);


};
class ConsultaPersonas
{
public:
	ConsultaPersonas(SiscomDatCom *,
			 const char *,
			 const char *,
			 const char *,
			 const char *,
			 const char *,
			 const char *,
			 const char *,
			 Personas &);
	ConsultaPersonas();
	void ConsultaUsuariosSeguridad3(SiscomDatCom *,Personas &);
	Persona *ObtenDatosFirma(SiscomDatCom *,const char *);
	void EmpleadosExpendio(SiscomDatCom *,const char *,Personas &);
	Persona *ValidaFirmaEmpleado(SiscomDatCom *,const char *,const char *,Persona *);
/*
	void RegistraEmpleado(Persona *);
*/

	

private:
	
	void GeneraPersonas(const SiscomComunicaSrv *,Personas &);

};

class OpPersonas
{
public:
	OpPersonas(SiscomDatCom *);
	void RegistrarPersona(Persona *);
	void CambiaEstatusFirma(const char *,const char *,const char *);
private:
SiscomDatCom *SisDatCom;
};
Persona *ConsultaPersonaRFC(SiscomDatCom *,const char *);
void AsignaEmpleadoExpendio(SiscomDatCom *,const char *,const char *);

#endif
