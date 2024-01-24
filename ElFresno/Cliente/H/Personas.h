#ifndef __PERSONAS_H__
#define __PERSONAS_H__
#include <qptrlist.h>
#include <Direcciones.h>
#include <Correos.h>
#include <Telefonos.h>
#include <Apodos.h>
#include <Firmas.h>
#include <CQSiscomCom.h>
#include <qstringlist.h>

class QSiscomPerfilBD;
class CQTipoPersona;

class CQ_Persona
{
	public:
		CQ_Persona(const char *,
			   const char *,
			   const char *,
			   const char *,
			   const char *,
			   const char *);
		const char *ObtenNombre();
		const char *ObtenAPaterno();
		const char *ObtenAMaterno();
		const char *ObtenIdPersona();
		const char *ObtenEdoRegistro();
		const char *ObtenRFC();
		const char *ObtenIdUsuarioBDSeguridad3();
		CQ_Firma *ObtenFirma();
		QSiscomPerfilBD *ObtenPerfil();
		const CQ_Direcciones &ObtenDirecciones();
		const CQ_Telefonos &ObtenTelefonos();
		const CQ_Apodos &ObtenApodos();
		const CQ_Correos &ObtenCorreos();
		void PonNombre(const char *);
		void PonAPaterno(const char *);
		void PonAMaterno(const char *);
		void PonRFC(const char *);
		void PonIdPersona(const char *);
		void PonTipoPersona(const char *);
		void PonEdoRegistro(const char *);
		void PonPerfil(QSiscomPerfilBD *);
		void PonFirma(CQ_Firma *);
		void PonTipoPersona(CQTipoPersona *);
		void PonIdUsuarioBDSeguridad3(const char *);

		void AnexaDireccion(CQ_Direccion *);
		void AnexaTelefono(CQ_Telefono *);
		void AnexaCorreo(CQ_Correo *);
		void AnexaApodo(CQ_Apodo *);


private:

	const char *chrPtrNombre;
	const char *chrPtrAPaterno;
	const char *chrPtrAMaterno;
	const char *chrPtrTipoPersona;
	const char *chrPtrIdPersona;
	const char *chrPtrEdoRegistro;
	const char *chrPtrRFC;
	const char *chrPtrIdUsuarioBDSeg3;
	CQ_Direcciones CQDirDatos;
	CQ_Telefonos CQTelTelefonos;
	CQ_Apodos CQApodos;
	CQ_Correos CQCoDatos;
	CQ_Firma *CQFirma;
	QSiscomPerfilBD *QSPerfilBD;


};
class CQ_Personas:public QPtrList<CQ_Persona>
{
	public:
		CQ_Personas();
		const CQ_Personas &operator<<(CQ_Persona *);

};
/*
void CQCtrPersonas::FormaEnvioPersonas(CQ_Personas *);

			Esta funcion se encarga de enviar 
			toda la informacion de la lista de
			personas, con el concepto de estado
			de registro se podra, proceder con
			la misma infraestructura, a insertar
			actualizar, eliminar cualquier parte
			de la clase, en la base de datos.
			
			Por Ejemplo en el caso de la inser-
			cion se se envia vacio el tipo de
			persona y el estdo del registro con
			lo que el servidor realizara la 
			insercion en la base de datos, 
			asignando un idPersona para cada
			registro, el servidor respondera al
			cliente con la misma informacion
			con lo que esta funcion llenara
			los campos de la clase que falten
		 */





class CQCtrPersonas
{
	public:
		enum CtrPersonas
		{
			Registrar,
			Consultar
		};
		CQCtrPersonas(CSISCOMDatComunicaciones *,
			      CtrPersonas,
			      CQ_Personas *);
		CQCtrPersonas(CSISCOMDatComunicaciones *,
			      QStringList ,
			      CQ_Personas *);
		
	const char *ObtenIdPersona();
	private:
		 CQOGenericaServidorSiscom *CQOGSvrSiscom;
		 CSISCOMDatComunicaciones *CSisDatCom;
		 QStringList QSLRegistro;
		 CQ_Persona *CQPersona;
		 
		 const char *chrPtrIdPersona;
		 
	private:
		 void RegistraPersonas(CQ_Personas *);
		 void FormaEnvioPersonas(CQ_Personas *);
		 void AnexaRegistroVacio();
		 void AnalizaRespuesta(CQ_Personas *);
		 void ConsultaLasPersonas(QStringList ,CQ_Personas *);
		 void AsignaRespuestaConsulta(CQ_Personas *);
		 void AsignaGenerales();
		 void AsignaDirecciones();
		 void AsignaTelefonos();
		 void AsignaCorreos();
		  
		 

};
#define __NumParametrosRegistraPersona__ 29
#define __ParametrosRegistraPersona__ "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s"

CQ_Persona *ObtenDatosUsuarioFirmado(CSISCOMDatComunicaciones *);

#endif
