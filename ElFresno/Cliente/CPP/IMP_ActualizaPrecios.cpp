#include <IMP_ActualizaPrecios.h>
#include <IMP_BuscarClientes.h>
#include <CQSiscomCom.h>

#include <qvariant.h>
#include <qlabel.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QActualizaPrecios::QActualizaPrecios(CSISCOMDatComunicaciones *pCSisDatCom,
				     Producto *pProducto,
				     const char *pchrPtrPrecio,
	 			     QWidget* parent,
				     const char* name,
				     bool modal,
				     WFlags fl )
    : ActualizaPrecios( parent, name, modal, fl ),
       CSisDatCom(pCSisDatCom),
	chrPtrPrecio(pchrPtrPrecio),
	PProducto(pProducto)
{
	IniciaVariables();
	ConectaSlots();
	exec();
}

QActualizaPrecios::~QActualizaPrecios()
{
}
void QActualizaPrecios::IniciaVariables()
{
	LlenaComboTiposPrecios();
	setCaption(PProducto->ObtenDescripcion());
	
}
QActualizaPrecios::BTN_Botones QActualizaPrecios::ObtenSeleccion()
{
	return BTN_Seleccion;
}
void QActualizaPrecios::ConectaSlots()
{
	connect(QPBSCliente,
		SIGNAL(clicked()),
		SLOT(S_SeleccionaCliente()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
	connect(QPBPEnGeneral,
		SIGNAL(clicked()),
		SLOT(S_SeleccionaPublicoEnGeneral()));
}
void QActualizaPrecios::S_SeleccionaPublicoEnGeneral()
{
	CQ_Personas lCQPersonas;
        CQCtrPersonas lCQCPersonas(CSisDatCom,
                           QStringList() <<
                           "ConsultarPersonas"     <<
                           ""                      <<
                           "GENERAL"               <<
                           ""                      <<
                           ""                      <<
                           "",
                           &lCQPersonas);
	CQPersonas.append(lCQPersonas.at(0));
	MuestraYAsignaPrecios();
	
	BTN_Seleccion=QActualizaPrecios::Aceptar;
	
}
void QActualizaPrecios::S_Aceptar()
{
	BTN_Seleccion=QActualizaPrecios::Aceptar;
	done(1);

}
void QActualizaPrecios::S_SeleccionaCliente()
{
QBuscarClientes lQBClientes(CSisDatCom);
	if(lQBClientes.ObtenSeleccion()==QBuscarClientes::Aceptar)
	{
	   CQPersonas=lQBClientes.ObtenPersonas();
	   MuestraYAsignaPrecios();
	}
	QPBSCliente->setEnabled(false);
}
void QActualizaPrecios::MuestraYAsignaPrecios()
{
CQ_Persona *lCQPersona;
	for(lCQPersona=CQPersonas.first();
	    lCQPersona;
	    lCQPersona=CQPersonas.next())
	{
	AnexarRegistroALaTabla(QTDatos,
			 QStringList () <<
			 chrPtrPrecio <<
			 lCQPersona->ObtenNombre() <<
			 QCBTiposPrecios->currentText() );
	AnexaPrecio(lCQPersona);
	}
			 
			 	


}
void QActualizaPrecios::AnexaPrecio(CQ_Persona *pCQPersona)
{
Precio *lP_Precio;
		lP_Precio=new Precio("",
				     "",
				     chrPtrPrecio,
				     CQ_TiposPrecios.at(QCBTiposPrecios->currentItem()));

		lP_Precio->PonPersona(pCQPersona);
		CQPPrecios.append(lP_Precio);
		PProducto->AnexaPrecio(lP_Precio);
				     
}
void QActualizaPrecios::LlenaComboTiposPrecios()
{
CQCtrTiposPrecios lCQCTPrecios(CSisDatCom,
                               CQCtrTiposPrecios::Consultar,
                               &CQ_TiposPrecios);
TipoPrecio *lT_TipoPrecio;

        for(lT_TipoPrecio=CQ_TiposPrecios.first();
            lT_TipoPrecio;
            lT_TipoPrecio=CQ_TiposPrecios.next())
         QCBTiposPrecios->insertItem(lT_TipoPrecio->ObtenDescripcion());

}
