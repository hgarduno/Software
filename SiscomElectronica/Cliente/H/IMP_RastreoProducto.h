#ifndef __IMP_RASTREOPRODUCTO_H__
#define __IMP_RASTREOPRODUCTO_H__
#include <UIC_H_RastreoProducto.h>
class SiscomDatCom;
class SiscomRegistro3;
class CQSisRastreoProducto;
class QRastreoProducto:public RastreoProducto
{
 Q_OBJECT
public:
	QRastreoProducto(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRastreoProducto();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisRastreoProducto *CQSRastreoProducto;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
	void RastreaProducto(SiscomRegistro3 *pSisReg3Producto);
	void IniciaRastreoProducto(SiscomRegistro3 *pSisReg3Producto);
	void RastreandoProducto();
	void EnviaRastreo();
	void MuestraRastreo();
	void MuestraExistencia();
	void MuestraExistenciaBodegas();
	void MuestraVentasProducto();
	void MuestraComprasProducto();
	void MuestraTransferenciasBodegasExpendio();
	void MuestraTransferenciasExpendioExpendio();
	void MuestraActualizoInventario();
	void MuestraTransferenciaBodegaBodega();
	QTable *ExistenciaBodegas();
	QTable *ActualizoInventario();
	QTable *TransferenciaBodegaBodega();
	void MuestraEncabezados();
private slots:

	void SlotPasaFocoProductos();
	void SlotPasaFocoFechaFin();
	void SlotProducto(SiscomRegistro3 *);
	void SlotProductosConDesajuste();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QRastreoProducto *InstanciaRastreoProducto(void *,char **,void *,const char *,int);
#endif
