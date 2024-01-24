#ifndef __QSISOPERACIONPERSONA_H__
#define __QSISOPERACIONPERSONA_H__


class QWidget;
class QDialog;
class QSisOperacionPersona
{
public:
	QSisOperacionPersona();
	virtual const char *ObtenTexto();
	virtual void EjecutaOperacion();
};




#endif
