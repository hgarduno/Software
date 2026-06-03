#include <IMP_Existencias.h>

#include <zSiscomElectronica.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <zSiscomDesarrollo4.h>


#include <zPedidoExistenciaM.h>

#include <qmessagebox.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>
#include <qtable.h>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <qapplication.h>
#include <qclipboard.h>

QExistencias *InstanciaExistencias(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QExistencias((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QExistencias::QExistencias(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				QtExistencias(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
PedidoExistenciaM()->IdExpendio(zSiscomDesarrollo4::IdExpendio(pchrPtrArgumentos));
}
QExistencias::~QExistencias()
{

}


void QExistencias::PedidoExistenciaMinima()
{
zSiscomElectronica lzSisEPedidoEm(zSiscomDesarrollo4::Conexion(),
				  "PedidoExistenciaMinima");
lzSisEPedidoEm.PedidoExistenciaMinima(PedidoExistenciaM());

}

void QExistencias::RegistraPedidoExistenciaMinima()
{
zSiscomElectronica lzSisEPedidoEm(zSiscomDesarrollo4::Conexion(),
				  "RegistraPedidoExistenciaMinima");
lzSisEPedidoEm.RegistraPedidoExistenciaMinima(PedidoExistenciaM());

}
