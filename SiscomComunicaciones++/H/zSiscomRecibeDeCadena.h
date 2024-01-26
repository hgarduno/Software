#ifndef __ZSISCOMRECIBEDECADENA_H__
#define __ZSISCOMRECIBEDECADENA_H__
#include <zSiscomRecibe.h>

class zSiscomRecibeDeCadena:public zSiscomRecibe
{
public:
	zSiscomRecibeDeCadena();
	unsigned char *Caracteres(int pintNCaracteres);
};


#endif
