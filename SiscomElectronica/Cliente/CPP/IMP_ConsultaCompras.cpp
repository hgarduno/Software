#include <IMP_ConsultaCompras.h>
#include <IMP_QControlFecha.h> 

#include <zSiscomElectronica.h>

#include <zSiscomDesarrollo4.h> 

QConsultaCompras *InstanciaConsultaCompras(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QConsultaCompras((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QConsultaCompras::QConsultaCompras(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				QtConsultaCompras(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{

}

QConsultaCompras::~QConsultaCompras()
{

}
void QConsultaCompras::Consulta()
{
zSiscomElectronica lzSisECNSCompras(zSiscomDesarrollo4::Conexion(),
				    "ConsultaComprasSiscom");
lzSisECNSCompras.ConsultaComprasSiscom((const char *)QCtrFechaIni->ObtenFecha(),
				       (const char *)QCtrFechaFin->ObtenFecha(),
				       Compras());

}
