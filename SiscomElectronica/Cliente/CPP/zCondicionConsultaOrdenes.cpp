#include <zCondicionConsultaOrdenes.h>
#include <zSiscomCampo.h>
zCondicionConsultaOrdenes::zCondicionConsultaOrdenes()
{
  (*this)   			  				<< 
  new zSiscomCampo("PorCondicionConsultaOrdenes")	 	<<
  new zSiscomCampo("FechaInicio")				<<
  new zSiscomCampo("FechaFin")					<<
  new zSiscomCampo("ComoConsulto");
}

void zCondicionConsultaOrdenes::ComoConsulto(const char *pchrPtrComoConsulto)
{
   ActualizaCampo("ComoConsulto",(const unsigned char *)pchrPtrComoConsulto);
}

void zCondicionConsultaOrdenes::FechaInicio(const char *pchrPtrFecha)
{
   ActualizaCampo("FechaInicio",(const unsigned char *)pchrPtrFecha);

}
void zCondicionConsultaOrdenes::FechaFin(const char *pchrPtrFecha)
{
   ActualizaCampo("FechaFin",(const unsigned char *)pchrPtrFecha);
}

zCondicionConsultaFechaEntrega::zCondicionConsultaFechaEntrega()
{
   (*this)				<<
   new zSiscomCampo("IdTipoOrden");
}



void zCondicionConsultaFechaEntrega::IdTipoOrden(const char *pchrPtrIdTipoOrden)
{
   ActualizaCampo("IdTipoOrden",(const unsigned char *)pchrPtrIdTipoOrden);
}




zCondicionConsultaHoraEntrega::zCondicionConsultaHoraEntrega()
{
  (*this)				<<
  new zSiscomCampo("HoraInicio")	<<
  new zSiscomCampo("HoraFin");
}
void zCondicionConsultaHoraEntrega::HoraInicio(const char *pchrPtrHoraInicio)
{
	ActualizaCampo("HoraInicio",(const unsigned char *)pchrPtrHoraInicio);
}
void zCondicionConsultaHoraEntrega::HoraFin(const char *pchrPtrHoraFin)
{
	ActualizaCampo("HoraFin",(const unsigned char *)pchrPtrHoraFin);
}
