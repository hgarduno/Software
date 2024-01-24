#ifndef __QSISICONDATOSPERSONA_H__
#define __QSISICONDATOSPERSONA_H__
#include <qiconview.h>
class QSisOperacionPersona;

class QSisIconDatosPersona:public QIconViewItem
{
public:

	QSisIconDatosPersona(const char *,const char *,QWidget *,QIconView *);	
	~QSisIconDatosPersona();
	void IniciaControl();
	QSisOperacionPersona *ObtenOperacionPersona();
private:
	const char *chrPtrBiblioteca;
	const char *chrPtrFuncion;
	void *vidPtrAncla;
	QWidget *QWPtrPadre;
	QSisOperacionPersona *(*CreaInstancia)(QWidget *);
	QSisOperacionPersona *QSisOpPersona;

private:
	void CargaBiblioteca();

	
};

#endif
