
#include <QtModuloBodegas.h>
#include <QCtrlBodegas4.h>
#include <zBodega.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <IMP_InventarioBodega4.h>
#include <IMP_TransfiereBodegaBodega.h>

#include <qtabwidget.h>
QtModuloBodegas::QtModuloBodegas(char **pchrPtrArgumentos,
			         QWidget *pQWParent,
				 const char *pchrPtrName,
				 WFlags pWFlags):
			ModuloBodegas(pQWParent,pchrPtrName,pWFlags),
			QWParent(pQWParent),
			zBodegaA(0)
{

}
void QtModuloBodegas::IniciaVariables()
{
EliminaInicio();
IniciaControles();
IniciaOperaciones();
ConectaSlots();
}
void QtModuloBodegas::IniciaOperaciones()
{
  AgregaOperacion((QInvBodega4=InventarioBodega()),"Captura Inventario");
  AgregaOperacion((QTransfiereBB=TransfiereBodegaBodega()),"Transfiere Bodega A Bodega");
}
void QtModuloBodegas::ConectaSlots()
{
connect(QCtrBodegas,SIGNAL(SignalBodega(zBodega *)),SLOT(SlotBodega(zBodega *))); 
connect(QTWOperaciones,SIGNAL(currentChanged(QWidget *)),SLOT(SlotOperacion(QWidget *)));

}
void QtModuloBodegas::SlotOperacion(QWidget *pQWidget)
{
    pQWidget->setFocus();
}
void QtModuloBodegas::SlotBodega(zBodega *pzBodega)
{
  AsignaBodega(pzBodega);
  ActivaOperacion();
  BodegaAOperaciones();
}

void QtModuloBodegas::BodegaAOperaciones()
{
  QInvBodega4->Bodega(Bodega());
  zSiscomQt3::Foco(QInvBodega4);
}
void QtModuloBodegas::Conexion(zSiscomConexion *pzSisConexion)
{
   zSisConexion=pzSisConexion;
}
void QtModuloBodegas::AgregaOperacion(QWidget *pQWOperacion,
				      const QString &pQStrTitulo)
{
 QTWOperaciones->addTab(pQWOperacion,pQStrTitulo);
}
QTransfiereBodegaBodega *QtModuloBodegas::TransfiereBodegaBodega()
{
QTransfiereBodegaBodega *lQTransfiereBB;
lQTransfiereBB=new QTransfiereBodegaBodega(zSisConexion,0,QWParent);
return lQTransfiereBB;
}
QInventarioBodega4 *QtModuloBodegas::InventarioBodega()
{
QInventarioBodega4 *lQInvBodega;
lQInvBodega=new QInventarioBodega4(zSisConexion,0,QWParent);
return lQInvBodega;
}
void QtModuloBodegas::EliminaInicio()
{
  QTWOperaciones->removePage(QTWOperaciones->currentPage());
}
void QtModuloBodegas::IniciaControles()
{
QCtrBodegas->Servidor(zSisConexion);
QCtrBodegas->IniciaControl();
}
zBodega *QtModuloBodegas::Bodega()
{
  return zBodegaA;
}
void QtModuloBodegas::AsignaBodega(zBodega *pzBodega)
{
   if(pzBodega)
    zBodegaA=pzBodega;
}
bool QtModuloBodegas::BodegaValida()
{
  return  Bodega() ?  true : false;
}
void QtModuloBodegas::ActivaOperacion()
{
   QTWOperaciones->currentPage()->setEnabled(BodegaValida());
}
