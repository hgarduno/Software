#include <IMP_ProductosFaltantes4.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

QProductosFaltantes4::QProductosFaltantes4(char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ProductosFaltantes4(pQWParent,pchrPtrName,pbModal,pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
IniciaVariables();
ConectaSlots();
exec();
}

QProductosFaltantes4::~QProductosFaltantes4()
{

}

void QProductosFaltantes4::ConectaSlots()
{


}
void QProductosFaltantes4::IniciaVariables()
{

}
