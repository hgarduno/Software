#ifndef __COTIZANDO_H__
#define __COTIZANDO_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OPCotizaPerfilMedico();
SiscomOperaciones2 *OPCotizaConsulta();
SiscomOperaciones2 *OPDatosParaCobrarConsulta();
SiscomOperaciones2 *OPVentasMedico();

void ArgumentosCotizando(SArgsSiscom *pSAgsSiscom);
void EnviaCotizacionClinicas(SArgsSiscom *pSAgsSiscom);
void CotizaPerfilServicio(SArgsSiscom *);
void CalculaImporteConsulta(SArgsSiscom *);

void SumaProductosSimilares(SArgsSiscom *);
void ActualizaCantidades(SArgsSiscom *);

#endif
