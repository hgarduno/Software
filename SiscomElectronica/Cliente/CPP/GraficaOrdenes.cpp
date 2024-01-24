#include <GraficaOrdenes.h>
#include <IMP_CapturaRangoFechas.h>
#include <qpainter.h>
const char *gchrPtrDias[]={"Lunes",
			   "Martes",
			   "Miercoles",
			   "Jueves",
			   "Viernes",
			   "Sabado",
			   "Domingo"};

StcSiscomRGB gStcSRGB[]={ {255,0,0},
			  {0,255,0},
			  {0,0,255}
			};
QGraficaOrdenes::QGraficaOrdenes(SiscomDatCom *pSisDatCom,
				 char **pchrPtrArgumentos,
				 QWidget *pQWParent,
				 const char *pchrPtrName):
		QWidget(pQWParent,pchrPtrName),
		chrPtrArgumentos(pchrPtrArgumentos),
		SisDatCom(pSisDatCom),
		intIniciaEjeX(50),
		intTerminaEjeX(10),
		intIniciaEjeXPosY(30),
		intIniciaEjeY(10),
		QLEjeX(0),
		QLEjeY(0),
		intHoraInicio(8),
		intHoraFin(21),
		intTamElipseX(10),
		intTamElipseY(5),
		intPosTextoDia(20)
{
	IniciaVariables();
	IniciaDiasHorasPuntos();
	setBackgroundColor(white);
	show();
}
void QGraficaOrdenes::ObtenAreaTrabajo()
{
	if(parent())
	QRArea=geometry();
	else
	QRArea=rect();
}
void QGraficaOrdenes::ColocaEjes(QPainter *pQPDibuja)
{
	ObtenAreaTrabajo();
	ColocaEjeX(pQPDibuja);
	ColocaEjeY(pQPDibuja);
	ColocaTextoDias(pQPDibuja);
}
void QGraficaOrdenes::ColocaTextoDias(QPainter *pQPDibuja)
{
int lintContador;
int lintIncEspacio=QLEjeX->ObtenDistanciaX()/7;
int lintDesplazaX=QLEjeX->X();
QWMatrix m,r;
for(lintContador=0;
    lintContador<7;
    lintContador++,
    lintDesplazaX+=lintIncEspacio)
{
 pQPDibuja->drawLine(lintDesplazaX,QLEjeX->Y()-5,lintDesplazaX,QLEjeX->Y()+5);
 pQPDibuja->drawText(lintDesplazaX,QLEjeX->Y()+intPosTextoDia,gchrPtrDias[lintContador]);
 ColocaMarcasHoras(gchrPtrDias[lintContador],lintDesplazaX,lintIncEspacio,pQPDibuja);
}
}
void QGraficaOrdenes::ColocaMarcasHoras(const char *pchrPtrDia,
					int pintInicioX,
					int pintTamanoX,
					QPainter *pQPDibuja)
{
int lintContador;
int lintIncX=pintTamanoX/(intHoraFin-intHoraInicio);
QPuntosDia *lQPDia;
QPuntoHora *lQPHora;
int lintDesplazaX=pintInicioX+lintIncX;
char lchrArrHora[12];
	lQPDia=QPSemana[pchrPtrDia];

  for(lintContador=intHoraInicio;
      lintContador<intHoraFin;
      lintContador++,
      lintDesplazaX+=lintIncX)
  { 
   sprintf(lchrArrHora,"%02d:00",lintContador);
   lQPHora=(*lQPDia)[lchrArrHora];
   lQPHora->ActualizaPunto(lintDesplazaX,QLEjeX->Y());
   pQPDibuja->drawLine(lintDesplazaX,
   			QLEjeX->Y()-2,
			lintDesplazaX,
			QLEjeX->Y()+2);
  }

}
void QGraficaOrdenes::ColocaEjeX(QPainter *pQPDibuja)
{
    if(QLEjeX)
     delete QLEjeX;
    QLEjeX=new QLinea(QRArea.left()+intIniciaEjeX,
    		      QRArea.bottom()-intIniciaEjeXPosY,
		      QRArea.right()-intTerminaEjeX,
		      QRArea.bottom()-intIniciaEjeXPosY);
   DibujaLinea(QCEjes,pQPDibuja,QLEjeX); 

}
void QGraficaOrdenes::ColocaEjeY(QPainter *pQPDibuja)
{
    if(QLEjeY)
     delete QLEjeY;
	QLEjeY=new QLinea(QRArea.left()+intIniciaEjeX,
			QRArea.top()+intIniciaEjeY,
			QRArea.left()+intIniciaEjeX,
			QRArea.bottom()-intIniciaEjeXPosY);
	DibujaLinea(QCEjes,pQPDibuja,QLEjeY);
}
int QGraficaOrdenes::EspacioEntreDias()
{
int lintTamano=(QRArea.right()-QRArea.left());
return lintTamano/7;
}
void QGraficaOrdenes::paintEvent(QPaintEvent *pQPEvent)
{
QPainter lQPDibuja(this);
	ColocaEjes(&lQPDibuja);
	RealizaGrafica(&lQPDibuja);
}
void QGraficaOrdenes::resizeEvent(QResizeEvent *pQREvent)
{

}

