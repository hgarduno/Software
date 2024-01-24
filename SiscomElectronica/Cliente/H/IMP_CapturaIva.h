#ifndef __IMP_CAPTURAIVA_H__
#define __IMP_CAPTURAIVA_H__

#include <UIC_H_CapturaIva.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;

class QCapturaIva : public CapturaIva
{
    Q_OBJECT

public:
    QCapturaIva( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QCapturaIva();
    const char *ObtenSinConIva();
private:
	void ConectaSlots();
	void closeEvent(QCloseEvent *);
private:
	const char *chrPtrMasConIva;
private slots:
	void S_MasIva();
	void S_ConIva();
};

#endif 
