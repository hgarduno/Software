#ifndef __PERSONAS2_H__
#define __PERSONAS2_H__
#include <Personas.h>
#include <CQSiscomCom.h>

class CQCtrActualizaPersona:public SISCOMOperacionesEnvio
{

public:
	CQCtrActualizaPersona(CSISCOMDatComunicaciones *,
			      QStringList ,
			      CQ_Personas *);
private:
	void SISCOMIniciaRegistroEnvio();
	void SISCOMRegistrosEnvio();
	void AnalizaRespuesta();
private:
	SISCOMRegistroEnvio SISCOMRegEnvioDat;
	CQ_Personas *CQPersonas;

};

#endif
