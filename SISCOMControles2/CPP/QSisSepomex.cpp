#include <QSisSepomex.h> 
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisSepomex.h>

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

QSisSepomex::QSisSepomex( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();	
}
void QSisSepomex::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QSisSepomex::SiscomDatosServidor(const char *pchrPtrOperacionesConsulta,
				      const char *pchrPtrConsulta)
{
	chrPtrOperacionesConsulta=pchrPtrOperacionesConsulta;
	chrPtrConsulta=pchrPtrConsulta;
}
void QSisSepomex::IniciaControl()
{

	ConsultaEstados();
	LlenaComboEstados();

}
void QSisSepomex::ConsultaEstados()
{
SiscomEscribeLog3Qt("%s %s",
		     chrPtrOperacionesConsulta,
		     chrPtrConsulta);
SepomexOp lSepomex(SisDatCom);
lSepomex.SepomexEstados(chrPtrOperacionesConsulta,
			chrPtrConsulta,
			&SisReg3LstEstados);
}
void QSisSepomex::LlenaComboAsentamientos()
{
	SiscomDesarrollo3Qt::RegistrosAlCombo("asentamiento",
						QCBAsentamiento,
						&SisReg3LstAsentamientos);

}
void QSisSepomex::LlenaComboEstados()
{
	SiscomDesarrollo3Qt::RegistrosAlCombo("estado",
						QCBEstados,
						&SisReg3LstEstados);
}
void QSisSepomex::LlenaComboMunicipios()
{
  QCBMunicipio->clear();
  SiscomDesarrollo3Qt::RegistrosAlCombo("municipio",
  					QCBMunicipio,
					&SisReg3LstMunicipios);
}
void QSisSepomex::ConectaSlots()
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
		SLOT(S_SeleccionoMunicipio()));
	connect(QLEAsentamientos,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoAsentamiento()));
	connect(QLECP,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoCP()));

	connect(QCBEstados,
		SIGNAL(activated(int)),
		SLOT(S_SeleccionoEstado(int)));
	connect(QCBMunicipio,
		SIGNAL(activated(int)),
		SLOT(S_SeleccionoMunicipio(int)));
	connect(QCBAsentamiento,
		SIGNAL(activated(int)),
		SLOT(S_SeleccionoAsentamiento(int)));
}
void QSisSepomex::S_SeleccionoAsentamiento(int pintNAsentamiento)
{
	intYaColonias=0;
	SisReg3Asentamiento=SisReg3LstAsentamientos[pintNAsentamiento];
	S_SeleccionoAsentamiento();
	intYaColonias=1;
}
void QSisSepomex::S_SeleccionoMunicipio(int pintNMunicipio)
{
	intYaMunicipios=0;
	SisReg3Municipio=SisReg3LstMunicipios[pintNMunicipio];
	S_SeleccionoMunicipio();
	intYaMunicipios=1;

}
void QSisSepomex::S_SeleccionoEstado(int pintNEstado)
{

	intYaEstados=0;
	SisReg3Estado=SisReg3LstEstados[pintNEstado];
	S_SeleccionoEstado();
	intYaEstados=1;
}
void QSisSepomex::S_SeleccionoMunicipio()
{
/*
	SepAsen=0;
	if(!intYaMunicipios  &&
	   (int )QCBMunicipio->currentItem() < SepMunicipios.count())
	{
	SepMunicipio=SepMunicipios.at(QCBMunicipio->currentItem());	
	ConsultaAsentamientos();
	LlenaComboAsentamientos();
	SiscomPasaFocoControl(QLEAsentamientos);
	}
	GeneraSenalDireccion();
*/
	ConsultandoAsentamientos();
	SiscomDesarrollo3Qt::PasaFocoControl(QLEAsentamientos);

}
SiscomRegistro3 *QSisSepomex::IniciaDireccion()
{
SiscomRegistro3 *lSisReg3Direccion=new SiscomRegistro3;
(*lSisReg3Direccion)								 <<
new SiscomCampo3("IdEmpresa","")						 <<
new SiscomCampo3("IdPersona","")						 <<
new SiscomCampo3("Calle",SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLECalle)) <<
new SiscomCampo3("Numero",SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLENumero));
return lSisReg3Direccion;
}
void QSisSepomex::S_SeleccionoCP()
{
SiscomRegistro3 *lSisReg3Direccion;
lSisReg3Direccion=IniciaDireccion();
(*lSisReg3Direccion)+=SisReg3Estado;
(*lSisReg3Direccion)+=SisReg3Municipio;
(*lSisReg3Direccion)+=SisReg3Asentamiento;
emit SignalDireccion(lSisReg3Direccion);
}
void QSisSepomex::S_SeleccionoAsentamiento()
{
/*
	if(!intYaColonias 	&&
	   (int )QCBAsentamiento->currentItem() < SepAsentamientos.count() )
	{
	SepAsen=SepAsentamientos.at(QCBAsentamiento->currentItem());
	QLECP->setText(SepAsen->SRegistrosPro2["CP"]);
	SiscomPasaFocoControl(QLECP);
	}
	GeneraSenalDireccion();
*/
	QLECP->setText((*SisReg3Asentamiento)["cp"]);
	SiscomDesarrollo3Qt::PasaFocoControl(QLECP);
	
}
void QSisSepomex::S_PasaFocoNumero()
{
/*
	SiscomPasaFocoControl(QLENumero);
*/
	SiscomDesarrollo3Qt::PasaFocoControl(QLENumero);
}
void QSisSepomex::S_PasaFocoEstados()
{
/*
	SiscomPasaFocoControl(QLEEstados);
*/
 	SiscomDesarrollo3Qt::PasaFocoControl(QLEEstados);
}
void QSisSepomex::S_SeleccionoEstado()
{
/*
	SepMunicipio=0;
	SepAsen=0;
	if(!intYaEstados &&
	   (int )QCBEstados->currentItem()<SepEstados.count() &&
	   (int )QCBEstados->currentItem()!=-1)
	{
	SepEstado=SepEstados.at(QCBEstados->currentItem());
	ConsultaMunicipios(QCBEstados->currentItem());
	LlenaComboMunicipios();
	SiscomPasaFocoControl(QLEMunicipios);
	}
	GeneraSenalDireccion();
*/
	ConsultandoMunicipios();
	SiscomDesarrollo3Qt::PasaFocoControl(QLEMunicipios);
}
void QSisSepomex::ConsultaAsentamientos()
{
SepomexOp lSepomex(SisDatCom);
lSepomex.SepomexAsentamientos(chrPtrOperacionesConsulta,
			"SepomexAsentamientos",
			SisReg3Estado,
			SisReg3Municipio,
			&SisReg3LstAsentamientos);

}
void QSisSepomex::ConsultandoMunicipios()
{
	ConsultaMunicipios();
	LlenaComboMunicipios();
}
void QSisSepomex::ConsultandoAsentamientos()
{
	ConsultaAsentamientos();
	LlenaComboAsentamientos();
}
void QSisSepomex::ConsultaMunicipios()
{
SepomexOp lSepomexOp(SisDatCom);
 lSepomexOp.SepomexMunicipios(chrPtrOperacionesConsulta,
 			      "SepomexMunicipios",
			      SisReg3Estado,
			      &SisReg3LstMunicipios);
}
void QSisSepomex::IniciaVariables()
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
	(*QHEAsentamiento)+=CreaEspacioEtiquetaCombo("Colonias",
						     "Colonias",
						     "Colonias",
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

	QLEEstados=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBEstados,"QLEEstados");
	QLEMunicipios=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBMunicipio,"QLEMunicipio");
	QLEAsentamientos=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBAsentamiento,"QLEAsentamientos");

	
}

