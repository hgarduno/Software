#include <Facturas.h>
#include <ComunElectronica2.h>
#include <SqlFacturas.h>
#include <stdlib.h>

SiscomOperaciones2 *OpAnexaFacturasCompras()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*120);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosFacturas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaFacturasCompras,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ActualizaNumeroFactura,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OpActualizaNumeroFactura()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*120);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosFacturas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlActualizaNumeroFactura,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ActualizaNumeroFactura,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OpBuscaFacturas()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlBuscaFacturas,lSOpOperaciones2);
return lSOpOperaciones2;
}
SiscomOperaciones2 *OpDetalleFactura()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlDetalleFactura,lSOpOperaciones2);
return lSOpOperaciones2;
}
SiscomOperaciones2 *OpFacturasComprasPorFecha()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(150,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlFacturasComprasPeriodo,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(FacturasComprasPeriodo,lSOpOperaciones2);
return lSOpOperaciones2;
}

SiscomOperaciones2 *OpRegistraFactura()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*200);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosRegistraFactura,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(GeneraDatosFactura,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistrandoFactura,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(InsercionAPersonaFisicaMoral,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistrandoDetalleFactura,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistrandoFactura,lSOpOperaciones);
return lSOpOperaciones;
}

void RegistrandoFactura(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRegreso;
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SqlRegistraFactura",
				 &lLCSiscomPro2Reg,
				 &lintNRegRegreso);
/*
SiscomContenidoSubRegistrosLog(pSAgsSiscom->LCSiscomPro2SREntrada);
SiscomImprimeArgumento("SqlRegistraFactura",pSAgsSiscom);
*/
}
void ArgumentosFacturas(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlFacturas",pSAgsSiscom);
}

void ArgumentosRegistraFactura(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlRegistraFactura",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"DatosFactura",pSAgsSiscom);
}
void GeneraDatosFactura(SArgsSiscom *pSAgsSiscom)
{
char lchrArrIdMovimiento[26];
char lchrArrFechaHoy[26];
  SiscomObtenNumeroUnicoChar(lchrArrIdMovimiento);
  SiscomObtenFechaHoyCharAAAADDMM(lchrArrFechaHoy);
  SiscomAnexaRegistroArgumento("DatosFactura",
  				pSAgsSiscom,
				"IdFactura,Fecha",
				lchrArrIdMovimiento,
				lchrArrFechaHoy);
}
void AgregaFacturasNumFacturaVacio(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				   LCamposSiscomPro2 **pLCSiscomPro2RegPrim,
				   LCamposSiscomPro2 **pLCSiscomPro2RegAct,
				   int *pintPtrNRegReg)
{
for(*pintPtrNRegReg=0;
     pLCSiscomPro2Dat;
     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig,
     (*pintPtrNRegReg)++)
SiscomCreaListaCamposPro2(pLCSiscomPro2Dat->SCSiscomPro2,
			  pLCSiscomPro2RegPrim,
			  pLCSiscomPro2RegAct);
}
void FacturasComprasPeriodo(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2Agrupados *lLCSiscomPro2AgReg=0;
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0,
                  *lLCSiscomPro2RegAct=0;
int lintNRegRegreso=0;
SiscomAgrupaListaPorCampoPro2("numfactura",
			       pSAgsSiscom->LCSiscomPro2Regreso,
			       &lLCSiscomPro2AgReg);
AgregaFacturasNumFacturaVacio(lLCSiscomPro2AgReg->LCSiscomPro2Prim,
			      &lLCSiscomPro2RegPrim,
			      &lLCSiscomPro2RegAct,
			      &lintNRegRegreso);
 lLCSiscomPro2AgReg=lLCSiscomPro2AgReg->LCSiscomPro2AgrupaS;
for(;
     lLCSiscomPro2AgReg;
     lLCSiscomPro2AgReg=lLCSiscomPro2AgReg->LCSiscomPro2AgrupaS,
     lintNRegRegreso++)
{

SiscomCreaListaCamposPro2(lLCSiscomPro2AgReg->LCSiscomPro2Prim->SCSiscomPro2,
			  &lLCSiscomPro2RegPrim,
			  &lLCSiscomPro2RegAct);
}
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      lintNRegRegreso,
		      "Respuesta",
		      lLCSiscomPro2RegPrim);
}


void InsercionAPersonaFisicaMoral(SArgsSiscom *pSArgsSiscom)
{
const char *lchrPtrPersona=SiscomCampoSubRegistroPrincipalArgs("persona",pSArgsSiscom);
SiscomLog("%s",lchrPtrPersona);
   if(!strcmp(lchrPtrPersona,"PersonaFisica"))
   SqlRegistrandoFacturaPersonaFisica(pSArgsSiscom);
   if(!strcmp(lchrPtrPersona,"PersonaMoral"))
   SqlRegistrandoFacturaPersonaMoral(pSArgsSiscom);
}

void ActualizaNumeroFactura(SArgsSiscom *pSAgsSiscom)
{
SiscomImprimeArgumento("SqlFacturas",pSAgsSiscom);
SiscomLog("Se Envia al Servidor");
SiscomEnviaServidorArgumento(pSAgsSiscom,"SqlFacturas");
}

