#ifndef __IMP_NOTTRANSMISION_H__
#define __IMP_NOTTRANSMISION_H__

#include <UIC_H_NotTransmision.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QLCDNumber;
class QTextEdit;

class QNotTransmision : public NotTransmision
{
    Q_OBJECT

public:
    QNotTransmision( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QNotTransmision();
    void PonDatos(const char *,const char *,const char *,const char *);
private:
	void closeEvent(QCloseEvent *);
private:
	const char *chrPtrEdoTransmision;

};

#endif 
