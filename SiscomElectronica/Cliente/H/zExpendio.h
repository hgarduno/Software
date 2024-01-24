#ifndef __ZEXPENDIO_H__
#define __ZEXPENDIO_H__
#include <zSiscomRegistro.h>

class zExpendio:public zSiscomRegistro
{
public:
	zExpendio();
	zExpendio(const char *,const char *,const char *,const char *);
	zExpendio(zExpendio *);
	zExpendio(zSiscomRegistro *);
	void RazonSocial(const char *);
	void DirIp(const char *);
	void Puerto(const char *);
	void Puerto(int);
	void IdExpendio(const char *);
	void Base(const char *);

	const char *DirIp();
	const char *Puerto();
	int PuertoInt();
	const char *IdExpendio();
	const char *RazonSocial();
	const char *Base();

};

#endif
