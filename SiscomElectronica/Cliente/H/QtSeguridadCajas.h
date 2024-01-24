#ifndef __QTSEGURIDADCAJAS_H__
#define __QTSEGURIDADCAJAS_H__
#include <qlistview.h>
class CQSisCajaSeguridad;
class SiscomRegistro3;
class QtListViewItemEstadoControl;
class QtListViewItemCaja:public QListViewItem
{
public:
	QtListViewItemCaja(CQSisCajaSeguridad *,
			   QListView *);
private:
	CQSisCajaSeguridad *CQSCajaSeguridad;
};

class QtListViewItemControlCaja:public QListViewItem
{
public:
	QtListViewItemControlCaja(SiscomRegistro3 *,QListViewItem *);
	SiscomRegistro3 *ControlCaja();
private:
	SiscomRegistro3 *SisReg3Control;
	QtListViewItemEstadoControl *QtLstViewItemEdoControl;
private:
	void AgregaEstado();
};

class QtListViewItemEstadoControl:public QListViewItem
{
public:
	QtListViewItemEstadoControl(SiscomRegistro3 *,
				    QListViewItem *);
	SiscomRegistro3 *Control();
private:
	SiscomRegistro3 *SisReg3Control;
};
#endif
