#include <IMP_ProductosSimilares.h>

#include <zSiscomElectronica.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <zProductos.h>
#include <zProducto.h>

#include <qtextedit.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
QProductosSimilares::QProductosSimilares(const  char *pchrPtrCriterio,
					 QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ProductosSimilares(pQWParent,pchrPtrName,pbModal,pWFlags),
				 zSisConexion((zSiscomConexion *)gzSiscomConexion),
				 chrPtrCriterio(pchrPtrCriterio),
				 intAceptar(0),
				 intSiHayAlgunProducto(0)
{
setFont(pQWParent->font());
IniciaVariables();
ConectaSlots();
if(AnalizandoRespuesta())
exec();
else
QMessageBox::information(this,"Aviso Sistema","NO Hay productos con la descripcion");
}

QProductosSimilares::~QProductosSimilares()
{

}

void QProductosSimilares::ConectaSlots()
{
connect(QTProductos,
	SIGNAL(currentChanged(int,int)),
	SLOT(SlotMostrando(int,int)));
connect(QTProductos,
	SIGNAL(doubleClicked(int,int,int,const QPoint &)),
	SLOT(SlotSelecciono(int,int,int,const QPoint &)));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QTProductos,SIGNAL(selectionChanged()),SLOT(SlotSeleccionando()));
}
void QProductosSimilares::SlotSeleccionando()
{
     QPBAceptar->setEnabled(true);
}
void QProductosSimilares::SlotSelecciono(int pintProducto,
					 int,
					 int,
					 const QPoint &)
{
      if(pintProducto!=-1)
      {
       QTProductos->selectRow(pintProducto);
       /*
       QPBAceptar->setEnabled(true);
       zSiscomQt3::Foco(QPBAceptar);
       */
       
       intProducto=pintProducto;
       Selecciono();

       }
}
void QProductosSimilares::SlotAceptar()
{
  ProductosSeleccionados();
  Selecciono();
}

void QProductosSimilares::SlotMostrando(int pintFila,
					int)
{
   if(pintFila!=-1)
   {
   MostrandoDescripcion(pintFila);
   }
}
void QProductosSimilares::IniciaVariables()
{
  zProdSeleccionados=new zProductos; 
   Consultando();
}
void QProductosSimilares::Consultando()
{
	Consulta();
	if(SiHayAlgunProducto())
	Muestra();
}
void QProductosSimilares::Consulta()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ProductosSE");
zSisRegsProductos=lzSisElectronica.Productos(chrPtrCriterio);
LogSiscom("El puntero de regreso %x",zSisRegsProductos);

intSiHayAlgunProducto=AnalizandoRespuesta();
}
void QProductosSimilares::Muestra()
{
const char *lchrPtrCampos[]={"cveproducto",
			     "dsccorta",
			     "existencia",
			     "exbodegas",
			     "precio",
			     "estante",
			     "caja",
			     0};
SiscomRegistrosLog(zSisRegsProductos);
zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegsProductos,QTProductos);
zSiscomQt3::AjustaFilasTabla(QTProductos);
zSiscomQt3::AjustaColumnasTabla(QTProductos);
}
void QProductosSimilares::MostrandoDescripcion(int pintProducto)
{
   QTEDescripcion->setText((const char *)((*(*zSisRegsProductos)[pintProducto])["dscproducto"]));
}
int QProductosSimilares::Producto(char *pchrPtrClave)
{
if(intAceptar)
    strcpy(pchrPtrClave,
    	   (const char *)((*(*zSisRegsProductos)[intProducto])["cveproducto"]));
return intAceptar;
}
void QProductosSimilares::ProductosSeleccionados()
{
int lintContador;
   for(lintContador=0;lintContador<QTProductos->numRows();lintContador++)
   if(QTProductos->isRowSelected(lintContador))
   AgregaProductoSeleccionado((*zSisRegsProductos)[lintContador]);
}
void QProductosSimilares::AgregaProductoSeleccionado(zSiscomRegistro *pzSisRegProducto)
{
    zProdSeleccionados->Agrega(new zProducto(pzSisRegProducto));    
}
void QProductosSimilares::Selecciono()
{
      intAceptar=1;
      done(1);
}
int QProductosSimilares::HayVariosSeleccionados()
{
   return zProdSeleccionados->NNodos(); 
}
zProductos *QProductosSimilares::Seleccionados()
{
   return zProdSeleccionados;
}
int QProductosSimilares::Aceptar()
{
   return intAceptar;
}
int QProductosSimilares::SiHayAlgunProducto()
{
 return intSiHayAlgunProducto;
}

int QProductosSimilares::AnalizandoRespuesta()
{
 return zSisRegsProductos ? 1 : 0;  
}
