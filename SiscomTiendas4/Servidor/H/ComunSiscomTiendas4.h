#ifndef __COMUNSISCOMTIENDAS4_H__
#define __COMUNSISCOMTIENDAS4_H__
#include <SiscomDesarrollo2.h>


typedef struct CadenaConsulta
{
   const char *chrPtrNombre;
   int intNConsultas;
   void (*SQLFormaCadena)(SArgsSiscom *,char *);
}StcArgsConsulta;

typedef void (*SQLGeneraConsulta)(SArgsSiscom *,char *);

void ComunicacionAccesoDatos(SArgsSiscom *);
void EjecutaRegistroInformacion(SArgsSiscom *,const char *);
void ObtenInformacionArgumento(const char *pchrPtrArgumento,
			       SArgsSiscom *pSAgsSiscom,
			       LCamposSiscomPro2 **pLCSiscomPro2Prim,
			       LCamposSiscomPro2 **pLCSiscomPro2Act,
			       int *pintPtrNRegistros);

void AsignaInformacionArgumento(const char *,
				SArgsSiscom *,
			       LCamposSiscomPro2 *,
			       LCamposSiscomPro2 *,
			       int );

void EjecutaConsultaYResponde(SArgsSiscom *pSAgsSiscom,
			      const char *pchrPtrConsultaSQL);

void CambiaCampoProtocoloMayusculas(LCamposSiscomPro2 *,const char *);
void CambiaCampoMayusculas(LCamposSiscomPro2 *,const char *);

void AnexaArgsConsulta(void (*SQLConsulta)(SArgsSiscom *,char *),
		       const char *,
		       StcArgsConsulta *);


SQLGeneraConsulta ObtenFuncionGeneraConsulta(StcArgsConsulta *,
					     SQLGeneraConsulta,
					     const char *);
void SQLConsultaNoSoportada(SArgsSiscom *,char *);

void GeneraInsercionActualizacion(SArgsSiscom *,
				  const char *,
				  void (*GeneraSQL)(LCamposSiscomPro2 *,
				  		    LCamposSiscomPro2 **,
				  		    LCamposSiscomPro2 **,
						    int *));

#endif
