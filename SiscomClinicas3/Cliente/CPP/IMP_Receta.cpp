#include <IMP_Receta.h>
#include<SISCOMComunicaciones++.h>

#include <CQSisConsultas.h>

#include <qpushbutton.h>
QReceta::QReceta(CQSisConsulta *pCQSConsulta,
		 SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):
				Receta(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				CQSConsulta(pCQSConsulta)
{
IniciaVariables();
ConectaSlots();
show();
}

QReceta::~QReceta()
{

}

void QReceta::ConectaSlots()
{
	connect(QLEFolio,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoReceta()));
	connect(QPBRegistra,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));

}
void QReceta::SlotRegistra()
{
Registra();
}
void QReceta::SlotPasaFocoReceta()
{
   if(!QLEFolio->text().isEmpty())
   {
	QPBRegistra->setEnabled(true);
	SiscomPasaFocoControl(QTEReceta);
   }
}
void QReceta::IniciaVariables()
{
SiscomPasaFocoControl(QLEFolio);
RecetaConsulta();
}
void QReceta::Registra()
{
CQSisOpReceta lCQSOReceta(SisDatCom);
lCQSOReceta.Registra(FormaReceta());
}
CQSisReceta *QReceta::FormaReceta()
{
return new CQSisReceta(
		(*CQSConsulta)["IdConsulta"],
		"",
		SiscomObtenInformacionDelEdit(QLEFolio),
		"",
		SiscomObtenInformacionDelEdit(QTEReceta));
}

void QReceta::RecetaConsulta()
{
CQSisOpReceta lCQSOReceta(SisDatCom);
lCQSOReceta.Receta((*CQSConsulta)["IdConsulta"],
		   &CQSLReceta);
if(CQSLReceta.count())
{
QTEReceta->setText((*CQSLReceta.at(0))["Receta"]);
QLEFolio->setText(((*CQSLReceta.at(0))["FolioRegistrado"]));
}
}
void QReceta::Actualiza()
{


}
