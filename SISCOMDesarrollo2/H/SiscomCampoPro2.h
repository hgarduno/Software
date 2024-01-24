#ifndef __SISCOMCAMPOPRO2_H__
#define __SISCOMCAMPOPRO2_H__
extern "C"{
#include <SiscomDesarrollo2.h>
}
class SiscomCampoPro2
{

	public:
		 SiscomCampoPro2(const char *,const char *);
		 SiscomCampoPro2();
		 ~SiscomCampoPro2();
		 void PonCampo(const char *);
		 void PonDato(const char *);
		 const char *SiscomObtenCampo();
		 const char *SiscomObtenDato();
	private:
		const char *chrPtrNmbCampo;
		const char *chrPtrDato;

};

#endif
