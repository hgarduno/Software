#include <IMP_PreciosServicios.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlPrecios.h>
#include <QCtrlServicios.h>
#include <QCtrlPersonas.h>

QPreciosServicios *InstanciaPreciosServicios(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPreciosServicios((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPreciosServicios::QPreciosServicios(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				PreciosServicios(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				CQSSGeneral(0),
				CQSSMedico(0)
{
ConectaSlots();
IniciaVariables();
}

QPreciosServicios::~QPreciosServicios()
{

}

void QPreciosServicios::ConectaSlots()
{
	
	connect(QCtrPersonas,
		SIGNAL(SignalPersona(CQSisPersona *)),
		SLOT(SlotMedico(CQSisPersona *)));
	connect(QCtrSGenerales,
		SIGNAL(SignalServicio(CQSisServicio *)),
		SLOT(SlotServicioGeneral(CQSisServicio *)));
	connect(QCtrSMedico,
		SIGNAL(SignalServicio(CQSisServicio *)),
		SLOT(SlotServicioMedico(CQSisServicio *)));
	connect(QCtrPrecios,
		SIGNAL(SignalPrecio(CQSisPrecio *)),
		SLOT(SlotPrecio(CQSisPrecio *)));
	connect(QLEPrecio,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoActualiza()));
	connect(QPBActualizar,
		SIGNAL(clicked()),
		SLOT(SlotActualiza()));

}
void QPreciosServicios::SlotPrecio(CQSisPrecio *pCQSPrecio)
{
printf("QPreciosServicios::SlotPrecio:%x\n",pCQSPrecio);
	CQSPrecio=pCQSPrecio;
	HabilitaActualizar();
}
void QPreciosServicios::SlotActualiza()
{
	Actualiza();
	CQSSGeneral=0;
	CQSSMedico=0;
	HabilitaActualizar();
}
void QPreciosServicios::SlotPasaFocoActualiza()
{
	HabilitaActualizar();
	SiscomPasaFocoControl(QPBActualizar);
}

void QPreciosServicios::SlotServicioMedico(CQSisServicio *pCQSServicio)
{
	CQSSMedico=pCQSServicio;
	CQSSGeneral=0;
	MuestraServicio(pCQSServicio);
	ConsultandoPreciosServicioMedico();
	SiscomPasaFocoControl(QLEPrecio);
	HabilitaActualizar();
}
void QPreciosServicios::SlotServicioGeneral(CQSisServicio *pCQSSGeneral)
{

	CQSSGeneral=pCQSSGeneral;
	CQSSMedico=0;
	MuestraServicio(pCQSSGeneral);
	ConsultandoPreciosServicio();
	SiscomPasaFocoControl(QLEPrecio);
	HabilitaActualizar();

}
void QPreciosServicios::SlotMedico(CQSisPersona *pCQSPersona)
{
	CQSPersona=pCQSPersona;
	ServiciosMedico();
	HabilitaActualizar();
}
void QPreciosServicios::IniciaVariables()
{
	QCtrPrecios->PonServidor(SisDatCom);
	QCtrPrecios->IniciaControl();
	QCtrSGenerales->PonServidor(SisDatCom);
	QCtrSGenerales->TipoServicio("ServiciosGenerales");
	QCtrSGenerales->IdMedico("");
	QCtrSGenerales->IniciaControl();
	QCtrPersonas->PonServidor(SisDatCom);
	QCtrPersonas->NombrePerfil("Medicos");
	QCtrPersonas->IniciaControl();

	QCtrPrecios->setFocus();
}

void QPreciosServicios::ServiciosMedico()
{
	QCtrSMedico->PonServidor(SisDatCom);
	QCtrSMedico->TipoServicio("ServiciosMedico");
	QCtrSMedico->IdMedico(CQSPersona->SRegistrosPro2["IdPersona"]);
	QCtrSMedico->IniciaControl();
}

void QPreciosServicios::ConsultandoPreciosServicio()
{
	ConsultaPreciosServicio();
	MuestraPreciosServicio();

}
void QPreciosServicios::ConsultaPreciosServicio()
{
CQSisOpPrecioServicio lCQSOPServicios(SisDatCom);
lCQSOPServicios.PreciosServicio((*CQSSGeneral)["IdServicio"],&CQSLPServicio);
}
void QPreciosServicios::MuestraPreciosServicio()
{
CQSisPrecioServicio *lCQSPServicio;
int lintContador;

	QTDatos->setNumRows(CQSLPServicio.count());
for(lintContador=0,
    lCQSPServicio=CQSLPServicio.first();
    lCQSPServicio;
    lintContador++,
    lCQSPServicio=CQSLPServicio.next())
 SiscomAnexarRegistroALaTabla(
 	lintContador,
	QTDatos,
	QStringList () 		<<
	(*lCQSPServicio->Precio())["Nombre"] <<
	(*lCQSPServicio)["Precio"]);
}
void QPreciosServicios::MuestraServicio(CQSisServicio *pCQSServicio)
{
	QLEServicio->setText((*pCQSServicio)["Descripcion"]);
}
void QPreciosServicios::ActualizaServicioGeneral()
{
CQSisOpPrecioServicio lCQSOPServicio(SisDatCom);
	lCQSOPServicio.ActualizaPrecio(
			new CQSisPrecioServicio(
				(*CQSSGeneral)["IdServicio"],
				(*CQSPrecio)["IdPrecio"],
				"",
				SiscomObtenInformacionDelEdit(QLEPrecio)));
}
void QPreciosServicios::ActualizaServicioMedico()
{

CQSisOpPrecioServicio lCQSOPServicio(SisDatCom);
	lCQSOPServicio.ActualizaPrecioMedico(
			new CQSisPrecioServicio(
				(*CQSSMedico)["IdServicio"],
				(*CQSPrecio)["IdPrecio"],
				(*CQSPersona)["IdPersona"],
				SiscomObtenInformacionDelEdit(QLEPrecio)));
}
void QPreciosServicios::Actualiza()
{
	if(CQSSGeneral)
	{
	ActualizaServicioGeneral();
	ConsultandoPreciosServicio();
	}

	if(CQSSMedico)
	{
	ActualizaServicioMedico();
	ConsultandoPreciosServicioMedico();
	}
}

void QPreciosServicios::ConsultandoPreciosServicioMedico()
{
	ConsultaPreciosServicioMedico();
	MuestraPreciosServicio();

}
void QPreciosServicios::ConsultaPreciosServicioMedico()
{
CQSisOpPrecioServicio lCQSOPServicios(SisDatCom);
lCQSOPServicios.PreciosServicio(
	(*CQSSMedico)["IdServicio"],
	(*CQSPersona)["IdPersona"],
	&CQSLPServicio);
}
void QPreciosServicios::HabilitaActualizar()
{
QPBActualizar->setEnabled(CQSPrecio &&
                          (CQSSGeneral || (CQSSMedico && CQSPersona)) &&
			  !QLEPrecio->text().isEmpty() );
}
