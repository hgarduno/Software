#ifndef __CQSISCOMUNPAQUETES_H__
#define __CQSISCOMUNPAQUETES_H__
#include <qwidget.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class QTable;

class CQSisProductosPaquete:public QObject
{
Q_OBJECT
public:
	CQSisProductosPaquete(SiscomDatCom *pSisDatCom,
			      QTable *pQTProductos,
			      QObject *pQOParent,
			      const char *pchrPtrName);
	void ProductosPaquete(const char *pchrPtrIdPaquete);
private:
	void ConsultaProductosPaquete(const char *pchrPtrIdPaquete);
	void MuestraProductosPaquete();
	void ConectaSlots();
private:
	QTable *QTProductos;
	SiscomRegistro3Lst SReg3LstProductos;
	SiscomDatCom *SisDatCom;
private slots:
	void SlotProducto(int ,int,int,const QPoint &);
signals:
	void SignalProducto(SiscomRegistro3 *);
};

#endif
