#include <IMP_PedidosOtrosExpendios.h>

#include <zProductoTransferir.h>
#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>


#include <qpushbutton.h>
QPedidosOtrosExpendios *InstanciaPedidosOtrosExpendios(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPedidosOtrosExpendios((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPedidosOtrosExpendios::QPedidosOtrosExpendios(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				PedidosOtrosExpendios(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				zSisRegsProductos(0)
{
IniciaVariables();
ConectaSlots();
}

QPedidosOtrosExpendios::~QPedidosOtrosExpendios()
{

}


void QPedidosOtrosExpendios::ConectaSlots()
{
connect(QPBActualizar,SIGNAL(clicked()),SLOT(SlotActualizar()));
connect(QPBImprimir,SIGNAL(clicked()),SLOT(SlotImprimir()));
}
void QPedidosOtrosExpendios::SlotImprimir()
{
Imprimiendo();
}

void QPedidosOtrosExpendios::SlotActualizar()
{
   Consultando(); 
}
void QPedidosOtrosExpendios::IniciaVariables()
{
  Consultando(); 
  QPBImprimir->setEnabled(zSisRegsProductos ? 1 : 0);
}
void QPedidosOtrosExpendios::Consultando()
{
 Consulta();
 Muestra();

}
void QPedidosOtrosExpendios::Consulta()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"TransferenciaOtrosExpendios");
zSisRegsProductos=lzSisElectronica.ProductosTransferenciaOtrosExpendios();
}
void QPedidosOtrosExpendios::Muestra()
{
const char *lchrPtrCampos[]={"cveproducto","cantidad","destino",0};
if(zSisRegsProductos)
{
zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegsProductos,QTDatos);
zSiscomQt3::AjustaColumnasTabla(QTDatos);
}
}
void QPedidosOtrosExpendios::Imprimiendo()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ImprimePedidoOtrosExpendios");
lzSisElectronica.ImprimeTransferenciaOtrosExpendios();
}
