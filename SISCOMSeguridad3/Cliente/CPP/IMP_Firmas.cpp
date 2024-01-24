#include <IMP_Firmas.h>

#include <SISCOMComunicaciones++.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


CQSisFirmas::CQSisFirmas(long plnIdAplicacion,
			 long plnIdPerfil,
			 CSISCOMDatComunicaciones *pCSisDatCom,
			  QWidget* parent, const char* name, WFlags fl )
    : Firmas( parent, name, fl ),
      CSisDatCom(pCSisDatCom),
      lngIdAplicacion(plnIdAplicacion),
      lngIdPerfil(plnIdPerfil) 
	
{
	ObtenUsuarios();
	MuestraUsuariosXPerfil();
	ConectaSlots();
	show();
}

CQSisFirmas::~CQSisFirmas()
{
}
void CQSisFirmas::ConectaSlots()
{
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionaUsuario(int,int,int,const QPoint &)));
	connect(QPBRegistraF,
		SIGNAL(clicked()),
		SLOT(SlotRegistraFirma()));
}
void CQSisFirmas::SlotRegistraFirma()
{
CQOperacionesUsuario lCQOUsuario(CSisDatCom);

	CQUsuariosA[intNumUsuario]->PonFirma((const char *)QLEFirma->text());
	CQUsuariosA[intNumUsuario]->PonPassword((const char *)QLEPassword->text());
	lCQOUsuario.RegistraFirma(CQUsuariosA[intNumUsuario]);
}
void CQSisFirmas::SlotSeleccionaUsuario(int pintFila,
					int ,
					int ,
					const QPoint &)
{
CQUsuario *lCQUsuario=CQUsuariosA[pintFila];
	QLEUsuario->setText(QString (lCQUsuario->ObtenNombre()) +
			    " "                       +
			    lCQUsuario->ObtenAPaterno() +
			    " "				+
			    lCQUsuario->ObtenAMaterno());
	QLEFirma->setText(lCQUsuario->ObtenFirma());
	QLEPassword->setText(lCQUsuario->ObtenPassword());
	intNumUsuario=pintFila;
}
void CQSisFirmas::ObtenUsuarios()
{
CQOperacionesUsuario lCQOUsuario(CSisDatCom);
   lCQOUsuario.ConsultaUsuarios(lngIdAplicacion,
				lngIdPerfil,
				CQUsuariosA);				        

}
void CQSisFirmas::MuestraUsuariosXPerfil()
{
CQUsuario *lCQUsuario;                    
int lintContador;
for(lintContador=0;
    (lCQUsuario=CQUsuariosA[lintContador]);
    lintContador++)
  AnexarRegistroALaTabla(QTDatos,
			 QStringList() << 
			 QString(lCQUsuario->ObtenNombre() + 
			 QString(" ") 			   +
			 lCQUsuario->ObtenAPaterno() +
			 QString(" ")                         +
			 lCQUsuario->ObtenAMaterno() ));
}
