#include <QtCorteCajaImp.h>


#include <zSiscomDesarrollo4.h>
#include <zDenominacion.h>
#include <zDenominaciones.h>
#include <zCajas.h>
#include <zCaja.h>
#include <zZonaGasto.h>
#include <zEncabezadoCaja.h>
#include <zGasto.h>
#include <zCeldaPagoTarjeta.h>
#include <zCeldaImporteGastos.h>
QtCorteCajaImp::QtCorteCajaImp(QWidget *pQWParent,
			      const char *pchrPtrName):
			      QtCorteCaja(pQWParent,pchrPtrName)
{
ConectaSlots();
}

void QtCorteCajaImp::ConectaSlots()
{
connect(this,SIGNAL(valueChanged(int,int)),SLOT(SlotCaptura(int,int)));
}
void QtCorteCajaImp::SlotCaptura(int pintFila,int pintColumna)
{
   ActualizandoDenominacion(pintFila,pintColumna); 
   AgregandoGasto(pintFila,pintColumna);
   ActualizandoImporteGasto(pintFila,pintColumna);
   ActualizandoPagoTarjeta(pintFila,pintColumna);
}
void QtCorteCajaImp::ActualizandoDenominacion(int pintFila,int pintColumna)
{
    if((zDenoD=Denominacion(pintFila,pintColumna)))
    {
    ActualizaCantidad(pintFila,pintColumna,zDenoD);
    emit SignalCapturoCantidadDenominacion();
    }
}
zDenominacion *QtCorteCajaImp::Denominacion(int pintFila,int pintColumna)
{
zDenominacion *lzDenoD=0;

 if((lzDenoD=Cajas()->Denominacion(pintFila,pintColumna)))
 return lzDenoD;
 return 0;
}
void QtCorteCajaImp::ActualizaCantidad(int pintFila,
				       int pintColumna,
				       zDenominacion *pzDenoD)
{
  pzDenoD->Cantidad((const char *)text(pintFila,pintColumna));
}
void QtCorteCajaImp::ActualizandoGui()
{
   ActualizaGui();
   ActualizaTotalGastos();
}
void QtCorteCajaImp::ActualizaGui()
{
zCaja *lzCaja;
for(lzCaja=(zCaja *)Cajas()->Primer();lzCaja;lzCaja=(zCaja *)Cajas()->Siguiente())
{
  ActualizaDineroGui(lzCaja->Dinero());
  ActualizaTotalGui(lzCaja);
}
}
void QtCorteCajaImp::ActualizaDineroGui(zDenominaciones *pzDenoS)
{
zDenominacion *lzDeno;
for(lzDeno=(zDenominacion *)pzDenoS->Primer();
    lzDeno;
    lzDeno=(zDenominacion *)pzDenoS->Siguiente())
setText(lzDeno->Fila(),lzDeno->Columna()+2,lzDeno->Importe());
}
void QtCorteCajaImp::ActualizaTotalGui(zCaja *pzCaja)
{
zEncabezadoCaja *lzEncabezado; 
if((lzEncabezado=pzCaja->EncabezadoTotal()))
 setText(lzEncabezado->Fila(),lzEncabezado->Columna(),pzCaja->Total());
}
void QtCorteCajaImp::AgregaGasto(int pintFila,int pintColumna)
{
    QtCorteCaja::AgregaGasto(pintFila,pintColumna); 
    emit SignalAgregaGasto(pintFila,pintColumna);

}
void QtCorteCajaImp::AgregandoGasto(int pintFila,int pintColumna)
{
zZonaGasto lzZoGasto(pintFila,pintColumna);
    if(*ZonaGasto()==lzZoGasto)
    AgregaGasto(pintFila,pintColumna);
}
void QtCorteCajaImp::ActualizaImporteGasto(int pintFila,
					  int pintColumna,
					  zGasto *pzGasto)
{
pzGasto->Importe((const char *)text(pintFila,pintColumna));
}
void QtCorteCajaImp::ActualizandoImporteGasto(int pintFila,int pintColumna)
{
zGasto *lzGasto;
zCaja *lzCaPrincipal=(zCaja *)(*Cajas())[0];
if((lzGasto=lzCaPrincipal->Gasto(pintFila,pintColumna)))
{
    ActualizaImporteGasto(pintFila,pintColumna,lzGasto);
    emit SignalActualizaImporteGasto();
}
}
void QtCorteCajaImp::ActualizandoPagoTarjeta(int pintFila,int pintColumna)
{
zCeldaPagoTarjeta lzCePaTarjeta(pintFila,pintColumna);
zCaja *lzCaPrincipal=(zCaja *)(*Cajas())[0];
   if((*(CeldaPagoTarjeta()))==lzCePaTarjeta)
   {
    lzCaPrincipal->PagoTarjeta((const char *)text(pintFila,pintColumna));
    emit SignalPagoTarjeta();
   }
}
void QtCorteCajaImp::ActualizaTotalGastos()
{
   setText(CeldaImporteGastos()->Fila(),
           CeldaImporteGastos()->Columna(),
           Cajas()->Principal()->TotalGastos()); 
}
