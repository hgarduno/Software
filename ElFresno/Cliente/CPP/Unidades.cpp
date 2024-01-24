#include <Unidades.h>
#include <CQSiscomCom.h>
#include <qlineedit.h>
#include <qcombobox.h>

Unidad::Unidad(const char *pchrPtrUnidad,
	       const char *pchrPtrNmbUnidad,
		const char *pchrPtrAbreviatura):
	chrPtrUnidad(pchrPtrUnidad),
	chrPtrNmbUnidad(pchrPtrNmbUnidad),
	chrPtrAbreviatura(pchrPtrAbreviatura),
	chrPtrEdoRegistro("0")
{

}
void Unidad::PonUnidad(const char *pchrPtrUnidad)
{
	chrPtrUnidad=pchrPtrUnidad;
}


void Unidad::PonNmbUnidad(const char *pchrPtrNmbUnidad)
{
	chrPtrNmbUnidad=pchrPtrNmbUnidad;
}


void Unidad::PonAbreviatura(const char *pchrPtrAbreviatura)
{
	chrPtrAbreviatura=pchrPtrAbreviatura;
}
void Unidad::PonEdoRegistro(const char *pchrPtrEdoRegistro)
{
	chrPtrEdoRegistro=pchrPtrEdoRegistro;
}
const char *Unidad::ObtenUnidad()
{
	return chrPtrUnidad;
}

const char *Unidad::ObtenAbreviatura()
{
	return chrPtrAbreviatura;
}

const char *Unidad::ObtenNmbUnidad()
{
	return chrPtrNmbUnidad;
}
const char *Unidad::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}


CQUnidades::CQUnidades()
{

}

CQCtrUnidades::CQCtrUnidades(CSISCOMDatComunicaciones *pCSisDatCom,
			     CQCtrUnidades::CtrUnidades pCQOperacion,
			     CQUnidades *pCQUnidades):
			CSisDatCom(pCSisDatCom),
			intNumParametros(5),
			chrPtrFormato("%s%s%s%s%s")
{
	switch(pCQOperacion)
	{
		case CQCtrUnidades::Registrar:
			RegistraLasUnidades(pCQUnidades);
		break;
		case CQCtrUnidades::Consultar:
			ConsultaUnidades(pCQUnidades);
			AnalizaRespuesta(pCQUnidades);
		break;
	}
}
void CQCtrUnidades::RegistraLasUnidades(CQUnidades *pCQUnidades)
{
	FormaEnvio(pCQUnidades);

}
void CQCtrUnidades::FormaEnvio(CQUnidades *pCQUnidades)
{
Unidad *lU_Unidad;
	CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
                                                   intNumParametros);
        CQOGSvrSiscom->AnexaRegistro(chrPtrFormato,
				     "RegistraUnidades",
				     "",
				     "",
				     "",
				     "");
	for(lU_Unidad=pCQUnidades->first();
	    lU_Unidad;
	    lU_Unidad=pCQUnidades->next())
	  CQOGSvrSiscom->AnexaRegistro(chrPtrFormato,
				       "",
					lU_Unidad->ObtenUnidad(),
					lU_Unidad->ObtenNmbUnidad(),
					lU_Unidad->ObtenAbreviatura(),
					lU_Unidad->ObtenEdoRegistro());	
	 CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
}
void CQCtrUnidades::ConsultaUnidades(CQUnidades *pCQUnidades)
{
CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
                                                   2);
        CQOGSvrSiscom->AnexaRegistro("%s%s",
				     "ConsultaUnidades",
				     "");
	CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();

}
void CQCtrUnidades::AnalizaRespuesta(CQUnidades *pCQUnidades)
{
Unidad *lU_Unidad;
	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	       QSLRegistro.count()==3)
	{
	 lU_Unidad=new Unidad((const char *)QSLRegistro[0],
			      (const char *)QSLRegistro[1],
			      (const char *)QSLRegistro[2]);
	 lU_Unidad->PonEdoRegistro("1");
	 pCQUnidades->append(lU_Unidad);
	}
}


CQSeleccionaUnidades::CQSeleccionaUnidades(CSISCOMDatComunicaciones *pCSisDatCom,
					   QWidget *pQWParent,
					   const char *pchrPtrName,
					   QLineEdit *pQLECUnidades,
					   QLineEdit *pQLEAbreviatura,
					   QComboBox *pQCBUnidades):
			QObject(pQWParent,pchrPtrName),
			CSisDatCom(pCSisDatCom),
			QLECUnidades(pQLECUnidades),
			QLEAbreviatura(pQLEAbreviatura),
			QCBUnidades(pQCBUnidades)
{
	ConectaSlots();
	LlenaComboUnidades();
}
void CQSeleccionaUnidades::ConectaSlots()
{
	connect(QCBUnidades,
		SIGNAL(highlighted(int )),
		SLOT(S_SeleccionandoUnidad(int)));
	connect(QLECUnidades,
		SIGNAL(returnPressed()),
		SLOT(S_Unidad()));
	connect(QCBUnidades,
		SIGNAL(activated(int)),
		SLOT(S_Unidad(int)));

}
void CQSeleccionaUnidades::LlenaComboUnidades()
{
CQCtrUnidades lCQCUnidades(CSisDatCom,
                           CQCtrUnidades::Consultar,
                           &CQ_Unidades);
Unidad *lU_Unidad;

        for(lU_Unidad=CQ_Unidades.first();
            lU_Unidad;
            lU_Unidad=CQ_Unidades.next())
	QCBUnidades->insertItem(lU_Unidad->ObtenNmbUnidad());
}
void CQSeleccionaUnidades::S_Unidad(int pintNUnidad)
{

	QLEAbreviatura->setText(CQ_Unidades.at(pintNUnidad)->ObtenAbreviatura());
	QLEAbreviatura->setText(CQ_Unidades.at(pintNUnidad)->ObtenAbreviatura());
	emit Signal_SUnidad(CQ_Unidades.at(pintNUnidad));
}
void CQSeleccionaUnidades::S_Unidad()
{
int lintUnidad=QCBUnidades->currentItem();
	QLEAbreviatura->setText(CQ_Unidades.at(lintUnidad)->ObtenAbreviatura());
emit Signal_SUnidad(CQ_Unidades.at(lintUnidad));
}
void CQSeleccionaUnidades::S_SeleccionandoUnidad(int pintNUnidad)
{
	QLEAbreviatura->setText(CQ_Unidades.at(pintNUnidad)->ObtenAbreviatura());
}
