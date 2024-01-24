#ifndef __PUNTOSPROMOCIONESCLIENTE_H__
#define __PUNTOSPROMOCIONESCLIENTE_H__
#include <SiscomDesarrollo2.h>



SiscomOperaciones2 *OpPuntosPromocionesCliente();


void PuntosPromocionesCliente(SArgsSiscom *);
void CalculaPuntosCliente(SArgsSiscom *);
void ArgumentosPuntosPromocionesCliente(SArgsSiscom *pSAgsSiscom);
void ClienteNoPublicoEnGeneral(SArgsSiscom *);
void ClientePublicoEnGeneral(SArgsSiscom *);
void AsignaCodigosErrorPromocionesCliente(SArgsSiscom *pSAgsSiscom);

SiscomOperaciones2 *OpValidaPuntosPSelecionadas();

void ValidaPuntosPSeleccionadas(SArgsSiscom *);
void ElClientePuedeTomarLasPromociones(float pfltPuntosPSel,SArgsSiscom *);
void ElClienteNoPuedeTomarLasPromociones(float pfltPuntosPSel,SArgsSiscom *);
#endif
