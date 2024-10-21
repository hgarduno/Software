#include <QtCorteCaja.h>
#include <QtImpCaja.h>
#include <zSiscomTableItem.h>
#include <zSiscomQt3.h>
#include <zSiscomDesarrollo4.h>

#include <zFiCo.h>
#include <zZonaGasto.h>
#include <zDenominacion.h> 
#include <zCaja.h>
#include <zGasto.h>
#include <zCeldaPagoTarjeta.h>
#include <zCeldaImporteGastos.h>
#include <zCeldaImporteTransferencias.h>
#include <zCeldaImporteEfectivoCaja.h>
#include <zCeldaCambioDiaAnterior.h>
#include <zCeldaVentasTotales.h>
#include <zCeldaCalculandoCorte.h>
#include <zCeldaCorteTotal.h>


#include <zCajas.h>
#include <zDenominaciones.h>
#include <zEncabezadoCaja.h>
#include <zEncabezadosCaja.h>
#include <zCajas.h>
#include <zGastos.h>


QtCorteCaja::QtCorteCaja(QWidget *pQWParent,
			  const char *pchrPtrName):
			 QTable(pQWParent,pchrPtrName)
{
 setShowGrid(false);
 zCajasExp=new zCajas;
}
void QtCorteCaja::IniciaControl(int pintFila,int pintColumna)
{ 

 EncabezadosGastos(pintFila,pintColumna); 
 EncabezadoPagoTarjeta(pintFila,pintColumna);
 EncabezadoImporteGastos(pintFila,pintColumna);
 EncabezadoTransferencias(pintFila,pintColumna);
 EncabezadoVentasEfectivo(pintFila,pintColumna);
 EncabezadoCambioDiaAnterior(pintFila,pintColumna);
 EncabezadoVentasTotales(pintFila,pintColumna);
 EncabezadoCalculandoCorte(pintFila,pintColumna);
 EncabezadoCorteTotal(pintFila,pintColumna);

 FormandoCajaCorte(pintFila,pintColumna);
 FormandoEncabezadosCorte();

 PagoTarjeta(pintFila,pintColumna);
 ImporteTransferencias(pintFila,pintColumna);
 ImporteEfectivoCaja(pintFila,pintColumna);
 CambioDiaAnterior(pintFila,pintColumna);
 VentasTotales(pintFila,pintColumna);
 CalculandoCorte(pintFila,pintColumna);
 CorteTotal(pintFila,pintColumna);


 zSiscomQt3::AjustaColumnasTabla(this);
}
void QtCorteCaja::FormandoCajaCorte(int pintFila,int pintColumna)
{
 (*zCajasExp) 							<< 
 FormaCajaDinero(pintFila,pintColumna,"Caja","Principal")	<<
 FormaCajaDinero(pintFila,pintColumna+4,"Cambio en la caja","Cambio");
}
zCaja *QtCorteCaja::FormaCajaDinero(int pintFila,
				    int pintColumna,
				   const char *pchrPtrCaja,
				   const char *pchrPtrNombre)
{
zCaja *lzCaja=new zCaja(pchrPtrCaja,pchrPtrNombre);
CeldaColor(pintFila,pintColumna+1,"gray",pchrPtrCaja);
EncabezadosDinero(pintFila,pintColumna,lzCaja);
LlenaCeldasDinero(pintFila,pintColumna,lzCaja);
FormaEncabezadosCaja(lzCaja);
FormaDenominacionesCaja(lzCaja);
return lzCaja;
}
void QtCorteCaja::AgregaCaja(const char *pchrPtrCaja,
			     int pintFila,
			     int pintColumna)
{
}

