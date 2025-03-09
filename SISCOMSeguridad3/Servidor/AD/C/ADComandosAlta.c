#include <FuncionesComunes.h>
#include <ADComandosAlta.h>


void ControladorComandoSQL(const char *,StcLtaRegComSISCOM *);
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
