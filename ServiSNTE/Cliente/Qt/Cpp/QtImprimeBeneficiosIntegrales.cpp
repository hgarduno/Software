#include <zSiscomDesarrollo4.h>
#include <QtImprimeBeneficiosIntegrales.h>
#include <QtImpVolteaContrato.h>
Registro arrayContratoBI[500];


QtImprimeBeneficiosIntegrales::QtImprimeBeneficiosIntegrales():i(0)
{
    setCaption( "Qt imprimir" );
    setBackgroundMode(PaletteBase);
}
void QtImprimeBeneficiosIntegrales::Inicia()
{
    printer = new QPrinter;
    printer->setMargins(intMargenArriba,intMargenIzquierda,intMargenAbajo,intMargenDerecha);
    printer->setPageSize(QPrinter::Letter);
    printer->setResolution(96);
}
QtImprimeBeneficiosIntegrales::~QtImprimeBeneficiosIntegrales()
{
#ifndef QT_NO_PRINTER
    delete printer;
#endif
}

void QtImprimeBeneficiosIntegrales::imprimir( zContratoBeneficios *zConBeneficios )
{
QPainter paint;
    alistaDatos( zConBeneficios );
    //Posiciones(arrayContratoBI);
    printer->setPrintRange(QPrinter::PageRange);
    printer->setPageSize(QPrinter::Letter);
    printer->setNumCopies(1);
    /*
    printer->setMinMax(1,9);
    printer->setFromTo(1,9); 
    */
    if(!paint.begin(printer))
    return;
    else
    beneficios(&paint);
}
void QtImprimeBeneficiosIntegrales::ImprimeFrente( zContratoBeneficios *zConBeneficios )
{
QPainter paint;
    alistaDatos( zConBeneficios );
    //Posiciones(arrayContratoBI);
    printer->setPrintRange(QPrinter::PageRange);
    printer->setPageSize(QPrinter::Letter);
    printer->setNumCopies(1);
    /*printer->setMinMax(1,9);
    printer->setFromTo(1,9); */
    if(!paint.begin(printer))
    return;
    else
    beneficiosFrente(&paint);
}
void QtImprimeBeneficiosIntegrales::ImprimeAtras( zContratoBeneficios *zConBeneficios )
{
QPainter paint;
    alistaDatos( zConBeneficios );
    //Posiciones(arrayContratoBI);
    printer->setPrintRange(QPrinter::PageRange);
    printer->setPageSize(QPrinter::Letter);
    printer->setNumCopies(1);
    //printer->setFromTo(1,1);
    if(!paint.begin(printer))
    return;
    else
    beneficiosAtras(&paint);
}

