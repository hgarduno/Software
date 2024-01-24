#include <IMP_Familias.h>
#include <IMP_MantenFamilia.h>
#include <SISCOMComunicaciones++.h>


#include <CQSiscomCom.h>
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

QFamilias *InstanciaFamilias(void *pCSisDatCom,
			     void *pQWParent,
			     const char *pchrPtrName,
			     int pintWFlags)
{
	return new QFamilias((CSISCOMDatComunicaciones *)pCSisDatCom,
			     (QWidget *)pQWParent,
			     pchrPtrName,
			     pintWFlags);
}

QFamilias::QFamilias(CSISCOMDatComunicaciones *pCSisDatCom,
			 QWidget* parent, const char* name, WFlags fl )
    : Familias( parent, name, fl ),
	CSisDatCom(pCSisDatCom)
{
	SDatCom=new SiscomDatCom(atoi(getenv("PtoComSvr2")),
	                         CSisDatCom->ObtenDirIpSvr());
	ConsultaLasFamilias();
	ConectaSlots();
	IniciaVariables();
}

QFamilias::~QFamilias()
{
}
void QFamilias::ConectaSlots()
{
	connect(QLEFamilia,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoDscFamilia()));
	connect(QLEDscFamilia,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexar()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_Registrar()));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint  &)),
		SLOT(S_SeleccionaFamilia(int,int,int,const QPoint &)));
	connect(QTDatos,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(S_MantenFamilia(int,int,int,const QPoint &)));
}
void QFamilias::S_SeleccionaFamilia(int pintNFila,
				    int,
				    int,
				    const QPoint &)
{
	if(pintNFila!=-1)
	  QTDatos->selectRow(pintNFila);

}
void QFamilias::S_MantenFamilia(int pintNFila,
				int,
				int,
				const QPoint &)
{
 QMantenFamilia lQMFamilia(SDatCom,
 			   CQ_Familias.at(pintNFila));
ConsultaLasFamilias();
 			  
}
void QFamilias::S_Registrar()
{
 CQCtrFamilias lCQCFamilias(CSisDatCom,
			    CQCtrFamilias::Registrar,
			    &CQ_Familias);
	ConsultaLasFamilias();
}
void QFamilias::S_Anexar()
{
	AnexarRegistroALaTabla(QTDatos,
				QStringList () <<
				QLEFamilia->text () <<
				QLEDscFamilia->text() );	

	CQ_Familias.append(new Familia("",
				       (const char *)QLEFamilia->text(), 
				       (const char *)QLEDscFamilia->text()));
	PasaFocoControl(QLEFamilia);
}
void QFamilias::S_PasaFocoDscFamilia()
{
	PasaFocoControl(QLEDscFamilia);
}
void QFamilias::S_PasaFocoAnexar()
{
	PasaFocoControl(QPBAnexar);
}

void QFamilias::IniciaVariables()
{
	PasaFocoControl(QLEFamilia);
}
void QFamilias::ConsultaLasFamilias()
{
CQ_Familias.setAutoDelete(true);
CQ_Familias.clear();
CQCtrFamilias lCQCFamilias(CSisDatCom,
			   CQCtrFamilias::Consultar,
			   &CQ_Familias);
Familia *lF_Familia;
int lintContador;
	QTDatos->setNumRows(CQ_Familias.count());	
	for(lF_Familia=CQ_Familias.first(),
	    lintContador=0;
	    lF_Familia;
	    lF_Familia=CQ_Familias.next(),
	    lintContador++)
	SISCOMAnexarRegistroALaTabla(lintContador,
				QTDatos,
			      QStringList () <<
			      lF_Familia->ObtenNmbFamilia() <<
			      lF_Familia->ObtenDscFamilia() );

	 
}
