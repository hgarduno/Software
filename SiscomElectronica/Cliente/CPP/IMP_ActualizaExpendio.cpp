#include <IMP_ActualizaExpendio.h>
#include<SiscomDesarrollo3Qt++.h>
#include <CQSis3QtOperaciones.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qmessagebox.h>
QActualizaExpendio *InstanciaActualizaExpendio(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QActualizaExpendio((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QActualizaExpendio::QActualizaExpendio(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ActualizaExpendio(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QActualizaExpendio::~QActualizaExpendio()
{

}

void QActualizaExpendio::ConectaSlots()
{
connect(QTExpendios,
	SIGNAL(doubleClicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionaExpendio(int,int,int,const QPoint &)));
connect(QPBProductos,
	SIGNAL(clicked()),
	SLOT(SlotProductos()));

}
void QActualizaExpendio::SlotProductos()
{
if(!SisReg3LstProductos.count())
ConsultandoProductosNoExpendio();
else
ActualizaProductosEnElExpendio();
}
void QActualizaExpendio::SlotSeleccionaExpendio(int pintFila,
						int,
						int,
						const QPoint &)
{
   if(pintFila!=-1)
   {
   QTExpendios->selectRow(pintFila);
   EExpendio=EExpendios.at(pintFila);
   }
}
void QActualizaExpendio::IniciaVariables()
{
ConsultandoExpendios();
}


void QActualizaExpendio::ConsultandoProductosNoExpendio()
{
ConsultaProductosNoExpendio();

if(!SisReg3LstProductos.at(0)->EstaElCampo("CodigoRetorno"))
{
QPBProductos->setText("Sincronizar Productos");
MuestraProductosNoExpendio();
}
else
QMessageBox::information(this,
			 "Aviso del sistema",
			 (*SisReg3LstProductos.at(0))["Mensaje"]);

}
void QActualizaExpendio::ConsultaProductosNoExpendio()
{
CQSis3QtOperaciones lCQS3QtOpProdNExpendio(SisDatCom);
lCQS3QtOpProdNExpendio.ProductosEnMatrizNoExpendio(
				(*EExpendio)["idempresa"],
				&SisReg3LstProductos);

}
void QActualizaExpendio::MuestraProductosNoExpendio()
{
const char *lchrPtrCampos[]={"CveProducto",0};

SiscomDesarrollo3Qt::RegistrosALaTabla(
			lchrPtrCampos,
			QTProdsNoExpendio,
			&SisReg3LstProductos);

SiscomDesarrollo3Qt::AjustaColumnas(QTProdsNoExpendio);
}


void QActualizaExpendio::ConsultandoExpendios()
{
ConsultaExpendios();
MuestraExpendios();
SiscomDesarrollo3Qt::AjustaColumnas(QTExpendios);
}
void QActualizaExpendio::ConsultaExpendios()
{
ConsultaEmpresasN lCCnsExpendios(SisDatCom,
				 "Expendios",
				 EExpendios);
}
void QActualizaExpendio::MuestraExpendios()
{
EmpresaN *lEmpresa;
int lintContador;
QTExpendios->setNumRows(EExpendios.count());
for(lEmpresa=EExpendios.first(),
    lintContador=0;
    lEmpresa;
    lEmpresa=EExpendios.next(),
    lintContador++)
QTExpendios->setText(lintContador,0,(*lEmpresa)["RazonSocial"]);
}
void QActualizaExpendio::ActualizandoProductosEnElExpendio()
{
CQSis3QtOperaciones lCQS3QtOpeSincroniza(SisDatCom);
lCQS3QtOpeSincroniza.SincronizaProductosExpendio((*EExpendio)["idempresa"],
						 &SisReg3LstProductos);
}
void QActualizaExpendio::ActualizaProductosEnElExpendio()
{
ActualizandoProductosEnElExpendio();
}
