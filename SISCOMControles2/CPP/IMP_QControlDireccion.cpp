#include <IMP_QControlDireccion.h>
#include <LibSISCOMComunControles.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

CQControlDireccion::CQControlDireccion( QWidget* parent, const char* name, WFlags fl )
    : QControlDireccion( parent, name, fl )
{

	IniciaVariables();
	ConectaSlots();
}

CQControlDireccion::~CQControlDireccion()
{
}
void CQControlDireccion::IniciaVariables()
{
}

void CQControlDireccion::ConectaSlots()
{
	connect(QLECalle,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoNumero()));
	connect(QLENumero,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoCP()));
	connect(QLECP,
		 SIGNAL(returnPressed()),
		SLOT(S_PasaFocoColonia()));
	connect(QLEColonia,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoMunicipio()));



	connect(QLEMunicipio,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoEstado()));
	connect(QLECP,
		SIGNAL(textChanged(const QString &)),
		SLOT(S_CambioElCodigoPostal(const QString &)));
	connect(QLEComboEdo,
		SIGNAL(returnPressed()),
		SLOT(S_EnterEstado()));
}
void CQControlDireccion::S_EnterEstado()
{
	emit SignalEnterEstado();
}
void CQControlDireccion::setFocus()
{
}
void CQControlDireccion::S_CambioElCodigoPostal(const QString &pQSTexto)
{
	ValidaSoloNumerosYTamano(QLECP,
				 99999,
				 5,
				 0,
				 pQSTexto);
			
}
void CQControlDireccion::S_PasaFocoNumero()
{
}
void CQControlDireccion::S_PasaFocoColonia()
{
}
void CQControlDireccion::S_PasaFocoCP()
{
}
void CQControlDireccion::S_PasaFocoMunicipio()
{
}
void CQControlDireccion::S_PasaFocoEstado()
{
}
const char *CQControlDireccion::ObtenCalle()
{

	return "";
	
}
const char *CQControlDireccion::ObtenNumero()
{
	return "";
}
const char *CQControlDireccion::ObtenCP()
{
	return "";
}
const char *CQControlDireccion::ObtenColonia()
{

	return "";
}
const char *CQControlDireccion::ObtenMunicipio()
{
	return "";
}
const char *CQControlDireccion::ObtenEstado()
{
return (const char *)QLEComboEdo->text();
	
}

