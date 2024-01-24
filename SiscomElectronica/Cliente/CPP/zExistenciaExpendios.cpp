#include <zExistenciaExpendios.h>

zExistenciaExpendios::zExistenciaExpendios()
{


}
void zExistenciaExpendios::Productos(zSiscomRegistros *pzSisRegsProductos)
{
    (*this)=*((zExistenciaExpendios *)(pzSisRegsProductos));
}
