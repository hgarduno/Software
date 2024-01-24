#include <IMP_Hospitalizacion.h>
#include <Seguridad3Protocolo2.h>
#include<SISCOMComunicaciones++.h>
#include <IMP_QControlFecha.h>
#include <QSisPacientes.h>
#include <CQSisEstadoConsulta.h>
#include <QCtrlServicios.h>
#include <QCtrlCotizas.h>
#include <QCtrlPrecios.h>
#include <CQSisServicios.h>
#include <CQSisProdCotiza.h>
QHospitalizacion *InstanciaHospitalizacion(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QHospitalizacion((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QHospitalizacion::QHospitalizacion(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Hospitalizacion(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
ConectaSlots();
IniciaVariables();
}

QHospitalizacion::~QHospitalizacion()
{

}

void QHospitalizacion::ConectaSlots()
{
	connect(QCtrSMedico,
		SIGNAL(SignalServicio(CQSisServicio *)),
		SLOT(SlotServicioMedico(CQSisServicio *)));
	connect(QCtrSGenerales,
		SIGNAL(SignalServicio(CQSisServicio *)),
		SLOT(SlotServicioGeneral(CQSisServicio *)));
	connect(QCtrConsultas,
		SIGNAL(SignalConsulta(CQSisConsulta *)),
		SLOT(SlotConsulta(CQSisConsulta *)));
	connect(QCtrPrecios,
		SIGNAL(SignalPrecio(CQSisPrecio *)),
		SLOT(SlotPrecio(CQSisPrecio *)));
	connect(QCtrFechaIni,
		SIGNAL(Signal_EnterA_o()),
		SLOT(SlotPasaFocoFechaFin()));
	connect(QCtrFechaFin,
		SIGNAL(Signal_EnterA_o()),
		SLOT(SlotPasaFocoConsultas()));
	connect(QPBRegistra,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));

	
	connect(QCtrCFarmacia,
		SIGNAL(SignalCotizacion(CQSisCliente *,
				    CQSisFormaPago *,
				    CQSisPrecio *,
				    CQSisProducto *,
				    CQSisProdCotiza *,
				    CQSisContacto *)),
		SLOT(SlotCotiza(CQSisCliente *,
				CQSisFormaPago *,
				CQSisPrecio *,
				CQSisProducto *,
				CQSisProdCotiza *,
				CQSisContacto *)));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(SlotAnexarProductoFarmacia()));
}

void QHospitalizacion::SlotAnexarProductoFarmacia()
{

	CQSLMHosp << new CQSisMatHosp(
			   CQSConsulta,
			   SUSeg3Firmado,
			   (*CQSPCFarmacia)["IdProducto"],
			   (*CQSPrecio)["IdPrecio"],
			   "",
			   "1");
	CQSLCotizando << Servicio(CQSPCFarmacia);	
	CotizandoConsulta();
	//HabilitaTerminar();
	SiscomAjustaFilas(QTDetalle);
	QCtrCFarmacia->setFocus();

}
void QHospitalizacion::SlotCotiza(CQSisCliente *,
			       CQSisFormaPago *,
			       CQSisPrecio *,
			       CQSisProducto *,
			       CQSisProdCotiza *pCQSPCProducto,
			       CQSisContacto *)
{
int lintSePuedeVender;
lintSePuedeVender=!strcmp((*pCQSPCProducto)["SePuedeVender"],"Si");
QPBAnexar->setEnabled(lintSePuedeVender);
if(lintSePuedeVender)
{
CQSPCFarmacia=pCQSPCProducto;
SiscomPasaFocoControl(QPBAnexar);
}

}
void QHospitalizacion::SlotRegistra()
{
	Registra();
	RegistraMaterialSesion();
	CQSLMHosp.clear();
}
void QHospitalizacion::SlotPasaFocoFechaFin()
{
	QCtrFechaFin->setFocus();
}
void QHospitalizacion::SlotPasaFocoConsultas()
{
	QCtrConsultas->setFocus();	
 	QCtrConsultas->RangoFechas(strdup((const char *)QCtrFechaIni->ObtenFecha()),
 			    strdup((const char *)QCtrFechaFin->ObtenFecha()));
 QCtrConsultas->IniciaControl();
}
void QHospitalizacion::SlotPrecio(CQSisPrecio *pCQSPrecio)
{
	CQSPrecio=pCQSPrecio;
	QCtrFechaIni->setFocus();

}
void QHospitalizacion::SlotConsulta(CQSisConsulta *pCQSConsulta)
{
CQSConsulta=pCQSConsulta;
ConsultandoConsulta();
}
void QHospitalizacion::SlotServicioMedico(CQSisServicio *pCQSServicio)
{
	CQSLCotizando << Servicio(pCQSServicio);
	CQSLMHosp << new CQSisMatHosp(CQSConsulta,
				     SUSeg3Firmado,
				     (*pCQSServicio)["IdServicio"],
				     (*CQSPrecio)["IdPrecio"],
				     "",
				     "1");
					
	CotizandoConsulta();
}
void QHospitalizacion::SlotServicioGeneral(CQSisServicio *pCQSServicio)
{

	CQSLCotizando << Servicio(pCQSServicio);
	CQSLMHosp << new CQSisMatHosp(CQSConsulta,
				     SUSeg3Firmado,
				     (*pCQSServicio)["IdServicio"],
				     (*CQSPrecio)["IdPrecio"],
				     "",
				     "1");
	CotizandoConsulta();
}
void QHospitalizacion::IniciaVariables()
{
 SUSeg3Firmado=(SisUsuarioSeg3 *)chrPtrArgumentos[0];
 QCtrFechaIni->ColocaFechaHoy();
 QCtrFechaFin->ColocaFechaHoy();
 QCtrConsultas->RangoFechas(strdup((const char *)QCtrFechaIni->ObtenFecha()),
 			    strdup((const char *)QCtrFechaFin->ObtenFecha()));
 QCtrConsultas->Servidor(SisDatCom);
 QCtrConsultas->IniciaControl();
 QCtrCFarmacia->PonServidor(SisDatCom);
 QCtrCFarmacia->IniciaControl(); 


	QCtrPrecios->PonServidor(SisDatCom);
	QCtrPrecios->IniciaControl();

 IniciaServicios();
 QCtrPrecios->setFocus();
}

void QHospitalizacion::IniciaServicios()
{
	QCtrSGenerales->PonServidor(SisDatCom);
	QCtrSGenerales->TipoServicio("ServiciosGenerales");
	QCtrSGenerales->IdMedico("");
	QCtrSGenerales->IniciaControl();

	QCtrSMedico->PonServidor(SisDatCom);
	QCtrSMedico->TipoServicio("ServiciosMedico");
	QCtrSMedico->IdMedico((*SUSeg3Firmado)["IdPersona"]);
	QCtrSMedico->IniciaControl();

}

CQSisCotizando *QHospitalizacion::Servicio(CQSisServicio *pCQSServicio)
{

return new CQSisCotizando(
		(*pCQSServicio)["IdServicio"],
		"",
		"",
		(*SUSeg3Firmado)["IdPersona"],
		(*CQSPrecio)["IdPrecio"],
		"",
		"",
		"1",
		"",
		"");
}

CQSisCotizando *QHospitalizacion::Servicio(CQSisProdCotiza *pCQSPCotiza)
{

return new CQSisCotizando(
		(*pCQSPCotiza)["IdProducto"],
		"",
		"",
		(*SUSeg3Firmado)["IdPersona"],
		(*CQSPrecio)["IdPrecio"],
		"",
		"",
		(*pCQSPCotiza)["Cantidad"],
		"",
		"");
}
void QHospitalizacion::MuestraCotizacion()
{
CQSisCotizando *lCQSCotizando;
int lintContador;
int lintNumRegistros;
lintNumRegistros=CQSLCotizando.count();
QTDetalle->setNumRows(lintNumRegistros);
for(lCQSCotizando=CQSLCotizando.first(),
    lintContador=0;
    lintContador<lintNumRegistros;
    lCQSCotizando=CQSLCotizando.next(),
    lintContador++)
SiscomAnexarRegistroALaTabla(
	lintContador,
	QTDetalle,
	QStringList() <<
	(*lCQSCotizando)["Clave"] 		<<
	(*lCQSCotizando)["Descripcion"]		<<
	(*lCQSCotizando)["Cantidad"]		<<
	(*lCQSCotizando)["Precio"]		<<
	(*lCQSCotizando)["Importe"]);
SiscomAjustaColumnas(QTDetalle);
QLCDNTConsulta->display(CQSLCotizando.ImporteTotal());
}
void QHospitalizacion::CotizandoConsulta()
{
CotizaConsulta();
MuestraCotizacion();
}
void QHospitalizacion::CotizaConsulta()
{
CQSisOpCotizando lCQSOCotizando(SisDatCom);
lCQSOCotizando.CotizaConsulta(&CQSLCotizando);
}

void QHospitalizacion::Registra()
{
	RegistraMaterialServicios();
}
void QHospitalizacion::RegistraMaterialServicios()
{
CQSisOpEstadoConsulta lCQSOEConsulta(SisDatCom);
lCQSOEConsulta.MaterialServicioHospitalizacion
			        ((*CQSConsulta)["IdConsulta"],
				&CQSLCotizando);
}

void QHospitalizacion::ConsultaConsulta()
{
CQSisOpCotizando lCQSOCotizando(SisDatCom);
lCQSOCotizando.CotizaConsulta((*CQSConsulta)["IdConsulta"],&CQSLCotizando);
}
void QHospitalizacion::ConsultandoConsulta()
{
ConsultaConsulta();
MuestraCotizacion();
}

void QHospitalizacion::RegistraMaterialSesion()
{
CQSisOpMatHosp lCQSOMHosp(SisDatCom);
	lCQSOMHosp.MatHosp(&CQSLMHosp);
}
