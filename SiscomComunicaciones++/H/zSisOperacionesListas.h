#ifndef __ZSISOPERACIONESLISTAS_H__
#define __ZSISOPERACIONESLISTAS_H__
#include <zSisNodo.h>

class zSisOperacionesListas:public zSisNodo
{
public:
		zSisNodo *Primer();
		zSisNodo *Siguiente();
		zSisNodo *Anterior();
		zSisNodo *Actual();
		int NNodos();
		void Libera();
protected:
		zSisOperacionesListas();
		~zSisOperacionesListas();
		void Agrega(zSisNodo::zSisPtrNodo pzSisPtrNodo);
		zSisNodo *EliminaNodo(int pintNNodo);
		zSisOperacionesListas *AsignaMemoria(zSisNodo::zSisPtrNodo );
private:
	    void Inicia(zSisPtrNodo pzSisPtrNodo);
	    void AgregaNodo(zSisPtrNodo pzSisPtrNodo);
	    void Elimina();
	    zSisNodo *EliminaNodoDiferenteCero(int pintNNodo);
	    zSisNodo *EliminaElementoCero();
private:
	zSisNodo *zSisNodoPuntero;
	int intContador;
};

#endif
