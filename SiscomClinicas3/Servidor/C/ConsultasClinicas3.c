#include <ConsultasClinicas3.h>
#include <Servicios.h>
#include <TipoPrecio.h>
#include <Empleados.h>
#include <Consultas.h>
#include <Precios.h>
#include <Cotizando.h>
#include <SiscomDirecciones.h>
#include <stdlib.h>
SiscomOperaciones2 *OPConsultasClinicas3()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(ConsultaClinicas3,lSOpPtrGimnasio);
return lSOpPtrGimnasio;
}

void ConsultaClinicas3(SArgsSiscom *pSAgsSiscom)
{
SSiscomOperaciones2 *lSSOperaciones=0;
SiscomOperaciones2 *lSOpPtrCnsGimnasios=0;
SiscomLeeEntradaOperaciones2(pSAgsSiscom);
SiscomCopiaArgumentosConsulta(pSAgsSiscom);
SiscomMensajesLog2("ConsultaClinicas3");
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,pSAgsSiscom->LCSiscomPro2Dat);
SiscomAnexaOperacion2("ServiciosGenerales",OPServiciosRegistrados(),&lSSOperaciones);
SiscomAnexaOperacion2("ServiciosMedico",OPServiciosMedicoRegistrados(),&lSSOperaciones);
SiscomAnexaOperacion2("TiposPrecio",OPTipoPrecioRegistrados(),&lSSOperaciones);
SiscomAnexaOperacion2("Empleados",OPEmpleadosRegistrados(),&lSSOperaciones);
SiscomAnexaOperacion2("ConsultasPendientesMedico",OPConsultasPendientesMedico(),&lSSOperaciones);
SiscomAnexaOperacion2("Consultas",OPConsultas(),&lSSOperaciones);
SiscomAnexaOperacion2("ConsultaActualMedico",OPConsultaActualMedico(),&lSSOperaciones);
SiscomAnexaOperacion2("ObservacionesConsulta",OPObservacionesConsulta(),&lSSOperaciones);
SiscomAnexaOperacion2("RecetaConsulta",OPRecetaConsulta(),&lSSOperaciones);
SiscomAnexaOperacion2("DatosParaCobrar",OPDatosParaCobrarConsulta(),&lSSOperaciones);
SiscomAnexaOperacion2("PreciosServicioGeneral",OPPreciosServicio(),&lSSOperaciones);
SiscomAnexaOperacion2("PreciosServicioMedico",OPPreciosServicioMedico(),&lSSOperaciones);
SiscomAnexaOperacion2("DireccionesPersona",OPSiscomAplicacionesDirecciones(),&lSSOperaciones);
SiscomAnexaOperacion2("MediosComunicacionPersona",OPSiscomAplicacionesMediosComunicacion(),&lSSOperaciones);
SiscomAnexaOperacion2("Expediente",OPExpediente(),&lSSOperaciones);
SiscomAnexaOperacion2("RecetasPaciente",OPRecetasPaciente(),&lSSOperaciones);
SiscomAnexaOperacion2("VentasTotalesMedico",OPVentasMedico(),&lSSOperaciones);
SiscomAnexaOperacion2("MaterialHospitalizado",OPMaterialHospitalizado(),&lSSOperaciones);
lSOpPtrCnsGimnasios=SiscomOperaciones2CualEjecuta(
				pSAgsSiscom->chrPtrArgConsulta[0],
				lSSOperaciones,
				ConsultaNoSoportada,
				pSAgsSiscom);
SiscomOperaciones2Ejecuta(lSOpPtrCnsGimnasios,pSAgsSiscom);
}
void ConsultaNoSoportada(SArgsSiscom *pSAgsSiscom)
{
SiscomMensajesLog2("ConsultaNoSoportada");
}
