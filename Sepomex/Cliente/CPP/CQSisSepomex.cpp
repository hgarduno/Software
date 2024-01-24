#include <CQSisSepomex.h>

SepomexOp::SepomexOp(SiscomDatCom *pSisDatCom):
		SiscomOperaciones3(pSisDatCom)
{

}

void SepomexOp::SepomexEstados(
	const char *pchrPtrOperacionConsulta,
	const char *pchrPtrOperacion,
	SiscomRegistro3Lst *pSisReg3LstEstados)
{
SiscomEnvia(pchrPtrOperacionConsulta,
	    pSisReg3LstEstados,
	    "%s",
	    pchrPtrOperacion);
}
void SepomexOp::SepomexMunicipios(
	const char *pchrPtrOperacionConsulta,
	const char *pchrPtrOperacion,
	SiscomRegistro3 *pSisReg3Estado,
	SiscomRegistro3Lst *pSisReg3LstMunicipios)
{
pSisReg3LstMunicipios->clear();
SiscomEnvia(pchrPtrOperacionConsulta,
	    pSisReg3LstMunicipios,
	    "%s%s%s",
	    pchrPtrOperacion,
	    "",
	    (*pSisReg3Estado)["numestado"]);
}

void SepomexOp::SepomexAsentamientos(
	const char *pchrPtrOperacionConsulta,
	const char *pchrPtrOperacion,
	SiscomRegistro3 *pSisReg3Estado,
	SiscomRegistro3 *pSisReg3Municipio,
	SiscomRegistro3Lst *pSisReg3LstAsentamientos)
{
pSisReg3LstAsentamientos->clear();
SiscomEnvia(pchrPtrOperacionConsulta,
	    pSisReg3LstAsentamientos,
	    "%s%s%s%s",
	    pchrPtrOperacion,
	    "",
	    (*pSisReg3Estado)["numestado"],
	    (*pSisReg3Municipio)["nummunicipio"]);
}
void SepomexOp::SepomexDatosPorCP(
			const char *pchrPtrOperacionConsulta,
			const char *pchrPtrCP,
			SiscomRegistro3 *pSisReg3Estado,
			SiscomRegistro3Lst *pSisReg3Municipios,
			SiscomRegistro3Lst *pSisReg3Asentamientos)
{

}
		
