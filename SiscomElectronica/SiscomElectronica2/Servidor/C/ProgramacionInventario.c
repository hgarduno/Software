#include <ProgramacionInventario.h>
#include <SqlProgramacionInventario.h>
#include <ComunElectronica2.h>

#include <stdlib.h>
SiscomOperaciones2 *OpRegistraProgramacionInventario()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendio3,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosProgramacion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraProgramacionInventario,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ProgramacionInventario,lSOpOperaciones);
return lSOpOperaciones;
}


void ProgramacionInventario(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRespuesta=0;

SiscomContenidoSubRegistrosLog(pSAgsSiscom->LCSiscomPro2SREntrada);
SiscomLog("El Resultado");
SiscomImprimeArgumento("SqlProgramaInventario",pSAgsSiscom);
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SqlProgramaInventario",
				 &lLCSiscomPro2Reg,
				 &lintNRegRespuesta);
SiscomContenidoProtocolo(lLCSiscomPro2Reg);
}


SiscomOperaciones2 *OpInventariosProgramados()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlInventariosProgramados,lSOpOperaciones2);
return lSOpOperaciones2;
}



void ArgumentosProgramacion(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlProgramaInventario",pSAgsSiscom);
}
