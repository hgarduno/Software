#ifndef __QESPACIOEXPENDIOS_H__
#define __QESPACIOEXPENDIOS_H__
#include <qmainwindow.h>
class QWorkspace;
class EmpresaN;

class QEspacioExpendios:public QMainWindow
{
Q_OBJECT 
public:
	QEspacioExpendios(EmpresaN *,QWidget *,const char *,WFlags );
	QWorkspace *ObtenEspacioTrabajo();
private:
	QWorkspace *ws;
	EmpresaN *Expendio;
private:
	void CreaWS();
	void ColocaEncabezado();

};


#endif
