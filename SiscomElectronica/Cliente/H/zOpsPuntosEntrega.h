#ifndef __ZOPSPUNTOENTREGA_H__
#define __ZOPSPUNTOENTREGA_H__
#include <zSiscomOperaciones.h>

class zPuntoEntrega;
class zPuntosEntrega;
class zOpsPuntosEntrega:public zSiscomOperaciones
{
public:
	zOpsPuntosEntrega(zSiscomConexion *,
			 zPuntoEntrega *,
			  const char *pchrPtrFuncion,
			  const char *pchrPtrModulo="libSiscomElectronica4.so");


	zOpsPuntosEntrega(const char *pchrPtrConsulta,
			  zSiscomConexion *,
			 zPuntoEntrega *,
			  const char *pchrPtrFuncion,
			  const char *pchrPtrModulo="libSiscomElectronica4.so");

	
	zPuntosEntrega *ObtenPuntosEntrega();
private:
	void Enviando(zSiscomRegistro *);
	void RegistraPuntoEntrega(zPuntoEntrega *);
	void PuntosEntrega(const char *);
private:
	zSiscomRegistros *zSisRegsRespuesta;
	zPuntosEntrega *zPsEntrega;
private:
	void PuntosEntrega();

};
class zOperacionesPuntoE
{
public:
	zOperacionesPuntoE();

private:
	char chrArrOperacion[128];
	void (zOpsPuntosEntrega::*Operacion)(zSiscomRegistro *);
};
#endif
