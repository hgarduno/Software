#include <Rotaciones.h>
#include <SqlRotaciones.h>
StcRotacion gSRotacion[10][10]=
		{ { 
		    {0,0,0,0}
		  },
		   { 
		   	  {"Piso","Caballo con arzones",6,6},
			  {"Caballo con arzones","Anillos",5,6},
			  {"Anillos","Salto De Caballo",2,6},
			  {"Salto De Caballo","Barras Paralelas",8,6},
			  {"Barras Paralelas","Barra Fija",7,6},
			  {"Barra Fija","Piso",1,6}

		   },
		  {
			   {"Piso","Salto De Caballo",2,4},
			   {"Salto De Caballo","Barras Asimetricas",3,4},
			   {"Barras Asimetricas","Viga De Equilibrio",4,4},
			   {"Viga De Equilibrio","Piso",1,4} 
		   }
		  };
				 
SiscomOperaciones2 *OperacionesRotacion()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosRotaciones,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlAparatosCompetencia,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlGimnastasAparatoRonda,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EjecutaRotacion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EnviaEjecutaRotacion,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *ORondasCompetencia(SArgsSiscom *pSAgsSiscom)
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(100,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRondasCompetencia,lSOpOperaciones);
return lSOpOperaciones;
}
void ArgumentosRotaciones(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlApCompetencia",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlGimnastaRonda",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"SqlEjecutaRotacion",pSAgsSiscom);

}
void EjecutaRotacion(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2AparatosPrim=0,
                  *lLCSiscomPro2AparatosAct=0;
LCamposSiscomPro2 *lLCSiscomPro2GimnastasPrim=0,
		  *lLCSiscomPro2GimnastasAct=0;
LCamposSiscomPro2 *lLCSiscomPro2Contador;
LCamposSiscomPro2 *lLCSiscomPro2RotacionPrim=0,
                  *lLCSiscomPro2RotacionAct=0;
int lintNAparatos;
int lintNGimnastas;
int lintNRotacion=0;
char lchrArrIdAparatoPasa[10];

SiscomObtenInformacionArgumento("SqlApCompetencia",
				pSAgsSiscom,
				&lLCSiscomPro2AparatosPrim,
				&lLCSiscomPro2AparatosAct,
				&lintNAparatos);
SiscomObtenInformacionArgumento("SqlGimnastaRonda",
				pSAgsSiscom,
				&lLCSiscomPro2GimnastasPrim,
				&lLCSiscomPro2GimnastasAct,
				&lintNGimnastas);
SiscomContenidoProtocolo(lLCSiscomPro2AparatosPrim);
SiscomContenidoProtocolo(lLCSiscomPro2GimnastasPrim);
for(lLCSiscomPro2Contador=lLCSiscomPro2GimnastasPrim;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
 AparatoAlQuePasa(lLCSiscomPro2Contador,
 		  SiscomObtenDato(lLCSiscomPro2AparatosPrim,"idtipocompetencia"),
		  lchrArrIdAparatoPasa);
 SqlEjecutaRotacion(lchrArrIdAparatoPasa,
 		    lLCSiscomPro2Contador,
		    &lLCSiscomPro2RotacionPrim,
		    &lLCSiscomPro2RotacionAct,
		    &lintNRotacion);


}
SiscomContenidoProtocolo(lLCSiscomPro2RotacionPrim);
SiscomAsignaInformacionArgumento("SqlEjecutaRotacion",	
				 pSAgsSiscom,
				 lLCSiscomPro2RotacionPrim,
				 lLCSiscomPro2RotacionAct,
				 lintNRotacion);
}

void AparatoAlQuePasa(LCamposSiscomPro2 *pLCSiscomPro2GimsRonda,
		      const char *pchrPtrIdCompetencia,
		      char *pchrPtrIdAparatoPasa)
{
const char *lchrPtrAparato=SiscomObtenDato(pLCSiscomPro2GimsRonda,"aparato");
StcRotacion *lSRotacion=gSRotacion[atoi(pchrPtrIdCompetencia)];
int lintContador;
for(lintContador=0;
    lintContador<lSRotacion->intNAparatos;
    lintContador++)
{
  if(!strcmp((lSRotacion+lintContador)->chrPtrAparato,
  	     lchrPtrAparato))
  {
    SiscomLog("Aparato Actual:%s y Pasa a :%s",
    	      lchrPtrAparato,
    	      (lSRotacion+lintContador)->chrPtrRota);
    sprintf(pchrPtrIdAparatoPasa,
    	    "%d",
	    (lSRotacion+lintContador)->intIdAparatoRota);
     return ;
  }

}
}
void EnviaEjecutaRotacion(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegReg=0;
SiscomEjecutaRegistroInformacion(
		pSAgsSiscom,
		"SqlEjecutaRotacion",
		&lLCSiscomPro2Reg,
		&lintNRegReg);
}
