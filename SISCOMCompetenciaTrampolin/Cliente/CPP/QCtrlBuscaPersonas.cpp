#include <QCtrlBuscaPersonas.h>
#include <SISCOMComunicaciones++.h>
#include <CQSisConsultas.h>
#include <qlayout.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>


QCtrlBuscaPersonas::QCtrlBuscaPersonas( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
}
void QCtrlBuscaPersonas::ColocaDatosGenerales()
{
	(*QSHEspacio)+=SiscomCreaEspacioVerticalEtiquetaEdit(
				this,
				"Nombre",
				"Nombre",
				"QLENombre",
				&QLENombre,
				&QLNombre);
	(*QSHEspacio)+=SiscomCreaEspacioVerticalEtiquetaEdit(
				this,
				"APaterno",
				"APaterno",
				"QLEAPaterno",
				&QLEAPaterno,
				&QLAPaterno);
	(*QSHEspacio)+=SiscomCreaEspacioVerticalEtiquetaEdit(
				this,
				"AMaterno",
				"AMaterno",
				"QLEAMaterno",
				&QLEAMaterno,
				&QLAMaterno);
}
void QCtrlBuscaPersonas::IniciaGrids()
{
	QGLEspacio1=new QGridLayout(this,1,2,1,1,"QGLEspacio1");
	QGLEspacio=new QGridLayout(0,3,1,1,1,"QGLEspacio");
	QSHEspacio=new QSisHEspacio(this,1,1,"QSHEspacio");

}
void QCtrlBuscaPersonas::ColocaTablaYBoton()
{
	QPBBuscar=new QPushButton("Buscar",this,"QPBBuscar");
	QTDatos=new QTable(this,"QTDatos");
	QPBBuscar->setAutoDefault(false);
	QTDatos->setNumCols(3);
	QTDatos->horizontalHeader()->setLabel(0,"Nombre");
	QTDatos->horizontalHeader()->setLabel(1,"Apellido Paterno");
	QTDatos->horizontalHeader()->setLabel(2,"Apellido Materno");
	QTDatos->setReadOnly(true);
}
void QCtrlBuscaPersonas::ColocaRadioBotones()
{

	QBGBotones=new QButtonGroup(this);
	QBGBotones->setColumnLayout(0, Qt::Vertical );
	QBGBotones->layout()->setSpacing( 6 );
	QBGBotones->layout()->setMargin( 11 );
	QGLRadioBotones=new QGridLayout(QBGBotones->layout());
	QGLRadioBotones->setAlignment( Qt::AlignTop );
	QRBGimnasta=new QRadioButton("Gimnasta",QBGBotones);
	QRBJuez=new QRadioButton("Juez",QBGBotones);
	QRBEntrenador=new QRadioButton("Entrenador",QBGBotones);

	QGLRadioBotones->addWidget(QRBGimnasta,0,0);
	QGLRadioBotones->addWidget(QRBJuez,1,0);
	QGLRadioBotones->addWidget(QRBEntrenador,2,0);


}
void QCtrlBuscaPersonas::IniciaVariables()
{
	IniciaGrids();	
	ColocaDatosGenerales();
	ColocaTablaYBoton();
	ColocaRadioBotones();

	QGLEspacio->addItem(QSHEspacio,0,0);
	QGLEspacio->addWidget(QTDatos,1,0);
	QGLEspacio->addWidget(QPBBuscar,2,0);
	QGLEspacio1->addItem(QGLEspacio,0,0);
	QGLEspacio1->addWidget(QBGBotones,0,1);

	QRBGimnasta->setEnabled(false);
	QRBJuez->setEnabled(false);
	QRBEntrenador->setEnabled(false);

	SiscomPasaFocoControl(QLENombre);

	TipoPersona[0]=&QCtrlBuscaPersonas::Gimnasta;
	TipoPersona[1]=&QCtrlBuscaPersonas::Juez;
	TipoPersona[2]=&QCtrlBuscaPersonas::Entrenador;
	QPBBuscar->setEnabled(false);

}
void QCtrlBuscaPersonas::Juez()
{

}
void QCtrlBuscaPersonas::Gimnasta()
{
	chrPtrPersona=strdup("gimnasta");
	QPBBuscar->setEnabled(true);
}
void QCtrlBuscaPersonas::Entrenador()
{
	chrPtrPersona=strdup("entrenador");
	QPBBuscar->setEnabled(true);
}
void QCtrlBuscaPersonas::IniciaControl()
{
	ConectaSlots();
}
void QCtrlBuscaPersonas::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}

