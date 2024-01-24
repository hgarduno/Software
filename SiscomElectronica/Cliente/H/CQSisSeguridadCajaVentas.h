#ifndef __CQSISSEGURIDADCAJAVENTAS_H__
#define __CQSISSEGURIDADCAJAVENTAS_H__
#include <SiscomRegistros3.h>
#include <SiscomOperaciones3.h>

class CQSisCajasSeguridad;
class CQSisCajaSeguridad;
class CQSisControlCaja:public SiscomRegistro3
{
public:
	CQSisControlCaja(const char *pchrPtrIdCaja,
			 const char *pchrPtrDireccionIp,
			 const char *pchrPtrDescripcion,
			 const char *pchrPtrIdControl,
			 const char *pchrPtrNombreQt,
			 const char *pchrPtrNombre,
			 const char *pchrPtrEstado,
			 const char *pchrPtrIdExpendio);

};
class CQSisOpControlCaja:public SiscomOperaciones3
{
	
public:
	CQSisOpControlCaja(SiscomDatCom *);
	void CajasYControles(const char *,
			     SiscomRegistro3Lst *,
			     CQSisCajasSeguridad *); 
	void RegistraEstados(const char *,
			     CQSisCajasSeguridad *);
	void ControlesSeguridadCaja(const char *pchrPtrIdExpendio,
				    const char *pchrPtrIdCaja,
				    SiscomRegistro3Lst *pSisReg3LstControlesCaja);
private:
	void ObtenControlesCaja(SiscomRegistro3Lst *,
				CQSisCajaSeguridad *);
	int IdCaja(SiscomRegistro3Lst *);
	void AgregaSeguridadCaja(SiscomRegistro3 *,
				 CQSisCajasSeguridad *,
				 CQSisCajaSeguridad **);
	void ColocaIdExpendio(SiscomRegistro3Lst &,const char *);
};
class CQSisCajaSeguridad
{
public:
	CQSisCajaSeguridad(SiscomRegistro3 *);
	/*!
	 * Agrega un control a la caja
	 */
	const CQSisCajaSeguridad &operator<<(const SiscomRegistro3 *);
	const SiscomRegistro3Lst &ControlesCaja();
	const char *Caja();
private:
	SiscomRegistro3Lst SisReg3LstControl;
	SiscomRegistro3 *SisReg3Caja;
};
class CQSisCajasSeguridad:public QPtrList<CQSisCajaSeguridad>
{
public:
	CQSisCajasSeguridad();
	const CQSisCajasSeguridad &operator<<(const CQSisCajaSeguridad *);
};

class CQSisControlesCaja:public SiscomRegistro3Lst 
{
public:
	CQSisControlesCaja();
	SiscomRegistro3 *operator[](const char *);

	int EsVerdaderoEntero(const char *);
};
#endif
