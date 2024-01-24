
#ifndef __IMP_VENTASMEDICO_H__
#define __IMP_VENTASMEDICO_H__
#include <UIC_H_VentasMedico.h>
class SiscomDatCom;
class CQSisPersona;
class QVentasMedico:public VentasMedico
{
 Q_OBJECT
public:
	QVentasMedico(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QVentasMedico();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisPersona *CQSMedico;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ReporteVentas();
private slots:
	void SlotMedico(CQSisPersona *);
};
extern "C" QVentasMedico *InstanciaVentasMedico(void *,char **,void *,const char *,int);
#endif
