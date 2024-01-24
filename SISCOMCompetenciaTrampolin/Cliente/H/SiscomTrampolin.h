#ifndef __SISCOMTRAMPOLIN_H__
#define __SISCOMTRAMPOLIN_H__
#include <SISCOMVentanaPrincipal3.h>

class SiscomTrampolin:public SISCOMVentanaPrincipal
{
Q_OBJECT
public:
	SiscomTrampolin(QWidget *pQWParent=0,
			const char *pchrPtrName=0,
			WFlags pWFlags=0);
private:
	void ObtenDatosComunicacion();
private:
	int intPtoCom;
	const char *chrPtrDirIp;
};

#endif
