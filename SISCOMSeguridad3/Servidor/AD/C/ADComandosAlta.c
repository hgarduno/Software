#include <FuncionesComunes.h>
#include <POSTGRESQLControlador.h>
#include <ADComandosAlta.h>

int  ADComandosAlta(int pintSCliente,
			   int pintTuberia[],
			   int pintPtoCom,
			   char *pchrPtrDirIPSvrAD)
{

int lintNCampos,
    lintNRegistros,
    lintI;
const char *lchrPtrBaseDatos=getenv("BASESISCOM");
StcLtaRegComSISCOM *lSLRCSisPrim=0,
		   *lSLRCSisPResR=0;


	SISCOMObtenRespuestaSVR(pintSCliente,
				&lintNCampos,
				&lintNRegistros,
				&lSLRCSisPrim);
	ControladorComandoSQL(lchrPtrBaseDatos,
			      lSLRCSisPrim);
}
