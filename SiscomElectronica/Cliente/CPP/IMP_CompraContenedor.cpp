#include <IMP_CompraContenedor.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>


QCompraContenedor *InstanciaCompraContenedor(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QCompraContenedor((SiscomDatCom *)pSisDatCom,
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QCompraContenedor::QCompraContenedor(SiscomDatCom *pSisDatCom,
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				QtCompraContenedor((zSiscomConexion *)gzSiscomConexion,
						   pchrPtrArgumentos,
						   pQWParent,
						   pchrPtrName,
						   pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)

{
}

QCompraContenedor::~QCompraContenedor()
{

}

