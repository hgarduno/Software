#include <MotivoInventario.h>
void SqlMotivoInventario(SArgsSiscom *pSAgsSiscom)
{
SiscomEjecutaConsultaYResponde(pSAgsSiscom,"select * from motivoinventario");
}
