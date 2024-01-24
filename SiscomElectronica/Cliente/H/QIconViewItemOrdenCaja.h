#ifndef __QICONVIEWITEMORDENCAJA_H__
#define __QICONVIEWITEMORDENCAJA_H__
#include <qiconview.h>

class SiscomRegistro3;
class QIconViewItemOrdenCaja:public QIconViewItem
{
public:
	QIconViewItemOrdenCaja(SiscomRegistro3 *,
			       SiscomRegistro3 *,
			       QIconView *pQIVOrdenes);
	SiscomRegistro3 *Orden();
	SiscomRegistro3 *Cliente();

private:
private:
	SiscomRegistro3 *SisReg3Orden;
	SiscomRegistro3 *SisReg3Cliente;

};

#endif
