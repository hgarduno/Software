#include <QtModuloVentasGemini.h>


QtModuloVentasGemini *InstanciaModuloVentasGemini(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QtModuloVentasGemini((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}

QtModuloVentasGemini::QtModuloVentasGemini(SiscomDatCom *pSisDatCom,
			     char **pchrPtrArgumentos,
			     QWidget *pQWParent,
			     const char *pchrPtrName,
			     WFlags pWFlags):
			     QtGeminiModuloVentas(pSisDatCom,
			     		     pchrPtrArgumentos,
					     pQWParent,
					     pchrPtrName,
					     pWFlags)
{
}

