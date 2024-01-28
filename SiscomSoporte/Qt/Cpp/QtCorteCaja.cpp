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
 EncabezadoVentasEfectivo(pintFila,pintColumna);
 FormandoCajaCorte(pintFila,pintColumna);
 FormandoEncabezadosCorte();
 PagoTarjeta(pintFila,pintColumna);
 zSiscomQt3::AjustaColumnasTabla(this);
}
void QtCorteCaja::FormandoCajaCorte(int pintFila,int pintColumna)
{
 (*zCajasExp) 							<< 
 FormaCajaDinero(pintFila,pintColumna,"Caja")			<<
 FormaCajaDinero(pintFila,pintColumna+4,"Dinero A Caja");
}
zCaja *QtCorteCaja::FormaCajaDinero(int pintFila,
				    int pintColumna,
				   const char *pchrPtrCaja)
{
zCaja *lzCaja=new zCaja(pchrPtrCaja);
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
zCaja *lzCaPrincipal=(zCaja *)(*zCajasExp)[0];
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

void QtCorteCaja::EncabezadoVentasEfectivo(int pintFila,int pintColumna)
{
zEncabezadosCaja *lzEncaVenEfec=new zEncabezadosCaja;
(*lzEncaVenEfec) 							<< 
new zEncabezadoCaja(pintFila+18,pintColumna,0,"gray","Ventas efectivo") <<
new zEncabezadoCaja(pintFila+18,pintColumna+1,0,"gray","0.00");
zCajasExp->EncabezadosVentasEfectivo(lzEncaVenEfec);
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
