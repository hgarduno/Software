#include <IMP_ClavesSatSiscom.h>

#include <zSiscomElectronica.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>
#include <zClaveSat.h>
#include <QCtrlProductosSE.h>

#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtextedit.h>

QClavesSatSiscom *InstanciaClavesSatSiscom(void *pSisDatCom,
	 char **pchrPtrArgumentos,
	 void *pQWParent,
	const char *pchrPtrName,
	 int pintWFlags)
{
return new QClavesSatSiscom((SiscomDatCom *)pSisDatCom,	
		pchrPtrArgumentos,		
		(QWidget *)pQWParent,		
		pchrPtrName,			
		pintWFlags);
}
QClavesSatSiscom::QClavesSatSiscom(SiscomDatCom *pSisDatCom, 
			    char **pchrPtrArgumentos, 
			    QWidget *pQWParent,       
			    const char *pchrPtrName,
			    WFlags pWFlags):	      
			ClavesSatSiscom(pQWParent,pchrPtrName,pWFlags),
			SisDatCom(pSisDatCom),
			chrPtrArgumentos(pchrPtrArgumentos),
			zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
IniciaVariables();
ConectaSlots();
}

QClavesSatSiscom::~QClavesSatSiscom()
{

}

void QClavesSatSiscom::ConectaSlots()
{
connect(QCtrProductos,
SIGNAL(SignalSelecciono(zSiscomRegistro *)),
SLOT(SlotSeleccionoProducto(zSiscomRegistro *)));
connect(QLEClaveSatReg,SIGNAL(returnPressed()),SLOT(SlotFocoAPalabraClave()));
connect(QLEPalabraClaveReg,SIGNAL(returnPressed()),SLOT(SlotFocoARegistrar()));
connect(QPBRegistrar,SIGNAL(clicked()),SLOT(SlotRegistrar()));
connect(QLEClaveSatReg,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoSat(const QString &)));
connect(QLEPalabraClaveReg,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoPalabraClave(const QString &)));
}
void QClavesSatSiscom::SlotCapturandoPalabraClave(const QString &)
{
QPBRegistrar->setEnabled(zSisRegProducto &&
		         zSiscomQt3::TextoValido(QLEClaveSatReg) &&
			 zSiscomQt3::TextoValido(QLEPalabraClaveReg));

}
void QClavesSatSiscom::SlotCapturandoSat(const QString &)
{
	QLEPalabraClaveReg->setEnabled(zSiscomQt3::TextoValido(QLEClaveSatReg));
}
void QClavesSatSiscom::SlotFocoARegistrar()
{
zSiscomQt3::Foco(QPBRegistrar);
}
void QClavesSatSiscom::SlotRegistrar()
{
 	Registrando();
}
void QClavesSatSiscom::SlotFocoAPalabraClave()
{
zSiscomQt3::Foco(QLEPalabraClaveReg);
}
void QClavesSatSiscom::SlotSeleccionoProducto(zSiscomRegistro *pzSisRegProducto)
{
zSisRegProducto=pzSisRegProducto;
if(!ConsultandoClaveSat())
  SeRegistraClave();
else
YaEstaLaClave();

}
void QClavesSatSiscom::IniciaVariables()
{
QCtrProductos->Servidor(zSisConexion);
QCtrProductos->IniciaControl();

zSiscomQt3::Foco(QCtrProductos);

}
void QClavesSatSiscom::Registrando()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistraClaveSat");
lzSisElectronica.RegistraClaveSat(ClaveSatSiscom());
}
zClaveSat *QClavesSatSiscom::ClaveSatSiscom()
{
zClaveSat *lzCveSat;
lzCveSat=new zClaveSat;
lzCveSat->Clave((const char *)(*zSisRegProducto)["cveproducto"]);
lzCveSat->Sat(zSiscomQt3::Texto(QLEClaveSatReg));
lzCveSat->PalabraClave(zSiscomQt3::Texto(QLEPalabraClaveReg));

return lzCveSat;
}
int QClavesSatSiscom::ConsultandoClaveSat()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ClaveSat");
return lzSisElectronica.ClaveSat((const char *)(*zSisRegProducto)["cveproducto"],&zCveSatReg);
}
void QClavesSatSiscom::SeRegistraClave()
{
QTEDescripcion->setText((const char *)(*zSisRegProducto)["dscproducto"]);
QLEClaveSatReg->setEnabled(true);

zSiscomQt3::Foco(QLEClaveSatReg);

}
void QClavesSatSiscom::YaEstaLaClave()
{
	QLEClaveSat->setText(zCveSatReg.Sat());
	QLEPalabraClave->setText(zCveSatReg.PalabraClave());
}
