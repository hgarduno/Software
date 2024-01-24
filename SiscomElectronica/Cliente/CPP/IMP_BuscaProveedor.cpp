#include <IMP_BuscaProveedor.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisProveedores.h>
#include <qtextedit.h>
#include <qcombobox.h>
#include <qpushbutton.h>
QBuscaProveedor::QBuscaProveedor(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				BuscaProveedor(pQWParent,
					       pchrPtrName,
					       pbModal,
					       pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QBuscaProveedor::~QBuscaProveedor()
{

}

void QBuscaProveedor::ConectaSlots()
{
connect(QCBRSocial,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBRSocial,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));
connect(QPBCancelar,
	SIGNAL(clicked()),
	SLOT(SlotCancelar()));
}
void QBuscaProveedor::SlotCancelar()
{
	intOpcion=0;
	done(1);
}
void QBuscaProveedor::SlotAceptar()
{
	intOpcion=1;
	done(1);
	
}
void QBuscaProveedor::SlotSelecciono(int pintProveedor)
{
  Muestra(pintProveedor);
  SiscomDesarrollo3Qt::PasaFocoControl(QPBAceptar);
}
void QBuscaProveedor::SlotSeleccionando(int pintProveedor)
{
Muestra(pintProveedor);
}
void QBuscaProveedor::IniciaVariables()
{
Consultando();
}
void QBuscaProveedor::Consultando()
{
Consulta();
LlenaCombo();
Muestra(0);
}
void QBuscaProveedor::LlenaCombo()
{
SiscomDesarrollo3Qt::RegistrosAlCombo("razonsocial",
				      QCBRSocial,
				      &SisReg3LstProveedores);
}
void QBuscaProveedor::Consulta()
{
CQSisProveedores lCQSProveedores(SisDatCom);
lCQSProveedores.Proveedores(chrPtrArgumentos[0],&SisReg3LstProveedores);
}
void QBuscaProveedor::Muestra(int pintProveedor)
{
QString lQSDireccion;
SisReg3Proveedor=SisReg3LstProveedores[pintProveedor];
lQSDireccion+=QString("Calle:") 				+
	      (*SisReg3Proveedor)["calle"] 		+
	      "\n"					+
	      "Numero:"					+
	      (*SisReg3Proveedor)["numero"]		+
	      "\n"					+
	      "Colonia:"				+
	      (*SisReg3Proveedor)["colonia"]		+
	      "\n"					+
	      "Codigo Postal:"				+
	      (*SisReg3Proveedor)["cp"];
QTEDireccion->setText(lQSDireccion);
}

int QBuscaProveedor::Opcion()
{
return intOpcion;
}
SiscomRegistro3 *QBuscaProveedor::Proveedor()
{
	return SisReg3Proveedor;
}
