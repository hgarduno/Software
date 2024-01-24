#include <ManejadorKits.h>
#include <SqlManejadorKits.h>

SiscomOperaciones2 *OpRegistraProductosTipoProducto()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(10,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosRegistraTipoProducto,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraProductosTipoProducto,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraProductosTipoProducto,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OpRegistraTipoProducto()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(10,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosRegistraTipoProducto,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(GeneraIdTipoProducto,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraTipoProducto,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraTipoProducto,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EnviaIdTipoProducto,lSOpOperaciones);
return lSOpOperaciones;
}
void EnviaIdTipoProducto(SArgsSiscom *pSAgsSiscom)
{
SiscomAnexaRegistroRegreso(pSAgsSiscom,
			   "IdProducto",
			   SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdProducto"));
SiscomEnviaRegreso(pSAgsSiscom);
}
void RegistraTipoProducto(SArgsSiscom *pSAgsSiscom)
{
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomImprimeArgumento("SqlTipoProducto",pSAgsSiscom);
SiscomElectronicaInsertaSistema(pSAgsSiscom,"SqlTipoProducto");
}
void ArgumentosRegistraTipoProducto(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlTipoProducto",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"Operacion",pSAgsSiscom);
}
void GeneraIdTipoProducto(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraIdRegistro(pSAgsSiscom,"IdProducto");
}

void RegistraProductosTipoProducto(SArgsSiscom *pSAgsSiscom)
{
SiscomImprimeArgumento("SqlTipoProducto",pSAgsSiscom);
SiscomElectronicaInsertaSistema(pSAgsSiscom,"SqlTipoProducto");
}
