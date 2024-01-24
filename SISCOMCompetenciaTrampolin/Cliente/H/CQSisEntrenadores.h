#ifndef __CQSISENTRENADORES_H__
#define __CQSISENTRENADORES_H__
#include <SISCOMComunicaciones++.h>
#include <SisMedioComunicacion.h>
#include <SisPersonas.h>
class CQSisGimnasio;
class CQSisEntrenador:public 
		      //SisPersona
		      //SiscomInformacion2
		      SiscomInformacion
{
public:
	CQSisEntrenador(const char *,
			const char *,
			const char *,
			const char *);
	void PonFechaNac(const char *);
	void PonEdad(const char *);
	void PonGimnasio(CQSisGimnasio *);
	void AnexaCorreoElectronico(const char *);
	void AnexaTelefono(const char *,const char *);
	int operator==(CQSisEntrenador *);
private:
	SisLstMedCom SLstMCom;
};

class CQSisLstEntrenador:public QPtrList<CQSisEntrenador>
{
public:
	CQSisLstEntrenador();
	CQSisLstEntrenador &operator<<(CQSisEntrenador *);
};

class CQSisOpEntrenador:public SiscomOperaciones
{
public:
	CQSisOpEntrenador(SiscomDatCom *);
	/* Se agrega el parametro de CQSisLstGimnasio 
	 * debido a que en esta clase se realiza el manejo de errores
	 * al regreso de la insercion, es muy importante realizar el 
	 * cambio despues a una clase general que contenga los errores
	 * de toda la aplicacion.
	 * 
	 * En particular para el proceso de registro del gimnasio se
	 * ha requerido de regresar los gimnasios que ya estan registrados
	 * o cuando el contacto ya esta registrado, aqui se tendra que
	 * integrar los errores que resulten ahora del registro de los
	 * entrenadores.
	 */
	void InsertaEntrenador(CQSisEntrenador *,SiscomRegistrosPro2 **);
private:
	CQSisLstEntrenador CQSLEntrenador;
};
#endif
