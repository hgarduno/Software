#include <IMP_PedidoMaterial.h>
#include <IMP_CapturaObservacionPedidoProducto.h>
#include <IMP_PedidosPendientes.h>
#include <ProductosE.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qmessagebox.h>
QPedidoMaterial *InstanciaPedidoMaterial(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPedidoMaterial((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPedidoMaterial::QPedidoMaterial(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				PedidoMaterial(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QPedidoMaterial::~QPedidoMaterial()
{

}

void QPedidoMaterial::ConectaSlots()
{

	connect(QMProductos,
		SIGNAL(SignalProducto(ProductoE *)),
		SLOT(S_Producto(ProductoE *)));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(S_FocoAAnexar()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QPBRegPedidoMaterial,
		SIGNAL(clicked()),
		SLOT(S_RegistraPedidoMaterial()));
	connect(QTProductos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(S_SeleccionoTabla(int,int,int,const QPoint &)));
	connect(QTProductos,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(S_EliminaProducto(int,int,int,const QPoint &)));
	connect(QPBEliminaProducto,
		SIGNAL(clicked()),
		SLOT(S_EliminaProducto()));
	connect(QPBPedidosPendientes,
		SIGNAL(clicked()),
		SLOT(S_PedidosPendientes()));
}
void QPedidoMaterial::S_PedidosPendientes()
{
QPedidosPendientes lQPedPendientes(SisDatCom,
				   chrPtrArgumentos);

}
void QPedidoMaterial::S_EliminaProducto()
{
  EliminaProducto();
  QPBEliminaProducto->setEnabled(false);
  intProductoSeleccionado=-1;
  SiscomPasaFocoControl(QLECProductos);

}
void QPedidoMaterial::S_EliminaProducto(int pintFila,
				         int,
					 int,
					 const QPoint &)
{
int lintEstado;
	if((lintEstado=pintFila!=-1))
	{
	QPBEliminaProducto->setEnabled(lintEstado);
	QTProductos->selectRow(pintFila);
	intProductoSeleccionado=pintFila;
	}
}
void QPedidoMaterial::S_SeleccionoTabla(int pintFila,
					int pintColumna,
					int,
					const QPoint &)
{
	if(pintColumna==2)
	CapturaObservacionProducto(pintFila);

}
void QPedidoMaterial::S_RegistraPedidoMaterial()
{
SiscomRegistro3 *lSisReg3Regreso;
   lSisReg3Regreso=RegistraPedidoMaterial();
   if(!lSisReg3Regreso->CampoAInt("EstadoRegistro"))
   {
	QMessageBox::information(this,"Aviso Sistema",(*lSisReg3Regreso)["Mensaje"]);
	QPBRegPedidoMaterial->setEnabled(false);
   }
   else
   ReIniciaVentana();
}
void QPedidoMaterial::S_Anexar()
{
   if(ProdSeleccionado)
   {
   AnexarProducto();
   MuestraProductos();
   SiscomPasaFocoControl(QLECProductos);
   QPBAnexar->setEnabled(false);
   QLECantidad->setEnabled(false);
   ProdSeleccionado=0;
   QPBRegPedidoMaterial->setEnabled(true);
   }
}
void QPedidoMaterial::S_FocoAAnexar()
{
   if(ProdSeleccionado)
   {
   QPBAnexar->setEnabled(true);
   SiscomPasaFocoControl(QPBAnexar);
   }
}
void QPedidoMaterial::S_Producto(ProductoE *pProductoE)
{
   if(pProductoE)
   {
   QLECantidad->setEnabled(true);
   SiscomPasaFocoControl(QLECantidad);
   ProdSeleccionado=pProductoE;
   }
}
void QPedidoMaterial::IniciaVariables()
{

	QLECProductos=SiscomColocaEditAlCombo(QCBProductos,"QLECProductos");
	QMProductos=new QManProductos(SisDatCom,
					chrPtrArgumentos[0],
					QCBProductos,
					QLECProductos,
					QTEDescripcion,
					this,
					"QMProductos");

   CQSPedidoMaterial.Expendio(chrPtrArgumentos[0]);
   SiscomPasaFocoControl(QLECProductos);
}
void QPedidoMaterial::AnexarProducto()
{
  CQSPedidoMaterial.AgregaProducto((*ProdSeleccionado)["CveProducto"],
  				   SiscomDesarrollo3Qt::InformacionEdit(QLECantidad),
				   "");
}
void QPedidoMaterial::MuestraProductos()
{
const char *lchrArrCampos[]={"CveProducto","Cantidad","Observaciones",0};
SiscomRegistro3Lst *lSisReg3LstProductos;
lSisReg3LstProductos=CQSPedidoMaterial.RegistrosSubGrupo(0,1);
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrArrCampos,QTProductos,lSisReg3LstProductos);
SiscomDesarrollo3Qt::AjustaFilas(QTProductos);
SiscomDesarrollo3Qt::AjustaColumnas(QTProductos);
}
SiscomRegistro3 *QPedidoMaterial::RegistraPedidoMaterial()
{
CQSPedidoMaterial.Observaciones(
			SiscomDesarrollo3Qt::InformacionEdit(QTEObservacionesPedido));
CQSisPedidoMaterialOp lCQSPedidoMaterialOp(SisDatCom);
return lCQSPedidoMaterialOp.Registra(&CQSPedidoMaterial);
}
void QPedidoMaterial::CapturaObservacionProducto(int pintNProducto)
{
char lchrArrObservaciones[256];
QCapturaObservacionPedidoProducto lQCapObsPedido(SisDatCom,chrPtrArgumentos);
if(lQCapObsPedido.Aceptar())
{
lQCapObsPedido.Observaciones(lchrArrObservaciones);
CQSPedidoMaterial.SiscomActualizaCampoSubRegistro(0,1,pintNProducto,"Observaciones",lchrArrObservaciones);
MuestraProductos();
}
}
void QPedidoMaterial::ReIniciaVentana()
{
  CQSPedidoMaterial.EliminaGrupoRegistros(0,1);
  QTProductos->setNumRows(0);
  SiscomPasaFocoControl(QLECProductos);

}
void QPedidoMaterial::EliminaProducto()
{
   CQSPedidoMaterial.EliminaProducto(0,intProductoSeleccionado); 
   MuestraProductos();
}
