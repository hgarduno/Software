#include <zSiscomMenu.h>
#include <zSiscomMenus.h>
#include <zSiscomCampo.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistros.h>
#include <zSiscomMenusVentana.h>
#include <ClasesMenus.h>
#include <zPruebas.h>
#include <stdio.h>

#include <qapplication.h>
#include <qwidgetfactory.h>
#include <qworkspace.h>
#include <qvbox.h>

FILE *gPtrFleArchivoLog;
void *gzSiscomConexion;



int main(int pintArgc,
	 char **pchrPtrArgv)
{
gPtrFleArchivoLog=stdout;
QApplication::addLibraryPath("/home/hgarduno/SiscomDesarrollo/Software/Probando/PantallasPruebas");
QApplication lQAVentanaPrueba(pintArgc,
			      pchrPtrArgv);
zSiscomMenusVentana lzSisMenusVentana;
CreaMenusVentana(&lzSisMenusVentana);
zVentanaPrueba *lzVenPrueba=new zVentanaPrueba(&lzSisMenusVentana);
lzVenPrueba->show();
return lQAVentanaPrueba.exec();
}

zVentanaPrueba::zVentanaPrueba(zSiscomMenusVentana *pzSisMenusVentana):
		  zSiscomVentana()
{
   Menus(pzSisMenusVentana);
   MuestraMenus();
   AreaTrabajo();
   ClasePrueba(); 
   ListaLibraryPaths();

}
void zVentanaPrueba::ListaLibraryPaths()
{
QStringList lQStrLstPaths=QApplication::libraryPaths();
int lintContador;
for(lintContador=0; 
    lintContador<lQStrLstPaths.count();
    lintContador++)
printf("%s\n",(const char *)lQStrLstPaths[lintContador]);

}
void zVentanaPrueba::ClasePrueba()
{
QWidgetFactory lQWFCarga;
QStringList lQStrLstWidgets;
int lintContador;
/*
lQStrLstWidgets=lQWFCarga.widgets();
for(lintContador=0; 
    lintContador<lQStrLstWidgets.count();
    lintContador++)
 printf("%s\n",(const char *)lQStrLstWidgets[lintContador]);
 QWidget *lQWCargando;
 lQWCargando=lQWFCarga.createWidget("zPruebas",QWSATrabajo,"Nada");
 if(lQWCargando)
 lQWCargando->show();
 else
 {
     printf("No se encontro\n");
 }
 */
}
void zVentanaPrueba::AreaTrabajo()
{
QVBox* vb = new QVBox( this );
vb->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );
QWSATrabajo = new QWorkspace( vb ,"QWSAreaTrabajo");
QWSATrabajo->setScrollBarsEnabled( TRUE ); setCentralWidget( vb );
zSiscomVentana::AreaTrabajo(QWSATrabajo);
}
zSiscomMenus *Administracion()
{
zSiscomMenu *lzSisMenuPuVenta,
	    *lzSisMenuCompras,
	    *lzSisMenuTraspasos,
	    *lzSisMenuPopMenu;

zSiscomMenus *lzSisMenus;
lzSisMenuPuVenta=new zSiscomMenu("QAPuVenta","zPruebas");
lzSisMenuCompras=new zSiscomMenu("QACompras");
lzSisMenuTraspasos=new zSiscomMenu("QATraspasos");

lzSisMenuPuVenta->Propiedad("text","Punto de Venta");
lzSisMenuPuVenta->Propiedad("visible","true");
lzSisMenuPuVenta->Propiedad("enabled","true");

lzSisMenuCompras->Propiedad("text","Compras");
lzSisMenuCompras->Propiedad("visible","true");
lzSisMenuCompras->Propiedad("enabled","true");


lzSisMenuTraspasos->Propiedad("text","Traspasos");
lzSisMenuTraspasos->Propiedad("visible","true");
lzSisMenuTraspasos->Propiedad("enabled","true");

lzSisMenuPopMenu=new zSiscomMenu("QPopupMenuAdministracion");
lzSisMenuPopMenu->Propiedad("text","Administracion");
lzSisMenuPopMenu->Propiedad("visible","true");
lzSisMenuPopMenu->Propiedad("enabled","true");

lzSisMenus=new zSiscomMenus(lzSisMenuPopMenu);
(*lzSisMenus) << lzSisMenuPuVenta << lzSisMenuCompras << lzSisMenuTraspasos;
return lzSisMenus;
}
zSiscomMenus *Registros()
{
zSiscomMenu *lzSisMenuRegCliente=new zSiscomMenu("QARegCliente"),
	    *lzSisMenuRegPromocion=new zSiscomMenu("QARegPromocion"),
	    *lzSisMenuRegPuntos=new zSiscomMenu("QARegPuntos"),
	    *lzSisMenuPopMenu;

zSiscomMenus *lzSisMenus;

lzSisMenuRegCliente->Propiedad("text","Registro Cliente");
lzSisMenuRegCliente->Propiedad("visible","true");
lzSisMenuRegCliente->Propiedad("enabled","true");

lzSisMenuRegPromocion->Propiedad("text","Registra Promocion");
lzSisMenuRegPromocion->Propiedad("visible","true");
lzSisMenuRegPromocion->Propiedad("enabled","true");

lzSisMenuRegPuntos->Propiedad("text","Registra Puntos");
lzSisMenuRegPuntos->Propiedad("visible","true");
lzSisMenuRegPuntos->Propiedad("enabled","true");

lzSisMenuPopMenu=new zSiscomMenu("QPopupMenuRegistros");
lzSisMenuPopMenu->Propiedad("text","Registros");
lzSisMenuPopMenu->Propiedad("visible","true");
lzSisMenuPopMenu->Propiedad("enabled","false");

lzSisMenus=new zSiscomMenus(lzSisMenuPopMenu);
(*lzSisMenus) << lzSisMenuRegCliente << lzSisMenuRegPromocion<< lzSisMenuRegPuntos;
return lzSisMenus;
}
zSiscomMenus *Reportes()
{
zSiscomMenu *lzSisMenuReporteVentas=new zSiscomMenu("QAReporteVentas"),
	    *lzSisMenuReporteCompras=new zSiscomMenu("QAReporteCompras"),
	    *lzSisMenuReporteClientes=new zSiscomMenu("QAReporteClientes"),
	    *lzSisMenuReporteGastos=new zSiscomMenu("QAReporteGastos") ,
	    *lzSisMenuPopMenu;

zSiscomMenus *lzSisMenus;


lzSisMenuReporteVentas->Propiedad("text","Reporte de ventas");
lzSisMenuReporteVentas->Propiedad("visible","true");
lzSisMenuReporteVentas->Propiedad("enabled","false");

lzSisMenuReporteCompras->Propiedad("text","Reporte de compras");
lzSisMenuReporteCompras->Propiedad("visible","true");
lzSisMenuReporteCompras->Propiedad("enabled","false");

lzSisMenuReporteClientes->Propiedad("text","Reporte ventas por cliente");
lzSisMenuReporteClientes->Propiedad("visible","true");
lzSisMenuReporteClientes->Propiedad("enabled","false");

lzSisMenuReporteGastos->Propiedad("text","Puntos por cliente");
lzSisMenuReporteGastos->Propiedad("visible","true");
lzSisMenuReporteGastos->Propiedad("enabled","false");

lzSisMenuPopMenu=new zSiscomMenu("QPopupMenuReportes");
lzSisMenuPopMenu->Propiedad("text","Reportes ");
lzSisMenuPopMenu->Propiedad("visible","true");
lzSisMenuPopMenu->Propiedad("enabled","false");

lzSisMenus=new zSiscomMenus(lzSisMenuPopMenu);
(*lzSisMenus) << lzSisMenuReporteVentas << lzSisMenuReporteCompras << lzSisMenuReporteClientes << lzSisMenuReporteGastos;
return lzSisMenus;

}
void CreaMenusVentana(zSiscomMenusVentana *pzSisMenusVentana)
{
(*pzSisMenusVentana) 		<< 
	Administracion()	<<
	Registros()		<<
	Reportes();
}
/*
void PruebasMenus()
{
zSiscomMenu lzSisMenuPba("QAPuntoVenta"),
	    lzSisMenuPba2("QACompras"),
	    lzSisMenuPba3("QATraspasos");

zSiscomMenus lzSisMenusAdmin;
zSiscomRegistros *lzSisRegsPropiedades;
gPtrFleArchivoLog=stdout;
SiscomRegistroLog2(&lzSisMenuPba);
lzSisMenuPba.Propiedad("text","Punto De Venta");
lzSisMenuPba.Propiedad("visible","enable");
lzSisMenuPba.Propiedad("enabled","false");


lzSisMenuPba2.Propiedad("text","Compras");
lzSisMenuPba2.Propiedad("visible","enable");
lzSisMenuPba2.Propiedad("enabled","false");


lzSisMenuPba3.Propiedad("text","Traspasos");
lzSisMenuPba3.Propiedad("visible","enable");
lzSisMenuPba3.Propiedad("enabled","false");



zSiscomCampo lzSisCampoBusca("Propiedades",0);
zSiscomCampo *lzSisCamPropiedades;
lzSisCamPropiedades=lzSisMenuPba.Nodo(lzSisCampoBusca);
SiscomRegistrosLog(lzSisCamPropiedades->Asociados());
lzSisMenusAdmin << &lzSisMenuPba << &lzSisMenuPba2 << &lzSisMenuPba3;
SiscomRegistrosLog(&lzSisMenusAdmin);
}
*/

