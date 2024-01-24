#include <QCtrlCuentaDinero.h>
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>

#include <qlayout.h>
#include <qcombobox.h>

QCtrlCuentaDinero::QCtrlCuentaDinero(QWidget *pQWParent,
				const char *pchrPtrName):
			QWidget(pQWParent,pchrPtrName)
{
IniciaVariables();
ConectaSlots();

}
void QCtrlCuentaDinero::IniciaVariables()
{

QHBLayout=new QHBoxLayout(this);
QHBLayout->setMargin(0);
QTCuDinero=new QTable(this);
QHBLayout->addWidget(QTCuDinero);

}
void QCtrlCuentaDinero::Servidor(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
} 
void QCtrlCuentaDinero::IniciaControl()
{
}
void QCtrlCuentaDinero::ConectaSlots()
{

}




void QCtrlCuentaDinero::setFocus()
{
}

