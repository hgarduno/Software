#include <zSiscomVentana.h>
#include <zSiscomMenusVentana.h>
#include <zSiscomRegistros.h>
#include <zSiscomMenus.h>
#include <zSiscomMenu.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQAction.h>
#include <zSiscomVentanaOpcion.h>
#include <zSiscomConexion.h>
#include <zSiscomModuloMenu.h>
#include <qpopupmenu.h>
#include <qmenubar.h>
#include <qwidgetfactory.h>
#include <qworkspace.h>
#include <qvbox.h>
#include <qlibrary.h>

/* Martes 16 de diciembre del 2014
 * Para el nuevo prototipo de la biblioteca de la clase
 * que gestionara la ventana principal, se tomara como 
 * base la informacion de una clase zSiscomRegistros
 * de la siguiente manera 
 *
 * Menu 
 *    ---> Propiedases  -> Texto
 *    		 	-> Enabled
 *    		 	-> Visible
 *    ---> Modulo -> libreria , Funcion
 *    ---> Imagen 
 *    ---> SubMenu ->
 *    		     Texto
 *    		     Modulo-> Libreria, Funcion
 *    		     Imagen
 *    		     SubMenu -> Texto
 *    		     	        Modulo Libreria,Funcion
 *    		     	        Imagen
 *    		     	        SubMenu
 *
 */
zSiscomVentana::zSiscomVentana(QWidget *pQWParent,
			       const char *pchrPtrName,
			       WFlags pWFlags):
			 QMainWindow(pQWParent,pchrPtrName,pWFlags)
{

}
zSiscomVentana::zSiscomVentana(zSiscomConexion *pzSisConexion,
				QWidget *pQWParent,
			       const char *pchrPtrName,
			       WFlags pWFlags):
			 QMainWindow(pQWParent,pchrPtrName,pWFlags),
			 zSisConexion(pzSisConexion)
{

}
void zSiscomVentana::Menus(zSiscomMenusVentana *pzSisMenusVentana)
{
  zSisMenusVentana=pzSisMenusVentana;
}
zSiscomQAction *zSiscomVentana::OpcionMenu(zSiscomMenu *pzSisMenu)
{
zSiscomQAction *lzSQAction=new zSiscomQAction(this,pzSisMenu);
connect(lzSQAction,
	SIGNAL(SignalSelecciono(zSiscomQAction *)),
	SLOT(SlotSelecciono(zSiscomQAction *)));
lzSQAction->AreaTrabajo(QWSAreaTrabajo);
return lzSQAction;
}
QPopupMenu *zSiscomVentana::FormaMenu(zSiscomMenus *pzSisMenus)
{
QPopupMenu *lQPopupMenu=new QPopupMenu(this,0);
zSiscomMenu *lzSisMenu;
SiscomRegistrosLog(pzSisMenus);
for(lzSisMenu=(zSiscomMenu *)pzSisMenus->Primer();
    lzSisMenu;
    lzSisMenu=(zSiscomMenu *)pzSisMenus->Siguiente())
{
    OpcionMenu(lzSisMenu)->addTo(lQPopupMenu);
    CargaModulo(lzSisMenu);
}

return lQPopupMenu;
}
void zSiscomVentana::MuestraMenus()
{
zSiscomMenus *lzSisMenus;
QPopupMenu *lQPopMenuDato;
for(lzSisMenus=zSisMenusVentana->Primer();
    lzSisMenus;
    lzSisMenus=zSisMenusVentana->Siguiente())
{
 menuBar()->insertItem(lzSisMenus->PropiedadPopupMenu("text"),
 			FormaMenu(lzSisMenus));
}

}

void zSiscomVentana::SlotSelecciono(zSiscomQAction *pzSisQAction)
{
 zSiscomVentanaOpcion *lzSisVenOpcion;
 zSiscomFuncionMenu lzSisFuncionMenu;
 /*
 if((lzSisVenOpcion=(zSiscomVentanaOpcion *)QWidgetFactory().createWidget(pzSisQAction->Menu()->Clase(),QWSAreaTrabajo,0)))
 {
    lzSisVenOpcion->Configuracion(zSisConfiguracion);
    lzSisVenOpcion->show();
 }
 */
  if((lzSisFuncionMenu=zSisModsMens.Funcion(pzSisQAction->Menu()->Clase(),
  					    pzSisQAction->Menu()->Funcion())))
  {
     lzSisVenOpcion=(zSiscomVentanaOpcion *)lzSisFuncionMenu(QWSAreaTrabajo,0);
     lzSisVenOpcion->show();
  }
  else
  LogSiscom("No Se encontro la funcion ");
}

void zSiscomVentana::AreaTrabajo(QWorkspace *pQWSAreaTrabajo)
{
   QWSAreaTrabajo=pQWSAreaTrabajo;
}
void zSiscomVentana::Configuracion(zSiscomConfiguracion *pzSisConfiguracion)
{
 zSisConfiguracion=pzSisConfiguracion; 
}

void zSiscomVentana::AreaTrabajo() 
{
QVBox* vb = new QVBox( this );
vb->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );
QWSAreaTrabajo = new QWorkspace( vb ,"QWSAreaTrabajo");
QWSAreaTrabajo->setScrollBarsEnabled( TRUE ); setCentralWidget( vb );
}

void zSiscomVentana::Conexion(zSiscomConexion *pzSisConexion)
{
  zSisConexion=pzSisConexion;
}
void zSiscomVentana::SlotInicioPantalla(zSiscomConexion *pzSisConexion)
{
printf("Ya inicio el control\n");
}
void zSiscomVentana::CargaModulo(zSiscomMenu *pzSisMenu)
{
QLibrary *lQLibModulo;
lQLibModulo=new QLibrary(pzSisMenu->Clase());
 SiscomRegistroLog2(pzSisMenu);
 if(lQLibModulo->load())
  zSisModsMens << new zSiscomModuloMenu(lQLibModulo,pzSisMenu->Clase());
 else
 LogSiscom("NO Se cargo el Modulo %s",pzSisMenu->Clase());
}
