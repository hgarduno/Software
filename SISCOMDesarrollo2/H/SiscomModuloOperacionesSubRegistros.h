#ifndef __SISCOMMODULOOPERACIONESSUBREGISTROS_H__
#define __SISCOMMODULOOPERACIONESSUBREGISTROS_H__
#include <SiscomModuloOperaciones.h>
#include <SiscomProtocolo2SubRegistros.h>

void SiscomInsercionActualizacionSubRegistros(int pintNSubRegistro,
					      SArgsSiscom *pSAgsSiscom,
					      const char *pchrPtrArgSalida,
					      char *pchrPtrBufferSql,
					      void (*SiscomSql)(LCamposSiscomPro2 *,
					      		        SArgsSiscom *,
								char *));
					      			

void SiscomInsercionActualizacionRegistroPrincipal(
		SArgsSiscom *pSAgsSiscom,
		const char *pchrPtrArgSalida,
		char *pchrPtrBufferSql,
		void (*SiscomSql)(LCamposSiscomPro2ConSubReg *,
				 SArgsSiscom *,
				char *));
void SiscomInsercionActualizacionEntradaSubRegistroAArgumento2(
		SArgsSiscom *pSAgsSiscom,
		const char *pchrPtrArgSalida,
		char *pchrPtrBufferSql,
		int pintNSubRegistro,
		void (*SiscomSql)(LCamposSiscomPro2 *,
				  char *pchrPtrSql));

void SiscomInsercionActualizacionEntradaSubRegistroAArgumento(
		SArgsSiscom *pSAgsSiscom,
		const char *pchrPtrArgSal,
		void (*SiscomOperacionSql)(
				const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				SArgsSiscom *,
				LCamposSiscomPro2 **,
				LCamposSiscomPro2 **,
				int *));
void SiscomInsercionActualizacionSql2(SArgsSiscom *pSAgsSiscom,
				      int pintNSubRegistro,
				      void (*SiscomSql)(SArgsSiscom *,LCamposSiscomPro2 *));

void SiscomInsercionActualizacionSql(SArgsSiscom *pSAgsSiscom,
				     const char *pchrPtrArgSal,
				     int pintNSubRegistro,
				     void (*SiscomSql)(LCamposSiscomPro2 *,
				     		       LCamposSiscomPro2 **,
						       LCamposSiscomPro2 **,
						       int *));

void SiscomOperacionGeneralSql2(int pintNSubRegistro,
				void (*SiscomOperacionSql)(SArgsSiscom *,LCamposSiscomPro2 *),
				SArgsSiscom *pSAgsSiscom);
void SiscomOperacionGeneralSql(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					 void (*SiscomOperacion)(LCamposSiscomPro2 *,
					 			 LCamposSiscomPro2 **,
								 LCamposSiscomPro2 **,
								 int *),
					 LCamposSiscomPro2 **pLCSiscomPro2Prim,
					 LCamposSiscomPro2 **pLCSiscomPro2Act,
					 int *pintPtrNRegistros);


/* Miercoles 7 de Noviembre 2012
 * Esta funcion, esta mal ...... 
 *
 */
const char *SiscomCampoSubRegistroArgs(int pintNSubRegistro,
				       const char *pchrPtrCampo,
				       SArgsSiscom *pSAgsSiscom);


const char *SiscomCampoSubRegistroPrincipalArgs(const char *pchrPtrCampo,SArgsSiscom *);
float SiscomCampoSubRegistroPrincipalArgsFloat(const char *pchrPtrCampo,SArgsSiscom *);
int SiscomCampoSubRegistroPrincipalArgsInt(const char *pchrPtrCampo,SArgsSiscom *);

void SiscomAsignaCampoRegistroPrincipalArgs(SArgsSiscom *pSAgsSiscom,
					    const char *pchrPtrCampo,
					    const char *pchrPtrDato);


void SiscomInsercionActualizacionRegPrincipal(
		SArgsSiscom *pSAgsSiscom,
		const char *pchrPtrArgumentoSal,
		char *pchrPtrBufferSql,
		void (*SiscomSql)(LCamposSiscomPro2ConSubReg *,char *));
#endif
