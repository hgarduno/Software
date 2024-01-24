#ifndef __ROTACIONES_H__
#define __ROTACIONES_H__
#include <SiscomDesarrollo2.h>
/*
 * Artistica Femenil
 *
 * Barras 
 * Viga
 * Piso
 * Salto caballo
 * 
 * Piso			-> Salto Caballo
 * Salto caballo	-> Barras 
 * Barras		-> Viga
 * Viga			-> Pisa
 *
 *
 */
/*
 * El Roll de paso Olimpico
 */
/*
 * Piso				-> Caballo con arzones
 * Caballo con arzones		-> Anillos
 * Anillos			-> 
 * Salto de caballo
 * Barras paralelas
 * Barra fija
 *
 *
 */
typedef struct Rotacion
{
 const char *chrPtrAparato;
 const char *chrPtrRota;
 int intIdAparatoRota;
 int intNAparatos;
}StcRotacion;

extern StcRotacion gSRotacion[10][10];
 SiscomOperaciones2 *OperacionesRotacion();
 SiscomOperaciones2 *ORondasCompetencia();
 void EjecutaRotacion(SArgsSiscom *);
 void ArgumentosRotaciones(SArgsSiscom *);
 void EnviaEjecutaRotacion(SArgsSiscom *);
void AparatoAlQuePasa(LCamposSiscomPro2 *pLCSiscomPro2GimsRonda,
		      const char *pchrPtrIdCompetencia,
		      char *pchrPtrIdAparatoPasa);
#endif
