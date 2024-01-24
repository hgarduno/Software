#include <SiscomClinicas3.h>
#include <ServidorGeneral.h>
#include <RNSiscomSeguridad3Prot2.h>
#include <ConsultasClinicas3.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <Errores.h> 
#include <Empleados.h>
#include <Servicios.h>
#include <Pacientes.h>
#include <Consultas.h>
#include <Cotizando.h>
#include <Precios.h>

/*SiscomTiendas4
 *
 */

#include <Familias.h>
#include <Productos.h>
#include <ConsultasTiendas4.h>
#include <Empresas.h>
#include <Precios.h>
#include <Compras.h>
#include <Cotiza.h>
#include <Devoluciones.h>
#include <Ventas.h>

/* SiscomAplicaciones 
 *
 *
 */

#include <SiscomDirecciones.h>
#include <SiscomMediosComunicacion.h>

void Principal(int pintSocket) 
	       
{
SSiscomOperaciones *lSSiscomOp=0;
int lintContador;
char *lchrPtrOperacion=0;
int lintNRegistros;
SSiscomOperaciones2 *lSOpPtrOperaciones=0;
SiscomOperaciones2 *lSOpPtrSistema;
SArgsSiscom lSArgsSiscomDat;
	memset(&lSArgsSiscomDat,0,sizeof(SArgsSiscom));
	OperacionesSistemaGeneral(&lSSiscomOp);
	SiscomLeeNumeroRegistros(pintSocket,
				 &lintNRegistros);	
	SiscomLeeOperacion(pintSocket,
                           &lchrPtrOperacion);
	for(lintContador=0;
            lintContador<lSSiscomOp->intNumOperaciones;
            lintContador++)
        if(!strcmp((lSSiscomOp+lintContador)->chrPtrOperacion,
                   lchrPtrOperacion))
        {
             (lSSiscomOp+lintContador)->Operacion(pintSocket,lintNRegistros);
             return ;
        }
	SiscomMensajesLog(gPtrFleArchivoLog,
			 "Se busca la operacion %s, en el nuevo sistema",lchrPtrOperacion);
	AsignaOperacionesVersion2(pintSocket,
				  lintNRegistros,
				  &lSOpPtrOperaciones,
				  &lSArgsSiscomDat);
	ManejadorErrores(&lSArgsSiscomDat);
	lSOpPtrSistema=SiscomOperaciones2CualEjecuta(
				lchrPtrOperacion,
				lSOpPtrOperaciones,
				SiscomErrorOperacion2,
				&lSArgsSiscomDat);
	SiscomOperaciones2Ejecuta(lSOpPtrSistema,
				  &lSArgsSiscomDat);
}

void OperacionesSistemaGeneral(SSiscomOperaciones **pSSiscomOp)
{
	SiscomIniciaOperaciones(3,pSSiscomOp);
	SiscomAnexaOperacion("ConsultaSepomex",
			      ConsultaSepomex,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaSeguridad3Pro2",
			      ConsultaSeguridad3Pro2,
			      pSSiscomOp);
	SiscomAnexaOperacionesAlFinal(gSSiscomOpSistema,pSSiscomOp);
}
void AsignaOperacionesVersion2(int pintSocket,
			       int pintNRegistros,
			       SSiscomOperaciones2 **pSSOperaciones2,
			       SArgsSiscom *pSArgsSiscom)
{
pSArgsSiscom->intSocketCliente=pintSocket;
pSArgsSiscom->intNRegistrosDat=pintNRegistros;
SiscomAnexaOperacion2("ConsultasClinicas3",
		      OPConsultasClinicas3(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraEmpleado",
		      OPEmpleado(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraServicioGeneral",
		      OPServicio(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraServicioMedico",
		      OPServiciosMedico(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraTipoPrecio",
		      OPTipoPrecio(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraPerfilMedico",
		      OPPerfilServicioMedico(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraPaciente",
		      OPPaciente(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraConsulta",
		      OPConsulta(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("ActualizaEdoConsulta",
		      OPActualizaEstadoConsulta(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraExpediente",
		      OPRegistraExpediente(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("ActualizaObservaciones",
		      OPActualizaObservaciones(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("CotizaPerfilMedico",
		      OPCotizaPerfilMedico(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("CotizaConsulta",
		      OPCotizaConsulta(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("TerminaConsulta",
		      OPTerminaConsulta(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraReceta",
		      OPRegistraReceta(),
		      pSSOperaciones2);

SiscomAnexaOperacion2("ActualizaReceta",
		      OPActualizaReceta(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("ActualizaPrecioServicioGeneral",
		      OPActualizaPrecioServicioGeneral(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("ActualizaPrecioServicioMedico",
		      OPActualizaPrecioServicioMedico(),
		      pSSOperaciones2);

SiscomAnexaOperacion2("BuscaPersonas",
		      OPBuscaPersonas(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("PacientesSimilares",
		      OPBuscaPersonasSimilares(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("ActualizaPersona",
		      OPActualizaPersonales(),
		      pSSOperaciones2);
/* SiscomAplicaciones
 *
 *
 */

SiscomAnexaOperacion2("RegistraDireccion",
		      OPSiscomAplicacionesRegistraDireccion(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraMedioComunicacion",
		      OPSiscomAplicacionesRegistraMedioComunicacion(),
		      pSSOperaciones2);

/* Insercion del sistema de tiendas4
 *
 *
 *
 */

SiscomAnexaOperacion2("ConsultaTiendas4",
		      OperacionesConsultasTiendas4(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraFamilia",
		      OperacionesFamilias(),
		      pSSOperaciones2);

SiscomAnexaOperacion2("RegistraProducto",
		      OperacionesProductos(),
		      pSSOperaciones2);

SiscomAnexaOperacion2("RegistraEmpresa",
		      OPRegistraEmpresa(),
		      pSSOperaciones2);

SiscomAnexaOperacion2("RegistraPrecio",
		      OPAnexaPrecio(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("ActualizaProducto",
		      OperacionesActualizaProductos(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraCompra",
		      OPRegistraCompra(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("CotizaProductos",
		      OPCotiza(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("IdentificadorCotizacion",
		      OPIdCotizacion(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraVenta",
		      OPRegistraVenta(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("Devolucion",
		      OPDevolucion(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("TotalADevolver",
		      OPTotalADevolver(),
		      pSSOperaciones2);

SiscomAnexaOperacion2("MaterialServicioHospitalizacion",
		      OPMaterialServicioHospitalizacion(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("MaterialHospitalizacion",
		       OPMaterialHospSesion(),
		      pSSOperaciones2);
}
void SiscomErrorOperacion2(SArgsSiscom *pSAgsSisPtr)
{
SiscomMensajesLog(gPtrFleArchivoLog,"Operacion No Soportada");
}

