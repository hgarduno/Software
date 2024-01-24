#include <Familias.h>

Familia::Familia(const char *pchrPtrIdFamilia,
		 const char *pchrPtrNmbFamilia,
		 const char *pchrPtrDscFamilia,
		 const char *pchrPtrEdoRegistro)
{

	IniciaRegistro();
	SRegistrosPro2							<<
	SiscomCampoPro2("IdFamilia",pchrPtrIdFamilia)			<<
	SiscomCampoPro2("NmbFamilia",pchrPtrNmbFamilia)			<<
	SiscomCampoPro2("DscFamilia",pchrPtrDscFamilia)			<<
	SiscomCampoPro2("EdoRegistro",pchrPtrEdoRegistro);
	SRegistrosPro2.SiscomAnexaRegistro();
}
void Familia::IniciaRegistro()
{
	SRegistroPro2				<<
	"IdFamilia"				<<
	"NmbFamilia"				<<
	"DscFamilia"				<<
	"EdoRegistro";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);	

}

Familias::Familias()
{

}

Familias &Familias::operator<<(Familia *pFamilia)
{
	append(pFamilia);
	return *this;
}

OpFamilias::OpFamilias(SiscomDatCom *pSisDatCom):
		SisDatCom(pSisDatCom)
{

}
void OpFamilias::GeneraFamilias(const SiscomComunicaSrv *pSComunicaSrv,
			        Familias &pFamilias)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);

	for(;
	    !lSRegistrosPro2.SiscomEsElUltimoRegistro();
	     ++lSRegistrosPro2)
	   pFamilias<< new Familia(lSRegistrosPro2["idfamilia"],
	   			   lSRegistrosPro2["nmbfamilia"],
				   lSRegistrosPro2["dscfamilia"],
				   "Insertado");
	   	
delete pSComunicaSrv;
}
void OpFamilias::ConsultaFamilias(Familias &pFamilias)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta 				         	<<
		new SiscomParametroConsulta("Familias");	
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaFamilias");
		GeneraFamilias((const SiscomComunicaSrv *)lSGenOp,pFamilias);
}
void OpFamilias::RegistraFamilias(Familias &pFamilias)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&pFamilias);
		lSGenOp.SiscomEjecutaEnvio("RegistraFamilias");

}
ManFamilias::ManFamilias(SiscomDatCom *pSisDatCom,
			 QComboBox *pQCBFamilias,
			 QLineEdit *pQLECFamilias,
			 QLineEdit *pQLEDscFamilia,
			 QWidget *pQWParent,
			 const char *pchrPtrName):
	QWidget(pQWParent,pchrPtrName),
	SisDatCom(pSisDatCom),
	QCBFamilias(pQCBFamilias),
	QLECFamilias(pQLECFamilias),
	QLEDscFamilia(pQLEDscFamilia)
{
	ConsultaFamilias();
	ConectaSlots();


}
void ManFamilias::ConsultaFamilias()
{
OpFamilias lOpFam(SisDatCom);
	   lOpFam.ConsultaFamilias(FFamilias);
Familia *lFamilia;
	  for(lFamilia=FFamilias.first();
	      lFamilia;
	      lFamilia=FFamilias.next())
	     QCBFamilias->insertItem(lFamilia->SRegistrosPro2["NmbFamilia"]);
}
void ManFamilias::ConectaSlots()
{
	connect(QCBFamilias,
		SIGNAL(highlighted(int)),
		SLOT(S_SeleccionandoFamilia(int)));
	connect(QLECFamilias,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoFamilia()));
}
void ManFamilias::S_SeleccionandoFamilia(int pintNFamilia)
{
Familia *lFamilia=FFamilias.at(pintNFamilia);
	if(lFamilia &&
	   QLEDscFamilia)
	QLEDscFamilia->setText(lFamilia->SRegistrosPro2["DscFamilia"]);

}
void ManFamilias::S_SeleccionoFamilia()
{
int lintNFamilia=QCBFamilias->currentItem();
Familia *lFamilia=FFamilias.at(lintNFamilia);

	emit SignalFamilia(lFamilia);

}
Familia *ManFamilias::ObtenFamilia(int pintNFamilia)
{
	return FFamilias.at(pintNFamilia);
}
