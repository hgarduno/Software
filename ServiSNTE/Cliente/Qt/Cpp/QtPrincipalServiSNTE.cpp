#include <QtPrincipalServiSNTE.h>
#include <QtImpAccesoServiSNTE.h>
#include <QtImpActualizandoSistema.h>
#include <QtSiscomServiSNTE.h>
#include <zSiscomMenusVentana.h>
#include <zSiscomMenus.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomConexion.h>
#include <zSiscomLineaComandos.h>

#include <zSiscomAdministracionSeguridad.h>
#include <qapplication.h>
#include <qfont.h>

#include <stdio.h>
#include <stdlib.h>

FILE *gPtrFleArchivoLog;
void *gzSiscomConexion;
/* Mexico DF Sabado 3 de octurbre del 2015
 * Se debe considerar una variable global 
 * que almacena toda la informacion de la estacion
 * de trabajo, tienda, ip , quien se firma etc etc ...
 */
int main(int pintArgc,
	 char **pchrPtrArgv)

{
QApplication lQAQt3SiscomServiSNTE(pintArgc,pchrPtrArgv);
QtSiscomServiSNTE *lQt3SiscomServiSNTE;
QFont lQFTipoLetra;
zSiscomMenusVentana lzSisMenusVentana;
char lchrArrDirIp[25];
int lintPuerto;
gPtrFleArchivoLog=AbreArchivoLog();
zSiscomLineaComandos lzSisLineaComandos(pintArgc,pchrPtrArgv);
SiscomRegistrosLog(&lzSisLineaComandos);
SeReAsignanLibraryPaths(&lzSisLineaComandos,&lQAQt3SiscomServiSNTE);
fflush(stdout);
ComunicacionServidor(&lzSisLineaComandos,lchrArrDirIp,&lintPuerto);
gzSiscomConexion=(void *)new zSiscomConexion(lchrArrDirIp,lintPuerto);
//VerificandoActualizacionDisponible();
FirmandoteAlSistema(&lzSisMenusVentana,&lQFTipoLetra);
lQt3SiscomServiSNTE=new QtSiscomServiSNTE((zSiscomConexion *)gzSiscomConexion,&lzSisMenusVentana);
QObject::connect(&lQAQt3SiscomServiSNTE,
		 SIGNAL(lastWindowClosed()),
		 &lQAQt3SiscomServiSNTE,
		 SLOT(quit()));
lQAQt3SiscomServiSNTE.setFont(lQFTipoLetra,true);
CargaVentana(pintArgc,pchrPtrArgv,lQt3SiscomServiSNTE);
return lQAQt3SiscomServiSNTE.exec();
}
FILE *AbreArchivoLog()
{
const char *lchrPtrUsuario=getenv("LOGNAME");
const char *lchrPtrHome=getenv("HOME");
char lchrArrArchivo[1024];
sprintf(lchrArrArchivo,"%s/ServiSNTE.%s.Log",lchrPtrHome,lchrPtrUsuario);
FILE *lFlePtrArchivo=fopen(lchrArrArchivo,"a");
if(lFlePtrArchivo)
return lFlePtrArchivo;
else
return stdout;

}
void AgregaPropiedadesPopupMenu(zSiscomRegistro *pzSisRegPopupMenu,
				zSiscomMenu *pzSiscomMenuPopup)
{
zSiscomRegistros *lzSisRegsPropiedades=pzSisRegPopupMenu->AsociadosDelCampo("Propiedades");
zSiscomRegistro *lzSisRegPropiedad;
SiscomRegistrosLog(lzSisRegsPropiedades);
for(lzSisRegPropiedad=lzSisRegsPropiedades->Primer();
    lzSisRegPropiedad;
    lzSisRegPropiedad=lzSisRegsPropiedades->Siguiente())
    pzSiscomMenuPopup->Propiedad((const char *)(*lzSisRegPropiedad)["Nombre"],
    				 (const char *)(*lzSisRegPropiedad)["Valor"]);
}
void AgregaPropiedadesQAction(zSiscomRegistros *pzSisRegsPropiedades,zSiscomMenu *pzSiscomMenu)
{
zSiscomRegistro *lzSisRegPropiedad;
for(lzSisRegPropiedad=pzSisRegsPropiedades->Primer();
    lzSisRegPropiedad;
    lzSisRegPropiedad=pzSisRegsPropiedades->Siguiente())
        pzSiscomMenu->Propiedad((const char *)(*lzSisRegPropiedad)["Nombre"],(const char *)(*lzSisRegPropiedad)["Valor"]);
}
		
