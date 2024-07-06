#include <QtTransfiereBodegaBodega.h>

#include <zSiscomQt3.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zTransfiereBodegaBodega.h>
#include <zExistenciaBodega.h>
#include <zExistenciaBodegaOriDes.h>

#include <QCtrlCmbBodegas4.h>
#include <QCtrlProductosSE.h>

#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qtable.h>
QtTransfiereBodegaBodega::QtTransfiereBodegaBodega(QWidget *pQWParent,
						   const char *pchrPtrName,
						   WFlags pWFlags):
				TransfiereBodegaBodega(pQWParent,pchrPtrName,pWFlags),
				zBodegaD(0),
				zBodegaO(0),
				zSisRegProducto(0),
				intNTransferencia(0)
{
 setFocus();
}
void QtTransfiereBodegaBodega::Conexion(zSiscomConexion *pzSisConexion)
{
   zSisConexion=pzSisConexion;
}
zSiscomConexion *QtTransfiereBodegaBodega::Conexion()
{
  return zSisConexion;
}
void QtTransfiereBodegaBodega::Conexiones()
{
  QCmbBodegasO->Servidor(Conexion());
  QCmbBodegasD->Servidor(Conexion());
  QCtrProductos->Servidor(Conexion());
} 
void QtTransfiereBodegaBodega::IniciaControles()
{
 QCmbBodegasO->IniciaControl();
 QCmbBodegasD->IniciaControl();
 QCtrProductos->IniciaControl();
}
void QtTransfiereBodegaBodega::IniciaVariables()
{
	IniciandoVariables();
	Conexiones();
	IniciaControles();
	ConectaSlots();
}
void QtTransfiereBodegaBodega::IniciandoVariables()
{
	zTransfiereBB=new zTransfiereBodegaBodega;
}
void QtTransfiereBodegaBodega::ConectaSlots()
{
ConectaSlotBodega(QCmbBodegasO,SLOT(SlotBodegaO(zBodega *)));
ConectaSlotBodega(QCmbBodegasD,SLOT(SlotBodegaD(zBodega *)));


connect(QCtrProductos,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotProducto(zSiscomRegistro *)));
connect(QLECantidad,SIGNAL(returnPressed()),SLOT(SlotFocoAActualiza()));
connect(QPBTransfiere,SIGNAL(clicked()),SLOT(SlotTransfiere()));
}
void QtTransfiereBodegaBodega::SlotTransfiere()
{
  Transfiriendo();
  AsignandoTransferencias();
  MuestraRegistro();
  //HabilitaDesHabilita(false);
  zSiscomQt3::Foco(QCtrProductos);
}
void QtTransfiereBodegaBodega::SlotFocoAActualiza()
{
   ActivaActualiza();
    zSiscomQt3::Foco(QPBTransfiere);
}
void QtTransfiereBodegaBodega::SlotProducto(zSiscomRegistro *pzSisRegProducto)
{
	SeleccionoProducto(pzSisRegProducto);
}
void QtTransfiereBodegaBodega::ConectaSlotBodega(QCtrlCmbBodegas4 *pQCtrlCmbBodegas,
						 const char *pchrPtrSlot)
{
connect(pQCtrlCmbBodegas,SIGNAL(SignalSelecciono(zBodega *)),pchrPtrSlot);
}
void QtTransfiereBodegaBodega::SlotBodegaD(zBodega *pzBodegaD)
{
	SeleccionoBodegaDestino(pzBodegaD);
      HabilitaProductos();
}
void QtTransfiereBodegaBodega::SlotBodegaO(zBodega *pzBodegaO)
{
      SeleccionoBodegaOrigen(pzBodegaO);
}

void QtTransfiereBodegaBodega::SeleccionoBodegaOrigen(zBodega *pzBodegaO)
{
	zBodegaO=pzBodegaO;
	QCmbBodegasD->setEnabled(true);
    	zSiscomQt3::Foco(QCmbBodegasD);
}

void QtTransfiereBodegaBodega::SeleccionoBodegaDestino(zBodega *pzBodegaD)
{
	zBodegaD=pzBodegaD;
	zSiscomQt3::Foco(QCtrProductos);
}
void QtTransfiereBodegaBodega::SeleccionoProducto(zSiscomRegistro *pzSisRegProducto)
{
        zSisRegProducto=pzSisRegProducto;
	zSiscomQt3::Foco(QLECantidad);
	QTEDescripcion->setText((const char *)(*zSisRegProducto)["dscproducto"]);
	zExistenciaBO=IniciaExistenciaBodega(BodegaO());
	zExistenciaBD=IniciaExistenciaBodega(BodegaD());
	ExistenciaOrigen();
	ExistenciaDestino();
}

