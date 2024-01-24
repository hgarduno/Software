#ifndef __IMP_CAPTURACANTIDAD_H__
#define __IMP_CAPTURACANTIDAD_H__
#include <UIC_H_CapturaCantidad.h>
class SiscomDatCom;
class CQSisProdCotiza;
class QCapturaCantidad:public CapturaCantidad
{
 Q_OBJECT
public:
	QCapturaCantidad(
	    CQSisProdCotiza *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapturaCantidad();
	int Opcion();
private:
	CQSisProdCotiza *CQSPCotiza;
	int intOpcion;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotPasaFocoAceptar();
	void SlotAceptar();
	void SlotCancelar();
	
};
#endif
