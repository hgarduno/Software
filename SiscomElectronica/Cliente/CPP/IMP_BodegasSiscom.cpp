#include <IMP_BodegasSiscom.h>
#include <QCtrlCmbBodegas.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <SiscomRegistros3.h>



#include <qpushbutton.h>

QBodegasSiscom::QBodegasSiscom(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				BodegasSiscom(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				intAceptar(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QBodegasSiscom::~QBodegasSiscom()
{

}

void QBodegasSiscom::ConectaSlots()
{
connect(QCtrBodegas,
	SIGNAL(SignalSelecciono(SiscomRegistro3 *)),
	SLOT(SlotBodega(SiscomRegistro3 *)));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));
}
void QBodegasSiscom::SlotCancelar()
{

}
void QBodegasSiscom::SlotAceptar()
{
	intAceptar=1;
     done(1); 
}
void QBodegasSiscom::SlotBodega(SiscomRegistro3 *pSisReg3Bodega)
{
    SisReg3Bodega=pSisReg3Bodega;
    zSiscomQt3::Foco(QPBAceptar);
    SiscomContenidoRegistro3(SisReg3Bodega);
}
void QBodegasSiscom::IniciaVariables()
{
QCtrBodegas->Servidor(SisDatCom);
QCtrBodegas->Expendio(chrPtrArgumentos[0]);
QCtrBodegas->IniciaControl();
}


int QBodegasSiscom::Aceptar()
{
   return intAceptar;

}
SiscomRegistro3 *QBodegasSiscom::Bodega()
{
    return SisReg3Bodega;
}

