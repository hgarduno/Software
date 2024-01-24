#include <QCtrlUsuarios.h>
#include <SISCOMComunicaciones++.h>
#include <Seguridad3Protocolo2.h>
#include <qlayout.h>


QCtrlUsuarios::QCtrlUsuarios( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
}
void QCtrlUsuarios::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QIVPerfiles=new QIconView(this);
	QHBLayout->addWidget(QIVPerfiles);
	ConectaSlots();
}
void QCtrlUsuarios::MuestraUsuarios()
{
SisUsuarioSeg3 *lSisUSeg3;
	for(lSisUSeg3=SisUsSeg3.first();
	    lSisUSeg3;
	    lSisUSeg3=SisUsSeg3.next())
	QIVPerfiles->insertItem(new QIVItemUsuario(lSisUSeg3,QIVPerfiles));	  
}
void QCtrlUsuarios::LimpiaVariables()
{
	SisUsSeg3.clear();
	QIVPerfiles->clear();
}
void QCtrlUsuarios::IniciaControl()
{
	LimpiaVariables();
	ConsultaUsuarios();
	MuestraUsuarios();
}
void QCtrlUsuarios::ConectaSlots()
{
	connect(QIVPerfiles,
		SIGNAL(doubleClicked(QIconViewItem *)),
		SLOT(S_SeleccionoUsuario(QIconViewItem *)));
	connect(QIVPerfiles,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoUsuario(QIconViewItem *)));
}
void QCtrlUsuarios::S_SeleccionoUsuario(QIconViewItem *pQIVItem)
{
	if(pQIVItem)
	SignalUsuario(((QIVItemUsuario *)pQIVItem)->ObtenUsuario());

}
void QCtrlUsuarios::ConsultaUsuarios()
{
OpUsuariosSeg3 lOpUsSeg3(SisDatCom);
SiscomLog("%s\t%s\n",
	chrPtrAplicacion,
	chrPtrIdPerfil);
	lOpUsSeg3.ObtenUsuarios(chrPtrAplicacion,
				chrPtrIdPerfil,
				&SisUsSeg3);
SiscomLog("Termino:%s\t%s",chrPtrAplicacion,chrPtrIdPerfil);
}
void QCtrlUsuarios::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlUsuarios::PonAplicacion(const char *pchrPtrAplicacion)
{
	chrPtrAplicacion=pchrPtrAplicacion;
}
void QCtrlUsuarios::PonIdPerfil(const char *pchrPtrIdPerfil)
{
	chrPtrIdPerfil=pchrPtrIdPerfil;
}
void QCtrlUsuarios::LimpiaSeleccion()
{
	QIVPerfiles->clearSelection();
}
void QCtrlUsuarios::setFocus()
{
	QIVPerfiles->setFocus();
	QIVPerfiles->setSelected(QIVPerfiles->firstItem(),true);
}

QIVItemUsuario::QIVItemUsuario(SisUsuarioSeg3 *pSisUSeg3,QIconView *pQIVParent):
		QIconViewItem(pQIVParent),
		SisUSeg3(pSisUSeg3)
{
	IniciaVariables();
}
void QIVItemUsuario::IniciaVariables()
{
	setText(QString(SisUSeg3->SRegistrosPro2["Firma"]));	
}
SisUsuarioSeg3 *QIVItemUsuario::ObtenUsuario()
{
	return SisUSeg3;
}
