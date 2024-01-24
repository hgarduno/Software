#include <SiscomTrampolin.h>
#include <ServidorGeneral.h>
#include <RNSiscomSeguridad3Prot2.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void Principal(int pintSocket) 
	       
{
SSiscomOperaciones *lSSiscomOp=0;
int lintContador;
char *lchrPtrOperacion=0;
int lintNRegistros;
SSiscomOperaciones2 *lSOpPtrOperaciones=0;
SiscomOperaciones2 *lSOpPtrSistema;
SArgsSiscom lSArgsSiscomDat;
	memset(&lSArgsSiscomDat,0,sizeof(SArgsSiscom));
	OperacionesSistemaGeneral(&lSSiscomOp);
	SiscomLeeNumeroRegistros(pintSocket,
				 &lintNRegistros);	
	SiscomLeeOperacion(pintSocket,
                           &lchrPtrOperacion);
	for(lintContador=0;
            lintContador<lSSiscomOp->intNumOperaciones;
            lintContador++)
        if(!strcmp((lSSiscomOp+lintContador)->chrPtrOperacion,
                   lchrPtrOperacion))
        {
             (lSSiscomOp+lintContador)->Operacion(pintSocket,lintNRegistros);
             return ;
        }
	SiscomLog("Se busca la operacion %s, en el nuevo sistema",lchrPtrOperacion);
	AsignaOperacionesVersion2(pintSocket,
				  lintNRegistros,
				  &lSOpPtrOperaciones,
				  &lSArgsSiscomDat);
	lSOpPtrSistema=SiscomOperaciones2CualEjecuta(
				lchrPtrOperacion,
				lSOpPtrOperaciones,
				SiscomErrorOperacion2,
				&lSArgsSiscomDat);
	SiscomLog("Ejecutando La Operacion");
	SiscomOperaciones2Ejecuta(lSOpPtrSistema,
				  &lSArgsSiscomDat);
}

void OperacionesSistemaGeneral(SSiscomOperaciones **pSSiscomOp)
{
	SiscomIniciaOperaciones(3,pSSiscomOp);
	SiscomAnexaOperacion("ConsultaSepomex",
			      ConsultaSepomex,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaSeguridad3Pro2",
			      ConsultaSeguridad3Pro2,
			      pSSiscomOp);
	SiscomAnexaOperacionesAlFinal(gSSiscomOpSistema,pSSiscomOp);
}
void AsignaOperacionesVersion2(int pintSocket,
			       int pintNRegistros,
			       SSiscomOperaciones2 **pSSOperaciones2,
			       SArgsSiscom *pSArgsSiscom)
{
pSArgsSiscom->intSocketCliente=pintSocket;
pSArgsSiscom->intNRegistrosDat=pintNRegistros;
SiscomLog(".......");
SiscomAnexaOperacion2("RegistraGimnasio",
			GeneraOperacionesGimnasio(),
			pSSOperaciones2);
SiscomAnexaOperacion2("ConsultaGimnasio", 
		       GeneraConsultasGimnasio(), 
		       pSSOperaciones2);
SiscomAnexaOperacion2("RegistraEntrenador",
			GeneraOperacionesEntrenador(),
			pSSOperaciones2);
SiscomAnexaOperacion2("RegistraGimnasta",
			GeneraOperacionesGimnasta(),
			pSSOperaciones2);
SiscomAnexaOperacion2("RegistraCompetencia",
		      OperacionesCompetencia(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraCompetidor",
		       OperacionesCompitiendo(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RegistraJuez",
		      OperacionesJuez(),
		      pSSOperaciones2);

SiscomAnexaOperacion2("IniciaCalificacion",
		      OperacionesIniciaCalificacion(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("ActualizaEjecucion",
		      OperacionesActualizaEjecucion(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("ActualizaDificultad",
		      OperacionesActualizaDificultad(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("ActDatCompGimnasta",
		      OperacionesActDatCompGimnasta(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("ActualizaGimnasta",
		      OperacionesActualizaGimnasta(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("AnexaMedio",
		      AnexaComunicacionGimnasta(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraRondas",
		      RegistraRondas(),
		      pSSOperaciones2);
}
void SiscomErrorOperacion2(SArgsSiscom *pSAgsSisPtr)
{
SiscomMensajesLog(gPtrFleArchivoLog,"Operacion No Soportada");
}

