#include <IMP_Vehiculos.h>
#include <IMP_MantenVehiculo.h>
#include <CQSiscomCom.h>
#include <SISCOMComunicaciones++.h>


#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

QVehiculos *InstanciaVehiculos(void *pCSisDatCom,
			       void *pQWParent,
			       const char *pchrPtrName,
			       int pintWFlags)
{
	return new QVehiculos((CSISCOMDatComunicaciones *)pCSisDatCom,
			      (QWidget *)pQWParent,
			      pchrPtrName,
			      pintWFlags);
}
QVehiculos::QVehiculos(CSISCOMDatComunicaciones *pCSisDatCom,
		QWidget* parent, const char* name, WFlags fl )
    : Vehiculos( parent, name, fl ),
    CSisDatCom(pCSisDatCom)
{
	SDatCom=new SiscomDatCom(atoi(getenv("PtoComSvr2")),
			     CSisDatCom->ObtenDirIpSvr());
	IniciaVariables();
	ConectaSlots();
}

QVehiculos::~QVehiculos()
{
}
void QVehiculos::IniciaVariables()
{
	PasaFocoControl(QLEPlacas);
	ConsultaVehiculos();
	
}
void QVehiculos::ConectaSlots()
{
	connect(QLEPlacas,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoDescripcion()));
	connect(QLEDescripcion,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexar()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_Registrar()));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(S_SeleccionaVehiculo(int ,int,int,const QPoint &)));
	connect(QTDatos,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(S_ModificaVehiculo(int,int,int,const QPoint &)));
}
void QVehiculos::S_ModificaVehiculo(int pintNFila,
				    int ,
				    int,
				    const QPoint &)
{
QMantenVehiculo lQMVehiculo(SDatCom,
			    VVehiculos2.at(pintNFila));
ConsultaVehiculos();

}
void QVehiculos::S_SeleccionaVehiculo(int pintNFila,
				      int,
				      int,
				      const QPoint &)
{

	if(pintNFila!=-1)
	 QTDatos->selectRow(pintNFila);

}
void QVehiculos::S_PasaFocoDescripcion()
{
	PasaFocoControl(QLEDescripcion);
}
void QVehiculos::S_PasaFocoAnexar()
{
	PasaFocoControl(QPBAnexar);
}
void QVehiculos::S_Anexar()
{
	CQVVehiculos.append(new Vehiculo("",
					 (const char *)QLEPlacas->text(),
					 (const char *)QLEDescripcion->text()));

	AnexarRegistroALaTabla(QTDatos,
				QStringList () <<
				QLEPlacas->text () <<
				QLEDescripcion->text());

}
void QVehiculos::S_Registrar()
{
CQCtrVehiculos lCQCVehiculos(CSisDatCom,
			     CQCtrVehiculos::Registrar,
			     &CQVVehiculos);



}				
void QVehiculos::ConsultaVehiculos()
{
SiscomParametrosConsulta lSParConsulta;
	VVehiculos2.setAutoDelete(true);
	VVehiculos2.clear();
			lSParConsulta   <<
			new SiscomParametroConsulta("Todos") <<
			new SiscomParametroConsulta("Parametro2") <<
			new SiscomParametroConsulta("Parametro2");

SiscomGeneralOperacionesSrv lSGenOp(SDatCom,
				    (QPtrList<SiscomInformacion> *)&lSParConsulta);
			     lSGenOp.SiscomEjecutaEnvio("ConsultaVehiculos");
			     VVehiculos2.GeneraRegistros((const SiscomComunicaSrv *)lSGenOp);
MuestraVehiculos();
}
void QVehiculos::MuestraVehiculos()
{
Vehiculo *lVehiculo;
int lintContador;
	QTDatos->setNumRows(VVehiculos2.count());
	for(lVehiculo=VVehiculos2.first(),
	    lintContador=0;
	    lVehiculo;
	    lVehiculo=VVehiculos2.next(),
	    lintContador++)
	{
	    SISCOMAnexarRegistroALaTabla(lintContador,
	    			   QTDatos,
	    			   QStringList () << 
				   lVehiculo->ObtenPlacas()  <<
				   lVehiculo->ObtenDescripcion());

	}

}