void QtImprimeBeneficiosIntegrales::ImprimeAArchivo(const char *pchrPtrArchivo,
						    zContratoBeneficios *pzConBeneficios)
{
QPainter paint;
alistaDatos(pzConBeneficios);
//Posiciones(arrayContratoBI);
printer->setOutputToFile(true);
printer->setOutputFileName(pchrPtrArchivo);
    printer->setNumCopies(1);
    printer->setPrintRange(QPrinter::PageRange);
    printer->setNumCopies(1);
   /* printer->setMinMax(1,1);
    printer->setFromTo(1,1); 
    */
if(!paint.begin(printer))
LogSiscom("Error al mandar a imprimir");
else
{
LogSiscom("Imprimiendo en ServiSNTE.ps");
beneficiosAArchivo(&paint);
}
}
void QtImprimeBeneficiosIntegrales::alistaDatos( zContratoBeneficios *zConBeneficios )
{
    arrayContratoBI[0].valor = zConBeneficios->Lugar();
    arrayContratoBI[1].valor = zConBeneficios->FechaConMesLetra();
    arrayContratoBI[2].valor = zConBeneficios->APaterno();
    arrayContratoBI[3].valor = zConBeneficios->AMaterno();
    arrayContratoBI[4].valor = zConBeneficios->Nombre();
    arrayContratoBI[5].valor = zConBeneficios->RFC();
    arrayContratoBI[6].valor = zConBeneficios->CURP();
    arrayContratoBI[7].valor = zConBeneficios->Estado() ;
    arrayContratoBI[8].valor = zConBeneficios->PaisNacimiento();
    arrayContratoBI[9].valor = zConBeneficios->EsMasculino(),
    arrayContratoBI[10].valor = zConBeneficios->EsFemenino(),
    arrayContratoBI[11].valor = zConBeneficios->EsCasado(),
    arrayContratoBI[12].valor = zConBeneficios->EsSoltero(),
    arrayContratoBI[13].valor = zConBeneficios->Edad() ;
    arrayContratoBI[14].valor = zConBeneficios->FechaNacimiento() ;
    arrayContratoBI[15].valor = zConBeneficios->Identificacion() ;
    arrayContratoBI[16].valor = zConBeneficios->NoIdentificacion() ;
    arrayContratoBI[17].valor = zConBeneficios->Ocupacion() ;
    arrayContratoBI[18].valor = zConBeneficios->Nacionalidad() ;
    arrayContratoBI[19].valor = zConBeneficios->Calle() ;
    arrayContratoBI[20].valor = zConBeneficios->NumExterior() ;
    arrayContratoBI[21].valor = zConBeneficios->NumInterior() ;
    arrayContratoBI[22].valor = zConBeneficios->Colonia() ;
    arrayContratoBI[23].valor = zConBeneficios->CodigoPostal() ;

    arrayContratoBI[24].valor = zConBeneficios->Delegacion() ;
    arrayContratoBI[25].valor = zConBeneficios->Ciudad() ;
    arrayContratoBI[26].valor = zConBeneficios->Estado() ;
    arrayContratoBI[27].valor = zConBeneficios->PaisNacimiento() ;

    arrayContratoBI[28].valor = zConBeneficios->EsTipoViviendaPropia() ;
    arrayContratoBI[29].valor = zConBeneficios->EsTipoViviendaHipotecada() ;
    arrayContratoBI[30].valor = zConBeneficios->EsTipoViviendaFamiliar() ;
    arrayContratoBI[31].valor = zConBeneficios->EsTipoViviendaRentada() ;
    arrayContratoBI[32].valor = "";


    arrayContratoBI[33].valor = zConBeneficios->TelefonoParticular() ;
    arrayContratoBI[34].valor = zConBeneficios->TiempoResidir() ;
    arrayContratoBI[35].valor = zConBeneficios->TelefonoCelular() ;
    arrayContratoBI[36].valor = zConBeneficios->CorreoElectronico() ;
    arrayContratoBI[37].valor = zConBeneficios->TelefonoRecados() ;

    arrayContratoBI[38].valor = zConBeneficios->Empresa() ;
    arrayContratoBI[39].valor = zConBeneficios->Antiguedad() ;
    arrayContratoBI[40].valor = zConBeneficios->Puesto() ;
    arrayContratoBI[41].valor = zConBeneficios->Giro() ;

    arrayContratoBI[42].valor = zConBeneficios->Jefe() ;
    arrayContratoBI[43].valor = zConBeneficios->CalleEmpleo() ;
    arrayContratoBI[44].valor = zConBeneficios->NumExteriorEmpleo() ;
    arrayContratoBI[45].valor = zConBeneficios->NumInteriorEmpleo() ;
    arrayContratoBI[46].valor = zConBeneficios->ColoniaEmpleo() ;

    arrayContratoBI[47].valor = zConBeneficios->CodigoPostalEmpleo() ;
    arrayContratoBI[48].valor = zConBeneficios->DelegacionEmpleo() ;
    arrayContratoBI[49].valor = zConBeneficios->CiudadEmpleo() ;
    arrayContratoBI[50].valor = zConBeneficios->EstadoEmpleo() ;
    arrayContratoBI[51].valor = zConBeneficios->PaisNacimiento() ;

    arrayContratoBI[52].valor = zConBeneficios->TelefonoEmpleo() ;
    arrayContratoBI[53].valor = zConBeneficios->ExtensionEmpleo() ;
    arrayContratoBI[54].valor = zConBeneficios->CorreoEmpleo() ;
    arrayContratoBI[55].valor = zConBeneficios->Importe() ;
    arrayContratoBI[56].valor = zConBeneficios->Plazo() ;
    arrayContratoBI[57].valor = zConBeneficios->ImporteLetra() ;
    arrayContratoBI[58].valor = zConBeneficios->NombreCompleto() ;
    /* Queretaro a 4 de febrero del 2016 
     * me salto donde va el fin de pagina 
     */
    arrayContratoBI[60].valor = zConBeneficios->Importe();
    arrayContratoBI[61].valor = zConBeneficios->Plazo() ;
    // Fin Pagina
    arrayContratoBI[63].valor = zConBeneficios->Importe() ;
    arrayContratoBI[64].valor = zConBeneficios->ImporteLetra();
    // Fin Pagina
    arrayContratoBI[68].valor= zConBeneficios->Lugar();
    arrayContratoBI[69].valor= zConBeneficios->FechaConMesLetra();
    arrayContratoBI[70].valor= zConBeneficios->NombreCompleto();
    arrayContratoBI[71].valor= zConBeneficios->Calle();
    arrayContratoBI[72].valor= zConBeneficios->Colonia();
    arrayContratoBI[73].valor= zConBeneficios->Estado();
    arrayContratoBI[74].valor= zConBeneficios->RFC();
    arrayContratoBI[75].valor= zConBeneficios->CentroTrabajo2();
    arrayContratoBI[76].valor= zConBeneficios->ClavePresupuestal();
    arrayContratoBI[77].valor= zConBeneficios->PagoQuincenal();
    arrayContratoBI[78].valor= zConBeneficios->PagoQuincenalLetra();
    arrayContratoBI[79].valor= zConBeneficios->PagoTotal();
    arrayContratoBI[80].valor= zConBeneficios->PagoTotalLetra();

    /// Fin de pagina

    arrayContratoBI[82].valor= zConBeneficios->Lugar();
    arrayContratoBI[83].valor= zConBeneficios->FechaConMesLetra();

    //Fin Pagina 
    arrayContratoBI[87].valor= zConBeneficios->Sueldo();
    arrayContratoBI[88].valor= zConBeneficios->EsFrecuenciaPagoSemanal();
    arrayContratoBI[89].valor= zConBeneficios->EsFrecuenciaPagoCatorcenal();
    arrayContratoBI[90].valor= zConBeneficios->EsFrecuenciaPagoQuincenal();
    arrayContratoBI[91].valor= zConBeneficios->EsFrecuenciaPagoMensual();
    arrayContratoBI[92].valor= zConBeneficios->OtrosIngresosMonto();
    arrayContratoBI[93].valor= zConBeneficios->TotalIngresos();

    arrayContratoBI[94].valor= "x";
    arrayContratoBI[95].valor= "x";
    arrayContratoBI[96].valor= "x";
    arrayContratoBI[97].valor= "x";
    arrayContratoBI[98].valor= "x";


    arrayContratoBI[99].valor= zConBeneficios->NombreReferencia(0);
    arrayContratoBI[100].valor= zConBeneficios->DomicilioReferencia(0);
    arrayContratoBI[101].valor= zConBeneficios->TelefonoReferencia(0);

    arrayContratoBI[102].valor= zConBeneficios->NombreReferencia(1);
    arrayContratoBI[103].valor= zConBeneficios->DomicilioReferencia(1);
    arrayContratoBI[104].valor= zConBeneficios->TelefonoReferencia(1);

    arrayContratoBI[105].valor= zConBeneficios->NombreReferencia(2);
    arrayContratoBI[106].valor= zConBeneficios->DomicilioReferencia(2);
    arrayContratoBI[107].valor= zConBeneficios->TelefonoReferencia(2);
    /* Pagina */
    arrayContratoBI[112].valor= zConBeneficios->Lugar();
    arrayContratoBI[113].valor= zConBeneficios->DiaFecha();
    arrayContratoBI[114].valor= zConBeneficios->MesFechaLetra();
    arrayContratoBI[115].valor= zConBeneficios->AnioFecha();
    // Fin Pagina
    arrayContratoBI[117].valor= zConBeneficios->Lugar();
    arrayContratoBI[118].valor= zConBeneficios->FechaConMesLetra();
    arrayContratoBI[119].valor= zConBeneficios->NombreCompleto();
    arrayContratoBI[120].valor= zConBeneficios->TelefonoParticular();
    arrayContratoBI[121].valor= zConBeneficios->Calle();
    arrayContratoBI[122].valor= zConBeneficios->CodigoPostal();
    arrayContratoBI[123].valor= zConBeneficios->Colonia();
    arrayContratoBI[124].valor= zConBeneficios->Estado();
    arrayContratoBI[125].valor= zConBeneficios->PagoTotal();
    arrayContratoBI[126].valor= zConBeneficios->PagoTotalLetra();
    arrayContratoBI[127].valor= zConBeneficios->NumeroPagos();
    arrayContratoBI[128].valor= zConBeneficios->PorcentajeTasa();
    arrayContratoBI[129].valor= zConBeneficios->PorcentajeTasaLetra();
    arrayContratoBI[130].valor= zConBeneficios->Lugar();
    arrayContratoBI[131].valor= zConBeneficios->Estado();
    arrayContratoBI[132].valor= zConBeneficios->DiaFecha();
    arrayContratoBI[133].valor= zConBeneficios->MesFechaLetra();
    arrayContratoBI[134].valor= zConBeneficios->AnioFecha();
    /* Pagina   */
    arrayContratoBI[136].valor= zConBeneficios->NombreCompleto();
    arrayContratoBI[137].valor= zConBeneficios->CURP();
    arrayContratoBI[138].valor= zConBeneficios->Calle();
    arrayContratoBI[139].valor= zConBeneficios->Colonia();
    arrayContratoBI[140].valor= zConBeneficios->Delegacion();
    arrayContratoBI[141].valor= zConBeneficios->Estado();
    arrayContratoBI[142].valor= zConBeneficios->CodigoPostal();
    arrayContratoBI[143].valor= zConBeneficios->TelefonoParticular();

    

    arrayContratoBI[145].valor=0;
    //CheckBoxes
}

