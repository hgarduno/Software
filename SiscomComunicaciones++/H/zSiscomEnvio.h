#ifndef __ZSISCOMENVIO_H__
#define __ZSISCOMENVIO_H__

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class zSiscomCampo;
class zSiscomEnvio
{
public:
	zSiscomEnvio();
	zSiscomEnvio(zSiscomConexion *pzSisConexion,
		     zSiscomRegistros *pzSisRegsEnvio,
		     char *pchrPtrCadenaEnvio);
	zSiscomEnvio(zSiscomConexion *pzSisConexion,zSiscomRegistros *pzSisRegsEnvio);
	zSiscomEnvio(zSiscomConexion *pzSisConexion);

	void Registros();
	void Envio(zSiscomRegistros *pzSisRegistros);
	zSiscomConexion *Conexion();
	virtual void Cadena(const char *pchrPtrCadena);
	
private:
	void NRegistrosNCampos(int pintRegistros,
			      zSiscomRegistro *pzSisRegistro);
	void Registro(int pintNRegistros,zSiscomRegistro *pzSisRegistro);
	void Campo(zSiscomCampo *pzSisCampo);
	void Asociados(zSiscomCampo *pzSisCampo);
	void RegistrosSinFinal(zSiscomRegistros *pzSisRegistros);

	int TamanoCampo(zSiscomCampo *pzSisCampo);
	char *MemoriaCadenaEnvio(zSiscomCampo *pzSisCampo);
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsEnvio;
};

#endif
