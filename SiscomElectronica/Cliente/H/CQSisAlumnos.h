#ifndef __CQSISALUMNOS_H__
#define __CQSISALUMNOS_H__
#include <SiscomRegistros4.h>
#include <SiscomOperaciones3.h>
class CQSisAlumno:public SiscomRegistro4 
{
public:
	CQSisAlumno(SiscomRegistro3 *pSisReg3Expendio,
		    SiscomRegistro3 *pSisReg3GensAlumno);
	CQSisAlumno();
	void Expendio(SiscomRegistro3 *pSisReg3Expendio);
	void Generales(SiscomRegistro3 *pSisReg3Generales);
	void Telefonos(SiscomRegistro3Lst *pSisReg3LstTelefonos);

	void Nombre(const char *);
	void APaterno(const char *);
	void AMaterno(const char *);
	void Boleta(const char *);
	void CorreoElectronico(const char *);
	void Celular(const char *);
	void TelefonoCasa(const char *);
	void Escuela(const char *);
	void Grupo(const char *);

	void Grupo(SiscomRegistro3Lst *);
	void CorreoElectronico(SiscomRegistro3Lst *);

	const char *Boleta();
	const char *CorreoElectronico();
	const char *Celular();
	const char *TelefonoCasa();
	const char *Escuela();
	const char *Grupo();
};


class CQSisOpAlumno:public SiscomOperaciones3
{
public:
	CQSisOpAlumno(SiscomDatCom *pSisDatCom);
	void Alumno(CQSisAlumno *);
	void Actualiza(CQSisAlumno *);
};

#endif
