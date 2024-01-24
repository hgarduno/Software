#include <IMP_EdoRegGimnasio.h>
#include<SISCOMComunicaciones++.h>

#include <CQSisGimnasios.h>


#include <qpushbutton.h>
QEdoRegGimnasio::QEdoRegGimnasio(const char *pchrPtrGimnasio,
				CQSisLstGimnasio *pCQSLstGimnasio,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				EdoRegGimnasio(pQWParent,pchrPtrName,pbModal,pWFlags),
				CQSLstGimnasio(pCQSLstGimnasio),
				intSiLoRegistro(0),
				chrPtrGimnasio(pchrPtrGimnasio)
{
IniciaVariables();
ConectaSlots();
exec();
}

QEdoRegGimnasio::~QEdoRegGimnasio()
{

}

void QEdoRegGimnasio::ConectaSlots()
{

	connect(QPBRegGimnasio,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));
	connect(CanRegistro,
		SIGNAL(clicked()),
		SLOT(SlotCancelaRegistro()));

}
void QEdoRegGimnasio::SlotCancelaRegistro()
{
	intSiLoRegistro=0;
	done(intSiLoRegistro);
}
void QEdoRegGimnasio::SlotRegistra()
{
	intSiLoRegistro=1;
	done(intSiLoRegistro);
}
void QEdoRegGimnasio::IniciaVariables()
{
	QLEGimnasio->setText(chrPtrGimnasio);
	MuestraGimnasios();
}
int QEdoRegGimnasio::ObtenSiLoRegistro()
{
	return intSiLoRegistro;
}
void QEdoRegGimnasio::MuestraGimnasios()
{
int lintContador;
	QTDatos->setNumRows(CQSLstGimnasio->count());
	for(lintContador=0;
	    lintContador<(int )CQSLstGimnasio->count();
	    lintContador++)
	  SiscomAnexarRegistroALaTabla(lintContador,
	  			       QTDatos,
				       QStringList() << CQSLstGimnasio->at(lintContador)->SRegistrosPro2["Gimnasio"]);
}

void QEdoRegGimnasio::closeEvent(QCloseEvent *)
{

}
