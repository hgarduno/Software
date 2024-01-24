#include <IMP_PuntoVenta.h>
#include <QCtrlProductosSE.h>

#include <zSiscomElectronica.h>
#include <zProductoCotizar.h>


#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>
#include <qpushbutton.h>
#include <qtextbrowser.h>
#include <qlineedit.h>


QPuntoVenta *InstanciaPuntoVenta(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPuntoVenta((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPuntoVenta::QPuntoVenta(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				PuntoVenta(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zOrdVenta(0)
{
Conexion((zSiscomConexion *)gzSiscomConexion);
IniciaVariables();
ConectaSlots();
}

QPuntoVenta::~QPuntoVenta()
{

}
void QPuntoVenta::Conexion(zSiscomConexion *pzSiscomConexion)
{
   zSisConexion=pzSiscomConexion;
}
void QPuntoVenta::ConectaSlots()
{
 connect(QPBCargaArchivoHtml,
 	 SIGNAL(clicked()),
	 SLOT(SlotCargaArchivoHtml()));
 connect(QCtrProductos,
 	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotSeleccionoProducto(zSiscomRegistro *)));
 connect(QLECantidad,
 	 SIGNAL(returnPressed()),
	 SLOT(SlotFocoAProductos()));
 connect(QPBIncrementaTexto,
 	 SIGNAL(clicked()),
	 SLOT(SlotIncrementaTexto()));
 connect(QPBDecrementaTexto,
 	 SIGNAL(clicked()),
	 SLOT(SlotDecrementaTexto()));
  connect(QTBPuntoVenta,
  	  SIGNAL(linkClicked(const QString &)),
	  SLOT(SlotSeleccionoLink(const QString &)));
   connect(QTBPuntoVenta,
   	   SIGNAL(clicked(int,int)),
	   SLOT(SlotClicked(int,int)));
   connect(QTBPuntoVenta,
   	   SIGNAL(anchorClicked(const QString &,const QString &)),
	   SLOT(SlotSeleccionoLink(const QString &,const QString &)));
   connect(QPBAnexarOrden,
   	   SIGNAL(clicked()),
	   SLOT(SlotAnexarOrden()));
}
void QPuntoVenta::SlotAnexarOrden()
{
     CotizandoOrden();
     zSiscomQt3::Foco(QLECantidad);
}
void QPuntoVenta::SlotSeleccionoLink(const QString &pQStrName,
				     const QString &pQStrLink)
{
LogSiscom("Name(%s) Link(%s)",
	  (const char *)pQStrName,
	  (const char *)pQStrLink);
}
void QPuntoVenta::SlotClicked(int pintPara,
			      int pintPos)
{
LogSiscom("%d %d ",pintPara,pintPos);

}
void QPuntoVenta::SlotSeleccionoLink(const QString &pQStrLink)
{
  LogSiscom("Seleccionando %s",(const char *)pQStrLink);

}
void QPuntoVenta::SlotIncrementaTexto()
{
 QTBPuntoVenta->zoomOut();
}
void QPuntoVenta::SlotDecrementaTexto()
{
QTBPuntoVenta->zoomIn();
}
void QPuntoVenta::SlotFocoAProductos()
{
  zSiscomQt3::Foco(QCtrProductos);
}
void QPuntoVenta::SlotSeleccionoProducto(zSiscomRegistro *pzSisRegProducto)
{
zSisRegProducto=pzSisRegProducto;
CotizandoProducto(pzSisRegProducto);
}
void QPuntoVenta::SlotCargaArchivoHtml()
{
MuestraPuntoVenta();
}
void QPuntoVenta::IniciaVariables()
{
  QCtrProductos->Servidor(zSisConexion);  
  QCtrProductos->IniciaControl();
  zSiscomQt3::Foco(QLECantidad);
  MuestraPuntoVenta();
}

void QPuntoVenta::MuestraPuntoVenta()
{
CargaArchivoHtmlPuntoVenta();
sprintf(chrArrArchivoHtmlPuntoVenta,
	chrArrEncabezadoPuntoVenta,
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"");
strcat(chrArrArchivoHtmlPuntoVenta,"</table></html>");
QTBPuntoVenta->setText(chrArrArchivoHtmlPuntoVenta);
}

void QPuntoVenta::CargaArchivoHtmlPuntoVenta()
{
char lchrArrBufferLinea[256];
  zSiscomDesarrollo4::LeeArchivo("PuntoVenta.html",
  				 lchrArrBufferLinea,
				 chrArrEncabezadoPuntoVenta);
}

void QPuntoVenta::CotizandoProducto(zSiscomRegistro *pzSisRegProducto)
{
zSiscomElectronica lzSiscomE(zSisConexion,"CotizandoProductos4");
zOrdCotProducto=new zOrdenVenta(0,chrPtrArgumentos[0]);
zProductoCotizar *lzProdCotizar=new zProductoCotizar(zSiscomQt3::Texto(QLECantidad),
						     0,
						     pzSisRegProducto);
	zOrdCotProducto->AgregaProducto(lzProdCotizar);
	lzSiscomE.CotizaOrden(zOrdCotProducto,0);
	MuestraCotizacionProducto(zOrdCotProducto);
	zProdCotizar=zOrdCotProducto->Producto(0);
	delete zOrdCotProducto;
zSiscomQt3::Foco(QPBAnexarOrden);
}
void QPuntoVenta::MuestraCotizacionProducto(zOrdenVenta *pzOrdVenta)
{
sprintf(chrArrArchivoHtmlPuntoVenta,
	chrArrEncabezadoPuntoVenta,
	pzOrdVenta->Importe(0),
	pzOrdVenta->Descripcion(0),
	pzOrdVenta->Cantidad(0),
	pzOrdVenta->Existencia(0),
	pzOrdVenta->ExBodega(0),
	pzOrdVenta->Clave(0),
	pzOrdVenta->Precio(0));
strcat(chrArrArchivoHtmlPuntoVenta,"</table></th></tr><tr><th>Otra Cosa</th></tr></table></html>");
QTBPuntoVenta->setText(chrArrArchivoHtmlPuntoVenta);


}
void QPuntoVenta::IniciaOrden()
{
     zOrdVenta=new zOrdenVenta(0,chrPtrArgumentos[0]);
}
void QPuntoVenta::CotizandoOrden()
{
    if(!zOrdVenta)
    IniciaOrden();

    CotizaOrden();
    MuestraOrdenCotizada(zOrdVenta);
}
void QPuntoVenta::CotizaOrden()
{
zSiscomElectronica lzSiscomE(zSisConexion,"CotizandoProductos4");
      zOrdVenta->AgregaProducto(zProdCotizar); 
      lzSiscomE.CotizaOrden(zOrdVenta,0);
}
void QPuntoVenta::MuestraOrdenCotizada(zOrdenVenta *pzOrdVenta)
{
char lchrArrProductos[16132];
int lintContador;
 sprintf(chrArrArchivoHtmlPuntoVenta,
 	 chrArrEncabezadoPuntoVenta,
	 (*zProdCotizar)["Importe"],
	 (*zProdCotizar)["Descripcion"],
	 (*zProdCotizar)["Cantidad"],
	 (*zProdCotizar)["Existencia"],
	 (*zProdCotizar)["ExiBodega"],
	 (*zProdCotizar)["Clave"],
	 (*zProdCotizar)["Precio"],
	 pzOrdVenta->ImporteOrden());
for(lintContador=0;
    lintContador<pzOrdVenta->ProductosCotizados();
    lintContador++)
{
  sprintf(lchrArrProductos,
   	  "<tr> 				\n\
	       <th>%s</th>			\n\
	       <th colspan=\"12\">%s</th>	\n\
	       <th>%s</th>			\n\
	       <th>%s</th>			\n\
	   </tr>",
	   pzOrdVenta->Cantidad(lintContador),
	   pzOrdVenta->Clave(lintContador),
	   pzOrdVenta->Precio(lintContador),
	   pzOrdVenta->Importe(lintContador));
   strcat(chrArrArchivoHtmlPuntoVenta,lchrArrProductos);
}
strcat(chrArrArchivoHtmlPuntoVenta,"</table></th><th>Otra Cosa</th></tr></table</html>");
QTBPuntoVenta->setText(chrArrArchivoHtmlPuntoVenta);
LogSiscom("(%d) %s",strlen(chrArrArchivoHtmlPuntoVenta),chrArrArchivoHtmlPuntoVenta);
}
