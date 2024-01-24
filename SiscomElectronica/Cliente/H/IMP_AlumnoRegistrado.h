
#ifndef __IMP_ALUMNOREGISTRADO_H__
#define __IMP_ALUMNOREGISTRADO_H__
#include <UIC_H_AlumnoRegistrado.h>
class SiscomDatCom;
class SiscomRegistro3Lst;
class SiscomRegistro3;
class QAlumnoRegistrado:public AlumnoRegistrado
{
 Q_OBJECT
public:
	QAlumnoRegistrado(SiscomRegistro3Lst *pSisReg3LstDat=0,
			SiscomDatCom *pSisDatCom=0,
	    char **pchrPtrArgumentos=0,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QAlumnoRegistrado();
	SiscomRegistro3 *IdCliente();
	SiscomRegistro3 *Cliente();
	int InscribirCliente();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst *SisReg3LstARegistrado;
	SiscomRegistro3 *SisReg3Cliente;
	int intInscribirCliente;
private:
	void ConectaSlots();
	void IniciaVariables();
	void CopiaDatosAlumnoRegistrado();
	void closeEvent(QCloseEvent *);
	SiscomRegistro3 *FormaRegistroAlumno(SiscomRegistro3 *pSisReg3Alumno);
private slots:
	void SlotInscribirCliente();
	void SlotCancelar();
};
#endif
