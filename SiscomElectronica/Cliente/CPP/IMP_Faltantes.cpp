#include <IMP_Faltantes.h>
#include <zProductoCotizar.h>

#include <qtabwidget.h>
#include <qlineedit.h>
#include <qtextedit.h>
QFaltantes::QFaltantes(zProductoCotizar *pzProductoCot,
				char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				Faltantes(pQWParent,pchrPtrName,pbModal,pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos),
				zProdCotizar(pzProductoCot)
{
IniciaVariables();
ConectaSlots();
SiscomRegistroLog2(Producto());
exec();
}

QFaltantes::~QFaltantes()
{
}

void QFaltantes::ConectaSlots()
{

}
void QFaltantes::IniciaVariables()
{
    TipoProducto();
}
zProductoCotizar *QFaltantes::Producto()
{

     return zProdCotizar;
}
void QFaltantes::TipoProducto()
{
     if(Producto()->Clave())
     {
     QTWTipoProducto->page(0)->setEnabled(true);
     QTWTipoProducto->page(1)->setEnabled(false);
     QTWTipoProducto->setCurrentPage(0);
     MuestraProductoRegistrado();
     }
     else
     {
     QTWTipoProducto->page(0)->setEnabled(false);
     QTWTipoProducto->page(1)->setEnabled(true);
     QTWTipoProducto->setCurrentPage(1);
     MuestraNuevoProducto();
     }

}
void QFaltantes::MuestraProductoRegistrado()
{
     QLEProducto->setText(Producto()->Clave()); 
     QTEDescripcion->setText(Producto()->Descripcion());
}
void QFaltantes::MuestraNuevoProducto()
{
    QTEDescripcionNvo->setText(Producto()->Descripcion());	

}
