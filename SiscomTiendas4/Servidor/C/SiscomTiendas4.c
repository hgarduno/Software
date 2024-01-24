#include <SiscomTiendas4.h>
#include <SiscomAplicaciones.h>
#include <ServidorGeneral.h>
#include <RNSiscomSeguridad3Prot2.h>
#include <ComunSiscomTiendas4.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


#include <AsignaAsesor.h>
#include <Clientes.h>
#include <Pedidos.h>

#include <Errores.h>
void (*ComunicacionAccesoDatosSepomex)(SArgsSiscom *);
void Principal(int pintSocket) 
	       
{
SSiscomOperaciones *lSSiscomOp=0;
int lintContador;
char *lchrPtrOperacion=0;
int lintNRegistros;
SSiscomOperaciones2 *lSOpPtrOperaciones=0;
SiscomOperaciones2 *lSOpPtrSistema=0;
SArgsSiscom lSArgsSiscomDat;
	memset(&lSArgsSiscomDat,0,sizeof(SArgsSiscom));
	OperacionesSistemaGeneral(&lSSiscomOp);
	SiscomLeeNumeroRegistros(pintSocket,
				 &lintNRegistros);	
	SiscomLeeOperacion(pintSocket,
                           &lchrPtrOperacion);
	ComunicacionAccesoDatosSepomex=ComunicacionAccesoDatos;
	for(lintContador=0;
            lintContador<lSSiscomOp->intNumOperaciones;
            lintContador++)
        if(!strcmp((lSSiscomOp+lintContador)->chrPtrOperacion,
                   lchrPtrOperacion))
        {
             (lSSiscomOp+lintContador)->Operacion(pintSocket,lintNRegistros);
	     
             return ;
        }
	SiscomLog("Se busca la operacion %s, en el nuevo sistema",
			 lchrPtrOperacion);
	AsignaOperacionesVersion2(pintSocket,
				  lintNRegistros,
				  &lSOpPtrOperaciones,
				  &lSArgsSiscomDat);
	ManejadorErrores(&lSArgsSiscomDat);
	if((lSOpPtrSistema=SiscomOperaciones2CualEjecuta(
				lchrPtrOperacion,
				lSOpPtrOperaciones,
				SiscomErrorOperacion2,
				&lSArgsSiscomDat)))
	{
	SiscomLog("Ejecutando %s",lchrPtrOperacion);
	SiscomOperaciones2Ejecuta(lSOpPtrSistema,
				  &lSArgsSiscomDat);
	}
	else
	SiscomLog("No se encontro la operacion");
}

void OperacionesSistemaGeneral(SSiscomOperaciones **pSSiscomOp)
{
	SiscomIniciaOperaciones(4,pSSiscomOp);
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

SiscomAnexaOperacion2("RegistraEmpresa2",
		      OPRegistraEmpresa2(),

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
SiscomAnexaOperacion2("RegistraEmpleado",
		      OPRegistraEmpleado(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraClienteFisica",
		      ORegistraClienteFisica(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraDireccion",
                      OPSiscomAplicacionesRegistraDireccion(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraMedioComunicacion",
		      OPSiscomAplicacionesRegistraMedioComunicacion(),
		      pSSOperaciones2);


SiscomAnexaOperacion2("AsignaAsesor",
		      OAsignaAsesor(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraPedido",
		      ORegistraPedido(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("PedidoEntregado",
		      OPedidoEntregado(),
		      pSSOperaciones2);

SiscomAnexaOperacion2("RegistraPaquete",
		      ORegistraPaquete(),
		      pSSOperaciones2);

SiscomAnexaOperacion2("ProductosAlPaquete",
		      OProductosPaquete(),
		      pSSOperaciones2);

SiscomAnexaOperacion2("EliminaProductoPaquete",
		      OEliminaProductoPaquete(),
		      pSSOperaciones2);

SiscomAnexaOperacion2("AnexarProductoPaquete",
		      OAnexarProductoPaquete(),
		      pSSOperaciones2);

SiscomAnexaOperacion2("EliminaPaquete",
		      OEliminaPaquete(),
		      pSSOperaciones2);


SiscomAnexaOperacion2("RegistraPropietarioVehiculo",
		      ORegistraPropietarioVehiculo(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraResponsableVehiculo",
		      ORegistraResponsableVehiculo(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("EmpresaRegistrada",
		      OpEmpresaRegistrada(),
		      pSSOperaciones2);


SiscomAnexaOperacion2("AnexaDireccion",
		      OpAnexaDireccion(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraDireccion2",
		      ORegistraDireccion2(),
		      pSSOperaciones2);
}
void SiscomErrorOperacion2(SArgsSiscom *pSAgsSisPtr)
{
SiscomLog("Operacion No Soportada");
}

