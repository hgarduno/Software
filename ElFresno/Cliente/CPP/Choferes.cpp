#include <Choferes.h>
#include <Personas.h>
#include <qlineedit.h>
#include <qcombobox.h>

Chofer::Chofer(CQ_Persona *pCQPChofer):
	     CQPChofer(pCQPChofer)
{


}

CQ_Persona *Chofer::ObtenChofer()
{
	return CQPChofer;
}
CQChoferes::CQChoferes()
{

}
CQCtrChoferes::CQCtrChoferes(CSISCOMDatComunicaciones *pCSisDatCom,
			     QStringList pQSLParametros,
			     CQChoferes *pCQChoferes):
		CSisDatCom(pCSisDatCom),
		intNumArgumentosEnvio(2),
		chrPtrOperacionesChoferes("%s%s")
{


	EjecutaOperacion(pQSLParametros,pCQChoferes);
	AnalizaRespuesta(pCQChoferes);	


}
void CQCtrChoferes::AnexaRegistroVacio()
{

	CQOGSvrSiscom->AnexaRegistro(chrPtrOperacionesChoferes,
				     "",
				     "");
}
void CQCtrChoferes::AnexaParametrosOperacion(QStringList pQSLParametros)
{
int lintContador;
	for(lintContador=0;
	    lintContador<pQSLParametros.size();
	    lintContador++)
	CQOGSvrSiscom->AnexaRegistro(chrPtrOperacionesChoferes,
				     "",
				     (const char *)pQSLParametros[lintContador]);

	AnexaRegistroVacio();	


}
void CQCtrChoferes::EjecutaOperacion(QStringList pQSLParametros,
				     CQChoferes *pCQChoferes)
{
	CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						   intNumArgumentosEnvio);
	CQOGSvrSiscom->AnexaRegistro(chrPtrOperacionesChoferes,
				     "OperacionesChoferes",
				     "");
	AnexaParametrosOperacion(pQSLParametros);
	AnexaChoferes(pCQChoferes);
	 CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
	AnalizaRespuesta(pCQChoferes);	

}
void CQCtrChoferes::AnexaChoferes(CQChoferes *pCQChoferes)
{


}
void CQCtrChoferes::AnalizaRespuesta(CQChoferes *pCQChoferes)
{

	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	       QSLRegistro.count()==6)
	   pCQChoferes->append(new Chofer(new CQ_Persona((const char *)QSLRegistro[0],
					      (const char *)QSLRegistro[1],
					      (const char *)QSLRegistro[2],
					      (const char *)QSLRegistro[3],
					      (const char *)QSLRegistro[5],
					      (const char *)QSLRegistro[4])));
}

CQSeleccionaChoferes::CQSeleccionaChoferes(const char *pchrPtrIdChoferes,
					   CSISCOMDatComunicaciones *pCSisDatCom,
					   QWidget *pQWParent,
					   const char *pchrPtrName,
					   QLineEdit *pQLECNombreChofer,
					   QLineEdit *pQLENombreCompleto,
					   QComboBox *pQCBChoferes):
				QObject(pQWParent,pchrPtrName),
				chrPtrIdChoferes(pchrPtrIdChoferes),
				QLECChoferes(pQLECNombreChofer),
				QLENmbCompleto(pQLENombreCompleto),
				QCBNmbChofer(pQCBChoferes),
				CSisDatCom(pCSisDatCom)
{
	LlenaComboChoferes();
	ConectaSlots();
}
void CQSeleccionaChoferes::LlenaComboChoferes()
{
CQCtrChoferes lCQCChoferes(CSisDatCom,
			   QStringList() <<
			   "ConsultaTodosLosChoferes" <<
			   chrPtrIdChoferes,
			   &CQCChoferes);
Chofer *lC_Chofer;

	for(lC_Chofer=CQCChoferes.first();
	    lC_Chofer;
	    lC_Chofer=CQCChoferes.next())
	 QCBNmbChofer->insertItem(QString(lC_Chofer->ObtenChofer()->ObtenNombre())+
			 	  " " +
				  lC_Chofer->ObtenChofer()->ObtenAPaterno() +
				  " " +
				  lC_Chofer->ObtenChofer()->ObtenAMaterno());
			   
}

void CQSeleccionaChoferes::ConectaSlots()
{
	connect(QCBNmbChofer,
		SIGNAL(highlighted(int)),
		SLOT(S_SeleccionandoChofer(int)));
	connect(QCBNmbChofer,
		SIGNAL(activated(int)),
		SLOT(S_Chofer(int)));
	connect(QLECChoferes,
		SIGNAL(returnPressed()),
		SLOT(S_Chofer()));

}
void CQSeleccionaChoferes::S_Chofer()
{
	emit Signal_Chofer(CQCChoferes.at(QCBNmbChofer->currentItem()));
}
void CQSeleccionaChoferes::S_SeleccionandoChofer(int pintNumChofer)
{
Chofer *lChofer=CQCChoferes.at(pintNumChofer);
	QLENmbCompleto->setText(QString(lChofer->ObtenChofer()->ObtenNombre()) +
				" " +
				lChofer->ObtenChofer()->ObtenAPaterno() +
				lChofer->ObtenChofer()->ObtenAMaterno());
				  
}
void CQSeleccionaChoferes::S_Chofer(int pintNChofer)
{
	emit Signal_Chofer(CQCChoferes.at(pintNChofer));
	

}
