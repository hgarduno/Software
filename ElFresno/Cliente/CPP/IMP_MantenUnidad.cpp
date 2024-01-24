#include <IMP_MantenUnidad.h>
#include <Unidades.h>
#include <UnidadesProt2.h>
#include <SISCOMComunicaciones++.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QMantenUnidad::QMantenUnidad(SiscomDatCom *pSisDatCom,
			     Unidad *pUnidad,
			     QWidget* parent,
			     const char* name,
			     bool modal, WFlags fl )
    : MantenUnidad( parent, name, modal, fl ),
      UUnidad(pUnidad),
      SDatCom(pSisDatCom)
{
	MuestraUnidad();
	ConectaSlots();
	exec();
}

QMantenUnidad::~QMantenUnidad()
{
}
void QMantenUnidad::ConectaSlots()
{
	connect(QPBModifica,
		SIGNAL(clicked()),
		SLOT(S_ModificaUnidad()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));

}
void QMantenUnidad::MuestraUnidad()
{
	QLEUnidad->setText(UUnidad->ObtenNmbUnidad());
	QLEAbreviatura->setText(UUnidad->ObtenAbreviatura());
}
void QMantenUnidad::S_ModificaUnidad()
{
UnidadesProt2 lUnidadesProt2;
		lUnidadesProt2 <<
		new UnidadProt2(UUnidad->ObtenUnidad(),
				(const char *)QLEUnidad->text(),
				(const char *)QLEAbreviatura->text());
SiscomGeneralOperacionesSrv lSGenOperaciones(
				SDatCom,
				(QPtrList<SiscomInformacion> *)&lUnidadesProt2);
		lSGenOperaciones.SiscomEjecutaEnvio("ModificaUnidad");
						
				
}
void QMantenUnidad::S_Cancelar()
{
	done(1);
}
