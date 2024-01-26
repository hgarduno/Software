#include <QtImpTransferenciaParcial.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistros.h>
#include <zSiscomCampo.h>

#include <zOperacionesServiSNTE.h>

#include <qlineedit.h> 
#include <qpushbutton.h>
#include <qtable.h>
#include <zSiscomQt3.h>

QtImpTransferenciaParcial::QtImpTransferenciaParcial(
			QWidget *pQWParent,
			const char *pchrPtrName,
			bool pbModal,
			WFlags pWFlags,
            zSiscomRegistros *pzSisRegsProductosTransferencia):
		TransferenciaParcial(pQWParent,pchrPtrName,pbModal,pWFlags),
		intAceptar(0)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 ConectaSlots();
 IniciaVariables(pzSisRegsProductosTransferencia);
 SiscomRegistrosLog(pzSisRegsProductosTransferencia);
 pzSisRegsProdTrans = pzSisRegsProductosTransferencia;
 exec();
}

void QtImpTransferenciaParcial::Conexion(zSiscomConexion *pzSisConexion)
{
    zSisConexion=pzSisConexion;
}

void QtImpTransferenciaParcial::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
    connect(QTProductos,
        SIGNAL(valueChanged(int, int)),
        SLOT(SlotCheckTabla(int, int)));
/*    connect(QTProductos,
        SIGNAL(clicked(int, int, int, const QPoint &)),
        SLOT(SlotContenidosTabla(int, int, int, const QPoint &)));
*/
/*	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(SlotCantidad()));
*/
}

void QtImpTransferenciaParcial::SlotAceptar()
{
	intAceptar=1;
    MandaProductosSeleccionados();
	done(1);
}

void QtImpTransferenciaParcial::SlotCancelar()
{
	intAceptar=0;
	done(1);
}

void QtImpTransferenciaParcial::SlotContenidosTabla(int pintFila,
                         int pintColumna,
                         int,
                         const QPoint &)
{







}

void QtImpTransferenciaParcial::SlotCheckTabla(int pintFila,
                         int pintColumna)
{
    bool valor;
    QTProductos->blockSignals(true);
    LogSiscom("Ha cambiado la Fila: %d",pintFila);
    if(pintColumna == 5)
    {
        valor = ((QCheckTableItem *) QTProductos->item(pintFila,pintColumna))->isChecked();
        if(valor)
        { 
            QTProductos->setItem(pintFila,pintColumna,new QCheckTableItem( QTProductos,"Si"));
            ((QCheckTableItem *) QTProductos->item(pintFila,pintColumna))->setChecked(true);
        }
        else
        { 
            QTProductos->setItem(pintFila,pintColumna,new QCheckTableItem( QTProductos,"No"));
        }
        LogSiscom("Valor: %d",valor);
    }
    QTProductos->blockSignals(false);
}

void QtImpTransferenciaParcial::IniciaVariables(zSiscomRegistros *pzProductos)
{
    int fil,col;
    const char *lchrPtrCampos[]={"nombreproducto","modelo","codigobarras","cantidad",0};
    QTProductos->setColumnWidth(0,300);
    QTProductos->setColumnWidth(5,55);
    QTProductos->setColumnWidth(6,300);
    zSiscomQt3::LlenaTabla(lchrPtrCampos,pzProductos,QTProductos);
    for(fil = 0;fil<QTProductos->numRows();fil++)
    {
        QTProductos->setItem(fil,5,new QCheckTableItem( QTProductos,"Si"));
        ((QCheckTableItem *) QTProductos->item(fil,5))->setChecked(true);
    }
    for(col=0;col<QTProductos->numCols();col++) QTProductos->setColumnReadOnly(col,true);
    QTProductos->setColumnReadOnly(5,false);
    LogSiscom("Se puede editar la columna 5: %d",QTProductos->isColumnReadOnly(5));
}

void QtImpTransferenciaParcial::reject()
{

}

int QtImpTransferenciaParcial::Aceptar()
{
    return intAceptar;
}

void QtImpTransferenciaParcial::MandaProductosSeleccionados()
{
    LogSiscom("");
    zOperacionesServiSNTE lzOpeServiSNTETransferencia(zSisConexion,"RecibeTransferenciaParcial");
    lzOpeServiSNTETransferencia.RecibeTransferenciaParcial(
            ObtenListaProductosSeleccionados(true),
            ObtenListaProductosSeleccionados(false));
    LogSiscom("Analizar que termina correctamente");



}

zSiscomRegistros *QtImpTransferenciaParcial::ObtenListaProductosSeleccionados(bool check)
{
    int fil;
    bool valor;
    zSiscomRegistro *lzSiscomRegistro,
                    *lzSisRegProducto;
    zSiscomRegistros *lzSiscomRegistros = new zSiscomRegistros;
    for(fil = 0,lzSisRegProducto=pzSisRegsProdTrans->Primer();
        fil<QTProductos->numRows();
        fil++,lzSisRegProducto=pzSisRegsProdTrans->Siguiente())
    {
        lzSiscomRegistro = new zSiscomRegistro;
        valor = ((QCheckTableItem *) QTProductos->item(fil,5))->isChecked();
        LogSiscom("Se analiza fila: %d con check = %d",fil,valor);
        if(valor!=check) continue; 
        (*lzSiscomRegistro) <<
            new zSiscomCampo("IdProducto",
                    (const unsigned char *)lzSisRegProducto->Campo("idproducto"))   <<
            new zSiscomCampo("NumProducto",
                    (const unsigned char *)lzSisRegProducto->Campo("numproducto"))   <<
            new zSiscomCampo("NombreProducto",
                    (const unsigned char *)QTProductos->text(fil,0).ascii())   <<
            new zSiscomCampo("Modelo",
                    (const unsigned char *)QTProductos->text(fil,1).ascii())   <<
            new zSiscomCampo("CodigoBarras",
                    (const unsigned char *)QTProductos->text(fil,2).ascii())   <<
            new zSiscomCampo("IdTransferencia",
                    (const unsigned char *)lzSisRegProducto->Campo("idtransferencia"))   <<
            new zSiscomCampo("Cantidad",
                    (const unsigned char *)QTProductos->text(fil,3).ascii());
        (*lzSiscomRegistros) << lzSiscomRegistro;
    }
    if(lzSiscomRegistros->NNodos()) SiscomRegistrosLog(lzSiscomRegistros);
    else LogSiscom("No se han seleccionado productos a recibir.");
    return lzSiscomRegistros;
}

