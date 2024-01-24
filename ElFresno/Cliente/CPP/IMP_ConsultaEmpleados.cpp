#include <IMP_ConsultaEmpleados.h>
#include <IMP_MuestraEmpleados.h>
#include <PersonasProt2.h>
#include <Personas.h>
#include <CQSiscomCom.h>

#include <SISCOMComunicaciones++.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QConsultaEmpleados::QConsultaEmpleados(SiscomDatCom *pSDatCom,
					QWidget* parent,
					const char* name, 
					bool modal, 
					WFlags fl )
    : ConsultaEmpleados( parent, name, modal, fl ),
    SDatCom(pSDatCom)
{
	ConectaSlots();
	exec();
}

QConsultaEmpleados::~QConsultaEmpleados()
{
}
void QConsultaEmpleados::ConectaSlots()
{
	connect(QPBConsulta,
		SIGNAL(clicked()),
		SLOT(S_Consulta()));

}
void QConsultaEmpleados::S_Consulta()
{
RegConsultasPersona lRCnsPersonas;
PersonasProt2 lPersonasProt2;
		lRCnsPersonas << 
		new RegConsultaPersona(
			SISCOMObtenInformacionDelEdit(QLENombre),
			SISCOMObtenInformacionDelEdit(QLEAPaterno),
			SISCOMObtenInformacionDelEdit(QLEAMaterno),
			SISCOMObtenInformacionDelEdit(QLERFC));
SiscomGeneralOperacionesSrv lSGenOp(SDatCom,
				(QPtrList<SiscomInformacion>*)&lRCnsPersonas);
		lSGenOp.SiscomEjecutaEnvio("ConsultaPersonas");
		lPersonasProt2.GeneraRegistros((const SiscomComunicaSrv *)lSGenOp);
QMuestraEmpleados lQMEmpleados((CQ_Personas *)lPersonasProt2);
	if(lQMEmpleados.ObtenBoton()==SISCOMGlobales::Aceptar)
	{
	   BTN_Opcion=SISCOMGlobales::Aceptar;
	   CQPersonas=lQMEmpleados.ObtenEmpleados();
	   done(1);
	}
}
CQ_Personas *QConsultaEmpleados::ObtenEmpleados()
{
	return CQPersonas;
}
SISCOMGlobales::BTN_Captura QConsultaEmpleados::ObtenBoton()
{
	return BTN_Opcion;
}
