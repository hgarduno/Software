#include <PuntosPromocionesCliente.h>
#include <SqlPuntosPromocionesClientes.h>
#include <ComunElectronica2.h>

#include <stdlib.h>


/*
 * Tepotzotlan 1 Agosto 2011 
 * Se requiere integrar como parte del manejo de los puntos siscom
 * el seguimiento para las operaciones que el cliente hace, aqui
 * se debera agregar a la actualizacion de ComprasClientes (Al Realizar la venta)
 * el seguimiento de cada una de las operaciones que los clientes hacen
 * es decir si comprasn se debera actualizar ComprasClientes y agregar 
 * a SeguimientoCOmprasClientes una entrada por cada vez que el cliente
 * realiza una compra.
 *
 * Una vez que el cliente decide tomar una promocion con los puntos 
 * se debera incluir el seguimiento de esta operacion, aqui lo importante
 * es llevar el control de los puntos que el cliente toma y los puntos 
 * que sobran, para el calculo de los puntos totales, en este punto
 * tengo definidas las tablas SeguimientoPuntosClientes con un IdOperacion
 * que se insertara en DetalleOperacionPuntosClientes para saber en esta
 * operacion las promociones que el cliente tomo, aqui el punto que habra
 * que resolver tiene que ver con dejar en una sola tabla el total de 
 * puntos que se tomaron en esta operacion y el saldo de puntos, para que
 * al momento de consultar los puntos totales del cliente calculados 
 * via las compras del cliente quede la cantidad correcta
 *
 */



SiscomOperaciones2 *OpValidaPuntosPSelecionadas()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*120);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ValidaPuntosPSeleccionadas,lSOpOperaciones);
return lSOpOperaciones;
}