void QtCorteCaja::EncabezadosDinero(int pintFila,
				    int pintColumna,
				    zCaja *pzCajaDinero)
{
zEncabezadosCaja *lzEncaSCajaDinero=new zEncabezadosCaja;
(*lzEncaSCajaDinero) 							<< 
new zEncabezadoCaja(pintFila+1,pintColumna+1,0,"gray","Billetes") 	<<
new zEncabezadoCaja(pintFila+1,pintColumna+2,0,"gray","Cantidad")	<< 
new zEncabezadoCaja(pintFila+1,pintColumna+3,0,"gray","Importe")	<< 
new zEncabezadoCaja(pintFila+13,pintColumna+2,0,"gray","Total")		<<
new zEncabezadoCaja(pintFila+13,pintColumna+3,"Total","gray","");
pzCajaDinero->EncabezadosCaja(lzEncaSCajaDinero);
}
void QtCorteCaja::LlenaCeldasDinero(int pintFila,
				    int pintColumna,
				    zCaja *pzCaja)
{
zDenominaciones *lzDenoSDinero=new zDenominaciones;
 (*lzDenoSDinero) 							<<
 new zDenominacion(pintFila+2,pintColumna+1,"1000","0","0","gray") 	<<
 new zDenominacion(pintFila+3,pintColumna+1,"500","0","0","white")	<<
 new zDenominacion(pintFila+4,pintColumna+1,"200","0","0","gray")	<<
 new zDenominacion(pintFila+5,pintColumna+1,"100","0","0","white")	<<
 new zDenominacion(pintFila+6,pintColumna+1,"50","0","0","gray")	<<
 new zDenominacion(pintFila+7,pintColumna+1,"20","0","0","white")	<<
 new zDenominacion(pintFila+8,pintColumna+1,"10","0","0","gray") 	<<
 new zDenominacion(pintFila+9,pintColumna+1,"5","0","0","white") 	<<
 new zDenominacion(pintFila+10,pintColumna+1,"2","0","0","gray") 	<<
 new zDenominacion(pintFila+11,pintColumna+1,"1","0","0","white") 	<<
 new zDenominacion(pintFila+12,pintColumna+1,"0.50","0","0","gray");
 pzCaja->Dinero(lzDenoSDinero);
}
void QtCorteCaja::FormaRegistroDenominacion(zDenominacion *pzDeno)
{
   CeldaColor(pzDeno->Fila(),pzDeno->Columna(),pzDeno->Color(),pzDeno->Valor());
   CeldaColor(pzDeno->Fila(),pzDeno->Columna()+1,pzDeno->Color(),pzDeno->Cantidad());
   CeldaColor(pzDeno->Fila(),pzDeno->Columna()+2,pzDeno->Color(),pzDeno->Importe());
}
void QtCorteCaja::FormaRegistroEncabezadoCaja(zEncabezadoCaja *pzEncaCaja)
{
CeldaColor(pzEncaCaja->Fila(),
	   pzEncaCaja->Columna(),
	   pzEncaCaja->Color(),
	   pzEncaCaja->Valor());
}
void QtCorteCaja::FormaRegistroGasto(const char *pchrPtrColor,
				     zGasto *pzGasto)
{
pzGasto->Color(pchrPtrColor);
CeldaColor(pzGasto->Fila(),
	   pzGasto->Columna(),
	   pzGasto->Color(),
	   pzGasto->Gasto());

CeldaColor(pzGasto->Fila(),
	   pzGasto->Columna()+1,
	   pzGasto->Color(),
	   pzGasto->Importe());
}
void QtCorteCaja::FormaDenominacionesCaja(zCaja *pzCaja)
{
zDenominacion *lzDenominacion;
for(lzDenominacion=(zDenominacion *)pzCaja->Dinero()->Primer();
    lzDenominacion;
    lzDenominacion=(zDenominacion *)pzCaja->Dinero()->Siguiente())
  FormaRegistroDenominacion(lzDenominacion);
}
void QtCorteCaja::FormaEncabezadosCaja(zCaja *pzCaja)
{
zEncabezadoCaja *lzEncaCaja;
for(lzEncaCaja=(zEncabezadoCaja *)pzCaja->EncabezadosCaja()->Primer();
    lzEncaCaja;
    lzEncaCaja=(zEncabezadoCaja *)pzCaja->EncabezadosCaja()->Siguiente())
 FormaRegistroEncabezadoCaja(lzEncaCaja); 
}
void QtCorteCaja::CeldaGris(int pintFila,int pintColumna,const QString &pQStrTexto)
{
zSiscomTableItem *lzSisTabItem=new zSiscomTableItem(this,
						    QColor("gray"),
						    QTableItem::OnTyping,
						    pQStrTexto);
setItem(pintFila,pintColumna,lzSisTabItem);
}

