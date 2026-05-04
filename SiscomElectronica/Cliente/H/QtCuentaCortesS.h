#ifndef __QTCUENTACORTESS_H__
#define __QTCUENTACORTESS_H__

#include <UIC_H_CuentaCortes.h>


class QtCuentaCortesS:public CuentaCortes
{
Q_OBJECT
public:
	QtCuentaCortesS(QWidget *,const char *,WFlags);
private:
	void ConectaSlots();
	virtual void SeleccionaExpendio();

private slots:
	void SlotExpendio();


};

#endif
