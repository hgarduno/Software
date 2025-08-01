#include <IMP_ModuloVentasMayoreo.h>



QModuloVentasMayoreo *InstanciaModuloVentasMayoreo(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QModuloVentasMayoreo((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}

QModuloVentasMayoreo::QModuloVentasMayoreo(SiscomDatCom *pSisDatCom,
			     char **pchrPtrArgumentos,
			     QWidget *pQWParent,
			     const char *pchrPtrName,
			     WFlags pWFlags):
			     QManejadorOrden(pSisDatCom,
			     		     pchrPtrArgumentos,
					     pQWParent,
					     pchrPtrName,
					     pWFlags)
{
TextoBotonRegistro("Vende Orden");
TextoBotonNuevaOrden("Nueva Orden");
}

