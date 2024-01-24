#include <SQLFormaPago.h>
void SQLFormaPago(SArgsSiscom *pSAgsSiscom)
{
EjecutaConsultaYResponde(pSAgsSiscom,"select * from formapago");
}
