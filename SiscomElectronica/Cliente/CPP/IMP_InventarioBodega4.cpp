#include <IMP_InventarioBodega4.h>
#include <zSiscomConexion.h>

#include <zBodega.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomElectronica.h>
QInventarioBodega4::QInventarioBodega4(zSiscomConexion *pzSisConexion,
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				QtInventarioBodega4(pQWParent,pchrPtrName,pWFlags)
{
 QtInventarioBodega4::Argumentos(pchrPtrArgumentos);
 QtInventarioBodega4::Conexion(pzSisConexion);
 QtInventarioBodega4::IniciaVariables();
}

QInventarioBodega4::~QInventarioBodega4()
{

}
void QInventarioBodega4::Bodega(zBodega *pzBodega)
{
   QtInventarioBodega4::Bodega(pzBodega); 
}
void QInventarioBodega4::ConsultandoExistencia()
{
zSiscomElectronica lzSisElectronica(Conexion(),"ExistenciaBodega4");
lzSisElectronica.ExistenciaBodega(QtInventarioBodega4::ExistenciaBodega());
}
void QInventarioBodega4::Actualizando()
{
zSiscomElectronica lzSisElectronica(Conexion(),"ActualizaExistenciaBodega4");
lzSisElectronica.ActualizaExistenciaBodega(QtInventarioBodega4::ExistenciaBodega());

}
void QInventarioBodega4::setFocus()
{
  QtInventarioBodega4::FocoAProductos(); 
}
