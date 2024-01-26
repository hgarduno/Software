#include <zSisNodo.h>
zSisNodo::zSisNodo():
		zSisPtrNodoDat(0),
		zSisNodoAct(0),
		zSisNodoPrim(0),
		zSisNodoSig(0),
		zSisNodoAnt(0)
			
{

}
zSisNodo::~zSisNodo()
{

}
zSisNodo::zSisPtrNodo zSisNodo::Crea(zSisPtrNodo pzSisPtrNodo)
{
  return pzSisPtrNodo;
}


