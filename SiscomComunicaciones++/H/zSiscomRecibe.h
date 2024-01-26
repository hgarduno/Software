#ifndef __ZSISCOMRECIBE_H__
#define __ZSISCOMRECIBE_H__
class zSiscomConexion;
class zSiscomCampo;
class zSiscomRegistros;
class zSiscomRegistro;
class zSiscomRecibe
{
public:
	zSiscomRecibe();
	zSiscomRecibe(zSiscomConexion *pzSisConexion);
	int CaracteresInt(int pintCaracteres);
	zSiscomRegistros *Registros();
	zSiscomRegistro *Registro(int pintCampos);
	zSiscomCampo *Campo();
	unsigned char *DatoCampo();
	void Asociados(zSiscomCampo *pzSisCampo);
	unsigned char *MemoriaLectura(int pintCaracteres);

	zSiscomRegistros *Respuesta();
virtual unsigned char *Caracteres(int pintCaracteres);
private:
	zSiscomConexion *zSisConexion;
};
#endif
