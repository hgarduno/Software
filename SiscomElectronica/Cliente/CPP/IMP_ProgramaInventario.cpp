#include <IMP_ProgramaInventario.h>
#include<SISCOMComunicaciones++.h>
QProgramaInventario *InstanciaProgramaInventario(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QProgramaInventario((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QProgramaInventario::QProgramaInventario(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ProgramaInventario(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QProgramaInventario::~QProgramaInventario()
{

}

void QProgramaInventario::ConectaSlots()
{


}
void QProgramaInventario::IniciaVariables()
{

}
void QProgramaInventario::closeEvent(QCloseEvent *)
{

emit SignalTerminar(this);
}