void QtCorteCaja::CeldaColor(int pintFila,
			     int pintColumna,
			     const char *pchrPtrColor,
			     const QString &pQStrTexto)
{
zSiscomTableItem *lzSisTabItem=new zSiscomTableItem(this,
						    QColor(pchrPtrColor),
						    QTableItem::OnTyping,
						    pQStrTexto);
setItem(pintFila,pintColumna,lzSisTabItem);
}
zCajas *QtCorteCaja::Cajas()
{   
     return zCajasExp;
}

void QtCorteCaja::EncabezadosGastos(int pintFila,int pintColumna)
{
char lchrArrGasto[]="Gasto                                              ";
int lintFiIni=0,
    lintCoIni=10,
    lintFila,
    lintColumna;
lintFila=pintFila+lintFiIni;
lintColumna=pintColumna+lintCoIni;
 zEncabezadosCaja *lzEncaSGastos=new zEncabezadosCaja;
 (*lzEncaSGastos) 							<<
 new zEncabezadoCaja(lintFila,lintColumna,0,"gray","Gastos") 		<<
 new zEncabezadoCaja(lintFila+1,lintColumna,0,"gray",lchrArrGasto)	<<
 new zEncabezadoCaja(lintFila+1,lintColumna+1,0,"gray","Importe") ;

 zZoGasto=new zZonaGasto(lintFila+2,lintColumna);
 zCajasExp->EncabezadosGastos(lzEncaSGastos);
}
void QtCorteCaja::EncabezadoPagoTarjeta(int pintFila,int pintColumna)
{
 zEncabezadosCaja *lzEncaSPagoT=new zEncabezadosCaja; 
 (*lzEncaSPagoT)								<<
 new zEncabezadoCaja(pintFila+16,pintColumna,0,"gray","Pago con tarjeta"); 
 zCajasExp->EncabezadosPagoTarjeta(lzEncaSPagoT);
}
void QtCorteCaja::PagoTarjeta(int pintFila,
				 int pintColumna)
{
zCelPaTarjeta=new zCeldaPagoTarjeta(pintFila+16,pintColumna+1,"gray");
CeldaGris(pintFila+16,pintColumna+1,"0.00");
}
void QtCorteCaja::EncabezadoImporteGastos(int pintFila,
					  int pintColumna)
{
zEncabezadosCaja *lzEncaSImGasto=new zEncabezadosCaja;
(*lzEncaSImGasto) 							<< 
new zEncabezadoCaja(pintFila+17,pintColumna,0,"white","Importe gastos") ;
zCelImGastos=new zCeldaImporteGastos(pintFila+17,pintColumna+1);
CeldaColor(pintFila+17,pintColumna+1,"white","0.00");
zCajasExp->EncabezadosImporteGastos(lzEncaSImGasto);
}

void QtCorteCaja::EncabezadoTransferencias(int pintFila,int pintColumna)
{
zEncabezadosCaja *lzEncaVenEfec=new zEncabezadosCaja;
(*lzEncaVenEfec) 							<< 
new zEncabezadoCaja(pintFila+18,pintColumna,0,"gray","Transferencias") <<
new zEncabezadoCaja(pintFila+18,pintColumna+1,0,"gray","0.00");
zCajasExp->EncabezadosVentasEfectivo(lzEncaVenEfec);
}

