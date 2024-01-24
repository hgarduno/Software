#ifndef __ZCONDICIONCONSULTAORDENES_H__
#define __ZCONDICIONCONSULTAORDENES_H__

#include <zSiscomRegistro.h>
class zCondicionConsultaOrdenes:public zSiscomRegistro
{
public:

    zCondicionConsultaOrdenes();
   void ComoConsulto(const char *);
   	void FechaInicio(const char *);
   	void FechaFin(const char *);
};


class zCondicionConsultaFechaEntrega:public zCondicionConsultaOrdenes
{
public:
	zCondicionConsultaFechaEntrega();
        void IdTipoOrden(const char *);
};

class zCondicionConsultaHoraEntrega:public zCondicionConsultaOrdenes
{
public:
	zCondicionConsultaHoraEntrega();
   	void HoraInicio(const char *);
   	void HoraFin(const char *);
};

#endif