void QCtrlBuscaPersonas::ConectaSlots()
{
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoBuscar()));
	connect(QPBBuscar,
		SIGNAL(clicked()),
		SLOT(SlotBusca()));
	connect(QTDatos,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(SlotPersona(int,int,int,const QPoint &)));
	connect(QBGBotones,
		SIGNAL(clicked(int)),
		SLOT(SlotTipoPersona(int)));
}
void QCtrlBuscaPersonas::SlotTipoPersona(int pintTPersona)
{
	(this->*TipoPersona[pintTPersona])();
}
void QCtrlBuscaPersonas::SlotPersona(int pintNFila,
				     int,
				     int,
				     const QPoint &)
{
	emit SignalPersona(CQSLPersonas.at(pintNFila),chrPtrPersona);
}

void QCtrlBuscaPersonas::SlotBusca()
{
CQSisOpConsultas lCQSOConsultas(SisDatCom);
	lCQSOConsultas.ConsultaPersonasNombre(
			chrPtrPersona,
			SiscomObtenInformacionDelEdit(QLENombre),
			SiscomObtenInformacionDelEdit(QLEAPaterno),
			SiscomObtenInformacionDelEdit(QLEAMaterno),
			&CQSLPersonas);
	if(CQSLPersonas.count()==1)
	emit SignalPersona(CQSLPersonas.at(0),chrPtrPersona);
	else
	MuestraResultados();

}
void QCtrlBuscaPersonas::MuestraResultados()
{
CQSisEntrenador *lCQSEntrenador;
int lintContador;
	QTDatos->setNumRows(CQSLPersonas.count());
	for(lCQSEntrenador=CQSLPersonas.first(),
	    lintContador=0;
	    lCQSEntrenador;
	    lCQSEntrenador=CQSLPersonas.next(),
	    lintContador++)
	 SiscomAnexarRegistroALaTabla(lintContador,
	 			      QTDatos,
				      QStringList() 				<< 
				      lCQSEntrenador->SRegistrosPro2["Nombre"] 	<<
				      lCQSEntrenador->SRegistrosPro2["APaterno"]	<<
				      lCQSEntrenador->SRegistrosPro2["AMaterno"]);
}
void QCtrlBuscaPersonas::SlotPasaFocoAPaterno()
{
	SiscomPasaFocoControl(QLEAPaterno);
}
void QCtrlBuscaPersonas::SlotPasaFocoAMaterno()
{
	SiscomPasaFocoControl(QLEAMaterno);
}
void QCtrlBuscaPersonas::SlotPasaFocoBuscar()
{
	SiscomPasaFocoControl(QPBBuscar);
}
void QCtrlBuscaPersonas::setFocus()
{
	
}
void QCtrlBuscaPersonas::LimpiaSeleccion()
{
}

void QCtrlBuscaPersonas::HabilitaGimnasta(bool pbEstado)
{
	QRBGimnasta->setEnabled(pbEstado);
}
void QCtrlBuscaPersonas::HabilitaJuez(bool pbEstado)
{
	QRBJuez->setEnabled(pbEstado);
}
void QCtrlBuscaPersonas::HabilitaEntrenador(bool pbEstado)
{
	QRBEntrenador->setEnabled(pbEstado);
}



void QCtrlBuscaPersonas::PonPersona(const char *pchrPtrPersona)
{
	chrPtrPersona=pchrPtrPersona;
	QPBBuscar->setEnabled(true);
}
