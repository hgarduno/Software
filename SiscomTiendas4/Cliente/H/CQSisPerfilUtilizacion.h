#ifndef __CQSISPERFILUTILIZACION_H__
#define __CQSISPERFILUTILIZACION_H__
#include <SISCOMComunicaciones++.h>


class CQSisPerfilVentas
{
public:
	CQSisPerfilVentas();
	int EdoClientes();
	int EdoContacto();
	int EdoFormaPago();
	int EdoPrecios();
	void EdoClientes(int);
	void EdoContacto(int);
	void EdoFormaPago(int);
	void EdoPrecios(int);
private:
	
	int intEdoClientes;
	int intEdoContacto;
	int intEdoFormaPago;
	int intEdoPrecios;
	

};

class CQSisPerfilPrincipal
{
public:
	CQSisPerfilPrincipal(CQSisLstMenu *);
	void Habilitado(const char *,int );
private:
	CQSisLstMenu *CQSLMenus;
};
#endif
