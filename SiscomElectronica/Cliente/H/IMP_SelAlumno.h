
#ifndef __IMP_SELALUMNO_H__
#define __IMP_SELALUMNO_H__
#include <UIC_H_SelAlumno.h>
#include <SiscomRegistros3.h>

class Persona;
class SiscomDatCom;
class QLineEdit;
class QRegistroRapidoAlumno;
class QSelAlumno:public SelAlumno
{
 Q_OBJECT
public:
	QSelAlumno(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QSelAlumno();
	int Selecciono();
	SiscomRegistro3 *Escuela();
 	Persona *Alumno();	
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	QLineEdit *QLEAlumno;
	SiscomRegistro3Lst SisReg3LstAlumnos;
	SiscomRegistro3 *SisReg3Alumno;
	SiscomRegistro3 *SisReg3Escuela;
	int intSeleccion;

	QRegistroRapidoAlumno *QRegRapAlumno;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
	void ConsultaAlumnos();
	void MuestraAlumnos();
	void ConsultandoAlumnos();
	void MuestraAlumno();
	int EsAlumnoRegistrado();
	void HabilitaDesHabilitaControles(bool pbEstado);
	void AsignaEscuelaAlumnoSeleccionado();
private slots:
	void SlotSeleccionando(int);
	void SlotSelecciono(int);
	void SlotEscuela(SiscomRegistro3 *);
	void SlotAceptar();
	void SlotCancelar();
	void SlotRegistrarAlumno();
	void SlotCancelarRegRapido();
	void SlotRegistroAlumno(const QString &);
};
#endif