void QSisSepomex::setFocus()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QLECalle);
}

QVBoxLayout *QSisSepomex::CreaEspacioEtiquetaEdit(
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
	lQLEtiqueta->setSizePolicy(QSizePolicy(
				   QSizePolicy::Fixed,QSizePolicy::Fixed));
QLineEdit *lQLEdit=new QLineEdit(this,pchrPtrEdit);

	 lQVBLEspacio->addWidget(lQLEtiqueta);
	 lQVBLEspacio->addWidget(lQLEdit);
	 *pQLERegreso=lQLEdit;
	 return lQVBLEspacio;
}

QVBoxLayout *QSisSepomex::CreaEspacioEtiquetaCombo(
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
	 lQCombo->setInsertionPolicy(QComboBox::NoInsertion);
	 *pQCBRegreso=lQCombo;
	 if(pQLRegreso)
	 *pQLRegreso=lQLEtiqueta;
	 return lQVBLEspacio;
}

void QSisSepomex::LimpiaMunicipios()
{
}
void QSisSepomex::LimpiaAsentamientos()
{
}
int QSisSepomex::SeGeneraLaSenalDireccion()
{
/*
return !QLECalle->text().isNull() 	 &&
       !QLENumero->text().isNull()	 &&
       SepEstado			 &&
       SepMunicipio			 &&
       SepAsen;

*/
}

void QSisSepomex::GeneraSenalDireccion()
{
/*
	if(SeGeneraLaSenalDireccion())
	S_SeleccionoCP();
	else
	emit SignalDireccion(0);
*/
}

void QSisSepomex::S_SeleccionoTipoAsentamiento()
{

}
void QSisSepomex::S_PasaFocoTipoAsentamientos()
{

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



QVEspacio::QVEspacio(QWidget *pQWParent,
		     int pintMargen,
		     int pintEspacio,
		     const char *pchrPtrName):
	   QVBoxLayout(pQWParent,
	   	       pintMargen,
		       pintEspacio,
		       pchrPtrName)
{


}
QVEspacio &QVEspacio::operator+=(QVBoxLayout *pQVBEspacio)
{
	addItem(pQVBEspacio);
	return *this;
}
