#ifndef __SQLCOMPRAS_H__
#define __SQLCOMPRAS_H__
#include <SiscomDesarrollo2.h>
/*!
 * \brief  Ejecuta la consulta ....
 *
 */
void SqlHistoricoCompras(SArgsSiscom *);
void SqlHistoricoComprasExistenciaMinima(SArgsSiscom *);
void SqlComprasSemestreAnterior(SArgsSiscom *);
void SqlVentasTotalesSemestreAnterior(SArgsSiscom *);
void SqlVentasActuales(SArgsSiscom *);
const char *ObtenTotales(LCamposSiscomPro2 *);
#endif
