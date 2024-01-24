#include <IMP_ProductoApartados.h>
#include <zSiscomElectronica.h>
#include <zProductoCotizar.h>

#include <zSiscomRegistros.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>

#include <zSiscomQt3.h>

#include <qpushbutton.h>
QProductoApartados::QProductoApartados(
				    zProductoCotizar *pzProdCotizar,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ProductoApartados(pQWParent,pchrPtrName,pWFlags),
				zProdCotizar(pzProdCotizar),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)

{
IniciaVariables();
if(Consultando())
{
ConectaSlots();
exec();
}
}

QProductoApartados::~QProductoApartados()
{

}

void QProductoApartados::ConectaSlots()
{
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));

}
void QProductoApartados::SlotAceptar()
{
   intAceptar=1;
   done(1);
}
void QProductoApartados::SlotCancelar()
{
	intAceptar=0;
	done(1);
}
void QProductoApartados::IniciaVariables()
{
}
int QProductoApartados::Consultando()
{
   if(Consulta())
   {
   Muestra();
   return 1;
   }
   else
   return 0;
}
int QProductoApartados::Consulta()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ProductoEnApartados");
zSisRegsProdEnApartados=lzSisElectronica.ProductoEnApartados(zProdCotizar->Clave());
LogSiscom("Regresaron %d Productos",zSisRegsProdEnApartados->NNodos());
if(!zSisRegsProdEnApartados->NNodos())
return 0;
else
return 1;

}
void QProductoApartados::Muestra()
{
const char *lchrPtrCampos[]={"fechaentrega",
		 	"horaentrega",
			"nombre",
			"cantidad",
			"precio",
			"importe",
			"acuenta",
			"porpagar",
			0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegsProdEnApartados,QTApartados);
}
void QProductoApartados::reject()
{

}

