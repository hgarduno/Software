#include <zSisOperacionesListas.h>
#include <stdio.h>
#include <stdlib.h>
zSisOperacionesListas::zSisOperacionesListas():
			intContador(0)
{

}
zSisOperacionesListas::~zSisOperacionesListas()
{
   
}
void zSisOperacionesListas::Agrega(zSisNodo::zSisPtrNodo pzSisPtrNodo)
{
	 intContador++;

	if(!zSisNodoPrim)
	 Inicia(pzSisPtrNodo);
	else
	 AgregaNodo(pzSisPtrNodo);

}


void zSisOperacionesListas::Inicia(zSisNodo::zSisPtrNodo pzSisPtrNodo)
{
zSisOperacionesListas *lzSisOpListas=new zSisOperacionesListas;
	 lzSisOpListas->zSisPtrNodoDat=pzSisPtrNodo;
	 zSisNodoAct=lzSisOpListas;
	 zSisNodoAct->zSisNodoAct=0;
	 zSisNodoPrim=zSisNodoAct;
}
void zSisOperacionesListas::Elimina()
{

}
zSisNodo *zSisOperacionesListas::EliminaElementoCero()
{
zSisNodo *lzSisPtrNodoEliminar;
lzSisPtrNodoEliminar=Primer();
intContador--;
zSisNodoPrim=Siguiente();
return lzSisPtrNodoEliminar;
}
zSisNodo *zSisOperacionesListas::EliminaNodo(int pintNNodo)
{
   if(pintNNodo>0 && 
      pintNNodo<intContador)
    return EliminaNodoDiferenteCero(pintNNodo);
   else
   if(!pintNNodo)
     return EliminaElementoCero();
   else
   return 0;
}
zSisNodo *zSisOperacionesListas::EliminaNodoDiferenteCero(int pintNNodo)
{
int lintContador;
zSisNodo *lzSisPtrNodo=Primer();;
zSisNodo *lzSisPtrNodoAnterior=0;
zSisNodo *lzSisPtrNodoAEliminar=0;
	for(lintContador=0; lintContador<intContador; lintContador++)
	{
	   if(pintNNodo==lintContador)
	   {
		intContador--;
		lzSisPtrNodoAEliminar=lzSisPtrNodo;
		if(!lzSisPtrNodoAEliminar->zSisNodoSig)
		{
		zSisNodoAct=lzSisPtrNodoAnterior;
		zSisNodoAct->zSisNodoSig=0;
		}
		else
	        lzSisPtrNodoAnterior->zSisNodoSig=lzSisPtrNodo->zSisNodoSig;
		break;
	   }
	   else
	   {
	       lzSisPtrNodoAnterior=lzSisPtrNodo;
	       lzSisPtrNodo=lzSisPtrNodo->zSisNodoSig;

	   }
	
	   
	}
return lzSisPtrNodoAEliminar;


}
void zSisOperacionesListas::AgregaNodo(zSisNodo::zSisPtrNodo pzSisPtrNodo)
{
zSisOperacionesListas *lzSisOpListas=AsignaMemoria(pzSisPtrNodo);
	zSisNodoAnt=zSisNodoAct;
	zSisNodoAct->zSisNodoSig=lzSisOpListas;
	zSisNodoAct=zSisNodoAct->zSisNodoSig;
	zSisNodoAct->zSisNodoSig=0;
}
/* Sabado 13 de Diciembre del 2014 
 * Estas funciones se tomaran como iteradores, 
 * es decir me permitiran recorrer la lista, apartir
 * de la variable zSisNodoPuntero;
 *
 * Las variables zSisNodoAct, zSisNodoSig, y zSisNodoPrim,
 * son para el caso en que se requiera agregar un nodo
 * las cuales no se alteran, por el iterador
 */
zSisNodo *zSisOperacionesListas::Primer()
{
  zSisNodoPuntero=zSisNodoPrim; 
   return zSisNodoPuntero;
}
zSisNodo *zSisOperacionesListas::Siguiente()
{
	zSisNodoPuntero= zSisNodoPuntero ? zSisNodoPuntero->zSisNodoSig:0;
	return zSisNodoPuntero;
}

int zSisOperacionesListas::NNodos()
{
 return intContador;
}

void zSisOperacionesListas::Libera()
{
zSisNodo *lzSisNodo=Primer();
zSisNodo *lzSisNodoProximo;

   while(lzSisNodo)
   {
          lzSisNodoProximo=lzSisNodo->zSisNodoSig;	
	  free(lzSisNodo);
	  lzSisNodo=0;
	  lzSisNodo=lzSisNodoProximo;
   }
zSisPtrNodoDat=0;
zSisNodoAct=0;
zSisNodoPrim=0;
zSisNodoSig=0;
zSisNodoAnt=0;
intContador=0;
zSisNodoPuntero=0;

}
zSisNodo *zSisOperacionesListas::Anterior()
{
	return zSisNodoAnt;
}
zSisNodo *zSisOperacionesListas::Actual()
{
  return zSisNodoAct;
}
zSisOperacionesListas *zSisOperacionesListas::AsignaMemoria(zSisNodo::zSisPtrNodo pzSisPtrNodo)
{
zSisOperacionesListas *lzSisOpListas=new zSisOperacionesListas;
lzSisOpListas->zSisPtrNodoDat=pzSisPtrNodo;
lzSisOpListas->zSisNodoAct=0;
lzSisOpListas->zSisNodoSig=0;
lzSisOpListas->zSisNodoPrim=0;
lzSisOpListas->zSisNodoAnt=0;
lzSisOpListas->zSisNodoUltimo=0;
return lzSisOpListas;
}
