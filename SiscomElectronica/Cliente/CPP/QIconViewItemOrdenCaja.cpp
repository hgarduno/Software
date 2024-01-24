#include <QIconViewItemOrdenCaja.h>
#include <SiscomRegistros3.h>
QIconViewItemOrdenCaja::QIconViewItemOrdenCaja(SiscomRegistro3 *pSisReg3Orden,
					       SiscomRegistro3 *pSisReg3Cliente,
					       QIconView *pQIVOrdenes):
					QIconViewItem(pQIVOrdenes),
					SisReg3Orden(pSisReg3Orden),
					SisReg3Cliente(pSisReg3Cliente)
{
setText(QString().sprintf("Orden:%s Escuela:%s Fecha:%s Total:%s",
			 (*SisReg3Orden)["idventa"],
			 (*SisReg3Orden)["nombre"],
			 (*SisReg3Orden)["fecha"],
			 (*SisReg3Orden)["total"]));
}

SiscomRegistro3 *QIconViewItemOrdenCaja::Orden()
{
return SisReg3Orden;
}
SiscomRegistro3 *QIconViewItemOrdenCaja::Cliente()
{
return SisReg3Cliente;
}

