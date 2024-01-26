#ifndef __ZSISCOMREGISTROS_H__
#define __ZSISCOMREGISTROS_H__
#include <zSiscomRegistro.h>


class zSiscomRegistros:public zSisLista<zSiscomRegistro>
{
public:
	zSiscomRegistros();
	zSiscomRegistros &operator<<(zSiscomRegistro *pzSisRegistro);
	zSiscomRegistros &operator=(zSiscomRegistros &pzSisRegsDatos);
	zSiscomRegistros &operator+=(zSiscomRegistros &pzSisRegsDatos);
	zSiscomRegistro *operator[](int pintNRegistro);
	zSiscomRegistro *PorCampoDato(const char *pchrPtrCampo,
				      const unsigned char *pchrPtrDato);
	const char *CampoRegistro(int pintNRegistro,const char *pchrPtrCampo);
	int CampoRegistroInt(int pintNRegistro,const char *pchrPtrCampo);
	zSiscomRegistros &ListaCadenas(const char *pchrPtrNombreCampo,char **pchrPtrCadenas);
	zSiscomRegistros &CadenaConSeparador(const char *pchrPtrNombreCampo, 
					     const char *pchrPtrCadena,
					     char pchrSeparador);
	zSiscomRegistros *Respalda();
	void EliminaCampo(const char *);
	zSiscomRegistro *BuscaRegistro(const char *pchrPtrCampo,
				       const char *pchrPtrDato);
private:
	int BuscaCampoRegistro(zSiscomRegistro *pzSisRegistro,
			       const char *pchrPtrCampo,
			       const unsigned char *pchrPtrDato);
};


void SiscomRegistrosAlLog(const char *pchrPtrArchivo,
			  const char *pchrPtrFuncion,
			  int pintNoLinea,
			  zSiscomRegistros *pzSisRegistrosDat);
void SiscomRegistrosAlLogLista(const char *pchrPtrArchivo,
			       const char *pchrPtrFuncion,
			       int pintNoLinea,
			       zSiscomRegistros *pzSisRegistrosDat);
#define SiscomRegistrosLog(pzSisRegistrosDat) 					\
	SiscomRegistrosAlLog(__FILE__,__FUNCTION__,__LINE__,pzSisRegistrosDat)
#endif
