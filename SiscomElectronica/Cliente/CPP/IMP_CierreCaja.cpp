#include <IMP_CierreCaja.h>


#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <zSiscomElectronica.h>

QCierreCaja *InstanciaCierreCaja(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QCierreCaja((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QCierreCaja::QCierreCaja(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				CierreCaja(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
IniciaVariables();
ConectaSlots();
}

QCierreCaja::~QCierreCaja()
{

}

void QCierreCaja::ConectaSlots()
{


}
void QCierreCaja::IniciaVariables()
{
  CierreHoy();  
}
void QCierreCaja::CierreHoy()
{
zSiscomElectronica lzSiscomE(zSisConexion,"CierreHoy");

lzSiscomE.CierreHoy(&zCCaja);

}
