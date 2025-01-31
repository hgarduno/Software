#include <zExistenciaExpendios.h>
#include <zSiscomDesarrollo4.h>
zExistenciaExpendios::zExistenciaExpendios()
{


}
void zExistenciaExpendios::Productos(zSiscomRegistros *pzSisRegsProductos)
{
     SiscomRegistrosLog(pzSisRegsProductos);
    (*this)=*((zExistenciaExpendios *)(pzSisRegsProductos));
}
