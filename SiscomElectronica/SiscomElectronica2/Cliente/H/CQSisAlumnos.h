#ifndef __CQSISALUMNOS_H__
#define __CQSISALUMNOS_H__
#include <SISCOMComunicaciones++.h>

class CQSisAlumno:public SiscomInformacion
{
public:
	/*
	 * Este constructor se utiliza para el proceso de
	 * registro del alumno. Por lo que solo se
	 * pasan los Id's, si se requiere contar con 
	 * la informacion por ejemplo de la escuela etc
	 * se requerira sobrecargar el constructor
	 *
	 */
	CQSisAlumno(const char *,
		    const char *,
		    const char *,
		    const char *,
		    const char *,
		    const char *,
		    const char *);


};


class CQSisLstAlumno:public QPtrList<CQSisAlumno>
{
public:
	CQSisLstAlumno();
	CQSisLstAlumno &operator<<(CQSisAlumno *);

};

class CQSisOpAlumnos:public SiscomOperaciones
{
public:
	CQSisOpAlumnos(SiscomDatCom *);
	void RegistraAlumno(CQSisAlumno *,SiscomRegistrosPro2 **);
};
#endif
