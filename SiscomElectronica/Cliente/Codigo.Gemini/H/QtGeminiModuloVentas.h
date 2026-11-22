#ifndef QT_GEMINI_MODULO_VENTAS_H
#define QT_GEMINI_MODULO_VENTAS_H

#include <IMP_ModuloVentas.h>

class SiscomDatCom;

class QtGeminiModuloVentas : public QModuloVentas
{
    Q_OBJECT

public:
    QtGeminiModuloVentas(SiscomDatCom *pzSisDatCom,
                         char **pchrPtrArgumentos,
                         QWidget *pQWParent,
                         const char *pchrPtrName,
                         WFlags pWFlags);
    ~QtGeminiModuloVentas();

private:
    void ConectaSlots();

private slots:
    void SlotFaltante();
};

#endif // QT_GEMINI_MODULO_VENTAS_H
