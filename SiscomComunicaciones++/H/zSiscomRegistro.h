#ifndef __ZSISCOMREGISTRO_H__
#define __ZSISCOMREGISTRO_H__
#include <zSisListas.h>
#include <cstdio>
class zSiscomCampo;
class zSiscomRegistros;

class zSiscomRegistro:public zSisLista<zSiscomCampo>
{

public:
	zSiscomRegistro();
	~zSiscomRegistro();
	void AgregaCampo(zSiscomCampo *);
	void AgregaCampo(const char *pchrPtrCampo,const unsigned char *pchrPtrDato);
	void AgregaCampo(const char *pchrPtrCampo,zSiscomRegistro *pzSisRegAsociado);
	zSiscomRegistro *Registro(const char *pchrPtrFormato,...);
	void AsociadosAlCampo(const char *pchrPtrCampo,
			      zSiscomRegistros *pzSisRegistros);
	void AsociadoAlCampo(const char *pchrPtrCampo,
			     zSiscomRegistro *pzSisRegistro);
	zSiscomRegistro &operator<<(zSiscomCampo  *);
	const unsigned char *Campo(const char *pchrPtrCampo);
	int  CampoInt(const char *pchrPtrCampo);
	float CampoFloat(const char *pchrPtrCampo);
	const unsigned char *operator[](const char *);
	zSiscomCampo *CampoDato(const char *pchrPtrCampo);
	zSiscomRegistros *AsociadosDelCampo(const char *pchrPtrCampo);
	zSiscomRegistro *AsociadoDelCampo(const char *pchrPtrCampo);
	void ActualizaCampo(const char *pchrPtrCampo,const unsigned char *pchrPtrDato);
	void ActualizaCampo(const char *pchrPtrCampo,zSiscomRegistro *pzSisRegDato);
	void ActualizaCampo(const char *pchrPtrCampo,zSiscomRegistros *pzSisRegsDato);
	void ActualizaCampo(const char *pchrPtrCampo,int pintDato);
	void ActualizaCampoAsociado(const char *pchrPtrAsociado,
				    const char *pchrPtrCampo,
				    const unsigned char *pchrPtrDato);
	zSiscomRegistro &operator=(zSiscomRegistro &pzSiscomRegistro);
	zSiscomRegistro *Copia(zSiscomRegistro *pzSiscomRegistro);
	zSiscomRegistro *Duplica();
	int EstaElCampoEnElRegistro(const char *pchrPtrCampo);
	const unsigned char *CampoAsociado(const char *pchrPtrAsociado,const char *pchrPtrCampo);
	int CampoAsociadoInt(const char *pchrPtrAsociado,const char *pchrPtrCampo);
	const unsigned char *CampoAsociadoAsociado(const char *pchrPtrAsociado,
						   const char *pchrPtrAsociadoA,
						   const char *pchrPtrCampo);
	int EsElValorCampo(const char *pchrPtrCampo,const char *pchrPtrValor);

	zSiscomRegistro *DuplicaCampos(zSiscomRegistro *pzSisRegDato);
	void DuplicaAsociados(zSiscomCampo *pzSisCamDato,zSiscomRegistro *pzSisRegDato);
	void EliminaCampo(const char *pchrPtrCampo);
	const char *CampoConstChar(const char *pchrPtrCampo);
	int CampoVsCadena(const char *pchrPtrCampo,const char *pchrPtrCadena);
};


void SiscomRegistroAlLog2(const char *pchrPtrArchivo,
			   const char *pchrPtrFuncion,
			   int pintNoLinea,
			   zSiscomRegistro *pzSiscomRegistroDat);
#define SiscomRegistroLog2(pzSisRegistroDat) 							\
			 SiscomRegistroAlLog2(__FILE__,__FUNCTION__,__LINE__,pzSisRegistroDat)
#endif
