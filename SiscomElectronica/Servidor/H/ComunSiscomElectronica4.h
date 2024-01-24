#ifndef __COMUNSISCOMELECTRONICA4_H__
#define __COMUNSISCOMELECTRONICA4_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
#include <SiscomProtocoloComunicaciones.h>

extern char gchrArrDirIpCliente[28];

int CondicionConsultaUnosExpendios(SiscomOperaciones *pSisOpePtrDato);
int ArgumentoConsultaUnosExpendios(SiscomOperaciones *pSisOpePtrDato);
int AccesoDatosSiscomElectronica4(SiscomOperaciones *pSiscomOpeDato);
int AccesoDatosSiscomMatriz(SiscomOperaciones *pSiscomOpeDato);
int ValidandoReCaptura(SiscomOperaciones *pSiscomOpePtrDato);
int ValidandoExistenciaATransferir(SiscomOperaciones *pSiscomOpePtrDato);
int ActualizaMatrizConsultaExpendios(SiscomOperaciones *pSiscomOpePtrDatos);

void ExpendiosSiscom(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
void ValidaReCaptura(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

void ValidaExistenciaATransferir(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);


void EnviaCampoIgual(SiscomOperaciones *pSiscomOpePtrDato);
void EnviaCampoDesIgual(SiscomOperaciones *pSiscomOpetrDato);
int EnviaExpendios(SiscomOperaciones *pSiscomOpetrDato);

void ArmaMensajeRegreso(SiscomRegistroProL **pSiscomRegProLPtrRegPrim,
			SiscomRegistroProL **pSiscomRegProLPtrRegAct,
			const char *pchrPtrMensaje,
			const char *pchrPtrEstado);
void SiscomRespuestaEstado(SiscomOperaciones *pSisOpePtrDato,
			  const char *pchrPtrEstado,
			  const char *pchrPtrDescripcion);
int AccesoDatosSeguridad3(SiscomOperaciones *pSiscomOpePtrDato);



int CopiaExpendiosAArgumento(const char *pchrPtrEnvio,
			     const char *pchrPtrAsociado,
			     SiscomOperaciones *pSisOpePtrDato);

int AgregaCampoCondicionConsultaUnosExpendios(const char *pchrPtrEnvio,
					      SiscomOperaciones *pSisOpePtrDato);
void LogOrden(const char *pchrPtrArchivo,
	      const char *pchrPtrFuncion,
	      int pintNLinea,
	      SiscomOperaciones *pSiscomOpePtrDato);



void LogAsociadoEnvio(const char *,const char *,int,char *,SiscomOperaciones *);
#define LOGOrden(pSiscomOpePtrDato) LogOrden(__FILE__,__FUNCTION__,__LINE__,pSiscomOpePtrDato)

#define LOGAsociadoEnvio(pchrPtrBuffer,pSisOpePtrDato) \
	LogAsociadoEnvio(__FILE__,__FUNCTION__,__LINE__,pchrPtrBuffer,pSisOpePtrDato) 

#endif
