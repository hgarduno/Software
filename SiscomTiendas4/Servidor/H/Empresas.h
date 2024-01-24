#ifndef __EMPRESAS_H__
#define __EMPRESAS_H__
#include <SiscomDesarrollo2.h>
SiscomOperaciones2 *OPRegistraEmpresa();
SiscomOperaciones2 *OPRegistraEmpresa2();
SiscomOperaciones2 *OPProveedores();
SiscomOperaciones2 *OPContactosProveedores();

SiscomOperaciones2 *OpEmpresaRegistrada();
SiscomOperaciones2 *OpAnexaDireccion();

void ArgumentosEmpresa(SArgsSiscom *);

void NormalizaEmpresa(SArgsSiscom *);
void RegistraEmpresa(SArgsSiscom *);
void RegistraEmpresa2(SArgsSiscom *);
void GeneraIdEmpresa(SArgsSiscom *);
void AsignaIdEmpresaADirecciones(SArgsSiscom *pSAgsSiscom);
void AsignaIdEmpresaAMediosComunicacion(SArgsSiscom *pSAgsSiscom);
void AsignaIdPersonaContactos(SArgsSiscom *pSAgsSiscom);
void AsignaIdEmpresaASubRegistro(SArgsSiscom *pSAgsSiscom,
				 int pintNSubRegistro);
void CopiaContactoAPersonas(SArgsSiscom *);
void NormalizaContacto(SArgsSiscom *);

int LaEmpresaEstaEnNormalizados(SArgsSiscom *);
int ElContactoEstaEnNormalizados(SArgsSiscom *);

void EmpresaYaRegistrada(SArgsSiscom *pSAgsSiscom);
void CopiaIdEmpresaArgumento(SArgsSiscom *pSAgsSiscom);
void EnviaEmpresaRegistrada(SArgsSiscom *pSAgsSiscom);
void AnexaDireccion(SArgsSiscom *pSAgsSiscom);
#endif
