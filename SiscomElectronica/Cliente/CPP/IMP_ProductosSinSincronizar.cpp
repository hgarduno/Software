#include <IMP_ProductosSinSincronizar.h>
#include<SiscomDesarrollo3Qt++.h>
#include <CQSisOpeProductoNoSincronizado.h>

#include <qpushbutton.h>
QProductosSinSincronizar *InstanciaProductosSinSincronizar(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QProductosSinSincronizar((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QProductosSinSincronizar::QProductosSinSincronizar(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ProductosSinSincronizar(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QProductosSinSincronizar::~QProductosSinSincronizar()
{

}

void QProductosSinSincronizar::ConectaSlots()
{
connect(QPBRegistra,
	SIGNAL(clicked()),
	SLOT(SlotRegistra()));

}
void QProductosSinSincronizar::SlotRegistra()
{
CQSisOpeProductoNoSincronizado lCQSOPNSincronizado(SisDatCom);
lCQSOPNSincronizado.EjecutaSincronizacion(chrPtrArgumentos[0],
					 &SisReg4EdoRegistro);
}
void QProductosSinSincronizar::IniciaVariables()
{
ConsultandoProductos();
}
void QProductosSinSincronizar::ConsultandoProductos()
{
ConsultaProductos();
MuestraProductos();
}
void QProductosSinSincronizar::ConsultaProductos()
{
CQSisOpeProductoNoSincronizado lCQSONSincronizado(SisDatCom);
lCQSONSincronizado.ProductosNoSincronizados(chrPtrArgumentos[0],&CQSPNSincronizado);
}
void QProductosSinSincronizar::MuestraProductos()
{
const char *lchrPtrCampos[]={"razonsocial","cveproducto",0};
SiscomContenidoRegistro4Log(&CQSPNSincronizado);
SiscomDesarrollo3Qt::RegsPrincipal4ALaTabla(lchrPtrCampos,QTProdNoSincronizados,&CQSPNSincronizado);
SiscomDesarrollo3Qt::AjustaColumnas(QTProdNoSincronizados);
}
