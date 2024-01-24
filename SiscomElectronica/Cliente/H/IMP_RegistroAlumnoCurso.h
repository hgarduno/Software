
#ifndef __IMP_REGISTROALUMNOCURSO_H__
#define __IMP_REGISTROALUMNOCURSO_H__
#include <UIC_H_RegistroAlumnoCurso.h>
#include <SiscomRegistros.h>
class SiscomDatCom;
class SiscomRegistro3;
class QRegistroAlumnoCurso:public RegistroAlumnoCurso
{
 Q_OBJECT
public:
	QRegistroAlumnoCurso(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroAlumnoCurso();
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
	SiscomRegistro3Lst SisReg3LstCostosCurso;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoFechasCursos();
	void ConsultaFechasCurso();
	void MuestraFechasCurso();
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
	void ConsultandoCostosCurso(SiscomRegistro3 *pSisReg3FechaCurso);
	void ConsultaCostosCurso(SiscomRegistro3 *pSisReg3FechaCurso);
	void MuestraCostosCurso();
private slots:
	void SlotCurso(SiscomRegistro3 *);
	void SlotSeleccionaHorarioCurso(int,int,int,const QPoint &);
	void SlotSeleccionaCostoCurso(int,int,int,const QPoint &);

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
	
	void SlotDisponibilidadCursos();

	void SlotImprimeComprobante();
	void SlotInscribeOAlumno();
};
extern "C" QRegistroAlumnoCurso *InstanciaRegistroAlumnoCurso(void *,char **,void *,const char *,int);
#endif
