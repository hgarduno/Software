#include <QCtrlServidoresSiscom.h>
#include <SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qfiledialog.h>
#include <qlayout.h>
#include <stdio.h>

QCtrlServidoresSiscom::QCtrlServidoresSiscom( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlServidoresSiscom::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QIVServidores=new QIconView(this);
	QHBLayout->addWidget(QIVServidores);

}
void QCtrlServidoresSiscom::setFocus()
{
	QIVServidores->setFocus();
}
void QCtrlServidoresSiscom::LimpiaSeleccion()
{
	QIVServidores->clearSelection();
}
void QCtrlServidoresSiscom::ConectaSlots()
{
	connect(QIVServidores,
		SIGNAL(doubleClicked(QIconViewItem *)),
		SLOT(S_SeleccionoServidor(QIconViewItem *)));
	connect(QIVServidores,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoServidor(QIconViewItem *)));
	connect(QIVServidores,
		SIGNAL(clicked(QIconViewItem *)),
		SLOT(S_MarcaServidor(QIconViewItem *)));
}	
void QCtrlServidoresSiscom::S_MarcaServidor(QIconViewItem *pQIVServidor)
{
	if(pQIVServidor)
	 emit SignalMarcaServidor(((QIVItemServidor *)pQIVServidor)->ObtenServidor());

}
void QCtrlServidoresSiscom::S_SeleccionoServidor(QIconViewItem *pQIVServidor)
{
	if(pQIVServidor)
	emit SignalServidor(((QIVItemServidor *)pQIVServidor)->ObtenServidor());
}
void QCtrlServidoresSiscom::PonArchivoComunicaciones(const char *pchrPtrAComunicaciones)
{
	chrPtrArcComunicaciones=pchrPtrAComunicaciones;
}
void QCtrlServidoresSiscom::IniciaControl()
{
	MuestraArchivos();
}
void QCtrlServidoresSiscom::MuestraArchivos()
{
FILE *lFleArchivo;
char lchrArrLinea[256];
char *lchrPtrDirIp;
char *lchrPtrPtoCom;
char *lchrPtrNombre;
QIVItemServidor *lQIVItemServidor;
	if(!(lFleArchivo=fopen(chrPtrArcComunicaciones,"r")))
	{
	  SiscomEscribeLog3Qt("NO se pudo abrir %s",chrPtrArcComunicaciones);		
	}
	else
	{
	  while(!SiscomLeeLineaArchivo(lFleArchivo,lchrArrLinea))
	  {
	  	SiscomEscribeLog3Qt("La Linea:%s",lchrArrLinea);
		ObtenDatosServidores(lchrArrLinea,
				     &lchrPtrDirIp,
				     &lchrPtrPtoCom,
				     &lchrPtrNombre);
		lQIVItemServidor=new QIVItemServidor(
					lchrPtrNombre,
					new SiscomDatCom(atoi(lchrPtrPtoCom),
							 lchrPtrDirIp),
							 QIVServidores);
		QIVServidores->insertItem((QIconViewItem *)lQIVItemServidor);
							
	  }
	}
}
void QCtrlServidoresSiscom::ObtenDatosServidores(const char *pchrPtrCadena,
						 char **pchrPtrDirIp,
						 char **pchrPtrPtoCom,
						 char **pchrPtrNombre)
{
char lchrArrBuffer[256];
char **lchrPtrCadenas;
	if(SiscomAnalizaCadenas(pchrPtrCadena,
			     '@',
			     lchrArrBuffer,
			     &lchrPtrCadenas))
	{
		*pchrPtrDirIp=lchrPtrCadenas[0];
		*pchrPtrPtoCom=lchrPtrCadenas[1];
		*pchrPtrNombre=lchrPtrCadenas[2];
	}
}

QIVItemServidor::QIVItemServidor(const char *pchrPtrNombre,
				  SiscomDatCom *pSisDatCom,
				 QIconView *pQIVPadre):
		QIconViewItem(pQIVPadre),
		SisDatCom(pSisDatCom),
		chrPtrNombre(pchrPtrNombre)
{
	IniciaVariables();
}
void QIVItemServidor::IniciaVariables()
{
/*
	setText((QString(SisDatCom->SiscomObtenDireccionIp())	+
		"\n"						+
		QString().sprintf("%d",SisDatCom->SiscomObtenPuertoCom())));
*/

	setText(QString(chrPtrNombre) 					+	
		"["		      					+
		 QString().sprintf("%s:%d",
		 		   SisDatCom->SiscomObtenDireccionIp(),
				   SisDatCom->SiscomObtenPuertoCom())	+
		 "]");

}
SiscomDatCom *QIVItemServidor::ObtenServidor()
{
	return SisDatCom;
}
