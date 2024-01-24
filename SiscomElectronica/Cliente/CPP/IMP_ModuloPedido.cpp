#include <IMP_ModuloPedido.h>
#include <IMP_ClientePedido.h>
#include <IMP_DatosPedido.h>

#include <zSiscomElectronica.h>
#include <zClienteSiscom.h>

#include <zTelefono.h>
#include <zCorreo.h>
#include <zDireccion.h>
#include <zPedido.h>
#include <zEstadoPedido.h>
#include <zPuntoEntrega.h>

#include <zSiscomQt3.h>
#include <zSiscomDesarrollo4.h>

#include <qpushbutton.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qmessagebox.h>


QModuloPedido *InstanciaModuloPedido(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QModuloPedido((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QModuloPedido::QModuloPedido(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				QManejadorOrden(pSisDatCom,pchrPtrArgumentos,pQWParent,pchrPtrName,pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos),
				zPedSiscom(0),
				intDatosPedido(0)
{
IniciaVariables();
ConectaSlots();
}

QModuloPedido::~QModuloPedido()
{

}

void QModuloPedido::ConectaSlots()
{
connect(QPBDatosPedido,SIGNAL(clicked()),SLOT(SlotDatosPedido()));


}
void QModuloPedido::SlotDatosPedido()
{
CapturaDatosPedido();
zSiscomQt3::Foco(QPBImprime);
}
void QModuloPedido::IniciaVariables()
{
Orden()->Pedido(new zPedido);
Redimensiona();
QPBRegistrar->setText("Regist&ra Pedido");
}
void QModuloPedido::NuevaOrden()
{
QClientePedido lQClientePed(Orden(),chrPtrArgumentos);
int lintAceptar;
lintAceptar=lQClientePed.Aceptar();
LogSiscom("El tipo de Aceptar %d",lintAceptar);
/*   0  ->   ???? Cancelar
 *   1  -> Envio Punto de entrega Siscom
 *   2  -> Envio a domicilio cliente
 */
if(lintAceptar)
{
	PedidoDesdeCero(&lQClientePed);
     	ObtenIdOrden(); 
     	MuestraDatosCliente();
     	QPBNuevaOrden->setEnabled(false);
     	QPBAnexarOrden->setEnabled(true);
     	QPBDatosPedido->setEnabled(true);
}
}

void QModuloPedido::MuestraDatosCliente()
{
/*
QString lQStrCliente=QString(Cliente()->Nombre()) +
	   " "				+
	   Cliente()->APaterno() 	+
	   " "				+
	   Cliente()->AMaterno()        +
	   "  *****  "			+
	   Cliente()->Escuela()		+
	   "  *****";
setCaption(lQStrCliente);
emit SignalActualizaMenu(lQStrCliente);
*/
/*		   
 //{{QTECliente->setText(QString("Nombre del Cliente\n")			+
 QTECliente->setText(QString("Nombre del Cliente\n")			+
 			     Cliente()->Nombre()  			+ 
 			     " " 					+
			     Cliente()->APaterno()			+
			     " "					+
			     Cliente()->AMaterno()  			+
			     "\n"					+
			     "Escuela\n" 				+
			     " "					+
			     Cliente()->Escuela()			+
			     "\n"					+
			     "Datos Comunicacion"			+
			     "\n"					+
			     "Celular:"                 		+
			     Cliente()->Celular()->Telefono()		+
			     "\n"					+
			     "Correo Electronico:"			+
			     Cliente()->Correo()->Correo()		+
			     "\n"					+
			     "Direccion Entrega"			+
			     "\n"					+
			     Cliente()->Direccion()->Calle() 		+
			     " " 					+
			     Cliente()->Direccion()->Numero()		+
			     " "					+
			     Cliente()->Direccion()->Colonia()		+
			     " " 					+
			     Cliente()->Direccion()->Delegacion()	+
			     " "					+
			     Cliente()->Direccion()->Estado()		+
			     " "					+
			     Cliente()->Direccion()->CP()		+
			     "\n"					+
			     "Referencias"				+
			     "\n"					+
			     Cliente()->Direccion()->Referencias());
//}}
*/
/*
QTECliente->setText(QString("Enviando a ") 	+
		    Orden()->Pedido()->Calle()	+
		    "\n"			+
		    Orden()->Cliente()->Nombre());

*/
}

void QModuloPedido::CapturaDatosPedido()
{
QDatosPedido lQDatPedido(Orden());
if(lQDatPedido.Aceptar())
{
  Orden()->Pedido()->EstadoPedido(new zEstadoPedido("0",0,0,0));
  intDatosPedido=1;
}
}
void QModuloPedido::Registrar()
{
 RegistraOrden();
 EliminaOrden();
 IniciaOrden();
 ReIniciaInterfaz();
 //LiberaCliente();
 intDatosPedido=0;
 EliminaPedido();
 IniciaVariables();
}

void QModuloPedido::RegistraOrden()
{
zSiscomElectronica lzSisElectronica(Conexion(),"RegistraOrden");
lzSisElectronica.RegistraOrden(Orden());
}
void QModuloPedido::Imprimir()
{
if(intDatosPedido)
{
zSiscomElectronica lzSisElectronica(Conexion(),"ImprimeTicketVenta4");
lzSisElectronica.ImprimeTicketVenta(Orden());
zSiscomQt3::Foco(QPBRegistrar);
}
else
{
QMessageBox::information(this,"Aviso del Sistema","NO Se han Capturado los Datos del Pedido");
zSiscomQt3::Foco(QPBDatosPedido);
}
}

void QModuloPedido::Redimensiona()
{
  setMinimumSize(802,393);
  setGeometry(0,40,812,403);
}


void QModuloPedido::closeEvent(QCloseEvent *)
{
  emit SignalTerminar(this);
}

void QModuloPedido::PedidoDesdeCero(QClientePedido *pQClientePedido)
{
     Orden()->IdTipoOrden(pQClientePedido->IdTipoOrden());
}

void QModuloPedido::EliminaPedido()
{
   delete zPedSiscom;
   zPedSiscom=0;
}
