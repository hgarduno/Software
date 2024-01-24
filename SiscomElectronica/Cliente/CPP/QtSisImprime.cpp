#include <QtSisImprime.h>
#include <qpainter.h>
#include <qwidget.h>
#include <qpaintdevicemetrics.h>
#include <qprinter.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros3.h>
QtSisImprime::QtSisImprime(SiscomRegistro3Lst *pSisReg3LstDatos,
			   char **pchrPtrColumnas,
			   char **pchrPtrTitulosColumna,
			   int *pintPtrCaracteresC,
			   QWidget *pQWParent,
			   const char *pchrPtrName):
			QScrollView(pQWParent,pchrPtrName,WStaticContents),
		        SisReg3LstDatos(pSisReg3LstDatos),
			chrPtrColumnas(pchrPtrColumnas),
			chrPtrTitulosColumnas(pchrPtrTitulosColumna),
			intPtrCaracteresC(pintPtrCaracteresC),
			intPagina(0),
			intMargen(10),
			intTitulosYa(0)
{
SiscomEscribeLog3Qt("");
TamanoHoja();
setResizePolicy(Default);
resizeContents(1920,40000);
viewport()->setBackgroundMode( PaletteBase );
setVScrollBarMode(QScrollView::AlwaysOn);
}
void QtSisImprime::Margen(int pintMX,
			  int pintMY,
			  int pintMX1,
			  int pintMY1)
{
  intMX=pintMX;
  intMY=pintMY;
  intMX1=pintMX1;
  intMY1=pintMY1;

}
void QtSisImprime::DibujandoHoja(QPainter *pQPADibujo,
				 SiscomRegistro3Lst *pSisReg3LstDatos,
				 int pintRenglones,
				 int pintColumnas,
				 int pintPagina)
{
int lintRegistros=1;
SiscomRegistro3 *lSisReg3Datos;
SiscomRegistro3Lst lSisReg3LstDatos;


   while(lintRegistros <= pintRenglones &&
         pSisReg3LstDatos->current())
   {
     lSisReg3LstDatos << pSisReg3LstDatos->next();
     lintRegistros++;
   }


   DibujaHoja(pQPADibujo,
   	      &lSisReg3LstDatos,
	      pintPagina,
	      pintRenglones,
	      pintColumnas);

}

