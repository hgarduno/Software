#include <IMP_DescripcionCompraImportacion.h>
QDescripcionCompraImportacion::QDescripcionCompraImportacion(char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				DescripcionCompraImportacion(pQWParent,pchrPtrName,pbModal,pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QDescripcionCompraImportacion::~QDescripcionCompraImportacion()
{

}

void QDescripcionCompraImportacion::ConectaSlots()
{


}
void QDescripcionCompraImportacion::IniciaVariables()
{

}
