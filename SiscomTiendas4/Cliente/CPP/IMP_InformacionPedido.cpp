#include <IMP_InformacionPedido.h>
#include<SISCOMComunicaciones++.h>
#include <CQSisPedidos.h>
#include <CQSisEmpleados.h>
QInformacionPedido::QInformacionPedido(const char *pchrPtrNoPedido,
				    SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				InformacionPedido(pQWParent,
						  pchrPtrName,
						  pbModal,
						  pWFlags),
				chrPtrNoPedido(pchrPtrNoPedido),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QInformacionPedido::~QInformacionPedido()
{

}

void QInformacionPedido::ConectaSlots()
{
connect(QPBRegistra,
	SIGNAL(clicked()),
	SLOT(SlotRegistra()));

}
void QInformacionPedido::SlotRegistra()
{
Registra();
done(1);
}
void QInformacionPedido::IniciaVariables()
{
QLENoPedido->setText(chrPtrNoPedido);
/*
CQSEmpleado=(CQSisEmpleado *)chrPtrArgumentos[1];

*/
}

void QInformacionPedido::Registra()
{
CQSisOpPedido lCQSOPedido(SisDatCom);
lCQSOPedido.Registra(Pedido());
}
CQSisPedido *QInformacionPedido::Pedido()
{
return new CQSisPedido(chrPtrNoPedido,
		       "1",
		       "",
		       SiscomObtenInformacionDelEdit(QTEComentarios),
		       "",
		       "");
}
