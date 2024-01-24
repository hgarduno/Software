#include <IMP_ModuloBodegas.h>

#include <zSiscomConexion.h>
#include <zSiscomElectronica.h>
#include <zProductoCotizar.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

QModuloBodegas *InstanciaModuloBodegas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QModuloBodegas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QModuloBodegas::QModuloBodegas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				QtModuloBodegas(pchrPtrArgumentos,
						pQWParent,
						pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
QtModuloBodegas::Conexion(zSisConexion);
QtModuloBodegas::IniciaVariables();
}

QModuloBodegas::~QModuloBodegas()
{

}
