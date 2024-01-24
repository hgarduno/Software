#include <IMP_PerfilReferencia.h>

#include <SISCOMComunicaciones++.h>
#include <SoporteAplicacionSeguridad.h>

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


CQSisPerfilReferencia::CQSisPerfilReferencia(CSISCOMDatComunicaciones *pCSisDatCom,
					     const char *pchrPtrPerfil,
					     const char *pchrPtrIdAplicacion,
					     QWidget* parent,
					     const char* name,
					     bool modal, 
					     WFlags fl )
    : PerfilReferencia( parent, name, modal, fl ),
	chrPtrNmbPerfil(pchrPtrPerfil),
	CSisDatCom(pCSisDatCom),
	chrPtrIdAplicacion(pchrPtrIdAplicacion)
{
	printf("CQSisPerfilReferencia::CQSisPerfilReferencia:%s\n",
		pchrPtrIdAplicacion);
	QLEPerfil->setText(pchrPtrPerfil);
	ConsultaPerfilesValidos();
	MuestraPerfiles();
	ConectaSlots();
	exec();
}

CQSisPerfilReferencia::~CQSisPerfilReferencia()
{
}
void CQSisPerfilReferencia::ConsultaPerfilesValidos()
{

           CQPerfilesDat=new CQPerfiles(CSisDatCom,
					chrPtrIdAplicacion,
					0);
	

}
void CQSisPerfilReferencia::ConectaSlots()
{
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionaPerfil(int,int,int,const QPoint &)));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
}
void CQSisPerfilReferencia::SlotAceptar()
{
	done(0);
}
void CQSisPerfilReferencia::SlotSeleccionaPerfil(int pintNumFila,int ,int ,const QPoint &)
{
QSiscomPerfilBD *lQSPerfilBD;

		lQSPerfilBD=(*CQPerfilesDat)[pintNumFila];
		QLEPerfileRef->setText(lQSPerfilBD->ObtenNmbPerfil());
		intNumPerfil=pintNumFila;
}
const char *CQSisPerfilReferencia::ObtenPerfilReferencia()
{
	return (*CQPerfilesDat)[intNumPerfil]->ObtenIdPerfil();
}
void CQSisPerfilReferencia::MuestraPerfiles()
{
int lintContador=0;
QSiscomPerfilBD *lQSPerfilBD;
QTDatos->setNumRows(0);
           while((lQSPerfilBD=(*CQPerfilesDat)[lintContador++]))
                AnexarRegistroALaTabla(QTDatos,
                                       QStringList() <<
                                       lQSPerfilBD->ObtenNmbPerfil());
}
