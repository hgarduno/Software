#include <QtSeguridadCajas.h>
#include <CQSisSeguridadCajaVentas.h>
#include <SiscomRegistros3.h>
QtListViewItemCaja::QtListViewItemCaja(CQSisCajaSeguridad *pCQSCSeguridad,
					QListView *pQLisViewCaja):
			QListViewItem(pQLisViewCaja),
			CQSCajaSeguridad(pCQSCSeguridad)
{
	setText(0,CQSCajaSeguridad->Caja());
}

QtListViewItemControlCaja::QtListViewItemControlCaja(SiscomRegistro3 *pSisReg3Control,
						     QListViewItem *pQListViewItemCaja):
			QListViewItem(pQListViewItemCaja),
			SisReg3Control(pSisReg3Control)
{

		setText(0,(*SisReg3Control)["nombreqt"]);
		AgregaEstado();
}
SiscomRegistro3 *QtListViewItemControlCaja::ControlCaja()
{
	return SisReg3Control;
}
void QtListViewItemControlCaja::AgregaEstado()
{
QtLstViewItemEdoControl=new QtListViewItemEstadoControl(SisReg3Control,this);
insertItem(QtLstViewItemEdoControl);
}
QtListViewItemEstadoControl::QtListViewItemEstadoControl(
				SiscomRegistro3 *pSisReg3Control,
				QListViewItem *pQLstViewItemControl):
			QListViewItem(pQLstViewItemControl),
			SisReg3Control(pSisReg3Control)
{

	setText(0,(*SisReg3Control)["estado"]);

}

SiscomRegistro3 *QtListViewItemEstadoControl::Control()
{
return SisReg3Control;
}