void QtImprimeBeneficiosIntegrales::beneficiosAArchivo( QPainter *p )
{    
    QFont font("Courier",8);
    p->setFont(font);
    while(arrayContratoBI[i].valor &&
	   strcmp(arrayContratoBI[i].valor,"FinContrato"))
    {
      while(arrayContratoBI[i].valor && 
           strcmp(arrayContratoBI[i].valor,"FinPagina") &&
	   strcmp(arrayContratoBI[i].valor,"FinContrato")) 
      {
        LogSiscom("%d.- %s",i,arrayContratoBI[i].valor); 
        p->drawText(arrayContratoBI[i].x,arrayContratoBI[i].y,arrayContratoBI[i].valor);
        i++;
      }
      LogSiscom("Siguiente Pagina -> Impares (%d) (%s)",
      		 i,
		 arrayContratoBI[i].valor ? arrayContratoBI[i].valor : ""); 
      if(arrayContratoBI[i].valor)
      printer->newPage();
      i++;
    } 
    i++;
}
void QtImprimeBeneficiosIntegrales::beneficios( QPainter *p )
{  
    QFont font("Courier",8);
    p->setFont(font);
    while(arrayContratoBI[i].valor &&
	   strcmp(arrayContratoBI[i].valor,"FinContrato"))
    {
      while(arrayContratoBI[i].valor && 
           strcmp(arrayContratoBI[i].valor,"FinPagina") &&
	   strcmp(arrayContratoBI[i].valor,"FinContrato")) 
      {
        LogSiscom("%d.- %s",i,arrayContratoBI[i].valor); 
        p->drawText(arrayContratoBI[i].x,arrayContratoBI[i].y,arrayContratoBI[i].valor);
        i++;
      }
      LogSiscom("Siguiente Pagina -> Impares (%d) (%s)",
      		 i,
		 arrayContratoBI[i].valor ? arrayContratoBI[i].valor : ""); 
      if(arrayContratoBI[i].valor)
      printer->newPage();
      i++;
    } 
    i++;
}

