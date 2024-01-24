#include <IMP_ExpendiosSE.h>
QExpendiosSE::QExpendiosSE(QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ExpendiosSE(pQWParent,pchrPtrName,pbModal,pWFlags)
{
IniciaVariables();
ConectaSlots();
exec();
}

QExpendiosSE::~QExpendiosSE()
{

}

void QExpendiosSE::ConectaSlots()
{


}
void QExpendiosSE::IniciaVariables()
{

}
