
#ifndef __IMP_PROGRAMANDOCURSO_H__
#define __IMP_PROGRAMANDOCURSO_H__
#include <UIC_H_ProgramandoCurso.h>
#include <CQSisCursosDiaHora.h>
class SiscomDatCom;
class SiscomRegistro3;
class QProgramandoCurso:public ProgramandoCurso
{
 Q_OBJECT
public:
	QProgramandoCurso(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QProgramandoCurso();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3ProgramacionCurso;
	SiscomRegistro3 *SisReg3Curso;
	SiscomRegistro3Lst SisReg3LstCostosCurso;
	CQSisCursosDiaHora CQSisCuDiaHora;
private:
	void ConectaSlots();
	void IniciaVariables();

	void ValidandoRegistroCurso(char *pchrPtrHoraInicio,
				    char *pchrPtrHoraFin);
	void MuestraCursosProgramados();
	void MuestraCursosPorHora(int pintDia,SiscomRegistro3Lst *pSisReg3LstCursos);
	void HabilitaProgramacionCurso();
	int VerificaAlgunaCeldaSeleccionada();
	void ConsultandoPreciosCurso(const char *pchrPtrIdProgramacion,
				     const char *pchrPtrIdCurso,
				     const char *pchrPtrCurso);
	int ConsultaPreciosCurso(const char *pchrPtrIdProgramacion,const char *pchrPtrIdCurso);
	void MuestraPreciosCurso();
	int EsHoraInicioFinCurso(SiscomRegistro3 *pSiscomReg3Dato,SiscomRegistro3 *pSiscomReg3Sig);
				 
private slots:
	void SlotAgregaProgramacion();
	void SlotHabilitaProgramacionCursos();
	void SlotHabilitaCursos();
	void SlotProgramacionCurso(SiscomRegistro3 *);
	void SlotCurso(SiscomRegistro3 *);
	void SlotCapturoFecha();
	void SlotFocoAHoraInicioFin();
	void SlotCapturoRangoHora(char *pchrPtrHoraInicio,
				  char *pchrPtrHoraFin);
	void SlotRegistraFecha();
	void SlotRegistraProgramacionCurso();
	void SlotEliminaHorariosSeleccionados();
	void SlotConsultaCursosPorFecha();
	void SlotSeSeleccionoAlgo();
	void SlotSeleccionandoCurso(int pintFila,int pintColumna,int,const QPoint &);
};
extern "C" QProgramandoCurso *InstanciaProgramandoCurso(void *,char **,void *,const char *,int);
#endif
