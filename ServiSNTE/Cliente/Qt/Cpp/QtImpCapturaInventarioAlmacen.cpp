#include <QtImpCapturaInventarioAlmacen.h>
#include <QtImpCapturaCantidad.h>
#include <QtImpInventarioEnCurso.h>
#include <QCtrlProveedoresSS.h>
#include <QCtrlProductosSS.h>
#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>

#include <zOperacionesServiSNTE.h>


#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <zInventario.h> 
#include <zProducto.h>
#include <qlineedit.h> 
#include <qcheckbox.h> 
#include <qpushbutton.h>
#include <qtable.h>
#include <qmessagebox.h>

QtImpCapturaInventarioAlmacen::QtImpCapturaInventarioAlmacen(
					 QWidget *pQWParent,
				     const char *pchrPtrName,
				     WFlags pWFlags):
				     CapturaInventarioAlmacen(pQWParent,pchrPtrName),
				     zSisProducto(0)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaVariables();
 ConectaSlots();
 VerificaInventario();
}

void QtImpCapturaInventarioAlmacen::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpCapturaInventarioAlmacen::IniciaVariables()
{
	IniciaControles();
	zSiscomQt3::Foco(QCtrProveedores);

}
void QtImpCapturaInventarioAlmacen::ConectaSlots()
{
connect(QCtrProveedores,
	SIGNAL(SignalProveedor(zSiscomRegistro *)),
	SLOT(SlotProveedor(zSiscomRegistro *)));
connect(QCtrProductos,
	SIGNAL(SignalProducto(zSiscomRegistro *)),
	SLOT(SlotProducto(zSiscomRegistro *)));
connect(QLECantidad,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAAnexar()));
connect(QPBAnexar,
	SIGNAL(clicked()),
	SLOT(SlotAnexar()));
connect(QPBProgramaInventario,
	SIGNAL(clicked()),
	SLOT(SlotProgramarInventario()));
connect(QLECodigoBarras,
	SIGNAL(returnPressed()),
	SLOT(SlotProductoPorCodigoBarras()));
connect(QPBRegistrar,
	SIGNAL(clicked()),
	SLOT(SlotRegistraInventario()));
connect(QTProductos,
        SIGNAL(clicked(int, int, int, const QPoint &)),
        SLOT(SlotCapturaCantidad(int, int, int, const QPoint &)));
}
void QtImpCapturaInventarioAlmacen::SlotRegistraInventario()
{
  RegistraInventario();
  QPBRegistrar->setEnabled(false);
}
void QtImpCapturaInventarioAlmacen::SlotProductoPorCodigoBarras()
{
 	QLECantidad->setEnabled(true);
	zSiscomQt3::Foco(QLECantidad);
    //SlotAnexar();
}
void QtImpCapturaInventarioAlmacen::SlotProgramarInventario()
{
    IniciaCaptura();
    zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"ProgramaInventarioAlmacen");
    lzOpServiSNTE.ProgramaInventarioAlmacen(zInventarioP);
    SiscomRegistroLog2(zInventarioP);
    QPBProgramaInventario->setEnabled(false);
}
void QtImpCapturaInventarioAlmacen::SlotAnexar()
{
  AnexaProductoInventario();
  MuestraProductos();
}
void QtImpCapturaInventarioAlmacen::SlotFocoAAnexar()
{
 QPBAnexar->setEnabled(true);
 zSiscomQt3::Foco(QPBAnexar); 
}
void QtImpCapturaInventarioAlmacen::SlotProducto(zSiscomRegistro *pzSisProducto)
{
      zSisProducto=pzSisProducto;
      QLECantidad->setEnabled(true);
      zSiscomQt3::Foco(QLECantidad);
}
void QtImpCapturaInventarioAlmacen::SlotProveedor(zSiscomRegistro *pzSisProveedor)
{
	zSisProveedor=pzSisProveedor;
	ProductosProveedor();
	QCtrProductos->setEnabled(true);
	zSiscomQt3::Foco(QCtrProductos);
	QCtrProductos->ReIniciaControl();
}
void QtImpCapturaInventarioAlmacen::SlotCapturaCantidad(int pintFila,
                         int pintColumna,
                         int,
                         const QPoint &)
{
    if(pintColumna==3)
    {
        QtImpCapturaCantidad IQICCantidad;
        QString lQStrCantidad;
        if(IQICCantidad.Aceptar()==1)
        {
            IQICCantidad.Cantidad(&lQStrCantidad);
            QTProductos->setText(pintFila,pintColumna,lQStrCantidad);
        }
    }
}
void QtImpCapturaInventarioAlmacen::IniciaControles()
{
	QCtrProveedores->Servidor(zSisConexion);
	QCtrProductos->Servidor(zSisConexion);
	QCtrProveedores->IniciaControl();
}