void AgregaMenusAlPopupMenu(zSiscomRegistro *pzSisRegPopupMenu,
			    zSiscomMenus *pzSisMenus)
{
zSiscomRegistros *lzSisRegsMenus=pzSisRegPopupMenu->AsociadosDelCampo("Menus");
zSiscomRegistro *lzSisRegMenu;
zSiscomMenu *lzSisMenu;
for(lzSisRegMenu=lzSisRegsMenus->Primer();
    lzSisRegMenu;
    lzSisRegMenu=lzSisRegsMenus->Siguiente())
{
      lzSisMenu=new zSiscomMenu((const char *)(*lzSisRegMenu)["QAction"],(const char *)(*lzSisRegMenu)["Modulo"]);
      AgregaPropiedadesQAction(lzSisRegMenu->AsociadosDelCampo("Propiedades"),lzSisMenu);
      (*pzSisMenus) << lzSisMenu;
}
}
void FirmandoteAlSistema(zSiscomMenusVentana *pzSisMenusVentana,	
			 QFont *pQFTipoLetra)
{
zSiscomRegistros *lzSisRegsMenusSistema;
zSiscomRegistro *lzSisRegPopupMenu;
zSiscomMenu *lzSiscomMenuPopup;
zSiscomMenus *lzSisMenusSistema;
QtImpAccesoServiSNTE lQtImpAccesoServiSNTE;
lzSisRegsMenusSistema=lQtImpAccesoServiSNTE.MenusSistema();
if(lQtImpAccesoServiSNTE.Aceptar(pQFTipoLetra))
{

for(lzSisRegPopupMenu=lzSisRegsMenusSistema->Primer();
    lzSisRegPopupMenu;
    lzSisRegPopupMenu=lzSisRegsMenusSistema->Siguiente())
{
    LogSiscom("%s",(const char *)(*lzSisRegPopupMenu)["Nombre"]);
    lzSiscomMenuPopup=new zSiscomMenu((const char *)(*lzSisRegPopupMenu)["Nombre"]);
    AgregaPropiedadesPopupMenu(lzSisRegPopupMenu,lzSiscomMenuPopup);
    lzSisMenusSistema=new zSiscomMenus(lzSiscomMenuPopup);
    AgregaMenusAlPopupMenu(lzSisRegPopupMenu,lzSisMenusSistema);
    (*pzSisMenusVentana) << lzSisMenusSistema;
}
}
else
exit(0);
}
/*
void CreaMenusVentana(zSiscomMenusVentana *pzSisMenusVentana)
{
  (*pzSisMenusVentana) << Administracion();
}

zSiscomMenus *Administracion()
{
zSiscomMenu *lzSisMenuProveedores=new zSiscomMenu("QAProveedores","QtImpProveedores"),
	    *lzSisMenuCapturaProductos=new zSiscomMenu("QACapturaProductos","QtImpCapturaProductos"),
	    *lzSisMenuCargaNominaEmpleados=new zSiscomMenu("QACargaNominaEmpleados","QtImpCargaNominaEmpleados"),
	    *lzSisMenuCargaBaseDeDatosMaestros=new zSiscomMenu("QACargaBaseDeDatosMaestros","QtImpCargaBaseDeDatosMaestros"),
	    *lzSisMenuCapturaCliente=new zSiscomMenu("QACapturaCliente","QtImpCapturaCliente"),
	    *lzSisMenuCapturaCamiones=new zSiscomMenu("QACapturaCamiones","QtImpCapturaCamiones"),
	    *lzSisMenuCapturaChoferes=new zSiscomMenu("QACapturaChoferes","QtImpCapturaChoferes"),
	    *lzSisMenuCapturaVendedores=new zSiscomMenu("QACapturaVendedores","QtImpCapturaVendedores"),
	    *lzSisMenuCapturaConceptosExistencias=new zSiscomMenu("QACapturaConceptosExistencias","QtImpCapturaConceptosExistencias"),
	    *lzSisMenuCapturaDireccion=new zSiscomMenu("QACapturaDireccion","QtImpCapturaDireccion"),
	    *lzSisMenuCapturaTienda=new zSiscomMenu("QACapturaTienda","QtImpCapturaTienda"),
	    *lzSisMenuCapturaDepartamentos=new zSiscomMenu("QACapturaDepartamentos","QtImpCapturaDepartamentos"),
	    *lzSisMenuPuntoDeVenta=new zSiscomMenu("QAPuntoDeVenta","QtImpPuntoDeVenta"),
	    *lzSisMenuRegistroCompras=new zSiscomMenu("QARegistroCompras","QtImpRegistroCompras"),
	    *lzSisMenuImpresionCodigoBarras=new zSiscomMenu("QAImpresionCodigoBarras","QtImpImpresionCodigoBarras"),
	    *lzSisMenuCapturaInventario=new zSiscomMenu("QACapturaInventario","QtImpCapturaInventario"),
	    *lzSisMenuCapturaInventarioAlmacen=new zSiscomMenu("QACapturaInventarioAlmacen","QtImpCapturaInventarioAlmacen"),
	    *lzSisMenuTransferenciaAlmacen=new zSiscomMenu("QATransferenciaAlmacen","QtImpTransferenciaAlmacen"),
	    *lzSisMenuReporteVentas=new zSiscomMenu("QAReporteVentas","QtImpReporteVentas"),
	    *lzSisMenuVisorTransferencias=new zSiscomMenu("QAVisorTransferencias","QtImpVisorTransferencias"),
	    *lzSisMenuAbonosApartado=new zSiscomMenu("QAAbonosApartado","QtImpAbonosApartado"),
	    *lzSisMenuBeneficiosIntegrales=new zSiscomMenu("QABeneficiosIntegrales","QtImpBeneficiosIntegrales"),
	    *lzSisMenuRecibirTransferencias=new zSiscomMenu("QARecibirTransferencias","QtImpRecibirTransferencias"),
	    *lzSisMenuControlReplicas=new zSiscomMenu("QAControlReplicas","QtImpControlReplicas"),
	    *lzSisMenuCatalogoStock=new zSiscomMenu("QACatalogoStock","QtImpCatalogoStock"),
	    *lzSisMenuFijaFechaCompra=new zSiscomMenu("QAFijaFechaCompra","QtImpFijaFechaCompra"),
	    *lzSisMenuPopMenu;
zSiscomMenus *lzSisMenus;

//Asignacion de Propiedades{
lzSisMenuProveedores->Propiedad("text","Captura Cita");
lzSisMenuProveedores->Propiedad("visible","true");
lzSisMenuProveedores->Propiedad("enabled","true");

lzSisMenuCapturaProductos->Propiedad("text","Captura Productos");
lzSisMenuCapturaProductos->Propiedad("visible","true");
lzSisMenuCapturaProductos->Propiedad("enabled","true");

lzSisMenuCapturaDireccion->Propiedad("text","Captura de Direccion");
lzSisMenuCapturaDireccion->Propiedad("visible","true");
lzSisMenuCapturaDireccion->Propiedad("enabled","true");

lzSisMenuCapturaCliente->Propiedad("text","Captura de Cliente");
lzSisMenuCapturaCliente->Propiedad("visible","true");
lzSisMenuCapturaCliente->Propiedad("enabled","true");

lzSisMenuCapturaCamiones->Propiedad("text","Captura de Camiones");
lzSisMenuCapturaCamiones->Propiedad("visible","true");
lzSisMenuCapturaCamiones->Propiedad("enabled","true");

lzSisMenuCapturaChoferes->Propiedad("text","Captura de Choferes");
lzSisMenuCapturaChoferes->Propiedad("visible","true");
lzSisMenuCapturaChoferes->Propiedad("enabled","true");

lzSisMenuCapturaVendedores->Propiedad("text","Captura de Vendedores");
lzSisMenuCapturaVendedores->Propiedad("visible","true");
lzSisMenuCapturaVendedores->Propiedad("enabled","true");

lzSisMenuCargaNominaEmpleados->Propiedad("text","Carga Nomina Empleados");
lzSisMenuCargaNominaEmpleados->Propiedad("visible","true");
lzSisMenuCargaNominaEmpleados->Propiedad("enabled","true");

lzSisMenuCargaBaseDeDatosMaestros->Propiedad("text","Carga Base de Datos Maestros");
lzSisMenuCargaBaseDeDatosMaestros->Propiedad("visible","true");
lzSisMenuCargaBaseDeDatosMaestros->Propiedad("enabled","true");

lzSisMenuCapturaConceptosExistencias->Propiedad("text","Captura de Conceptos de Existencias");
lzSisMenuCapturaConceptosExistencias->Propiedad("visible","true");
lzSisMenuCapturaConceptosExistencias->Propiedad("enabled","true");

lzSisMenuCapturaTienda->Propiedad("text","Captura de Tiendas");
lzSisMenuCapturaTienda->Propiedad("visible","true");
lzSisMenuCapturaTienda->Propiedad("enabled","true");

lzSisMenuCapturaDepartamentos->Propiedad("text","Captura de Departamentos");
lzSisMenuCapturaDepartamentos->Propiedad("visible","true");
lzSisMenuCapturaDepartamentos->Propiedad("enabled","true");

lzSisMenuPuntoDeVenta->Propiedad("text","Punto de Venta");
lzSisMenuPuntoDeVenta->Propiedad("visible","true");
lzSisMenuPuntoDeVenta->Propiedad("enabled","true");

lzSisMenuRegistroCompras->Propiedad("text","Registro de Compras");
lzSisMenuRegistroCompras->Propiedad("visible","true");
lzSisMenuRegistroCompras->Propiedad("enabled","true");

lzSisMenuImpresionCodigoBarras->Propiedad("text","Impresion Codigo Barras");
lzSisMenuImpresionCodigoBarras->Propiedad("visible","true");
lzSisMenuImpresionCodigoBarras->Propiedad("enabled","true");

lzSisMenuCapturaInventario->Propiedad("text","Captura Inventario");
lzSisMenuCapturaInventario->Propiedad("visible","true");
lzSisMenuCapturaInventario->Propiedad("enabled","true");

lzSisMenuCapturaInventarioAlmacen->Propiedad("text","Captura Inventario Almacen");
lzSisMenuCapturaInventarioAlmacen->Propiedad("visible","true");
lzSisMenuCapturaInventarioAlmacen->Propiedad("enabled","true");


lzSisMenuTransferenciaAlmacen->Propiedad("text","Transfiere Almacen");
lzSisMenuTransferenciaAlmacen->Propiedad("visible","true");
lzSisMenuTransferenciaAlmacen->Propiedad("enabled","true");

lzSisMenuReporteVentas->Propiedad("text","Reporte Ventas");
lzSisMenuReporteVentas->Propiedad("visible","true");
lzSisMenuReporteVentas->Propiedad("enabled","true");

lzSisMenuVisorTransferencias->Propiedad("text","Visor Transferencias");
lzSisMenuVisorTransferencias->Propiedad("visible","true");
lzSisMenuVisorTransferencias->Propiedad("enabled","true");

lzSisMenuAbonosApartado->Propiedad("text","Abonos Apartado");
lzSisMenuAbonosApartado->Propiedad("visible","true");
lzSisMenuAbonosApartado->Propiedad("enabled","true");

lzSisMenuBeneficiosIntegrales->Propiedad("text","Contrato Beneficios Integrales");
lzSisMenuBeneficiosIntegrales->Propiedad("visible","true");
lzSisMenuBeneficiosIntegrales->Propiedad("enabled","true");

lzSisMenuRecibirTransferencias->Propiedad("text","Recibir Transferencias");
lzSisMenuRecibirTransferencias->Propiedad("visible","true");
lzSisMenuRecibirTransferencias->Propiedad("enabled","true");

lzSisMenuControlReplicas->Propiedad("text","Control Replicas");
lzSisMenuControlReplicas->Propiedad("visible","true");
lzSisMenuControlReplicas->Propiedad("enabled","true");

lzSisMenuCatalogoStock->Propiedad("text","Catalogo Stock");
lzSisMenuCatalogoStock->Propiedad("visible","true");
lzSisMenuCatalogoStock->Propiedad("enabled","true");

lzSisMenuFijaFechaCompra->Propiedad("text","Fija Fecha Compra");
lzSisMenuFijaFechaCompra->Propiedad("visible","true");
lzSisMenuFijaFechaCompra->Propiedad("enabled","true");
//}

lzSisMenuPopMenu=new zSiscomMenu("QPopupMenuAdminProductos");
lzSisMenuPopMenu->Propiedad("text","Administracion Servi SNTE");
lzSisMenuPopMenu->Propiedad("visible","true");
lzSisMenuPopMenu->Propiedad("enabled","false");


lzSisMenus=new zSiscomMenus(lzSisMenuPopMenu);
//Asignacion de los menus {
(*lzSisMenus) 						<< 
		lzSisMenuProveedores			    <<
		lzSisMenuCapturaProductos		    <<
		lzSisMenuCargaNominaEmpleados		<<
		lzSisMenuCargaBaseDeDatosMaestros   <<
		lzSisMenuCapturaDireccion		    <<
		lzSisMenuCapturaCliente			    <<
		lzSisMenuCapturaCamiones		    <<
		lzSisMenuCapturaChoferes		    <<
		lzSisMenuCapturaVendedores		    <<
		lzSisMenuCapturaConceptosExistencias	<<
		lzSisMenuCapturaTienda			    <<
		lzSisMenuCapturaDepartamentos		<<
		lzSisMenuPuntoDeVenta			    <<
		lzSisMenuRegistroCompras		    <<
		lzSisMenuImpresionCodigoBarras		<<
		lzSisMenuCapturaInventario		    <<
		lzSisMenuCapturaInventarioAlmacen	<<
		lzSisMenuTransferenciaAlmacen		<<
		lzSisMenuReporteVentas             	<<
		lzSisMenuVisorTransferencias	 	<<
		lzSisMenuAbonosApartado			    <<
		lzSisMenuBeneficiosIntegrales       <<
		lzSisMenuRecibirTransferencias      <<
		lzSisMenuControlReplicas            <<
        	lzSisMenuCatalogoStock			<<
        	lzSisMenuFijaFechaCompra ;
//}
LogSiscom("Se tienen %d Registros",lzSisMenus->NNodos());
return lzSisMenus;
}
*/
void ComunicacionPorArgumentos(zSiscomLineaComandos *pzSisLineaComandos,
		       	      char *pchrPtrDirIp,
		       	      int *pintPtrPuerto)
{
strcpy(pchrPtrDirIp,(const char *)(*pzSisLineaComandos)["DirIp"]);
*pintPtrPuerto=atoi((const char *)(*pzSisLineaComandos)["Puerto"]);
}
void ComunicacionPorVariablesAmbiente(char *pchrPtrDirIp,
				      int *pintPtrPuerto)
{
strcpy(pchrPtrDirIp,getenv("IpServidor"));
*pintPtrPuerto=atoi(getenv("PuertoServidor"));
}
void ComunicacionServidor(zSiscomLineaComandos *pzSisLineaComandos,
			  char *pchrPtrDirIp,
			  int *pintPtrPuerto)
{
 if(!(*pzSisLineaComandos)["DirIp"] &&
    !(*pzSisLineaComandos)["Puerto"])
  ComunicacionPorVariablesAmbiente(pchrPtrDirIp,pintPtrPuerto);
else
ComunicacionPorArgumentos(pzSisLineaComandos,pchrPtrDirIp,pintPtrPuerto);
}

