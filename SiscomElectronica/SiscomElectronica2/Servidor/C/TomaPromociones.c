#include <TomaPromociones.h>
#include <ComunElectronica2.h>
#include <SqlTomaPromocion.h>


#include <stdlib.h>


SiscomOperaciones2 *OpTomaPromociones()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendio3,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosTomaPromociones,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(GeneraIdOperacion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlSeguimientoPuntosClientes,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlDetalleOperacionPuntosClientes,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraTomaPromocionesCliente,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(TomaPromociones,lSOpOperaciones);
return lSOpOperaciones;


}
void RegistraTomaPromocionesCliente(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaServidorArgumento(pSAgsSiscom,"SqlSeguimiento");
}
void TomaPromociones(SArgsSiscom *pSAgsSiscom)
{
   SiscomContenidoSubRegistrosLog(pSAgsSiscom->LCSiscomPro2SREntrada);
   SiscomLog("El Id Para el movimiento:%s %s",
   	     SiscomObtenCampoArgumento("Operacion",
	     			       "IdMovimiento",
				       pSAgsSiscom),
	     SiscomObtenCampoArgumento("Operacion",
	     			       "Fecha",
				       pSAgsSiscom));
    SiscomImprimeArgumento("SqlSeguimiento",
    			   pSAgsSiscom);
}
void GeneraIdOperacion(SArgsSiscom *pSAgsSiscom)
{
char lchrArrIdMovimiento[26];
char lchrArrFechaHoy[26];
  SiscomObtenNumeroUnicoChar(lchrArrIdMovimiento);
  SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
  SiscomAnexaRegistroArgumento("Operacion",
  				pSAgsSiscom,
				"IdMovimiento,Fecha",
				lchrArrIdMovimiento,
				lchrArrFechaHoy);
}

void ArgumentosTomaPromociones(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlSeguimiento",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"Operacion",pSAgsSiscom);
}
