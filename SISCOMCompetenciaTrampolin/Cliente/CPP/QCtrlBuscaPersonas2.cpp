#include <QCtrlBuscaPersonas2.h>
#include <SISCOMComunicaciones++.h>
#include <CQSisConsultas.h>
#include <qlayout.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>


QCtrlBuscaPersonas2::QCtrlBuscaPersonas2( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    intYaConectoSlots(0)
{
	IniciaVariables();
}
void QCtrlBuscaPersonas2::ColocaDatosGenerales()
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
void QCtrlBuscaPersonas2::IniciaGrids()
{
	QGLEspacio1=new QGridLayout(this,1,2,1,1,"QGLEspacio1");
	QGLEspacio=new QGridLayout(0,3,1,1,1,"QGLEspacio");
	QSHEspacio=new QSisHEspacio(this,1,1,"QSHEspacio");

}
void QCtrlBuscaPersonas2::IniciaVariables()
{
	IniciaGrids();	
	ColocaDatosGenerales();

	QGLEspacio->addItem(QSHEspacio,0,0);
	QGLEspacio1->addItem(QGLEspacio,0,0);
	SiscomPasaFocoControl(QLENombre);

	TipoPersona[0]=&QCtrlBuscaPersonas2::Gimnasta;
	TipoPersona[1]=&QCtrlBuscaPersonas2::Juez;
	TipoPersona[2]=&QCtrlBuscaPersonas2::Entrenador;
}
void QCtrlBuscaPersonas2::Juez()
{

}
void QCtrlBuscaPersonas2::Gimnasta()
{
	chrPtrPersona=strdup("gimnasta");
}
void QCtrlBuscaPersonas2::Entrenador()
{
	chrPtrPersona=strdup("entrenador");
}
void QCtrlBuscaPersonas2::IniciaControl()
{
	if(!intYaConectoSlots)
	ConectaSlots();
}
void QCtrlBuscaPersonas2::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}

void QCtrlBuscaPersonas2::ConectaSlots()
{
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotBusca()));
	intYaConectoSlots=1;
}
void QCtrlBuscaPersonas2::SlotBusca()
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
void QCtrlBuscaPersonas2::MuestraResultados()
{
CQSisEntrenador *lCQSEPersona;
QResBusqueda lQRBusqueda(&CQSLPersonas);

	if((lCQSEPersona=lQRBusqueda.ObtenPersona()))
	emit SignalPersona(lCQSEPersona,chrPtrPersona);


}
void QCtrlBuscaPersonas2::SlotPasaFocoAPaterno()
{
	SiscomPasaFocoControl(QLEAPaterno);
}
void QCtrlBuscaPersonas2::SlotPasaFocoAMaterno()
{
	SiscomPasaFocoControl(QLEAMaterno);
}

void QCtrlBuscaPersonas2::setFocus()
{
	SiscomPasaFocoControl(QLENombre);	
}
void QCtrlBuscaPersonas2::LimpiaSeleccion()
{
}



void QCtrlBuscaPersonas2::PonPersona(const char *pchrPtrPersona)
{
	chrPtrPersona=pchrPtrPersona;
}

QResBusqueda::QResBusqueda(
		CQSisLstEntrenador *pCQSEPersonas,
		QWidget *pQWParent,
		const char *pchrPtrName,
		bool pbModal,
		WFlags pWFlags):
	QDialog(pQWParent,
		pchrPtrName,
		pbModal,
		pWFlags),
	CQSLEPersona(pCQSEPersonas)
{
	IniciaTabla();
	IniciaVariables();
	ConectaSlots();
	MuestraPersonas();
	exec();
}
void QResBusqueda::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QHBLayout->addWidget(QTDatos);

}
void QResBusqueda::IniciaTabla()
{
	QTDatos=new QTable(0,3,this);
	QTDatos->horizontalHeader()->setLabel(0,"Nombre");
	QTDatos->horizontalHeader()->setLabel(1,"Apellido Paterno");
	QTDatos->horizontalHeader()->setLabel(2,"Apellido Materno");
	QTDatos->setReadOnly(true);
}
void QResBusqueda::MuestraPersonas()
{
CQSisEntrenador *lCQSEntrenador;
int lintContador;
	QTDatos->setNumRows(CQSLEPersona->count());
	for(lCQSEntrenador=CQSLEPersona->first(),
	    lintContador=0;
	    lCQSEntrenador;
	    lCQSEntrenador=CQSLEPersona->next(),
	    lintContador++)
	 SiscomAnexarRegistroALaTabla(lintContador,
	 			      QTDatos,
				      QStringList() 				<< 
				      lCQSEntrenador->SRegistrosPro2["Nombre"] 	<<
				      lCQSEntrenador->SRegistrosPro2["APaterno"]	<<
				      lCQSEntrenador->SRegistrosPro2["AMaterno"]);


}
void QResBusqueda::ConectaSlots()
{
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotPersona(int,int,int,const QPoint &)));
}
void QResBusqueda::SlotPersona(int pintNPersona,
				int ,
				int ,
				const QPoint &)
{
	if(pintNPersona!=-1)
	{
	CQSEPersona=CQSLEPersona->at(pintNPersona);
	done(1);
	}

}
CQSisEntrenador *QResBusqueda::ObtenPersona()
{
	return CQSEPersona;
}
void QResBusqueda::closeEvent(QCloseEvent *pQCEvent)
{
	CQSEPersona=0;
	pQCEvent->accept();

}
