#ifndef __SISCOMTIENDAS41_H__
#define __SISCOMTIENDAS41_H__
#include <SiscomVentanaPrincipal.h>
#include <SiscomVariablesIni.h>
class SisUsuarioSeg3;
class CQSisEmpleado;
class SiscomTiendas41:public SiscomVentanaPrincipal
{
Q_OBJECT
public:
	SiscomTiendas41(QWidget *pQWParent);
private:
	void FirmaAlSistema();
	void Argumentos(SisUsuarioSeg3 *pSisUsrSeg3,
			const char *pchrPtrIdAplicacion,
			const char *pchrPtrIdPerfil);
private:

	SiscomVariablesIni SisVarIniArgs;
	CQSisEmpleado *CQSEmpleado;
private:
	void SiscomIniciaSeguridad();
};
#endif