void MuestraLibraryPaths(QApplication *pQAppPrincipal)
{
QStringList lQStrLstPath=pQAppPrincipal->libraryPaths();
QString lQStrCadena;
int lintContador;
for(lintContador=0;
    lintContador<lQStrLstPath.count();
    lintContador++)
{
LogSiscom("%d.-  %s ",lintContador,(const char *)lQStrLstPath[lintContador]);
}	
}
void EliminaLibraryPaths(QApplication *pQAppPrincipal)
{
QStringList lQStrLstPath=pQAppPrincipal->libraryPaths();
QString lQStrCadena;
int lintContador;
LogSiscom("");
for(lintContador=0;
    lintContador<lQStrLstPath.count();
    lintContador++)
    pQAppPrincipal->removeLibraryPath(lQStrLstPath[lintContador]);
}
void AsignaLibraryPaths(QApplication *pQAppPrincipal,
			char **pchrPtrArgv)
{
   while(*pchrPtrArgv)
   {
	pQAppPrincipal->addLibraryPath(*pchrPtrArgv);
	pchrPtrArgv++;
   }
}
void SeReAsignanLibraryPaths(zSiscomLineaComandos *pzSisLineaComandos,
			    QApplication *pQAppPrincipal)
{
zSiscomRegistro *lzSisRegComando;
int lintContador=0;
SiscomRegistrosLog(pzSisLineaComandos);
for(lzSisRegComando=pzSisLineaComandos->Primer();
    lzSisRegComando;
    lzSisRegComando=pzSisLineaComandos->Siguiente(),
    lintContador++)
{
   LogSiscom("La ruta:%s",lzSisRegComando->Campo("Opcion")); 
   if(!strcmp("Ruta",(const char *)lzSisRegComando->Campo("Opcion")))
   {
     if(!lintContador)
	 EliminaLibraryPaths(pQAppPrincipal);
     pQAppPrincipal->addLibraryPath((const char *)lzSisRegComando->Campo("Argumento"));
    }
}
   MuestraLibraryPaths(pQAppPrincipal);
}


int SeMaximiza(int pintArgc,
	       char **pchrPtrArgv)
{
int lintContador;
   for(lintContador=0;
       lintContador<pintArgc;
       lintContador++)
	 if(strstr(*(pchrPtrArgv+lintContador),"Maximizada"))
	  return 1;
return 0;
}

void CargaVentana(int pintArgc,
		   char **pchrPtrArgv,
		   QtSiscomServiSNTE *pQt3SiscomServiSNTE)
{
const char *lchrPtrMaximizada=getenv("Maximizada");
    if(lchrPtrMaximizada)
    pQt3SiscomServiSNTE->showMaximized();
    else
    pQt3SiscomServiSNTE->show();
}

void VerificandoActualizacionDisponible()
{
QtImpActualizandoSistema lQtImpActSistema;
}
