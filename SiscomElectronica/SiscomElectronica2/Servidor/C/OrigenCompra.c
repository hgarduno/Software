#include <OrigenCompra.h>
#include <ComunElectronica2.h>
#include <SqlOrigenCompra.h>
#include <SqlClientes.h>
#include <string.h>
#include <stdlib.h>
#include <SqlOrigenCompra.h>
SiscomOperaciones2 *OpOrigenCompra()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(10,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlOrigenCompra,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(OrigenCompra,lSOpOperaciones2); 
return lSOpOperaciones2;
}

void OrigenCompra(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaRegreso2(pSAgsSiscom,"Respondiendo"); 
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
sleep(2); 
SiscomLog("Respondiendo con otra....");
}
