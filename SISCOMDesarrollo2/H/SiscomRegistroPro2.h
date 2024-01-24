#ifndef __SISCOMREGISTROPRO2_H__
#define __SISCOMREGISTROPRO2_H__

extern "C"{
#include <SiscomDesarrollo2.h>
};

class SiscomRegistroPro2
{
public:
	SiscomRegistroPro2();
	~SiscomRegistroPro2();
	SiscomRegistroPro2 &operator<<(const char *);
	SCampoSiscomPro2 *operator[](int );
	int SiscomObtenNumCampos();
	SCampoSiscomPro2 *SiscomObtenCampos();
	operator const SCampoSiscomPro2 *()
	{
	  return SCSiscomPro2;
	}
	const SiscomRegistroPro2 &operator=(SiscomRegistroPro2 );
	void SiscomRegistroPro2ReAsigna();
private:
	SCampoSiscomPro2 *SCSiscomPro2;
	int intNumCampos;
private:
	int YaEstaElCampo(SCampoSiscomPro2 *,const char *);
};


#endif
