#include <TipoPrecios.h>
TipoPrecio::TipoPrecio(const char *pchrPtrNmbTipoPrecio,
		 const char *pchrPtrDscTipoPrecio)
{

	IniciaRegistro();
	SRegistrosPro2								<<
	SiscomCampoPro2("NmbTipoPrecio",pchrPtrNmbTipoPrecio)			<<
	SiscomCampoPro2("DscTipoPrecio",pchrPtrDscTipoPrecio);
	SRegistrosPro2.SiscomAnexaRegistro();
}
void TipoPrecio::IniciaRegistro()
{
	SRegistroPro2				<<
	"NmbTipoPrecio"				<<
	"DscTipoPrecio";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);	

}
TipoPrecios::TipoPrecios()
{

}

TipoPrecios &TipoPrecios::operator<<(TipoPrecio *pTipoPrecio)
{
	append(pTipoPrecio);
	return *this;
}

OpTipoPrecios::OpTipoPrecios(SiscomDatCom *pSisDatCom):
		SisDatCom(pSisDatCom)
{

}
void OpTipoPrecios::ConsultaTipoPrecios(TipoPrecios &pTipoPrecios)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta 				         	<<
		new SiscomParametroConsulta("TipoPrecios");	
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaTipoPrecios");
		GeneraTipoPrecios((const SiscomComunicaSrv *)lSGenOp,pTipoPrecios);
}
void OpTipoPrecios::GeneraTipoPrecios(const SiscomComunicaSrv *pSComunicaSrv,
				      TipoPrecios &pTipoPrecios)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);

	for(;
	    !lSRegistrosPro2.SiscomEsElUltimoRegistro();
	     ++lSRegistrosPro2)
	   pTipoPrecios << new TipoPrecio(lSRegistrosPro2["nmbtipoprecio"],
				   lSRegistrosPro2["descripcion"]);
delete pSComunicaSrv;	
}

ManTipoPrecio::ManTipoPrecio(SiscomDatCom *pSisDatCom,
			     QComboBox *pQCBTipoPrecio,
			     QLineEdit *pQLECTipoPrecio,
			     QTextEdit *pQLEDescripcion,
			     QWidget *pQWParent,
			     const char *pchrPtrName):
		QWidget(pQWParent,pchrPtrName),
		SisDatCom(pSisDatCom),
		QCBTipoPrecio(pQCBTipoPrecio),
		QLECTipoPrecio(pQLECTipoPrecio),
		QLEDescripcion(pQLEDescripcion)
{
	Consulta();
	ConectaSlots();
}
void ManTipoPrecio::Consulta()
{
OpTipoPrecios lOpTipoPrecios(SisDatCom);
lOpTipoPrecios.ConsultaTipoPrecios(TTipoPrecios);
TipoPrecio *lTipoPrecio;
	for(lTipoPrecio=TTipoPrecios.first();
	    lTipoPrecio;
	    lTipoPrecio=TTipoPrecios.next())
	  /* CDMX Siscom Electronica Miercoles 19 Junio 2019 
	   * Con la integracion de los precios de mayoreo, se muestra el 
	   * Precio para la persona 
	   *
	   * QCBTipoPrecio->insertItem(lTipoPrecio->SRegistrosPro2["NmbTipoPrecio"]);*/
	   QCBTipoPrecio->insertItem(lTipoPrecio->SRegistrosPro2["DscTipoPrecio"]);
	 QLEDescripcion->setText((TTipoPrecios.first())->SRegistrosPro2["DscTipoPrecio"]);
}
void ManTipoPrecio::ConectaSlots()
{
	connect(QLECTipoPrecio,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoTipoPrecio()));
}
void ManTipoPrecio::S_SeleccionoTipoPrecio()
{
	emit SignalTipoPrecio(TTipoPrecios.at(QCBTipoPrecio->currentItem()));		
}
TipoPrecio *ManTipoPrecio::ObtenTipoPrecio(int pintNumTipoPrecio)
{
	return TTipoPrecios.at(pintNumTipoPrecio);
}
