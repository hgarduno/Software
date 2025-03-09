#include <SQLFormaPago.h>
#include <ComunSiscomTiendas4.h>
void SQLFormaPago(SArgsSiscom *pSAgsSiscom)
{
EjecutaConsultaYResponde(pSAgsSiscom,"select * from formapago");
}
