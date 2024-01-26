#ifndef __COMUNSISCOMSERVISNTET_H__
#define __COMUNSISCOMSERVISNTET_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>
int ComunicacionAccesoDatos(SiscomOperaciones *pSiscomOpePtrDat);
int RespondeConsultaSinRegistros(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaMensajeCliente(const char *pchrPtrArchivo,
			const char *pchrPtrFuncion,
			int pintNoLinea,
			const char *pchrPtrEstado,
			const char *pchrPtrMensaje,
			SiscomOperaciones *pSiscomOpePtrDato);

void RespondeRegistroExitoso(SiscomOperaciones *pSiscomOpePtrDato);
void DatosFecha(const char *pchrPtrFecha,
        char *pchrPtrAnio,
        char *pchrPtrMes,
        char *pchrPtrDia);

void RespondiendoEstadoInsercion(const char *pchrPtrArgumento,
				  SiscomOperaciones *pzSiscomOpePtrDato);

void ExistenciasTiendaLocalRemota(SiscomRegistroProL *pSiscomRegProLPtrServidores,
		       SiscomOperaciones *pSiscomOpePtrDato,
		       const char *pchrPtrSql);

#define MSGAviso(pchrPtrEstado,pchrPtrMensaje,pSiscomOperaciones) 	\
	  EnviaMensajeCliente(__FILE__,					\
	  			__FUNCTION__,				\
				__LINE__,				\
				pchrPtrEstado,				\
				pchrPtrMensaje,				\
				pSiscomOperaciones)
#endif
