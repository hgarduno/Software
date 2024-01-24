#ifndef _CQSISPRUEBASGUI_H__
#define _CQSISPRUEBASGUI_H__

#include <UIC_H_PruebaGUI.h>
#include <qpopupmenu.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QAction;
class CSISCOMDatComunicaciones;

class CQSisPruebasGUI : public PruebasGUI
{
    Q_OBJECT

public:
    CQSisPruebasGUI(CSISCOMDatComunicaciones *,
		    QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CQSisPruebasGUI();
private:
	CSISCOMDatComunicaciones *CSisDatCom;
private slots:
	void SlotMuestraMenu(int ,int ,const QPoint &);
};

class CQSisMenuPrueba:public QPopupMenu
{
	Q_OBJECT 
	public:
		CQSisMenuPrueba(QWidget *,
				const QPoint &,
				CSISCOMDatComunicaciones *);
private:

	QAction *QAPrueba1;
	QAction *QAPrueba2;
	QAction *QAPrueba3;
	QAction *QAPrueba4;
	CSISCOMDatComunicaciones *CSisDatCom;
private:
	QAction *CreaOpcionMenu(const char *,const char *,const char *pchrPtrSlot=0);
	void CreaMenu();
	void AsignaPermisos();


};
#endif 
