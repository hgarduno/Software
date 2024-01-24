#include <IMP_QControlNombres.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

CQControlNombres::CQControlNombres( QWidget* parent, const char* name, WFlags fl )
    : QControlNombres( parent, name, fl )
{
	ConectaSlots();
}

CQControlNombres::~CQControlNombres()
{
}
void CQControlNombres::setFocus()
{
}
void CQControlNombres::ConectaSlots()
{
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(S_EnterAMaterno()));
}
void CQControlNombres::S_PasaFocoAPaterno()
{
	emit SignalEnterNombre();
}
void CQControlNombres::S_PasaFocoAMaterno()
{

	emit SignalEnterAPaterno();
}
void CQControlNombres::S_EnterAMaterno()
{
	emit SignalEnterAMaterno();
}
const char *CQControlNombres::ObtenNombre()
{
	return QLENombre->text().isEmpty() ? "":(const char *)QLENombre->text();
}
const char *CQControlNombres::ObtenAPaterno()
{
	return QLEAPaterno->text().isEmpty() ? "":(const char *)QLEAPaterno->text();
}
const char *CQControlNombres::ObtenAMaterno()
{

	return QLEAMaterno->text().isEmpty() ? "":(const char *)QLEAMaterno->text();
}
void CQControlNombres::PonNombre(const char *pchrPtrNombre)
{
	QLENombre->setText(pchrPtrNombre);
}
void CQControlNombres::PonAPaterno(const char *pchrPtrAPaterno)
{
	QLEAPaterno->setText(pchrPtrAPaterno);
}
void CQControlNombres::PonAMaterno(const char *pchrPtrAMaterno)
{
	QLEAMaterno->setText(pchrPtrAMaterno);
}
