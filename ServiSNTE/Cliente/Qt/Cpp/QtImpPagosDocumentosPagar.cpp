#include <QtImpPagosDocumentosPagar.h>
#include <QtImprimiendoRelacionChequesPagar.h>
#include <zReportesServiSNTE.h>
#include <QCtrlTiendasEntrega.h>
#include <QCtrlProveedoresSS.h>

#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <zImpresionRelacionChequesPagar.h>
#include <zRelacionChequesPagar.h>

#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qtextedit.h>
QtImpPagosDocumentosPagar::QtImpPagosDocumentosPagar(QWidget *pQWParent,
					       const char *pchrPtrName):
					   PagosDocumentosPagar(pQWParent,pchrPtrName)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpPagosDocumentosPagar::IniciaVariables()
{

}
void QtImpPagosDocumentosPagar::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpPagosDocumentosPagar::ConectaSlots()
{
   connect(QPBImprimir,
           SIGNAL(clicked()),
           SLOT(SlotImprimir()));
}

void QtImpPagosDocumentosPagar::SlotImprimir()
{
zImpresionRelacionChequesPagar *lzImpRelacionChequesPagar=new zImpresionRelacionChequesPagar(zLstRelacion);
QtImprimiendoRelacionChequesPagar lQtImpRelacionChequesPagar(zSisConexion,
                                                 lzImpRelacionChequesPagar);
}
