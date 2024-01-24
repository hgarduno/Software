#include <CQSisPerfilUtilizacion.h>
CQSisPerfilVentas::CQSisPerfilVentas():
		intEdoClientes(0),
		intEdoContacto(0),
		intEdoFormaPago(0),
		intEdoPrecios(0)
{


}

int CQSisPerfilVentas::EdoClientes()
{
return intEdoClientes;
}
int CQSisPerfilVentas::EdoContacto()
{
return intEdoContacto;
}
int CQSisPerfilVentas::EdoFormaPago()
{
return intEdoFormaPago;
}
int CQSisPerfilVentas::EdoPrecios()
{
return intEdoPrecios;
}
void CQSisPerfilVentas::EdoClientes(int pintEdoClientes)
{
	intEdoClientes=pintEdoClientes;
}
void CQSisPerfilVentas::EdoContacto(int pintEdoContacto)
{
	intEdoContacto=pintEdoContacto;
}
void CQSisPerfilVentas::EdoFormaPago(int pintEdoFormaPago)
{
	intEdoFormaPago=pintEdoFormaPago;
}
void CQSisPerfilVentas::EdoPrecios(int pintEdoPrecios)
{
	intEdoPrecios=pintEdoPrecios;
}

CQSisPerfilPrincipal::CQSisPerfilPrincipal(CQSisLstMenu *pCQSLMenus):
			CQSLMenus(pCQSLMenus)
{
}
void CQSisPerfilPrincipal::Habilitado(const char *pchrPtrNmbMenu,
				   int pintValor)
{
	(*CQSLMenus)[pchrPtrNmbMenu]->setEnabled(pintValor);
}
