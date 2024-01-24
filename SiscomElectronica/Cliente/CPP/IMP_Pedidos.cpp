#include <IMP_Pedidos.h>
#include <IMP_ClientePedido.h>

#include <QCtrlProductosSE.h>

#include <zSiscomElectronica.h>
#include <zProductoCotizar.h>
#include <zClienteSiscom.h>
#include <zTelefono.h>
#include <zDireccion.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>


#include <qtextedit.h> 
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qpushbutton.h>
#include <qtable.h>
QPedidos *InstanciaPedidos(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPedidos((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPedidos::QPedidos(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Pedidos(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				zOrdVenta(0),
				intIdConsecutivo(0)

{
IniciaVariables();
ConectaSlots();
}

QPedidos::~QPedidos()
{

}

void QPedidos::ConectaSlots()
{
connect(QCtrProductos,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotSeleccionoProducto(zSiscomRegistro *)));
connect(QLECantidad,SIGNAL(returnPressed()),SLOT(SlotFocoAProducto()));
connect(QPBAnexarOrden,SIGNAL(clicked()),SLOT(SlotAnexarOrden()));	
connect(QPBDatosCliente,SIGNAL(clicked()),SLOT(SlotDatosCliente()));

}
void QPedidos::SlotDatosCliente()
{
{
  MuestraDatosCliente();
}
}
void QPedidos::SlotAnexarOrden()
{
  CotizandoOrden();
  zSiscomQt3::Foco(QLECantidad);

}
void QPedidos::SlotFocoAProducto()
{
  zSiscomQt3::Foco(QCtrProductos);
}
void QPedidos::SlotSeleccionoProducto(zSiscomRegistro *pzSisRegProducto)
{
	zSisRegProducto=pzSisRegProducto;
	CotizandoProducto(zSisRegProducto);
	zSiscomQt3::Foco(QPBAnexarOrden);
}
void QPedidos::IniciaVariables()
{
QCtrProductos->Servidor(zSisConexion);
QCtrProductos->IniciaControl();
zSiscomQt3::Foco(QLECantidad);
}
void QPedidos::CotizandoOrden()
{
    if(!zOrdVenta)
    IniciaOrden();
    CotizaOrden();
    MuestraOrdenCotizada(zOrdVenta);
}

void QPedidos::CotizandoProducto(zSiscomRegistro *pzSisRegProducto)
{
zSiscomElectronica lzSiscomE(zSisConexion,"CotizandoProductos4");
zOrdCotProducto=new zOrdenVenta(0,chrPtrArgumentos[0]);
zProductoCotizar *lzProdCotizar=new zProductoCotizar(zSiscomQt3::Texto(QLECantidad),
						     0,
						     pzSisRegProducto);
	lzProdCotizar->IdConsecutivo(intIdConsecutivo);
	zOrdCotProducto->AgregaProducto(lzProdCotizar);
	lzSiscomE.CotizaOrden(zOrdCotProducto,&zSisRegEdoCotizacion);
	MuestraCotizacionProducto(zOrdCotProducto);
	zProdCotizar=zOrdCotProducto->Producto(0);
	delete zOrdCotProducto;
}
void QPedidos::MuestraDefinicionProducto(zProductoCotizar *pzProdCotizar)
{
zSiscomRegistro *lzSisRegProducto;
zSiscomRegistros *lzSisRegsProducto;
int lintFilas=QTOrden->numRows();
 lzSisRegsProducto=pzProdCotizar->DefinicionProducto();
 QTOrden->setNumRows(QTOrden->numRows()+lzSisRegsProducto->NNodos());
/*
 QTOrden->setText(lintFilas-1,0,pzProdCotizar->Cantidad());
 QTOrden->setText(lintFilas-1,1,pzProdCotizar->Clave());
 QTOrden->setText(lintFilas-1,2,pzProdCotizar->Precio());
 QTOrden->setText(lintFilas-1,3,pzProdCotizar->Importe());
*/
 for(lzSisRegProducto=lzSisRegsProducto->Primer();
     lzSisRegProducto;
     lzSisRegProducto=lzSisRegsProducto->Siguiente())
  {
	QTOrden->setText(lintFilas,0,(const char *)(*lzSisRegProducto)["cantidad"]);
	QTOrden->setText(lintFilas,1,(const char *)(*lzSisRegProducto)["cveproducto"]);
	lintFilas++;
  }
}
void QPedidos::MuestraProducto(int pintNProducto,zProductoCotizar *pzProdCotizar)
{
	QTOrden->setText(pintNProducto,0,pzProdCotizar->Cantidad());
	QTOrden->setText(pintNProducto,1,pzProdCotizar->Clave());
	QTOrden->setText(pintNProducto,2,pzProdCotizar->Precio());
	QTOrden->setText(pintNProducto,3,pzProdCotizar->Importe());
}
int QPedidos::NoEsProducto(zProductoCotizar *pzProdCotizar)
{
 if(pzProdCotizar->EsElValorCampo("TipoProducto","2"))
 return 0;
 else
 return 1;
}
void QPedidos::MuestraProductos(zOrdenVenta *pzOrdenVenta)
{
int lintProductos=0;
    QTOrden->setNumRows(pzOrdenVenta->ProductosCotizados());  
	while(lintProductos<pzOrdenVenta->ProductosCotizados())
	{
		LogSiscom("%s %s %s %s",
			  pzOrdenVenta->Clave(lintProductos),
			  pzOrdenVenta->Precio(lintProductos),
			  pzOrdenVenta->Cantidad(lintProductos),
			  pzOrdenVenta->Importe(lintProductos));
	    if(NoEsProducto(pzOrdenVenta->Producto(lintProductos)))
	    {
		MuestraProducto(lintProductos,
				pzOrdenVenta->Producto(lintProductos));
	     }
	   lintProductos++;
	}
}
void QPedidos::MuestraNoProductos(zOrdenVenta *pzOrdenVenta)
{
int lintContador;
	for(lintContador=0;
	    lintContador<pzOrdenVenta->ProductosCotizados();
	    lintContador++)
        if(!NoEsProducto(pzOrdenVenta->Producto(lintContador)))
	MuestraDefinicionProducto(pzOrdenVenta->Producto(lintContador));
}
void QPedidos::MuestraOrdenCotizada(zOrdenVenta *pzOrdenVenta)
{
int lintContador;
  QTOrden->setNumRows(0);
  QLCDNumTotalOrden->display(pzOrdenVenta->ImporteOrden());
  MuestraProductos(pzOrdenVenta);
  MuestraNoProductos(pzOrdenVenta);
  zSiscomQt3::AjustaColumnasTabla(QTOrden);
}
void QPedidos::MuestraCotizacionProducto(zOrdenVenta *pzOrdVenta)
{
  QLEExistencia->setText(pzOrdVenta->Existencia(0));
  QLEExiBodega->setText(pzOrdVenta->ExBodega(0));
  QLCDNumPrecio->display(pzOrdVenta->Importe(0));
  QTEDescripcion->setText(pzOrdVenta->Descripcion(0));
}
void QPedidos::CotizaOrden()
{
zSiscomElectronica lzSiscomE(zSisConexion,"CotizandoProductos4");
      zOrdVenta->AgregaProducto(zProdCotizar); 
      intIdConsecutivo++;
      lzSiscomE.CotizaOrden(zOrdVenta,&zSisRegEdoCotizacion);
}

void QPedidos::IniciaOrden()
{
     zOrdVenta=new zOrdenVenta(0,chrPtrArgumentos[0]);
}
void QPedidos::MuestraDatosCliente()
{
 QTECliente->setText(QString("Nombre del Cliente\n")			+
 			     zSisCliSiscom->Nombre()  			+ 
 			     " " 					+
			     zSisCliSiscom->APaterno()			+
			     " "					+
			     zSisCliSiscom->AMaterno()  		+
			     "\n"					+
			     "Escuela\n" 				+
			     " "					+
			     zSisCliSiscom->Escuela()			+
			     "\n"					+
			     "Datos Comunicacion"			+
			     "\n"					+
			     "Celular:"                 		+
			     zSisCliSiscom->Celular()->Telefono()	+
			     " "					+
			     "Direccion Entrega"			+
			     "\n"					+
			     zSisCliSiscom->Direccion()->Calle() 	+
			     " " 					+
			     zSisCliSiscom->Direccion()->Numero()	+
			     " "					+
			     zSisCliSiscom->Direccion()->Colonia()	+
			     " " 					+
			     zSisCliSiscom->Direccion()->Delegacion()	+
			     " "					+
			     zSisCliSiscom->Direccion()->Estado()	+
			     " "					+
			     zSisCliSiscom->Direccion()->CP()		+
			     "\n"					+
			     "Referencias"				+
			     "\n"					+
			     zSisCliSiscom->Direccion()->Referencias());
}
