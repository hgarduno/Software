#include <QtImpAccesoServiSNTE.h>
#include <zSiscomAdministracionSeguridad.h>

#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>


#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>
#include <qlineedit.h> 
#include <qpushbutton.h>
#include <qfontdialog.h>
#include <qfont.h>
#include <qmessagebox.h>

#include <stdlib.h>

QtImpAccesoServiSNTE::QtImpAccesoServiSNTE(
			QWidget *pQWParent,
			const char *pchrPtrName,
			bool pbModal,
			WFlags pWFlags):
		AccesoServiSNTE(pQWParent,pchrPtrName,pbModal,pWFlags),
		intAceptar(0)
{
 ConectaSlots();
 exec();
}
void QtImpAccesoServiSNTE::IniciaVariables()
{
   zSiscomQt3::Foco(QLEUsuario);
}
void QtImpAccesoServiSNTE::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QLEUsuario,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAPassword()));
	connect(QLEPassword,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAAceptar()));
	connect(QPBTipoLetra,
		SIGNAL(clicked()),
		SLOT(SlotTipoLetra()));
}
void QtImpAccesoServiSNTE::SlotTipoLetra()
{
bool lbOpcion;
char lchrArrNombreArchivo[256];
const char *lchrPtrHome;
QFTipoLetra=QFontDialog::getFont(&lbOpcion,QFont( "Helvetica [Cronyx]", 10 ), this );	
if(lbOpcion==true)
{
lchrPtrHome=getenv("HOME");
sprintf(lchrArrNombreArchivo,
	"%s/.ServiSNTE/%s.TipoLetra",
	lchrPtrHome,
	zSiscomQt3::Texto(QLEUsuario));
setFont(QFTipoLetra);
zSiscomQt3::GuardaTipoLetra(lchrArrNombreArchivo,&QFTipoLetra);
}
}
void QtImpAccesoServiSNTE::SlotFocoAAceptar()
{
int lintAccesoSistema;
if((lintAccesoSistema=AccesoSistema()))
{
   QPBAceptar->setEnabled(true);
   QPBTipoLetra->setEnabled(true);
   zSiscomQt3::Foco(QPBAceptar);
   CargaTipoLetra();
   intAceptar=1;
}
else
{
  QMessageBox::information(this,"Aviso del Sistema","Usuario o Password Incorrecto");
  zSiscomQt3::Foco(QLEUsuario);
  intAceptar=0;
}

}
void QtImpAccesoServiSNTE::SlotFocoAPassword()
{
   zSiscomQt3::Foco(QLEPassword);
}
void QtImpAccesoServiSNTE::SlotAceptar()
{
	AccesoSistema();
	done(1);
}
void QtImpAccesoServiSNTE::SlotCancelar()
{
	intAceptar=0;
	done(1);
}
void QtImpAccesoServiSNTE::reject()
{

}
int QtImpAccesoServiSNTE::Aceptar(QFont *pQFTipoLetra)
{
  *pQFTipoLetra=QFTipoLetra;
  return intAceptar;
}

int QtImpAccesoServiSNTE::AccesoSistema()
{
zSiscomAdministracionSeguridad lzSisAdmSeguridad((zSiscomConexion *)gzSiscomConexion,
						 "SiscomCargaMenus",
						 "libSiscomServiSNTE.so");
if((zSisRegsAcceso=lzSisAdmSeguridad.SiscomMenusSistema(zSiscomQt3::Texto(QLEUsuario),
							    zSiscomQt3::Texto(QLEPassword))))
return 1;   
else
return 0;
}
zSiscomRegistros *QtImpAccesoServiSNTE::MenusSistema()
{
    return zSisRegsAcceso;
}
void QtImpAccesoServiSNTE::CargaTipoLetra()
{
const char *lchrPtrHome;
char lchrArrNombreArchivo[256];
lchrPtrHome=getenv("HOME");
sprintf(lchrArrNombreArchivo,
	"%s/.ServiSNTE/%s.TipoLetra",
	lchrPtrHome,
	zSiscomQt3::Texto(QLEUsuario));
if(zSiscomQt3::LeeTipoLetra(lchrArrNombreArchivo,&QFTipoLetra))
setFont(QFTipoLetra);
}
