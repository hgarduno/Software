#include <stdio.h>
#include <FuncionesComunes.h>
#include <unistd.h>
#include <RNADFuncionesComunes.h>
#include <string.h>
typedef struct OpcLinCmdCliente
{
	int        intPuertoRN;
	char       chrPtrDirIPRN[20];
	int        intMovimiento;
	char       chrArrUsuario[256];
	char       chrArrPassword[256];
	char       chrArrLibreriaDinamicaRN[256];
	char       chrArrFuncionRN[256];
	int        intPuertoAD;
	char       chrPtrDirIPAD[20];
	int 	   intNumeroDeProductos;
}OpcLinCmdCliente;
void CopiaDatosDeLineaCMDADatosOperacion(OpcLinCmdCliente ,STRUCTDatosDeLaOperacion *pstcDatosDeLaOperacionPtrReg);
void GeneraEncabezado(PARDEPURACION OpcLinCmdCliente ,char *);
void GeneraCadenaAltaProductos(PARDEPURACION int,char *);
void ObtenArgumentos(int,char **,OpcLinCmdCliente *);
int main(int pintArgc,char **pchrPtrArgv)
{
	int lintPto,lintSocketCon;
	STRUCTError lSTRUCTErrorReg;
	char lchrCadenotaEncabezado[400];
	char lchrCadenotaProductos[4096];
	char lchrCadenaTotal[8192];
	char lchrCaracter;
	OpcLinCmdCliente lstcOpcLinCmdClienteReg;

	char lchrArrRegreso[]="\n\t";	

ObtenArgumentos(pintArgc,pchrPtrArgv,&lstcOpcLinCmdClienteReg);	
SISCOMConectateServidor(DATODEP lstcOpcLinCmdClienteReg.intPuertoRN,lstcOpcLinCmdClienteReg.chrPtrDirIPRN,&lintSocketCon,&lSTRUCTErrorReg);
GeneraEncabezado(DATODEP lstcOpcLinCmdClienteReg,lchrCadenotaEncabezado);
sprintf(lchrCadenotaProductos,"%04d%04d%04d%04d%c",1,1,1,1,'*');
//GeneraCadenaAltaProductos(DATODEP 5,lchrCadenotaProductos);
sprintf(lchrCadenaTotal,"%s%s",lchrCadenotaEncabezado,lchrCadenotaProductos);
printf("%s\n",lchrCadenaTotal);
Write(lintSocketCon,lchrCadenaTotal,strlen(lchrCadenaTotal));
while(lchrCaracter!='*')
{
	Read(lintSocketCon,&lchrCaracter,1);
	printf("%c",lchrCaracter);
}
}
void CopiaDatosDeLineaCMDADatosOperacion(OpcLinCmdCliente pstcOpcLinCmdCliente,STRUCTDatosDeLaOperacion *pstcDatosDeLaOperacionPtrReg)
{
sprintf(pstcDatosDeLaOperacionPtrReg->chrArrMovimiento,"%05d",pstcOpcLinCmdCliente.intMovimiento);
strcpy(pstcDatosDeLaOperacionPtrReg->chrArrUsuario,pstcOpcLinCmdCliente.chrArrUsuario);
strcpy(pstcDatosDeLaOperacionPtrReg->chrArrPassword,pstcOpcLinCmdCliente.chrArrPassword);
strcpy(pstcDatosDeLaOperacionPtrReg->chrArrNomDll,pstcOpcLinCmdCliente.chrArrLibreriaDinamicaRN);
strcpy(pstcDatosDeLaOperacionPtrReg->chrArrNomFuncion,pstcOpcLinCmdCliente.chrArrFuncionRN);
}
void ObtenArgumentos(int pintArgc,char **pchrPtrArgv,OpcLinCmdCliente *pstcOpcLinCmdCliente)
{
	char lchrCaracter;
	while((lchrCaracter=getopt(pintArgc,pchrPtrArgv,":A:B:C:D:E:F:G:H:I:J:K:"))!=-1)
	{
		switch(lchrCaracter)
		{
			case 'A':
				pstcOpcLinCmdCliente->intPuertoRN=atoi(optarg);	
			break;
			case 'B':
				strcpy(pstcOpcLinCmdCliente->chrPtrDirIPRN,optarg);
			break;
			case 'C':
				pstcOpcLinCmdCliente->intMovimiento=atoi(optarg);
			break;
			case 'D':
				strcpy(pstcOpcLinCmdCliente->chrArrUsuario,optarg);
			break;
			case 'E':
				strcpy(pstcOpcLinCmdCliente->chrArrPassword,optarg);
			break;
			case 'F':
				strcpy(pstcOpcLinCmdCliente->chrArrLibreriaDinamicaRN,optarg);   
			break;
			case 'G':
				strcpy(pstcOpcLinCmdCliente->chrArrFuncionRN,optarg);
			break;
			case 'I':
				pstcOpcLinCmdCliente->intPuertoAD=atoi(optarg);
			break;
			case 'J':
				strcpy(pstcOpcLinCmdCliente->chrPtrDirIPAD,optarg);
			break;
			case 'K':
				pstcOpcLinCmdCliente->intNumeroDeProductos=atoi(optarg);
			break;

		}
	}

}
void GeneraEncabezado(PARDEPURACION OpcLinCmdCliente pstcOpcLinCmdCliente,char *pchrPtrCadEncabezado)
{
int lintTuberia[2];
int lintTamano;
char lchrArrEncabezado[500];
STRUCTDatosDeLaOperacion lstcDatosDeLaOperacionReg;
pipe(lintTuberia);
CopiaDatosDeLineaCMDADatosOperacion(pstcOpcLinCmdCliente,&lstcDatosDeLaOperacionReg);
RNADFormaProtocoloEncabezado(PDEPURACION lintTuberia[1],lstcDatosDeLaOperacionReg,NULL);
Read(lintTuberia[0],lchrArrEncabezado,5);
lchrArrEncabezado[5]=0;
lintTamano=atoi(lchrArrEncabezado);
Read(lintTuberia[0],lchrArrEncabezado,lintTamano);
lchrArrEncabezado[lintTamano]=0;
sprintf(pchrPtrCadEncabezado,"%05d%s",lintTamano,lchrArrEncabezado);
}
void GeneraCadenaAltaProductos(PARDEPURACION int pintNRegistros,char *pchrPtrEncabezado)
{
char lchrArrClaveProd[256];
char lchrArrClaveProv[256];
char lchrArrNombreProd[256];
char lchrArrDescProd[256];
int lintI,lintTamDato;	
int lintPosFinal=strlen(pchrPtrEncabezado);
sprintf(pchrPtrEncabezado+lintPosFinal,"%05d",pintNRegistros);
lintPosFinal+=5;
sprintf(pchrPtrEncabezado+lintPosFinal,"%05d",4);
lintPosFinal+=5;
//SISCOMFormaDatosProtocoloINT(int pintDato,int pintNDato,int *pintPtrTamano,char *pchrPtrCampo);
for(lintI=1;lintI<=pintNRegistros;lintI++)
{
	sprintf(lchrArrClaveProd,"CLAVE%05d",lintI);
	sprintf(lchrArrNombreProd,"Nombre Del Producto %05d",lintI);
	sprintf(lchrArrClaveProv,"CLAVEPROV%05d",lintI);
	sprintf(lchrArrDescProd,"Esta es la descripcion %05d",lintI);
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION lchrArrClaveProd,1,1,&lintTamDato,pchrPtrEncabezado+lintPosFinal);lintPosFinal+=lintTamDato;
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION lchrArrNombreProd,2,1,&lintTamDato,pchrPtrEncabezado+lintPosFinal);lintPosFinal+=lintTamDato;
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION lchrArrClaveProv,3,1,&lintTamDato,pchrPtrEncabezado+lintPosFinal);lintPosFinal+=lintTamDato;
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION lchrArrDescProd,4,1,&lintTamDato,pchrPtrEncabezado+lintPosFinal);lintPosFinal+=lintTamDato;

}
}
/*Clave del producto.
	Nombre del producto.
		Clave del proveedor 
			Descripción del producto
			*/
