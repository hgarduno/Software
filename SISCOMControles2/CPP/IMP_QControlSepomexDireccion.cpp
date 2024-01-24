#include <IMP_QControlSepomexDireccion.h>

#include <LibSISCOMComunControles.h>
#include <SISCOMComunicaciones++.h>

#include <qvariant.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qfile.h>
#include <qdatetime.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qpushbutton.h>
FILE *gPtrFleArchivoLog;
CQControlSepomexDireccion::CQControlSepomexDireccion( QWidget* parent, const char* name)
    : QWidget ( parent, name)
{
/*
	IniciaVariables();
	ConectaSlots();	
*/
 QHBoxLayout *layout = new QHBoxLayout( this );
     layout->setMargin( 0 );
     lineEdit = new QLineEdit( this, "filechooser_lineedit" );
	layout->addWidget( lineEdit );

button = new QPushButton( "...", this, "filechooser_button" );
button->setFixedWidth( button->fontMetrics().width( " ... " ) );
layout->addWidget( button );



}
CQControlSepomexDireccion::~CQControlSepomexDireccion()
{
}
/*
void CQControlSepomexDireccion::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void CQControlSepomexDireccion::IniciaControl()
{

	ConsultaEstados();
	LlenaComboEstados();
	ConsultaTAsentamientos();
	LlenaComboTAsentamientos();

}
void CQControlSepomexDireccion::ConsultaEstados()
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta << new SiscomParametroConsulta("ConsultaEstados");

SepomexOpEstados lSepOpEstados(SisDatCom,&lSPConsulta);

	lSepOpEstados.SiscomConsulta("ConsultaSepomex",
				    (QPtrList<SiscomInformacion>*)&SepEstados);
}
void CQControlSepomexDireccion::LlenaComboAsentamientos()
{
SepomexAsentamiento *lSepAsenta;

	for(lSepAsenta=SepAsentamientos.first();
	    lSepAsenta;
	    lSepAsenta=SepAsentamientos.next())
	  QCBAsentamiento->insertItem(lSepAsenta->SRegistrosPro2["Asentamiento"]);
}
void CQControlSepomexDireccion::LlenaComboTAsentamientos()
{
SepomexTAsentamiento *lSepTAsentamiento;

		for(lSepTAsentamiento=SepTAsentamientos.first();
		    lSepTAsentamiento;
		    lSepTAsentamiento=SepTAsentamientos.next())
		 QCBTipoAsen->insertItem(lSepTAsentamiento->SRegistrosPro2["Asentamiento"]); 

}
void CQControlSepomexDireccion::LlenaComboEstados()
{
SepomexEstado *lSepEstado;

	for(lSepEstado=SepEstados.first();
	    lSepEstado;
	    lSepEstado=SepEstados.next())
	 QCBEstados->insertItem(lSepEstado->SRegistrosPro2["Estado"]);

}
void CQControlSepomexDireccion::LlenaComboMunicipios()
{
SepomexMunicipio *lSepMunicipio;
	for(lSepMunicipio=SepMunicipios.first();
	    lSepMunicipio;
	    lSepMunicipio=SepMunicipios.next())
	  QCBMunicipio->insertItem(lSepMunicipio->SRegistrosPro2["Municipio"]);
}
void CQControlSepomexDireccion::ConectaSlots()
{

	connect(QLECalle,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoNumero()));
	connect(QLENumero,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoEstados()));
	connect(QLEEstados,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoEstado()));
	connect(QLEMunicipios,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoTipoAsentamientos()));
	connect(QLETAsen,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoTipoAsentamiento()));
	connect(QLEAsentamientos,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoAsentamiento()));
	
}
void CQControlSepomexDireccion::S_SeleccionoMunicipio()
{

}
void CQControlSepomexDireccion::S_SeleccionoAsentamiento()
{
	SepAsen=SepAsentamientos.at(QCBAsentamiento->currentItem());
	QLECP->setText(SepAsen->SRegistrosPro2["CP"]);
	SiscomPasaFocoControl(QLECP);



}
void CQControlSepomexDireccion::S_SeleccionoTipoAsentamiento()
{
	SepTAsen=SepTAsentamientos.at(QCBTipoAsen->currentItem());
	QLAsentamiento->setText(SepTAsen->SRegistrosPro2["Asentamiento"]);
	ConsultaAsentamientos();
	LlenaComboAsentamientos();
	SiscomPasaFocoControl(QLEAsentamientos);
}
void CQControlSepomexDireccion::S_PasaFocoTipoAsentamientos()
{
	SepMunicipio=SepMunicipios.at(QCBMunicipio->currentItem());	
	SiscomPasaFocoControl(QLETAsen);
}
void CQControlSepomexDireccion::S_PasaFocoNumero()
{
	SiscomPasaFocoControl(QLENumero);

}
void CQControlSepomexDireccion::S_PasaFocoEstados()
{
	SiscomPasaFocoControl(QLEEstados);
}
void CQControlSepomexDireccion::S_SeleccionoEstado()
{
	SepEstado=SepEstados.at(QCBEstados->currentItem());
	ConsultaMunicipios(QCBEstados->currentItem());
	LlenaComboMunicipios();
	SiscomPasaFocoControl(QLEMunicipios);
	

}
void CQControlSepomexDireccion::ConsultaAsentamientos()
{
SiscomParametrosConsulta lSPConsulta;
lSPConsulta<< 
new SiscomParametroConsulta("ConsultaAsentamientos") <<
new SiscomParametroConsulta(SepEstado->SRegistrosPro2["NumEstado"]) <<
new SiscomParametroConsulta(SepMunicipio->SRegistrosPro2["NumMunicipio"]) <<
new SiscomParametroConsulta(SepTAsen->SRegistrosPro2["Tipo"]);
SepomexOpAsentamientos lSepOpAsenta(SisDatCom,
				    &lSPConsulta);


		lSepOpAsenta.SiscomConsulta("ConsultaSepomex",
			(QPtrList<SiscomInformacion> *)&SepAsentamientos);


}
void CQControlSepomexDireccion::ConsultaMunicipios(int pintNumEstado)
{
SiscomParametrosConsulta lSPConsulta;
SepomexEstado *lSepEstado=SepEstados.at(pintNumEstado);
	lSPConsulta <<
	new SiscomParametroConsulta("ConsultaMunicipios") <<
	new SiscomParametroConsulta(lSepEstado->SRegistrosPro2["NumEstado"]);

SepomexOpMunicipios lSOpMunicipios(SisDatCom,
				   &lSPConsulta);
	lSOpMunicipios.SiscomConsulta("ConsultaSepomex",
				(QPtrList<SiscomInformacion> *)&SepMunicipios);
}
void CQControlSepomexDireccion::ConsultaTAsentamientos()
{
SiscomParametrosConsulta lSPConsulta;

	lSPConsulta <<
	new SiscomParametroConsulta("ConsultaTAsentamientos") ;
SepomexOpTAsentamientos lSOpTAsentamientos(SisDatCom,
					   &lSPConsulta);
	lSOpTAsentamientos.SiscomConsulta("ConsultaSepomex",
				(QPtrList<SiscomInformacion >*)&SepTAsentamientos);
}
void CQControlSepomexDireccion::IniciaVariables()
{

	QGLRegilla=new QGridLayout(this,5,1,1,2,"QGLRegilla");
	QHECalleNum=new QHEspacio(0,0,0,"QHECalleNum");
	QHEAsentamiento=new QHEspacio(0,0,0,"QHEAsentamiento");
	QHECPCiudad=new QHEspacio(0,0,0,"QHECPCiudad");
	(*QHECalleNum)+=CreaEspacioEtiquetaEdit("Calle",
						"Calle",
						"Calle",
						&QLECalle);
	(*QHECalleNum)+=CreaEspacioEtiquetaEdit("Numero",
						"Numero",
						"Numero",
						&QLENumero);
	QGLRegilla->addItem(QHECalleNum,0,0);	
	QGLRegilla->addItem(CreaEspacioEtiquetaCombo("Estado",
						"Estado",
						"Estado",
						&QCBEstados),
			    1,
			    0);
	QGLRegilla->addItem(CreaEspacioEtiquetaCombo("Municipio",
						"Municipio",
						"Municipio",
						&QCBMunicipio),
			    2,
			    0);
	(*QHEAsentamiento)+=CreaEspacioEtiquetaCombo("Asentamiento",
						     "Asentamiento",
						     "Asentamiento",
						     &QCBTipoAsen);
	(*QHEAsentamiento)+=CreaEspacioEtiquetaCombo("Asentamiento",
						     "Asentamiento",
						     "Asentamiento",
						     &QCBAsentamiento,
						     &QLAsentamiento);
	QGLRegilla->addItem(QHEAsentamiento,3,0);
	(*QHECPCiudad)+=CreaEspacioEtiquetaCombo("Ciudad",
						     "Ciudad",
						     "Ciudad",
						     &QCBCiudad);
	(*QHECPCiudad)+=CreaEspacioEtiquetaEdit("CP",
						     "Codigo Postal",
						     "CP",
						     &QLECP);
	QGLRegilla->addItem(QHECPCiudad,4,0);
	QLENumero->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
	QLECP->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));


	QLEEstados=SiscomColocaEditAlCombo(QCBEstados,"QLEEstados");
	QLEMunicipios=SiscomColocaEditAlCombo(QCBMunicipio,"QLEMunicipio");
	QLETAsen=SiscomColocaEditAlCombo(QCBTipoAsen,"QLETAsen");
	QLEAsentamientos=SiscomColocaEditAlCombo(QCBAsentamiento,"QLEAsentamientos");

	QLECalle->setEnabled(false);
	QLENumero->setEnabled(false);
	QLEEstados->setEnabled(false);
	QLEMunicipios->setEnabled(false);
	QLETAsen->setEnabled(false);
	QLEAsentamiento->setEnabled(false);
}

void CQControlSepomexDireccion::setFocus()
{
	SiscomPasaFocoControl(QLECalle);
}

QVBoxLayout *CQControlSepomexDireccion::CreaEspacioEtiquetaEdit(
				const char *pchrPtrNombre,
				const char *pchrPtrEtiqueta,
				const char *pchrPtrEdit,
				QLineEdit **pQLERegreso)
{

QVBoxLayout *lQVBLEspacio=new QVBoxLayout(0,
					  0,
					  -1,
					  pchrPtrNombre);

QLabel *lQLEtiqueta=new QLabel(pchrPtrEtiqueta,
			       this,
			       pchrPtrEtiqueta,
			       0);
	lQLEtiqueta->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
QLineEdit *lQLEdit=new QLineEdit(this,pchrPtrEdit);

	 lQVBLEspacio->addWidget(lQLEtiqueta);
	 lQVBLEspacio->addWidget(lQLEdit);
	 *pQLERegreso=lQLEdit;
	 return lQVBLEspacio;
}

QVBoxLayout *CQControlSepomexDireccion::CreaEspacioEtiquetaCombo(
				const char *pchrPtrNombre,
				const char *pchrPtrEtiqueta,
				const char *pchrPtrEdit,
				QComboBox **pQCBRegreso,
				QLabel **pQLRegreso)
{

QVBoxLayout *lQVBLEspacio=new QVBoxLayout(0,
					  0,
					  -1,
					  pchrPtrNombre);

QLabel *lQLEtiqueta=new QLabel(pchrPtrEtiqueta,
			       this,
			       pchrPtrEtiqueta,
			       0);
QComboBox *lQCombo=new QComboBox(this,pchrPtrEdit);

	 lQVBLEspacio->addWidget(lQLEtiqueta);
	 lQVBLEspacio->addWidget(lQCombo);
	 lQCombo->setAutoCompletion(true);
	 lQCombo->setDuplicatesEnabled(false);
	 *pQCBRegreso=lQCombo;
	 if(pQLRegreso)
	 *pQLRegreso=lQLEtiqueta;
	 return lQVBLEspacio;
}


QHEspacio::QHEspacio(QWidget *pQWParent,
		     int pintMargen,
		     int pintEspacio,
		     const char *pchrPtrName):
	   QHBoxLayout(pQWParent,
	   	       pintMargen,
		       pintEspacio,
		       pchrPtrName)
{


}
QHEspacio &QHEspacio::operator+=(QVBoxLayout *pQVBEspacio)
{
	addItem(pQVBEspacio);
	return *this;
}
*/
