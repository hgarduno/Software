#ifndef __SISCOMSERVISNTE_H__
#define __SISCOMSERVISNTE_H__
#include <SiscomProtocoloComunicaciones.h>

void ServidorSiscomServiSNTE(const char *pchrPtrDirIpCliente,
		     void *pvidPtrAncla,
		     int pintSocket);

void EjecutaOperacion(int pintSocket,
		      void *pvidPtrAncla,
		      const SiscomRegistroProL *pSiscomRegProLPtrPrim,
		      const SiscomRegistroProL *pSiscomRegProLPtrAct);
#endif
