#include <TiposPrecios.h>
#include <CQSiscomCom.h>
#include <qlineedit.h>
#include <qcombobox.h>
TipoPrecio::TipoPrecio(const char *pchrPtrNmbTipoPrecio,
		       const char *pchrPtrDescripcion,
		       const char *pchrPtrTipo):
		chrPtrNmbTipoPrecio(pchrPtrNmbTipoPrecio),
		chrPtrDescripcion(pchrPtrDescripcion),
		chrPtrTipo(pchrPtrTipo),
		chrPtrEdoRegistro("0")

{

}
void TipoPrecio::PonNmbTipoPrecio(const char *pchrPtrNmbTipoPrecio)
{
	chrPtrNmbTipoPrecio=pchrPtrNmbTipoPrecio;
}
void TipoPrecio::PonDescripcion(const char *pchrPtrDescripcion)
{
	chrPtrDescripcion=pchrPtrDescripcion;
}
void TipoPrecio::PonEdoRegistro(const char *pchrPtrEdoRegistro)
{
	chrPtrEdoRegistro=pchrPtrEdoRegistro;
}
void TipoPrecio::PonTipo(const char *pchrPtrTipo)
{
	chrPtrTipo=pchrPtrTipo;
}
const char *TipoPrecio::ObtenNmbTipoPrecio()
{
	return chrPtrNmbTipoPrecio;
}
const char *TipoPrecio::ObtenTipo()
{
	return chrPtrTipo;
}
const char *TipoPrecio::ObtenDescripcion()
{
	return chrPtrDescripcion;
}
const char *TipoPrecio::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}
CQTiposPrecios::CQTiposPrecios()
{

}

CQCtrTiposPrecios::CQCtrTiposPrecios(CSISCOMDatComunicaciones *pCSisDatCom,
				     CQCtrTiposPrecios::CtrTiposPrecios pCQCOperacion,
				     CQTiposPrecios *pCQTiposPrecios):
			CSisDatCom(pCSisDatCom),
			intNumParametrosReg(5),
			chrPtrParametrosRegistro("%s%s%s%s%s")
{
	switch(pCQCOperacion)
	{
	   case CQCtrTiposPrecios::Consultar:
		ConsultaLosTiposPrecios(pCQTiposPrecios);
		FormaRespuesta(pCQTiposPrecios);
	    break;
	   case CQCtrTiposPrecios::Registrar:
	    	RegistrarLosTiposPrecios(pCQTiposPrecios);
	   break;
	}

}
void CQCtrTiposPrecios::RegistrarLosTiposPrecios(CQTiposPrecios *pCQTiposPrecios)
{
TipoPrecio *lT_TipoPrecio;
CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
                                                   intNumParametrosReg);
	CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosRegistro,
                                     "RegistraTiposPrecios",
                                     "",
                                     "",
                                     "",
                                     "");
	for(lT_TipoPrecio=pCQTiposPrecios->first();
	    lT_TipoPrecio;
	    lT_TipoPrecio=pCQTiposPrecios->next())
	CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosRegistro,
                                     "",
                                     lT_TipoPrecio->ObtenNmbTipoPrecio(),
                                     lT_TipoPrecio->ObtenDescripcion(),
				     lT_TipoPrecio->ObtenTipo(),
                                     lT_TipoPrecio->ObtenEdoRegistro());
        CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();

	 

	
}
void CQCtrTiposPrecios::ConsultaLosTiposPrecios(CQTiposPrecios *pCQTiposPrecios)
{
CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
                                                   2);
        CQOGSvrSiscom->AnexaRegistro("%s%s",
                                     "ConsultaTiposPrecios",
                                     "");

        CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
}
void CQCtrTiposPrecios::FormaRespuesta(CQTiposPrecios *pCQTiposPrecios)
{
	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	       QSLRegistro.count()==3)
	 pCQTiposPrecios->append(new TipoPrecio((const char *)QSLRegistro[0],
					        (const char *)QSLRegistro[1],
					        (const char *)QSLRegistro[2]));

}
CQSeleccionaTipoPrecio::CQSeleccionaTipoPrecio(CSISCOMDatComunicaciones *pCSisDatCom,
					       QWidget *pQWParent,
					       const char *pchrPtrName,
					       QLineEdit *pQLECNmbTipoPrecio,
					       QLineEdit *pQLEDescripcion,
					       QComboBox *pQCBNmbTipoPrecio):
					QLECNmbTipoPrecio(pQLECNmbTipoPrecio),
					QLEDescripcion(pQLEDescripcion),
					QCBNmbTipoPrecio(pQCBNmbTipoPrecio),
					QObject(pQWParent,pchrPtrName),
					CSisDatCom(pCSisDatCom)
{
	LlenaComboNmbTipoPrecios();	
	ConectaSlots();
}
void CQSeleccionaTipoPrecio::LlenaComboNmbTipoPrecios()
{
CQCtrTiposPrecios lCQCtrTPrecios(CSisDatCom,
				 CQCtrTiposPrecios::Consultar,
				 &CQTPrecios);
TipoPrecio *lT_Precio;
	for(lT_Precio=CQTPrecios.first();
	    lT_Precio;
	    lT_Precio=CQTPrecios.next())
	QCBNmbTipoPrecio->insertItem(lT_Precio->ObtenNmbTipoPrecio());
}
void CQSeleccionaTipoPrecio::ConectaSlots()
{
	connect(QCBNmbTipoPrecio,
		SIGNAL(highlighted(int)),
		SLOT(S_SeleccionandoTipoPrecio(int)));
	connect(QCBNmbTipoPrecio,
		SIGNAL(activated(int)),
		SLOT(S_SeleccionoTipoPrecio(int)));
	connect(QLECNmbTipoPrecio,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoTipoPrecio()));


}
void CQSeleccionaTipoPrecio::S_SeleccionoTipoPrecio()
{
	emit Signal_STipoPrecio(CQTPrecios.at(QCBNmbTipoPrecio->currentItem()));
}
void CQSeleccionaTipoPrecio::S_SeleccionandoTipoPrecio(int pintNTipoPrecio)
{

	QLEDescripcion->setText(CQTPrecios.at(pintNTipoPrecio)->ObtenDescripcion());
}
void CQSeleccionaTipoPrecio::S_SeleccionoTipoPrecio(int pintNTipoPrecio)
{

		emit Signal_STipoPrecio(CQTPrecios.at(pintNTipoPrecio));
}
