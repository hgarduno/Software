#ifndef __PERFILESSEGURIDAD3PROT2_H__
#define __PERFILESSEGURIDAD3PROT2_H__

#include <SISCOMComunicaciones++.h>
#include <qptrlist.h>

class PerfilSeguridad3Prot2:public SiscomInformacion
{
public:
	PerfilSeguridad3Prot2(const char *,
				const char *,
				const char *,
				const char *);

};

class PerfilesSeguridad3Prot2:public QPtrList<PerfilSeguridad3Prot2>
{
public:
	PerfilesSeguridad3Prot2();
	PerfilesSeguridad3Prot2 &operator<<(PerfilSeguridad3Prot2 *);

};

class OpPerfilesSeguridad3Prot2
{
public:
	OpPerfilesSeguridad3Prot2(SiscomDatCom *);

};
#endif
