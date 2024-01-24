#include <Familias.h>
#include <CQSiscomCom.h>
#include <qwidget.h>
#include <qlineedit.h>
#include <qcombobox.h>

Familia::Familia(const char *pchrPtrIdFamilia,
		 const char *pchrPtrNmbFamilia,
		 const char *pchrPtrDscFamilia):
		chrPtrIdFamilia(pchrPtrIdFamilia),
		chrPtrNmbFamilia(pchrPtrNmbFamilia),
		chrPtrDscFamilia(pchrPtrDscFamilia),
		chrPtrEdoRegistro("0")
{


}
void Familia::PonIdFamilia(const char *pchrPtrIdFamilia)
{
	chrPtrIdFamilia=pchrPtrIdFamilia;
}

void Familia::PonNmbFamilia(const char *pchrPtrNmbFamilia)
{
	chrPtrNmbFamilia=pchrPtrNmbFamilia;
}

void Familia::PonDscFamilia(const char *pchrPtrDscFamilia)
{
	chrPtrDscFamilia=pchrPtrDscFamilia;
}

void Familia::PonEdoRegistro(const char *pchrPtrEdoRegistro)
{
	chrPtrEdoRegistro=pchrPtrEdoRegistro;
}
const char *Familia::ObtenIdFamilia()
{
	return chrPtrIdFamilia;
}
const char *Familia::ObtenNmbFamilia()
{
	return chrPtrNmbFamilia;
}
const char *Familia::ObtenDscFamilia()
{
	return chrPtrDscFamilia;
}
const char *Familia::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}
CQFamilias::CQFamilias()
{

}
CQCtrFamilias::CQCtrFamilias(CSISCOMDatComunicaciones *pCSisDatCom,
			     CQCtrFamilias::CtrFamilias pCQCOperacion,
			     CQFamilias *pCQFamilias):
			CSisDatCom(pCSisDatCom)
{
	switch(pCQCOperacion)
	{
	   case CQCtrFamilias::Registrar:
		RegistraLasFamilias(pCQFamilias);
	   break;
	   case CQCtrFamilias::Consultar:
		ConsultaLasFamilias(pCQFamilias);
		AnalizaRespuesta(pCQFamilias);
	   break;
	}

}
void CQCtrFamilias::RegistraLasFamilias(CQFamilias *pCQFamilias)
{
	FormaEnvio(pCQFamilias);
	AnalizaRespuesta(pCQFamilias);
}
void CQCtrFamilias::FormaEnvio(CQFamilias *pCQFamilias)
{
Familia *lF_Familia;
	CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						   __NumParRegFamilias__);
	CQOGSvrSiscom->AnexaRegistro(__ParametrosRegFamilias__,
				     "RegistraFamilias",
				     "",
				     "",
				     "",
				     "");

	for(lF_Familia=pCQFamilias->first();
	    lF_Familia;
	    lF_Familia=pCQFamilias->next())
	   CQOGSvrSiscom->AnexaRegistro(__ParametrosRegFamilias__,
					"",	
					lF_Familia->ObtenIdFamilia(),
					lF_Familia->ObtenNmbFamilia(),
					lF_Familia->ObtenDscFamilia(),
					lF_Familia->ObtenEdoRegistro());

	 CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
}
void CQCtrFamilias::AnalizaRespuesta(CQFamilias *pCQFamilias)
{
Familia *lF_Familia;
	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	      QSLRegistro.count()==3)
	{
	lF_Familia=new Familia((const char *)QSLRegistro[0],
			       (const char *)QSLRegistro[1],
			       (const char *)QSLRegistro[2]);
	lF_Familia->PonEdoRegistro("1");
	pCQFamilias->append(lF_Familia);
	}
					
}
void CQCtrFamilias::ConsultaLasFamilias(CQFamilias *pCQFamilias)
{
CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						   2);
	CQOGSvrSiscom->AnexaRegistro("%s%s",
				     "ConsultaFamilias",
				     "");

	CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
} 
CQSeleccionaFamilia::CQSeleccionaFamilia(CSISCOMDatComunicaciones *pCSisDatCom,
					 QWidget *pQWParent,
					 const char *pchrPtrName,
					 QLineEdit *pQLEFamilia,
					 QLineEdit *pQLEDscFamilia,
					 QComboBox *pQCBFamilia):
				QObject(pQWParent,pchrPtrName),
				QLEFamilia(pQLEFamilia),
				QLEDscFamilia(pQLEDscFamilia),
				QCBFamilia(pQCBFamilia),
				CSisDatCom(pCSisDatCom)
{
	
	ConectaSlots();
	LlenaComboFamilias();

}
void CQSeleccionaFamilia::ConectaSlots()
{
	if(QLEFamilia)
	connect(QLEFamilia,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoFamilia()));
	connect(QCBFamilia,
		SIGNAL(activated(int)),
		SLOT(S_SeleccionoFamilia(int)));
}
void CQSeleccionaFamilia::LlenaComboFamilias()
{
CQCtrFamilias lCQCFamilias(CSisDatCom,
			   CQCtrFamilias::Consultar,
			   &CQ_Familias);
Familia *lF_Familia;

	for(lF_Familia=CQ_Familias.first();
	    lF_Familia;
	    lF_Familia=CQ_Familias.next())
	 QCBFamilia->insertItem(lF_Familia->ObtenNmbFamilia());
}
void CQSeleccionaFamilia::S_SeleccionoFamilia(int pintNProducto)
{

	emit Signal_Familia(CQ_Familias.at(pintNProducto));
}
void CQSeleccionaFamilia::S_SeleccionoFamilia()
{
	emit Signal_Familia(CQ_Familias.at(QCBFamilia->currentItem()));
}	
void CQSeleccionaFamilia::setFocus()
{
	PasaFocoControl(QLEFamilia);
}
