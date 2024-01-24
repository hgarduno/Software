#ifndef __CQSISEMPRESAS2_H__
#define __CQSISEMPRESAS2_H__

#include <SiscomRegistros3.h>
#include <SiscomRegistros4.h>
#include <SiscomOperaciones3.h>
class CQSisMedioComunicacionE;
class CQSisContactoE;
class CQSisDireccionE;
class CQSisEmpresa2:public SiscomRegistro4
{
public:

	CQSisEmpresa2();
	void Generales(const char *pchrPtrIdEmpresa,
		       const char *pchrPtrRazonSocial,
		       const char *pchrPtrTEmpresa);
	void Generales(SiscomRegistro3 *);
	void AgregaDireccion(SiscomRegistro3 *);
	void AgregaContacto(SiscomRegistro3 *);
	void AgregaMedioComunicacion(SiscomRegistro3 *);
	void AsignaDirecciones(SiscomRegistro3Lst *);	
	void AsignaMediosComunicacion(SiscomRegistro3Lst *);
	void AsignaContactos(SiscomRegistro3Lst *);
	void AsignaEmpresa(SiscomRegistro4 *);

private:
	void LimpiaSubGrupo(SiscomRegistro3Lst *);
	SiscomRegistro3 *DatosGenerales(const char *pchrPtrIdEmpresa,
					const char *pchrPtrRazonSocial,
					const char *pchrPtrTEmpresa);

};


class CQSisContactoE:public SiscomRegistro3
{
public:
	CQSisContactoE(const char *pchrPtrIdPersona,
		       const char *chrPtrDescripcion,
		       const char *pchrPtrNombre,
		       const char *pchrPtrAPaterno,
		       const char *pchrPtrAMaterno);
};
class CQSisDireccionE:public SiscomRegistro3
{
public:
	CQSisDireccionE(const char *pchrPtrIdPersona,
			 const char *pchrPtrIdEmpresa,
			 const char *pchrPtrLinea1,
			 const char *pchrPtrLinea2,
			 const char *pchrPtrLinea3);

};
class CQSisMedioComunicacionE:public SiscomRegistro3
{
public:
	CQSisMedioComunicacionE(const char *pchrPtrIdPersona,
			       const char *pchrPtrIdEmpresa,
			       const char *pchrPtrIdMedio,
			       const char *pchrPtrDescripcion,
			       const char *pchrPtrDato);
};

class CQSisOperacionesEmp2:public SiscomOperaciones3
{
public:
	CQSisOperacionesEmp2(SiscomDatCom *pSisDatCom);
	void Envia(SiscomRegistro3 *pSisReg3Conf,
		   CQSisEmpresa2 *pCQSisEmpresa2,
		   SiscomRegistro4 *pSisReg4LstResp);	
	int EmpresaRegistrada(CQSisEmpresa2 *pCQSEmpresa2);
};
#endif
