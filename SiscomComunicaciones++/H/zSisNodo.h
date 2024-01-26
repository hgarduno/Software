#ifndef __ZSISNODO_H__
#define __ZSISNODO_H__


class zSisNodo
{
public:
	typedef void *zSisPtrNodo;
	zSisPtrNodo zSisPtrNodoDat;
	zSisNodo *zSisNodoAct;
	zSisNodo *zSisNodoSig;
	zSisNodo *zSisNodoPrim;
	zSisNodo *zSisNodoAnt;
	zSisNodo *zSisNodoUltimo;

protected:
	zSisNodo();
	virtual ~zSisNodo();
	virtual zSisPtrNodo Crea(zSisPtrNodo pzSisPtrNodo);
	virtual void Elimina()=0;
private:
};

#endif
	
	
