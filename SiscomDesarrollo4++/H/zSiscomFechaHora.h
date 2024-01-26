#ifndef __ZSISCOMFECHAHORA_H__
#define __ZSISCOMFECHAHORA_H__

class zSiscomHora
{
public:
	zSiscomHora();
	static void Actual(char *pchrPtrHora);
	
private:

};

class zSiscomFecha
{
public:
	zSiscomFecha();
	static void Actual(char *pchrPtrFecha);
	static void Actual2(char *pchrPtrFecha);
	static const char *Actual3(char *pchrPtrFecha);
	static void Actual(int *pintPtrDiaMes,
			   int *pintPtrMes,
			   int *pintPtrAno,
			   int *pintPtrDiaSemana=0);
};
class zSiscomFechaHora
{
public:
	zSiscomFechaHora();
	static void Actual(char *pchrPtrFechaHora);
	static void Actual2(char *pchrPtrFechaHora);
	static const char *Actual3(char *pchrPtrFechaHora);


};

#endif
