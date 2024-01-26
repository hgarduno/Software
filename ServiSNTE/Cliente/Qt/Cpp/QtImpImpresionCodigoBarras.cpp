#include <QtImpImpresionCodigoBarras.h>
#include <QtImpCapturaCantidad.h>

#include <QCtrlProveedoresSS.h>
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

#include <qpushbutton.h>
#include <qlineedit.h>
#include <qpainter.h>
#include <qtable.h>
#include <QBarCode.h>

QtImpImpresionCodigoBarras::QtImpImpresionCodigoBarras(QWidget *pQWParent,
				     const char *pchrPtrName):
				     ImpresionCodigoBarras(pQWParent,pchrPtrName)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaVariables();
 ConectaSlots();

}

void QtImpImpresionCodigoBarras::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpImpresionCodigoBarras::ConectaSlots()
{
	connect(QCtrProveedores,
		SIGNAL(SignalProveedor(zSiscomRegistro *)),
		SLOT(SlotProveedor(zSiscomRegistro *)));
	connect(QLEFechaCompra,
		SIGNAL(returnPressed()),
		SLOT(SlotFechaCompra()));
	connect(QPBTodosProductos,
		SIGNAL(clicked()),
		SLOT(SlotTodosProductos()));
    connect(QPBImprimir,
        SIGNAL(clicked()),
        SLOT(SlotImprimirCodigos()));
    connect(QPBImprimirTodo,
        SIGNAL(clicked()),
        SLOT(SlotImprimirCodigosX8()));
    connect(QPBImpresionTodaHoja,
    	SIGNAL(clicked()),
	    SLOT(SlotImpresionTodaHoja()));
    connect(QTProductos,
    	SIGNAL(clicked(int, int, int, const QPoint &)),
	    SLOT(SlotCapturaCantidad(int, int, int, const QPoint &)));
}
void QtImpImpresionCodigoBarras::SlotImpresionTodaHoja()
{
    ImprimeCodigosSeleccionados();
}
void QtImpImpresionCodigoBarras::SlotTodosProductos()
{
    ConsultandoProductosTodos();
    MuestraProductos();
    QPBImprimir->setEnabled(true);
    QPBImprimirTodo->setEnabled(true);
    QPBImpresionTodaHoja->setEnabled(true);
}
void QtImpImpresionCodigoBarras::SlotImprimirCodigos()
{
    zSiscomRegistros lzSisProdsSeleccionados;
    zSiscomRegistro *lzSisRegistro;
    RegistrosParaImprimir(QTProductos,
                   zSisRegProductos,
                   &lzSisProdsSeleccionados);
    int cCodigos,y;
    char info[100];
    SiscomRegistrosLog(&lzSisProdsSeleccionados);
    printf("\nNo.   Descripción     Código\n");
    for(cCodigos=0,lzSisRegistro=lzSisProdsSeleccionados.Primer();
        cCodigos<lzSisProdsSeleccionados.NNodos();
        cCodigos++,lzSisRegistro=lzSisProdsSeleccionados.Siguiente())
    {
        printf(" #%d, %s -> %s \n",
            cCodigos+1,
            (const char *)lzSisRegistro->Campo("nombreproducto"),
            (const char *)lzSisRegistro->Campo("codigobarras"));
    }
    printer = new QPrinter;
    printer->setMargins(32,18,0,0);
    printf("Margen inzquierdo: %d\n",printer->margins().width() );
    printf("Margen superior: %d\n",printer->margins().height() );
    printer->setPageSize(QPrinter::Letter);
    printer->setResolution(96);
    LogSiscom("Resolución: %d \n",printer->resolution());
    printf("Se mando a imprimir!!\n");
    if ( printer->setup( this ) )
    {
        QPainter p;
        if( !p.begin( printer ) )
        return;
        
        QBarCode *barcode = new QBarCode(0);
        QImage codigo;
        QPixmap im;
        QFont font("Courier",8);
        for(cCodigos=0,y=0,lzSisRegistro=lzSisProdsSeleccionados.Primer();
            cCodigos<lzSisProdsSeleccionados.NNodos();
            cCodigos++,y+=60,lzSisRegistro=lzSisProdsSeleccionados.Siguiente())
        {
            if((cCodigos>=32)&&(cCodigos%32==0))
            {
                p.drawLine ( 385, 0, 385, 1000 );
                printer->newPage();
                y=0;
            }
            codigo = barcode->generaCodeBar128BImprimir((const char *)lzSisRegistro->Campo("codigobarras"),2,25);
            im=codigo;
            strcpy(info,(const char *)lzSisRegistro->Campo("nombreproducto"));
            if(strlen(info)>30) info[30] = '\0';
            strcat(info," - ");
            strcat(info,(const char *)lzSisRegistro->Campo("modelo"));
            strcat(info," - ");
            strcat(info,(const char *)lzSisRegistro->Campo("codigobarras"));
            if(cCodigos%2==0)
            {
                p.drawPixmap(0,y,im);
                p.drawText(10,y+25,info);
                p.drawLine ( 0, y+40, 800, y+40 );
            }
            else
            {
                y-=60;
                p.drawPixmap(395,y,im);
                p.drawText(405,y+25,info);
            }
        }
        p.drawLine ( 385, 0, 385, 1000 );
        p.end();
    }
}
void QtImpImpresionCodigoBarras::SlotImprimirCodigosX8()
{
    int cCodigos,y,muestras;
    zSiscomRegistro *lzSisRegistro;
    char info[100];
    printf("\nNo.   Descripción     Código\n");
    for(cCodigos=0,lzSisRegistro=zSisRegProductos->Primer();
        cCodigos<zSisRegProductos->NNodos();
        cCodigos++,lzSisRegistro=zSisRegProductos->Siguiente())
    {
        printf(" #%d, %s -> %s \n",
            cCodigos+1,
            (const char *)lzSisRegistro->Campo("nombreproducto"),
            (const char *)lzSisRegistro->Campo("codigobarras"));
    }
    printer = new QPrinter;
    printer->setMargins(32,18,0,0);
    printf("Margen inzquierdo: %d\n",printer->margins().width() );
    printf("Margen superior: %d\n",printer->margins().height() );
    printer->setPageSize(QPrinter::Letter);

    printf("Se mando a imprimir!!\n");
    if ( printer->setup( this ) )
    {
        QPainter p;
        if( !p.begin( printer ) )
        return;
        
        QBarCode *barcode = new QBarCode(0);
        QImage codigo;
        QPixmap im;
        QFont font("Courier",8);
        for(cCodigos=0,y=0,lzSisRegistro=zSisRegProductos->Primer();
            cCodigos<zSisRegProductos->NNodos()*8;
            cCodigos++,y+=60,lzSisRegistro=zSisRegProductos->Siguiente())
        {
            for(muestras=0;muestras<8;muestras++,cCodigos++,y+=60)
            {
                if((cCodigos>=32)&&(cCodigos%32==0))
                {
                    p.drawLine ( 385, 0, 385, 1000 );
                    printer->newPage();
                    y=0;
                }
                codigo = barcode->generaCodeBar128BImprimir((const char *)lzSisRegistro->Campo("codigobarras"),2,25);
                im=codigo;
                strcpy(info,(const char *)lzSisRegistro->Campo("nombreproducto"));
                if(strlen(info)>30) info[30] = '\0';
                strcat(info," - ");
                strcat(info,(const char *)lzSisRegistro->Campo("modelo"));
                strcat(info," - ");
                strcat(info,(const char *)lzSisRegistro->Campo("codigobarras"));
                if(cCodigos%2==0)
                {
                    p.drawPixmap(0,y,im);
                    p.drawText(10,y+25,info);
                    p.drawLine ( 0, y+40, 800, y+40 );
                }
                else
                {
                    y-=60;
                    p.drawPixmap(395,y,im);
                    p.drawText(405,y+25,info);
                }
            }
            cCodigos--;
            if(y!=0) y-=60;
        }
        p.drawLine ( 385, 0, 385, 1000 );
        p.end();
    }
}
void QtImpImpresionCodigoBarras::SlotFechaCompra()
{
  ConsultandoProductosFechaCompra();
  MuestraProductos();
}
void QtImpImpresionCodigoBarras::SlotProveedor(zSiscomRegistro *pzSisRegistro)
{
    zSisProveedor=pzSisRegistro;
    ConsultandoProductosProveedor();
    QPBImprimir->setEnabled(true);
    QPBImprimirTodo->setEnabled(true);
    QPBImpresionTodaHoja->setEnabled(true);
}
void QtImpImpresionCodigoBarras::SlotCapturaCantidad(int pintFila,
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
void QtImpImpresionCodigoBarras::IniciaVariables()
{
    IniciaControles();
    QPBImprimir->setEnabled(false);
    QPBImprimirTodo->setEnabled(false);
    QPBImpresionTodaHoja->setEnabled(false);
}
void QtImpImpresionCodigoBarras::IniciaControles()
{
QCtrProveedores->Servidor(zSisConexion);
QCtrProveedores->IniciaControl();
}
void QtImpImpresionCodigoBarras::ConsultaProductosProveedor()
{
zOperacionesServiSNTE lzSisOpProductosSS(zSisConexion,"ProductosCodigoBarras");
zSisRegProductos=lzSisOpProductosSS.ProductosCodigoBarras(zSisProveedor);
}
void QtImpImpresionCodigoBarras::ConsultandoProductosProveedor()
{
ConsultaProductosProveedor();
MuestraProductos();
}

void QtImpImpresionCodigoBarras::ConsultaProductosFechaCompra()
{
zOperacionesServiSNTE lzSisOpProductosSS(zSisConexion,"ProductosCodigoBarrasFechaCompra");
zSisRegProductos=lzSisOpProductosSS.ProductosCodigoBarrasFechaCompra(zSiscomQt3::Texto(QLEFechaCompra));
}
void QtImpImpresionCodigoBarras::ConsultandoProductosFechaCompra()
{
ConsultaProductosFechaCompra();
MuestraProductos();
}

void QtImpImpresionCodigoBarras::ConsultaProductosTodos()
{
    zOperacionesServiSNTE lzSisOpProductosSS(zSisConexion,"ProductosCodigoBarrasTodos");
    zSisRegProductos=lzSisOpProductosSS.ProductosCodigoBarrasTodos();
}

void QtImpImpresionCodigoBarras::ConsultandoProductosTodos()
{
    ConsultaProductosTodos();
}

void QtImpImpresionCodigoBarras::MuestraProductos()
{
    const char *lchrPtrCampos[]={"nombreproducto","modelo","codigobarras",0};
    zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegProductos,QTProductos);
}

