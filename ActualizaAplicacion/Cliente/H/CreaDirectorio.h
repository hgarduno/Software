#ifndef __CREADIRECTORIO_H__
#define __CREADIRECTORIO_H__
#include <SISCOMComunicaciones++.h>
class CreaDirectorio
{

public:
	CreaDirectorio(SiscomDatCom *,const char *,const char *);
	~CreaDirectorio();
	const char *ObtenEdoConexion();
	void EnviaOrden();
	void ObtenEdoCreacion(char **,char **);

private:
	char *chrPtrEdoConexion;
	SiscomDatCom *SDatCom;
	SiscomComunicaSrv *SComunicaSrv;
	const char *chrPtrNmbDirectorio;
	const char *chrPtrNmbDirectorioServidor;

private:

};

#endif
