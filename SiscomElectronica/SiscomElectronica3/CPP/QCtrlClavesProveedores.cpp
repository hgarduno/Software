#include <QCtrlClavesProveedores.h>
#include <IMP_ProductosSimilares.h>

#include <zProducto.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>


#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>

#include <zClavesProveedor.h>
#include <zClaveProveedor.h>

QCtrlClavesProveedores::QCtrlClavesProveedores(QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName),
			intSiEnLista(0),
			zClavesProv(0)

{

IniciaVariables();
ConectaSlots();

}
void QCtrlClavesProveedores::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QCBProductos=new QComboBox(this);
QHBLayout->addWidget(QCBProductos);
QLEProducto=zSiscomQt3::EditAlCombo(QCBProductos,"QLEProducto");
QCBProductos->setAutoCompletion(true);
QCBProductos->setDuplicatesEnabled(false);
QCBProductos->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlClavesProveedores::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlClavesProveedores::IniciaControl()
{
   Consultando();
}
void QCtrlClavesProveedores::ConectaSlots()
{
connect(QCBProductos,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBProductos,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
connect(QCBProductos,
	SIGNAL(activated(const QString &)),
	SLOT(SlotProducto(const QString &)));
}
void QCtrlClavesProveedores::SlotProducto(const QString &pQStrTexto)
{
/*
  if(!intSiEnLista)
  {
   ConsultandoProductosSimilares((const char *)pQStrTexto);
   emit  SignalProductoNoValido(IniciaParaProducto((const char *)pQStrTexto));
  }
   intSiEnLista=0;
*/
}
void QCtrlClavesProveedores::SlotSelecciono(int pintNProducto)
{
/*
 emit SignalSelecciono((*zClavesProv)[pintNProducto]);
 intSiEnLista=1;
*/
}
void QCtrlClavesProveedores::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zClavesProv)[pintNProducto]);
}
void QCtrlClavesProveedores::ConsultaProductos()
{
/*
zSiscomElectronica lzSisElectronica(zSisConexion,"ClavesProveedores");
zClavesProv=lzSisElectronica.Productos((const char *)0); 

*/
}
void QCtrlClavesProveedores::MuestraProductos()
{
zSiscomQt3::RegistrosAlCombo(QCBProductos,"cveproducto",zClavesProv);
}
QLineEdit *QCtrlClavesProveedores::QLineEditProducto()
{
	return QLEProducto;
}
void QCtrlClavesProveedores::setFocus()
{
zSiscomQt3::Foco(QLEProducto);
}
void QCtrlClavesProveedores::Consultando()
{
 EliminandoProductos();
 ConsultaProductos();
 MuestraProductos();
}
void QCtrlClavesProveedores::ConsultandoProductosSimilares(const char *pchrPtrCriterio)
{
char lchrArrProducto[128];
QProductosSimilares lQProdSimilares(pchrPtrCriterio);
LogSiscom("Buscando algun producto similar  %d ",lQProdSimilares.SiHayAlgunProducto());


if(lQProdSimilares.Producto(lchrArrProducto))
    QLEProducto->setText(lchrArrProducto);
if(lQProdSimilares.HayVariosSeleccionados())
 emit SignalSeleccionados(lQProdSimilares.Seleccionados());
}
void QCtrlClavesProveedores::EliminandoProductos()
{
  if(zClavesProv && zClavesProv->NNodos())
  {
	QCBProductos->clear();
	zClavesProv->Libera();
  }
}

zSiscomRegistro *QCtrlClavesProveedores::Producto(const char *pchrPtrClave)
{
return zClavesProv->BuscaRegistro("cveproducto",pchrPtrClave);
}
zProducto *QCtrlClavesProveedores::IniciaParaProducto(const char *pchrPtrTexto)
{
 zProducto *lzProducto;
    lzProducto=new zProducto();
    lzProducto->Descripcion(pchrPtrTexto);
   return lzProducto;
}
