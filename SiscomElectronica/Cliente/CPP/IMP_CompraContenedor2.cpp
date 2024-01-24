#include <IMP_CompraContenedor2.h>

#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
QCompraContenedor2 *InstanciaCompraContenedor2(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QCompraContenedor2((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QCompraContenedor2::QCompraContenedor2(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				QtCompraContenedor2(pchrPtrArgumentos,
						    (zSiscomConexion *)gzSiscomConexion,
						    pQWParent,
						    pchrPtrName,
						    pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
}

QCompraContenedor2::~QCompraContenedor2()
{

}
