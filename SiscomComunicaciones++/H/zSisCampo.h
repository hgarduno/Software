#ifndef __ZSISCAMPO_H__
#define __ZSISCAMPO_H__


class zSisCampo
{
public:
	zSisCampo(const char *pchrPtrNombre,
		  const char *pchrPtrDato);
private:
	const char *chrPtrNombre;
	const char *chrPtrDato;
};

#endif
