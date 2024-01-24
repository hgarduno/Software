#include <QCtrlGrupo.h>
#include <SISCOMComunicaciones++.h>
#include <qlayout.h>
#include <qtable.h>

#include <CQSisCompetencias.h>


QCtrlGrupo::QCtrlGrupo( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
}
void QCtrlGrupo::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QTDatos=new QTable(0,0,this);
	QTDatos->setReadOnly(true);
	QHBLayout->addWidget(QTDatos);
}
void QCtrlGrupo::MuestraCompetencias()
{
/*
CQSisGimnasio *lCQSGPtrGimnasio;

	for(lCQSGPtrGimnasio=CQSLstCompetencias.first();
	    lCQSGPtrGimnasio;
	    lCQSGPtrGimnasio=CQSLstCompetencias.next())
	 QIVCompetencias->insertItem(new QIVItemGrupo(lCQSGPtrGimnasio,QIVCompetencias));
	 */
}
void QCtrlGrupo::IniciaControl()
{
	ConsultaCompetencias();
	MuestraCompetencias();
	ConectaSlots();
}
void QCtrlGrupo::FormateaGrupo(CQSisGrupo *pCQSGrupo,
			       char *pchrPtrFormato)
{
const char *lchrPtrEdadIni;
const char *lchrPtrEdadFin;

lchrPtrEdadIni=!strcmp(pCQSGrupo->SRegistrosPro2["EdadIni"],"-1") ?
	                    "Mas" :
			    pCQSGrupo->SRegistrosPro2["EdadIni"]; 
	    lchrPtrEdadFin=!strcmp(pCQSGrupo->SRegistrosPro2["EdadFin"],"-1") ?
	                    "Mas" :
			    pCQSGrupo->SRegistrosPro2["EdadFin"]; 
	     if(!strcmp(lchrPtrEdadIni,"Mas") &&
	        !strcmp(lchrPtrEdadFin,"Mas"))
		strcpy(pchrPtrFormato,"Opcional");
	      else
	      sprintf(pchrPtrFormato,
	              "%s-%s",
		      lchrPtrEdadIni,
		      lchrPtrEdadFin);


}
int QCtrlGrupo::NumeroFilas(CQSisLstGrupo *pCQSLGrupo,
			   int *pintPtrNumFilas)
{
	if((int )QTDatos->numRows()>(int )pCQSLGrupo->count())
	return 0;
	else
	{
	*pintPtrNumFilas=pCQSLGrupo->count();
	return 1;
	}
	
}
void QCtrlGrupo::ConsultaCompetencias()
{
CQSisOpConsultas lCQSOConsultas(SisDatCom);
SiscomRegistrosPro2 *lSRegistrosPro2;
int lintFila;
int lintColumna=0;
CQSisLstGrupo *lCQSLGrupo;
CQSisGrupo *lCQSGrupo;
const char *lchrPtrColumna;
const char *lchrPtrEdadIni;
const char *lchrPtrEdadFin;
int lintNumFilas;
		CQSLstLstGrupo.clear();
		lCQSOConsultas.ObtenGrupos(
		 CQSCompetencia->SRegistrosPro2["IdTipoCompetencia"],
		 &CQSLstLstGrupo);
	
	QTDatos->setNumCols(CQSLstLstGrupo.count());
	QTDatos->setNumRows(CQSLstLstGrupo.at(0)->count());
	for(lCQSLGrupo=CQSLstLstGrupo.first(),
	    lintColumna=0;
	    lCQSLGrupo;
	    lCQSLGrupo=CQSLstLstGrupo.next(),
	    lintColumna++)
	 {
	   lchrPtrColumna=lCQSLGrupo->at(0)->SRegistrosPro2["Grupo"];
	   QTDatos->horizontalHeader()->setLabel(lintColumna,lchrPtrColumna);
	   if(NumeroFilas(lCQSLGrupo,&lintNumFilas))
	    QTDatos->setNumRows(lintNumFilas);
	   for(lCQSGrupo=lCQSLGrupo->first(),
	       lintFila=0;
	       lCQSGrupo;
	       lCQSGrupo=lCQSLGrupo->next(),
	       lintFila++)
	   {
	    lchrPtrEdadIni=!strcmp(lCQSGrupo->SRegistrosPro2["EdadIni"],"-1") ?
	                    "Mas" :
			    lCQSGrupo->SRegistrosPro2["EdadIni"]; 
	    lchrPtrEdadFin=!strcmp(lCQSGrupo->SRegistrosPro2["EdadFin"],"-1") ?
	                    "Mas" :
			    lCQSGrupo->SRegistrosPro2["EdadFin"]; 
	    if(!strcmp(lchrPtrEdadIni,"Mas") &&
	       !strcmp(lchrPtrEdadFin,"Mas"))
		QTDatos->setText(lintFila,
	    		     lintColumna,
			     "Opcional");
	    else
	    QTDatos->setText(lintFila,
	    		     lintColumna,
			     QString().sprintf("%s-%s",
			     lchrPtrEdadIni,
			     lchrPtrEdadFin));

	   }
	   			

	 }

}
void QCtrlGrupo::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlGrupo::PonCompetencia(CQSisCompetencia *pCQSCompetencia)
{
	CQSCompetencia=pCQSCompetencia;
}
void QCtrlGrupo::ConectaSlots()
{
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionoGrupo(int,int,int,const QPoint &)));
}
void QCtrlGrupo::SlotSeleccionoGrupo(int pintFila,
				     int pintColumna,
				     int,
				     const QPoint &)
{
CQSisGrupo *lCQSGrupo=CQSLstLstGrupo.at(pintColumna)->at(pintFila);

	if(lCQSGrupo)
	emit SignalGrupo(lCQSGrupo);
}
void QCtrlGrupo::setFocus()
{
	
	QIVCompetencias->setFocus();
}
void QCtrlGrupo::LimpiaSeleccion()
{
	QIVCompetencias->clearSelection();
}









QIVItemGrupo::QIVItemGrupo(CQSisGrupo *pCQSClase,
				QIconView *pQIVParent):
		QIconViewItem(pQIVParent),
		CQSClase(pCQSClase)

{
	IniciaVariables();
}
void QIVItemGrupo::IniciaVariables()
{
/*
	setText(CQSGimnasio->SRegistrosPro2["Gimnasio"]);	
*/
}
CQSisGrupo *QIVItemGrupo::ObtenClase()
{
	return CQSClase;
}
