
#ifndef __IMP_FACTURACION_H__
#define __IMP_FACTURACION_H__
#include <UIC_H_Facturacion.h>
#include <ProductosE.h>
class SiscomDatCom;
class GeneralesOrden;
class QFacturacion:public Facturacion
{
 Q_OBJECT
public:
	QFacturacion(SiscomDatCom *,
	    char **,
	    GeneralesOrden *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QFacturacion();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	GeneralesOrden *GenOrdenes;
	ProductosE PProductos;


private:
	void ConectaSlots();
	void IniciaVariables();
	void CalculaFacturacion();
	void MuestraCalculoFacturacion();
	void MuestraDatosOrdenes();

private slots:
	void S_ImprimeFactura();
};
#endif
