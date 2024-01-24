#include <IMP_ManejadorPrecios.h>
#include <IMP_ActualizaPrecios.h>
#include <IMP_IntroduceDatos.h>
#include <IMP_BuscarClientes.h>
#include <CQSiscomCom.h>
#include <SISCOMComunicaciones++.h>
#include <Productos.h>

#include <qmessagebox.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

QManejadorPrecios *InstanciaManejadorPrecios(void *pCSisDatCom,
					     void *pQWParent,
					     const char *pchrPtrName,
					     int pintWFlags)
{
	return new QManejadorPrecios((CSISCOMDatComunicaciones *)pCSisDatCom,
				     (QWidget *)pQWParent,
				     pchrPtrName,
				     pintWFlags);
}
QManejadorPrecios::QManejadorPrecios(
		CSISCOMDatComunicaciones *pCSisDatCom, 
		QWidget* parent, 
		const char* name, 
		WFlags fl )
    : ManejadorPrecios( parent, name, fl ),
    CSisDatCom(pCSisDatCom),
	QWParent(parent),
	QSiscomSeguridad3((ManejadorPrecios *)this,
			  pCSisDatCom,
			  getenv("Aplicacion"),
			  pCSisDatCom->ObtenUsuario(),
			  ""),
	CQPCliente(0),
	P_Producto(0)
{
	IniciaVariables();
	ConectaSlots();
}

