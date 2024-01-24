
#ifndef __IMP_ALUMNOSINSCRITOSCURSO_H__
#define __IMP_ALUMNOSINSCRITOSCURSO_H__
#include <UIC_H_AlumnosInscritosCurso.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro3;
class QAlumnosInscritosCurso:public AlumnosInscritosCurso
{
 Q_OBJECT
public:
	QAlumnosInscritosCurso(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QAlumnosInscritosCurso();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Curso;
	SiscomRegistro3 *SisReg3Fecha;
	SiscomRegistro3Lst SisReg3LstAInscritosCurso;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ObtenFechasCurso();
	void ConsultandoAlumnosInscritosCurso();
	void ConsultaAlumnosInscritosCurso();
	void MuestraAlumnosInscritosCurso();
private slots:
	void SlotCurso(SiscomRegistro3 *);
	void SlotFecha(SiscomRegistro3 *);
};
extern "C" QAlumnosInscritosCurso *InstanciaAlumnosInscritosCurso(void *,char **,void *,const char *,int);
#endif