void QtTransfiereBodegaBodega::Transfiriendo()
{
   FormaBodegaBodega();
   Transfiere();
   zSiscomQt3::Foco(QCtrProductos);
   QPBTransfiere->setEnabled(false);
}
void QtTransfiereBodegaBodega::Transfiere()
{

}
zTransfiereBodegaBodega *QtTransfiereBodegaBodega::BodegaBodega()
{
  return zTransfiereBB;
}
void QtTransfiereBodegaBodega::FormaBodegaBodega()
{
 BodegaBodega()->BodegaD(zBodegaD);
 BodegaBodega()->BodegaO(zBodegaO);
 BodegaBodega()->Cantidad(zSiscomQt3::Texto(QLECantidad));
 BodegaBodega()->CveProducto((const char *)(*zSisRegProducto)["cveproducto"]);
}

void QtTransfiereBodegaBodega::Existencia(QLineEdit *pQLEExistencia,
					  zExistenciaBodega *pzExistenciaB)
{
  Consultando(pzExistenciaB);
  MuestraExistencia(pQLEExistencia,pzExistenciaB);
}
void QtTransfiereBodegaBodega::MuestraExistencia(QLineEdit *pQLEExistencia,
						 zExistenciaBodega *pzExistenciaB)
{
  pQLEExistencia->setText(pzExistenciaB->Existencia());
}
void QtTransfiereBodegaBodega::ExistenciaOrigen()
{
      Existencia(QLEExistenciaO,zExistenciaBO);
}
void QtTransfiereBodegaBodega::ExistenciaDestino()
{
  Existencia(QLEExistenciaD,zExistenciaBD);
}
void QtTransfiereBodegaBodega::Consultando(zExistenciaBodega *)
{

}
zExistenciaBodega *QtTransfiereBodegaBodega::IniciaExistenciaBodega(zBodega *pzBodega)
{
zExistenciaBodega *lzExistenciaB;

 lzExistenciaB=new zExistenciaBodega(pzBodega);
 lzExistenciaB->Producto(Producto());
 return lzExistenciaB;
}

zBodega *QtTransfiereBodegaBodega::BodegaD()
{
 	return zBodegaD;
}

zBodega *QtTransfiereBodegaBodega::BodegaO()
{
	return zBodegaO;
}
void QtTransfiereBodegaBodega::MuestraRegistro()
{
zExistenciaBodegaOriDes *lzExistenciaBodOriDes;
int lintNFila;
QTDatos->setNumRows(Transferencias().NNodos());
for(lzExistenciaBodOriDes=(zExistenciaBodegaOriDes *)Transferencias().Primer(),
    lintNFila=0;
    lzExistenciaBodOriDes;
    lzExistenciaBodOriDes=(zExistenciaBodegaOriDes *)Transferencias().Siguiente(),
    lintNFila++)
{
QTDatos->setText(lintNFila,0,Transferencias().Producto(lintNFila));
QTDatos->setText(lintNFila,1,Transferencias().Cantidad(lintNFila));
QTDatos->setText(lintNFila,2,Transferencias().BodegaO(lintNFila));
QTDatos->setText(lintNFila,3,Transferencias().ExistenciaO(lintNFila));
QTDatos->setText(lintNFila,4,Transferencias().BodegaD(lintNFila));
QTDatos->setText(lintNFila,5,Transferencias().ExistenciaD(lintNFila));
}
zSiscomQt3::AjustaColumnasTabla(QTDatos);
}

zTransferenciasBodegaBodega &QtTransfiereBodegaBodega::Transferencias()
{
	return zTransBodBod;
}
void QtTransfiereBodegaBodega::AsignandoTransferencias()
{
  Transferencias().Agrega(new zExistenciaBodegaOriDes(BodegaExistenciaO(),
  						      BodegaExistenciaD()));

}
zExistenciaBodega *QtTransfiereBodegaBodega::BodegaExistenciaO()
{
  return zExistenciaBO;
}

zExistenciaBodega *QtTransfiereBodegaBodega::BodegaExistenciaD()
{
  return zExistenciaBD;
}

const char *QtTransfiereBodegaBodega::Producto()
{
  return (const char *)(*zSisRegProducto)["cveproducto"];
}

void QtTransfiereBodegaBodega::setFocus()
{
   zSiscomQt3::Foco(QCmbBodegasO);
}

void QtTransfiereBodegaBodega::ActivaActualiza()
{
   QPBTransfiere->setEnabled(zBodegaD && 
   			     zBodegaO &&
			     zSisRegProducto);
}

void QtTransfiereBodegaBodega::HabilitaDesHabilita(bool pbModal)
{
QCmbBodegasD->setEnabled(pbModal);
QCtrProductos->setEnabled(pbModal);
/* Siscom Zacatenco  
 * Miercoles 3 de abril del 2024 
 * Revisar la funcionalidad que deshabilita estos controles 
 * en particular el de cantidad 
QLECantidad->setEnabled(pbModal);

*/
QPBTransfiere->setEnabled(pbModal);
}
void QtTransfiereBodegaBodega::HabilitaProductos()
{
    QCtrProductos->setEnabled(zBodegaD && zBodegaO);
}
