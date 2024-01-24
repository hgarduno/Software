#include <IMP_SIN_UI_MenuOperaciones.h>
#include <qaction.h>

#include <SISCOMComunicaciones++.h>

CQSisMOperaciones::CQSisMOperaciones(const QPoint &pQPPosicion,
				     QWidget *pQWParent,
				     const char *pchrPtrNmb):
		  QPPosicion(pQPPosicion),
		  QPopupMenu(pQWParent,pchrPtrNmb),
		  QWParent(pQWParent)
{
	CreaMenu();
	popup(pQPPosicion);
}

void CQSisMOperaciones::CreaMenu()
{

	CreaOpcionMenu("Cabecera",
			     "QACabecera",
			     0)->addTo(this);
	insertSeparator();
	CreaOpcionMenu("Crear Objeto En Tiempo Ejecucion",
			     "QAObjTEj",
			     SLOT(SlotAnexaObjTEjecucion()))->addTo(this);

	CreaOpcionMenu("Alguna Otra Chachara",
			     "QAObjEObjTEj",
			     SLOT(SlotEliminaObjTEjecucion()))->addTo(this);
			     
}
void CQSisMOperaciones::SlotAnexaObjTEjecucion()
{
	emit SignalAnexaObjeto();	
}
void CQSisMOperaciones::SlotEliminaObjTEjecucion()
{
	emit SignalEliminaObjeto();
}
QAction *CQSisMOperaciones::CreaOpcionMenu(const char *pchrPtrTexto,
					   const char *pchrPtrName,
					   const char *pchrPtrSlot)
{
QAction *lQAOpcion=new QAction(QWParent,pchrPtrName);

	lQAOpcion->setText(pchrPtrTexto);
	if(pchrPtrSlot)
	connect(lQAOpcion,
		SIGNAL(activated()),
		pchrPtrSlot);

	return lQAOpcion;	

}

