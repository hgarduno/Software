#include <IMP_PaquetesRegistrados.h>
#include <IMP_ProductosPaquete.h>
#include <IMP_AnexarProducto.h>
#include<SiscomDatCom.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisPaquetes.h>
#include <CQSisComunPaquetes.h>

#include <qtable.h>
#include <qpushbutton.h>
QPaquetesRegistrados *InstanciaPaquetesRegistrados(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPaquetesRegistrados((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPaquetesRegistrados::QPaquetesRegistrados(SiscomDatCom *pSisDatCom, 
			           char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				PaquetesRegistrados(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				QWParent(pQWParent)
{
IniciaVariables();
ConectaSlots();
}

QPaquetesRegistrados::~QPaquetesRegistrados()
{

}
void QPaquetesRegistrados::IniciaVariables()
{
CQSPPaquete=new CQSisProductosPaquete(SisDatCom,
				      QTProductos,
				      this,
				      "CQSPPaquete");
ConsultandoPaquetes();
}
void QPaquetesRegistrados::ConectaSlots()
{
	connect(QTDatos,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionaPaquete(int,int,int,const QPoint &)));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotPaquete(int,int,int,const QPoint &)));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionandoPaquetes(int,int,int,const QPoint &)));
	connect(QTDatos,
		SIGNAL(currentChanged(int,int)),
		SLOT(SlotSeleccionandoPaquetes(int,int)));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(SlotEliminaPaquete()));
	connect(CQSPPaquete,
		SIGNAL(SignalProducto(SiscomRegistro3 *)),
		SLOT(SlotProducto(SiscomRegistro3 *)));
	connect(QPBEProducto,
		SIGNAL(clicked()),
		SLOT(SlotEliminaProductoPaquete()));
	connect(QPBAPaquete,
		SIGNAL(clicked()),
		SLOT(SlotAnexarProducto()));
}
void QPaquetesRegistrados::SlotAnexarProducto()
{
CQSisPaqueteProducto *lCQSPProducto;
const char *lchrPtrIdPaquete;
lchrPtrIdPaquete=(*SReg3Paquete)["idpaquete"];
QAnexarProducto lQAProducto(SisDatCom,
			    chrPtrArgumentos,
			    lchrPtrIdPaquete);
lCQSPProducto=lQAProducto.Producto();
CQSisOpPaquetes lCQSOPaquetes(SisDatCom);
lCQSOPaquetes.AnexarProducto(lCQSPProducto);
CQSPPaquete->ProductosPaquete(lchrPtrIdPaquete);
}
void QPaquetesRegistrados::SlotEliminaProductoPaquete()
{
CQSisOpPaquetes lCQSOPaquetes(SisDatCom);


SiscomEscribeLog3Qt("Se eliminara el producto  %s del paquete %s",
		    (*SReg3ProductoPaquete)["clave"],
		    (*SReg3Paquete)["clave"]);

lCQSOPaquetes.EliminaProducto((*SReg3Paquete)["idpaquete"],
			      (*SReg3ProductoPaquete)["idproducto"]);
CQSPPaquete->ProductosPaquete((*SReg3Paquete)["idpaquete"]);
}
void QPaquetesRegistrados::SlotProducto(SiscomRegistro3 *pSisReg3Producto)
{
SiscomEscribeLog3Qt("El Producto Seleccionado:%s",
		    (*pSisReg3Producto)["clave"]);
SReg3ProductoPaquete=pSisReg3Producto;

}
void QPaquetesRegistrados::SlotSeleccionandoPaquetes(int pintNPaquete,
						     int)
{
	SReg3Paquete=SReg3LPaquetes[pintNPaquete];
	CQSPPaquete->ProductosPaquete((*SReg3LPaquetes[pintNPaquete])["idpaquete"]);
}

void QPaquetesRegistrados::SlotSeleccionandoPaquetes(int pintNPaquete,
						     int,
						     int,
						     const QPoint &)
{

	CQSPPaquete->ProductosPaquete((*SReg3LPaquetes[pintNPaquete])["idpaquete"]);

}
void QPaquetesRegistrados::SlotPaquete(int pintNPaquete,
				       int,
				       int,
				       const QPoint &)
{
	QTDatos->selectRow(pintNPaquete);
	SReg3Paquete=SReg3LPaquetes[pintNPaquete];
}
void QPaquetesRegistrados::SlotEliminaPaquete()
{

CQSisOpPaquetes lCQSOPaquetes(SisDatCom);
lCQSOPaquetes.EliminaPaquete((*SReg3Paquete)["idpaquete"]);
ConsultandoPaquetes();

}

void QPaquetesRegistrados::SlotSeleccionaPaquete(int pintNPaquete,
						 int,
						 int,
						 const QPoint &)
{
QProductosPaquete lQPPaquete(SisDatCom,
			     chrPtrArgumentos,
			     (*SReg3LPaquetes[pintNPaquete])["idpaquete"]);

}
void QPaquetesRegistrados::ConsultaPaquetes()
{
SReg3LPaquetes.clear();
CQSisOpPaquetes lCQSOPaquetes(SisDatCom);
lCQSOPaquetes.Paquetes(&SReg3LPaquetes);
}
void QPaquetesRegistrados::ConsultandoPaquetes()
{
ConsultaPaquetes();
MuestraPaquetes();
}
void QPaquetesRegistrados::MuestraPaquetes()
{
const char *lchrPtrCampos[]={"clave",
		       "descripcion",
		       "precio",
		       0
		       };
SiscomEscribeLog3Qt("Se Recibieron %d Paquetes",
		     SReg3LPaquetes.count());
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,QTDatos,&SReg3LPaquetes);
SiscomDesarrollo3Qt::AjustaFilas(QTDatos);
SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
}

void QPaquetesRegistrados::keyPressEvent(QKeyEvent *pQKEvent)
{
	switch(pQKEvent->key())
	{
	  case Key_F5:
	  	ConsultandoPaquetes();
	  break;
	}
}

void QPaquetesRegistrados::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
