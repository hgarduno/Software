#include <UtilizacionVentas.h>
CQSisPerfilVentas *UtilizacionNivelUno()
{
CQSisPerfilVentas *lCQSPVentas;
	lCQSPVentas=new CQSisPerfilVentas;
	lCQSPVentas->EdoClientes(0);
	lCQSPVentas->EdoContacto(0);
	lCQSPVentas->EdoFormaPago(0);
	lCQSPVentas->EdoPrecios(0);
return lCQSPVentas;
}

void NivelUnoPrincipal(void *pCQSLMenu)
{
CQSisPerfilPrincipal lCQSPPrincipal((CQSisLstMenu *)pCQSLMenu);
lCQSPPrincipal.Habilitado("QAFamilias",0);
lCQSPPrincipal.Habilitado("QAAPrecios",0);
lCQSPPrincipal.Habilitado("QAOrdenesCaja",0);
lCQSPPrincipal.Habilitado("QACaja",0);
}
