#include <CQSisPromocionesCliente.h>
#include <CQSisExpendios.h>
#include <SiscomRegistros3.h>
CQSisPromocionesCliente::CQSisPromocionesCliente(
			   SiscomRegistro3 *pSisReg3Expendio,
			   SiscomRegistro3 *pSisReg3Cliente,
			   SiscomRegistro3Lst *pSisReg3LstPromos,
			   const char *pchrPtrPuntosTotPromos)
{
SiscomAgregaRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaRegistro(0,pSisReg3Expendio);
SiscomAgregaRegistro(1,pSisReg3Cliente);
SiscomAgregaRegistros(2,pSisReg3LstPromos);
SiscomAgregaRegistro(3,PuntosTotalesPromo(pchrPtrPuntosTotPromos));
}
void CQSisPromocionesCliente::EdoTomaPromociones(SiscomRegistro4 *pSisReg4EdoTomaPromocion)
{
SisReg4EdoTomaPromocion=pSisReg4EdoTomaPromocion;
}
SiscomRegistro3 *CQSisPromocionesCliente::PuntosTotalesPromo(
				const char *pchrPtrPuntosTotPromos)
{
SiscomRegistro3 *lSisReg3Regreso=new SiscomRegistro3;
(*lSisReg3Regreso) << 
new SiscomCampo3("PuntosTotalesPromos",pchrPtrPuntosTotPromos);

return lSisReg3Regreso;
}
