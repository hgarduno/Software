#include <SiscomRegistroPro2.h>
#include <stdlib.h>
#include <string.h>
SiscomRegistroPro2::SiscomRegistroPro2():
	intNumCampos(0)
{
	SCSiscomPro2=(SCampoSiscomPro2 *)malloc(sizeof(SCampoSiscomPro2));
}
SiscomRegistroPro2::~SiscomRegistroPro2()
{
}
void SiscomRegistroPro2::SiscomRegistroPro2ReAsigna()
{
	intNumCampos=0;
	SCSiscomPro2=(SCampoSiscomPro2 *)malloc(sizeof(SCampoSiscomPro2));

}
int SiscomRegistroPro2::YaEstaElCampo(SCampoSiscomPro2 *pSCSiscomPro2,
				      const char *pchrPtrNmbCampo)
{
int lintContador;

	for(lintContador=0;
	    lintContador<intNumCampos;
	    lintContador++)
	{
	 if(!strcmp((pSCSiscomPro2+lintContador)->chrPtrNmbCampo,pchrPtrNmbCampo))
	  return 1;
	}
	 return 0;
}
SiscomRegistroPro2 &SiscomRegistroPro2::operator<<(const char *pchrPtrNmbCampo)
{
char lchrArrNoCampo[5];
	if(!YaEstaElCampo(SCSiscomPro2,pchrPtrNmbCampo))
	{
	sprintf(lchrArrNoCampo,"%d",intNumCampos);
	(SCSiscomPro2+intNumCampos)->chrPtrNmbCampo=strdup(pchrPtrNmbCampo);
	(SCSiscomPro2+intNumCampos)->chrPtrNoCampo=strdup(lchrArrNoCampo);
	intNumCampos++;
	SCSiscomPro2->intNumCampos=intNumCampos;
	SCSiscomPro2=(SCampoSiscomPro2 *)realloc(SCSiscomPro2,
						 sizeof(SCampoSiscomPro2)*(intNumCampos+1));
	}
	return *this;
}
SCampoSiscomPro2 *SiscomRegistroPro2::operator[](int pintNumCampo)
{
	return SCSiscomPro2+pintNumCampo;
}
const SiscomRegistroPro2 &SiscomRegistroPro2::operator=(SiscomRegistroPro2 pSRegistroPro2)
{
 	SCSiscomPro2=pSRegistroPro2.SiscomObtenCampos();		
	return *this;
}
int SiscomRegistroPro2::SiscomObtenNumCampos()
{
	return intNumCampos;
}
SCampoSiscomPro2 *SiscomRegistroPro2::SiscomObtenCampos()
{
	return SCSiscomPro2;
}

