
#ifndef __IMP_DISPONIBILIDADCURSOS_H__
#define __IMP_DISPONIBILIDADCURSOS_H__
#include <UIC_H_DisponibilidadCursos.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro3;
class QDisponibilidadCursos:public DisponibilidadCursos
{
 Q_OBJECT
public:
	QDisponibilidadCursos(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QDisponibilidadCursos();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Fecha;
	SiscomRegistro3Lst SisReg3LstCursos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoCursos();
	void ConsultaCursos();
	void MuestraCursos();
private slots:
	void SlotFechaCurso(SiscomRegistro3 *);
};
#endif
