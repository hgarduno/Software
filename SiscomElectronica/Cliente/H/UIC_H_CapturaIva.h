/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaIva.ui'
**
** Created: Thu Apr 11 21:51:22 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURAIVA_H
#define CAPTURAIVA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;

class CapturaIva : public QDialog
{
    Q_OBJECT

public:
    CapturaIva( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaIva();

    QPushButton* QPBMasIva;
    QPushButton* QPBConIva;

protected:
    QGridLayout* CapturaIvaLayout;
    QHBoxLayout* layout22;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURAIVA_H
