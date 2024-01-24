#include <ProductosSinOrden.h>
#include <ComunElectronica2.h>
SiscomOperaciones2 *OpRegistraProductosSinOrden()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(RegistraProductoSinOrden,lSOpOperaciones2);
return lSOpOperaciones2;
}

void RegistraProductoSinOrden(SArgsSiscom *pSArgsSiscom)
{
SiscomLog("");

}
