
#ifndef __IMP_ACTUALIZADATOSALUMNO_H__
#define __IMP_ACTUALIZADATOSALUMNO_H__
#include <UIC_H_ActualizaDatosAlumno.h>
#include <CQSisAlumnos.h>
class SiscomDatCom;
class SiscomRegistro3;
class QActualizaDatosAlumno:public ActualizaDatosAlumno
{
 Q_OBJECT
public:
	QActualizaDatosAlumno(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QActualizaDatosAlumno();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Alumno;
	CQSisAlumno CQSAlumno;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
	void ConsultaDatosAlumno();
	void ConsultandoDatosAlumno();
	void MuestraDatosAlumno();
	void ActualizaDatos();
	void EnviaActualizacion();
	void Actualizando();
private slots:
	void SlotAlumno(SiscomRegistro3 *);
	void SlotActualiza();
	void SlotCambiaEscuela();
	void SlotSeleccionaAlumno();

	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoBoleta();
	void SlotPasaFocoCorreoE();
	void SlotPasaFocoCelular();
	void SlotPasaFocoTelefonoCasa();
	void SlotPasaFocoActualizar();
	void SlotPreguntaCambiaEscuela();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QActualizaDatosAlumno *InstanciaActualizaDatosAlumno(void *,char **,void *,const char *,int);
#endif
