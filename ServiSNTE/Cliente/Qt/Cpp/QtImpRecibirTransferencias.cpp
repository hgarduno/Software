#include <QtImpRecibirTransferencias.h>
#include <QtImpTransferenciaParcial.h>
#include <zSiscomDesarrollo4.h>
#include <QCtrlTiendasEntrega.h>
#include <QCtrlVendedores.h>
#include <QCtrlCamiones.h>
#include <QCtrlCodigoBarras.h>
#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <zOperacionesServiSNTE.h>
#include <zTransferencia.h>

#include <qpushbutton.h>
#include <qlineedit.h>
#include <qstring.h>
#include <qtable.h>
#include <qtextedit.h>
#include <qmessagebox.h>

QtImpRecibirTransferencias::QtImpRecibirTransferencias(QWidget *pQWParent,
				     const char *pchrPtrName):
				     RecibirTransferencias(pQWParent,pchrPtrName)
{
    Conexion((zSiscomConexion *)gzSiscomConexion);
    IniciaControles();
    IniciaVariables();
    ConectaSlots();
}

void QtImpRecibirTransferencias::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpRecibirTransferencias::ConectaSlots()
{
    connect(QTTransferencias,
        SIGNAL(clicked(int, int, int, const QPoint &)),
        SLOT(SlotMuestraContenidoTransferencia(int, int, int, const QPoint &)));
    connect(QPBRecibir,
        SIGNAL(clicked()),
        SLOT(SlotRecibirTransferencia()));
    connect(QPBParcial,
        SIGNAL(clicked()),
        SLOT(SlotRecibirParcialTransferencia()));
    connect(QPBActualizar,
    	    SIGNAL(clicked()),
	    SLOT(SlotActualizar()));
}
void QtImpRecibirTransferencias::SlotActualizar()
{
MostrarTransferenciasTabla();
}
void QtImpRecibirTransferencias::SlotMuestraContenidoTransferencia(int pintFila,
                         int pintColumna,
                         int,
                         const QPoint &)
{
zSiscomRegistro *lzSisRegTransferencia;
    if(pintFila == -1) return;
    LogSiscom("Se selecciono la Fila:%d Columna:%d Nodos (%d) ",
    		pintFila,
		pintColumna,
		zSisRegTransferencias->NNodos());
    lzSisRegTransferencia=(*zSisRegTransferencias)[pintFila];
    LogSiscom("Transferencia a mostrar: %s",(*lzSisRegTransferencia)["idtransferencia"]);
    zSisRegTransferencia=(*zSisRegTransferencias)[pintFila];
    MostrarDatosTransferencia((const char *)(*lzSisRegTransferencia)["idtransferencia"]);
    QPBRecibir->setEnabled(true);
    QPBParcial->setEnabled(true);
}

void QtImpRecibirTransferencias::SlotRecibirTransferencia()
{
    zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"RecibeTransferencia");
    lzOpeServiSNTE.RecibeTransferencia(zSisRegsTransferenciaSeleccionada);
    Reinicia();  
    SlotActualizar();
}

void QtImpRecibirTransferencias::SlotRecibirParcialTransferencia()
{
    int pintFila;
    pintFila = QTTransferencias->currentRow();
    LogSiscom("Fila seleccionada: %d",pintFila);
    QtImpTransferenciaParcial IQITParcial(0,0,false,false,lzSisRegsProductos);
    if(IQITParcial.Aceptar()==1)
    {
        zOperacionesServiSNTE lzOpeServiSNTETransferencia(zSisConexion,"ActualizaEstadoTransferencia");
        lzOpeServiSNTETransferencia.ActualizaEstadoTransferencia(
                (QTTransferencias->text(pintFila,0)).ascii(),
                "2",
		"");
        Reinicia();    
    }
/*
    zOperacionesServiSNTE lzOpeServiSNTETransferencia(zSisConexion,"ActualizaEstadoTransferencia");
    lzOpeServiSNTETransferencia.ActualizaEstadoTransferencia(
                (QTTransferencias->text(pintFila,0)).ascii(),
                "2");
    lzOpeServiSNTETransferencia=zOperacionesServiSNTE(zSisConexion,"RecibeTransferencia");
    lzOpeServiSNTETransferencia.RecibeTransferencia(
                (QTTransferencias->text(pintFila,0)).ascii()); 
    */
}