QManejadorPrecios::~QManejadorPrecios()
{
}
void QManejadorPrecios::IniciaVariables()
{
	QLECProductos=ColocaLineEditAlCombo(QCBProductos,
					    "QLECProductos");
	QLECProductos->setEnabled(false);
	CQSProducto=new CQSeleccionaProducto(CSisDatCom,
					     QWParent,
					     "CQSProducto",
					     QLECProductos,
					     QLEDescripcion,
					     QLEAbreviatura,
					     QCBProductos); 
	connect(CQSProducto,
		SIGNAL(Signal_SProducto(Producto *)),
		SLOT(S_SProducto(Producto *)));
					 
	HabilitaDesHabilitaControles("%W0%W0%W1%W0",
					QPBAnexar,
					QPBMPrecio,
					QPBRegistrar,
					QPBAsignarPrecios);

}
void QManejadorPrecios::ConectaSlots()
{
	connect(QLEPrecio,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexarPrecio()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_AnexarPrecio()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_Registrar()));
	connect(QPBMPrecio,
		SIGNAL(clicked()),
		SLOT(S_ModificarPrecio()));
	connect(QPBAsignarPrecios,
		SIGNAL(clicked()),
		SLOT(S_AsignarPreciosAProductos()));
	connect(QPBAPDCliente,
		SIGNAL(clicked()),
		SLOT(S_AsignaPreciosDefaultAlCliente()));
	connect(QPBSCliente,
		SIGNAL(clicked()),
		SLOT(S_SCliente()));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionandoProducto(int,int,int,const QPoint &)));

}
void QManejadorPrecios::SlotSeleccionandoProducto(int pintNFila,
						  int,
						  int,
						  const QPoint &)
{
QTDatos->selectRow(pintNFila);
}
void QManejadorPrecios::S_SCliente()
{
QBuscarClientes lQBCliente(CSisDatCom);
		if(lQBCliente.ObtenSeleccion()==QBuscarClientes::Aceptar)
		{
		CQPCliente=lQBCliente.ObtenPersona();	
		CQPrecios lCQPrecios;
		setCaption(QString("Manejador De Precios:") +
			   " "+
			   CQPCliente->ObtenNombre() +
			   " " +
			   CQPCliente->ObtenAPaterno() +
			   " " +
			   CQPCliente->ObtenAMaterno());
		QLECProductos->setEnabled(true);
		ConsultaPreciosDelProducto(); 
		}
}
void QManejadorPrecios::BuscaCliente()
{
if(!CQPCliente)
{
	QBuscarClientes lQBCliente(CSisDatCom);
	if(lQBCliente.ObtenSeleccion()==QBuscarClientes::Aceptar)
	{
   		CQPCliente=lQBCliente.ObtenPersona();	
	}
}

}
void QManejadorPrecios::S_AsignaPreciosDefaultAlCliente()
{
BuscaCliente();	
		CQPrecios lCQPrecios;
		CQCtrPrecios lCQCPrecios(CSisDatCom,
					 QStringList() <<
			 		"AsignaPreciosALClienteDeGeneral" <<
			 		CQPCliente->ObtenIdPersona(),
			 		&lCQPrecios);
		ConsultaPreciosDelProducto();
		setCaption(QString("Manejador De Precios:") +
			   " "+
			   CQPCliente->ObtenNombre() +
			   " " +
			   CQPCliente->ObtenAPaterno() +
			   " " +
			   CQPCliente->ObtenAMaterno());
}
void QManejadorPrecios::S_AsignarPreciosAProductos()
{
CQPrecios lCQPrecios;
CQCtrPrecios lCQCPrecios(CSisDatCom,
			QStringList() <<
			"AsignaPreciosALosProductosGeneral" <<
			 "",
			 &lCQPrecios);
}
void QManejadorPrecios::S_ModificarPrecio()
{
CQPrecios lCQPrecios=P_Producto->ObtenPrecios();
if(QTDatos->currentRow()!=-1)
{
QIntroduceDatos lQIDatos("Introduce Precio",
			 "Cambia El Precio");
	if(lQIDatos.ObtenBoton()==QIntroduceDatos::Aceptar)
	{
	lCQPrecios.at(QTDatos->currentRow())->PonEdoRegistro("2");
	lCQPrecios.at(QTDatos->currentRow())->PonPrecio((const char *)lQIDatos.ObtenDato());
	QTDatos->setText(QTDatos->currentRow(),1,lQIDatos.ObtenDato());
	S_Registrar();
	}
}
else
{
QMessageBox::information(this,"Sistema El Fresno","No se ha seleccionado un precio");
PasaFocoControl(QLECProductos);
}
	

}
void QManejadorPrecios::S_Registrar()
{
CQPrecios lCQPrecios=P_Producto->ObtenPrecios();
CQCtrPrecios lCQCPrecios(CSisDatCom,
			 CQCtrPrecios::Registrar,
			 P_Producto->ObtenClave(),
			 &lCQPrecios);
 ConsultaPreciosDelProducto();
}
void QManejadorPrecios::S_PasaFocoAnexarPrecio()
{
	PasaFocoControl(QPBAnexar);
}
void QManejadorPrecios::S_SProducto(Producto *pProducto)
{
	P_Producto=pProducto;
	 PasaFocoControl(QLEPrecio);
	ConsultaPreciosDelProducto();

	HabilitaDesHabilitaControles("%W1%W1",QPBAnexar,QPBMPrecio);
	

}
void QManejadorPrecios::S_AnexarPrecio()
{
QActualizaPrecios lCQAPrecios(CSisDatCom,
			      P_Producto,
			      strdup(QLEPrecio->text()));
MuestraPrecios(P_Producto->ObtenPrecios());
}
void QManejadorPrecios::MuestraPrecios(CQPrecios pCQPrecios)
{
Precio *lP_Precio;
int lintContador;
	QTDatos->setNumRows(pCQPrecios.count());
		for(lP_Precio=pCQPrecios.first(),
		    lintContador=0;
		    lP_Precio;
		    lP_Precio=pCQPrecios.next(),
		    lintContador++)
		 SISCOMAnexarRegistroALaTabla(lintContador,
				 	QTDatos,
				 	QStringList() <<
					P_Producto->ObtenClave() <<
					lP_Precio->ObtenPrecio () <<
					QString(lP_Precio->ObtenPersona()->ObtenNombre())  +
					" " 					  +
					lP_Precio->ObtenPersona()->ObtenAPaterno() +
					" "					   +
					lP_Precio->ObtenPersona()->ObtenAMaterno() <<
					lP_Precio->ObtenTipoPrecio()->ObtenNmbTipoPrecio());
}
void QManejadorPrecios::ConsultaPreciosDelProducto()
{

if(P_Producto)
{
printf("Se Buscan los precios \n");
CQPrecios lCQPrecios;
CQCtrPrecios lCQCPrecios(CSisDatCom,
			QStringList() <<
			"PreciosDelProducto" <<
			 P_Producto->ObtenClave() <<
			 (CQPCliente ? CQPCliente->ObtenIdPersona() :""),
			 &lCQPrecios);
	P_Producto->AnexaPrecios(lCQPrecios);
MuestraPrecios(lCQPrecios);
}
else
QMessageBox::information(this,
			 "El Fresno",
			 "No Se Ha Seleccionado Un Precio");
SiscomAjustaColumnas(QTDatos);
}