void QtCorteCaja::EncabezadoVentasEfectivo(int pintFila,int pintColumna)
{
zEncabezadosCaja *lzEncaVenEfec=new zEncabezadosCaja;
(*lzEncaVenEfec) 							<< 
new zEncabezadoCaja(pintFila+19,pintColumna,0,"white","Importe total que se recibio en caja") <<
new zEncabezadoCaja(pintFila+19,pintColumna+1,0,"white","0.00");
zCajasExp->EncabezadosVentasEfectivo(lzEncaVenEfec);
}
void QtCorteCaja::EncabezadoCambioDiaAnterior(int pintFila,int pintColumna)
{
zEncabezadosCaja *lzEncaVenEfec=new zEncabezadosCaja;
(*lzEncaVenEfec) 							<< 
new zEncabezadoCaja(pintFila+20,pintColumna,0,"gray","Cambio dia anterior") <<
new zEncabezadoCaja(pintFila+20,pintColumna+1,0,"gray","0.00");
zCajasExp->EncabezadosVentasEfectivo(lzEncaVenEfec);
}

void QtCorteCaja::EncabezadoVentasTotales(int pintFila,int pintColumna)
{
zEncabezadosCaja *lzEncaVenEfec=new zEncabezadosCaja;
(*lzEncaVenEfec) 							<< 
new zEncabezadoCaja(pintFila+21,pintColumna,0,"white","Ventas Totales") <<
new zEncabezadoCaja(pintFila+21,pintColumna+1,0,"white","0.00");
zCajasExp->EncabezadosVentasEfectivo(lzEncaVenEfec);
}

void QtCorteCaja::EncabezadoCalculandoCorte(int pintFila,int pintColumna)
{
zEncabezadosCaja *lzEncaVenEfec=new zEncabezadosCaja;
(*lzEncaVenEfec) 							<< 
new zEncabezadoCaja(pintFila+22,pintColumna,0,"gray","Calculando Corte") <<
new zEncabezadoCaja(pintFila+22,pintColumna+1,0,"gray","0.00");
zCajasExp->EncabezadosVentasEfectivo(lzEncaVenEfec);
}

void QtCorteCaja::EncabezadoCorteTotal(int pintFila,int pintColumna)
{
zEncabezadosCaja *lzEncaVenEfec=new zEncabezadosCaja;
(*lzEncaVenEfec) 							<< 
new zEncabezadoCaja(pintFila+23,pintColumna,0,"white","Corte Total") <<
new zEncabezadoCaja(pintFila+23,pintColumna+1,0,"white","0.00");
zCajasExp->EncabezadosVentasEfectivo(lzEncaVenEfec);
}

void QtCorteCaja::ImporteEfectivoCaja(int pintFila,
				      int pintColumna)
{
zCelImporteEC=new zCeldaImporteEfectivoCaja(pintFila+19,pintColumna+1);
CeldaColor(pintFila+19,pintColumna+1,"white","0.00");
}
void QtCorteCaja::ImporteTransferencias(int pintFila,
					int pintColumna)
{
zCelImporteT=new zCeldaImporteTransferencias(pintFila+18,pintColumna+1);
CeldaGris(pintFila+18,pintColumna+1,"0.00");
}
void QtCorteCaja::CambioDiaAnterior(int pintFila,
				    int pintColumna)
{
zCelCambioDA=new zCeldaCambioDiaAnterior(pintFila+20,pintColumna+1);
CeldaGris(pintFila+20,pintColumna+1,"0.00");
}
void QtCorteCaja::VentasTotales(int pintFila,int pintColumna)
{
zCelVentasTotales=new zCeldaVentasTotales(pintFila+21,pintColumna+1);
CeldaColor(pintFila+21,pintColumna+1,"white","0.00");
}
void QtCorteCaja::CalculandoCorte(int pintFila,int pintColumna)
{
zCelCalculandoCorte=new zCeldaCalculandoCorte(pintFila+22,pintColumna+1);
CeldaColor(pintFila+22,pintColumna+1,"gray","0.00");
}

