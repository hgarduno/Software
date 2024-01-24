#ifndef __SISCOMCPUINFO3_H__
#define __SISCOMCPUINFO3_H__
#include <stdio.h>
class SiscomCpuInfo
{
public:
	enum EnumCpuInfo
	{
		processor,
		vendor_id,
		cpu_family,
		model,
		model_name,
		stepping,
		cpu_MHz,
		cache_size,
		physical_id,
		siblings,
		core_id,
		cpu_cores,
		apicid,
		initial_apicid,
		fpu,
		fpu_exception,
		cpuid_level,
		wp,
		flags,
		bogomips,
		clflush_size,
		cache_alignment,
		address_sizes,
		power_management,
		fdiv_bug, /* Para el caso de un Pentium III */
		hlt_bug,
		f00f_bug,
		coma_bug
	};
private:
	const char *chrArrDatosCpu[32];
	/*!
	 * Se almacenan los datos hasta por 
	 * 10 cpus 
	 */
	const char ***chrArrValoresCpu;
	FILE *FlePtrArchivo;
	int intCpuNum;
	int intNumCpus;
	int intNumParametro;
private:
	void IniciaDatosCpu();
	int LeeLinea(char *);
	void LeeArchivo();
	void AsignaDatoParametro(const char *pchrPtrParametro,
				 const char *pchrPtrDato);

	void NombreParametroDato(const char *pchrPtrLinea,
				      char *pchrPtrNmbParametro,
				      char *pchrPtrDato);
	void EliminaTabulador(char *pchrPtrDato);
	int ObtenNumeroParametro(const char *);
	void AbreArchivo(const char *pchrPtrArchivo);
	void ObtenNumeroCpu(const char *pchrPtrParametro,
			    const char *pchrPtrDato);
	void IniciaMemoriaCpuInfo();
	void ParametroDato(const char *pchrPtrParametroDato,
			   char *pchrPtrParametro,
			   char *pchrPtrDato);
	void ObtenModeloFamilia(SiscomCpuInfo *pSisCpuInfo,
				int *pintPtrCpuFamily,
				int *pintPtrModel);
	int EsCpu_6_23(SiscomCpuInfo *pSisCpuInfo);
	int EsCpu_6_15(SiscomCpuInfo *pSisCpuInfo);
	int EsCpu_6_7(SiscomCpuInfo *pSisCpuInfo);
	/*
	 *  ATOM Acer One
	 */
	int EsCpu_6_28(SiscomCpuInfo *pSisCpuInfo);
	/*
	 * Core Duo
	 *
	 */
	 int EsCpu_6_14(SiscomCpuInfo *pSisCpuInfo);
	 /*
	  * Intel Pentium D
	  *
	  */
	 int EsCpu_15_4(SiscomCpuInfo *pSisCpuInfo);
	 /*
	  * Intel Pentium IV R
	  */
	 int EsCpu_15_2(SiscomCpuInfo *pSisCpuInfo);
	 /*
	  * Intel Pentium IV R Remplazo servidor
	  */
	 int EsCpu_15_6(SiscomCpuInfo *pSisCpuInfo);

	 /*
	  * Viernes 4 De Noviembre 2011 
	  * Intel core i7-2620M
	  */
	 int EsCpu_42_6(SiscomCpuInfo *pSisCpuInfo);

public:
	SiscomCpuInfo(FILE *pFlePtrArchivo);
	SiscomCpuInfo(const char *pchrPtrArchivo);
	SiscomCpuInfo();
	~SiscomCpuInfo();
	const char *operator[](int);
	const char *operator[](const char *);
	int operator==(SiscomCpuInfo *);
	int EsElUltimoParametro();
	
	/*!
	 * Se pasa en el argumento pchrPtrParametroDato la 
	 * informacion del parametro y el valor que se debe
	 * asigna con el siguiente formato:
	 * Parametro=Dato
	 * Por ejemplo:
	 * vendor_id=GenuineIntel
	 * Lo que hara el operador de forma interna es separar
	 * la cadena vendor_id obtener el indice entero para 
	 * asignar el dato GenuineIntel.
	 * Sera necesario considerar que antes de invocar este
	 * operador se tendra que asingar el numero de Cpu al
	 * que se requiere asignar la propiedad mediante CpuNum(int)
	 *
	 */
	SiscomCpuInfo &operator<<(const char *pchrPtrParametroDato);
	int CpusSistema();
	void CpuNum(int);
	void NumCpus(int pintNumCpus);
	const char *SiguienteParametro(char *pchrPtrParametro);

};


#endif
