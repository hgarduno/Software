#include <QtCuentaCortes.h>
#include <zSiscomTableItem.h>
#include <zSiscomQt3.h>
#include <zSiscomDesarrollo4.h>

#include <zEncabezadosCaja.h>
#include <zEncabezadoCaja.h>
#include <zSiscomTableItem.h>


QtCuentaCortes::QtCuentaCortes(QWidget *pQWParent,
			       const char *pchrPtrName):
			       	QTable(pQWParent,pchrPtrName)
{
setShowGrid(false);
}


void QtCuentaCortes::CeldaGris(int pintFila,int pintColumna,const QString &pQStrTexto)
{
zSiscomTableItem *lzSisTabItem=new zSiscomTableItem(this,
						    QColor("gray"),
						    QTableItem::OnTyping,
						    pQStrTexto);
setItem(pintFila,pintColumna,lzSisTabItem);
}



zEncabezadosCaja *QtCuentaCortes::Encabezados()
{
   return zEsCaja;
}


void QtCuentaCortes::EncabezadosDatosCortes()
{

(*Encabezados()) << 
new zEncabezadoCaja(Fila(),Columna(),"Fecha","gray","Fecha")  				<<
new zEncabezadoCaja(Fila(),Columna()+1,"Expendio","gray","Expendio")  			<<
new zEncabezadoCaja(Fila(),Columna()+2,"Ordenes","gray","Ordenes") 	 		<<
new zEncabezadoCaja(Fila(),Columna()+3,"Ventas","gray","Ventas")  			<<
new zEncabezadoCaja(Fila(),Columna()+4,"Efectivo","gray","Efectivo")  			<<
new zEncabezadoCaja(Fila(),Columna()+5,"Transferencias","gray","Transferencias")	<< 
new zEncabezadoCaja(Fila(),Columna()+6,"Tarjeta","gray","Tarjeta")			<< 
new zEncabezadoCaja(Fila(),Columna()+7,"Entregado","gray","Entregado");

}

void QtCuentaCortes::MuestraEncabezados()
{
zEncabezadoCaja *lzEnC;

for(lzEnC=(zEncabezadoCaja *)Encabezados()->Primer(); 
    lzEnC; 
    lzEnC=(zEncabezadoCaja *)Encabezados()->Siguiente())
CeldaColor(lzEnC->Fila(),
	   lzEnC->Columna(),
	   lzEnC->Color(),
	   lzEnC->Valor());
}


void QtCuentaCortes::IniciaVariables()
{
zEsCaja=new zEncabezadosCaja;
EncabezadosDatosCortes();
MuestraEncabezados();
}

void QtCuentaCortes::CeldaColor(int pintFila,
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


int QtCuentaCortes::Columna()
{
 return  intColumna;
}

int QtCuentaCortes::Fila()
{
    return intFila;
}

void QtCuentaCortes::Fila(int pintFila)
{
    intFila=pintFila;
}
void QtCuentaCortes::Columna(int pintColumna)
{
     intColumna=pintColumna;
}
