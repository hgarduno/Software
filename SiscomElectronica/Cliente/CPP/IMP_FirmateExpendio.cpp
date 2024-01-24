#include <IMP_FirmateExpendio.h>
#include <SISCOMComunicaciones++.h>
#include <Personas.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qmessagebox.h>

QFirmateExpendio::QFirmateExpendio(SiscomDatCom *pSisDatCom,
				  const char *pchrPtrAplicacion,
				  const char *pchrPtrIdExpendio,
				   Persona *pEmpleado,
				   QWidget* parent, const char* name, bool modal, WFlags fl )
    : FirmateExpendio( parent, name, modal, fl ),
        SisDatCom(pSisDatCom),
    	Empleado(pEmpleado),
	chrPtrAplicacion(pchrPtrAplicacion),
	intIntentos(0),
	intEdoValidacionUsuario(0),
	chrPtrIdExpendio(pchrPtrIdExpendio)
{
	QLEFirma->setText(Empleado->SRegistrosPro2["Firma"]);
	SiscomPasaFocoControl(QLEPassword);
	ConectaSlots();
	exec();
}

QFirmateExpendio::~QFirmateExpendio()
{
}
void QFirmateExpendio::ConectaSlots()
{
	connect(QLEPassword,
		SIGNAL(returnPressed()),
		SLOT(S_IntrodujoPassword()));

}
void QFirmateExpendio::S_IntrodujoPassword()
{
ConsultaPersonas lCnsPersonas;
Persona *lPersonaReg;
	
	Empleado->SiscomActualizaCampo("Password",
				       (const char *)QLEPassword->text());
	lPersonaReg=lCnsPersonas.ValidaFirmaEmpleado(SisDatCom,	
					 chrPtrAplicacion,
					 chrPtrIdExpendio,
					 Empleado);
	
/*
 * Jueves 31 de enero 2008
 * El cambio del estado de la firma, trae mas problemas
 * que lo que arregla, en el contexto actual de las 
 * aplicaciones no es necesario verificar si el usuario
 * ya esta firmado o 
 * no
 *
 */

/*
 *
 *
 *
 *
 *	if(lPersonaReg  &&
 *	   !strcmp(lPersonaReg->SRegistrosPro2["EdoFirma"],"1"))
 *	{
 *		QMessageBox::information(this,"SISCOM Tiendas","El Usuario esta firmado ya");
 *		intIntentos=4;
 *	}
 */
	if(intIntentos<4 &&
	   lPersonaReg   )
	{
	intEdoValidacionUsuario=1;
	done(1);
	}
	else
	if(intIntentos++>=4)
	{
	intEdoValidacionUsuario=0;
	done(1);
	}

}
int QFirmateExpendio::ObtenEdoValidacionUsuario()
{
	return intEdoValidacionUsuario;
}
