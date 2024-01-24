
#include <QCtrlSepomexComunicas.h>
#include <SISCOMComunicaciones++.h>
#include <CQSisSepomexComunicas.h>
#include <QSisDirecciones.h>
#include <qlayout.h>
#include <qtabwidget.h>


QCtrlSepomexComunicas::QCtrlSepomexComunicas( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
printf("QCtrlSepomexComunicas::QCtrlSepomexComunicas\n");
	IniciaVariables();
	ConectaSlots();
}
void QCtrlSepomexComunicas::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QTWDatos=new QTabWidget(this,"QTWDatos");
	QHBLayout->addWidget(QTWDatos);
}
void QCtrlSepomexComunicas::MuestraSepomexComunicas()
{
}
void QCtrlSepomexComunicas::Argumentos(char **pchrPtrArgumentos)
{
	chrPtrArgumentos=pchrPtrArgumentos;
}
void QCtrlSepomexComunicas::IdPersona(const char *pchrPtrIdPersona)
{
	chrPtrIdPersona=pchrPtrIdPersona;
}
void QCtrlSepomexComunicas::Direcciones()
{
QHBoxLayout *lQHBLayout;
   lQHBLayout=new QHBoxLayout(QTWDatos);
   QSDirecciones=new QSisDirecciones(QTWDatos,"QSisDirecciones");
   QSDirecciones->Servidor(SisDatCom);
   QSDirecciones->Argumentos(chrPtrArgumentos);
   QSDirecciones->IdPersona(chrPtrIdPersona);
   QSDirecciones->IniciaControl();
   lQHBLayout->addWidget(QSDirecciones);
   QTWDatos->insertTab(QSDirecciones,"Direcciones");
   QSDirecciones->show();
}
void QCtrlSepomexComunicas::IniciaControl()
{
	Direcciones();

}
void QCtrlSepomexComunicas::ConsultaSepomexComunicas()
{
}
void QCtrlSepomexComunicas::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}

void QCtrlSepomexComunicas::ConectaSlots()
{

}

void QCtrlSepomexComunicas::setFocus()
{
	
}
void QCtrlSepomexComunicas::LimpiaSeleccion()
{
}
void QCtrlSepomexComunicas::Limpia()
{
}








