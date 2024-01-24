
#ifndef __IMP_REGISTROALUMNOSERVICIO_H__
#define __IMP_REGISTROALUMNOSERVICIO_H__
#include <UIC_H_RegistroAlumnoServicio.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;

class SiscomRegistro3;
class QRegistroAlumnoServicio:public RegistroAlumnoServicio
{
 Q_OBJECT
public:
	QRegistroAlumnoServicio(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroAlumnoServicio();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Servicio;
	SiscomRegistro3 *SisReg3Alumno;
	SiscomRegistro3 *SisReg3RegEntrada;
	SiscomRegistro3Lst SisReg3LstAlumnosEnTaller;
	SiscomRegistro3 *SisReg3ServicioSel;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraAlumnosEnTaller();

	void ConsultandoSinRegistroSalida();
	void ConsultaSinRegistroSalida();
	void MuestraSinRegistroSalida();

	void RegistraHoraSalida();

private slots:
	void SlotServicio(SiscomRegistro3 *);
	void SlotAlumno(SiscomRegistro3 *);

	void SlotRegistraHoraEntrada();
	void SlotAsignaSalida(int,int,int,const QPoint &);
	void SlotRegistraHoraSalida();
};
extern "C" QRegistroAlumnoServicio *InstanciaRegistroAlumnoServicio(void *,char **,void *,const char *,int);
#endif
