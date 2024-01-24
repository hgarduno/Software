#include <QCtrlPerfiles.h>
#include <SISCOMComunicaciones++.h>
#include <Seguridad3Protocolo2.h>
#include <qlayout.h>


QCtrlPerfiles::QCtrlPerfiles( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlPerfiles::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QIVPerfiles=new QIconView(this);
	QHBLayout->addWidget(QIVPerfiles);
}
void QCtrlPerfiles::MuestraPerfiles()
{
PerfilSeguridadProt2 *lPSegProt2;
	for(lPSegProt2=PerSegPro2.first();
	    lPSegProt2;
	    lPSegProt2=PerSegPro2.next())
	QIVPerfiles->insertItem(new QIVItemPerfil(lPSegProt2,QIVPerfiles));	  
}
void QCtrlPerfiles::IniciaControl()
{
	ConsultaPerfiles();
	MuestraPerfiles();
}
void QCtrlPerfiles::ConsultaPerfiles()
{
QOperacionesSeguridad3 lQOpSegPerfiles(SisDatCom);
	lQOpSegPerfiles.PerfilesAplicacion(chrPtrAplicacion,
					   PerSegPro2);
}
void QCtrlPerfiles::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlPerfiles::PonAplicacion(const char *pchrPtrAplicacion)
{
	chrPtrAplicacion=pchrPtrAplicacion;
}
void QCtrlPerfiles::ConectaSlots()
{
	connect(QIVPerfiles,
		SIGNAL(doubleClicked(QIconViewItem *)),
		SLOT(S_SeleccionoPerfil(QIconViewItem *)));
	connect(QIVPerfiles,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoPerfil(QIconViewItem *)));
}
void QCtrlPerfiles::S_SeleccionoPerfil(QIconViewItem *pQIVPerfil)
{
	if(pQIVPerfil)
	 emit SignalPerfil(((QIVItemPerfil *)pQIVPerfil)->ObtenPerfil());
}
void QCtrlPerfiles::setFocus()
{
	QIVPerfiles->setFocus();
	QIVPerfiles->setSelected(QIVPerfiles->firstItem(),true);
}
void QCtrlPerfiles::LimpiaSeleccion()
{
	QIVPerfiles->clearSelection();
}
void QCtrlPerfiles::Limpia()
{
	QIVPerfiles->clear();
}








QIVItemPerfil::QIVItemPerfil(PerfilSeguridadProt2 *pPSeg3Prot2,QIconView *pQIVParent):
		QIconViewItem(pQIVParent),
		PSeg3Prot2(pPSeg3Prot2)
{
	IniciaVariables();
}
void QIVItemPerfil::IniciaVariables()
{
/*
	setText(QString(PSeg3Prot2->SRegistrosPro2["DscPerfil"]));	
*/
	setText(QString(PSeg3Prot2->SRegistrosPro2["NmbPerfil"]));	
}
PerfilSeguridadProt2 *QIVItemPerfil::ObtenPerfil()
{
	return PSeg3Prot2;
}
