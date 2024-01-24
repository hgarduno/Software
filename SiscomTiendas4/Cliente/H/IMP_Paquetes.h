
#ifndef __IMP_PAQUETES_H__
#define __IMP_PAQUETES_H__
#include <UIC_H_Paquetes.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro3;
class QPaquetes:public Paquetes
{
 Q_OBJECT
public:
	QPaquetes(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPaquetes();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	char chrArrIdPaquete[12];
	SiscomRegistro3 *SReg3Producto;
	SiscomRegistro3Lst SReg3LstProductos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void AnexaProducto();
	void RegistraProductos();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotPasaFocoDescripcion();
	void SlotRegistraPaquete();
	void SlotSeleccionandoProducto(SiscomRegistro3 *);
	void SlotProducto(SiscomRegistro3 *);
	void SlotPasaFocoAnexarProducto();
	void SlotAnexarProducto();
	void SlotRegistraProductos();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QPaquetes *InstanciaPaquetes(void *,char **,void *,const char *,int);
#endif
