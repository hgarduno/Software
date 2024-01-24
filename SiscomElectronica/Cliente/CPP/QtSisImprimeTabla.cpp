#include <QtSisImprimeTabla.h>
#include <QtSisImprimeMargen.h>
#include <QtSisImprimeHoja.h>
#include <QtSisImprimeEncabezados.h>
#include <SiscomRegistros3.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qpaintdevicemetrics.h>
#include <qpainter.h>
#include <qevent.h>
#include <qprinter.h>
QtSisImprimeTabla::QtSisImprimeTabla(QWidget *pQWParent,
				     const char *pchrPtrName):
		     QScrollView(pQWParent,pchrPtrName),
		     intYaMedidasDispositivo(0)
{
setResizePolicy(Default);
resizeContents(1920,40000);
viewport()->setBackgroundMode( PaletteBase );
setVScrollBarMode(QScrollView::AlwaysOn);

}
void QtSisImprimeTabla::drawContents(QPainter *pQPDibuja,
				     int,
				     int,
				     int,
				     int)
{
	MedidasDispositivo(pQPDibuja);
	Dibujando(pQPDibuja);

}
void QtSisImprimeTabla::HojaTrabajo(QPainter *pQPDibuja,
				    SiscomRegistro3Lst *pSisReg3LstDatos,
				    int pintHoja,
				    int pintPagina)
{
   	
	DibujaHojaTrabajo(pQPDibuja,pintHoja,pintPagina);
	MuestraDatos(pQPDibuja,pSisReg3LstDatos,pintPagina,pintHoja);
	
}
void QtSisImprimeTabla::Encabezado(QPainter *pQPDibuja,
				   int pintHoja,
				   int pintPagina)
{
if(!pintHoja && 
   pintPagina==1) 
{
	QtSisImpEncabezados->DibujaEncabezado(pQPDibuja);
	QtSisImpHojaT->Encabezados(QtSisImpEncabezados);
}
}
void QtSisImprimeTabla::MuestraDatos(QPainter *pQPDibuja,
				     SiscomRegistro3Lst *pSisReg3LstDatos,
				     int pintPagina,
				     int pintHoja)
{
SiscomRegistro3 *lSisReg3Renglon;
int lintContadorY=QtSisImpHojaT->Ypx(pintHoja,pintPagina)+AltoTextoPx(pQPDibuja);
for(lSisReg3Renglon=pSisReg3LstDatos->first();
    lSisReg3Renglon;
    lSisReg3Renglon=pSisReg3LstDatos->next())
{
	MuestraRenglon(pQPDibuja,
		       lintContadorY,
		       pintPagina,
		       pintHoja,
		       lSisReg3Renglon);
	DibujaLineaY(pQPDibuja,lintContadorY);
	lintContadorY+=AltoTextoPx(pQPDibuja);
}
MuestraNumeroPagina(pQPDibuja,pintPagina,lintContadorY); 
}
void QtSisImprimeTabla::MuestraRenglon(QPainter *pQPDibuja,
				       int pintY,
				       int pintPagina,
				       int pintHoja,
				       SiscomRegistro3 *pSisReg3Renglon)
{
int lintContadorX=QtSisImpHojaT->Xpx();
int lintContador;
for(lintContador=0;
    lintContador<QtSisImpEncabezados->Columnas();
    lintContador++)
{
   pQPDibuja->drawText(lintContadorX+2,
   		       pintY-2,
		       (*pSisReg3Renglon)[chrPtrColumnas[lintContador]]);
   DibujaLineaX(pQPDibuja,pintHoja,pintPagina,lintContadorX);
   lintContadorX+=QtSisImpEncabezados->AnchoColumnaPx(
   					 pQPDibuja,
					 intPtrCaracteresC[lintContador]);
}
}
void QtSisImprimeTabla::DibujaHojaTrabajo(QPainter *pQPDibuja,
					  int pintHoja,
					  int pintPagina)
{			    
pQPDibuja->drawLine(QtSisImpHojaT->Xpx(),
		    QtSisImpHojaT->Ypx(pintHoja,pintPagina),
		    QtSisImpHojaT->Xpx(),
		    QtSisImpHojaT->Y1px(pintHoja));
pQPDibuja->drawLine(QtSisImpHojaT->Xpx(),
		    QtSisImpHojaT->Ypx(pintHoja,pintPagina),
		    QtSisImpHojaT->X1px(),
		    QtSisImpHojaT->Ypx(pintHoja,pintPagina));
pQPDibuja->drawLine(QtSisImpHojaT->X1px(),
		    QtSisImpHojaT->Ypx(pintHoja,pintPagina),
		    QtSisImpHojaT->X1px(),
		    QtSisImpHojaT->Y1px(pintHoja));
pQPDibuja->drawLine(QtSisImpHojaT->Xpx(),
		    QtSisImpHojaT->Y1px(pintHoja),
		    QtSisImpHojaT->X1px(),
		    QtSisImpHojaT->Y1px(pintHoja));
}
void QtSisImprimeTabla::Dibujando(QPainter *pQPDibuja)
{
int lintHoja=0,
    lintPagina=1,
    lintNRenglones;
SiscomRegistro3Lst lSisReg3LstDatos;
	SisReg3LstDatos->first();
	while(SisReg3LstDatos->current())
	{
	Encabezado(pQPDibuja,lintHoja,lintPagina);
	lintNRenglones=ObtenNumeroRenglones(pQPDibuja,lintHoja,lintPagina);
	RenglonesHoja(lintNRenglones,&lSisReg3LstDatos); 
	HojaTrabajo(pQPDibuja,&lSisReg3LstDatos,lintHoja,lintPagina);
	lintHoja++;
	lintPagina++;
	lSisReg3LstDatos.clear();
	}
   
}

