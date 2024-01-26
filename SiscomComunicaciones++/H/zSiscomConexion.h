#ifndef __ZSISCOMCONEXION_H__
#define __ZSISCOMCONEXION_H__

class zSiscomConexion
{
public:
	zSiscomConexion();
	zSiscomConexion(const char *pchrPtrArchivo,const char *pchrPtrModo);
	zSiscomConexion(const char *pchrPtrDirIp,
			int pintPuerto);
	zSiscomConexion(int pintSocket);
	int Socket();
	int Conectate();
	int Puerto();
	const char *DireccionIp();
	void DireccionIp(const char *pchrPtrDirIp);
	void Puerto(int pintPuerto);

	void AsignaMemoriaCadena(int pintNBytes);
	char *Cadena();
	void Cadena(char *pchrPtrCadena);

	int SeDebeConectar();	

private:
private:
	int intSocket;
	const char *chrPtrDirIp;
	const char *chrPtrEdoConexion;
	int intPuerto;
	char *chrPtrCadena;

	int intSeDebeConectar;


};

#endif
