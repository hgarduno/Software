#ifndef __ZSISLISTAS_H__
#define __ZSISLISTAS_H__
#include <zSisOperacionesListas.h>
template <class T>
class zSisLista:public zSisOperacionesListas
{
public:
	void Agrega(T *pzTNodo);
	void Elimina(int pintNNodo);
	void Elimina(T *pzTNodo);
	T *Primer();
	T *Siguiente();
	T *Nodo(T &pNodo);
	T *operator[](int pintNNodo);
	int Nodo(T *pzTNodo);
private:
	
};
template <class T> inline
void zSisLista<T>::Elimina(int pintNNodo)
{
T *lzTNodo;
    lzTNodo=(T *)zSisOperacionesListas::EliminaNodo(pintNNodo);
    if(lzTNodo)
    {
      delete lzTNodo; 
      lzTNodo=0;
    }
}
template <class T> inline
void zSisLista<T>::Elimina(T *pzTNodo)
{
  int lintNNodo;
   if((lintNNodo=Nodo(pzTNodo))!=-1)
    Elimina(lintNNodo);
  
}

template <class T> inline
void zSisLista<T>::Agrega(T *pzTNodo)
{
    zSisOperacionesListas::Agrega(pzTNodo);  
}
template <class T>
inline 
T *zSisLista<T>::Primer()
{
   if(zSisOperacionesListas::Primer())
   return (T *)zSisOperacionesListas::Primer()->zSisPtrNodoDat;
   else
   return 0;
}
template <class T>
inline 
T *zSisLista<T>::Siguiente()
{
 zSisNodo *lzSisNodo;
  lzSisNodo=zSisOperacionesListas::Siguiente();
  return lzSisNodo ? (T *)lzSisNodo->zSisPtrNodoDat : (T *)0;
}
template <class T>
inline
T *zSisLista<T>::Nodo(T &pNodo)
{
T *lNodo;
for(lNodo=Primer();
    lNodo;
    lNodo=Siguiente())
{
  if(pNodo==*lNodo)
  return lNodo;
}

return (T *)0;
}

template <class T>
inline 
T *zSisLista<T>::operator[](int pintNNodo)
{
int lintContador;
T *lzSisNodo;
for(lintContador=0,
    lzSisNodo=Primer();
    lintContador<pintNNodo;
    lintContador++,
    lzSisNodo=Siguiente())
{
   
}
return lzSisNodo;
}
template <class T>
inline 
int zSisLista<T>::Nodo(T *pzTNodo)
{
int lintContador;
T *lzSisNodo;
for(lintContador=0,
    lzSisNodo=Primer();
    lintContador<NNodos(); 
    lintContador++,
    lzSisNodo=Siguiente())
{
    if(lzSisNodo==pzTNodo)
    return lintContador;
}
    
return -1;
}


#endif
