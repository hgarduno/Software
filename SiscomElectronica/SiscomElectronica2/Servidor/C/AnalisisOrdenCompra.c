#include <AnalisisOrdenCompra.h>
#include <SqlOrdenCompra.h>
#include <ComunElectronica2.h>
#include <ServidorGeneral.h>
#include <stdlib.h>
#include <string.h>
#include <cups/cups.h>
SiscomOperaciones2 *OpDatosComprasProducto()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*250);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);    
SiscomAnexaOperacionAlArreglo2(ArgumentosDatosComprasProducto,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(GeneraFechasSemestre,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlComprasProductoSemestreAnterior,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlVentasProductoSemestreAnterior,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlComprasProductoSemestreActual,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlVentasProductoSemestreActual,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlExistenciasPrecio,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlHistoricoComprasOrden,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlTotalTransferencias,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlTransferenciasPorExpendio,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(EnviaDatosComprasProducto,lSOpOperaciones); 
return lSOpOperaciones;
}

void EnviaDatosComprasProducto(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2RegPrim=0,
		   *lLCSiscomPro2RegAct=0,
		   *lLCSiscomPro2Historico;
int lintNRegistros=0;
SiscomImprimeArgumento("FechasSemestres",pSAgsSiscom); 
SiscomImprimeArgumento("SqlComprasSemestreAnterior",pSAgsSiscom); 
SiscomImprimeArgumento("SqlVentasSemestreAnterior",pSAgsSiscom); 
SiscomImprimeArgumento("SqlComprasSemestreActual",pSAgsSiscom); 
SiscomImprimeArgumento("SqlVentasSemestreActual",pSAgsSiscom); 
SiscomImprimeArgumento("SqlExistencias",pSAgsSiscom);  
SiscomImprimeArgumento("SqlHistorico",pSAgsSiscom);  
SiscomImprimeArgumento("SqlTotalTransferencias",pSAgsSiscom);  
SiscomImprimeArgumento("SqlTransferenciasPorExpendio",pSAgsSiscom);  

SiscomPonPrimerRegistroArgumento("SqlExistencias",pSAgsSiscom);
SiscomPonPrimerRegistroArgumento("SqlComprasSemestreAnterior",pSAgsSiscom);
SiscomPonPrimerRegistroArgumento("SqlVentasSemestreAnterior",pSAgsSiscom);
SiscomPonPrimerRegistroArgumento("SqlComprasSemestreActual",pSAgsSiscom);
SiscomPonPrimerRegistroArgumento("SqlVentasSemestreActual",pSAgsSiscom);
SiscomPonPrimerRegistroArgumento("SqlExistencias",pSAgsSiscom);
SiscomPonPrimerRegistroArgumento("SqlTotalTransferencias",pSAgsSiscom);
SiscomPonPrimerRegistroArgumento("SqlTransferenciasPorExpendio",pSAgsSiscom);
SiscomAnexaRegistroPro2(
	&lLCSiscomPro2RegPrim,
	&lLCSiscomPro2RegAct,
	&lintNRegistros,
	"CveProducto,			\
	PrecioVenta,			\
	Existencia,			\
	ExBodegas,			\
	ComprasSemAnterior,		\
	VentasSemAnterior,		\
	ComprasSemActual,		\
	VentasSemActual,		\
	TotalTransferencias",
	SiscomCampoDatosEntrada("CveProducto",pSAgsSiscom),
	SiscomObtenCampoArgumento("SqlExistencias","precio",pSAgsSiscom),
	SiscomObtenCampoArgumento("SqlExistencias","existencia",pSAgsSiscom),
	SiscomObtenCampoArgumento("SqlExistencias","exbodegas",pSAgsSiscom),
	SiscomObtenCampoArgumento("SqlComprasSemestreAnterior","comsemant",pSAgsSiscom),
	SiscomObtenCampoArgumento("SqlVentasSemestreAnterior","vensemant",pSAgsSiscom),
	SiscomObtenCampoArgumento("SqlComprasSemestreActual","comsemact",pSAgsSiscom),
	SiscomObtenCampoArgumento("SqlVentasSemestreActual","vensemact",pSAgsSiscom),
	SiscomObtenCampoArgumento("SqlTotalTransferencias","tottrans",pSAgsSiscom));
lLCSiscomPro2Historico=SiscomArgumentoOperacionPrim("SqlHistorico",pSAgsSiscom);
for(;
    lLCSiscomPro2Historico;
    lLCSiscomPro2Historico=lLCSiscomPro2Historico->SCP2PtrSig,
    lintNRegistros++)
    SiscomCreaListaCamposPro2(lLCSiscomPro2Historico->SCSiscomPro2,
    			      &lLCSiscomPro2RegPrim,
			      &lLCSiscomPro2RegAct);
lLCSiscomPro2Historico=SiscomArgumentoOperacionPrim("SqlTransferenciasPorExpendio",pSAgsSiscom);
for(;
    lLCSiscomPro2Historico;
    lLCSiscomPro2Historico=lLCSiscomPro2Historico->SCP2PtrSig,
    lintNRegistros++)
    SiscomCreaListaCamposPro2(lLCSiscomPro2Historico->SCSiscomPro2,
    			      &lLCSiscomPro2RegPrim,
			      &lLCSiscomPro2RegAct);


SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      lintNRegistros,
		      "Respuesta",
		      lLCSiscomPro2RegPrim);

SiscomContenidoProtocolo(lLCSiscomPro2RegPrim);
}

void ArgumentosDatosComprasProducto(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(10,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlComprasSemestreAnterior",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlVentasSemestreAnterior",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"SqlComprasSemestreActual",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(3,"SqlVentasSemestreActual",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(4,"SqlExistencias",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(5,"SqlHistorico",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(6,"SqlTotalTransferencias",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(7,"SqlTransferenciasPorExpendio",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(8,"FechasSemestres",pSAgsSiscom);
}

void GeneraFechasSemestre(SArgsSiscom *pSAgsSiscom)
{
char lchrArrFechaIniSemAnterior[28],
     lchrArrFechaFinSemAnterior[28],
     lchrArrFechaIniSemActual[28],
     lchrArrFechaFinSemActual[28];
SemestreAnterior(lchrArrFechaIniSemAnterior,lchrArrFechaFinSemAnterior);
SemestreActual(lchrArrFechaIniSemActual,lchrArrFechaFinSemActual);	
  SiscomAnexaRegistroArgumento("FechasSemestres",
  				pSAgsSiscom,
				"FechaIniSemAnterior,		\
				 FechaFinSemAnterior,		\
				 FechaIniSemActual,		\
				 FechaFinSemActual",
				lchrArrFechaIniSemAnterior,
				lchrArrFechaFinSemAnterior,
				lchrArrFechaIniSemActual,
				lchrArrFechaFinSemActual);
}
