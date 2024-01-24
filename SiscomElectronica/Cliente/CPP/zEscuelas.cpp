#include <zEscuelas.h>
#include <zEscuela.h>
zEscuelas::zEscuelas()
{

}
zEscuelas &zEscuelas::operator<<(zEscuela *pzEscuela)
{
 Agrega( pzEscuela);
  return *this;

}

