/****************************************************************************
** Form interface generated from reading ui file 'UI/ActualizaPesosPPunto.ui'
**
** Created: lun abr 1 18:57:46 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACTUALIZAPESOSPPUNTO_H
#define ACTUALIZAPESOSPPUNTO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class ActualizaPesosPPunto : public QWidget
{
    Q_OBJECT

public:
    ActualizaPesosPPunto( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ActualizaPesosPPunto();

    QLabel* textLabel3;
    QLineEdit* QLEPesosPPunto;
    QLabel* textLabel3_2;
    QLineEdit* QLEPesosPPuntoM;
    QPushButton* pushButton6;
    QPushButton* pushButton7;

protected:
    QGridLayout* ActualizaPesosPPuntoLayout;
    QVBoxLayout* layout5;
    QVBoxLayout* layout5_2;
    QHBoxLayout* layout22;

protected slots:
    virtual void languageChange();

};

#endif // ACTUALIZAPESOSPPUNTO_H
