#include <QtImpSeleccionaCredito.h>
#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zOperacionesServiSNTE.h>
#include <zDireccion.h>

#include <zCreditosCliente.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qmessagebox.h>
QtImpSeleccionaCredito::QtImpSeleccionaCredito(QWidget *pQWParent,
				     const char *pchrPtrName,
				     bool pbModal,
				     WFlags pWFlags):
				     SeleccionaCredito(pQWParent,pchrPtrName,pbModal,pWFlags)
{
 
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaVariables();
 ConectaSlots();
 exec();
}

void QtImpSeleccionaCredito::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpSeleccionaCredito::IniciaVariables()
{
zSiscomQt3::Foco(QLERFC);
}
void QtImpSeleccionaCredito::ConectaSlots()
{
	connect(QLERFC,
		SIGNAL(returnPressed()),
		SLOT(SlotRFC()));
	connect(QTCreditos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionaApartado(int,int,int,const QPoint &)));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
}
void QtImpSeleccionaCredito::SlotAceptar()
{ 
 intAceptar=1;
 done(1);
}
void QtImpSeleccionaCredito::SlotCancelar()
{
intAceptar=0;
done(1);
}
void QtImpSeleccionaCredito::SlotSeleccionaApartado(int pintNFila,
						 int,
						 int,
						 const QPoint &)
{
   if(pintNFila!=-1)
   {
   QTCreditos->selectRow(pintNFila);
   zSisRegCredito=(*zCredsCliente->Creditos())[pintNFila];
   QPBAceptar->setEnabled(zSisRegCredito);
   }
   else
   QPBAceptar->setEnabled(false);

}
void QtImpSeleccionaCredito::SlotRFC()
{
  ConsultandoCreditos();
}
int QtImpSeleccionaCredito::ConsultaCreditos()
{
zOperacionesServiSNTE lzOpServiSNTECreditosCliente(zSisConexion,"CreditosCliente");
zCredsCliente=lzOpServiSNTECreditosCliente.CreditosCliente(zSiscomQt3::Texto(QLERFC));
return zCredsCliente ? 1 : 0;
}
void QtImpSeleccionaCredito::MuestraCreditos()
{
const char *lchrArrCampos[]={"pagototal","total","pagoquincenal","plazo","numeropagos",0};
zSiscomQt3::LlenaTabla(lchrArrCampos,zCredsCliente->Creditos(),QTCreditos);
}
void QtImpSeleccionaCredito::ConsultandoCreditos()
{
if(ConsultaCreditos())
{
MuestraCreditos();
MuestraCliente();
}
else
QMessageBox::information(this,"Aviso del Sistema","No Se Encontro Informacion del RFC");
}
void QtImpSeleccionaCredito::MuestraCliente()
{
zSiscomRegistro *lzSisRegCliente=zCredsCliente->Cliente();
QLECliente->setText(QString((const char *)(*lzSisRegCliente)["nombre"]) +
                    " "					  		+
		    (const char *)(*lzSisRegCliente)["apaterno"]	+
		    " "						 	+
		    (const char *)(*lzSisRegCliente)["amaterno"]);
(*lzSisRegCliente) << new zSiscomCampo("RFC",(const unsigned char *)zSiscomQt3::Texto(QLERFC));
}


void QtImpSeleccionaCredito::reject()
{

}

zSiscomRegistro *QtImpSeleccionaCredito::Cliente()
{
  return zCredsCliente->Cliente();
}
zDireccion *QtImpSeleccionaCredito::Direccion()
{
  return zCredsCliente->Direccion();
}
int QtImpSeleccionaCredito::Aceptar()
{
 return intAceptar;
}
zSiscomRegistro *QtImpSeleccionaCredito::Credito()
{
 return zSisRegCredito;
}
