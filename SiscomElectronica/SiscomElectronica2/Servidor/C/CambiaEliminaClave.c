#include <CambiaEliminaClave.h>
#include <SqlCambiaEliminaClave.h>
#include <ComunElectronica2.h>
#include <ComunElectronica.h>
SiscomOperaciones2 *OpEliminaClave()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosCambiaEliminaClave,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaEliminaPrecios,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaEliminaInventario,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaEliminaMaterialBodega,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaEliminaCompras,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaEliminaTicketImpresoHistorial,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaEliminaDetallePractica,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaEliminaInventarioBodega,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaEliminaTransfiereMaterial,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaEliminaBodegaAExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaEliminaDesajusteInventario,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaEliminaClaveSat,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaEliminaProductos,lSOpOperaciones);

SiscomAnexaOperacionAlArreglo2(CambiaEliminaClave,lSOpOperaciones);

return lSOpOperaciones;
}
SiscomOperaciones2 *OpCambiaClave()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosCambiaEliminaClave,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaInsertaCveNueva,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaActualizaPrecios,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaActualizaTransfiereMaterial,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaActualizaBodegaAExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaActualizaCompras,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaActualizaDetallePedido,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaActualizaDetallePractica,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaActualizaInventario,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaActualizaMaterialBodega,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaActualizaTicketImpresoHistorial,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaActualizaExistencias,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaActualizaVentas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaEliminaDesajusteInventario,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaEliminaProductos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(CambiaEliminaClave,lSOpOperaciones);
return lSOpOperaciones;
}
void ArgumentosCambiaEliminaClave(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlCambiaClave",pSAgsSiscom);

}
void CambiaEliminaClave(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRegreso;
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomImprimeArgumento("SqlCambiaClave",pSAgsSiscom);
/*
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SqlCambiaClave",
				 &lLCSiscomPro2Reg,
				 &lintNRegRegreso);
SiscomContenidoProtocolo(lLCSiscomPro2Reg);

*/
SiscomElectronicaInsertaSistema(pSAgsSiscom,"SqlCambiaClave");
}