void QtImprimeBeneficiosIntegrales::beneficiosFrente( QPainter *p )
{  
    QFont font("Courier",8);
    p->setFont(font);
    i=0;
    while(arrayContratoBI[i].valor &&
	   strcmp(arrayContratoBI[i].valor,"FinContrato"))
    {
      while(arrayContratoBI[i].valor && 
           strcmp(arrayContratoBI[i].valor,"FinPagina") &&
	   strcmp(arrayContratoBI[i].valor,"FinContrato")) 
      {
        LogSiscom("%d.- %s",i,arrayContratoBI[i].valor);
        p->drawText(arrayContratoBI[i].x,arrayContratoBI[i].y,arrayContratoBI[i].valor);
        i++;
      }
      LogSiscom("Siguiente Pagina -> Impares (%d) (%s)",
      		 i,
		 arrayContratoBI[i].valor ? arrayContratoBI[i].valor : ""); 
      if(arrayContratoBI[i].valor)
      printer->newPage();
      i++;
    } 
    i++;
}

void QtImprimeBeneficiosIntegrales::beneficiosAtras( QPainter *p )
{  
    QFont font("Courier",8);
    p->setFont(font);
    i=87;
    while(arrayContratoBI[i].valor &&
	   strcmp(arrayContratoBI[i].valor,"FinContrato"))
    {
      while(arrayContratoBI[i].valor && 
           strcmp(arrayContratoBI[i].valor,"FinPagina") &&
	   strcmp(arrayContratoBI[i].valor,"FinContrato")) 
      {
        LogSiscom("%d.- %s",i,arrayContratoBI[i].valor);
        p->drawText(arrayContratoBI[i].x,arrayContratoBI[i].y,arrayContratoBI[i].valor);
        i++;
      }
      LogSiscom("Siguiente Pagina -> Impares (%d) (%s)",
      		 i,
		 arrayContratoBI[i].valor ? arrayContratoBI[i].valor : ""); 
      if(arrayContratoBI[i].valor)
      printer->newPage();
      i++;
    } 
    i++;
}


