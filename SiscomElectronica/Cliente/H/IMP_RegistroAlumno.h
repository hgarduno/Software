
#ifndef __IMP_REGISTROALUMNO_H__
#define __IMP_REGISTROALUMNO_H__
#include <UIC_H_RegistroAlumno.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro3;
class SiscomRegistro3Lst;
class QRegistroAlumno:public RegistroAlumno
{
 Q_OBJECT
public:
	QRegistroAlumno(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroAlumno();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	
	SiscomRegistro3 *SisReg3IdCliente;

	SiscomRegistro3 *SisReg3Escuela;
	SiscomRegistro3 *SisReg3Alumno;

	SiscomRegistro3Lst SisReg3LstRegAlumno;
private:
	void ConectaSlots();
	void IniciaVariables();

	SiscomRegistro3 *Alumno();
	SiscomRegistro3 *AlumnoParaValidar();
	SiscomRegistro3 *Credencial();
	int VerificaAlumnoRegistrado();

	void LiberaRegistro();
	void LimpiaCampos();
	void Registra();
	int ValidaCamposMinimos();
	int MensajeValidacionCamposMinimos(SiscomRegistro3Lst *);
	int MostrandoMensajeValidacionCamposMinimos(const char *,SiscomRegistro3Lst *);
private slots:

	void SlotEscuelas(SiscomRegistro3 *);

	void SlotFocoAAPaterno();
	void SlotFocoAAMaterno();
	void SlotFocoAEscuela();
	
	void SlotFocoAGrupo();
	void SlotFocoABoleta();
	void SlotFocoACorreo();
	void SlotFocoAReCorreo();
	void SlotFocoACelular();
	void SlotFocoATCasa();
	void SlotFocoANoCredencial();

	void SlotFocoARegistrar();

	void SlotRegistra();
};
extern "C" QRegistroAlumno *InstanciaRegistroAlumno(void *,char **,void *,const char *,int);
#endif
