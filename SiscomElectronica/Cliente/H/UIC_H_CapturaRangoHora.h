/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaRangoHora.ui'
**
** Created: Wed Apr 10 20:52:31 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURARANGOHORA_H
#define CAPTURARANGOHORA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CapturaRangoHora : public QDialog
{
    Q_OBJECT

public:
    CapturaRangoHora( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaRangoHora();

    QLabel* textLabel1;
    QLineEdit* QLEHoraInicio;
    QLabel* textLabel1_2;
    QLineEdit* QLEHoraFin;
    QPushButton* QPBAceptar;
    QPushButton* pushButton6_2;

protected:
    QGridLayout* CapturaRangoHoraLayout;
    QHBoxLayout* layout12;
    QVBoxLayout* layout10;
    QVBoxLayout* layout10_2;
    QHBoxLayout* layout13;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURARANGOHORA_H
