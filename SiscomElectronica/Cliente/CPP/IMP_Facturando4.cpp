#include <IMP_Facturando4.h>
#include <IMP_SeleccionaOrdenFactura.h>
#include <IMP_DatosFacturacion.h>
#include <IMP_CapturaDatosFactura.h>

#include <zSiscomElectronica.h>

#include <zCliente.h>
#include <zEmpresa.h>
#include <zCorreo.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <qpushbutton.h>
#include <qlcdnumber.h>
#include <qtextedit.h>
#include <qmessagebox.h>
#include <qtable.h>
QFacturando4 *InstanciaFacturando4(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QFacturando4((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QFacturando4::QFacturando4(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Facturando4(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				intPersonaFisica(0),
				zClienteC(0)
{
IniciaVariables();
ConectaSlots();
}

QFacturando4::~QFacturando4()
{
}

void QFacturando4::ConectaSlots()
{
connect(QPBOrdenesFecha,SIGNAL(clicked()),SLOT(SlotOrdenesFecha()));
connect(QPBDatosFacturacion,SIGNAL(clicked()),SLOT(SlotDatosFacturacion()));
connect(QPBRealizaFactura,SIGNAL(clicked()),SLOT(SlotRealizaFactura()));
connect(QPBCapturaDatos,SIGNAL(clicked()),SLOT(SlotCapturaDatos()));
}
void QFacturando4::SlotCapturaDatos()
{
QCapturaDatosFactura lQCapturaDatos(&zFacturaD);
QLCDNImporte->display(zFacturaD.Importe());
QLCDNTotal->display(zFacturaD.Total());
QLCDNIva->display(zFacturaD.Iva());
}
void QFacturando4::SlotRealizaFactura()
{
   ImporteLetra();
   if(!SeLiberaFactura(EnviaFactura()))
   LiberaFacturacion();
}
void QFacturando4::SlotDatosFacturacion()
{
QDatosFacturacion *lQDatFacturacion=new QDatosFacturacion(SisDatCom,
							  chrPtrArgumentos,
							  zClienteC);
if(lQDatFacturacion->Aceptar())
{
   zClienteC=lQDatFacturacion->Cliente(); 
   zFacturaD.Cliente(zClienteC);
   zFacturaD.MetodoPago(lQDatFacturacion->MetodoPago());
   zFacturaD.FormaPago(lQDatFacturacion->FormaPago());
   zFacturaD.UsoFactura(lQDatFacturacion->UsoFactura());
   MuestraCliente(); 
   QPBRealizaFactura->setEnabled(true);
   zSiscomQt3::Foco(QPBRealizaFactura);
}
}
void QFacturando4::SlotOrdenesFecha()
{
QSeleccionaOrdenFactura lQSelOrdFactura(SisDatCom,chrPtrArgumentos);
zSiscomRegistro *lzSisRegOrden;
if((lzSisRegOrden=lQSelOrdFactura.Orden()))
{
 zOrdenesF.Orden(lzSisRegOrden);
 Calculando();
 QPBDatosFacturacion->setEnabled(zFacturaD.Productos()->NNodos());
 zSiscomQt3::Foco(QPBDatosFacturacion);
}
}
int QFacturando4::SeLiberaFactura(int pintRegreso)
{
   if(pintRegreso==0) /* Se genero y se envio la factura */
    return 0;
    else
    if(pintRegreso==2) /* NO Se envio el Correo */
     return 0;
    else
    if(pintRegreso==1) /* Algo paso .... */
    return 1;
}
void QFacturando4::IniciaVariables()
{
}
void QFacturando4::ImporteLetra()
{
char *lchrPtrRegreso=0;
zSiscomQt3::SiscomALetras(zFacturaD.TotalFloat(),&lchrPtrRegreso); 
zFacturaD.TotalLetra(lchrPtrRegreso);
}
void QFacturando4::Calculando()
{
  Calcula();
  Muestra();
}
void QFacturando4::Calcula()
{
zSiscomElectronica lzSisECalcula(zSisConexion,"CalculaFactura");
lzSisECalcula.CalculaFactura(&zOrdenesF,&zFacturaD);
}
void QFacturando4::Muestra()
{
const char *lchrPtrCampos[]={"cveproducto","cantidad","precio","importe",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,zFacturaD.Productos(),QTFactura);
QLCDNImporte->display(zFacturaD.Importe());
QLCDNTotal->display(zFacturaD.Total());
QLCDNIva->display(zFacturaD.Iva());
}
void QFacturando4::Cliente(char *pchrPtrCliente)
{
	if(zClienteC->EsPersonaFisica())
	zClienteC->NombreCompleto(pchrPtrCliente);
	else
	strcpy(pchrPtrCliente,zClienteC->Empresa()->RazonSocial());
}
void QFacturando4::MuestraCliente()
{
char lchrArrCliente[120],
	lchrArrDireccion[120];
   Cliente(lchrArrCliente); 
  zClienteC->Direccion(lchrArrDireccion);
  QTEDatos->setText(QString(lchrArrCliente)	+ 
  	 	   "\n"				+
		   lchrArrDireccion		+
		   "\n"				+
		   "Correo Electronico:"	+
		   zClienteC->CorreoActivo()->Correo());
}
int QFacturando4::EnviaFactura()
{
int lintRegreso;
char *lchrPtrEstadoOperacion;
zSiscomElectronica lzSisElecFactura(zSisConexion,"RealizaFactura");
/*
zClienteC->LiberaCorreos();
*/
zFacturaD.Ordenes(&zOrdenesF);
if(!(lintRegreso=lzSisElecFactura.Factura(&zFacturaD,&lchrPtrEstadoOperacion)))
QMessageBox::information(this,"Aviso Del Sistema",lchrPtrEstadoOperacion);
else
QMessageBox::warning(this,"Aviso Del Sistema",lchrPtrEstadoOperacion);
return lintRegreso;
}

void QFacturando4::LiberaFacturacion()
{
	delete(zClienteC);
	zClienteC=0;
	QTEDatos->setText("");
	QTFactura->setNumRows(0);
}

void QFacturando4::closeEvent(QCloseEvent *pQCloseEvent)
{
  emit SignalTerminar(this);
}
