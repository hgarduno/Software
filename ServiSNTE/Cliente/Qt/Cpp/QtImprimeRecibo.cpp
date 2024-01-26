#include <QtImprimeRecibo.h>
#include <zSiscomDesarrollo4.h>

struct Registro{
    int x,y;
    const char *valor;
};

Registro arrayRecibo[] = 
{
    {325,25,"Folio"},
    {145,115,"Tienda"},
    {145,145,"Fecha"},
    {360,145,"Apartado"},
    {150,180,"Cliente"},
    {170,215,"Importe"},
    {90,240,"Importe Letra"},
    {90,285,"Concepto"},
    {90,315,"Elaboro"},
    {0,0,0}
};

QtImprimeRecibo::QtImprimeRecibo()
{
    setCaption( "Qt imprimir" );
    setBackgroundMode(PaletteBase);
    //connect( bgroup, SIGNAL(clicked(int)), SLOT(updateIt(int)) );

    printer = new QPrinter;
    printer->setMargins(32,18,0,0);
    printer->setPageSize(QPrinter::Letter);
    printer->setResolution(96);
    LogSiscom("Resolución: %d \n",printer->resolution());
}

QtImprimeRecibo::~QtImprimeRecibo()
{
#ifndef QT_NO_PRINTER
    delete printer;
#endif
}

void QtImprimeRecibo::imprimir( zReciboApartado & zRecApartado )
{
    int lintDialogImpresion=0;
    char *pchrArrRespuestaVarAmbiente;
    pchrArrRespuestaVarAmbiente = getenv("DIALOG_IMPRESION");
    if(pchrArrRespuestaVarAmbiente != NULL)
        lintDialogImpresion = atoi(pchrArrRespuestaVarAmbiente);

    alistaDatos( zRecApartado );
    LogSiscom("Se mando a imprimir!!\n");
    if(lintDialogImpresion)
    {
        if ( printer->setup( this ) )
        {
            QPainter paint;
            if( !paint.begin( printer ) )
                return;
            Recibo( &paint );
        }
    }
    else
    {
        QPainter paint;
        if( !paint.begin( printer ) )
            return;
        Recibo( &paint );
    }
}

void QtImprimeRecibo::alistaDatos( zReciboApartado & zRecApartado)
{
    //Alistando datos para llenar el recibo.
    arrayRecibo[0].valor = (const char *)zRecApartado["Folio"];
    arrayRecibo[1].valor = (const char *)zRecApartado["Tienda"];
    arrayRecibo[2].valor = (const char *)zRecApartado["Fecha"];
    arrayRecibo[3].valor = (const char *)zRecApartado["Apartado"];
    arrayRecibo[4].valor = (const char *)zRecApartado["Cliente"];
    arrayRecibo[5].valor = (const char *)zRecApartado["Importe"];
    arrayRecibo[6].valor = (const char *)zRecApartado["ImporteLetra"];
    arrayRecibo[7].valor = (const char *)zRecApartado["Concepto"];
    arrayRecibo[8].valor = (const char *)zRecApartado["Elaboro"];
}

void QtImprimeRecibo::Recibo( QPainter *p )
{    
    int i = 0,lintTamanioFuenteImpresion;
    char *pchrArrRespuestaVarAmbiente;
    pchrArrRespuestaVarAmbiente = getenv("TAMANIO_FONT_IMPRESION");
    if(pchrArrRespuestaVarAmbiente != NULL)
        lintTamanioFuenteImpresion = atoi(pchrArrRespuestaVarAmbiente);
    else
        lintTamanioFuenteImpresion = 8;
    QFont font("Roman",lintTamanioFuenteImpresion);
    font.setBold(true);
    p->setFont(font);
    //Agregamos valores de zVenta

    while(arrayRecibo[i].y)
    {
        p->drawText(arrayRecibo[i].x,arrayRecibo[i].y,arrayRecibo[i].valor);
        i++;
    }
}

