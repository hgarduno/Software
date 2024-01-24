#ifndef __SISCOMCOMUNICASRV_H__
#define __SISCOMCOMUNICASRV_H__

extern "C"{
#include <SiscomDesarrollo2.h>
};
class SiscomRegistrosPro2;
class SiscomDatCom;
class SiscomComunicaSrv
{
public:
	SiscomComunicaSrv(SiscomDatCom *);
	~SiscomComunicaSrv();
	void SiscomEnvia(SiscomRegistrosPro2 *,const char *);
	const char *SiscomObtenEdoConexion();
	const char *SiscomObtenOperacion();
	int SiscomObtenNumRegistrosRes();
	int SiscomObtenRespuesta();
	int SiscomObtenSocket();
	LCamposSiscomPro2 *SiscomRegistrosRespuesta();
private:
	SiscomDatCom *SDatCom;
	int intSocket;
	char *chrPtrEdoComunicacion;
	LCamposSiscomPro2 *LCSiscomPro2PrimRes;
	int intNRegistrosRes;
	char *chrPtrOperacion;
};


#endif
