#include <IMP_Caja2.h>
#include <zSiscomElectronica.h>


#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <qpushbutton.h>
QCaja2 *InstanciaCaja2(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QCaja2((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QCaja2::QCaja2(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Caja2(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
Conexion((zSiscomConexion *)gzSiscomConexion);
IniciaVariables();
ConectaSlots();
}

QCaja2::~QCaja2()
{

}
void QCaja2::Conexion(zSiscomConexion *pzSisConexion)
{
   zSisConexion=pzSisConexion;
}
void QCaja2::ConectaSlots()
{
connect(QPBOrdenesPendientes,
	SIGNAL(clicked()),
	SLOT(SlotOrdenesPendientes()));

}
void QCaja2::SlotOrdenesPendientes()
{
  ConsultandoOrdenesPendientes();

}
void QCaja2::IniciaVariables()
{
  ConsultandoOrdenesPendientes();
}
void QCaja2::ConsultaOrdenesPendientes()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"OrdenesPendientes");
lzSisElectronica.OrdenesPendientes("2016-03-01","2016-03-05");
}
void QCaja2::ConsultandoOrdenesPendientes()
{
	ConsultaOrdenesPendientes();
	MuestraOrdenesPendientes();
}
void QCaja2::MuestraOrdenesPendientes()
{

}

