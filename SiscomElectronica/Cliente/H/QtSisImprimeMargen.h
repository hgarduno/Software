#ifndef __QTSISIMPRIMEMARGEN_H__
#define __QTSISIMPRIMEMARGEN_H__

class QPaintDeviceMetrics;

class QtSisImprimeMargen
{
public:
	QtSisImprimeMargen(QPaintDeviceMetrics *pQPMMedidas);
	void X(int pintX);
	void Y(int pintY);
	int Ypx();
	int Xpx();
	int Xmm();
	int Ymm();
private:
	
	 int PixelesAMM(int pintPixeles);
	 int MMAPixeles(int pintMilimetros);
private:
	QPaintDeviceMetrics *QPDMMedidas;
	int intXmm;
	int intYmm;
};

#endif
