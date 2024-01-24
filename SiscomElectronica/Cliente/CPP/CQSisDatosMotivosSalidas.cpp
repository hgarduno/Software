#include <CQSisDatosMotivosSalidas.h>
CQSisDatosMotivosSalidas::CQSisDatosMotivosSalidas(const char *pchrPtrIdExpendio)
{
SiscomAgregaRegistro();
SiscomAgregaSubRegistro();
SiscomAgregaRegistro(0,MotivosSalidas(pchrPtrIdExpendio));
}
SiscomRegistro3 *CQSisDatosMotivosSalidas::MotivosSalidas(const char *pchrPtrIdExpendio)
{
SiscomRegistro3 *lSisReg3Regreso=new SiscomRegistro3;
(*lSisReg3Regreso) << 
new SiscomCampo3("MotivosSalidas","Todos")	<<
new SiscomCampo3("IdExpendio",pchrPtrIdExpendio);
return lSisReg3Regreso;
}
