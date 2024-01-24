#include <QControlSemanaVenta.h>
#include <OrdenesHora.h>


QCtrSemanaVenta::QCtrSemanaVenta(CSisDatosSemana *pCSDatosSemana,
				 QWidget *pQWParent,
				 const char *pchrPtrName):
		QTable(pQWParent,pchrPtrName),
		CSDatosSemana(pCSDatosSemana)
{
	setReadOnly(true);
	setShowGrid(false);
	//setFont(QFont("Helvetica",6));
	MuestraInformacion();

}
void QCtrSemanaVenta::MuestraInformacion()
{
CSisDatoDia *lCSDtoDia;
CSisDatoHora *lCSDtoHora;
int lintDias;
int lintHoras;
	setNumCols(CSDatosSemana->ObtenDias().count());
	lCSDtoDia=CSDatosSemana->ObtenDias().first();
	setNumRows(lCSDtoDia->ObtenDatosHoras().count()+3); 
	for(lintDias=0,
	    lCSDtoDia=CSDatosSemana->ObtenDias().first();
	    lCSDtoDia;
	    lCSDtoDia=CSDatosSemana->ObtenDias().next(),
	    lintDias++)
	{
    	  horizontalHeader()->setLabel(lintDias,lCSDtoDia->ObtenDia());
	  intHoras=0;
	  setText(0,lintDias,lCSDtoDia->ObtenFecha());
	  verticalHeader()->setLabel(0,"Fecha");
	  for(lCSDtoHora=lCSDtoDia->ObtenDatosHoras().first(),
	      lintHoras=1;
	      lCSDtoHora;
	      lCSDtoHora=lCSDtoDia->ObtenDatosHoras().next(),
	      lintHoras++)
	  {
	     verticalHeader()->setLabel(lintHoras,lCSDtoHora->ObtenHora());
	     setText(lintHoras,
	     	     lintDias,
		     lCSDtoHora->ObtenImporteChar());
	     adjustColumn(lintDias);
	     intHoras++;
	  }
	   
	   verticalHeader()->setLabel(lintHoras,"Total");
	   setText(lintHoras,
	   	   lintDias,
		   lCSDtoDia->ObtenImporteDiaChar());
	}
	   verticalHeader()->setLabel(lintHoras+1,"Sem");
	   setText(lintHoras+1,numCols()-1,CSDatosSemana->ObtenImporteSemana());
}
int QCtrSemanaVenta::ObtenTamanoControl()
{

	return (rowHeight(0)*(intHoras+5));

}