void QGraficaOrdenes::mouseDoubleClickEvent(QMouseEvent *pQMEvent)
{
	if(pQMEvent->button()==Qt::LeftButton)
	{
	  QCapturaRangoFechas lQCRFechas;
	  lQCRFechas.ObtenRangoFechas(chrArrFechaIni,
	  			      chrArrFechaFin);
	  ConsultaOrdenes();
	}
}
void QGraficaOrdenes::ConsultaOrdenes()
{

OrdenesHora lOHora;

	lOHora << 
	new OrdenHora("","","","VentasPorHora")		<<
	new OrdenHora("","","",chrPtrArgumentos[0])	<<
	new OrdenHora("","","",chrArrFechaIni)		<<
	new OrdenHora("","","",chrArrFechaFin);

OpOrdenesHora lOOrdenesHora(SisDatCom,&lOHora);
	    lOOrdenesHora.SiscomConsulta("ConsultaVentasPorHora",
	    				 (QPtrList<SiscomInformacion> *)&OHora);
	    lOOrdenesHora.ObtenDatosSemanas(CSDtsSemanas);


}

void QGraficaOrdenes::DibujaLinea(const QColor &pQColor,
				  QPainter *pQPDibuja,
				  QLinea *pQLinea)
{
/*	pQPDibuja->setBrush(pQColor); */
	pQPDibuja->drawLine(pQLinea->X(),
			    pQLinea->Y(),
			    pQLinea->X1(),
			    pQLinea->Y1());
}
QPuntosDia *QGraficaOrdenes::IniciaPuntosDias(const char *pchrPtrDia)
{
int lintContador;
QPuntosDia *lQPDias;
char lchrArrHora[12];
	lQPDias=new QPuntosDia(pchrPtrDia);
   for(lintContador=intHoraInicio;lintContador<intHoraFin;lintContador++)
   {
	sprintf(lchrArrHora,"%02d:00",lintContador);
	lQPDias->AgregaPunto(new QPuntoHora(lchrArrHora,0,0));
   }
  return lQPDias;
}
void QGraficaOrdenes::IniciaDiasHorasPuntos()
{
int lintContador;
	for(lintContador=0;lintContador<7;lintContador++)
	   QPSemana << IniciaPuntosDias(gchrPtrDias[lintContador]);              
}