void QtSisImprime::Dibujando(QPainter *pQPADibujo,
			     QPrinter *pQPImpresora)
{
SiscomRegistro3 *lSisReg3Datos;
SiscomRegistro3Lst lSisReg3LstDatos;
int lintNColumnas;
int lintRegistros=1;
int lintNRegistros=65;
int lintPagina=1;
/*
 *  Se debe agregar a SiscomRegistro3 el numero de 
 *  campos que tiene el Registro
 */
lintNColumnas=8;

      for(lSisReg3Datos=SisReg3LstDatos->first(),
          lintRegistros=1;
          lSisReg3Datos;
	  lSisReg3Datos=SisReg3LstDatos->next(),
	  lintRegistros++)
      {
	  lSisReg3LstDatos << lSisReg3Datos ;
	  if(lintRegistros==lintNRegistros)
	  {
	   DibujaHoja(pQPADibujo,
	   	      &lSisReg3LstDatos,
		      lintPagina,
		      lintNRegistros,
		      lintNColumnas);
	   pQPImpresora->newPage();
	   lintRegistros=0;
	   lSisReg3LstDatos.clear();
	   /*
	   lintPagina++;
	   */
	  }
      }
}
void QtSisImprime::Dibujando(QPainter *pQPADibujo)
{
SiscomRegistro3 *lSisReg3Datos;
SiscomRegistro3Lst lSisReg3LstDatos;
int lintNColumnas;
int lintRegistros=0;
int lintNRegistros=65;
int lintPagina=1;
/*
 *  Se debe agregar a SiscomRegistro3 el numero de 
 *  campos que tiene el Registro
 */
lintNColumnas=8;

      for(lSisReg3Datos=SisReg3LstDatos->first(),
          lintRegistros=0;
          lSisReg3Datos;
	  lSisReg3Datos=SisReg3LstDatos->next(),
	  lintRegistros++)
      {
	  lSisReg3LstDatos << lSisReg3Datos ;
	  if(lintRegistros==lintNRegistros)
	  {
	   DibujaHoja(pQPADibujo,
	   	      &lSisReg3LstDatos,
		      lintPagina,
		      lintNRegistros,
		      lintNColumnas);
	   lintRegistros=0;
	   lSisReg3LstDatos.clear();
	   lintPagina++;
	  }
      }
}
void QtSisImprime::drawContents(QPainter *pQPADibujo,
				int ,
				int ,
				int ,
				int )
{
   	ObtenMedidas(pQPADibujo);
   	Dibujando(pQPADibujo);
}
void QtSisImprime::ObtenMedidas(QPainter *pQPDispositivo)
{
  QPDMedidas=new QPaintDeviceMetrics(pQPDispositivo->device());	
}
int QtSisImprime::PixelesAMM(int pintPixeles)
{
return pintPixeles/MMAPixeles(1);
}
int QtSisImprime::MMAPixeles(int pintMilimetros)
{
int lintPixeles;
	lintPixeles=(int )((pintMilimetros/25.4)*QPDMedidas->logicalDpiX());
	return lintPixeles;
}
int QtSisImprime::AnchoColumnaMM(QPainter *pQPDibuja,
				 int pintNCaracteres)
{
return MMAPixeles(PixelesAMM(AnchoColumna(pQPDibuja,pintNCaracteres)));
}
int QtSisImprime::AnchoColumna(QPainter *pQPDibuja,
			       int pintNCaracteres)
{
char lchrArrCadena[128];
char lchrArrPaso[10];
sprintf(lchrArrPaso,"%%0%dd",pintNCaracteres);
sprintf(lchrArrCadena,lchrArrPaso,0);
return pQPDibuja->fontMetrics().width(lchrArrCadena);
}
int QtSisImprime::ObtenAltoTexto(QPainter *pQPDibuja)
{
return pQPDibuja->fontMetrics().height();
}
void QtSisImprime::RectanguloHojaY(int pintPagina,
				  int pintAltoHoja,
				  int &pintY)
{
pintY=(pintPagina-1)*pintAltoHoja;
}
void QtSisImprime::RectanguloHojaTrabajo(int pintPagina,
					 int pintMargen,
					  int pintAltoTotalHoja,
					  int &pintX,
					  int &pintY)
{
pintX=pintMargen;
pintY=((pintPagina-1)*pintAltoTotalHoja)+pintMargen;
}
void QtSisImprime::TamanoHojaTrabajo(int pintMargen,
				     int pintAnchoTotal,
				     int pintAltoTotal,
				     int &pintAnchoHojaT,
				     int &pintAltoHojaT)
{
pintAnchoHojaT=pintAnchoTotal-2*pintMargen;
pintAltoHojaT=pintAltoTotal-(2*pintMargen);
}
void QtSisImprime::MuestraTitulosColumna(int pintXHojaT,
					 int pintNColumnas,
					 int pintTamRenglon,
					 QPainter *pQPDibuja,
					 int &pintYHojaT)
{
int lintContadorX;
int lintContador;
for(lintContadorX=pintXHojaT,
    lintContador=0;
    lintContador<pintNColumnas;
    lintContadorX+=AnchoColumnaMM(pQPDibuja,intPtrCaracteresC[lintContador]),
    lintContador++)
  pQPDibuja->drawText(lintContadorX+2,
		      pintYHojaT+2+pintTamRenglon*(lintContador+1),
		      chrPtrTitulosColumnas[lintContador]);

pintYHojaT+=pintTamRenglon*(lintContador);

}
void QtSisImprime::DibujaHoja(QPainter *pQPDibuja,
			       SiscomRegistro3Lst *pSisReg3LstDato,
			       int pintPagina,
			       int pintNFilas,
			       int pintNColumnas)
{
int lintAnchoTotalHoja=MMAPixeles(intTamanoX);
int lintAltoTotalHoja=MMAPixeles(intTamanoY);
int lintY;
int lintXHojaT,
    lintYHojaT,
    lintAnchoHojaT,
    lintAltoHojaT;
int lintMargen=MMAPixeles(intMargen);
int lintTamRenglon=MMAPixeles(PixelesAMM(ObtenAltoTexto(pQPDibuja)));
int lintContadorY;
int lintContadorX;
int lintEspacioColumna;
int lintContador;
SiscomRegistro3 *lSisReg3Dato;
RectanguloHojaY(pintPagina,lintAltoTotalHoja,lintY);
TamanoHojaTrabajo(lintMargen,
		  lintAnchoTotalHoja,
		  lintAltoTotalHoja,
		  lintAnchoHojaT,
		  lintAltoHojaT);
RectanguloHojaTrabajo(pintPagina,
		      lintMargen,
		      lintAltoTotalHoja,
		      lintXHojaT,
		      lintYHojaT);
lintEspacioColumna=AnchoColumnaMM(pQPDibuja,intPtrCaracteresC[0]);

pQPDibuja->drawLine(lintXHojaT,
		    lintYHojaT,
		    lintXHojaT+lintAnchoHojaT,
		    lintYHojaT);

pQPDibuja->drawLine(lintXHojaT,
		    lintYHojaT+lintAltoHojaT,
		    lintXHojaT+lintAnchoHojaT,
		    lintYHojaT+lintAltoHojaT);

pQPDibuja->drawLine(lintXHojaT+lintAnchoHojaT,
		    lintYHojaT,
		    lintXHojaT+lintAnchoHojaT,
		    lintYHojaT+lintAltoHojaT);
for(lintContadorY=lintTamRenglon,
    lintY=0,
    lSisReg3Dato=pSisReg3LstDato->first();
    lintY<pintNFilas;
    lintContadorY+=lintTamRenglon,
    lintY++,
    lSisReg3Dato=pSisReg3LstDato->next())
{
pQPDibuja->drawLine(lintXHojaT,
		    lintYHojaT+lintContadorY,
		    lintXHojaT+lintAnchoHojaT,
		    lintYHojaT+lintContadorY);
for(lintContadorX=lintXHojaT,
    lintContador=0 ;
    lintContador<pintNColumnas;
    lintContadorX+=AnchoColumnaMM(pQPDibuja,intPtrCaracteresC[lintContador]),
    lintContador++)
{
pQPDibuja->drawLine(lintContadorX,
		    lintYHojaT,
		    lintContadorX,
		    lintYHojaT+lintAltoHojaT);
pQPDibuja->drawText(lintContadorX+2,
		    lintYHojaT+lintContadorY-2,
		    (*lSisReg3Dato)[chrPtrColumnas[lintContador]],
		    0,
		    -1);
}
}
}
void QtSisImprime::DibujaHoja(QPainter *pQPDibuja,int pintPagina)
{
int lintPosX,
    lintPosY;

int lintAncho,
	lintAlto;

int lintPosX1,
    lintPosY1;
int lintAncho1,
    lintAlto1;

lintAncho=MMAPixeles(intTamanoX);
lintAlto=MMAPixeles(intTamanoY);
lintPosY=lintAlto*(pintPagina+1);

lintPosX1=MMAPixeles(intMargen);
lintPosY1=MMAPixeles(intMargen);

lintAncho1=lintAncho-2*MMAPixeles(intMargen);
lintAlto1=lintAlto-2*MMAPixeles(intMargen);
pQPDibuja->drawRect(lintPosX1,lintPosY1,lintAncho1,lintAlto1);

int lintContador,
    lintNLineas,
    lintEspacioY,
    lintEspacio,
    lintDesplaza;

int lintTamano=PixelesAMM(ObtenAltoTexto(pQPDibuja));
 lintEspacioY=MMAPixeles(lintTamano);
 lintNLineas=lintAlto1/MMAPixeles(lintTamano);
for(lintContador=0,
    lintDesplaza=lintEspacioY;
    lintContador<lintNLineas;
    lintContador++,
    lintDesplaza+=lintEspacioY)
{
pQPDibuja->drawLine(lintPosX1,
		    lintPosY1+lintDesplaza, 
		    lintPosX1+lintAncho1,
		    lintPosY1+lintDesplaza);
}


int lintNColumnas=7;

lintEspacio=lintAncho1/lintNColumnas;

for(lintContador=0,
    lintDesplaza=lintEspacio;
    lintContador<lintNColumnas;
    lintContador++,
    lintDesplaza+=lintEspacio)
{
pQPDibuja->drawLine(lintPosX1+lintDesplaza,
		    lintPosY1,
		    lintPosX1+lintDesplaza,
		    lintPosY1+lintAlto1);

pQPDibuja->drawText(lintPosX1+lintContador*lintDesplaza+2,
		    lintPosY1+lintEspacioY-2,
		    "Heli Garduno",
		    0,
		    -1);

}



}
void QtSisImprime::TamanoHoja()
{
   intTamanoX=206;
   intTamanoY=279;
}
