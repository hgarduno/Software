
#ifndef __IMP_BODEGASSISCOM_H__
#define __IMP_BODEGASSISCOM_H__
#include <UIC_H_BodegasSiscom.h>
class SiscomDatCom;
class SiscomRegistro3;
class QBodegasSiscom:public BodegasSiscom
{
 Q_OBJECT
public:
	QBodegasSiscom(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QBodegasSiscom();
	int Aceptar();
	SiscomRegistro3 *Bodega();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Bodega;
	int intAceptar;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotBodega(SiscomRegistro3 *);
	void SlotAceptar();
	void SlotCancelar();
};
#endif
