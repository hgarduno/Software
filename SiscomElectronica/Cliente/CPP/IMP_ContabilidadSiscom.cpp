#include <IMP_ContabilidadSiscom.h>
#include <IMP_QControlFecha.h> 


#include <zSiscomDesarrollo4.h>
#include <zSiscomConexion.h>
#include <zSiscomContabilidad.h> 

QContabilidadSiscom *InstanciaContabilidadSiscom(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
        return new QContabilidadSiscom((SiscomDatCom *)pSisDatCom,
                        pchrPtrArgumentos,
                        (QWidget *)pQWParent,
                        pchrPtrName,
                        pintWFlags);
}



QContabilidadSiscom::QContabilidadSiscom(SiscomDatCom *pSisDatCom,
				         char **pchrPtrArgumentos,
					 QWidget *pQWParent,
				         const char *pchrPtrName,
					 WFlags pWFlags):
				QtContabilidadSiscom(pQWParent,pchrPtrName,pWFlags)
{
IniciaVariables();

}

QContabilidadSiscom::~QContabilidadSiscom()
{


}


void QContabilidadSiscom::IniciaVariables()
{

}

void QContabilidadSiscom::OrdenesPagoElectronico()
{
zSiscomContabilidad lzSisContabilidad(Conexion(),"OrdenesTransferenciaTarjeta");
lzSisContabilidad.OrdenesTarjetaTransferencia((const char *)QCtrFechaInicio->ObtenFecha(),
					      (const char *)QCtrFechaFin->ObtenFecha());
LogSiscom("");
}
zSiscomConexion *QContabilidadSiscom::Conexion()
{
  return (zSiscomConexion *)gzSiscomConexion;
 }
