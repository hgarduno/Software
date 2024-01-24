#include <IMP_Facturando3.h>
#include <IMP_ImprimeFactura.h>
#include <IMP_CapturaClientes.h>
#include <IMP_OrdenesAFacturar.h>
#include <CQSisFactura.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtabwidget.h>
#include <qlcdnumber.h>

QFacturando3 *InstanciaFacturando3(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QFacturando3((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QFacturando3::QFacturando3(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Facturando3(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				QWParent(pQWParent)
{
SiscomEscribeLog3Qt("");
IniciaVariables();
ConectaSlots();
}

QFacturando3::~QFacturando3()
{
}


void QFacturando3::IniciaVariables()
{
DatosFactura();
}
void QFacturando3::ConectaSlots()
{
connect(QPBImpFactura,
	SIGNAL(clicked()),
	SLOT(SlotImpFactura()));
connect(QPBCliente,
	SIGNAL(clicked()),
	SLOT(SlotCliente()));
connect(QPBAnexarOrden,
	SIGNAL(clicked()),
	SLOT(SlotAnexarOrden()));
}
void QFacturando3::SlotAnexarOrden()
{
QOrdenesAFacturar lQOAFacturar(SisDatCom,chrPtrArgumentos);
if(SisReg3LstOrdenes.count())
{
   SiscomEscribeLog3Qt("Se Anexaran ordenes a una previa");
   lQOAFacturar.PonOrdenes(&SisReg3LstOrdenes);
   lQOAFacturar.ConsultandoOrdenesAFacturar();
}
lQOAFacturar.exec();
lQOAFacturar.ObtenOrdenes(&SisReg3LstOrdenes);
lQOAFacturar.ObtenFacturacion(&SisReg3LstProdAFacturar);
MuestraOrdenesAFacturar();
MuestraTotales();
}
void QFacturando3::SlotCliente()
{
QCapturaClientes lQCCliente(SisDatCom,
			   chrPtrArgumentos);
if(lQCCliente.Opcion())
{
SisReg3Cliente=(SiscomRegistro3 *)lQCCliente.ClienteSiscom();
MuestraDatosCliente(SisReg3Cliente);
}
}
void QFacturando3::SlotImpFactura()
{
CQSisFactura lCQSFactura(SisReg3Cliente,
			 &SisReg3LstProdAFacturar,
			 &SisReg3LstOrdenes);
CQSisOpRegistraFactura lCQSOpRegFactura(SisDatCom);
lCQSOpRegFactura.Registra(&lCQSFactura);


/*
  QIFactura=new QImprimeFactura(SisReg3Cliente,
  				&SisReg3LstProdAFacturar,
  				QWParent,
				"QIFactura");
*/
}


void QFacturando3::closeEvent(QCloseEvent *pQCEvent)
{
delete QIFactura;
emit SignalTerminar(this);
}

void QFacturando3::DatosFactura()
{
/*
SisReg3Cliente=new SiscomRegistro3;
(*SisReg3Cliente) 			<< 
new SiscomCampo3("nombre","Maria Guadalupe")	<<
new SiscomCampo3("apaterno","Casasola")	<<
new SiscomCampo3("amaterno","Estrada") <<
new SiscomCampo3("calle","Eva Samano De Lopez Mateos No 28") <<
new SiscomCampo3("municipio","Tepotzotlan")			<<
new SiscomCampo3("colonia","Bo Tlacateco")			<<
new SiscomCampo3("estado","Mexico")				<<
new SiscomCampo3("cp","54605")					<<
new SiscomCampo3("rfc","GAEH720320LE8")				<<
new SiscomCampo3("telefono","015558766421");
*/
}
void QFacturando3::MuestraDatosCliente(SiscomRegistro3 *pSisReg3Cliente)
{
  if(!strcmp((*pSisReg3Cliente)["persona"],"PersonaFisica"))
	 MuestraPersonaFisica(pSisReg3Cliente);
  if(!strcmp((*pSisReg3Cliente)["persona"],"PersonaMoral"))
  MuestraPersonaMoral(pSisReg3Cliente);

	 SeleccionaPestana(pSisReg3Cliente);
}
void QFacturando3::MuestraPersonaFisica(SiscomRegistro3 *pSisReg3Cliente)
{
QLENombre->setText((*pSisReg3Cliente)["nombre"]);
QLEAPaterno->setText((*pSisReg3Cliente)["apaterno"]);
QLEAMaterno->setText((*pSisReg3Cliente)["amaterno"]);
QLERFC->setText((*pSisReg3Cliente)["rfc"]);
 QLECalle->setText((*pSisReg3Cliente)["calle"]);
 QLENumero->setText((*pSisReg3Cliente)["numero"]);
 QLEColonia->setText((*pSisReg3Cliente)["colonia"]);
 QLEEstado->setText((*pSisReg3Cliente)["estado"]);
 QLEDelMun->setText((*pSisReg3Cliente)["municipio"]);
 QLECP->setText((*pSisReg3Cliente)["cp"]);
 QLETelefono->setText((*pSisReg3Cliente)["telefono"]);
}
void QFacturando3::MuestraPersonaMoral(SiscomRegistro3 *pSisReg3Cliente)
{
 QLERazonSocial->setText((*pSisReg3Cliente)["nombre"]);
 QLERFC->setText((*pSisReg3Cliente)["rfc"]);
 QLECalle->setText((*pSisReg3Cliente)["calle"]);
 QLENumero->setText((*pSisReg3Cliente)["numero"]);
 QLEColonia->setText((*pSisReg3Cliente)["colonia"]);
 QLEEstado->setText((*pSisReg3Cliente)["estado"]);
 QLEDelMun->setText((*pSisReg3Cliente)["municipio"]);
 QLECP->setText((*pSisReg3Cliente)["cp"]);
 QLETelefono->setText((*pSisReg3Cliente)["telefono"]);
 QLECorreo->setText((*pSisReg3Cliente)["correo"]);

}
void QFacturando3::SeleccionaPestana(SiscomRegistro3 *pSisReg3Cliente)
{
QWidget *lQWPersonaFis=QTWTipoCliente->page(0);
QWidget *lQWPersonaMor=QTWTipoCliente->page(1);
if(TipoCliente(pSisReg3Cliente)==0)
{
   QTWTipoCliente->setTabEnabled(lQWPersonaFis,true);
   QTWTipoCliente->setTabEnabled(lQWPersonaMor,false);
   QTWTipoCliente->setCurrentPage(0);
}
if(TipoCliente(pSisReg3Cliente)==1)
{
   QTWTipoCliente->setTabEnabled(lQWPersonaFis,false);
   QTWTipoCliente->setTabEnabled(lQWPersonaMor,true);
   QTWTipoCliente->setCurrentPage(1);

}
}

int QFacturando3::TipoCliente(SiscomRegistro3 *pSisReg3Cliente)
{
return !strcmp((*pSisReg3Cliente)["persona"],"PersonaFisica") ?
	0 : 1;
}
void QFacturando3::MuestraOrdenesAFacturar()
{
const char *lchrPtrCampos[]={"cveproducto",
		       "CantidadTotal",
		       "precio",
		       "ImporteTotal",
		       0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
				       QTDatos,
				       &SisReg3LstProdAFacturar);
}
void QFacturando3::MuestraTotales()
{

SiscomRegistro3 *lSisReg3Total=SisReg3LstProdAFacturar[0];

QLCNTotal->display((*lSisReg3Total)["Total"]);
QLCNIVA->display((*lSisReg3Total)["IVA"]);
QLCDNTotalMIVA->display((*lSisReg3Total)["TotalMIVA"]);
}
