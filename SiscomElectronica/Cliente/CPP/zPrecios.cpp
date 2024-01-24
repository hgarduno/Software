#include <zPrecios.h>

#include <zPrecio.h>
zPrecios::zPrecios()
{

}
zPrecios &zPrecios::operator<<(zPrecio *pzPrecio)
{
    Agrega(pzPrecio);
    return *this;
}
