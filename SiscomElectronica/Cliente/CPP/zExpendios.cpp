#include <zExpendios.h>
#include <zExpendio.h>

zExpendios::zExpendios()
{


}

void zExpendios::Agrega(zExpendio *pzExpendio)
{
  (*this) << pzExpendio;
}
void zExpendios::Principal(zExpendio *pzExpendio)
{
   Agrega(pzExpendio);
}

const char *zExpendios::RazonSocialPrincipal()
{
  return (const char *)((zExpendio *)(*this)[0])->RazonSocial();
}
zExpendio *zExpendios::Expendio(int pintNExpendio)
{

   return (zExpendio *)(*this)[pintNExpendio];
}
zExpendio *zExpendios::Principal()
{
   return (zExpendio *)(*this)[0];
}
