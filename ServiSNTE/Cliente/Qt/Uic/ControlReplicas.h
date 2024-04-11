/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/ControlReplicas.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONTROLREPLICAS_H
#define CONTROLREPLICAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QFrame;
class QPushButton;
class QGroupBox;
class QTable;

class ControlReplicas : public QWidget
{
    Q_OBJECT

public:
    ControlReplicas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ControlReplicas();

    QFrame* frame14;
    QPushButton* QPBEjecutar;
    QPushButton* pushButton4_2;
    QPushButton* pushButton4_3;
    QFrame* frame4;
    QGroupBox* groupBox2;
    QTable* QTTransferencias;
    QFrame* frame6;
    QGroupBox* groupBox4;

protected:
    QHBoxLayout* frame14Layout;
    QGridLayout* frame4Layout;
    QGridLayout* groupBox2Layout;
    QGridLayout* frame6Layout;

protected slots:
    virtual void languageChange();

};

#endif // CONTROLREPLICAS_H
