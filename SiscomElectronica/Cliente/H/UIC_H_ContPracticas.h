/****************************************************************************
** Form interface generated from reading ui file 'UI/ContPracticas.ui'
**
** Created: Wed Jan 31 10:58:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONTPRACTICAS_H
#define CONTPRACTICAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;

class ContPracticas : public QWidget
{
    Q_OBJECT

public:
    ContPracticas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ContPracticas();

    QPushButton* QPBConMaterias;
    QPushButton* QPBContPracticas;
    QPushButton* QPBMatPracticas;
    QPushButton* QPBCEscuelas;
    QPushButton* pushButton21_3_2;
    QPushButton* pushButton21_3_2_2;

protected:
    QGridLayout* ContPracticasLayout;

protected slots:
    virtual void languageChange();

};

#endif // CONTPRACTICAS_H
