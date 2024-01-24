#ifndef __FIRMAS_H__
#define __FIRMAS_H__

class CQ_Firma
{
public:
	CQ_Firma(const char *,const char *);
	const char *ObtenFirma();
	const char *ObtenIdPersona();
	const char *ObtenEdoRegistro();

	void PonFirma(const char *);
	void PonIdPersona(const char *);
	void PonEdoRegistro(const char *);
	
private:
	const char *chrPtrFirma;
	const char *chrPtrIdPersona;
	const char *chrPtrEdoRegistro;

};


#endif
