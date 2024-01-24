#include <IMP_Usuarios.h>

 #include <SoporteAplicacionSeguridad.h>

#include <SISCOMComunicaciones++.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

CQSisUsuarios::CQSisUsuarios(CSISCOMDatComunicaciones *pCSisDatCom,
			     long plngIdAplicacion,
			     long plngIdPerfil,
				 QWidget* parent, const char* name, WFlags fl )
    : Usuarios( parent, name, fl ),
	CSisDatCom(pCSisDatCom),
	lngIdAplicacion(plngIdAplicacion),
	lngIdPerfil(plngIdPerfil)
{
	ConectaSlots();	
	show();
}

CQSisUsuarios::~CQSisUsuarios()
{
}
void CQSisUsuarios::ConectaSlots()
{
	connect(QPBRUsuario,
		SIGNAL(clicked()),
		SLOT(SlotRUsuario()));
}
void CQSisUsuarios::SlotRUsuario()
{
CQOperacionesUsuario lCQOUsuario(CSisDatCom);
CQUsuario *lCQUsuario=new CQUsuario(lngIdAplicacion,
				    lngIdPerfil,
				    (const char *)QLENombre->text(),
				    (const char *)QLEAPaterno->text(),
				    (const char *)QLEAMaterno->text());
	lCQOUsuario.RegistraUsuario(lCQUsuario);

	delete lCQUsuario;

	
				 


}
