
#ifndef __IMP_ORDENESVENDIDAS_H__
#define __IMP_ORDENESVENDIDAS_H__
#include <UIC_H_OrdenesVendidas.h>
#include <ProductosE.h>
#include <ControladorOrdenes.h>
class SiscomDatCom;
class QOrdenesVendidas:public OrdenesVendidas
{
 Q_OBJECT
public:
	QOrdenesVendidas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QOrdenesVendidas();
	
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	GeneralesOrden GOrdenes;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ObtenProductosOrden(const char *,ProductosE &);
	void ProductosLog(ProductosE );
	void MuestraProductos(ProductosE );
	void CopiaArgumentos(char ***);
	void closeEvent(QCloseEvent *);
private slots:
	void S_PasaFocoAnexarOrden();
	void S_AnexarOrden();
	void S_NuevaOrden();
	void S_OrdenesPorFecha();
	void S_Facturacion();
private:
	ProductosE PProductos;
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QOrdenesVendidas *InstanciaOrdenesVendidas(void *,char **,void *,const char *,int);
#endif
