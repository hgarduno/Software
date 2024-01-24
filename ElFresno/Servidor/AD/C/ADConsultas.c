#include <ADConsultas.h>
#include <POSTGRESQLControlador.h>


int ADConsultas(int pintSCliente,
		       int pintTuberia[],
		       int pintPtoCom,
		       char *pchrPtrDirIpSvr)
{
int lintNCampos,
    lintNRegistros,
    lintI,
    lintContador,
    lintNRegistrosR,
    lintNCamposR;
StcLtaRegComSISCOM *lSLRCSisPrim=0,
		   *lSLRCSisPResR=0;
        SISCOMObtenRespuestaSVR(pintSCliente,
			        &lintNCampos,
				&lintNRegistros,
				&lSLRCSisPrim); 
	ControladorEjecutaConsulta(getenv("BASESISCOM"),
				   lSLRCSisPrim,
				   &lintNCamposR,
				   &lintNRegistrosR,
				   &lSLRCSisPResR);
	SISCOMEnviaRespuestaAlCliente(pintSCliente,
				      lSLRCSisPResR,
				      lintNRegistrosR);
}

