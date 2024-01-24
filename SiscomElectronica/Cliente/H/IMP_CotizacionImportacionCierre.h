
#ifndef __IMP_COTIZACIONIMPORTACIONCIERRE_H__
#define __IMP_COTIZACIONIMPORTACIONCIERRE_H__
#include <UIC_H_CotizacionImportacionCierre.h>
class SiscomDatCom;
class QCotizacionImportacionCierre:public CotizacionImportacionCierre
{
 Q_OBJECT
public:

enum QCotImpCierre
{
	Cierre,
	SeleccionaOtraCotizacion,
	RegistraOtraCotizacion
};
	QCotizacionImportacionCierre(
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCotizacionImportacionCierre();
	QCotImpCierre ComoCierro();
private:
	QCotImpCierre QCotImpCerrando;
private:
	void ConectaSlots();
	void IniciaVariables();
	void reject();
private slots:
	void SlotCerrar();
	void SlotOtraCotizacion();
	void SlotRegistraCotizacion();
};
#endif
