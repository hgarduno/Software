#include <zCeldasCorte.h>
#include <zCeldaCorte.h>
zCeldasCorte::zCeldasCorte()
{


}
void zCeldasCorte::CeldaCorte(zCeldaCorte *pzCeldaCorte)
{
   Agrega(pzCeldaCorte); 
}

zCeldasCorte &zCeldasCorte::operator<<(zCeldaCorte *pzCeldaCorte)
{
	CeldaCorte(pzCeldaCorte);
}
