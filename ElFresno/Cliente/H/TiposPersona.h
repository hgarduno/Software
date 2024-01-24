#ifndef __TIPOSPERSONAS__
#define __TIPOSPERSONAS__

class CQTipoPersona
{
public:
	CQTipoPersona(const char *,
			const char *,
			const char *);
	void PonTipoPersona(const char *);
	void PonNmbTipoPersona(const char *);
	void PonDscTipoPersona(const char *);

	const char *ObtenTipoPersona();
	const char *ObtenNmbTipoPersona();
	const char *ObtenDscTipoPersona();

private:
	const char *chrPtrTipoPersona;
	const char *chrPtrNmbTipoPersona;
	const char *chrPtrDscTipoPersona;
			
};

#endif
