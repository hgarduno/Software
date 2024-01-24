#include <IMP_ReEnvioFactura.h>

#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <zDatosReEnvioFactura.h>

#include <qlineedit.h>
#include <qtable.h>
#include <qpushbutton.h> 

QReEnvioFactura::QReEnvioFactura(const char *pchrPtrIdFactura,
				 char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ReEnvioFactura(pQWParent,pchrPtrName,pbModal,pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				chrPtrIdFactura(pchrPtrIdFactura),
				intSeEnviaOtroCorreo(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QReEnvioFactura::~QReEnvioFactura()
{

}

void QReEnvioFactura::ConectaSlots()
{
connect(QPBReEnvia,SIGNAL(clicked()),SLOT(SlotReEnviaFactura()));
connect(QLEOtroCorreo,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoOtroCorreo(const QString &)));
connect(QTCorreos,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotCorreo(int,int,int,const QPoint &)));

}
void QReEnvioFactura::SlotCapturandoOtroCorreo(const QString &pQStrCadena)
{
	intSeEnviaOtroCorreo=zSiscomQt3::TextoValido(pQStrCadena);
	QPBReEnvia->setEnabled(intSeEnviaOtroCorreo);
}
void QReEnvioFactura::SlotReEnviaFactura()
{
ReEnviando();
MuestraEdoReEnvio();
}
void QReEnvioFactura::SlotCorreo(int pintNCorreo,
				 int,
				 int,
				 const QPoint &)
{
   QTCorreos->selectRow(pintNCorreo);
   intCorreoReEnvio=pintNCorreo;
   QPBReEnvia->setEnabled(true);
}
void QReEnvioFactura::IniciaVariables()
{
 Consultando();
}
void QReEnvioFactura::Consultando()
{
	Consulta();
	Muestra();
}
void QReEnvioFactura::Consulta()
{
zSiscomElectronica lzSisElectronica(zSisConexion,
				    "DatosParaReEnvioFactura");
lzSisElectronica.DatosParaReEnvioFactura(chrPtrIdFactura,&zDatReEnvioFactura);
}
void QReEnvioFactura::Muestra()
{
 QLERazonSocial->setText(zDatReEnvioFactura->RazonSocial());
 QLERFC->setText(zDatReEnvioFactura->RFC());
 MuestraCorreos();
}
void QReEnvioFactura::MuestraCorreos()
{
int lintContador=0;
const char *lchrPtrCorreo;
   while((lchrPtrCorreo=zDatReEnvioFactura->Correo()))
   {
        QTCorreos->setNumRows(lintContador+1);
	QTCorreos->setText(lintContador,0,lchrPtrCorreo);
	lintContador++;
   }
}
void QReEnvioFactura::ReEnviando()
{
const char *lchrPtrCorreo;
if(intSeEnviaOtroCorreo)
lchrPtrCorreo=zSiscomQt3::Texto(QLEOtroCorreo);
else
lchrPtrCorreo=zDatReEnvioFactura->Correo(intCorreoReEnvio);
zSiscomElectronica lzSisElectronica(zSisConexion,"ReEnviaFactura");
lzSisElectronica.ReEnviaFactura(chrPtrIdFactura,
				lchrPtrCorreo,
				&zSisRegEdoReEnvio);
}
void QReEnvioFactura::MuestraEdoReEnvio()
{

}
