#include <IMP_Inventario.h>
#include <IMP_ActualizaInventario.h>
#include <IMP_SeleccionaInventario.h>
#include <IMP_CapturaExistenciaFisica.h>
#include <QCtrlMotivoInventario.h>
#include <SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>
#include <ManInventario.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qmessagebox.h>
QInventario *InstanciaInventario(void *pSisDatCom,
				 char **pchrPtrArgumentos,
				 void *pQWParent,
				 const char *pchrPtrName,
				 int pintFlags)
{
	return new QInventario((SiscomDatCom *)pSisDatCom,
			       pchrPtrArgumentos,
			       (QWidget *)pQWParent,
			       pchrPtrName,
			       pintFlags);
}
QInventario::QInventario(SiscomDatCom *pSisDatCom,
			 char **pchrPtrArgumentos,
			 QWidget* parent, const char* name, WFlags fl )
    : Inventario( parent, name, fl ),
    SisDatCom(pSisDatCom),
    chrPtrArgumentos(pchrPtrArgumentos),
    intInventarioPorDesajuste(0)
{
	IniciaVariables();
	ConectaSlots();
}

QInventario::~QInventario()
{
}
void QInventario::IniciaVariables()
{
	QLECProductos=SiscomColocaEditAlCombo(QCBProductos,"QLECProductos");
	QMProductos=new QManProductos(SisDatCom,
				  chrPtrArgumentos[0],
				  QCBProductos,
				  QLECProductos,
				  QLEDescripcion,
				  this,
				  "QMProductos");
	/*
	 * Jueves 22 De Septiembre 2011 
	 * Con la problematica de que no coincide la existencia
	 * fisica con la existencia reportada en el sistema se
	 * agrego el motivo por el cual se actualiza el inventario
	 *
	 */
	QCtrMotivoInventario->Servidor(SisDatCom);
	QCtrMotivoInventario->IdExpendio(chrPtrArgumentos[0]);
	QCtrMotivoInventario->IniciaControl();
	/*
	SiscomPasaFocoControl(QLECProductos);
	*/
	SiscomPasaFocoControl(QCtrMotivoInventario);
}
void QInventario::ConectaSlots()
{
	connect(QCtrMotivoInventario,
		SIGNAL(SignalMotivoInventario(SiscomRegistro3 *)),
		SLOT(SlotPasaFocoProductos(SiscomRegistro3 *)));
	connect(QMProductos,
		SIGNAL(SignalProducto(ProductoE *)),
		SLOT(S_SelProducto(ProductoE *)));
	connect(QMProductos,
		SIGNAL(SignalNoEstaClave(const char *)),
		SLOT(S_NoEstaClave(const char *)));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoRegistrar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_Registrar()));
	connect(QPBActualiza,
		SIGNAL(clicked()),
		SLOT(S_Actualiza()));
	connect(QPBActivaMotivo,
		SIGNAL(clicked()),
		SLOT(SlotActivaMotivoInventario()));

}
void QInventario::SlotActivaMotivoInventario()
{
	QCtrMotivoInventario->setEnabled(true);
	SiscomDesarrollo3Qt::PasaFocoControl(QCtrMotivoInventario);
}
void QInventario::SlotPasaFocoProductos(SiscomRegistro3 *pSisReg3Motivo)
{
	SisReg3Motivo=pSisReg3Motivo;
	if(!strcmp((*pSisReg3Motivo)["idmotivo"],"0"))
	RegistroPorDesajuste();
	else
	SeleccionaInventario();


	SiscomDesarrollo3Qt::PasaFocoControl(QLECProductos);
}
void QInventario::S_NoEstaClave(const char *pchrPtrClave)
{

	QMessageBox::information(this,
				 "Siscom Electronica",
				 "Producto No Registrado");
	SiscomPasaFocoControl(QLECProductos);
	

}
void QInventario::S_Actualiza()
{
QActualizaInventario lQAInventario(SisDatCom,
				    chrPtrArgumentos);
}
void QInventario::S_SelProducto(ProductoE *pProducto)
{
	SiscomPasaFocoControl(QLECantidad);
	PProducto=pProducto;
	CapturaExistenciaFisica();
}
void QInventario::S_PasaFocoRegistrar()
{
  SiscomPasaFocoControl(QPBRegistrar);
}
void QInventario::S_Registrar()
{
	PProducto->SiscomActualizaCampo("Cantidad",(const char *)QLECantidad->text());
	PProducto->SiscomActualizaCampo("IdExpendio",chrPtrArgumentos[0]);
	/* En el campo de IdCliente, se pasa la informacion al servidor
	 * de la persona que esta firmada en el sistema, responsable del inventario*/
	PProducto->SiscomActualizaCampo("IdCliente",chrPtrArgumentos[1]);
	/*
	 * Viernes 23 De Septiembre 
	 * Por el manejo con mejor control de los inventarios, se agrega en el 
	 * campo NumFactura, que para este caso no se usa, la informacion 
	 * del inventario a realizar 
	 *
	 */
	if(intInventarioPorDesajuste)
	{
	PProducto->SiscomActualizaCampo("NumFactura","0");
	PProducto->SiscomActualizaCampo("FechaPago",chrPtrExistenciaFisica);
	}
	else
	PProducto->SiscomActualizaCampo("NumFactura",(*SisReg3Inventario)["idinventario"]);
	SiscomPasaFocoControl(QLECProductos);

ManInventario lMInventario(SisDatCom,ProductosE() << PProducto);
	      lMInventario.Registra();
}
void QInventario::closeEvent(QCloseEvent *)
{

emit SignalTerminar(this);
}
/*
 * Viernes 23 De Septiembre 2011 
 * Se agregaron rutinas para controlar mejor el manejo del registro
 * de inventario, esto por el problema de desajuste que se ha presentado
 * constantemente entre la exitencia que reporta el sistema y la que 
 * fisicamente se tiene
 */

void QInventario::RegistroPorDesajuste()
{
intInventarioPorDesajuste=1;
QCtrMotivoInventario->setEnabled(false);
}
void QInventario::SeleccionaInventario()
{
QSeleccionaInventario lQSInventario(SisDatCom,
					chrPtrArgumentos);
if((SisReg3Inventario=lQSInventario.Inventario()))
{
SiscomEscribeLog3Qt("Selecciono el inventario:%s",
		     (*SisReg3Inventario)["idinventario"]);
QLEInventario->setText((*SisReg3Inventario)["descripcion"]);
QCtrMotivoInventario->setEnabled(false);
}
}
void QInventario::CapturaExistenciaFisica()
{
if(intInventarioPorDesajuste)
{
QCapturaExistenciaFisica lQCEFisica;
if((chrPtrExistenciaFisica=lQCEFisica.ExistenciaFisica()))
{
QLEExistenciaFisica->setText(chrPtrExistenciaFisica);
QLECantidad->setText(chrPtrExistenciaFisica);
SiscomDesarrollo3Qt::PasaFocoControl(QPBRegistrar);
}

}
}
