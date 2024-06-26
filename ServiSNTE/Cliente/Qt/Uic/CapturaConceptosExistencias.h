/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaConceptosExistencias.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURACONCEPTOSEXISTENCIAS_H
#define CAPTURACONCEPTOSEXISTENCIAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QButtonGroup;
class QRadioButton;
class QGroupBox;
class QCheckBox;
class QPushButton;

class CapturaConceptosExistencias : public QWidget
{
    Q_OBJECT

public:
    CapturaConceptosExistencias( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CapturaConceptosExistencias();

    QLabel* textLabel9;
    QLineEdit* lineEdit71;
    QLabel* textLabel10;
    QLineEdit* lineEdit72;
    QLabel* textLabel11;
    QLineEdit* lineEdit73;
    QButtonGroup* buttonGroup1;
    QRadioButton* radioButton17;
    QRadioButton* radioButton18;
    QGroupBox* groupBox9;
    QCheckBox* checkBox6;
    QCheckBox* checkBox8;
    QCheckBox* checkBox7;
    QCheckBox* checkBox9;
    QPushButton* pushButton31;
    QPushButton* pushButton23;
    QPushButton* pushButton24;
    QPushButton* pushButton32;

protected:
    QGridLayout* CapturaConceptosExistenciasLayout;
    QVBoxLayout* layout83;
    QHBoxLayout* layout249;
    QSpacerItem* spacer8;
    QVBoxLayout* layout244;
    QHBoxLayout* layout247;
    QVBoxLayout* layout245;
    QVBoxLayout* layout246;
    QGridLayout* buttonGroup1Layout;
    QHBoxLayout* layout243;
    QGridLayout* groupBox9Layout;
    QHBoxLayout* layout242;
    QVBoxLayout* layout240;
    QVBoxLayout* layout241;
    QHBoxLayout* layout82;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURACONCEPTOSEXISTENCIAS_H
