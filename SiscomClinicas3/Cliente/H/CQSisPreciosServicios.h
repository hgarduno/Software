#ifndef __CQSISPRECIOSSERVICIOS_H__
#define __CQSISPRECIOSSERVICIOS_H__
#include <SISCOMComunicaciones++.h>

class CQSisServicio;
class CQSisPrecio;

class CQSisPrecioServicio:public SiscomInformacion
{
public:
	CQSisPrecioServicio(CQSisServicio *,
			    CQSisPrecio *,
			    const char *);
	CQSisPrecioServicio(const char *,
			    const char *,
			    const char *,
			    const char *);
	CQSisServicio *Servicio();
	CQSisPrecio *Precio();
private:
	CQSisServicio *CQSServicio;
	CQSisPrecio *CQSPrecio;
};
class CQSisLstPrecioServicio:public QPtrList<CQSisPrecioServicio>
{
public:
	CQSisLstPrecioServicio();
	CQSisLstPrecioServicio &operator<<(CQSisPrecioServicio *);
};

class CQSisOpPrecioServicio:public SiscomOperaciones
{
public:
	CQSisOpPrecioServicio(SiscomDatCom *);
	void PreciosServicio(const char *,CQSisLstPrecioServicio *);
	void PreciosServicio(const char *,const char *,CQSisLstPrecioServicio *);
	void ActualizaPrecio(CQSisPrecioServicio *);
	void ActualizaPrecioMedico(CQSisPrecioServicio *);
private:
	SiscomParametrosConsulta SPConsulta;
private:
	void Elimina(CQSisLstPrecioServicio *);
};
#endif