void QtImpRecibirTransferencias::IniciaControles()
{

}

void QtImpRecibirTransferencias::IniciaVariables()
{
    MostrarTransferenciasTabla();
}

void QtImpRecibirTransferencias::Reinicia()
{
    MostrarTransferenciasTabla();
    QLETienda->setText((const char *)"");
    QLEResponsable->setText((const char *)"");
    QLEChofer->setText((const char *)"");
    QLECamion->setText((const char *)"");
    QTEObservacionGeneral->setText((const char *)"");
    while (QTDetalleTransferencias->numRows())
        QTDetalleTransferencias->removeRow(0);
    QPBRecibir->setEnabled(false);
    QPBParcial->setEnabled(false);
}

void QtImpRecibirTransferencias::MostrarTransferenciasTabla()
{
    const char *lchrPtrCampos[]={"idtransferencia","fechahora",0};
    zOperacionesServiSNTE lzOpeServiSNTETransferencia(zSisConexion,"ConsultaTransferencias");
    zSisRegTransferencias = lzOpeServiSNTETransferencia.ConsultaTransferencias();
    if(zSisRegTransferencias)
    {
        SiscomRegistrosLog(zSisRegTransferencias);
        if(!((*zSisRegTransferencias->Primer())["EstadoConsulta"]))
            zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegTransferencias,QTTransferencias);
    }
    else
        LogSiscom("NO hay transferencias aun");
}

void QtImpRecibirTransferencias::MostrarDatosTransferencia(const char *pchrPtrTransferencia)
{
    zSiscomRegistro *lzSisRegreso;
    zSiscomRegistro *lzSisRegDetalle;
    zSiscomRegistros *lzSisRegsContenidoTransferencia;
    const char *lchrPtrCampos[]={"nombreproducto","modelo","codigobarras","cantidad","observacion","stock",0};
    zOperacionesServiSNTE lzOpeServiSNTETransferencia(zSisConexion,"ConsultaContenidoTransferencia");
    lzSisRegsContenidoTransferencia= lzOpeServiSNTETransferencia.ConsultaContenidoTransferencia(zSisRegTransferencia);
    if(lzSisRegsContenidoTransferencia)
    {
        SiscomRegistrosLog(lzSisRegsContenidoTransferencia);
        lzSisRegreso = lzSisRegsContenidoTransferencia->Primer();
	SiscomRegistroLog2(lzSisRegreso);
        lzSisRegDetalle=(lzSisRegreso->AsociadosDelCampo("DetalleTransferencia"))->Primer();
	SiscomRegistroLog2(lzSisRegDetalle);
        lzSisRegsProductos=lzSisRegreso->AsociadosDelCampo("ProductosTransferencia");
        SiscomRegistrosLog(lzSisRegsProductos);
        /*lzSisRegreso=zSisRegTransferencias->Primer(); */
        QLETienda->setText((const char *)(*lzSisRegDetalle)["tienda"]);
        QLEResponsable->setText((const char *)(*lzSisRegDetalle)["almacenista"]);
        QLEChofer->setText((const char *)(*lzSisRegDetalle)["chofer"]);
        QLECamion->setText((const char *)(*lzSisRegDetalle)["camion"]);
        QTEObservacionGeneral->setText((const char *)(*lzSisRegDetalle)["observacion"]);
        zSiscomQt3::LlenaTabla(lchrPtrCampos,lzSisRegsProductos,QTDetalleTransferencias);
	zSisRegsTransferenciaSeleccionada=lzSisRegsContenidoTransferencia;
    }
    else
        LogSiscom("NO hay contenido de esta transferencia");
}


