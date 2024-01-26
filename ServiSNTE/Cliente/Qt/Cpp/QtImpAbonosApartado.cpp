#include <QtImpAbonosApartado.h>
#include <QtImpCapturaAbonoApartado.h>
#include <QtImprimeRecibo.h>
#include <QtImprimeReciboApartado.h>
#include <QtImpCancelarFolioAbono.h>
#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zOperacionesServiSNTE.h>
#include <zImpresionApartado.h>

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
#include <qtable.h>
#include <qmessagebox.h>

QtImpAbonosApartado::QtImpAbonosApartado(QWidget *pQWParent,
				     const char *pchrPtrName):
				     AbonosApartado(pQWParent,pchrPtrName)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaVariables();
 ConectaSlots();

}
void QtImpAbonosApartado::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpAbonosApartado::IniciaVariables()
{
zSiscomQt3::Foco(QLEFolioApartado);
}
void QtImpAbonosApartado::ConectaSlots()
{
	connect(QLEFolioApartado,
		SIGNAL(returnPressed()),
		SLOT(SlotRFC()));
	connect(QTApartados,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionaApartado(int,int,int,const QPoint &)));
	connect(QTAbonos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionaAbono(int,int,int,const QPoint &)));
	connect(QPBCapturaAbono,
		SIGNAL(clicked()),
		SLOT(SlotCapturaAbono()));
	connect(QPBCancelarAbono,
		SIGNAL(clicked()),
		SLOT(SlotCancelaAbono()));
	connect(QPBCancelarApartado,
		SIGNAL(clicked()),
		SLOT(SlotCancelaApartado()));
	connect(QPBImprimir,
		SIGNAL(clicked()),
		SLOT(SlotImprimeRecibo()));
