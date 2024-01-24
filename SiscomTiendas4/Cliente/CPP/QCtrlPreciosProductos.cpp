#include <QCtrlPreciosProductos.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomOperaciones3.h>
#include <CQSisComunesTiendas3Qt.h>
#include <CQSisOpTiendas43Qt.h>
#include <qlayout.h>
#include <qtable.h>


QCtrlPreciosProductos::QCtrlPreciosProductos( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
QCtrlPreciosProductos::~QCtrlPreciosProductos()
{
}
void QCtrlPreciosProductos::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QTPProducto=new QTable(0,3,this);
	QTPProducto->horizontalHeader()->setLabel(0,"Escala");
	QTPProducto->horizontalHeader()->setLabel(1,"Precio");
	QTPProducto->horizontalHeader()->setLabel(2,"Cantidad");
	QHBLayout->addWidget(QTPProducto);
}
void QCtrlPreciosProductos::Producto(const char *pchrPtrIdProducto)
{
	chrPtrIdProducto=pchrPtrIdProducto;
}
void QCtrlPreciosProductos::MuestraPreciosProducto()
{
const char *lchrPtrDatos[]={"nombre",
		      "precio",
		      "cantidad",
		      0
		      };
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrDatos,
				       QTPProducto,
				       &SReg3LstPProducto);
SiscomDesarrollo3Qt::AjustaColumnas(QTPProducto);
}
void QCtrlPreciosProductos::ConsultaPreciosProducto()
{
SReg3LstPProducto.clear();
CQSisOpTiendas43Qt lCQSOpT43QtPProd(SisDatCom);
lCQSOpT43QtPProd.PreciosProducto(chrPtrIdProducto,
				 &SReg3LstPProducto);
}
void QCtrlPreciosProductos::ObtenPrecios()
{
	ConsultaPreciosProducto();
	MuestraPreciosProducto();
}
void QCtrlPreciosProductos::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlPreciosProductos::ConectaSlots()
{
}
void QCtrlPreciosProductos::SlotPrecioProducto(int pintNProducto)
{
	
}
void QCtrlPreciosProductos::SlotPrecioProducto()
{
}
void QCtrlPreciosProductos::setFocus()
{
}

void QCtrlPreciosProductos::Limpia()
{
}

