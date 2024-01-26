#include <QCtrlCodigoBarras.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <zSiscomCampo.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qmessagebox.h>

QCtrlCodigoBarras::QCtrlCodigoBarras( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegCodigoBarras(0),
    chrPtrEsStock("0")
{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlCodigoBarras::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QLECodigoBarras = new QLineEdit(this);
    	QHBLayout->addWidget(QLECodigoBarras);
    	zSisRegCodigoBarrasS = new zSiscomRegistros;
}
void QCtrlCodigoBarras::IniciaControl()
{
	//ConsultaCodigoBarras();
}
void QCtrlCodigoBarras::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlCodigoBarras::ConsultaCodigoBarras()
{
    zOperacionesServiSNTE lzSisOpCodigoBarras(zSisConexion,"ProductoCodigoBarras");
    if((zSisRegCodigoBarras=lzSisOpCodigoBarras.ProductoCodigoBarras(QLECodigoBarras->text())))
    {
        SiscomRegistroLog2(zSisRegCodigoBarras);
	AgregandoStock(zSisRegCodigoBarras);	
	AgregandoCantidad(zSisRegCodigoBarras,"0");
        (*zSisRegCodigoBarrasS) << zSisRegCodigoBarras;
        SiscomRegistrosLog(zSisRegCodigoBarrasS);
        
    }
    else
    {
        LogSiscom("NO coincide el codigo de barras con algun producto");
        QString informacion = "El producto NO se encuentra en la base: ";
        informacion = informacion + QLECodigoBarras->text();
        QMessageBox::information(0,"Aviso del sistema",informacion);
    }
}
zSiscomRegistros *QCtrlCodigoBarras::ConsultaProductosSumados()
{
    if(zSisRegCodigoBarrasS->NNodos())
    {
        LogSiscom("La lista zSisRegCodigoBarrasS SI tiene contenido");
	LogSiscom("Es Stock:%s",chrPtrEsStock);
        zOperacionesServiSNTE lzSisOpCodigoBarras(zSisConexion,"SumaProductosCodigoBarras");
        zSisRegCodigoBarrasSRespuesta=lzSisOpCodigoBarras.SumaProductosCodigoBarras(zSisRegCodigoBarrasS);
        LogSiscom("Nodos recibidos: %d",zSisRegCodigoBarrasSRespuesta->NNodos());
        if(zSisRegCodigoBarrasSRespuesta->NNodos())
        {
            SiscomRegistrosLog(zSisRegCodigoBarrasSRespuesta);
            LogSiscom("Se recibieron productos contabilizados:");
            emit SignalCodigoBarrasContabilizados(zSisRegCodigoBarrasSRespuesta);
        }
    }
    else
    {
        LogSiscom("La lista zSisRegCodigoBarrasS esta vacía");
    }
}
zSiscomRegistros *QCtrlCodigoBarras::ProductosSumados()
{
    return zSisRegCodigoBarrasSRespuesta;
}

void QCtrlCodigoBarras::ConectaSlots()
{
connect(QLECodigoBarras,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLECodigoBarras,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCodigoBarras(const QString &)));
}
void QCtrlCodigoBarras::SlotCapturandoCodigoBarras(const QString &pQStrCodigoBarras)
{
    if(pQStrCodigoBarras.isEmpty())
	emit SignalCodigoBarrasVacia();
}
void QCtrlCodigoBarras::SlotCapturo()
{
ConsultaCodigoBarras();
ConsultaProductosSumados();
if(zSisRegCodigoBarras)
{
emit SignalCodigoBarras(zSisRegCodigoBarras);
zSisRegCodigoBarras=0;
}
/*
else
{
LogSiscom("La CodigoBarras No existe, se registra");
emit SignalNuevoCodigoBarras(QLECodigoBarras->text());
}*/
    setFocus();
}

void QCtrlCodigoBarras::setFocus()
{
   zSiscomQt3::Foco(QLECodigoBarras); 
   QLECodigoBarras->selectAll();
}
const char *QCtrlCodigoBarras::CodigoBarras()
{
return  (const char *)QLECodigoBarras->text();
}

void QCtrlCodigoBarras::ReIniciaControl()
{
   zSisRegCodigoBarras->Libera();
   IniciaControl();
}

void QCtrlCodigoBarras::ActualizaCantidadProducto()
{
    //Eliminar producto si es igual a cero y/o modificar cantidad.
    
}


void QCtrlCodigoBarras::CodigoBarras(const QString &pQStrCodigoBarras)
{
	QLECodigoBarras->setText(pQStrCodigoBarras);	
}
void QCtrlCodigoBarras::EsStock(const char *pchrPtrEsStock)
{
	chrPtrEsStock=pchrPtrEsStock;
}
void QCtrlCodigoBarras::AgregandoStock(zSiscomRegistro *pzSisRegProducto)
{
	(*pzSisRegProducto) << new zSiscomCampo("EsStock",(const unsigned char *)chrPtrEsStock);
}

void QCtrlCodigoBarras::AgregandoCantidad(zSiscomRegistro *pzSisRegProducto,
					 const char *pchrPtrCantidad)
{
	(*pzSisRegProducto) << new zSiscomCampo("Cantidad",(const unsigned char *)pchrPtrCantidad);
}
void QCtrlCodigoBarras::Cantidad(int pintNProducto,const char *pchrPtrCantidad)
{
zSiscomRegistro *lzSisRegProducto=(*zSisRegCodigoBarrasS)[pintNProducto];
lzSisRegProducto->ActualizaCampo("Cantidad",(const unsigned char *)pchrPtrCantidad);
}
