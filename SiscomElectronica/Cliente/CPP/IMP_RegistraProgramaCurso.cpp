#include <IMP_RegistraProgramaCurso.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSis3QtOperaciones.h>
#include <qlineedit.h>
#include <qpushbutton.h>

QRegistraProgramaCurso::QRegistraProgramaCurso(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				RegistraProgramaCurso(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				intBotonAceptar(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QRegistraProgramaCurso::~QRegistraProgramaCurso()
{

}

void QRegistraProgramaCurso::ConectaSlots()
{
connect(QLEDscProgramacion,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAAceptar()));
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));
}
void QRegistraProgramaCurso::SlotAceptar()
{
CQSis3QtOperaciones lCQS3QtOperaciones(SisDatCom);

lCQS3QtOperaciones.RegistraProgramacionCursos(*chrPtrArgumentos,
					      SiscomDesarrollo3Qt::InformacionEdit(QLEDscProgramacion));
intBotonAceptar=1;
done(1);
}
void QRegistraProgramaCurso::SlotFocoAAceptar()
{
SiscomDesarrollo3Qt::FocoAControl(QPBAceptar);
}
void QRegistraProgramaCurso::IniciaVariables()
{

}
int QRegistraProgramaCurso::BotonAceptar()
{
return intBotonAceptar;

}
