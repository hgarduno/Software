#include <zPractica.h>
#include <zSiscomCampo.h>
#include <zSiscomRegistros.h>
#include <zSiscomDesarrollo4.h>

zPractica::zPractica():intDatosPractica(0)
{
   (*this) 				<<
   new zSiscomCampo("Producto")		<< /* Es el producto que se registro en la tabla productos */
   new zSiscomCampo("Nombre")		<<
   new zSiscomCampo("Materia")		<<
   new zSiscomCampo("Escuela")		<<
   new zSiscomCampo("Profesor")		<<
   new zSiscomCampo("Productos");
}
void zPractica::Producto(zSiscomRegistro *pzSisRegProducto)
{
	AsociadoAlCampo("Producto",pzSisRegProducto);
}
void zPractica::Nombre(const char *pchrPtrNombre)
{
    ActualizaCampo("Nombre",(const unsigned char *)pchrPtrNombre);
}
void zPractica::Materia(const char *pchrPtrMateria)
{
	ActualizaCampo("Materia",(const unsigned char *)pchrPtrMateria);
}

void zPractica::Escuela(zSiscomRegistro *pzSisRegEscuela)
{
	AsociadoAlCampo("Escuela",pzSisRegEscuela);
}

void zPractica::Productos(zSiscomRegistros *pzSisRegsProductos)
{
	AsociadosAlCampo("Productos",pzSisRegsProductos);
}
zSiscomRegistros *zPractica::Productos()
{
   return AsociadosDelCampo("Productos");
}
void zPractica::HayDatosPractica(zSiscomRegistro *pzSisRegPractica)
{
    intDatosPractica=pzSisRegPractica->AsociadoDelCampo("Practica") ? 1 : 0;
}
void zPractica::HayDatosProfesor(zSiscomRegistro *pzSisRegPractica)
{
   intDatosProfesor=pzSisRegPractica->AsociadoDelCampo("Profesor") ? 1 :0;
}
void zPractica::Practica(zSiscomRegistro *pzSisRegPractica)
{
    AsociadosAlCampo("Productos",pzSisRegPractica->AsociadosDelCampo("DefProducto"));  
    HayDatosPractica(pzSisRegPractica);
    HayDatosProfesor(pzSisRegPractica);
    
}
int zPractica::DatosProfesor()
{
  return intDatosProfesor;
}
int zPractica::DatosPractica()
{
   return intDatosPractica;
}
