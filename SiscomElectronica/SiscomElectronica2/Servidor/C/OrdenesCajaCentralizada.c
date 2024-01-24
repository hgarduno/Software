#include <OrdenesCajaCentralizada.h>
#include <SqlCajaCentralizada.h>
#include <ComunElectronica2.h>
#include <stdlib.h>
SiscomOperaciones2 *OpOrdenesPendientes()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(
					sizeof(SiscomOperaciones2 )*100
					);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendio3,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosOrdenesPendientes,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlOrdenesPendientes,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlDatosCliente,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(OrdenesPendientes,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EnviaOrdenesPendientes,lSOpOperaciones);

return lSOpOperaciones;
}

SiscomOperaciones2 *OpVendeOrdenCajaCentral()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(
					sizeof(SiscomOperaciones2 )*100
					);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendio3,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosVendeOrdenCajaCentral,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlProductosOrdenCajaCentral,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlActualizaEstadoVenta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaVentaCaja,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlActualizaEstadoOrdenCaja,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlActualizaExistenciaPorOrdenCaja,lSOpOperaciones);

SiscomAnexaOperacionAlArreglo2(VendeOrdenCajaCentral,lSOpOperaciones);
return lSOpOperaciones;
}

void EnviaOrdenesPendientes(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaArgumentoCliente("OrdenesPendientes",
			    pSAgsSiscom);

}
/*
insert into VentasCaja values(0,1358710979,35.00,40,5.00,'2013-01-14 18:44:13');|
insert into EscuelaOrden values(1358710979,-1165857915,1165974951,'2013-01-14 18:44:13');|
insert into ventas values(-1165857915,1358710979,'2013-01-14 18:44:13','74LS00',1.000000,7.00,7.00,11805352              25,1153257207,0);|
update existencias set Existencia=Existencia-1.000000            where CveProducto='74LS00' and                               idExpendio=-1165857915|
insert into ventas values(-1165857915,1358710979,'2013-01-14 18:44:13','LM35',1.000000,28.00,28.00,11805352              25,1153257207,0);|
update existencias set Existencia=Existencia-1.000000 where CveProducto='LM35' and                                 idExpendio=-1165857915| */
void VendeOrdenCajaCentral(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRegreso=0;
SiscomLog("==============");
SiscomContenidoSubRegistrosLog(pSAgsSiscom->LCSiscomPro2SREntrada);
SiscomLog("Datos ===============");
SiscomImprimeArgumento("SqlProductosOrden",pSAgsSiscom);
SiscomLog("Sentencias Para Actulizar");
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
			         "SqlRegistraOrden",
				 &lLCSiscomPro2Reg,
				 &lintNRegRegreso);
SiscomImprimeArgumento("SqlRegistraOrden",pSAgsSiscom);

}

void OrdenesPendientes(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Ordenes,
		  *lLCSiscomPro2PrimCliente,
		  *lLCSiscomPro2Cliente;
		
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0,
		  *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
SiscomLog("==============");
SiscomContenidoSubRegistrosLog(pSAgsSiscom->LCSiscomPro2SREntrada);
SiscomLog("==============");
/*
SiscomLog("---------------------");
SiscomImprimeArgumento("SqlOrdenesPendientes",pSAgsSiscom);
SiscomLog("---------------------");
SiscomImprimeArgumento("Cliente",pSAgsSiscom);

*/

lLCSiscomPro2PrimCliente=SiscomArgumentoOperacionPrim("Cliente",pSAgsSiscom);
lLCSiscomPro2Ordenes=SiscomArgumentoOperacionPrim("SqlOrdenesPendientes",pSAgsSiscom);

while(lLCSiscomPro2Ordenes)
{
SiscomCreaListaCamposPro2(lLCSiscomPro2Ordenes->SCSiscomPro2,
			  &lLCSiscomPro2RegPrim,
			  &lLCSiscomPro2RegAct);
lintNRegRegreso++;
if((lLCSiscomPro2Cliente=NodoCliente(lLCSiscomPro2Ordenes,lLCSiscomPro2PrimCliente)))
AgregaDatosCliente(lLCSiscomPro2Cliente,
		   &lLCSiscomPro2RegPrim,
		   &lLCSiscomPro2RegAct,
		   &lintNRegRegreso);
lLCSiscomPro2Ordenes=lLCSiscomPro2Ordenes->SCP2PtrSig;
}
SiscomAsignaInformacionArgumento("OrdenesPendientes",
				 pSAgsSiscom,
				 lLCSiscomPro2RegPrim,
				 lLCSiscomPro2RegAct,
				 lintNRegRegreso);
/*
SiscomContenidoProtocolo(lLCSiscomPro2RegPrim);
*/

}
LCamposSiscomPro2 *NodoCliente(LCamposSiscomPro2 *pLCSiscomPro2Orden,
			       LCamposSiscomPro2 *pLCSiscomPro2PrimCliente)
{
while(pLCSiscomPro2PrimCliente)
{
  if(!SiscomComparaCampoPro2("idventa",
  			    pLCSiscomPro2Orden,
			    pLCSiscomPro2PrimCliente))
  return pLCSiscomPro2PrimCliente;
  pLCSiscomPro2PrimCliente=pLCSiscomPro2PrimCliente->SCP2PtrSig;
}

return 0;
}
void AgregaDatosCliente(LCamposSiscomPro2 *pLCSiscomPro2Orden,
			LCamposSiscomPro2 **pLCSiscomPro2PrimReg,
			LCamposSiscomPro2 **pLCSiscomPro2ActReg,
			int *pintPtrNRegRegreso)
{
SiscomAnexaRegistroPro2(pLCSiscomPro2PrimReg,
			pLCSiscomPro2ActReg,
			pintPtrNRegRegreso,
			"IdPersona,		\
			 Nombre,		\
			 APaterno,		\
			 AMaterno,		\
			 RFC,			\
			 Departamento",
			 SiscomObtenDato(pLCSiscomPro2Orden,"idpersona"),
			 SiscomObtenDato(pLCSiscomPro2Orden,"nombre"),
			 SiscomObtenDato(pLCSiscomPro2Orden,"apaterno"),
			 SiscomObtenDato(pLCSiscomPro2Orden,"amaterno"),
			 SiscomObtenDato(pLCSiscomPro2Orden,"rfc"),
			 SiscomObtenDato(pLCSiscomPro2Orden,"departamento"));


}
void ArgumentosOrdenesPendientes(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(5,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlOrdenesPendientes",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"Cliente",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"OrdenesPendientes",pSAgsSiscom);
}


void ArgumentosVendeOrdenCajaCentral(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(5,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlProductosOrden",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlRegistraOrden",pSAgsSiscom);
}
