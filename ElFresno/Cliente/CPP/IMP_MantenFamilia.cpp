#include <IMP_MantenFamilia.h>

#include <SISCOMComunicaciones++.h>
#include <Familias.h>
#include <FamiliasProt2.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QMantenFamilia::QMantenFamilia(SiscomDatCom *pSisDatCom,
			       Familia *pFamilia,
			       QWidget* parent,
			       const char* name,
			       bool modal,
			       WFlags fl )
    : MantenFamilia( parent, name, modal, fl ),
      FFamilia(pFamilia),
      SDatCom(pSisDatCom)
{
	ConectaSlots();
	MuestraFamilia();
	exec();
}

QMantenFamilia::~QMantenFamilia()
{
}
void QMantenFamilia::ConectaSlots()
{
	connect(QPBModifica,
		SIGNAL(clicked()),
		SLOT(S_Modifica()));

}
void QMantenFamilia::S_Modifica()
{
FamiliasProt2 lFamiliasProt2;
		lFamiliasProt2 << 
		new FamiliaProt2(FFamilia->ObtenIdFamilia(),
				 (const char *)QLEFamilia->text(),
				 (const char *)QLEDescripcion->text());
SiscomGeneralOperacionesSrv lSGenOperaciones(SDatCom,
					     (QPtrList<SiscomInformacion> *)&lFamiliasProt2);
	lSGenOperaciones.SiscomEjecutaEnvio("ModificaFamilia");
	done(1);
}

void QMantenFamilia::MuestraFamilia()
{
	QLEFamilia->setText(FFamilia->ObtenNmbFamilia());
	QLEDescripcion->setText(FFamilia->ObtenDscFamilia());
}
