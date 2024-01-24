#ifndef __SISCOMCLASESINI_H__
#define __SISCOMCLASESINI_H__

#include <SiscomClaseIni.h>


class SiscomClasesIni:public QPtrList<SiscomClaseIni>
{
public:
	SiscomClasesIni();
	SiscomClasesIni &operator<<(SiscomClaseIni *pSisClasIni);
	const char *ValorPropiedad(const char *pchrPtrClase,
			      const char *pchrPtrPropiedad);
	SiscomClaseIni *YaEstaLaClase(int pintNCamposNombre,
			  char **pchrPtrCamposNombre,
			  char *pchrPtrNombre);
	SiscomClaseIni *ClasePorNombre(const char *pchrPtrNombre,
				       int pintNivel);

	void ClasesPorNombre(const char *pchrPtrNombre,
					      SiscomClasesIni &);
	void ClasesPorNombre(const char *pchrPtrNombre,
			     int pintNivel,
			     SiscomClasesIni &pSisClassIni);
private:
	void FormaNombre(int pintNCamposNombre,
			 char **pchrPtrCamposNombre,
			 char *pchrPtrNombre);
private:
};

#endif
