#ifndef __SISCOMPROTOCOLO2SUBREGISTROS_H__
#define __SISCOMPROTOCOLO2SUBREGISTROS_H__
#include <SiscomProtocolo2.h>
typedef struct LCProtocolo2SubReg
{
SCampoSiscomPro2 *SCSiscomPro2;
LCamposSiscomPro2 *LCSiscomPro2SRPrim[30];
LCamposSiscomPro2 *LCSiscomPro2SRAct[30]; 
int intNSubRegistro;
}CamposSiscomPro2ConSubReg;

typedef struct ListaCamposSiscomPro2ConSubReg
{
  CamposSiscomPro2ConSubReg *CSiscomPro2SReg;
  struct ListaCamposSiscomPro2ConSubReg *LCSiscomPro2SRSig;
}LCamposSiscomPro2ConSubReg;

void SiscomContenidoSubRegistros(const char *pchrPtrArchivo,
				 const char *pchrPtrFuncion,
				 int pintNLinea,
				 LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat);
void SiscomAsignaNodosSubRegistro(int pintNSubRegistro,
				  LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				  LCamposSiscomPro2 *pLCSiscomPro2Prim,
				  LCamposSiscomPro2 *pLCSiscomPro2Act);
int SiscomNSubRegistros(LCamposSiscomPro2ConSubReg *);
int SiscomNumeroCamposRegistroPrincipal(const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat);
int SiscomIncrementaNSubRegistro(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat);
SCampoSiscomPro2 *SiscomCamposRegistroPrincipal(const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat);
LCamposSiscomPro2 *SiscomSubRegistroPrim(int pintNSubRegistro,
				     const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat);
LCamposSiscomPro2 *SiscomSubRegistroAct(int pintNSubRegistro,
				     const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat);
const char *SiscomCampoRegistroPrincipal(
	                  const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
					 const char *pchrPtrNmbCampo);

float SiscomCampoRegistroPrincipalFloat(
	                  const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
					 const char *pchrPtrNmbCampo);
int SiscomCampoRegistroPrincipalInt(
	                  const LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
					 const char *pchrPtrNmbCampo);

const char *SiscomCampoSubRegistro(int pintNSubRegistro,
				   const char *pchrPtrNmbCampo,
				   const LCamposSiscomPro2ConSubReg *);
float SiscomCampoSubRegistroFloat(int pintNSubRegistro,
				   const char *pchrPtrNmbCampo,
				   const LCamposSiscomPro2ConSubReg *);

int SiscomCampoSubRegistroInt(int pintNSubRegistro,
				   const char *pchrPtrNmbCampo,
				   const LCamposSiscomPro2ConSubReg *);
void SiscomAsignaCampoRegistroPrincipal(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
					const char *pchrPtrNmbCampo,
					const char *pchrPtrDato);
void SiscomAsignaCampoSubRegistro(LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				  int pintNSubRegistro,
				  const char *pchrPtrCampo,
				  const char *pchrPtrDato);
void SiscomLeeConSubRegistros(int piSocket,
			      int pintNRegistros,
			      LCamposSiscomPro2 **pLCSiscomPro2RegCon,
			      LCamposSiscomPro2ConSubReg **pLCSiscomPro2ConSubReg);

void SiscomLeeRegistroConfiguracion(int pintSocket,
				    LCamposSiscomPro2 **pLCSiscomPro2RegCon);

void NombreRegistro(SCampoSiscomPro2 *pCSiscomPro2Dat,
		    char *pchrPtrNombre);

void NombreRegistroDeLista(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			   char *pchrPtrNmbRegistro);

int EsElRegistroPorNombre(const char *pchrPtrNmbRegistro,
			  LCamposSiscomPro2 *pLCSiscomPro2Dat);

void SiscomListaSubRegistros(CamposSiscomPro2ConSubReg *pCSiscomPro2SRDat,
				 LCamposSiscomPro2ConSubReg **pLCSiscomPro2SRPrim,
				 LCamposSiscomPro2ConSubReg **pLCSiscomPro2SRAct);
void SiscomNodoSubRegistros(CamposSiscomPro2ConSubReg *pCSiscomPro2SRDat,
			    LCamposSiscomPro2ConSubReg **pLCSiscomPRo2SRDat);


void MemoriaRegistroPrincipal(SCampoSiscomPro2 *pCSiscomPro2Dat,
			      CamposSiscomPro2ConSubReg **pCSiscomPro2SRDat);
void SiscomAgregaSubRegistro(const char *pchrPtrNmbRegistro,
			     SCampoSiscomPro2 *pCSiscomPro2Dat,
			     LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRActual);

int SiscomBuscaSubRegistro(const char *pchrPtrNmbRegistro,
				    SCampoSiscomPro2 *pCSiscomPro2Dat,
				    LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				    LCamposSiscomPro2 **pLCSiscomPro2Prim,
				    LCamposSiscomPro2 **pLCSiscomPro2Act);

int SiscomCopiaDatosPrincipalProtocoloSubRegCharChar(
				LCamposSiscomPro2ConSubReg *pLCSiscomPro2SRDat,
				int pintNRegistros,
				const char *pchrPtrCampo,
				char ***pchrPtrArgumentos);

#define SiscomContenidoSubRegistrosLog(pLCSiscomPro2SRDat)	\
SiscomContenidoSubRegistros(__FILE__,			\
			       __FUNCTION__,			\
			       __LINE__,			\
			       pLCSiscomPro2SRDat)

#endif
