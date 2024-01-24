#include <IMP_ProductosFaltantes.h>
#include<SiscomDesarrollo3Qt++.h>

#include <qpushbutton.h>
QProductosFaltantes *InstanciaProductosFaltantes(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QProductosFaltantes((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QProductosFaltantes::QProductosFaltantes(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ProductosFaltantes(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QProductosFaltantes::~QProductosFaltantes()
{

}

void QProductosFaltantes::ConectaSlots()
{
connect(QPBFaltantes,
	SIGNAL(clicked()),
	SLOT(SlotFaltantes()));

}
void QProductosFaltantes::SlotFaltantes()
{
Consultando();
}
void QProductosFaltantes::IniciaVariables()
{
Consultando();
}
void QProductosFaltantes::Consultando()
{
	Consulta();
	Muestra();
}
void QProductosFaltantes::Consulta()
{
CQSisProductosFaltantesOp lCQSProdsFaltantes(SisDatCom);
CQSProdsFaltantes.SiscomLimpia();
lCQSProdsFaltantes.Faltantes(chrPtrArgumentos[0],&CQSProdsFaltantes);

}
void QProductosFaltantes::Muestra()
{
const char *lchrPtrCampos[]={"cveproducto","veces",0};
SiscomDesarrollo3Qt::RegsPrincipal4ALaTabla(lchrPtrCampos,QTDatos,&CQSProdsFaltantes);
}