void QtSisImprimeTabla::Dibujando(QPainter *pQPDibuja,
				  QPrinter *pQPImpresora)
{
int lintHoja=0,
    lintPagina=1,
    lintNRenglones;
SiscomRegistro3Lst lSisReg3LstDatos;
	SisReg3LstDatos->first();
	while(SisReg3LstDatos->current())
	{
	Encabezado(pQPDibuja,lintHoja,lintPagina);
	lintNRenglones=ObtenNumeroRenglones(pQPDibuja,lintHoja,lintPagina);
	RenglonesHoja(lintNRenglones,&lSisReg3LstDatos); 
	HojaTrabajo(pQPDibuja,&lSisReg3LstDatos,lintHoja,lintPagina);
	lintPagina++;
	lSisReg3LstDatos.clear();
	pQPImpresora->newPage();
	}
   
}
void QtSisImprimeTabla::DibujaLineaY(QPainter *pQPDibuja,
				     int pintContadorY)
{
pQPDibuja->drawLine(QtSisImpHojaT->Xpx(),
		    pintContadorY,
		    QtSisImpHojaT->X1px(),
		    pintContadorY);

}
void QtSisImprimeTabla::DibujaLineaX(QPainter *pQPDibuja,
				     int pintHoja,
				     int pintPagina,
				     int pintContadorX)
{
pQPDibuja->drawLine(pintContadorX,
		    QtSisImpHojaT->Ypx(pintHoja,pintPagina),
		    pintContadorX,
		    QtSisImpHojaT->Y1px(pintHoja)-AltoTextoPx(pQPDibuja));

}
void QtSisImprimeTabla::RenglonesHoja(int pintNRenglones,
				      SiscomRegistro3Lst *pSisReg3LstRenglones)
{
SiscomRegistro3 *lSisReg3Renglon;
int lintContador=0;
		while(lintContador<pintNRenglones)
		{
		     (*pSisReg3LstRenglones) << SisReg3LstDatos->current();
		     SisReg3LstDatos->next();
		     lintContador++;
		    
		}
}

int QtSisImprimeTabla::ObtenNumeroRenglones(QPainter *pQPDibuja,
					    int pintHoja,
					    int pintPagina)
{
int lintTamRenglon=pQPDibuja->fontMetrics().height();

return 
(QtSisImpHojaT->Y1px(pintHoja) -
 QtSisImpHojaT->Ypx(pintHoja,pintPagina))/lintTamRenglon;
}
void QtSisImprimeTabla::Columnas(char **pchrPtrColumnas)
{
	chrPtrColumnas=pchrPtrColumnas;
}
void QtSisImprimeTabla::TitulosColumnas(char **pchrPtrTitulosColumna)
{
 chrPtrTitulosColumna=pchrPtrTitulosColumna;
}
void QtSisImprimeTabla::RegistrosSiscom(SiscomRegistro3Lst *pSisReg3LstDatos)
{
	SisReg3LstDatos=pSisReg3LstDatos;
}
void QtSisImprimeTabla::CaracteresColumna(int *pintPtrCaracteresC)
{
	intPtrCaracteresC=pintPtrCaracteresC;
}
void QtSisImprimeTabla::MargenSuperior(int pintX,
					  int pintY)
{
 intMargenSuperiorX=pintX;
 intMargenSuperiorY=pintY;
}
void QtSisImprimeTabla::MargenInferior(int pintX,
					  int pintY)
{
	intMargenInferiorX=pintX;
	intMargenInferiorY=pintY;
}
void QtSisImprimeTabla::TamanoHoja(int pintAncho,
				      int pintAlto)
{
	intAnchoHoja=pintAncho;
	intAltoHoja=pintAlto;
}

