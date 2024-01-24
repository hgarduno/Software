#include <zComprasImportacion.h>
#include <zCompraImportacion.h>
zComprasImportacion::zComprasImportacion()
{

}
zComprasImportacion &zComprasImportacion::operator<<(zCompraImportacion *pzComImportacion)
{
    Agrega(pzComImportacion);
     return *this;
}
