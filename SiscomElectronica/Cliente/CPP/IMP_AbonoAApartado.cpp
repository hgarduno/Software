#include <IMP_AbonoAApartado.h>

#include <zSiscomRegistro.h> 
#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zAbonoAApartado.h>

QAbonoAApartado::QAbonoAApartado(zOrdenVenta *pzOrden,
				   QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				QtAbonoAApartado(pzOrden,
						 pQWParent,
						 pchrPtrName,
						 pWFlags)
{
exec();
}

QAbonoAApartado::~QAbonoAApartado()
{

}

void QAbonoAApartado::Registrar()
{
zSiscomElectronica lzSisElectronica(zSiscomDesarrollo4::Conexion(),"AbonoAApartado");
lzSisElectronica.AbonoAApartado(QtAbonoAApartado::AbonoAApartadoD());
}
