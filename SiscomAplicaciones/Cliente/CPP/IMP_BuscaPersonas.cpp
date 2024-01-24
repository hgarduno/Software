#include <IMP_BuscaPersonas.h>
#include<SISCOMComunicaciones++.h>

#include <qpushbutton.h>
#include <qmessagebox.h>
QBuscaPersonas::QBuscaPersonas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pBoolModal,
				    WFlags pWFlags):	      
				BuscaPersonas(pQWParent,
					      pchrPtrName,
					      pBoolModal,
					      pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				CQSPersona(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QBuscaPersonas::~QBuscaPersonas()
{

}

void QBuscaPersonas::ConectaSlots()
{
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoIdPersona()));
	connect(QLEIdPersona,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoConsulta()));
	connect(QPBConsulta,
		SIGNAL(clicked()),
		SLOT(SlotConsulta()));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionandoPersona(int,int,int,const QPoint &)));
	connect(QPBSPersona,
		SIGNAL(clicked()),
		SLOT(SlotSeleccionaPersona()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
}
void QBuscaPersonas::SlotPasaFocoConsulta()
{
	SiscomPasaFocoControl(QPBConsulta);
}
void QBuscaPersonas::SlotCancelar()
{
	CQSLBPersona.setAutoDelete(true);
	CQSLBPersona.clear();
	CQSPersona=0;
	done(1);
}
void QBuscaPersonas::SlotSeleccionaPersona()
{
	if(CQSLBPersona.count())
	done(1);	
	else
	QMessageBox::information(
			this,
			"Siscom Clinicas3",
			"No se ha seleccionano una persona");
}
void QBuscaPersonas::SlotSeleccionandoPersona(
			int pintNFila,
			int,
			int,
			const QPoint &)
{
	QTDatos->selectRow(pintNFila);
	if(pintNFila!=-1)
	CQSPersona=CQSLBPersona.at(pintNFila);


}
						
void QBuscaPersonas::SlotConsulta()
{
	ConsultandoPersonas();
}
void QBuscaPersonas::IniciaVariables()
{
	SiscomPasaFocoControl(QLENombre);
}

void QBuscaPersonas::SlotPasaFocoAPaterno()
{
	SiscomPasaFocoControl(QLEAPaterno);
}
void QBuscaPersonas::SlotPasaFocoAMaterno()
{

	SiscomPasaFocoControl(QLEAMaterno);
}
void QBuscaPersonas::SlotPasaFocoIdPersona()
{
	SiscomPasaFocoControl(QLEIdPersona);
}

CQSisBuscaPersona *QBuscaPersonas::Persona()
{
return new CQSisBuscaPersona(
		SiscomObtenInformacionDelEdit(QLEIdPersona),
		SiscomObtenInformacionDelEdit(QLENombre),
		SiscomObtenInformacionDelEdit(QLEAPaterno),
		SiscomObtenInformacionDelEdit(QLEAMaterno));
}
void QBuscaPersonas::ConsultaPersonas()
{
CQSisOpBuscaPersonas lCQSOBPersonas(SisDatCom,
				    Persona());
lCQSOBPersonas.Personas(&CQSLBPersona);
}
void QBuscaPersonas::MuestraPersonas()
{
int lintContador;
CQSisBuscaPersona *lCQSBPersona;
QTDatos->setNumRows(CQSLBPersona.count());
for(lCQSBPersona=CQSLBPersona.first(),
    lintContador=0;
    lCQSBPersona;
    lCQSBPersona=CQSLBPersona.next(),
    lintContador++)
 SiscomAnexarRegistroALaTabla(
 	lintContador,
 	QTDatos,
	QStringList() <<
	QString((*lCQSBPersona)["Nombre"])	+
	" "					+
	(*lCQSBPersona)["APaterno"]	 	+
	" "					+
	(*lCQSBPersona)["AMaterno"] 	<<
	(*lCQSBPersona)["IdPersona"]);
}
void QBuscaPersonas::ConsultandoPersonas()
{
	ConsultaPersonas();
	MuestraPersonas();
	SiscomAjustaColumnas(QTDatos);
}
CQSisBuscaPersona *QBuscaPersonas::PersonaSeleccionada()
{
	return CQSPersona;
}

void QBuscaPersonas::closeEvent(QCloseEvent *)
{

}
void QBuscaPersonas::PersonasSeleccionadas(
			CQSisLstBuscaPersona *pCQSLBPersona)
{
int lintContador;
for(lintContador=0;
    lintContador<QTDatos->numRows();
    lintContador++)
if(QTDatos->isRowSelected(lintContador))
(*pCQSLBPersona) << CQSLBPersona.at(lintContador);
}
int QBuscaPersonas::SeSeleccionaronPersonas()
{
int lintContador;
int lintSeleccionadas=0;
for(lintContador=0;
    lintContador<QTDatos->numRows();
    lintContador++)
  if(QTDatos->isRowSelected(lintContador))
  lintSeleccionadas++;

return lintSeleccionadas>1;
}
