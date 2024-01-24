#include <IMP_ClientesRegistrados.h>
QClientesRegistrados::QClientesRegistrados(
				    zSiscomRegistros *pzSisRegistros,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ClientesRegistrados(pQWParent,pchrPtrName,pbModal,pWFlags),
				zSisRegsClientes(pzSisRegistros)
{
IniciaVariables();
ConectaSlots();
}

QClientesRegistrados::~QClientesRegistrados()
{

}

void QClientesRegistrados::ConectaSlots()
{


}
void QClientesRegistrados::IniciaVariables()
{

}
