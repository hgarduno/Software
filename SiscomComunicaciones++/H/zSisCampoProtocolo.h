#ifndef __ZSISCAMPOPROTOCOLO_H__
#define __ZSISCAMPOPROTOCOLO_H__

class zSisCampoProtocolo
{
public:
	const char *Campo();
	void NmbCampo(char *pchrPtrNmbCampo);
protected:
	zSisCampoProtocolo(const char *pchrPtrNombre,
			    const char *pchrPtrDato);
private:
	char chrArrNombre[128];
	const char *chrPtrDato;
};


#endif
