#include <IMP_SeleccionaCompraImp.h>
#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>

#include <zCompraImportacion.h>
#include <zEmpresa.h>

#include <qtable.h>
#include <qpushbutton.h>
QSeleccionaCompraImp::QSeleccionaCompraImp(char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				SeleccionaCompraImp(pQWParent,pchrPtrName,pbModal,pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				intAceptar(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QSeleccionaCompraImp::~QSeleccionaCompraImp()
{

}

void QSeleccionaCompraImp::ConectaSlots()
{
connect(QTCompsImportacion,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSelecciono(int,int,int,const QPoint &)));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
}
void QSeleccionaCompraImp::SlotAceptar()
{
   intAceptar=1;
    done(1);
}
void QSeleccionaCompraImp::SlotSelecciono(int pintNCompra,int,int,const QPoint &)
{
  if(pintNCompra!=-1)
  {
   zComImportacion=(zCompraImportacion *)zCompsImportacion[pintNCompra];
   zSiscomQt3::Foco(QPBAceptar);
  }
}
void QSeleccionaCompraImp::IniciaVariables()
{
  Consultando();
}
void QSeleccionaCompraImp::Muestra()
{
int lintContador;
zCompraImportacion *lzComImportacion;
QTCompsImportacion->setNumRows(zCompsImportacion.NNodos());
for(lzComImportacion=(zCompraImportacion *)zCompsImportacion.Primer(),
    lintContador=0;
    lzComImportacion;
    lzComImportacion=(zCompraImportacion *)zCompsImportacion.Siguiente(),
    lintContador++)
{
  QTCompsImportacion->setText(lintContador,0,lzComImportacion->Empresa()->RazonSocial());
  QTCompsImportacion->setText(lintContador,1,lzComImportacion->Descripcion());
  QTCompsImportacion->setText(lintContador,2,lzComImportacion->ImporteFactura());
  QTCompsImportacion->setText(lintContador,3,lzComImportacion->PesoCompra());
}
zSiscomQt3::AjustaColumnasTabla(QTCompsImportacion);
}
void QSeleccionaCompraImp::Consulta()
{
zSiscomElectronica lzSisElecCompsImp(zSisConexion,"ComprasImportacion");
lzSisElecCompsImp.ConsultaComprasImportacion("","",&zCompsImportacion);
}
void QSeleccionaCompraImp::Consultando()
{
   Consulta();
   Muestra();
}
zCompraImportacion *QSeleccionaCompraImp::CompraImportacion()
{
  return zComImportacion;
}
int QSeleccionaCompraImp::Aceptar()
{
  return intAceptar;
}
