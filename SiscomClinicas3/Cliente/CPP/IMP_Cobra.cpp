#include <IMP_Cobra.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlRecetas.h>
#include <CQSisObjetos.h>
#include <CQSisConsultas.h>
#include <CQSisEstadoConsulta.h>

#include <Seguridad3Protocolo2.h>
#include <qlcdnumber.h>
QCobra::QCobra(CQSisConsulta *pCQSConsulta,
		SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				Cobra(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				CQSConsulta(pCQSConsulta)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCobra::~QCobra()
{

}

void QCobra::ConectaSlots()
{
	connect(QPBRCobro,
		SIGNAL(clicked()),
		SLOT(SlotRegistraCobro()));

}
void QCobra::SlotRegistraCobro()
{
	RegistraCobro();
	done(1);

}
CQSisEstadoConsulta *QCobra::ConsultaCobrada()
{
return new CQSisEstadoConsulta(
		(*CQSConsulta)["IdConsulta"],
		"3",
		(*SUSeg3Firmado)["IdPersona"],
		"");
}
void QCobra::RegistraCobro()
{
CQSisOpEstadoConsulta lCQSOEdoConsulta(SisDatCom);
SiscomRegistrosPro2 *lSRegistrosPro2;
lCQSOEdoConsulta.EstadoConsulta(ConsultaCobrada(),
				&lSRegistrosPro2);
}
void QCobra::IniciaVariables()
{
	QCtrRecetas->PonServidor(SisDatCom);
	QCtrRecetas->Consulta(CQSConsulta);
	QCtrRecetas->IniciaControl();
	MuestraPaciente();
	CotizandoConsulta();
	SUSeg3Firmado=(SisUsuarioSeg3 *)chrPtrArgumentos[0];
}
void QCobra::MuestraPaciente()
{
char lchrArrNombre[256];
CQSisObjetos::NombreCompleto(CQSConsulta->Paciente(),
			     lchrArrNombre);
QLEPaciente->setText(lchrArrNombre);
}
void QCobra::ConsultaConsulta()
{
CQSisOpCotizando lCQSOCotizando(SisDatCom);
lCQSOCotizando.CotizaConsulta((*CQSConsulta)["IdConsulta"],&CQSLCotizando);

}
void QCobra::MuestraCotizacion()
{
CQSisCotizando *lCQSCotizando;
int lintContador;
int lintNumRegistros=CQSLCotizando.count();
QTDatos->setNumRows(lintNumRegistros);
for(lintContador=0,
    lCQSCotizando=CQSLCotizando.first();
    lintContador<lintNumRegistros;
    lintContador++,
    lCQSCotizando=CQSLCotizando.next())
SiscomAnexarRegistroALaTabla(
	lintContador,
	QTDatos,
	QStringList() 			<<
	(*lCQSCotizando)["Clave"]	<<
	(*lCQSCotizando)["Descripcion"]	<<
	(*lCQSCotizando)["Precio"]	<<
	(*lCQSCotizando)["Cantidad"]	<<
	(*lCQSCotizando)["Importe"]);
SiscomAjustaColumnas(QTDatos);
SiscomAjustaFilas(QTDatos);
QLCDNImporte->display(CQSLCotizando.ImporteTotal());
}
void QCobra::CotizandoConsulta()
{
	ConsultaConsulta();
	MuestraCotizacion();
}