/*	connect(QPBCancelarFolioAbono,
		SIGNAL(clicked()),
		SLOT(SlotCancelarFolioAbono()));
*/
}
void QtImpAbonosApartado::SlotCancelarFolioAbono()
{
  	CancelarFolioAbono();
}
void QtImpAbonosApartado::SlotImprimeRecibo()
{
  	ImprimeReciboApartado(); 
}
void QtImpAbonosApartado::SlotCapturaAbono()
{
    RegistrandoAbono();
    ConsultandoApartados();
    ConsultaAbonos();
    QPBCapturaAbono->setEnabled(false);
}
void QtImpAbonosApartado::SlotCancelaAbono()
{
    CancelaAbono();
    ConsultaAbonos();
    ConsultandoApartados();
    QPBCapturaAbono->setEnabled(false);
    QPBCancelarAbono->setEnabled(false);
    QPBCancelarApartado->setEnabled(false);
}
void QtImpAbonosApartado::SlotCancelaApartado()
{
    CancelaApartado();
}
void QtImpAbonosApartado::SlotSeleccionaApartado(int pintNFila,
						 int,
						 int,
						 const QPoint &)
{
    if(pintNFila>=0)
    {
        QTApartados->selectRow(pintNFila);
        zSisRegVenta=(*zSisRegsApartados)[pintNFila];
	QPBCapturaAbono->setEnabled(true);
        QPBCancelarAbono->setEnabled(false);
        QPBCancelarApartado->setEnabled(true);
        ConsultaAbonos();
    }

}
void QtImpAbonosApartado::SlotRFC()
{
  ConsultandoApartados();
}
void QtImpAbonosApartado::SlotSeleccionaAbono(int pintNFila,
						 int,
						 int,
						 const QPoint &)
{
    if(pintNFila>=0)
    {
        QTAbonos->selectRow(pintNFila);
        zSisRegAbono=(*zSisRegsAbonos)[pintNFila];
        QPBCancelarAbono->setEnabled(true);
    }
}
int QtImpAbonosApartado::ConsultaApartados()
{
char *lchrPtrFechaHoy;
int lintRegreso;
zOperacionesServiSNTE lzOpServiSNTEApartados(zSisConexion,"ApartadosCliente");
lintRegreso=lzOpServiSNTEApartados.ApartadosCliente(zSiscomQt3::Texto(QLEFolioApartado),
					&zSisRegTienda,
					&zSisRegCliente,
					&zSisRegsApartados,
					&lchrPtrFechaHoy);
zRecibo.Fecha(lchrPtrFechaHoy);
return lintRegreso;
}
void QtImpAbonosApartado::MuestraApartados()
{
    const char *lchrArrCampos[]={"fecha","folio","idventa","total","porpagar","abonado",0};
    LogSiscom("Nodos: %d",zSisRegsApartados->NNodos());
    if(zSisRegsApartados->NNodos()>0)
    {
        SiscomRegistrosLog(zSisRegsApartados);
        zSiscomQt3::LlenaTabla(lchrArrCampos,zSisRegsApartados,QTApartados);
    }
}
void QtImpAbonosApartado::ConsultandoApartados()
{
    int lintRegreso;
    if((lintRegreso=ConsultaApartados())==2)
    {
        MuestraApartados();
        MuestraCliente();
 	SiscomRegistroLog2(zSisRegTienda);
    }
    else
    {
    	if(lintRegreso==-1)
            QMessageBox::information(this,"Aviso Sistema","No Se Encontro Una Entrada en la tabla Tienda");
        if(lintRegreso==1)
            QMessageBox::information(this,"Aviso Sistema","El cliente no tiene apartados");
        if(!lintRegreso)
            QMessageBox::information(this,"Aviso Sistema","No se encontraron datos del cliente o no tiene apartados");
        LogSiscom("El regreso:%d",lintRegreso);
}
}
void QtImpAbonosApartado::MuestraCliente()
{
    if(zSisRegCliente)
    QLECliente->setText(QString((const char *)(*zSisRegCliente)["nombre"]) +
 		     " "						+
		     (const char *)(*zSisRegCliente)["apaterno"]	+
		     " "						+
		     (const char *)(*zSisRegCliente)["amaterno"]);
}
int QtImpAbonosApartado::CapturaAbono()
{
QtImpCapturaAbonoApartado lQtCapAbonoApartado(zSisConexion);
    if(lQtCapAbonoApartado.Aceptar())
    {
	lQtCapAbonoApartado.Cantidad(&zRecibo);
	return 1;
    }
    else
    return 0;
}
void QtImpAbonosApartado::RegistraAbono()
{
    zOperacionesServiSNTE lzOpServRegAbono(zSisConexion,"AbonoAApartado");
    lzOpServRegAbono.AbonoAApartado(zSisRegVenta,&zRecibo);
}
void QtImpAbonosApartado::RegistrandoAbono()
{
int lintCapturoAbono;
if((lintCapturoAbono=CapturaAbono()))
RegistraAbono();
}
void QtImpAbonosApartado::ImprimeReciboApartado()
{
QtImprimeReciboApartado lQtImpRecApartado(zSisConexion);
zImpresionApartado lzImpApartado;
lzImpApartado.Cliente(zSisRegCliente);
lzImpApartado.Tienda(zSisRegTienda);
lzImpApartado.Venta(zSisRegVenta);
lzImpApartado.Recibo(&zRecibo);
lQtImpRecApartado.ImpresionApartado(&lzImpApartado);
lQtImpRecApartado.MargenX(23);
lQtImpRecApartado.MargenY(5);
lQtImpRecApartado.Imprime();
}
void QtImpAbonosApartado::ConsultaAbonos()
{
    const char *lchrPtrCampos[]={"fecha","monto",0};
    zOperacionesServiSNTE lzOpServConAbonos(zSisConexion,"ConsultaAbonosVenta");
    zSisRegsAbonos = lzOpServConAbonos.ConsultaAbonosVenta((const char *)(*zSisRegVenta)["idventa"]);
    zSiscomQt3::LimpiaTabla(QTAbonos);
    if(zSisRegsAbonos)
    {
        SiscomRegistrosLog(zSisRegsAbonos);
        if(!((*zSisRegsAbonos->Primer())["EstadoConsulta"]))
            zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegsAbonos,QTAbonos);
    }
    else
        LogSiscom("NO hay registros");

}

void QtImpAbonosApartado::CancelaAbono()
{
    zOperacionesServiSNTE lzOpServRegAbono(zSisConexion,"CancelaAApartado");
    lzOpServRegAbono.CancelaAApartado(zSisRegAbono);
}

void QtImpAbonosApartado::CancelaApartado()
{
    zOperacionesServiSNTE lzOpServRegAbono(zSisConexion,"CancelaApartado");
    lzOpServRegAbono.CancelaApartado(zSisRegVenta);
    ConsultaApartados();
}

void QtImpAbonosApartado::ValidaLiquidacionApartado()
{
    zOperacionesServiSNTE lzOpServRegAbono(zSisConexion,"ValidaLiquidacionApartado");
    lzOpServRegAbono.ValidaLiquidacionApartado(zSisRegVenta);
}

void QtImpAbonosApartado::CancelarFolioAbono()
{
//QtImpCancelarFolioAbono lQtImpCancelarFA();
//QLEFolioApartado->setText();
}