void QtImpCapturaInventarioAlmacen::ProductosProveedor()
{
  	QCtrProductos->Proveedor(zSisProveedor);
	QCtrProductos->IniciaControl();
}
void QtImpCapturaInventarioAlmacen::IniciaCaptura()
{
 QCtrProveedores->setEnabled(true); 
 QLECodigoBarras->setEnabled(true);
 zInventarioP=new zInventario(0,"0");
 zSiscomQt3::Foco(QCtrProveedores);
}
void QtImpCapturaInventarioAlmacen::Reinicia()
{
    QCtrProveedores->setEnabled(false);
    QCtrProductos->setEnabled(false);
    QLECodigoBarras->setEnabled(false);
    QLECantidad->setEnabled(false);
    QPBProgramaInventario->setEnabled(true);
    QPBAnexar->setEnabled(false);
    QPBRegistrar->setEnabled(false);
    zProductosI.Libera();
    while (QTProductos->numRows())
        QTProductos->removeRow(0);
}
void QtImpCapturaInventarioAlmacen::ProductoPorProveedor()
{
zProducto *lzProducto=new zProducto(zSisProducto);
lzProducto->ParaInventario(zSiscomQt3::Texto(QLECantidad),
			   zSiscomQt3::Texto(QLECodigoBarras));

zProductosI << lzProducto;
zSisProducto=0;
}
void QtImpCapturaInventarioAlmacen::AnexaProductoInventario()
{
   if(zSisProducto)
   {
    ProductoPorProveedor();
    zSiscomQt3::Foco(QCtrProveedores);
   }
   else
   {
    ConsultandoCodigoBarras();
    zSiscomQt3::Foco(QLECodigoBarras);
   }
   if(zProductosI.NNodos()) QPBRegistrar->setEnabled(true);
}
void QtImpCapturaInventarioAlmacen::MuestraProductos()
{
const char *lchrPtrDatos[]={"nombreproducto","modelo","CodigoBarras","Cantidad",0};
if(zProductosI.NNodos())
  zSiscomQt3::LlenaTabla(lchrPtrDatos,
		       &zProductosI,
		       QTProductos);
}
void QtImpCapturaInventarioAlmacen::ConsultandoCodigoBarras()
{
   ConsultaCodigoBarras();
   MuestraProductos();
   QLECodigoBarras->clear();
}
void QtImpCapturaInventarioAlmacen::ConsultaCodigoBarras()
{
    zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"ProductoCodigoBarras");
    zSiscomRegistro *pzProducto = lzOpServiSNTE.ProductoCodigoBarras(zSiscomQt3::Texto(QLECodigoBarras));
    if(pzProducto)
    {
        AgregaPorCodigoBarras(pzProducto);
        SiscomRegistroLog2(zInventarioP);
        SiscomRegistroLog2(pzProducto);
        zOperacionesServiSNTE lzOpServiSNTE2(zSisConexion,"PreRegistraInventarioAlmacen");
        lzOpServiSNTE2.PreRegistraInventarioAlmacen(zInventarioP);
    }
    else 
    {
        LogSiscom("NO coincide el codigo de barras con algun producto");
        QString informacion = "El producto NO se encuentra en la base: ";
        informacion = informacion + QLECodigoBarras->text();
        QMessageBox::information(0,"Aviso del sistema",informacion);
    }
}
void QtImpCapturaInventarioAlmacen::AgregaPorCodigoBarras(zSiscomRegistro *pzSisProducto)
{
zProducto *lzProducto=new zProducto(pzSisProducto);
  lzProducto->ParaInventario(zSiscomQt3::Texto(QLECantidad),
  			     zSiscomQt3::Texto(QLECodigoBarras));
  zProductosI <<  lzProducto;
  zInventarioP->Producto(lzProducto);
}
void QtImpCapturaInventarioAlmacen::RegistraInventario()
{
    zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"RegistraInventarioAlmacen");
    zInventarioP->Productos(&zProductosI);
    zInventarioP->IdMotivoInventario("1");
    lzOpServiSNTE.RegistraInventarioAlmacen(zInventarioP);
    SiscomRegistroLog2(zInventarioP);
    Reinicia();
}

void QtImpCapturaInventarioAlmacen::VerificaInventario()
{
    zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"VerificarInventarioEnCursoAlmacen");
    if((zInventarioEnCurso = lzOpServiSNTE.VerificarInventarioEnCurso())!=0)
    {
        QtImpInventarioEnCurso IQIIEnCurso;
        if(IQIIEnCurso.Aceptar())
        {
            LogSiscom("Se ACEPTA recuperacion de Inventario en curso");
            zInventarioP=new zInventario(
                (const char *)(*zInventarioEnCurso)["idinventario"],"0");
            LogSiscom("IdInventario recuperado: %s",
                zInventarioEnCurso->Campo("idinventario"));
            QPBProgramaInventario->setEnabled(false);
            QCtrProveedores->setEnabled(true);
            QLECodigoBarras->setEnabled(true);
            zSiscomQt3::Foco(QCtrProveedores);
        }
        else
        {
            LogSiscom("Se CANCELA recuperacion de Inventario en curso");
            zOperacionesServiSNTE lzOpServiSNTESig(zSisConexion,"CancelaInventarioAlmacen");
            lzOpServiSNTESig.CancelaCapturaInventario((const char *)zInventarioEnCurso->Campo("idinventario"));
        }
    }
}

void QtImpCapturaInventarioAlmacen::RecuperaInventario()
{
    zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"RecuperaInventarioAlmacen");
    lzOpServiSNTE.RecuperaInventarioAlmacen("2348723492");
}


