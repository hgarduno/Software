
#ifndef __IMP_REPORTEVENTASCURSOS_H__
#define __IMP_REPORTEVENTASCURSOS_H__
#include <UIC_H_ReporteVentasCursos.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro3;
class QReporteVentasCursos:public ReporteVentasCursos
{
 Q_OBJECT
public:
	QReporteVentasCursos(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QReporteVentasCursos();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3ProgCurso;
	SiscomRegistro3Lst SisReg3LstVentasCursos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoVentasCursos();
	void ConsultaVentasCursos();
	void MuestraVentasCursos();
private slots:
	void SlotProgramacionCurso(SiscomRegistro3 *pSisReg3Fecha);
};
extern "C" QReporteVentasCursos *InstanciaReporteVentasCursos(void *,char **,void *,const char *,int);
#endif
