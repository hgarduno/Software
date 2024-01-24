#include <IMP_DatosPractica.h>
#include <QCtrlMateriasSE.h>

#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

QDatosPractica::QDatosPractica(zSiscomConexion *pzSiscomConexion,
			       zSiscomRegistro *pzSisRegEscuela,
				QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				DatosPractica(pQWParent,pchrPtrName,pbModal,pWFlags),
				zSisRegEscuela(pzSisRegEscuela),
				zSisConexion((zSiscomConexion *)pzSiscomConexion)


{
setFont(pQWParent->font());
IniciaVariables();
ConectaSlots();
exec();
}

QDatosPractica::~QDatosPractica()
{

}

void QDatosPractica::ConectaSlots()
{


}
void QDatosPractica::IniciaVariables()
{
QCtrMaterias->IdEscuela((const char *)(*zSisRegEscuela)["idescuela"]);
QCtrMaterias->Servidor(zSisConexion);
QCtrMaterias->IniciaControl();
}

