#include <QCtrlProductosSE.h>
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

QCtrlProductosSE::QCtrlProductosSE(QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName),
			intSiEnLista(0),
			zSisRegsProductos(0)
{

IniciaVariables();
ConectaSlots();

}
void QCtrlProductosSE::IniciaVariables()
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
void QCtrlProductosSE::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlProductosSE::IniciaControl()
{
   Consultando();
}
void QCtrlProductosSE::ConectaSlots()
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
void QCtrlProductosSE::SlotProducto(const QString &pQStrTexto)
{
  if(!intSiEnLista)
  {
   ConsultandoProductosSimilares((const char *)pQStrTexto);
   emit  SignalProductoNoValido(IniciaParaProducto((const char *)pQStrTexto));
  }
   intSiEnLista=0;
}
void QCtrlProductosSE::SlotSelecciono(int pintNProducto)
{
 emit SignalSelecciono((*zSisRegsProductos)[pintNProducto]);
 intSiEnLista=1;
}
void QCtrlProductosSE::SlotSeleccionando(int pintNProducto)
{
if(pintNProducto!=-1)
emit SignalSeleccionando((*zSisRegsProductos)[pintNProducto]);
}
void QCtrlProductosSE::ConsultaProductos()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ProductosSE");
zSisRegsProductos=lzSisElectronica.Productos((const char *)0); 
}
void QCtrlProductosSE::MuestraProductos()
{
zSiscomQt3::RegistrosAlCombo(QCBProductos,"cveproducto",zSisRegsProductos);
}
QLineEdit *QCtrlProductosSE::QLineEditProducto()
{
	return QLEProducto;
}
void QCtrlProductosSE::setFocus()
{
zSiscomQt3::Foco(QLEProducto);
}
void QCtrlProductosSE::Consultando()
{
 EliminandoProductos();
 ConsultaProductos();
 MuestraProductos();
}
void QCtrlProductosSE::ConsultandoProductosSimilares(const char *pchrPtrCriterio)
{
char lchrArrProducto[128];
QProductosSimilares lQProdSimilares(pchrPtrCriterio);

if(lQProdSimilares.Producto(lchrArrProducto))
    QLEProducto->setText(lchrArrProducto);
if(lQProdSimilares.HayVariosSeleccionados())
 emit SignalSeleccionados(lQProdSimilares.Seleccionados());
}
void QCtrlProductosSE::EliminandoProductos()
{
  if(zSisRegsProductos && zSisRegsProductos->NNodos())
  {
	QCBProductos->clear();
	zSisRegsProductos->Libera();
  }
}

zSiscomRegistro *QCtrlProductosSE::Producto(const char *pchrPtrClave)
{
return zSisRegsProductos->BuscaRegistro("cveproducto",pchrPtrClave);
}
zProducto *QCtrlProductosSE::IniciaParaProducto(const char *pchrPtrTexto)
{
 zProducto *lzProducto;
    lzProducto=new zProducto();
    lzProducto->Descripcion(pchrPtrTexto);
   return lzProducto;
}
