#include <Unidades.h>

Unidad::Unidad(const char *pchrPtrIdUnidad,
		 const char *pchrPtrNmbUnidad,
		 const char *pchrPtrDscUnidad)
{

	IniciaRegistro();
	SRegistrosPro2							<<
	SiscomCampoPro2("IdUnidad",pchrPtrIdUnidad)			<<
	SiscomCampoPro2("NmbUnidad",pchrPtrNmbUnidad)			<<
	SiscomCampoPro2("DscUnidad",pchrPtrDscUnidad);
	SRegistrosPro2.SiscomAnexaRegistro();
}
void Unidad::IniciaRegistro()
{
	SRegistroPro2				<<
	"IdUnidad"				<<
	"NmbUnidad"				<<
	"DscUnidad";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);	

}

Unidades::Unidades()
{

}

Unidades &Unidades::operator<<(Unidad *pUnidad)
{
	append(pUnidad);
	return *this;
}

OpUnidades::OpUnidades(SiscomDatCom *pSisDatCom):
		SisDatCom(pSisDatCom)
{

}
void OpUnidades::GeneraUnidades(const SiscomComunicaSrv *pSComunicaSrv,
			        Unidades &pUnidades)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);

	for(;
	    !lSRegistrosPro2.SiscomEsElUltimoRegistro();
	     ++lSRegistrosPro2)
	   pUnidades<< new Unidad(lSRegistrosPro2["unidad"],
	   			   lSRegistrosPro2["nmbunidad"],
				   lSRegistrosPro2["abreviatura"]);
	   	
delete pSComunicaSrv;
}
void OpUnidades::ConsultaUnidades(Unidades &pUnidades)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta 				         	<<
		new SiscomParametroConsulta("Unidades");	
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaUnidades");
		GeneraUnidades((const SiscomComunicaSrv *)lSGenOp,pUnidades);
}

ManUnidades::ManUnidades(SiscomDatCom *pSisDatCom,
			 QComboBox *pQCBUnidades,
			 QLineEdit *pQLECUnidades,
			 QLineEdit *pQLEDscUnidad,
			 QLineEdit *pQLEAbreviatura,
			 QWidget *pQWParent,
			 const char *pchrPtrName):
	QWidget(pQWParent,pchrPtrName),
	SisDatCom(pSisDatCom),
	QCBUnidades(pQCBUnidades),
	QLECUnidades(pQLECUnidades),
	QLEDscUnidad(pQLEDscUnidad),
	QLEAbreviatura(pQLEAbreviatura)
{
	ConsultaUnidades();
	ConectaSlots();


}
void ManUnidades::ConsultaUnidades()
{
OpUnidades lOpFam(SisDatCom);
	   lOpFam.ConsultaUnidades(FUnidades);
Unidad *lUnidad;
	  for(lUnidad=FUnidades.first();
	      lUnidad;
	      lUnidad=FUnidades.next())
	     QCBUnidades->insertItem(lUnidad->SRegistrosPro2["NmbUnidad"]);
}
void ManUnidades::ConectaSlots()
{
	connect(QCBUnidades,
		SIGNAL(highlighted(int)),
		SLOT(S_SeleccionandoUnidad(int)));
	connect(QLECUnidades,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoUnidad()));
}
void ManUnidades::S_SeleccionandoUnidad(int pintNUnidad)
{
Unidad *lUnidad=FUnidades.at(pintNUnidad);
	if(lUnidad &&
	   QLEDscUnidad)
	QLEDscUnidad->setText(lUnidad->SRegistrosPro2["DscUnidad"]);
	if(QLEAbreviatura)
	QLEAbreviatura->setText(lUnidad->SRegistrosPro2["Abreviatura"]);

}
void ManUnidades::S_SeleccionoUnidad()
{
int lintNUnidad=QCBUnidades->currentItem();
Unidad *lUnidad=FUnidades.at(lintNUnidad);

	emit SignalUnidad(lUnidad);

}
Unidad *ManUnidades::ObtenUnidad(int pintNUnidad)
{
	return FUnidades.at(pintNUnidad);
}