void QtImprimeBeneficiosIntegrales::MargenArriba(int pintMargenArriba)
{
  intMargenArriba=pintMargenArriba;
}

void QtImprimeBeneficiosIntegrales::MargenAbajo(int pintMargenAbajo)
{
  intMargenAbajo=pintMargenAbajo;
}
void QtImprimeBeneficiosIntegrales::MargenDerecha(int pintMargenDerecha)
{
  intMargenDerecha=pintMargenDerecha;
}
void QtImprimeBeneficiosIntegrales::MargenIzquierda(int pintMargenIzquierda)
{
  intMargenIzquierda=pintMargenIzquierda;
}
void QtImprimeBeneficiosIntegrales::AsignaPosiciones(Registro *pRegistro)
{
Registro *lRegistro=arrayContratoBI;
int lintContador=0;
    while(pRegistro->valor)
    {
	//LogSiscom("%d.-%s",lintContador,pRegistro->valor);
	lRegistro->valor=pRegistro->valor;
	lRegistro->x=pRegistro->x;
	lRegistro->y=pRegistro->y;
	lRegistro++;
	pRegistro++;
	lintContador++;
    }
}
void QtImprimeBeneficiosIntegrales::Posiciones(Registro *pRegPosiciones)
{
int lintContador=0;
Registro *lRegPosiciones=pRegPosiciones;
    while(lRegPosiciones->valor)
    {
	LogSiscom("%d.- %s (%d,%d)",
		  lintContador,
		  lRegPosiciones->valor,
		  lRegPosiciones->x,
		  lRegPosiciones->y);
 	lRegPosiciones++;
	lintContador++;
    }
}
