#include <IMP_ActualizaProductos.h>
#include<SISCOMComunicaciones++.h>

#include <QCtrlProductos.h>
#include <QCtrlFamilias.h>
#include <CQSisProductos.h>
#include <CQSisFamilias.h>
#include <CQSisOpTiendas4.h>
#include <CQSisPrecios.h>

#include <qpushbutton.h>
QActualizaProductos *InstanciaActualizaProductos(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QActualizaProductos((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QActualizaProductos::QActualizaProductos(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ActualizaProductos(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QActualizaProductos::~QActualizaProductos()
{

}

void QActualizaProductos::ConectaSlots()
{
	connect(QCtrProductos,
		SIGNAL(SignalProductos(CQSisProducto *)),
		SLOT(SlotProducto(CQSisProducto *)));
	connect(QCtrFamilias,
		SIGNAL(SignalFamilia(CQSisFamilia *)),
		SLOT(SlotFamilia(CQSisFamilia *)));
	connect(QLEClave,
		SIGNAL(textChanged(const QString &)),
		SLOT(SlotCambiandoClave(const QString &)));
	connect(QLEClave,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDsc()));
	connect(QTEDsc,
		SIGNAL(textChanged()),
		SLOT(SlotCambiandoDescripcion()));
	connect(QPBActualizar,
		SIGNAL(clicked()),
		SLOT(SlotActualiza()));

}
void QActualizaProductos::SlotActualiza()
{
CQSisProducto *lCQSProducto=FormaProducto();
	ActualizaProducto(lCQSProducto);
}
void QActualizaProductos::SlotPasaFocoDsc()
{
	SiscomPasaFocoControl(QTEDsc);
}
void QActualizaProductos::SlotCambiandoDescripcion()
{
	ValidaInformacion();
}
void QActualizaProductos::SlotCambiandoClave(const QString &pQSClave)
{
	ValidaInformacion();
}
void QActualizaProductos::SlotFamilia(CQSisFamilia *pCQSFamilia)
{
	CQSFamilia=pCQSFamilia;
	QLEFamSeleccionada->setText(CQSFamilia->SRegistrosPro2["Familia"]);
	SiscomPasaFocoControl(QLEClave);
	ValidaInformacion();
}
void QActualizaProductos::SlotProducto(CQSisProducto *pCQSProducto)
{
	CQSProducto=pCQSProducto;
	MuestraDatosProducto();
	PasaAFamilias();

}
void QActualizaProductos::ValidaInformacion()
{
	QTEDsc->setEnabled( CQSFamilia &&
			    QLEClave->text().length() );
	QPBActualizar->setEnabled(QLEClave->text().length() &&
				  CQSFamilia		   &&
				  QTEDsc->text().length());

}
void QActualizaProductos::PasaAFamilias()
{
	QCtrFamilias->IniciaControl();
	QCtrFamilias->setFocus();
	QCtrFamilias->PonFamiliaActual(CQSProducto->ObtenFamilia());
}
void QActualizaProductos::MuestraDatosProducto()
{
QLEProducto->setText(CQSProducto->SRegistrosPro2["Clave"]);
QLEFamilia->setText(CQSProducto->ObtenFamilia()->SRegistrosPro2["Familia"]);
QTEDscProducto->setText(CQSProducto->SRegistrosPro2["Dsc"]);
QTEDscFamilia->setText(CQSProducto->ObtenFamilia()->SRegistrosPro2["Dsc"]);
QLEClave->setText(CQSProducto->SRegistrosPro2["Clave"]);
QTEDsc->setText(CQSProducto->SRegistrosPro2["Dsc"]);
}
void QActualizaProductos::IniciaVariables()
{
	QCtrProductos->PonServidor(SisDatCom);
	QCtrFamilias->PonServidor(SisDatCom);
	QCtrProductos->IniciaControl();
	QCtrProductos->setFocus();
	//QCtrFamilias->IniciaControl();
}

CQSisProducto *QActualizaProductos::FormaProducto()
{
  return new CQSisProducto(
		CQSFamilia,
		CQSProducto->SRegistrosPro2["IdProducto"],
		SiscomObtenInformacionDelEdit(QLEClave),
		SiscomObtenInformacionDelEdit(QTEDsc));
}
void QActualizaProductos::ActualizaProducto(CQSisProducto *pCQSProducto)
{
CQSisOpTiendas4 lCQSOT4Actualiza(SisDatCom);
lCQSOT4Actualiza.ActualizaProducto(pCQSProducto);
}
void QActualizaProductos::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