float CuentaPuntosPSeleccionadas(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
float lfltSumaPuntos=0.0;
for(lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
  lfltSumaPuntos+=SiscomObtenCampoAFloat(lLCSiscomPro2Dat,"puntos");
return lfltSumaPuntos;
}
void ValidaPuntosPSeleccionadas(SArgsSiscom *pSAgsSiscom)
{
float lfltPuntosPSel=CuentaPuntosPSeleccionadas(pSAgsSiscom);
SiscomLog("Puntos promociones seleccionadas:%f",lfltPuntosPSel);
if((lfltPuntosPSel<=SiscomCampoDatosEntradaFloat("PuntosCliente",pSAgsSiscom)))
ElClientePuedeTomarLasPromociones(lfltPuntosPSel,pSAgsSiscom);
else
ElClienteNoPuedeTomarLasPromociones(lfltPuntosPSel,pSAgsSiscom);

SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
}
void SaldoPuntosCliente(float pfltPuntosPSel,
			 SArgsSiscom *pSAgsSiscom,
			 char *pchrPtrSaldoPuntos)
{
 float lfltSaldoPuntos=SiscomCampoDatosEntradaFloat("PuntosCliente",pSAgsSiscom)-
  	 pfltPuntosPSel;
sprintf(pchrPtrSaldoPuntos,"%.2f",lfltSaldoPuntos);
}
void ElClientePuedeTomarLasPromociones(float pfltPuntosPSel,
				       SArgsSiscom *pSAgsSiscom)
{
char lchrArrSaldoPuntos[25];
char lchrArrPuntosPSel[25];

SaldoPuntosCliente(pfltPuntosPSel,pSAgsSiscom,lchrArrSaldoPuntos);
sprintf(lchrArrPuntosPSel,"%.2f",pfltPuntosPSel);
SiscomAnexaRegistroRegreso(pSAgsSiscom,
			   "EdoValidacion,PuntosPromocion,SaldoPuntos",
			   "1",
			   lchrArrPuntosPSel,
			   lchrArrSaldoPuntos);
}
void ElClienteNoPuedeTomarLasPromociones(float pfltPuntosPSel,
				       SArgsSiscom *pSAgsSiscom)
{
char lchrArrPuntosPSel[25];

sprintf(lchrArrPuntosPSel,"%.2f",pfltPuntosPSel);
SiscomAnexaRegistroRegreso(pSAgsSiscom,
			   "EdoValidacion,PuntosPromocion,SaldoPuntos",
			   "0",
			   lchrArrPuntosPSel,
			   "0");
}













SiscomOperaciones2 *OpPuntosPromocionesCliente()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*200);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(AsignaCodigosErrorPromocionesCliente,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ClienteNoPublicoEnGeneral,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosPuntosPromocionesCliente,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlCostoPuntos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlComprasCliente,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlPuntosCanjeados,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(CalculaPuntosCliente,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlPromocionesCliente,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(PuntosPromocionesCliente,lSOpOperaciones);
return lSOpOperaciones;
}



void PuntosPromocionesCliente(SArgsSiscom *pSAgsSiscom)
{
const char *lchrPtrPuntosCliente;
char lchrArrNoPromociones[25];
int lintNRegPromociones;
lchrPtrPuntosCliente=SiscomObtenCampoArgumento("PuntosCliente",
					       "PuntosCliente",
					       pSAgsSiscom);
lintNRegPromociones=SiscomArgumentosNumeroRegistros("SqlPromociones",pSAgsSiscom);
sprintf(lchrArrNoPromociones,"%d",lintNRegPromociones);
SiscomAnexaRegistroRegreso(pSAgsSiscom,
			   "PuntosCliente,Promociones",
			   lchrPtrPuntosCliente,
			   lchrArrNoPromociones);
SiscomSumaListas(pSAgsSiscom->LCSiscomPro2Regreso,
		 SiscomArgumentoOperacionPrim("SqlPromociones",pSAgsSiscom));
pSAgsSiscom->intNumRegRegreso+=SiscomArgumentosNumeroRegistros("SqlPromociones",pSAgsSiscom);
/*
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
*/
}

void CalculaPuntosCliente(SArgsSiscom *pSAgsSiscom)
{
char lchrArrPuntosCliente[25];
float lfltTotalComprasC;
float lfltPuntosCliente;
float lfltCostoPunto;
SiscomPonPrimerRegistroArgumento("SqlComprasCliente",pSAgsSiscom);
SiscomPonPrimerRegistroArgumento("SqlCostoPunto",pSAgsSiscom);
lfltTotalComprasC=SiscomObtenCampoArgumentoFloat(
			"SqlComprasCliente",
			"compscliente",
			pSAgsSiscom);
lfltCostoPunto=SiscomObtenCampoArgumentoFloat(
			"SqlCostoPunto",
			"pesosppunto",
			pSAgsSiscom);

lfltPuntosCliente=(lfltTotalComprasC/lfltCostoPunto) -
		  SiscomObtenCampoArgumentoFloat("SqlPuntosCanjeados",
		  				  "TotalPuntosCanjeados",
						  pSAgsSiscom);
sprintf(lchrArrPuntosCliente,"%.2f",lfltPuntosCliente);
SiscomAnexaRegistroArgumento("PuntosCliente",
			     pSAgsSiscom,
			     "PuntosCliente,IdCliente",
			     lchrArrPuntosCliente,
			     "Cliente");
}
void ArgumentosPuntosPromocionesCliente(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(5,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlComprasCliente",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlPromociones",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"SqlCostoPunto",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(3,"PuntosCliente",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(4,"SqlPuntosCanjeados",pSAgsSiscom);
}

void ClienteNoPublicoEnGeneral(SArgsSiscom *pSAgsSiscom)
{
   if(!strcmp(pSAgsSiscom->chrPtrArgConsulta[3],"Publico En General"))
    pSAgsSiscom->intCodigoRetorno=1;
}
void AsignaCodigosErrorPromocionesCliente(SArgsSiscom *pSAgsSiscom)
{
	pSAgsSiscom->SiscomError[1]=ClientePublicoEnGeneral;
}
void ClientePublicoEnGeneral(SArgsSiscom *pSAgsSiscom)
{
  SiscomLog("El Cliente es publico en General, no se hace calculo de puntos");
  SiscomLog("El Cliente es publico en General, no se hace calculo de puntos");
  SiscomLog("El Cliente es publico en General, no se hace calculo de puntos");
  SiscomLog("El Cliente es publico en General, no se hace calculo de puntos");
SiscomAnexaRegistroRegreso(pSAgsSiscom,
			   "PuntosCliente,Promociones",
			   "0",
			   "0");
SiscomEnviaRegreso2(pSAgsSiscom,"Respuesta");
SiscomLog("El numero de registros:%d",pSAgsSiscom->intNumRegRegreso);
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
}
