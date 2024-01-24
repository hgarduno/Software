
#ifndef __IMP_REGISTROCLIENTESISCOM_H__
#define __IMP_REGISTROCLIENTESISCOM_H__
#include <UIC_H_RegistroClienteSiscom.h>
#include <SiscomRegistros.h>
class SiscomDatCom;
class QRegistroClienteSiscom:public RegistroClienteSiscom
{
 Q_OBJECT
public:
	QRegistroClienteSiscom(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroClienteSiscom();

private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Curso;
	SiscomRegistro3 *SisReg3FechaCurso;
	SiscomRegistro3 *SisReg3Escuela;
	SiscomRegistro3 *SisReg3Alumno;
	SiscomRegistro3 *SisReg3CostoCurso;
	SiscomRegistro3 *SisReg3IdCliente;
	SiscomRegistro4 SisReg4FechasCurso;
	SiscomRegistro3Lst SisReg3LstRegAlumno;
private:
	void ConectaSlots();
	void IniciaVariables();
	SiscomRegistro3 *Alumno();
	SiscomRegistro3 *AlumnoParaValidar();
	void Registra();
	int VerificaAlumnoRegistrado();
	int ValidaCamposMinimos();
	int MensajeValidacionCamposMinimos(SiscomRegistro3Lst *);
	int MostrandoMensajeValidacionCamposMinimos(const char *,SiscomRegistro3Lst *);
	void LimpiaCampos();
	void LiberaRegistro();
	void InscribeCliente();
private slots:
/*
	void SlotCurso(SiscomRegistro3 *);
	void SlotSeleccionaHorarioCurso(int,int,int,const QPoint &);
	void SlotSeleccionaCostoCurso(int,int,int,const QPoint &);
*/

	void SlotFocoAAPaterno();
	void SlotFocoAAMaterno();
	void SlotFocoAEscuela();
	
	void SlotFocoAGrupo();
	void SlotFocoABoleta();
	void SlotFocoACorreo();
	void SlotFocoAReCorreo();
	void SlotFocoACelular();
	void SlotFocoATCasa();

	void SlotEscuelas(SiscomRegistro3 *);
	void SlotFocoARegistrar();

	void SlotRegistra();
	
};
extern "C" QRegistroClienteSiscom *InstanciaRegistroClienteSiscom(void *,char **,void *,const char *,int);
#endif
