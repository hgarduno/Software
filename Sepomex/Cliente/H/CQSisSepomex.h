#ifndef __CQSISSEPOMEX_H__
#define __CQSISSEPOMEX_H__
#include <SiscomOperaciones3.h>


class SepomexOp:public SiscomOperaciones3
{

public:
	SepomexOp(SiscomDatCom *);

	void SepomexEstados(const char *pchrPtrOperacionConsulta,
			    const char *pchrPtrOperacion,
			    SiscomRegistro3Lst *pSisReg3LstEstados);
	void SepomexMunicipios(const char *pchrPtrOperacionConsulta,
			       const char *pchrPtrOperacion,
			       SiscomRegistro3 *pSisReg3Estado,
			       SiscomRegistro3Lst *pSisReg3LstMunicipios);
	void SepomexAsentamientos(
		const char *pchrPtrOperacionConsulta,
		const char *pchrPtrOperacion,
		SiscomRegistro3 *pSisReg3Estado,
		SiscomRegistro3 *pSisReg3Municipio,
		SiscomRegistro3Lst *pSisReg3LstAsentamientos);

	void SepomexDatosPorCP(const char *pchrPtrOperacionConsulta,
			       const char *pchrPtrCP,
			       SiscomRegistro3 *pSisReg3Estado,
			       SiscomRegistro3Lst *pSisReg3Municipios,
			       SiscomRegistro3Lst *pSisReg3Asentamientos);
};
#endif
