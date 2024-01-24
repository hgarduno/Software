#include <zEmpresas.h>
#include <zEmpresa.h>
zEmpresas::zEmpresas()
{

}

zEmpresas &zEmpresas::operator<<(zEmpresa *pzEmpresa)
{
   Agrega(pzEmpresa);
   return *this;
}
