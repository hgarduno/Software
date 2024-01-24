
#ifndef __IMP_MATERIALBODEGAEXPENDIO_H__
#define __IMP_MATERIALBODEGAEXPENDIO_H__
#include <UIC_H_MaterialBodegaExpendio.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro3;
class CQSisProdBodExpendio;
class QMaterialBodegaExpendio:public MaterialBodegaExpendio
{
 Q_OBJECT
public:
	QMaterialBodegaExpendio(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QMaterialBodegaExpendio();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Expendio;
	SiscomRegistro3 *SisReg3Bodega;
	SiscomRegistro3 *SisReg3Producto;
	SiscomRegistro3 *SisReg3ProductoBodega;
	SiscomRegistro3Lst SisReg3LstExiProdBodega;
	SiscomRegistro3Lst SisReg3LstProductos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
	void ConsultandoBodegas();
	void DesHabilitaExpendiosBodegas(bool);
	void ConsultandoExistenciaProducto();
	void ConsultaExistenciaProducto();
	void MuestraExistenciaProducto();
	void AnexaProducto();
	CQSisProdBodExpendio *FormaProdBodExpendio();
	void ValidaEstadoOperacion(SiscomRegistro3Lst *pSisReg3LstEdoOperacion);
	void ReIniciaDatos();
	int ValidacionExistenciaCantidad();
	void EliminaProductosLista();
private slots:
	void SlotExpendio(SiscomRegistro3 *);
	void SlotBodega(SiscomRegistro3 *);
	void SlotSeleccionando(SiscomRegistro3 *);
	void SlotSelecciono(SiscomRegistro3 *);
	void SlotPasaFocoAnexar();
	void SlotAnexar();
	void SlotRegistra();
	void SlotSeleccionaProducto(int pintNFila,int pintNColumn,int ,const QPoint &);
	void SlotEliminar();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QMaterialBodegaExpendio *InstanciaMaterialBodegaExpendio(void *,char **,void *,const char *,int);
#endif