void QtImpImpresionCodigoBarras::ImprimeCodigosSeleccionados()
{
    zSiscomRegistros lzSisProdsSeleccionados;
    zSiscomRegistro *lzSisRegistro;
    zSiscomQt3::RegistrosSeleccionados(QTProductos,
				   zSisRegProductos,
				   &lzSisProdsSeleccionados);
    LogSiscom("Se Seleccionaron %d",lzSisProdsSeleccionados.NNodos());
    SiscomRegistrosLog(&lzSisProdsSeleccionados);
    //Impresion de codigos
    int cCodigos,y,cMultiplo;
    char info[100];
    printer = new QPrinter;
    printer->setMargins(32,18,0,0);
    printf("Margen inzquierdo: %d\n",printer->margins().width() );
    printf("Margen superior: %d\n",printer->margins().height() );
    printer->setPageSize(QPrinter::Letter);
    printer->setResolution(96);
    LogSiscom("Resolución: %d \n",printer->resolution());
    printf("Se mando a imprimir!!\n");
    if ( printer->setup( this ) )
    {
        QPainter p;
        if( !p.begin( printer ) )
        return;
        
        QBarCode *barcode = new QBarCode(0);
        QImage codigo;
        QPixmap im;
        QFont font("Courier",8);
        for(cCodigos=0,y=0,lzSisRegistro=lzSisProdsSeleccionados.Primer();
            cCodigos<lzSisProdsSeleccionados.NNodos();
            cCodigos++,y+=60,lzSisRegistro=lzSisProdsSeleccionados.Siguiente())
        {
            codigo = barcode->generaCodeBar128BImprimir((const char *)lzSisRegistro->Campo("codigobarras"),2,25);
            im=codigo;
            strcpy(info,(const char *)lzSisRegistro->Campo("nombreproducto"));
            if(strlen(info)>30) info[30] = '\0';
            strcat(info," - ");
            strcat(info,(const char *)lzSisRegistro->Campo("modelo"));
            strcat(info," - ");
            strcat(info,(const char *)lzSisRegistro->Campo("codigobarras"));
            if(cCodigos>0)
            {
                p.drawLine ( 385, 0, 385, 1000 );
                printer->newPage();
                y=0;
            }
            for(cMultiplo=0;cMultiplo<32;cMultiplo++)
            {
                if(cMultiplo%2==0)
                {
                    p.drawPixmap(0,y,im);
                    p.drawText(10,y+25,info);
                    p.drawLine ( 0, y+40, 800, y+40 );
                }
                else
                {
                    y-=60;
                    p.drawPixmap(395,y,im);
                    p.drawText(405,y+25,info);
                }
                y+=60;
            }
        }
        p.drawLine ( 385, 0, 385, 1000 );
        p.end();
    }
}

void QtImpImpresionCodigoBarras::RegistrosParaImprimir(QTable *pQTDatos,
                        zSiscomRegistros *pzSisRegistros,
                    zSiscomRegistros *pzSisRegsSeleccionados)
{
QString QScantidad;
int lintContador,
    lintNRegistros=pzSisRegistros->NNodos(),
    lintCantidad,
    lintDatos;
for(lintContador=0;
    lintContador<lintNRegistros;
    lintContador++)
{
    QScantidad = pQTDatos->text(lintContador,3);
    lintCantidad = QScantidad.toInt();
    for(lintDatos=0;
        lintDatos<lintCantidad;
        lintDatos++)
    {
        (*pzSisRegsSeleccionados) << (*pzSisRegistros)[lintContador];
    }
}
}

