#ifndef __SQLALUMNOS_H__
#define __SQLALUMNOS_H__
#include <SiscomDesarrollo2.h>

void SQLIniciaComprasCliente(SArgsSiscom *pSAgsSiscom);
void SQLRegistraAlumnoExpendio(SArgsSiscom *);
void SQLActualizaParaClienteElectronica(SArgsSiscom *);
void SQLRegistraAlumnoEscuela(SArgsSiscom *);
void SQLRegistraGrupoAlumno(SArgsSiscom *);
void SQLRegistraAlumno(SArgsSiscom *);


void SQLRegistraCelularAlumno(SArgsSiscom *);
void SQLRegistraTelefonoAlumno(SArgsSiscom *);
void SQLRegistraCorreoAlumno(SArgsSiscom *);

void SqlRegistraCredencialAlumno(SArgsSiscom *);
void SQLGeneraIniciaComprasCliente(LCamposSiscomPro2 *,
				      LCamposSiscomPro2 **,
				      LCamposSiscomPro2 **,
				      int *);
void SQLGeneraRegistroAlumnoExpendio(LCamposSiscomPro2 *,
				      LCamposSiscomPro2 **,
				      LCamposSiscomPro2 **,
				      int *);
void SQLParaClienteElectronica(LCamposSiscomPro2 *,
					   LCamposSiscomPro2 **,
					   LCamposSiscomPro2 **,
					   int *);

void SQLAlumnoEscuela(LCamposSiscomPro2 *,
					   LCamposSiscomPro2 **,
					   LCamposSiscomPro2 **,
					   int *);
void SQLGrupoAlumno(LCamposSiscomPro2 *,
		    LCamposSiscomPro2 **,
		    LCamposSiscomPro2 **,
		    int *);

void SQLCorreoAlumno(LCamposSiscomPro2 *,
		    LCamposSiscomPro2 **,
		    LCamposSiscomPro2 **,
		    int *);
void SQLCelularAlumno(LCamposSiscomPro2 *,
		    LCamposSiscomPro2 **,
		    LCamposSiscomPro2 **,
		    int *);
void SQLTelefonoAlumno(LCamposSiscomPro2 *,
		    LCamposSiscomPro2 **,
		    LCamposSiscomPro2 **,
		    int *);
void SQLAlumno(LCamposSiscomPro2 *,
		LCamposSiscomPro2 **,
		LCamposSiscomPro2 **,
		int *);

void SqlInsertIntoCredencialAlumno(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);

void SqlAlumnosExpendio(SArgsSiscom *pSAgsSiscom);
void SqlDatosAlumno(SArgsSiscom *pSAgsSiscom);
void SqlTelefonosAlumno(SArgsSiscom *pSAgsSiscom);
void SqlCorreosAlumno(SArgsSiscom *pSAgsSiscom);
void SqlGrupoAlumno(SArgsSiscom *pSAgsSiscom);
#endif
