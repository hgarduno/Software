#include <QtGeminiModuloVentas.h>
#include <zSiscomDesarrollo4.h>
#include <qpushbutton.h>

QtGeminiModuloVentas::QtGeminiModuloVentas(SiscomDatCom *pzSisDatCom,
                                           char **pchrPtrArgumentos,
                                           QWidget *pQWParent,
                                           const char *pchrPtrName,
                                           WFlags pWFlags)
    : QModuloVentas(pzSisDatCom, pchrPtrArgumentos, pQWParent, pchrPtrName, pWFlags)
{
    ConectaSlots();
}

QtGeminiModuloVentas::~QtGeminiModuloVentas()
{
}

void QtGeminiModuloVentas::ConectaSlots()
{
    connect(QPBFaltante, SIGNAL(clicked()), SLOT(SlotFaltante()));
}

void QtGeminiModuloVentas::SlotFaltante()
{
    LogSiscom("");
}
