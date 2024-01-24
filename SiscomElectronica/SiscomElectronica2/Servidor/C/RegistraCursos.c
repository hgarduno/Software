#include <RegistraCursos.h>
#include <string.h>
void RegistraHorarioCurso(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta;
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SqlHorariosCursos",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);

SiscomImprimeArgumento("SqlHorariosCursos",pSAgsSiscom);
}

void ProgramandoCurso(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta;

SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SqlProgramandoCurso",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);

SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomImprimeArgumento("SqlProgramandoCurso",pSAgsSiscom);

}

void ArgumentosProgramandoCursos(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlProgramandoCurso",pSAgsSiscom);
}
void ArgumentosHorariosCursos(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlHorariosCursos",pSAgsSiscom);
}
int EsElFinalDiaHora(const char *pchrPtrHoraFin,
		     const char *pchrPtrHoraAnalizada)
{
const char *lchrPtrRegreso;
lchrPtrRegreso=strstr(pchrPtrHoraAnalizada,pchrPtrHoraFin);
return lchrPtrRegreso ? 1 : 0;

}
LCamposSiscomPro2 *ObtenHorarioInicioFinalAEliminar(LCamposSiscomPro2 *pLCSiscomPro2Dat,
						    char **pchrPtrHoraIniEliminar,
						    char **pchrPtrHoraFinEliminar)
{
LCamposSiscomPro2 *lLCSiscomPro2HorarioInicio=pLCSiscomPro2Dat;
LCamposSiscomPro2 *lLCSiscomPro2HorarioAntes;
SiscomLog("Horario Inicio:%s",SiscomObtenDato(lLCSiscomPro2HorarioInicio,"HoraInicio"));
*pchrPtrHoraIniEliminar=(char *)SiscomObtenDato(lLCSiscomPro2HorarioInicio,"HoraInicio");
    while(pLCSiscomPro2Dat &&
          !SiscomComparaCampoChar("IdEstatus","2",pLCSiscomPro2Dat))
    {	
        lLCSiscomPro2HorarioAntes=pLCSiscomPro2Dat;
	pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig;	
    }

SiscomLog("Horario Inicio(%s)",SiscomObtenDato(lLCSiscomPro2HorarioAntes,"HoraInicio"));
*pchrPtrHoraFinEliminar=(char *)SiscomObtenDato(lLCSiscomPro2HorarioAntes,"HoraInicio");
return pLCSiscomPro2Dat;
}
LCamposSiscomPro2 *VerificaHorariosEliminados(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					      char **pchrPtrHoraIniEliminar,
					      char **pchrPtrHoraFinEliminar)
{
LCamposSiscomPro2 *lLCSiscomPro2HorarioCurso=pLCSiscomPro2Dat;
SiscomLog("Dia(%s) IdCurso(%s) Fecha(%s) HoraInicio(%s) HoraFin(%s)",
	SiscomObtenDato(lLCSiscomPro2HorarioCurso,"Dia"),
	SiscomObtenDato(lLCSiscomPro2HorarioCurso,"IdCurso"),
	SiscomObtenDato(lLCSiscomPro2HorarioCurso,"Fecha"),
	SiscomObtenDato(lLCSiscomPro2HorarioCurso,"HoraInicio"),
	SiscomObtenDato(lLCSiscomPro2HorarioCurso,"HoraFin"));
 
   pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig;
   *pchrPtrHoraIniEliminar=0;
   *pchrPtrHoraFinEliminar=0;
   while(pLCSiscomPro2Dat &&
         !EsElFinalDiaHora("21:30:00",
	 		  SiscomObtenDato(pLCSiscomPro2Dat,"HoraInicio")))
   {
   	/*
	SiscomLog("HoraInicio(%s) IdEstatus(%s)",
		  SiscomObtenDato(pLCSiscomPro2Dat,"HoraInicio"),
		  SiscomObtenDato(pLCSiscomPro2Dat,"IdEstatus"));
	*/
	if(!SiscomComparaCampoChar("IdEstatus","2",pLCSiscomPro2Dat))
	 pLCSiscomPro2Dat=ObtenHorarioInicioFinalAEliminar(pLCSiscomPro2Dat,
	 						   pchrPtrHoraIniEliminar,
							   pchrPtrHoraFinEliminar);
   	pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig;

   }
return pLCSiscomPro2Dat;
}

int AjustaHorariosCurso(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 const char *pchrPtrHoraIniEliminar,
			 const char *pchrPtrHoraFinEliminar)
{
   if(!SiscomComparaNCaracteresCampoChar("HoraInicio",
   					pchrPtrHoraIniEliminar,
					5,
					pLCSiscomPro2Dat) &&
      !SiscomComparaNCaracteresCampoChar("HoraFin",
      					pchrPtrHoraFinEliminar,
					5,
					pLCSiscomPro2Dat))
      return 0;
    else
    return 1;
}
