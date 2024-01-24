#ifndef __CQSISEMPRESAS_H__
#define __CQSISEMPRESAS_H__
#include <SISCOMComunicaciones++.h>
#include <SisMedioComunicacion.h>
#include <SisPersonas.h>
#include <SisDirecciones.h>

#include <SiscomRegistros3.h>
class CQSisEmpresa:public SiscomInformacion
{
public:
	CQSisEmpresa();
	CQSisEmpresa(const char *,
		     const char *);
	CQSisEmpresa(const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *);
	void AnexaDireccion(SisDireccion *);
	void AnexaContacto(SisPersona *);
	void AnexaMedioComunicacion(SisMedCom *);
	const SisLstDireccion &Direcciones();
	const SisLstPersona &Contactos();
	const SisLstMedCom &Comunicacion();
private:
	SisLstDireccion SLDireccion;
	SisLstPersona SLContactos;
	SisLstMedCom SLMCComunicacion;
};

class CQSisLstEmpresa:public QPtrList<CQSisEmpresa>
{
public:
	CQSisLstEmpresa();
	~CQSisLstEmpresa();
	CQSisLstEmpresa &operator<<(CQSisEmpresa *);
};



/*
 *
 * Para no crear mas archivos, se procedio a poner aqui la clase para 
 * la version 3Qt++
 *
 */

class CQSisEmpresa3Qt:public SiscomRegistro3
{
public:
	CQSisEmpresa3Qt(const char *pchrPtrIdEmpresa,
			const char *pchrPtrRazonSocial);

};
#endif
