#include <IMP_VentasPedidos.h>
#include <IMP_IntroduceDatos.h>
#include <IMP_BuscarClientes.h>
#include <IMP_QControlFecha.h>
#include <CQSiscomCom.h>
#include <SISCOMComunicaciones++.h>
#include <Productos.h>
#include <Personas.h>
#include <Empresas.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qmessagebox.h>

QVentasPedidos *InstanciaVentasPedidos(void *pCSisDatCom,
				       void *pQWParent,
				       const char *pchrPtrName,
				       int pintWFlags)
{
	return new QVentasPedidos((CSISCOMDatComunicaciones *)pCSisDatCom,
				  (QWidget *)pQWParent,
				  pchrPtrName,
				  pintWFlags);
}
QVentasPedidos::QVentasPedidos(CSISCOMDatComunicaciones *pCSisDatCom,
				QWidget* parent,
				const char* name,
				WFlags fl )
    : VentasPedidos( parent, name, fl ),
    CSisDatCom(pCSisDatCom),
    QWParent(parent),
    intModificarDatos(1),
    intModificarPrecio(1)
{
	IniciaVariables();
	ConectaSlots();
}

QVentasPedidos::~QVentasPedidos()
{
}
void QVentasPedidos::IniciaVariables()
{

	QLECProductos=ColocaLineEditAlCombo(QCBProductos,"QLECProductos");
	QLECNmbTipoPrecio=ColocaLineEditAlCombo(QCBTipoPrecio,"QLECNmbTipoPrecio");
	if(!(CQPVendedor=ObtenDatosUsuarioFirmado(CSisDatCom)))
	QMessageBox::information(this,
			      "Sistema El Fresno",
			      "El Usuario NO tiene una firma en la base del sistema");
	CQSProducto=new CQSeleccionaProducto(CSisDatCom,
					     QWParent,
					     "CQSProducto",
					     QLECProductos,
					     QLEDescripcion,
					     QLEUnidades,
					     QCBProductos);
	CQSTPrecio=new CQSeleccionaTipoPrecio(CSisDatCom,
					     QWParent,
					     "CQSProducto",
					     QLECNmbTipoPrecio,
					     QLEDescripcion,
					     QCBTipoPrecio);
	QCFechaEntrega->ColocaFechaHoy();
	HabilitaDesHabilitaControles("%W0%W0",
				     QPBROperacion,
				     QPBAnexar);
	
					     
}
void QVentasPedidos::PonModificarDatos(int pintModificarDatos)
{
	intModificarDatos=pintModificarDatos;
	QPBROperacion->setEnabled(pintModificarDatos);
}
void QVentasPedidos::PonModificarPrecio(int pintModificarPrecio)
{
	intModificarPrecio=pintModificarPrecio;
}
void QVentasPedidos::ConectaSlots()
{
	connect(QPBSCliente,
		SIGNAL(clicked()),
		SLOT(S_SeleccionaCliente()));
	connect(QLECProductos,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoCantidad()));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(S_CotizaProducto()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_AnexarProductoYCotiza()));
	connect(CQSTPrecio,
		SIGNAL(Signal_STipoPrecio(TipoPrecio *)),
		SLOT(S_TipoPrecio(TipoPrecio *)));
	connect(QPBPEnGeneral,
		SIGNAL(clicked()),
		SLOT(S_PublicoEnGeneral()));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(S_EliminarProducto()));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(S_SeleccionoProducto(int,int,int,const QPoint &)));

	connect(QLECCliente,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoTipoPrecio()));
	connect(QLECNmbTipoPrecio,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoFechaEntrega()));
}
void QVentasPedidos::S_PasaFocoTipoPrecio()
{
	PasaFocoControl(QLECNmbTipoPrecio);	
}
void QVentasPedidos::CambiaCantidad(int pintNFila)
{

QIntroduceDatos lQIDatos("Cantidad","Modifica Cantidad");

		if(lQIDatos.ObtenBoton()==QIntroduceDatos::Aceptar)
		{
		     CQPCotizacion.at(pintNFila)->PonCantidad((const char *)lQIDatos.ObtenDato());
		     CotizaProductos();
		}

}
void QVentasPedidos::CambiaPrecio(int pintNFila)
{
QIntroduceDatos lQIDatos("Precio","Modifica Precio");
ProductoCotizacion *lP_PCotizacion;
		if(lQIDatos.ObtenBoton()==QIntroduceDatos::Aceptar)
		{
		     CQPrecios lCQPrecios;
		     CQCtrPrecios lCQCPrecios(CSisDatCom,
				     	      QStringList() <<
					      QString("ActualizaPrecio") <<
					      TTPrecio->ObtenNmbTipoPrecio() <<
					      CQPersona->ObtenIdPersona() <<
					      (const char *)lQIDatos.ObtenDato() <<
					      CQPCotizacion.at(pintNFila)->ObtenProducto()->ObtenClave(),
					      &lCQPrecios);
		     CotizaProductos();
		}
}
void QVentasPedidos::S_SeleccionoProducto(int pintNFila,
					  int pintNColumna,
					  int,
					  const QPoint &)
{
	if(pintNFila!=-1)
	switch(pintNColumna)
	{
	  case 1:
		  if(intModificarDatos)
		  CambiaCantidad(pintNFila);
	  break;
	  case 2:
	  	 if(intModificarPrecio)
	  	  CambiaPrecio(pintNFila);
	  break;
	}
}
void QVentasPedidos::S_EliminarProducto()
{
int lintContador;
	for(lintContador=0;
	    lintContador<QTDatos->numRows();
	    lintContador++)
	{
	    if(QTDatos->isRowSelected(lintContador))
	    {
	    CQPCotizacion.remove(lintContador);
	    CotizaProductos();
	    return;
	   }
	}
	QMessageBox::information(this,"Sistema El Fresno","No se ha seleccionado un Producto");

}
void QVentasPedidos::S_PublicoEnGeneral()
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
CQPersona=lCQPersonas.at(0);
	if(CQPersona)
	{
	  QLECliente->setText(QString() 		  +
			       CQPersona->ObtenNombre()   +
			       " "			  +
			       CQPersona->ObtenAPaterno() +
			       " "			  +
			       CQPersona->ObtenAMaterno() );
	PasaFocoControl(QLECCliente->isEnabled() ? QLECCliente : QLECNmbTipoPrecio);

	}
	

}
void QVentasPedidos::S_TipoPrecio(TipoPrecio *pTPrecio)
{
	if((TTPrecio=pTPrecio))
	{
	CotizaProductos();
		HabilitaDesHabilitaControles("%W1%W1",
				     QPBAnexar,
				     QLECantidad);
	   PasaFocoControl(QLECProductos);
	}

	
}
void QVentasPedidos::QuitaPreciosCotizacion()
{
ProductoCotizacion *lPCotizacion;

	for(lPCotizacion=CQPCotizacion.first();
	    lPCotizacion;
	    lPCotizacion=CQPCotizacion.next())
	 lPCotizacion->ObtenProducto()->PonPrecio(0,"");

}
void QVentasPedidos::CotizaProductos()
{
if(CQPCotizacion.count())
{
ProductoCotizacion *lP_PCotizacion;
Precio *lP_Precio;
CQPrecios lCQPrecios;
int lintContador;
QuitaPreciosCotizacion();
CQCtrCotizacion lCQCotizacion(CSisDatCom,
			      CQCtrCotizacion::Cotiza,
			      CQPersona->ObtenIdPersona(),	
			      TTPrecio->ObtenNmbTipoPrecio(),
			      E_Expendio->ObtenIdEmpresa(),
			      &CQPCotizacion);
	QTDatos->setNumRows(CQPCotizacion.count());
	for(lP_PCotizacion=CQPCotizacion.first(),
	    lintContador=0;
	    lP_PCotizacion;
	    lP_PCotizacion=CQPCotizacion.next(),
	    lintContador++)
	{
	lCQPrecios=lP_PCotizacion->ObtenProducto()->ObtenPrecios();
	lP_Precio=lCQPrecios.at(0);
	SISCOMAnexarRegistroALaTabla(lintContador,
			QTDatos,
			QStringList() <<
			     lP_PCotizacion->ObtenProducto()->ObtenClave()<<
			     lP_PCotizacion->ObtenCantidad() <<
			     lP_Precio->ObtenPrecio()	     <<
			     lP_PCotizacion->ObtenImporte() );
	}
	
		
	QLCNTotal->display(QString(CQPCotizacion.ObtenImporteTotal()));
}
}
void QVentasPedidos::S_AnexarProductoYCotiza()
{
	CQPCotizacion.append(P_PCotizacion);
	CotizaProductos();
	PasaFocoControl(QLECProductos);
		HabilitaDesHabilitaControles("%W1",
				     QPBROperacion);


}
void QVentasPedidos::EliminaProductosCotizacion()
{
	CQPCotizacion.clear();
	QTDatos->setNumRows(0);
		HabilitaDesHabilitaControles("%W0%W0%W0",
				     QPBROperacion,
				     QPBAnexar,
				     QLECantidad);
}
void QVentasPedidos::S_CotizaProducto()
{
		P_PCotizacion=new ProductoCotizacion(
			new Producto(
				      strdup((const char *)QLECProductos->text()),
				      ""),
				      strdup((const char *)QLECantidad->text()),
							"",
							"",
							"");
CQProductosCotizacion lCQPCotizacion;

		lCQPCotizacion.append(P_PCotizacion);
CQCtrCotizacion lCQCotizacion(CSisDatCom,
			      CQCtrCotizacion::Cotiza,
			      CQPersona->ObtenIdPersona(),
			      TTPrecio->ObtenNmbTipoPrecio(),
			      E_Expendio->ObtenIdEmpresa(),
			      &lCQPCotizacion);
		
	QLCNTotal->display(QString(lCQPCotizacion.ObtenImporteTotal()));
	QLEExistencia->setText(lCQPCotizacion.at(0)->ObtenExistencia());
	QPBAnexar->setEnabled(!strcmp(lCQPCotizacion.at(0)->ObtenSePuedeVender(),
				      "Si"));
	PasaFocoControl(QPBAnexar);
}
void QVentasPedidos::S_PasaFocoAnexar()
{
	PasaFocoControl(QPBAnexar);
}
void QVentasPedidos::S_PasaFocoCantidad()
{
	PasaFocoControl(QLECantidad);
}
void QVentasPedidos::S_PasaFocoContactoCliente()
{
	PasaFocoControl(QLECCliente);

}
void QVentasPedidos::S_PasaFocoFechaEntrega()
{
	if(QCFechaEntrega->isEnabled())
	{
	PasaFocoControl(QCFechaEntrega);
	connect(QCFechaEntrega,
		SIGNAL(Signal_EnterA_o()),
		SLOT(S_PasaFocoProducto()));
	}
	else
	PasaFocoControl(QLECProductos );
}
void QVentasPedidos::S_PasaFocoProducto()
{
	PasaFocoControl(QLECProductos);
}
void QVentasPedidos::S_SeleccionaCliente()
{
QBuscarClientes lQBClientes(CSisDatCom);
        if(lQBClientes.ObtenSeleccion()==QBuscarClientes::Aceptar)
	{
	   CQPersona=lQBClientes.ObtenPersona();
	   MuestraDatosCliente();
		PasaFocoControl(QLECCliente->isEnabled() ? QLECCliente :QLECNmbTipoPrecio);

	}
}
void QVentasPedidos::MuestraDatosCliente()
{
	   QLECliente->setText(QString() 		  +
			       CQPersona->ObtenNombre()   +
			       " "			  +
			       CQPersona->ObtenAPaterno() +
			       " "			  +
			       CQPersona->ObtenAMaterno() );

}
void QVentasPedidos::PonExpendio(Empresa *pEMatriz)
{
	setCaption(pEMatriz->ObtenRazonSocial());
	E_Expendio=pEMatriz;
}
Empresa *QVentasPedidos::ObtenExpendio()
{
	return E_Expendio;
}
const CQProductosCotizacion &QVentasPedidos::ObtenProductos()
{
	return CQPCotizacion;

}
CQ_Persona *QVentasPedidos::ObtenCliente()
{
	return CQPersona;
}
void QVentasPedidos::AsignaProductos(CQProductosCotizacion pCQPCotizacion,
				     CQ_Persona *pCQPCliente)
{
Precio *lP_Precio;
CQPrecios lCQPrecios;
	CQPCotizacion=pCQPCotizacion;
	lCQPrecios=pCQPCotizacion.at(0)->ObtenProducto()->ObtenPrecios();
	lP_Precio=lCQPrecios.at(0);
	TTPrecio=lP_Precio->ObtenTipoPrecio();
	CQPersona=pCQPCliente;
	MuestraDatosCliente();

	CotizaProductos();
}
CQ_Persona *QVentasPedidos::ObtenUsuario()
{
	return CQPVendedor;
}
