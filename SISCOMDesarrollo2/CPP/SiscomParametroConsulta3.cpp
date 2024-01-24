#include <SiscomParametroConsulta3.h>

SiscomParametroConsulta3::SiscomParametroConsulta3(const char *pchrPtrParametro)
{
	(*this)		<<
	new SiscomCampo3("Parametro",pchrPtrParametro);
}
