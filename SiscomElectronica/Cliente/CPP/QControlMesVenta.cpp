#include <QControlMesVenta.h>
#include <QControlSemanaVenta.h>
#include <SiscomDesarrollo3Qt++.h>
QCtrMesVenta::QCtrMesVenta(CSisDatosSemanas pCSDtsSemanas,
			   QWidget *pQWParent,
			   const char *pchrPtrName):
		QTable(pQWParent,pchrPtrName),
		CSDtsSemanas(pCSDtsSemanas)
{
	MuestraInformacion();

}
void QCtrMesVenta::MuestraInformacion()
{

	AsignaColumnasYFilas();
	MuestraSemanas();
}
void QCtrMesVenta::MuestraSemanas()
{
CSisDatosSemana *lCSDtosSemana;
QCtrSemanaVenta *lQCtrSVenta;
int lintFila=0,
    lintColumna=0;
	for(lintColumna=0,
	    lCSDtosSemana=CSDtsSemanas.first();
	    lCSDtosSemana;
	    lCSDtosSemana=CSDtsSemanas.next(),
	    lintColumna++)
	{
	  lQCtrSVenta=new QCtrSemanaVenta(lCSDtosSemana,0,0);
	  setCellWidget(lintFila,
	  	        lintColumna,
			lQCtrSVenta);
	  if((numCols()-1)==lintColumna)
	  {
	   setRowHeight(lintFila,lQCtrSVenta->ObtenTamanoControl());
	   lintFila++;
	   lintColumna=-1;
	  }
	}

	for(lintColumna=0;lintColumna<numCols();lintColumna++)
	adjustColumn(lintColumna);

}
void QCtrMesVenta::AsignaColumnasYFilas()
{
int lintNFilas=CSDtsSemanas.count();
lintNFilas=lintNFilas/3 + ((lintNFilas%3) ? 1 : 0);
	  setNumCols(3);
	  setNumRows(lintNFilas);
SiscomEscribeLog3Qt("Numero Semanas:%d Numero Filas(%d)",
		    CSDtsSemanas.count(),
		    lintNFilas);
}
void QCtrMesVenta::ActualizaDatos(CSisDatosSemanas pCSDtsSemanas)
{
	CSDtsSemanas=pCSDtsSemanas;
	MuestraInformacion();
}
