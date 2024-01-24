#include <Cursos.h>
#include <RegistraCursos.h>
#include <ComunElectronica2.h>
#include <SqlCursos.h>
#include <string.h>
#include <stdlib.h>
SiscomOperaciones2 *OpRegistraCostosCurso()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(160,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosRegistraCostosCursos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlRegistraCostosCursos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(RegistraCostosCurso,lSOpOperaciones2);
return lSOpOperaciones2;
}

SiscomOperaciones2 *OpConsultaCursosProgramados()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(160,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosRegistraHorarioCursos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlProgramacionCurso,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlCursosEnEsaFecha,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(GeneraHorariosDiasSemana,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(CursosProgramadosFechaRegistro,lSOpOperaciones2);
return lSOpOperaciones2;
}

SiscomOperaciones2 *OpProgramandoCurso()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(160,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosProgramandoCursos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlProgramandoCurso,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlRegistraFechasCursos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ProgramandoCurso,lSOpOperaciones2);
return lSOpOperaciones2;
}
SiscomOperaciones2 *OpRegistraHorarioCurso()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(160,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosHorariosCursos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlRegistraHorariosCursos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(RegistraHorarioCurso,lSOpOperaciones2);
return lSOpOperaciones2;
}


SiscomOperaciones2 *OpCursosProgramadosFechaRegistro()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(160,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosRegistraHorarioCursos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlProgramacionCurso,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlCursosEnEsaFecha,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(GeneraHorariosDiasSemana,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(CursosProgramadosFechaRegistro,lSOpOperaciones2);
return lSOpOperaciones2;
}
SiscomOperaciones2 *OpRegistraProgramacionCursos()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(155,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosRegistraProgramacionCursos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(AsignaIdRegistroProgramacionCurso,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlRegistraProgramacionCursos,lSOpOperaciones2); 
SiscomAnexaOperacionAlArreglo2(RegistraProgramacionCursos,lSOpOperaciones2);
return lSOpOperaciones2;
}

SiscomOperaciones2 *OpCursos()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(155,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlCursos,lSOpOperaciones2);
return lSOpOperaciones2;
}






SiscomOperaciones2 *OpDisponibilidadCursos()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(155,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlDisponibilidadCursos,lSOpOperaciones2);
return lSOpOperaciones2;
}
SiscomOperaciones2 *OpFechasCursos()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(155,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlFechasCursos,lSOpOperaciones2);
return lSOpOperaciones2;
}

SiscomOperaciones2 *OpFechasCostosCursos()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(200,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosFechasCursos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlFechasCursos2,lSOpOperaciones2);
/*SiscomAnexaOperacionAlArreglo2(SqlCostosCursos,lSOpOperaciones2); */
SiscomAnexaOperacionAlArreglo2(EnviaFechasCursos,lSOpOperaciones2);
return lSOpOperaciones2;
}

SiscomOperaciones2 *OpCostosCurso()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(200,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosFechasCursos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlCostosCursos,lSOpOperaciones2); 
SiscomAnexaOperacionAlArreglo2(EnviaCostosCurso,lSOpOperaciones2);
return lSOpOperaciones2;
}

