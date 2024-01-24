
#include <QCtrlServicios.h>
#include <SISCOMComunicaciones++.h>
#include <CQSisServicios.h>
#include <qlayout.h>
#include <qtable.h>


QCtrlServicios::QCtrlServicios( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlServicios::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QTServicios=new QTable(this);
	QTServicios->setReadOnly(true);
	QHBLayout->addWidget(QTServicios);
}
void QCtrlServicios::MuestraServicios()
{
CQSisServicio *lCQSServicio;
int lintContador;
QTServicios->setNumRows(CQSLServicio.count());
QTServicios->setNumCols(2);

for(lCQSServicio=CQSLServicio.first(),
    lintContador=0;
    lCQSServicio;
    lCQSServicio=CQSLServicio.next(),
    lintContador++)
SiscomAnexarRegistroALaTabla(
	lintContador,
	QTServicios,
	QStringList() <<
	lCQSServicio->SRegistrosPro2["Clave"]	<<
	lCQSServicio->SRegistrosPro2["Descripcion"]);
SiscomAjustaColumnas(QTServicios);
}
void QCtrlServicios::IniciaControl()
{
	ConsultaServicios();
	MuestraServicios();
}
void QCtrlServicios::ConsultaServicios()
{
CQSisOpServicio lCQSOServicio(SisDatCom);
lCQSOServicio.Servicio(chrPtrTipoServicio,
		       chrPtrIdMedico,
		       &CQSLServicio);
}
void QCtrlServicios::TipoServicio(const char *pchrPtrTipoServicio)
{
	chrPtrTipoServicio=pchrPtrTipoServicio;
}
void QCtrlServicios::IdMedico(const char *pchrPtrIdMedico)
{
	chrPtrIdMedico=pchrPtrIdMedico;
}
void QCtrlServicios::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}

void QCtrlServicios::ConectaSlots()
{
	connect(QTServicios,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotServicio(int,int,int,const QPoint &)));
}
void QCtrlServicios::SlotServicio(int pintNFila,
				  int ,
				  int,
				  const QPoint &)
{
	if(pintNFila!=-1)
	emit SignalServicio(CQSLServicio.at(pintNFila));
}

void QCtrlServicios::setFocus()
{
}
void QCtrlServicios::LimpiaSeleccion()
{
}
void QCtrlServicios::Limpia()
{
}

