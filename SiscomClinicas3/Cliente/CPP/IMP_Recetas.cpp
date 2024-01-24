#include <IMP_Recetas.h>
#include<SISCOMComunicaciones++.h>
#include <CQSisPersonas.h>
#include <CQSisObjetos.h>
QRecetas::QRecetas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Recetas(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
show();
}

QRecetas::~QRecetas()
{

}

void QRecetas::ConectaSlots()
{


}
void QRecetas::IniciaVariables()
{
	
}

void QRecetas::Paciente(CQSisPersona *pCQSPaciente)
{
	CQSPaciente=pCQSPaciente;
}

void QRecetas::Informacion()
{
MuestraPaciente();
ConsultandoRecetas();
}
void QRecetas::ConsultandoRecetas()
{
	ConsultaRecetas();
	MuestraRecetas();
}
void QRecetas::ConsultaRecetas()
{
CQSisOpReceta lCQSOReceta(SisDatCom);
lCQSOReceta.Recetas((*CQSPaciente)["IdPersona"],&CQSLReceta);
}
void QRecetas::CadenaColor(const char *pchrPtrColor,
			   const char *pchrPtrCadena,
			   char *pchrPtrCadenaColor)
{

	sprintf(pchrPtrCadenaColor,
		"<font color=%s>%s</font>",
		pchrPtrColor,
		pchrPtrCadena);

}
void QRecetas::MuestraRecetas()
{
CQSisReceta *lCQSReceta;
char lchrArrFecha[25];
for(lCQSReceta=CQSLReceta.first();
    lCQSReceta;
    lCQSReceta=CQSLReceta.next())
{
     CadenaColor("red",(*lCQSReceta)["Fecha"],lchrArrFecha);
     QTERecetas->append(lchrArrFecha);
     QTERecetas->append("\n");
     QTERecetas->append((*lCQSReceta)["Receta"]);
     QTERecetas->append("\n");
}
}
void QRecetas::MuestraPaciente()
{
char lchrArrPaciente[125];
CQSisObjetos::NombreCompleto(CQSPaciente,lchrArrPaciente); 
QLEPaciente->setText(lchrArrPaciente);
}
void QRecetas::closeEvent(QCloseEvent *)
{
	CQSLReceta.setAutoDelete(true);
	CQSLReceta.clear();
	delete this;
}
