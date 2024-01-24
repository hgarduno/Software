#include <QSisTelefonos.h>
#include <CQSisMedsComunicacion.h>
QSisTelefonos::QSisTelefonos(QWidget *pQWParent,
			     const char *pchrPtrName,
			     WFlags pWFlags):
	QWidget(pQWParent,pchrPtrName,pWFlags)
{
	IniciaVariables();
	ConectaSlots();

}

void QSisTelefonos::IniciaVariables()
{
QGLRegilla=new QGridLayout(this,4,1,1,2,"QGLRegilla2");
Etiqueta();
Tabla();
QGLRegilla->addWidget(QLTelefonos,0,0);
QGLRegilla->addItem(CapturaDatos(),1,0);
QGLRegilla->addWidget(QTTelefonos,2,0);
QGLRegilla->addItem(Botones(),3,0);
SiscomPasaFocoControl(QLETelefono);
}


void QSisTelefonos::Etiqueta()
{
	QLTelefonos=new QLabel(this,"QLDirecciones");
	QLTelefonos->setText("Telefonos Registradas");
}
void QSisTelefonos::Tabla()
{
	QTTelefonos=new QTable(0,2,this,"QTTelefonos");
	QTTelefonos->setReadOnly(true);
	QTTelefonos->horizontalHeader()->setLabel(0,"Telefono");
	QTTelefonos->horizontalHeader()->setLabel(1,"Descripcion");
}

QPushButton *QSisTelefonos::Boton(const char *pchrPtrTexto,
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
QHBoxLayout *QSisTelefonos::Botones()
{
QHBoxLayout *lQHBLayout;
QSpacerItem *lQSItem;
	lQHBLayout=new QHBoxLayout(0,2,2,"lQHBLayout2");
	QPBAnexar=Boton("Anexar","QPBAnexar");
	QPBEliminar=Boton("Eliminar","QPBEliminar");
	QPBModificar=Boton("Actualizar","QPBModiicar");
	lQHBLayout->addWidget(QPBAnexar);
	lQHBLayout->addWidget(QPBEliminar);
	lQHBLayout->addWidget(QPBModificar);
	return lQHBLayout;
}
QSisHEspacio *QSisTelefonos::CapturaDatos()
{
QSisHEspacio *lQSHEDatos=new QSisHEspacio(0,1,1,"lQSHEDatos");
	(*lQSHEDatos)+=SiscomCreaEspacioVerticalEtiquetaEdit(
			this,
			"Telefono",
			"Telefono",
			"QLETelefono",
			&QLETelefono,
			&QLTelefono);
	(*lQSHEDatos)+=SiscomCreaEspacioVerticalEtiquetaEdit(
			this,
			"Descripcion",
			"Descripcion",
			"QLEDescripcion",
			&QLEDescripcion,
			&QLDescripcion);
return lQSHEDatos;
}
void QSisTelefonos::ConectaSlots()
{
	connect(QLETelefono,	
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDescripcion()));
	connect(QLEDescripcion,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAnexar()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(SlotAnexar()));
}
void QSisTelefonos::SlotPasaFocoDescripcion()
{
SiscomPasaFocoControl(QLEDescripcion);
}
void QSisTelefonos::SlotPasaFocoAnexar()
{
SiscomPasaFocoControl(QPBAnexar);
}
void QSisTelefonos::SlotAnexar()
{
	Anexar();
	TelefonosRegistrados();
	SiscomPasaFocoControl(QLETelefono);
}
void QSisTelefonos::SistemaConsulta(const char *pchrPtrSistemaConsulta)
{
	chrPtrSistemaConsulta=pchrPtrSistemaConsulta;
}
void QSisTelefonos::IdPersona(const char *pchrPtrIdPersona)
{
chrPtrIdPersona=pchrPtrIdPersona;
}
void QSisTelefonos::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QSisTelefonos::Anexar()
{
CQSisOpMedComunicacion lCQSPMComunicacion(SisDatCom);
lCQSPMComunicacion.Registra(new SisMedCom(
				"1",
				"",
				SiscomObtenInformacionDelEdit(QLETelefono),
				SiscomObtenInformacionDelEdit(QLEDescripcion),
				chrPtrIdPersona));
}
void QSisTelefonos::ConsultaTelefonos()
{
SLMCom.clear();
CQSisOpMedComunicacion lCQSPMComunicacion(SisDatCom,chrPtrSistemaConsulta);
lCQSPMComunicacion.MedComunicacion(chrPtrIdPersona,"1",&SLMCom);
}
void QSisTelefonos::MuestraTelefonos()
{
int lintContador;
SisMedCom *lSMCom;
QTTelefonos->setNumRows(SLMCom.count());
for(lintContador=0,
    lSMCom=SLMCom.first();
    lSMCom;
    lintContador++,
    lSMCom=SLMCom.next())
SiscomAnexarRegistroALaTabla(
	lintContador,
	QTTelefonos,
	QStringList() 		<<
	(*lSMCom)["Dato"]	<<
	(*lSMCom)["Descripcion"]);
}
void QSisTelefonos::TelefonosRegistrados()
{
ConsultaTelefonos();
MuestraTelefonos();
}

void QSisTelefonos::Telefonos(SisLstMedCom *pSLMedCom)
{
	*pSLMedCom=SLMCom;	
}
