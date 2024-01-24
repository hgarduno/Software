#include <Vehiculos.h>
#include <CQSiscomCom.h>
#include <qlineedit.h>
#include <qcombobox.h>
Vehiculo::Vehiculo(const char *pchrPtrIdVehiculo,
		   const char *pchrPtrPlacas,
		   const char *pchrPtrDescripcion):
		   chrPtrIdVehiculo(pchrPtrIdVehiculo),
		   chrPtrPlacas(pchrPtrPlacas),
		   chrPtrDescripcion(pchrPtrDescripcion),
		   chrPtrEdoRegistro("0")
{


}
void Vehiculo::PonIdVehiculo(const char *pchrPtrIdVehiculo)
{
	chrPtrIdVehiculo=pchrPtrIdVehiculo;
}
void Vehiculo::PonPlacas(const char *pchrPtrPlacas)
{
	chrPtrPlacas=pchrPtrPlacas;
}

void Vehiculo::PonDescripcion(const char *pchrPtrDescripcion)
{
	chrPtrDescripcion=pchrPtrDescripcion;
}

void Vehiculo::PonEdoRegistro(const char *pchrPtrEdoRegistro)
{
	chrPtrEdoRegistro=pchrPtrEdoRegistro;
}
const char *Vehiculo::ObtenIdVehiculo()
{
	return chrPtrIdVehiculo;
}
const char *Vehiculo::ObtenPlacas()
{
	return chrPtrPlacas;
}
const char *Vehiculo::ObtenDescripcion()
{
	return chrPtrDescripcion;
}
const char *Vehiculo::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}

CQVehiculos::CQVehiculos()
{

}
CQCtrVehiculos::CQCtrVehiculos(CSISCOMDatComunicaciones *pCSisDatCom,
			       QStringList pQSLParametros,
			       CQCtrVehiculos::CtrVehiculos pCQCOperacion,
			       CQVehiculos *pCQVehiculos):
			CSisDatCom(pCSisDatCom)
{

	switch(pCQCOperacion)
	{
	   case CQCtrVehiculos::ConsultarVehiculos:
			ConsultaLosVehiculos(pQSLParametros,pCQVehiculos);
			AsignaRespuesta(pCQVehiculos);
	    break;
	}

}
CQCtrVehiculos::CQCtrVehiculos(CSISCOMDatComunicaciones *pCSisDatCom,
			       CQCtrVehiculos::CtrVehiculos pCQOperacion,
			       CQVehiculos *pCQVehiculos):
		CSisDatCom(pCSisDatCom),
		chrPtrParametrosRegistro("%s%s%s%s%s"),
		intNumParametrosRegistro(5)
{
	switch(pCQOperacion)
	{
		case CQCtrVehiculos::Registrar:
				RegistraLosVehiculos(pCQVehiculos);
		break;
	}
}
void CQCtrVehiculos::ConsultaLosVehiculos(QStringList pQSLParametros,	
					  CQVehiculos *pCQVehiculos)
{
int lintContador;
CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						   2);
	CQOGSvrSiscom->AnexaRegistro("%s%s",
				     "ConsultaVehiculos",
				     "");
	for(lintContador=0;
	    lintContador<pQSLParametros.size();
	    lintContador++)
	CQOGSvrSiscom->AnexaRegistro("%s%s",
				     "",
				     (const char *)pQSLParametros[lintContador]);
	 CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
         CQOGSvrSiscom->ObtenRespuesta();
}
void CQCtrVehiculos::AsignaRespuesta(CQVehiculos *pCQVehiculos)
{
	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	       QSLRegistro.count()==3)
	   pCQVehiculos->append(new Vehiculo((const char *)QSLRegistro[0],
					     (const char *)QSLRegistro[1],
					     (const char *)QSLRegistro[2]));
}
void CQCtrVehiculos::RegistraLosVehiculos(CQVehiculos *pCQVehiculos)
{
Vehiculo *lV_Vehiculo;
CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						   intNumParametrosRegistro);
	CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosRegistro,
				     "RegistraVehiculos",
				     "",
				     "",
				     "",
				     "");
		for(lV_Vehiculo=pCQVehiculos->first();
		    lV_Vehiculo;
		    lV_Vehiculo=pCQVehiculos->next())
			CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosRegistro,
						     "",
						     lV_Vehiculo->ObtenIdVehiculo(),
						     lV_Vehiculo->ObtenPlacas(),
						     lV_Vehiculo->ObtenDescripcion(),
						     lV_Vehiculo->ObtenEdoRegistro()); 

	 CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
         CQOGSvrSiscom->ObtenRespuesta();
}
CQSeleccionaVehiculo::CQSeleccionaVehiculo(CSISCOMDatComunicaciones *pCSisDatCom,
					   QWidget *pQWParent,
					   const char *pchrPtrName,
					   QLineEdit *pQLECPlacas,
					   QLineEdit *pQLEDescripcion,
					   QComboBox *pQCBPlacas):
			CSisDatCom(pCSisDatCom),
			QLEDescripcion(pQLEDescripcion),
			QLECPlacas(pQLECPlacas),
			QCBPlacas(pQCBPlacas),
			QObject(pQWParent,pchrPtrName)
{
	ConectaSlots();
	LlenaComboVehiculos();
}
void CQSeleccionaVehiculo::ConectaSlots()
{
	connect(QCBPlacas,
		SIGNAL(highlighted(int)),
		SLOT(S_MuestraVehiculo(int)));
	connect(QCBPlacas,
		SIGNAL(activated(int)),
		SLOT(S_SeleccionoVehiculo(int)));
	connect(QLECPlacas,
		SIGNAL(returnPressed()),
		SLOT(S_SeleccionoVehiculo()));

}
void CQSeleccionaVehiculo::S_SeleccionoVehiculo(int pintNVehiculo)
{
	emit Signal_Vehiculo(CQVVehiculos.at(pintNVehiculo));
}
void CQSeleccionaVehiculo::S_SeleccionoVehiculo()
{
	emit Signal_Vehiculo(CQVVehiculos.at(QCBPlacas->currentItem()));
}
void CQSeleccionaVehiculo::S_MuestraVehiculo(int pintNVehiculo)
{
	QLEDescripcion->setText(CQVVehiculos.at(pintNVehiculo)->ObtenPlacas());
}
void CQSeleccionaVehiculo::LlenaComboVehiculos()
{
CQCtrVehiculos lCQCVehiculos(CSisDatCom,
			     QStringList() << "" << "",
			     CQCtrVehiculos::ConsultarVehiculos,
			     &CQVVehiculos);
Vehiculo *lV_Vehiculo;
		for(lV_Vehiculo=CQVVehiculos.first();
		    lV_Vehiculo;
		    lV_Vehiculo=CQVVehiculos.next())
		 QCBPlacas->insertItem(lV_Vehiculo->ObtenDescripcion());
}
