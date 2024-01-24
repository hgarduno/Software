
#ifndef __IMP_INVENTARIOBODEGA_H__
#define __IMP_INVENTARIOBODEGA_H__
#include <UIC_H_InventarioBodega.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro3;
class CQSisInventarioBodega;
class QInventarioBodega:public InventarioBodega
{
 Q_OBJECT
public:
	QInventarioBodega(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QInventarioBodega();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Producto;
	SiscomRegistro3 *SisReg3Bodega;
	SiscomRegistro3 *SisReg3ProdBodega;
	SiscomRegistro3Lst SisReg3LstProductos;
private:
	void ConectaSlots();
	void IniciaVariables();

	void ExistenciaActual();
	void closeEvent(QCloseEvent *);
	CQSisInventarioBodega *RegistroInventarioBodega();
	void AnexaProducto();
private slots:
	void SlotSeleccionando(SiscomRegistro3 *);
	void SlotSelecciono(SiscomRegistro3 *);
	void SlotBodega(SiscomRegistro3 *);
	void SlotPasaFocoRegistra();
	void SlotRegistra();
	void SlotActivaBodegas();
signals:
	void SignalTerminar(QWidget *);

};
extern "C" QInventarioBodega *InstanciaInventarioBodega(void *,char **,void *,const char *,int);
#endif
