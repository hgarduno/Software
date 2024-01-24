
#ifndef __IMP_MANEMPLEADOS_H__
#define __IMP_MANEMPLEADOS_H__
#include <UIC_H_ManEmpleados.h>
#include <CQSisPersFresno.h>
class SiscomDatCom;
class CSISCOMDatComunicaciones;
class QManEmpleados:public ManEmpleados
{
 Q_OBJECT
public:
	QManEmpleados(CSISCOMDatComunicaciones*,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QManEmpleados();
private:
	SiscomDatCom *SisDatCom;
	void *chrPtrArgumentos;
	CQSisPersFresnoLst CQSLPFresnoLst;
	CQSisPersFresno *CQSPFresno;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraEmpleados();
	void ConsultaEmpleados();
	void ConsultandoEmpleados();
	void BorraEmpleado();
	void EliminaConsultaAnterior();

private slots:
	void SlotSeleccionando(int,int,int,const QPoint & );
	void SlotCambioFila();
	void SlotBorra();
};
extern "C" QManEmpleados *InstanciaManEmpleados(void *,void *,const char *,int);
#endif
