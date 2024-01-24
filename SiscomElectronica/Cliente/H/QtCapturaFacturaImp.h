#ifndef __QTCAPTURACOMPRAIMP_H__
#define __QTCAPTURACOMPRAIMP_H__

#include <IMP_ComprasImportaciones.h>


class QtCapturaFacturaImp:public QComprasImportaciones
{
Q_OBJECT
public:
	QtCapturaFacturaImp(SiscomDatCom *,
			   char **,
			   QWidget *pQWParent,
			   const char *,
			   WFlags);
private:
	void Inicia();
	void DesHabilitaControles();
};

#endif