void QtSisImprimeTabla::CalculaHojaTrabajo()
{
int lintAnchoHojaT,
    lintAltoHojaT;
lintAnchoHojaT=QtSisImpHoja->mmAncho()-(QtSisImpMSup->Xmm()+QtSisImpMInf->Xmm());
lintAltoHojaT=QtSisImpHoja->mmAlto()-(QtSisImpMSup->Ymm()+QtSisImpMInf->Ymm());
QtSisImpHojaT->mmAncho(lintAnchoHojaT);
QtSisImpHojaT->mmAlto(lintAltoHojaT);
QtSisImpHojaT->MargenSuperior(QtSisImpMSup);
QtSisImpHojaT->MargenInferior(QtSisImpMInf);
}

void QtSisImprimeTabla::MedidasDispositivo(QPainter *pQPDibuja)
{
  if(!intYaMedidasDispositivo)
  {
	QPDMMedidas=new QPaintDeviceMetrics(pQPDibuja->device());
        QtSisImpMSup=new QtSisImprimeMargen(QPDMMedidas);
	QtSisImpMInf=new QtSisImprimeMargen(QPDMMedidas);
	QtSisImpHoja=new QtSisImprimeHoja(QPDMMedidas);
	QtSisImpHojaT=new QtSisImprimeHoja(QPDMMedidas);
	QtSisImpMSup->X(intMargenSuperiorX);
	QtSisImpMSup->Y(intMargenSuperiorY);
	QtSisImpMInf->X(intMargenInferiorX);
	QtSisImpMInf->Y(intMargenInferiorY);
	QtSisImpHoja->mmAncho(intAnchoHoja);
	QtSisImpHoja->mmAlto(intAltoHoja);
	QtSisImpEncabezados=new QtSisImprimeEncabezados(
					QPDMMedidas,
					QtSisImpMSup,
					chrPtrTitulosColumna,
					intPtrCaracteresC);
	CalculaHojaTrabajo();
	intYaMedidasDispositivo=1;
  }
}
int QtSisImprimeTabla::PixelesAMM(int pintPixeles)
{
   return pintPixeles/MMAPixeles(1);
}
int QtSisImprimeTabla::MMAPixeles(int pintMilimetros)
{
return (int )((pintMilimetros/25.4)*QPDMMedidas->logicalDpiX());

}
void QtSisImprimeTabla::CambiaMargenAPixeles()
{
}
int QtSisImprimeTabla::AltoTextoPx(QPainter *pQPDibuja)
{
	return pQPDibuja->fontMetrics().height();
}
void QtSisImprimeTabla::MuestraNumeroPagina(QPainter *pQPDibuja,
					    int pintPagina,
					    int pintContadorY)
{
char lchrArrPagina[10];
int lintPosicionX;
lintPosicionX=(QtSisImpHojaT->X1px()-QtSisImpHojaT->Xpx())/2;
	sprintf(lchrArrPagina,"%d",pintPagina);
pQPDibuja->drawText(lintPosicionX+2,
		    pintContadorY-2,
		    lchrArrPagina);
}

void QtSisImprimeTabla::keyPressEvent(QKeyEvent *pQKETecla)
{
	SiscomEscribeLog3Qt("%d",pQKETecla->key());
	switch(pQKETecla->key())
	{
	   case Qt::Key_Up:
	   	 SiscomEscribeLog3Qt("Pagina hacia arriba");
	   break;
	   case Qt::Key_Down:
	   	 SiscomEscribeLog3Qt("Pagina hacia abajo");
	   break;

	}

}
