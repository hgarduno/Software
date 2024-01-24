#ifndef __CQSISSERVICIOS_H__
#define __CQSISSERVICIOS_H__
#include <SISCOMComunicaciones++.h>

/*
 *
 * Jueves 14 De Febrero 2008
 *
 * Se agrego el campo pchrPtrTipo, al constructor
 * ya que esto permitira controlar el registro de 
 * los servicios, que pueden ser generales o del 
 * medico, hacerlo de esta forma nos permitira 
 * controlar desde la misma ventana el registro
 * de servicios.
 * Adicionalmente, se requiere para el caso en
 * el que se utilice el registro de un servicio 
 * del medico el identificador del medico que 
 * realiza el registro
 *
 * En el campo Tipo se pasara en lugar de General
 * RegistraServicioGeneral
 * o
 * RegistraServicioMedico
 *
 * Por default sera RegistraServicioGeneral
 *
 *
 */
class CQSisServicio:public SiscomInformacion
{
public:
	CQSisServicio(const char *,
		      const char *,
		      const char *,
		      const char *pchrPtrTipo="RegistraServicioGeneral",
		      const char *pchrPtrIdMedico="");

};

class CQSisLstServicio:public QPtrList<CQSisServicio>
{
public:
	CQSisLstServicio();
	CQSisLstServicio &operator<<(CQSisServicio *);
};
class CQSisOpServicio:public SiscomOperaciones
{
public:
	CQSisOpServicio(SiscomDatCom *);
	void Servicio(CQSisServicio *,SiscomRegistrosPro2 **);
	void Servicio(const char *,
		      const char *,
		      CQSisLstServicio *);
	void PerfilServicioMedico(CQSisLstServicio *,SiscomRegistrosPro2 **);
	/*
	void PreciosServicios(CQSisLstServicio *);
	void PreciosServicios(const char *,CQSisLstServicio *);
	*/
private:
	SiscomParametrosConsulta SPConsulta;
private:
	void EliminaServicios(CQSisLstServicio *);
};
#endif