SiscomOperaciones2 *OpVentasCursos()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(200,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosVentasCursos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlVentasCursos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(FormaVentasCursos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(CalculaImporteCurso,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(TotalCursosYParticipacionSiscom,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(EnviaVentasCursos,lSOpOperaciones2);
return lSOpOperaciones2;
}


SiscomOperaciones2 *OpCursosProgramados()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(155,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlCursosProgramados,lSOpOperaciones2);
return lSOpOperaciones2;
}

SiscomOperaciones2 *OpExplicacionPromocion()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(155,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlExplicacionPromocion,lSOpOperaciones2);
return lSOpOperaciones2;
}


LCamposSiscomPro2 *HayCursoAEsaHora(const char *pchrPtrFecha,
				    const char *pchrPtrHora,
				    LCamposSiscomPro2 *pLCSiscomPro2Cursos)
{
const char *lchrPtrCursoDep;
for(; pLCSiscomPro2Cursos;pLCSiscomPro2Cursos=pLCSiscomPro2Cursos->SCP2PtrSig)
{
   if(!SiscomComparaCampoChar("fecha",pchrPtrFecha,pLCSiscomPro2Cursos) &&
      !SiscomComparaCampoChar("horainicio",pchrPtrHora,pLCSiscomPro2Cursos))
    return pLCSiscomPro2Cursos;
}
return 0;
}
float LlenaHorarioCurso(LCamposSiscomPro2 *pLCSiscomPro2Curso,
		       SArgsSiscom *pSAgsSiscom)
{
const char *lchrPtrHoraInicio,*lchrPtrHoraFin,*lchrPtrIdCurso;
char lchrArrHoraActual[12],lchrArrHoraIncrementada[12];
lchrPtrHoraInicio=SiscomObtenDato(pLCSiscomPro2Curso,"horainicio");
lchrPtrHoraFin=SiscomObtenDato(pLCSiscomPro2Curso,"horafin");
strcpy(lchrArrHoraActual,lchrPtrHoraInicio);
while(strcmp(lchrArrHoraActual,lchrPtrHoraFin))
{
SiscomIncrementaHora(lchrArrHoraActual,lchrArrHoraIncrementada,30);
lchrPtrIdCurso=SiscomObtenDato(pLCSiscomPro2Curso,"idcurso");
SiscomAnexaRegistroRegreso(pSAgsSiscom,
			   "HoraInicio,HoraFin,Curso,IdCurso,IdEstatus,IdProgramacion",
			   	lchrArrHoraActual,
				SiscomObtenDato(pLCSiscomPro2Curso,"horafin"),
				SiscomObtenDato(pLCSiscomPro2Curso,"curso"),
				lchrPtrIdCurso,
				"1",
				ObtenIdProgramacionCurso(pSAgsSiscom,lchrPtrIdCurso));
}
return SiscomHoraAFloat(lchrPtrHoraFin);
}
void AgregaCursoPropuesto(SArgsSiscom *pSAgsSiscom,
			  char *pchrPtrHora)
{
const char *lchrPtrHoraInicio=SiscomCampoDatosEntrada("HoraInicio",pSAgsSiscom),
	   *lchrPtrHoraFin=SiscomCampoDatosEntrada("HoraFin",pSAgsSiscom);
if(SiscomVerificaHoraRango(pchrPtrHora,lchrPtrHoraInicio,lchrPtrHoraFin))
{
SiscomAnexaRegistroRegreso(pSAgsSiscom,
     			   "HoraInicio,HoraFin,Curso,IdCurso,IdEstatus,IdProgramacion",
			    pchrPtrHora,
			    lchrPtrHoraFin,
			    SiscomCampoDatosEntrada("Curso",pSAgsSiscom),
			    SiscomCampoDatosEntrada("IdCurso",pSAgsSiscom),
			    "0",
			    SiscomCampoDatosEntrada("IdProgramacion",pSAgsSiscom));
}
else
SiscomAnexaRegistroRegreso(pSAgsSiscom,
     			   "HoraInicio,HoraFin,Curso,IdCurso,IdEstatus,IdProgramacion",
			   pchrPtrHora,"","","","","");

}
void CursosPorDiaPorHora(const char *pchrPtrFecha,
			  SArgsSiscom *pSAgsSiscom)
{
float lfltHora;
char lchrArrHora[10];
LCamposSiscomPro2 *lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("SqlCursosEnEsaFecha",pSAgsSiscom),
                  *lLCSiscomPro2DatCurso;
const char *lchrPtrIdCurso;
for(lfltHora=8.0;lfltHora<22.0;)
{
SiscomHoraFloatAChar(lfltHora,lchrArrHora);
if((lLCSiscomPro2DatCurso=HayCursoAEsaHora(pchrPtrFecha,lchrArrHora,lLCSiscomPro2Dat)))
{
    lchrPtrIdCurso=SiscomObtenDato(lLCSiscomPro2DatCurso,"idcurso");
     SiscomAnexaRegistroRegreso(pSAgsSiscom,
     				"HoraInicio,HoraFin,Curso,IdCurso,IdEstatus,IdProgramacion",
				SiscomObtenDato(lLCSiscomPro2DatCurso,"horainicio"),
				SiscomObtenDato(lLCSiscomPro2DatCurso,"horafin"),
				SiscomObtenDato(lLCSiscomPro2DatCurso,"curso"),
				lchrPtrIdCurso,
				"1",	
				ObtenIdProgramacionCurso(pSAgsSiscom,lchrPtrIdCurso));
     lfltHora=LlenaHorarioCurso(lLCSiscomPro2DatCurso,pSAgsSiscom);
}
else
{
    AgregaCursoPropuesto(pSAgsSiscom,lchrArrHora);
    lfltHora+=0.5;
}

}
}

void GeneraHorariosDiasSemana(SArgsSiscom *pSArgsSiscom)
{
const char *lchrPtrFechaInicio=SiscomCampoDatosEntrada("FechaInicio",pSArgsSiscom);
char lchrArrFechaSigDia[25],
     lchrArrFechaActual[25];
char *lchrPtrDias[]={"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"};
   
int lintDia;
strcpy(lchrArrFechaActual,lchrPtrFechaInicio);
for(lintDia=0;lintDia<7;lintDia++)
{
   SiscomAnexaRegistroRegreso(pSArgsSiscom,
   			     "Dia,Fecha,HoraInicio,HoraFin,IdCurso,IdProgramacion",
			     lchrPtrDias[lintDia],
			     lchrArrFechaActual,
			     SiscomCampoDatosEntrada("HoraInicio",pSArgsSiscom),
			     SiscomCampoDatosEntrada("HoraFin",pSArgsSiscom),
			     SiscomCampoDatosEntrada("IdCurso",pSArgsSiscom),
			     SiscomCampoDatosEntrada("IdProgramacion",pSArgsSiscom));
   CursosPorDiaPorHora(lchrArrFechaActual,pSArgsSiscom);
   SiscomSiguienteDia(lchrArrFechaActual,lchrArrFechaSigDia);
}
}

void CursosProgramadosFechaRegistro(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaRegreso2(pSAgsSiscom,"Regresando");
}

void RegistraProgramacionCursos(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta;
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomImprimeArgumento("SqlProgramacionCursos",pSAgsSiscom); 

SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SqlProgramacionCursos",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);
}
void AsignaIdRegistroProgramacionCurso(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraIdRegistro(pSAgsSiscom,"IdProgramacion");
}
LCamposSiscomPro2 *SumaImporteTotalPorCurso(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{

const char *lchrPtrIdCurso=SiscomObtenDato(pLCSiscomPro2Dat,"idcurso");
float lfltTotal=0.0;
LCamposSiscomPro2 *lLCSiscomPro2Ant=0;
while(pLCSiscomPro2Dat &&
      !strcmp(lchrPtrIdCurso,SiscomObtenDato(pLCSiscomPro2Dat,"idcurso")))
{
lLCSiscomPro2Ant=pLCSiscomPro2Dat;
lfltTotal+=(SiscomObtenDatoFloat(pLCSiscomPro2Dat,"costo")*
	   SiscomObtenDatoFloat(pLCSiscomPro2Dat,"cantidad"));
pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig;
}
AgregaNodoTotalCurso("0",
		     lfltTotal,
		     lLCSiscomPro2Ant,
		     pLCSiscomPro2Dat);
return lLCSiscomPro2Ant;
}
void FormaCamposRegistroTotalCurso(SCampoSiscomPro2 *pSCSiscomPro2Dat)
{

char **lchrPtrCampos;
int lintContador;
lchrPtrCampos=(char **)malloc(sizeof(char *)*3);
*(lchrPtrCampos+0)=strdup("IdCurso");
*(lchrPtrCampos+1)=strdup("ImporteTotal");
*(lchrPtrCampos+2)=0;
SiscomAsignaDatosCampoAlCampo(lchrPtrCampos,pSCSiscomPro2Dat);
}
void AgregaNodoTotalCurso(const char *pchrPtrIdCurso,
			     float pfltTotalCurso,
			     LCamposSiscomPro2 *pLCSiscomPro2Anterior,
			     LCamposSiscomPro2 *pLCSiscomPro2Siguiente)
{
char lchrArrTotal[28];
SCampoSiscomPro2 *lSCSiscomPro2Dat; 
LCamposSiscomPro2 *lLCSiscomPro2NodoTotalC=0;
lSCSiscomPro2Dat=(SCampoSiscomPro2 *)malloc(sizeof(SCampoSiscomPro2)*3);
sprintf(lchrArrTotal,"%.2f",pfltTotalCurso);
FormaCamposRegistroTotalCurso(lSCSiscomPro2Dat);
SiscomAsignaDatoCampo2A("IdCurso","0",lSCSiscomPro2Dat);
SiscomAsignaDatoCampo2A("ImporteTotal",lchrArrTotal,lSCSiscomPro2Dat);
SiscomCreaNodoLCamposPro2(lSCSiscomPro2Dat,&lLCSiscomPro2NodoTotalC);
pLCSiscomPro2Anterior->SCP2PtrSig=lLCSiscomPro2NodoTotalC;
lLCSiscomPro2NodoTotalC->SCP2PtrSig=pLCSiscomPro2Siguiente;
}
void FormaVentasCursos(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
LCamposSiscomPro2 *lLCSiscomPro2PrimReg=0,
		  *lLCSiscompRo2ActReg=0;
int lintNRegArgumento=SiscomArgumentosNumeroRegistros("SqlVentasCursos",pSAgsSiscom);
SiscomImprimeArgumento("SqlVentasCursos",pSAgsSiscom);
for(lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("SqlVentasCursos",pSAgsSiscom);
    lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
{
  if(SiscomEstaElCampo(lLCSiscomPro2Dat,"costo"))
  {
  lLCSiscomPro2Dat=SumaImporteTotalPorCurso(lLCSiscomPro2Dat);
  lintNRegArgumento++;
  }
}
SiscomAsignaArgumentoNumeroRegistros("SqlVentasCursos",lintNRegArgumento,pSAgsSiscom);
}
void ArgumentosVentasCursos(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlVentasCursos",pSAgsSiscom);
}
void ObtenImporteCurso(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
float lfltImporteCurso;
lfltImporteCurso=SiscomObtenDatoFloat(pLCSiscomPro2Dat,"cantidad")*
		 SiscomObtenDatoFloat(pLCSiscomPro2Dat,"costo");
SiscomAsignaDatoCampoFloat2(pLCSiscomPro2Dat,"importe",lfltImporteCurso);
}
float SumaTotalesCursos(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			LCamposSiscomPro2 **pLCSiscomPro2DatAct)
{
float lfltImporteCursos=0.0;
for(;
    pLCSiscomPro2Dat;
    pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
 *pLCSiscomPro2DatAct=pLCSiscomPro2Dat;
if(SiscomEstaElCampo(pLCSiscomPro2Dat,"importe"))
lfltImporteCursos+=SiscomObtenDatoFloat(pLCSiscomPro2Dat,"importe");

}
return lfltImporteCursos;
}
void TotalCursosYParticipacionSiscom(SArgsSiscom *pSAgsSiscom)
{
float lfltImporteCursos,
      lfltParticipacionSiscom;
char lchrArrImporteCursos[28],
	lchrArrParticipacionSiscom[28];
LCamposSiscomPro2 *lLCSiscomPro2VentasAct;
LCamposSiscomPro2 *lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("SqlVentasCursos",pSAgsSiscom);

lfltImporteCursos=SumaTotalesCursos(lLCSiscomPro2Dat,&lLCSiscomPro2VentasAct);
lfltParticipacionSiscom=0.20*lfltImporteCursos;
sprintf(lchrArrImporteCursos,"%.2f",lfltImporteCursos);
sprintf(lchrArrParticipacionSiscom,"%.2f",lfltParticipacionSiscom);
SiscomAsignaArgumentoOperacionAct("SqlVentasCursos",lLCSiscomPro2VentasAct,pSAgsSiscom);
SiscomAnexaRegistroArgumento("SqlVentasCursos",
			     pSAgsSiscom,
			     "TotalCursos,		\
			      ParticipacionSiscom",
			     lchrArrImporteCursos,
			     lchrArrParticipacionSiscom);
}
void CalculaImporteCurso(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
for(lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("SqlVentasCursos",pSAgsSiscom);
    lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
if(SiscomEstaElCampo(lLCSiscomPro2Dat,"costo"))
     ObtenImporteCurso(lLCSiscomPro2Dat);
}
void EnviaVentasCursos(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaArgumentoCliente("SqlVentasCursos",pSAgsSiscom);
}
void EnviaFechasCursos(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaArgumentosCliente(pSAgsSiscom);
}

void EnviaCostosCurso(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaArgumentosCliente(pSAgsSiscom);
}


SiscomOperaciones2 *OpAlumnosInscritosCurso()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(155,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlAlumnosInscritosCurso,lSOpOperaciones2);
return lSOpOperaciones2;
}


void ArgumentosFechasCursos(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlFechasCurso",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlCostosCurso",pSAgsSiscom);
}
void ArgumentosRegistraProgramacionCursos(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlProgramacionCursos",pSAgsSiscom);
}

void ArgumentosRegistraHorarioCursos(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlCursosEnEsaFecha",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlProgramacionCurso",pSAgsSiscom);
}

void ArgumentosRegistraCostosCursos(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlCostosCursos",pSAgsSiscom);
}
const char *ObtenIdProgramacionCurso(SArgsSiscom *pSAgsSiscom,const char *pchrPtrIdCurso)
{
SiscomPonPrimerRegistroArgumento("SqlProgramacionCurso",pSAgsSiscom);
LCamposSiscomPro2 *lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("SqlProgramacionCurso",pSAgsSiscom);
while(lLCSiscomPro2Dat)
{
if(!SiscomComparaCampoChar("idcurso",pchrPtrIdCurso,lLCSiscomPro2Dat))
return SiscomObtenDato(lLCSiscomPro2Dat,"idprogramacion");
lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;
}
return "";
}

void RegistraCostosCurso(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta;



SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SqlCostosCursos",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);

SiscomLog("_---_");
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomImprimeArgumento("SqlCostosCursos",pSAgsSiscom);
SiscomLog("-____-");
}
