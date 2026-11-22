#ifndef __QTMODULOVENTASGEMINI_H__
#define __QTMODULOVENTASGEMINI_H__

#include <QtGeminiModuloVentas.h> 



class QtModuloVentasGemini:public QtGeminiModuloVentas
{
Q_OBJECT
public:
	QtModuloVentasGemini(SiscomDatCom *pSisDatCom,
                              char **pchrPtrArgumentos,
                              QWidget *pQWParent,
                              const char *pchrPtrName,
                              WFlags pWFlags);

private:

};

extern "C" QtModuloVentasGemini *InstanciaModuloVentasGemini(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags);

#endif
