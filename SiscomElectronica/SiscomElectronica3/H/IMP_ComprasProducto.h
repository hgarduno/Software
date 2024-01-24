
#ifndef __IMP_COMPRASPRODUCTO_H__
#define __IMP_COMPRASPRODUCTO_H__
#include <UIC_H_ComprasProducto.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro3;
/*!
 * \brief Clase que se crea para obtener la informacion de las compras <br>
 * de un producto los datos que se requieren son los siguientes : <br>
 * Producto <br>
 * Descripcion<br>
 * Fecha de la Ultima Compra <br>
 * Proveedor <br>
 * Precio de compra <br>
 * Precio de venta <br>
 * Cantidad comprada en el semestre anterior<br>
 * Cantidad Vendida en el semestre anterior<br>
 * Cantidad Vendida ? <br>
 */
class QComprasProducto:public ComprasProducto
{
 Q_OBJECT
public:
	QComprasProducto(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QComprasProducto();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SRegistro3Prod;
	SiscomRegistro3Lst SRegistro3LstHistorico;
	char chrArrPEMAlto[12];
	char chrArrPEMBajo[12];
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void ConsultaPorExistenciaMinima();
	void Muestra();
	void MuestraComprasVentas();
	void closeEvent(QCloseEvent *);
	void InformaNoHayCompras();
private slots:
	void SlotSeleccionando(SiscomRegistro3 *);
	void SlotSelecciono(SiscomRegistro3 *);
	void SlotHistorico();
	void SlotPorcentajes();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QComprasProducto *InstanciaComprasProducto(void *,char **,void *,const char *,int);
#endif
