#include <IMP_RegistrarEntrega.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlClientes.h>
#include <CQSisClientes.h>
#include <CQSisPedidos.h>
#include <SisPersonas.h>
QRegistrarEntrega *InstanciaRegistrarEntrega(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegistrarEntrega((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegistrarEntrega::QRegistrarEntrega(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegistrarEntrega(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QRegistrarEntrega::~QRegistrarEntrega()
{

}

void QRegistrarEntrega::ConectaSlots()
{
/*
connect(QCClientes,
	SIGNAL(SignalFisica(CQSisCliente *)),
	SLOT(SlotClienteFisica(CQSisCliente *)));
*/
connect(QPBRegistra,
	SIGNAL(clicked()),
	SLOT(SlotRegistra()));
connect(QTDatos,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionandoPedido(int,int,int,const QPoint &)));
}
void QRegistrarEntrega::SlotSeleccionandoPedido(int pintNFila,
						int ,
						int ,
						const QPoint &)
{
if(pintNFila!=-1)
{
QTDatos->selectRow(pintNFila);
CQSPedido=CQSLPedidos.at(pintNFila);
}
}
void QRegistrarEntrega::SlotRegistra()
{
CQSisOpPedido lCQSOPedido(SisDatCom);
CQSPedido->SiscomActualizaCampo("Observaciones",
				SiscomObtenInformacionDelEdit(QTEComentario));
lCQSOPedido.PedidoEntregado(CQSPedido);


}
void QRegistrarEntrega::SlotClienteFisica(CQSisCliente *pCQSCliente)
{
	CQSCliente=pCQSCliente;
	ConsultandoPedidos();
}
const char *QRegistrarEntrega::IdCliente()
{
SisPersona *lSPersona=CQSCliente->Persona();
SiscomLog("%s",(*lSPersona)["IdPersona"]);
return (*lSPersona)["IdPersona"];
}
void QRegistrarEntrega::IniciaVariables()
{
/*
QCClientes->PonServidor(SisDatCom);
QCClientes->IniciaControl(); 
*/
}
void QRegistrarEntrega::ConsultandoPedidos()
{
	ConsultaPedidos();
	MuestraPedidos();
}
void QRegistrarEntrega::ConsultaPedidos()
{
CQSisOpPedido lCQSOPedido(SisDatCom);
lCQSOPedido.Pedidos(CQSCliente,&CQSLPedidos);
}
void QRegistrarEntrega::MuestraPedidos()
{
int lintContador;
CQSisPedido *lCQSPedido;
QTDatos->setNumRows(CQSLPedidos.count());

for(lintContador=0,
    lCQSPedido=CQSLPedidos.first();
    lCQSPedido;
    lintContador++,
    lCQSPedido=CQSLPedidos.next())
SiscomAnexarRegistroALaTabla(
		lintContador,
		QTDatos,
		QStringList() 			  	<< 
		(*lCQSPedido)["Fecha"]			<<
		(*lCQSPedido)["Importe"]		<<
		(*lCQSPedido)["IdPedido"]);
}

void QRegistrarEntrega::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
