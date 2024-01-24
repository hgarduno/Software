#ifndef __ZXY_H__
#define __ZXY_H__

class zXY
{
public:
	zXY(int pintX,int pintY);
	zXY();
	void Modulo(const char *pchrPtrModulo);
	void Inicia();
	void X(int pintX);
	void Y(int pintY);
	int X();
	int Y();
	int IncrementoX();
	int IncrementoY();
	void IncrementoX(int pintIncremento);
	void IncrementoY(int pintIncremento);

	void IncrementaX();
	void IncrementaY();
	void Incrementa();
	int XActual();
	int YActual();
	bool operator==(const char *pchrPtrModulo);
	int operator++();
private:
	int intX;
	int intY;

	int intXActual;
	int intYActual;
	
	int intIncrementoX;
	int intIncrementoY;

	char chrArrModulo[128];

};


class zXYArreglo
{
public:
	zXYArreglo();
	void X(const char *pchrPtrModulo,int pintX);
	const zXYArreglo &operator<<(zXY &pzXYDato);
	zXY *Modulo(const char *pchrPtrModulo);
	void Inicia();

private:
	zXY *zXYDatos;
	int intContador;
};

#endif
