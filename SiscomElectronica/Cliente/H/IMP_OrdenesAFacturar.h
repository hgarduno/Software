
#ifndef __IMP_ORDENESAFACTURAR_H__
#define __IMP_ORDENESAFACTURAR_H__
#include <UIC_H_OrdenesAFacturar.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro3;
class QOrdenesAFacturar:public OrdenesAFacturar
{
 Q_OBJECT
public:
	QOrdenesAFacturar(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QOrdenesAFacturar();
	void ObtenFacturacion(SiscomRegistro3Lst *pSisReg3LstProdAFacturar);
	void PonOrdenes(SiscomRegistro3Lst  *pSisReg3LstOrdenes);
	void ObtenOrdenes(SiscomRegistro3Lst *pSisReg3LstOrdenes);
	void ConsultandoOrdenesAFacturar();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisReg3LstOrdenes;
	SiscomRegistro3Lst SisReg3LstProdAFacturar;
	SiscomRegistro3Lst SisReg3LstProdOrden;

private:
	void ConectaSlots();
	void IniciaVariables();
	SiscomRegistro3 *CreaRegistroOrden();
	SiscomRegistro3 *CreaRegistroOrden(const  char *pchrPtrIdOrden);
	void AgregaOrden(SiscomRegistro3 *pSisReg3Orden);
	void EnviaOrdenes();
	void Muestra();
	void MuestraTotales();
	void MuestraOrdenes();
	void MuestraOrden();
	void MuestraOrdenPorNoOrden();
	void ColocaOrdenActual();
	/*
	 *
	 *  Se implemento para depuracion
	 */
	void CargaOrdenesEntradaEstandar();
	
private slots:
	void SlotAnexaOrden();
	void SlotPasaFocoAnexarOrden();
	void SlotProductosOrden(int pintFila,
				int pintColumna,
				int,
				const QPoint &);
	void SlotAceptar();
};
#endif
