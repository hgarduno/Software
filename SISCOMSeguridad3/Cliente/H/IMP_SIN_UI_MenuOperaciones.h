#ifndef __IMP_SIN_UI_MENUOPERACIONES__
#define __IMP_SIN_UI_MENUOPERACIONES__
#include <qpopupmenu.h>
class QAction;
class CQSisMOperaciones:public QPopupMenu
{
	Q_OBJECT 
	public:
		CQSisMOperaciones(const QPoint &,QWidget *,const char *);

	private:
		QPoint QPPosicion;
		QAction *QACabecera;
		QAction *QAObjTEj;
		QAction *QAObjEObjTEj;
		QWidget *QWParent;
	private:
		void CreaMenu();
		QAction *CreaOpcionMenu(const char *,const char *,const char *);
	private slots:
		void SlotAnexaObjTEjecucion();
		void SlotEliminaObjTEjecucion(); 
signals:
	void SignalAnexaObjeto();
	void SignalEliminaObjeto();
};


#endif
