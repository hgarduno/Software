#include <IMP_FirmaSistema.h>
#include <IMP_Firmate.h>
#include <QCtrlServidoresSiscom.h>
#include <QCtrlPerfiles.h>
#include <QCtrlUsuarios.h>
#include<SISCOMComunicaciones++.h>
#include <Seguridad3Protocolo2.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qfontdialog.h>
QFirmaSistema::QFirmaSistema(QWidget *pQWParent,       
			     const char *pchrPtrName,
			     bool pbModal,
			     WFlags pWFlags):	      
				FirmaSistema(pQWParent,pchrPtrName,pbModal,pWFlags),
				QWParent(pQWParent),
				intOpcion(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QFirmaSistema::~QFirmaSistema()
{

}

void QFirmaSistema::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QCtrServidores,
		SIGNAL(SignalServidor(SiscomDatCom *)),
		SLOT(SlotServidor(SiscomDatCom *)));
	connect(QCtrPerfiles,
		SIGNAL(SignalPerfil(PerfilSeguridadProt2 *)),
		SLOT(SlotPerfil(PerfilSeguridadProt2 *)));
	connect(QCtrUsuarios,
		SIGNAL(SignalUsuario(SisUsuarioSeg3 *)),
		SLOT(SlotUsuario(SisUsuarioSeg3 *)));
	connect(QPBTipoLetra,
		SIGNAL(clicked()),
		SLOT(SlotTipoLetra()));
}
void QFirmaSistema::SlotTipoLetra()
{
bool lbRegreso;
	QFLetra=QFontDialog::getFont(&lbRegreso,
				     QFont("Times",12),
				     this);
if(lbRegreso)
{
   if(QWParent)
   {
     SiscomEscribeLog3Qt("Se Reasigna el tipo de letra");
     QWParent->setFont(QFLetra);
   }
}
else
{

}
}
void QFirmaSistema::IniciaVariables()
{
	AsignaNombreArchivoServidores();
	QCtrServidores->IniciaControl();
}
void QFirmaSistema::AsignaNombreArchivoServidores()
{
const char *lchrPtrArchivo=getenv("ArchivoServidores");
SiscomLog("Se cargaran los servidores de %s",
		  lchrPtrArchivo);
if(lchrPtrArchivo)
 QCtrServidores->PonArchivoComunicaciones(lchrPtrArchivo);
 else
 SiscomLog("No Se ha definido la variable:\"ArchivoServidores\"\n");
}
void QFirmaSistema::SlotUsuario(SisUsuarioSeg3 *pSUsuarioSeg3)
{
	SUsuarioSeg3=pSUsuarioSeg3;
	Firmate();
}
void QFirmaSistema::SlotCancelar()
{
	intOpcion=0;
	done(1);
}
void QFirmaSistema::SlotServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
	MuestraPerfiles();
	QCtrPerfiles->setFocus();
}
void QFirmaSistema::SlotAceptar()
{
	if(intValidaPassword)
	{
	intOpcion=1;
	done(1);
	}
}

void QFirmaSistema::SlotPerfil(PerfilSeguridadProt2 *pPSeguridadPro2)
{
	PSeguridadPro2=pPSeguridadPro2;
	chrPtrIdAplicacion=pPSeguridadPro2->SRegistrosPro2["IdAplicacion"];
	chrPtrIdPerfil=pPSeguridadPro2->SRegistrosPro2["IdPerfil"];
	MuestraUsuarios();
	QCtrUsuarios->setFocus();
}
void QFirmaSistema::MuestraUsuarios()
{
	QCtrUsuarios->PonServidor(SisDatCom);
	QCtrUsuarios->PonAplicacion(chrPtrAplicacion);
	QCtrUsuarios->PonIdPerfil(
		 PSeguridadPro2->SRegistrosPro2["IdPerfil"]);
	
	QCtrUsuarios->IniciaControl();

}
int QFirmaSistema::OpcionFirma()
{
return intOpcion;
}
void QFirmaSistema::closeEvent(QCloseEvent *)
{

}
const char *QFirmaSistema::IdPerfil()
{
	return chrPtrIdPerfil;
}
const char *QFirmaSistema::IdAplicacion()
{
	return chrPtrIdAplicacion;
}
SiscomDatCom *QFirmaSistema::ServidorSiscom()
{
	return SisDatCom;
}
SisUsuarioSeg3 *QFirmaSistema::Usuario()
{
	return SUsuarioSeg3;
}
const char *QFirmaSistema::ObtenAplicacion()
{
const char *lchrPtrAplicacion=getenv("Aplicacion");
if(lchrPtrAplicacion)
return lchrPtrAplicacion;
else
{
QMessageBox::information(this,
			 "Siscom Tiendas 4",
			 "No se ha definido la variable:\"Aplicacion\""
			 );
exit(1);
}
}
void QFirmaSistema::MuestraPerfiles()
{

	chrPtrAplicacion=ObtenAplicacion();
	SiscomEscribeLog3Qt("%s La Aplicacion",chrPtrAplicacion);
	QCtrPerfiles->PonAplicacion(chrPtrAplicacion);
	QCtrPerfiles->PonServidor(SisDatCom);
	QCtrPerfiles->IniciaControl();
}
void QFirmaSistema::Firmate()
{
QFirmate lQFirmate(SisDatCom,
		   SUsuarioSeg3);
  if((intValidaPassword=lQFirmate.ValidacionPassword()))
  {
  intOpcion=1;
  done(1);
  }
}
const QFont QFirmaSistema::Letra()
{
return QFLetra;
}
