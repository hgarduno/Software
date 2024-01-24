#ifndef __IMP_CAPTURADATO_H__
#define __IMP_CAPTURADATO_H__

#include <UIC_H_CapturaDato.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;

class QCapturaDato : public CapturaDato
{
    Q_OBJECT

public:
    QCapturaDato(const char *,
    		 const char *,
    		 QWidget* parent = 0,
		 const char* name = 0,
		 bool modal = FALSE,
		 WFlags fl = 0 );
	QCapturaDato(const char *,
    		 const char *,
    		 const char *,
    		 QWidget* parent = 0,
		 const char* name = 0,
		 bool modal = FALSE,
		 WFlags fl = 0 );

    ~QCapturaDato();
    void ObtenDato(char *);
    float ObtenDatoFloat();
    int ObtenDatoInt();
    void PonTextoInicial(const char *);
private slots:
	void S_Capturo();
};

#endif 
