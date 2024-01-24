
#ifndef __IMP_REPORTANDOVENTAS_H__
#define __IMP_REPORTANDOVENTAS_H__
#include <UIC_H_ReportandoVentas.h>
class SiscomDatCom;
class QReportandoVentas:public ReportandoVentas
{
 Q_OBJECT
public:
	QReportandoVentas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QReportandoVentas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Muestra();
	void Consulta();
private slots:
	void SlotFocoAFechaFin();
	void SlotFocoConsultar();
	void SlotConsultar();
};
extern "C" QReportandoVentas *InstanciaReportandoVentas(void *,char **,void *,const char *,int);
#endif
