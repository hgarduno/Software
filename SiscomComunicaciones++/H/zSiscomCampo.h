#ifndef __ZSISCOMCAMPO_H__
#define __ZSISCOMCAMPO_H__
class zSiscomRegistros;
class zSiscomRegistro;
class zSiscomCampo
{
public:
	zSiscomCampo();
	zSiscomCampo(zSiscomCampo *pzSisCampCampo);
	zSiscomCampo(const char *pchrPtrNombre);
	zSiscomCampo(const char *pchrPtrNombre,
		     const unsigned char *pchrPtrDato);
	zSiscomCampo(const char *pchrPtrCampo,zSiscomRegistro *pzSisRegDato);
	zSiscomCampo(const char *pchrPtrCampo,zSiscomRegistros *pzSisRegsDatos);
	void Nombre(const char *pchrPtrNombre);
	void Dato(const  unsigned char *pchrPtrDato);
	void Dato(zSiscomRegistro *pzSisRegDato);
	void Dato(zSiscomRegistros *pzSisRegsDato);
	const char *Nombre();
	const unsigned char *Dato();
	int DatoInt();
	float DatoFloat();
	bool operator==(zSiscomCampo &);
	void Asociados(zSiscomRegistros *pzSisRegistros);
	zSiscomRegistros *Asociados();
private:
	const char *chrPtrNombre;
	const unsigned char *chrPtrDato;
	zSiscomRegistros *zSisRegsAsociados;
};


#endif
