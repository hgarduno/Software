#include <FuncionesComunes.h>
#include <POSTGRESQLControlador.h>

int  ADDllEliminaProductos(int pintSCliente,
			   int pintTuberia[],
			   int pintPtoCom,
			   char *pchrPtrDirIPSvrAD)
{

int lintNCampos,
    lintNRegistros,
    lintI;
StcLtaRegComSISCOM *lSLRCSisPrim=0,
		   *lSLRCSisPResR=0;
	SISCOMObtenRespuestaSVR(pintSCliente,
				&lintNCampos,
				&lintNRegistros,
				&lSLRCSisPrim);
	ControladorComandoSQL("SiscomTiendas",
			      lSLRCSisPrim);



}