void QGraficaOrdenes::IniciaVariables()
{
	SiscomObtenFechaHoyCharAAAADDMM(chrArrFechaIni);
	SiscomObtenFechaHoyCharAAAADDMM(chrArrFechaFin);
	setMinimumSize(QSize(200,400));
	setMaximumSize(QSize(5000,5000));
	ConsultaOrdenes();
}
float QGraficaOrdenes::ObtenEscala()
{
CSisDatosSemana *lCSDtoSemana;
CSisDatoDia *lCSDtoDia;
CSisDatoHora *lCSDtoHora;
float *lfltImportes;
int lintNImportes;
float lfltMaximo;
float *lfltMaximos;
int lintNMaximos=0;
float lfltElMaximo;
	lfltMaximos=(float *)malloc(sizeof(float)+1);
	for(lCSDtoSemana=CSDtsSemanas.first();
	    lCSDtoSemana;
	    lCSDtoSemana=CSDtsSemanas.next())
	{
	   for(lCSDtoDia=lCSDtoSemana->ObtenDias().first();
	       lCSDtoDia;
	       lCSDtoDia=lCSDtoSemana->ObtenDias().next())
	   {
	      lfltImportes=lCSDtoDia->ObtenDatosHoras().ObtenImportes(&lintNImportes);
	      lfltMaximo=ObtenMaximo(lfltImportes,lintNImportes);
	      lfltMaximos[lintNMaximos++]=lfltMaximo;
	      lfltMaximos=(float *)realloc(lfltMaximos,sizeof(float)*(lintNMaximos+1));

		free(lfltImportes);
	   }
	}
     lfltElMaximo=ObtenMaximo(lfltMaximos,lintNMaximos); 
     free(lfltMaximos);

	return QLEjeY ? (QLEjeY->Y1()-QLEjeY->Y())/lfltElMaximo:0.0;
}
void QGraficaOrdenes::Grafica(QPainter *pQPDibuja,
			      QColor pQColor,
			      CSisDatoDia *pCSDatoDia,
			      float pfltEscalaY)
{
QPuntosDia *lQPDia;
QPuntoHora *lQPHora;
CSisDatoHora *lCSDtoHora;
int lintCoordenaY;
	if((lQPDia=QPSemana[pCSDatoDia->ObtenDia()]))
	{
	  for(lCSDtoHora=pCSDatoDia->ObtenDatosHoras().first();
	      lCSDtoHora;
	      lCSDtoHora=pCSDatoDia->ObtenDatosHoras().next())
	  {
	      if((lQPHora=(*lQPDia)[lCSDtoHora->ObtenHora()]))
	      {
	      	lintCoordenaY=(int )(lCSDtoHora->ObtenImporte()*pfltEscalaY);
		pQPDibuja->setPen(QPen(pQColor));
		pQPDibuja->drawEllipse(lQPHora->ObtenX()-intTamElipseX/2,
				       (QLEjeY->Y1()-lintCoordenaY)-intTamElipseY/2,
				       intTamElipseX,intTamElipseY);
	      }
	  }


	}


}

void QGraficaOrdenes::RealizaGrafica(QPainter *pQPDibuja)
{
CSisDatosSemana *lCSDtoSemana;
CSisDatoDia *lCSDtoDia;
float lfltEscalaY=ObtenEscala();
int lintCColor=0;
	for(lCSDtoSemana=CSDtsSemanas.first();
	    lCSDtoSemana;
	    lCSDtoSemana=CSDtsSemanas.next(),
	    lintCColor++)
	{
	   SiscomMensajesLog(gPtrFleArchivoLog,
	   		     "Graficando La Semana {%s %s}",
			     lCSDtoSemana->ObtenInicioSemana(),
			     lCSDtoSemana->ObtenFinSemana());
	   for(lCSDtoDia=lCSDtoSemana->ObtenDias().first();
	       lCSDtoDia;
	       lCSDtoDia=lCSDtoSemana->ObtenDias().next())
	     Grafica(pQPDibuja,
	     	     QColor(gStcSRGB[lintCColor].intR,
		            gStcSRGB[lintCColor].intG,
			    gStcSRGB[lintCColor].intB),
		     lCSDtoDia,
		     lfltEscalaY);

	}
}
float QGraficaOrdenes::ObtenMaximo(float *pfltPtrNumeros,int pintNN)
{
float lfltPivote;
int lintContador;
	lfltPivote=pfltPtrNumeros[0];
	for(lintContador=0;
	    lintContador<pintNN;
	    lintContador++)
	 if(lfltPivote<=pfltPtrNumeros[lintContador])
	  lfltPivote=pfltPtrNumeros[lintContador];
   return lfltPivote;
}
