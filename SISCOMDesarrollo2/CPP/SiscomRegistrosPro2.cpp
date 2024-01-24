#include <SiscomRegistrosPro2.h>
#include <SiscomComunicaSrv.h>
#include <SiscomCampoPro2.h>
SiscomRegistrosPro2::SiscomRegistrosPro2(int pintNRegistros,
					 LCamposSiscomPro2 *pLCSiscomPro2):
			intNumRegistros(pintNRegistros),
			LCSiscomPro2Prim(pLCSiscomPro2),
			LCSiscomPro2Act(pLCSiscomPro2)
{


}

SiscomRegistrosPro2::SiscomRegistrosPro2():
		intNumRegistros(0),
		LCSiscomPro2Prim(0),
		LCSiscomPro2Act(0),
		intModoLibera(0),
		intLibera(1)
{
}
SiscomRegistrosPro2::SiscomRegistrosPro2(SiscomRegistroPro2 *pSRegistroPro2):
		intNumRegistros(0),
		LCSiscomPro2Prim(0),
		LCSiscomPro2Act(0),
		SRegistroPro2(pSRegistroPro2),
		intModoLibera(0),
		intLibera(1)
{
	SCSiscomPro2=SRegistroPro2->SiscomObtenCampos();
}
SiscomRegistrosPro2::SiscomRegistrosPro2(SiscomComunicaSrv *pSComunicaSrv):
			SComunicaSrv(pSComunicaSrv),
			intModoLibera(0),
		intNumRegistros(0),
		LCSiscomPro2Prim(0),
		LCSiscomPro2Act(0),
		intLibera(0)
{
	LCSiscomPro2Prim=LCSiscomPro2Act=SComunicaSrv->SiscomRegistrosRespuesta();	
	intNumRegistros=SComunicaSrv->SiscomObtenNumRegistrosRes();
}

SiscomRegistrosPro2::~SiscomRegistrosPro2()
{
if(intLibera)
{
SiscomLiberaListaCamposPro2(LCSiscomPro2Prim); 
}
}
void SiscomRegistrosPro2::SiscomColocaPrimerRegistro()
{
	LCSiscomPro2Act=LCSiscomPro2Prim;
}
void SiscomRegistrosPro2::PonRegistroPro2(SiscomRegistroPro2 *pSRegistroPro2)
{
	SCSiscomPro2=pSRegistroPro2->SiscomObtenCampos();
	SRegistroPro2=pSRegistroPro2;
}
SiscomRegistrosPro2 &SiscomRegistrosPro2::operator<<(SiscomCampoPro2 pSCampoPro2)
{
	SiscomAsignaDatoCampo(pSCampoPro2.SiscomObtenCampo(),
			      SRegistroPro2->SiscomObtenNumCampos(),
			      (char *)pSCampoPro2.SiscomObtenDato(),
			      SCSiscomPro2);
	return *this;
}
SiscomRegistroPro2 *SiscomRegistrosPro2::SiscomObtenRegistroPro2()
{

	return SRegistroPro2;	
}
SiscomRegistrosPro2 &SiscomRegistrosPro2::operator=(SiscomRegistrosPro2 &pSRegistrosPro2)
{
SCampoSiscomPro2 *lSCSiscomPro2;
lSCSiscomPro2=pSRegistrosPro2.SiscomObtenRegistroPro2()->SiscomObtenCampos();
LCSiscomPro2Prim=(LCamposSiscomPro2 *)malloc(sizeof(LCamposSiscomPro2 *));
SCSiscomPro2=(SCampoSiscomPro2 *)malloc(sizeof(SCampoSiscomPro2 )*
                                        lSCSiscomPro2->intNumCampos);
memcpy(SCSiscomPro2,lSCSiscomPro2,sizeof(SCampoSiscomPro2 )*lSCSiscomPro2->intNumCampos);
memcpy(LCSiscomPro2Prim,pSRegistrosPro2.SiscomObtenRegistros(),sizeof(LCamposSiscomPro2 ));
LCSiscomPro2Act=LCSiscomPro2Prim;
intNumRegistros=pSRegistrosPro2.SiscomObtenNumRegistros();
intModoLibera=1;
return *this;
}
SiscomRegistrosPro2 &SiscomRegistrosPro2::operator<<(const SCampoSiscomPro2 *pSCSiscomPro2)
{
	SiscomCreaListaCamposPro2((SCampoSiscomPro2 *)pSCSiscomPro2,
				  &LCSiscomPro2Prim,
				  &LCSiscomPro2Act);
	intNumRegistros++;
	return *this;

}
const char *SiscomRegistrosPro2::operator[](const char *pchrPtrNmbCampo)
{

	return SiscomObtenDato(LCSiscomPro2Act,
			       pchrPtrNmbCampo);
	

}
void SiscomRegistrosPro2::SiscomActualizaCampo(const char *pchrPtrCampo,
					       const char *pchrPtrValor)
{
int lintContador;
SCampoSiscomPro2 *lSCSiscomPro2=LCSiscomPro2Act->SCSiscomPro2;
	for(lintContador=0;
	    lintContador<lSCSiscomPro2->intNumCampos;
	    lintContador++)
	 if(!strcmp((lSCSiscomPro2+lintContador)->chrPtrNmbCampo,
	 	     pchrPtrCampo))
	      (lSCSiscomPro2+lintContador)->chrPtrDato=strdup(pchrPtrValor);

}
int SiscomRegistrosPro2::SiscomEsElUltimoRegistro()
{
	return LCSiscomPro2Act ? 0 :1;
}
void SiscomRegistrosPro2::operator++()
{
	if(LCSiscomPro2Act) 
	LCSiscomPro2Act=LCSiscomPro2Act->SCP2PtrSig;
}

void SiscomRegistrosPro2::SiscomAnexaRegistro()
{
	SiscomCreaListaCamposPro2(SCSiscomPro2,
				  &LCSiscomPro2Prim,
				  &LCSiscomPro2Act);
	intNumRegistros++;

}
void SiscomRegistrosPro2::SiscomAnexaRegistro(SiscomRegistrosPro2 pSRegistrosPro2)
{
const SCampoSiscomPro2 *lSCSiscomPro2;

	lSCSiscomPro2=(const SCampoSiscomPro2 *)pSRegistrosPro2;
	SiscomCreaListaCamposPro2((SCampoSiscomPro2 *)lSCSiscomPro2,
				  &LCSiscomPro2Prim,
				  &LCSiscomPro2Act);
	intNumRegistros++;

}
int SiscomRegistrosPro2::SiscomObtenNumRegistros()
{
	return intNumRegistros;
}

LCamposSiscomPro2 *SiscomRegistrosPro2::SiscomObtenRegistros()
{
	return LCSiscomPro2Prim;
}

void SiscomRegistrosPro2::SiscomIniciaObjeto()
{

	SiscomLiberaListaCamposPro2(LCSiscomPro2Prim);
	LCSiscomPro2Prim=LCSiscomPro2Act=0;
	intNumRegistros=0;

}


void SiscomRegistrosPro2::SiscomImprimeContenido()
{

	SiscomContenidoProtocolo(LCSiscomPro2Prim);
}
int SiscomRegistrosPro2::SiscomEsElCampo(const char *pchrPtrNmbCampo)
{
   return SiscomEstaElCampo(LCSiscomPro2Act,pchrPtrNmbCampo);
}
int SiscomRegistrosPro2::SiscomEsFinRegistro()
{
  return !(SiscomEsElCampo("Fin") &&
         SiscomEsElCampo("Registro"));
}
