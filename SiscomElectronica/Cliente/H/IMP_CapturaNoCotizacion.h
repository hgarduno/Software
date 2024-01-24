
#ifndef __IMP_CAPTURANOCOTIZACION_H__
#define __IMP_CAPTURANOCOTIZACION_H__
#include <UIC_H_CapturaNoCotizacion.h>
#include <ProductosE.h>
class SiscomDatCom;
class QCapturaNoCotizacion:public CapturaNoCotizacion
{
 Q_OBJECT
public:
	QCapturaNoCotizacion(SiscomDatCom *,
	    char **,
	    const char *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=true,
	    WFlags pWFlags=0);
	~QCapturaNoCotizacion();
	void ObtenProductosCotizacion(ProductosE *);
	int ObtenBotonPulsado();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	ProductosE PProductos;
	const char *chrPtrTipo;
	int intBoton;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Cotizacion();
	void Orden();
	void closeEvent(QCloseEvent *);
private slots:
	void S_PasaFocoAceptar();
	void S_Aceptar();
	void S_Cancelar();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QCapturaNoCotizacion *InstanciaCapturaNoCotizacion(void *,char **,void *,const char *,int);
#endif
