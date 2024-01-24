#include <QSisDirecciones.h>
#include <QSisSepomex.h>
#include <SisDirecciones.h>
#include <SiscomRegistros3.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qslider.h>
QSisDirecciones::QSisDirecciones(QWidget *pQWParent,
				 const char *pchrPtrName,
				 WFlags pWFlags):
		QWidget(pQWParent,pchrPtrName,pWFlags)
{

	IniciaVariables();
	ConectaSlots();


}


void QSisDirecciones::IniciaVariables()
{
	QGLRegilla=new QGridLayout(this,4,1,1,2,"QGLRegilla");
	QSSepomex=new QSisSepomex(this,"QSSepomex");
	Etiqueta();
	Tabla();
	QGLRegilla->addWidget(QSSepomex,0,0);
	QGLRegilla->addWidget(QLDirecciones,1,0);
	QGLRegilla->addWidget(QTDirecciones,2,0);
	QGLRegilla->addItem(Botones(),3,0);

	QPBAnexar->setEnabled(false);
	QPBEliminar->setEnabled(false);
	QPBModificar->setEnabled(false);

}
void QSisDirecciones::Etiqueta()
{
	QLDirecciones=new QLabel(this,"QLDirecciones");
	QLDirecciones->setText("Direcciones Registradas");
}
void QSisDirecciones::Tabla()
{
	QTDirecciones=new QTable(0,5,this,"QTDirecciones");
	QTDirecciones->setReadOnly(true);
	QTDirecciones->horizontalHeader()->setLabel(0,"Calle");
	QTDirecciones->horizontalHeader()->setLabel(1,"Numero");
	QTDirecciones->horizontalHeader()->setLabel(2,"Colonia");
	QTDirecciones->horizontalHeader()->setLabel(3,"Estado");
	QTDirecciones->horizontalHeader()->setLabel(4,"Municipio");

}
void QSisDirecciones::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QSisDirecciones::Argumentos(char **pchrPtrArgumentos)
{
	chrPtrArgumentos=pchrPtrArgumentos;
}
void QSisDirecciones::IdPersona(const char *pchrPtrIdPersona)
{
	chrPtrIdPersona=pchrPtrIdPersona;
}
void QSisDirecciones::SistemaConsulta(const char *pchrPtrSistemaConsulta)
{
	chrPtrSistemaConsulta=pchrPtrSistemaConsulta;
}
QPushButton *QSisDirecciones::Boton(const char *pchrPtrTexto,
				    const char *pchrPtrName)
{
QPushButton *lQPBBoton;
	
	lQPBBoton=new QPushButton(pchrPtrTexto,
				 this,
				 pchrPtrName);
	lQPBBoton->setMinimumSize(QSize(0,20));
	lQPBBoton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,
				 QSizePolicy::Minimum));
	lQPBBoton->setAutoDefault(false);
	return lQPBBoton;
}
QHBoxLayout *QSisDirecciones::Botones()
{
QHBoxLayout *lQHBLayout;
QSpacerItem *lQSItem;
	lQHBLayout=new QHBoxLayout(0,2,2,"lQHBLayout");
	QPBAnexar=Boton("Anexar Direccion","QPBAnexar");
	QPBEliminar=Boton("Eliminar","QPBEliminar");
	QPBModificar=Boton("Modificar","QPBModiicar");
	lQHBLayout->addWidget(QPBAnexar);
	lQHBLayout->addWidget(QPBEliminar);
	lQHBLayout->addWidget(QPBModificar);
	return lQHBLayout;
}
QSisSepomex *QSisDirecciones::Sepomex()
{
	return QSSepomex;
}
void QSisDirecciones::ConectaSlots()
{
	connect(QSSepomex,
		SIGNAL(SignalDireccion(SiscomRegistro3 *)),
		SLOT(SlotDireccion(SiscomRegistro3 *)));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(SlotAnexar()));
}
void QSisDirecciones::SlotDireccion(SiscomRegistro3 *pSisReg3Direccion)
{
	QPBAnexar->setEnabled(pSisReg3Direccion);
	SiscomDesarrollo3Qt::PasaFocoControl(QPBAnexar);
	SisReg3Direccion=pSisReg3Direccion;
}
void QSisDirecciones::SlotAnexar()
{
	RegistraDireccion();
	QPBAnexar->setEnabled(false);
	QSSepomex->setFocus();
	DireccionesPersona();
}
void QSisDirecciones::IniciaSepomex()
{
	QSSepomex->PonServidor(SisDatCom);
	QSSepomex->SiscomDatosServidor(chrPtrOperacionesConsulta,
				       chrPtrConsulta);
	QSSepomex->IniciaControl();

}
void QSisDirecciones::DatosServidor(const char *pchrPtrOperacionesConsulta,
				    const char *pchrPtrConsulta)
{
   chrPtrOperacionesConsulta=pchrPtrOperacionesConsulta;
   chrPtrConsulta=pchrPtrConsulta;
}
void QSisDirecciones::IniciaControl()
{
	IniciaSepomex();
}
void QSisDirecciones::ConsultaDirecciones()
{
}
void QSisDirecciones::DireccionesPersona()
{
	ConsultaDirecciones();
	MuestraDirecciones();
}
void QSisDirecciones::MuestraDirecciones()
{
SiscomAjustaColumnas(QTDirecciones);
}
void QSisDirecciones::RegistraDireccion()
{
SiscomContenidoRegistro3(SisReg3Direccion);

}

void QSisDirecciones::Direcciones(CQSisLstDireccion *pCQSLstDirecciones)
{
	*pCQSLstDirecciones=CQSLDirecciones;
}
void QSisDirecciones::setFocus()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QSSepomex);
}
