#include <IMP_OrdenCompraImportacion.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h> 
#include <zSiscomElectronica.h>

#include <zProductoCompraImportacion.h>
#include <zCompraImportacionProducto.h>
#include <zComprasImportacionProducto.h>

#include <QCtrlProveedoresSE.h>
#include <QCtrlProductosSE.h> 


#include <qlineedit.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>

QOrdenCompraImportacion *InstanciaOrdenCompraImportacion(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QOrdenCompraImportacion((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QOrdenCompraImportacion::QOrdenCompraImportacion(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				OrdenCompraImportacion(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
IniciaVariables();
ConectaSlots();
}

QOrdenCompraImportacion::~QOrdenCompraImportacion()
{

}

void QOrdenCompraImportacion::ConectaSlots()
{
connect(QCtrProveedores,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotProveedor(zSiscomRegistro *)));
connect(QCtrProductos,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotProducto(zSiscomRegistro *)));
connect(QLECantidadC,SIGNAL(returnPressed()),SLOT(SlotFocoAPrecio()));
connect(QLEPrecio,SIGNAL(returnPressed()),SLOT(SlotFocoAAnexar()));
connect(QLECantidadC,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCantidad(const QString &)));
connect(QLEPrecio,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoPrecio(const QString &)));
}
void QOrdenCompraImportacion::SlotCapturandoCantidad(const QString &)
{
   HabilitandoAnexar();
}
void QOrdenCompraImportacion::SlotCapturandoPrecio(const QString &)
{
   HabilitandoAnexar();
}
void QOrdenCompraImportacion::SlotFocoAPrecio()
{
  PasandoFocoAPrecio();
   AsignaCantidad();
  CalculandoPesoImporteTotal();  
}
void QOrdenCompraImportacion::SlotFocoAAnexar()
{
 AsignaPrecio();
 CalculandoPesoImporteTotal();
}
void QOrdenCompraImportacion::SlotProducto(zSiscomRegistro *pzSisRegProducto)
{
   zSisRegProducto=pzSisRegProducto;
   ObteniendoProducto();
   PasandoFocoCantidad();
}
void QOrdenCompraImportacion::SlotProveedor(zSiscomRegistro *pzSisRegProveedor)
{
    zSisRegProveedor=pzSisRegProveedor;
    SeleccionaProveedor();
}
void QOrdenCompraImportacion::IniciaVariables()
{
QCtrProductos->Servidor(zSisConexion);
QCtrProveedores->Servidor(zSisConexion);
QCtrProductos->IniciaControl();
QCtrProveedores->IniciaControl();
zSiscomQt3::Foco(QCtrProveedores);
QLCDImporte->setSmallDecimalPoint(true);
QLCDPeso->setSmallDecimalPoint(true);
}
void QOrdenCompraImportacion::SeleccionaProveedor()
{
    zSiscomQt3::Foco(QCtrProductos);
    QCtrProveedores->setEnabled(false);
}
void QOrdenCompraImportacion::ObteniendoProducto()
{
   ConsultaProducto();
   MuestraProducto();
}
void QOrdenCompraImportacion::ConsultaProducto()
{
zSiscomElectronica lzSisElecProd(zSisConexion,"ProductoCompraImportacion");
lzSisElecProd.ProductoCompraImportacion(zSisRegProducto,zSisRegProveedor,&zProdComImp);
}
void QOrdenCompraImportacion::MuestraProducto()
{
 MuestraDatosProducto();
 if(zProdComImp->Compras())
 MuestraUltimaCompra();
}
void QOrdenCompraImportacion::MuestraDatosProducto()
{
QLECveProductoProveedor->setText(zProdComImp->ClaveProveedor());  
QLEPeso->setText(zProdComImp->Peso());
QTEDescripcionP->setText(zProdComImp->DscProveedor());
}
void QOrdenCompraImportacion::MuestraUltimaCompra()
{
  QLEFecha->setText(zProdComImp->Compras()->Ultima()->Fecha());  
  QLECantidad->setText(zProdComImp->Compras()->Ultima()->Cantidad());
  QLECosto->setText(zProdComImp->Compras()->Ultima()->Costo());
  QLECostoTotal->setText(zProdComImp->Compras()->Ultima()->CostoTotal());
}
void QOrdenCompraImportacion::PasandoFocoCantidad()
{
 zSiscomQt3::Foco(QLECantidadC);
}
void QOrdenCompraImportacion::HabilitandoAnexar()
{
  QPBAnexar->setEnabled(zSisRegProducto 	&&
                        zSisRegProveedor 	&&
			zSiscomQt3::TextoValido(QLECantidadC) &&
			zSiscomQt3::TextoValido(QLEPrecio));
}
void QOrdenCompraImportacion::PasandoFocoAPrecio()
{
	zSiscomQt3::Foco(QLEPrecio);
}
void QOrdenCompraImportacion::CalculandoPesoImporteTotal()
{
CalculaPesoImporteTotal();
MuestraPesoImporteTotal();
}
void QOrdenCompraImportacion::CalculaPesoImporteTotal()
{
zSiscomElectronica lzSisElecCalculos(zSisConexion,"CalculandoPesoImporteTotal");
lzSisElecCalculos.CalculaPesoImporteTotal(zProdComImp);
}
void QOrdenCompraImportacion::MuestraPesoImporteTotal()
{
 QLCDPeso->display(zProdComImp->PesoTotal());
 QLCDImporte->display(zProdComImp->PrecioTotal());
/*
 QTEDatos->setText(QString().sprintf("							\
	<font color=\"#FF0000\">Rojo</font> 						\
       <font size = \"1\">Font size = \"1\"</font><br />				\
      	<font size = \"2\">Font size = \"2\"</font><br />				\
      	<font size = \"3\">Font size = \"3\"</font><br />				\
      	<font size = \"4\">Font size = \"4\"</font><br />				\
      	<font size = \"5\">Font size = \"5\"</font><br />				\
      <font size = \"6\">Font size = \"6\"</font><br />					\
      <font size = \"7\">Font size = \"7\"</font>					\
      <font face = \"Times New Roman\" size = \"5\">Times New Roman</font><br />		\
      <font face = \"Verdana\" size = \"5\">Verdana</font><br />				\
      <font face = \"Comic sans MS\" size =\" 5\">Comic Sans MS</font><br />		\
      <font face = \"WildWest\" size = \"5\">WildWest</font><br />				\
      <font face = \"Bedrock\" size = \"5\">Bedrock</font><br />				\
      <table class=\"default\">\
  <thead>\
    <tr>\
      <th></th>\
      <th colspan=\"2\">Anthony</th>\
      <th colspan=\"2\">Lione</th>\
    </tr>\
    <tr>\
      <th scope=\"col\">Fecha</th>\
      <th>Income</th>\
      <th>Outcome</th>\
      <th>Income</th>\
      <th>Outcome</th>\
    </tr>\
  </thead>\
  <tbody style=\"background: rgba(128, 255, 0, 0.3); border: 1px solid rgba(100, 200, 0, 0.3);\">\
    <tr>\
      <th>15/07</th>\
      <td>$200,00</td>\
      <td>$50,00</td>\
      <td>$0</td>\
      <td>$0</td>\
    </tr>\
    <tr>\
      <th>28/07</th>\
      <td>$0,00</td>\
      <td>$100,00</td>\
      <td>$100,00</td>\
      <td>$0,00</td>\
    </tr>\
  </tbody>\
  <tbody style=\"background: rgba(255, 128, 0, 0.3); border: 1px solid rgba(200, 100, 0, 0.3);\">\
    <tr>\
      <th>09/08</th>\
      <td>$0,00</td>\
      <td>$50,00</td>\
      <td>$0,00</td>\
      <td>$80,00</td>\
    </tr>\
    <tr>\
      <th>22/08</th>\
      <td>$40,00</td>\
      <td>$0,00</td>\
      <td>$0,00</td>\
      <td>$110,00</td>\
    </tr>\
    <tr>\
      <th>25/08</th>\
      <td>$0,00</td>\
      <td>$20,00</td>\
      <td>$0,00</td>\
      <td>$0,00</td>\
    </tr>\
  </tbody>\
  <tfoot>\
    <tr>\
      <th>Balance</th>\
      <td colspan=\"2\">$20,00</td>\
      <td colspan=\"2\">$10,00</td>\
    </tr>\
  </tfoot>\
</table>\
 				"));
 QTEDatos->setText(QString().sprintf("<table class=\"default\">\
					 <tr>\
					 <th>Clave Proveedor</th>\
					 <th>Peso</th>\
					 <th><font size=\"5\"Importe Total</font></th>\
					 <th><font size=\"5\"Peso Total </font></th>\
					 </tr>\
					 <tr>\
					 <td>%s</td>\
					 <td>%s</td>\
					 <td>%s</td>\
					 <td>%s</td>\
					 </tr>\
					 </table>\
				      ",
				      zProdComImp->ClaveProveedor(),
				      zProdComImp->Peso(),
				      zProdComImp->PesoTotal(),
				      zProdComImp->PrecioTotal()
				    )
 		  );
*/
}
void QOrdenCompraImportacion::AsignaPrecio()
{
  zProdComImp->Precio(zSiscomQt3::Texto(QLEPrecio));
}
void QOrdenCompraImportacion::AsignaCantidad()
{
 zProdComImp->Cantidad(zSiscomQt3::Texto(QLECantidadC));
}
