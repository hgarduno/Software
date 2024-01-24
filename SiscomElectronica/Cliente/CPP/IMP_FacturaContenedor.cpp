#include <IMP_FacturaContenedor.h>

#include <zCompraImportacion.h>
QFacturaContenedor::QFacturaContenedor(zSiscomConexion *pzSisConexion,
				QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				QtFacturaContenedor(pzSisConexion,pQWParent,pchrPtrName,pbModal,pWFlags)
{
}

QFacturaContenedor::~QFacturaContenedor()
{

}
void QFacturaContenedor::Inicia()
{

}
