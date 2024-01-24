#include <CQSisDatosOrdenCaja.h>

#include <SiscomRegistros3.h>
CQSisDatosOrdenCaja::CQSisDatosOrdenCaja(const char *pchrPtrIdExpendio)
{
SiscomAgregaRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaRegistro(0,DatosOrdenesPendientes(pchrPtrIdExpendio));
}
CQSisDatosOrdenCaja::CQSisDatosOrdenCaja(const char *pchrPtrIdExpendio,
					 const char *pchrPtrPago,
					 const char *pchrPtrCambio,
				    SiscomRegistro3 *pSisReg3Orden)
{
SiscomAgregaRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaRegistro(0,DatosOrdenesPendientes(pchrPtrIdExpendio));
SiscomAgregaRegistro(1,pSisReg3Orden);
SiscomAgregaRegistro(2,DatosPago(pchrPtrPago,pchrPtrCambio));
}
CQSisDatosOrdenCaja *CQSisDatosOrdenCaja::OrdenesPendientes(const char *pchrPtrIdExpendio)
{
return new CQSisDatosOrdenCaja(pchrPtrIdExpendio); 
}

SiscomRegistro3 *CQSisDatosOrdenCaja::DatosOrdenesPendientes(const char *pchrPtrIdExpendio)
{
SiscomRegistro3 *lSisReg3Regreso;

lSisReg3Regreso=new SiscomRegistro3;

(*lSisReg3Regreso)				<<
new SiscomCampo3("OrdenesPendientes","Todas")	<<
new SiscomCampo3("IdExpendio",pchrPtrIdExpendio);
return lSisReg3Regreso;
}

SiscomRegistro3 *CQSisDatosOrdenCaja::DatosPago(const char *pchrPtrPago,
						const char *pchrPtrCambio)
{
SiscomRegistro3 *lSisReg3Regreso;

lSisReg3Regreso=new SiscomRegistro3;

(*lSisReg3Regreso)				<<
new SiscomCampo3("Pago",pchrPtrPago)	<<
new SiscomCampo3("Cambio",pchrPtrCambio);
return lSisReg3Regreso;

}