void QtCorteCaja::CorteTotal(int pintFila,int pintColumna)
{
zCelCorteTotal=new zCeldaCorteTotal(pintFila+23,pintColumna+1);
CeldaColor(pintFila+23,pintColumna+1,"white","0.00");
}

void QtCorteCaja::FormandoEncabezadosCorte()
{
zEncabezadoCaja *lzEncaCorte;
for(lzEncaCorte=(zEncabezadoCaja *)zCajasExp->EncabezadosCorte()->Primer();
    lzEncaCorte;
    lzEncaCorte=(zEncabezadoCaja *)zCajasExp->EncabezadosCorte()->Siguiente())
 FormaRegistroEncabezadoCaja(lzEncaCorte);
}

zZonaGasto *QtCorteCaja::ZonaGasto()
{
     return zZoGasto;
}
void QtCorteCaja::AgregaGasto(int pintFila,int pintColumna)
{
zCaja *lzCaPrincipal=(zCaja *)(*zCajasExp)[0];
lzCaPrincipal->Gasto(Gasto(pintFila,pintColumna));
MuestraGastos(lzCaPrincipal);
}
zGasto *QtCorteCaja::Gasto(int pintFila,int pintColumna)
{
  zGasto *lzGasto=new zGasto(pintFila,pintColumna);
   lzGasto->Gasto((const char *)text(pintFila,pintColumna));

return lzGasto;
}
zCeldaPagoTarjeta *QtCorteCaja::CeldaPagoTarjeta()
{
  return zCelPaTarjeta;
}
zCeldaImporteGastos *QtCorteCaja::CeldaImporteGastos()
{
  return zCelImGastos;
}
zCeldaImporteEfectivoCaja *QtCorteCaja::CeldaImporteEfectivoCaja()
{
return zCelImporteEC;
}
zCeldaImporteTransferencias *QtCorteCaja::CeldaImporteTransferencias()
{
  return zCelImporteT;
}
zCeldaCambioDiaAnterior *QtCorteCaja::CeldaCambioDiaAnterior()
{
  return zCelCambioDA;
}
zCeldaVentasTotales *QtCorteCaja::CeldaVentasTotales()
{
  return zCelVentasTotales;
}
zCeldaCalculandoCorte *QtCorteCaja::CeldaCalculandoCorte()
{
  return zCelCalculandoCorte;
}
zCeldaCorteTotal *QtCorteCaja::CeldaCorteTotal()
{
  return zCelCorteTotal;
}

void QtCorteCaja::MuestraGastos(zCaja *pzCaja)
{
zGasto *lzGasto;
const char *lchrPtrColores[]={"gray","white"};
int lintContador;
for(lzGasto=(zGasto *)pzCaja->Gastos()->Primer(),
    lintContador=0; 
    lzGasto;
    lzGasto=(zGasto *)pzCaja->Gastos()->Siguiente(),
    lintContador++)
   FormaRegistroGasto(lchrPtrColores[lintContador%2],lzGasto);
}
void QtCorteCaja::ActualizaCantidadesCambio(zDenominaciones *pzDenominaciones)
{
  Cajas()->CajaPorNombre("Cambio")->Dinero()->ActualizaCantidades(pzDenominaciones);
  Cajas()->CajaPorNombre("Cambio")->Dinero()->ActualizaImportes(pzDenominaciones);
}
void QtCorteCaja::ActualizaTotalCajaCambio(const char *pchrPtrTotalCajaCambio)
{
  Cajas()->CajaPorNombre("Cambio")->Total(pchrPtrTotalCajaCambio);
}
void QtCorteCaja::ActualizaCambioDiaAnterior(const char *pchrPtrCambioDiaA)
{
  Cajas()->Principal()->CambioDiaAnterior(pchrPtrCambioDiaA);  
}
void QtCorteCaja::ActualizaVentasTotales(const char *pchrPtrVentasT)
{
  Cajas()->Principal()->VentasTotales(pchrPtrVentasT);
}
