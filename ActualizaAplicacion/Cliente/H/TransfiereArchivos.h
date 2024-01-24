#ifndef __TRANSFIEREARCHIVOS_H__
#define __TRANSFIEREARCHIVOS_H__
#include <SISCOMComunicaciones++.h>

class TransfiereArchivo
{
public:
	TransfiereArchivo(SiscomDatCom *,
			  const char *,
			  const char *,
			  const char *,
			  const char *,
			  const char *);
	TransfiereArchivo(SiscomDatCom *,
			  const char *,
			  const char *,
			  const char *,
			  const char *,
			  const char *,
			  const char *);
	~TransfiereArchivo();

private:
	SiscomComunicaSrv *SComunicaSrv;
	SiscomDatCom *SDatCom;
	SiscomRegistroPro2 SRegistroPro2;
	const char *chrPtrOrigen;
	const char *chrPtrDestino;
	const char *chrPtrDirTrabajo;
	const char *chrPtrHome;
	const char *chrPtrArchivoEnBuffer;
	const char *chrPtrComentario;
private:
	void CreaRegistroComunicaciones();
	void Transfiere();
	void TransfiereDelBuffer();
	void EnviaArchivo(int);
	void EnviaArchivoDelBuffer(int);
};


#endif
