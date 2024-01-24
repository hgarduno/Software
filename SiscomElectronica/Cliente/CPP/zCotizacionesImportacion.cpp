#include <zCotizacionesImportacion.h>
#include <zCotizacionImportacion.h>
#include <zEmpresa.h>


#include <zSiscomRegistros.h>

zCotizacionesImportacion::zCotizacionesImportacion()
{

}

void zCotizacionesImportacion::AgregaCotizacionConsultada(zSiscomRegistro *pzSisRegConsulta)
{
zCotizacionImportacion *lzCotImportacion=new zCotizacionImportacion;
lzCotImportacion->Cotizacion((const char *)(*pzSisRegConsulta)["cotizacion"]);
lzCotImportacion->Proveedor(zEmpresa::DeConsultaEmpresas(pzSisRegConsulta));
lzCotImportacion->IdCotizacion((const char *)(*pzSisRegConsulta)["idcotizacionimportacion"]);
lzCotImportacion->CostoDolar((const char *)(*pzSisRegConsulta)["costodolar"]);
lzCotImportacion->ImporteTotal((const char *)(*pzSisRegConsulta)["importe"]);
lzCotImportacion->PesoTotal((const char *)(*pzSisRegConsulta)["peso"]);

(*this) << lzCotImportacion;
}

void zCotizacionesImportacion::AgregaCotizaciones(zSiscomRegistros *pzSisRegsCotizaciones)
{
zSiscomRegistro *lzSisRegCotizacion;

for(lzSisRegCotizacion=pzSisRegsCotizaciones->Primer();
    lzSisRegCotizacion;
    lzSisRegCotizacion=pzSisRegsCotizaciones->Siguiente())
     AgregaCotizacionConsultada(lzSisRegCotizacion);
}
