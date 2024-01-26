#include <QtImprimiendoRepStockDepartamentoProveedor.h>
#include <QtImprimeRepStockDepartamentoProveedor.h>
#include <qlayout.h>
#include <qpushbutton.h>
QtImprimiendoRepStockDepartamentoProveedor::QtImprimiendoRepStockDepartamentoProveedor(
							zSiscomConexion *pzSisConexion,
							zSiscomRegistros *pzSisRegsInformacion,
							QWidget *pQWParent,
							const char *pchrPtrName,
							bool pbModal,
							WFlags pWFlags):
						QDialog(pQWParent,pchrPtrName,pbModal,pWFlags),
						zSisConexion(pzSisConexion),
						zSisRegsInformacion(pzSisRegsInformacion)
{

ColocaControles();
resize(QSize(1280,400));
exec();
}
void QtImprimiendoRepStockDepartamentoProveedor::ColocaControles()
{
QVBLayout=new QVBoxLayout(this);
QPBImprimir=new QPushButton("Imprimir",this,"QPBImprimir");
QtImpRepStockProv=new QtImprimeRepStockDepartamentoProveedor(zSisConexion,
							     zSisRegsInformacion,
							     this,
							     "QtImpRepStockProv");
QVBLayout->addWidget(QtImpRepStockProv);
QVBLayout->addWidget(QPBImprimir);
}
