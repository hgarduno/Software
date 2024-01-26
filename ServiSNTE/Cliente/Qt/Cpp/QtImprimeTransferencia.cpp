#include <zSiscomDesarrollo4.h>
#include <QtImprimeTransferencia.h>

struct Registro{
    int x,y;
    const char *valor;
};

Registro arrayTransferencia[] = {
    {280,44," "},   /*  0.- Folio               */
    {330,44," "},   /*  1.- Almacen             */
    {330,44," "},   /*  2.- Tienda a transferir */
    {20,150," "},   /*  3.- Dia                 */
    {52,150," "},   /*  4.- Mes                 */
    {90,150," "},   /*  5.- Anio                */
    {135,150," "},  /*  6.- Chofer              */
    {135,150," "},  /*  7.- Camion              */
    {135,150," "},  /*  8.- Placas              */
    {135,150," "},  /*  9.- Observacion General */
    {135,150," "},  /* 10.- Producto: Codigo    */
    {135,150," "},  /* 11.- Producto: Nota      */
    {135,150," "},  /* 12.- Producto: Modelo    */
    {135,150," "},  /* 13.- Producto: Cantidad  */
    {135,150," "},  /* 14.- Producto: Total     */
    {280,44," "},   /*  0.- Folio               */
    {330,44," "},   /*  1.- Almacen             */
    {330,44," "},   /*  2.- Tienda a transferir */
    {20,150," "},   /*  3.- Dia                 */
    {52,150," "},   /*  4.- Mes                 */
    {90,150," "},   /*  5.- Anio                */
    {135,150," "},  /*  6.- Chofer              */
    {135,150," "},  /*  7.- Camion              */
    {135,150," "},  /*  8.- Placas              */
    {135,150," "},  /*  9.- Observacion General */
    {135,150," "},  /* 10.- Producto: Codigo    */
    {135,150," "},  /* 11.- Producto: Nota      */
    {135,150," "},  /* 12.- Producto: Modelo    */
    {135,150," "},  /* 13.- Producto: Cantidad  */
    {135,150," "},  /* 14.- Producto: Total     */
    {0,0,0}
};

QtImprimeTransferencia::QtImprimeTransferencia()
{
    setCaption( "Qt imprimir" );
    setBackgroundMode(PaletteBase);
    printer = new QPrinter;
    printer->setMargins(32,18,0,0);
    LogSiscom("Margen inzquierdo: %d\n",printer->margins().width() );
    LogSiscom("Margen superior: %d\n",printer->margins().height() );
    printer->setPageSize(QPrinter::Letter);
    printer->setResolution(96);
    LogSiscom("Resolución: %d \n",printer->resolution());

}

QtImprimeTransferencia::~QtImprimeTransferencia()
{
#ifndef QT_NO_PRINTER
    delete printer;
#endif
}

void QtImprimeTransferencia::imprimir( zTransferencia & zTransferenciaOrden )
{
    alistaDatos( zTransferenciaOrden );
    LogSiscom("Se mando a imprimir!!\n");
    if ( printer->setup( this ) )
    {
        QPainter paint;
        if( !paint.begin( printer ) )
        return;
        transferencia( &paint, zTransferenciaOrden );
    }
}

void QtImprimeTransferencia::alistaDatos( zTransferencia & zTransferenciaOrden )
{
    char *nombre = (char *) malloc(strlen((const char *)zTransferenciaOrden["Nombre"])+strlen((const char *)zTransferenciaOrden["APaterno"])+strlen((const char *)zTransferenciaOrden["AMaterno"])+2);
    strcat(nombre,(const char *)zTransferenciaOrden["Nombre"]);
    strcat(nombre," ");
    strcat(nombre,(const char *)zTransferenciaOrden["APaterno"]);
    strcat(nombre," ");
    strcat(nombre,(const char *)zTransferenciaOrden["AMaterno"]);
    arrayTransferencia[2].valor = (const char *)zTransferenciaOrden["Dia"];
    arrayTransferencia[3].valor = (const char *)zTransferenciaOrden["Mes"];
    arrayTransferencia[4].valor = (const char *)zTransferenciaOrden["Anio"];
    arrayTransferencia[11].valor = nombre;
    arrayTransferencia[12].valor = (const char *)zTransferenciaOrden["Calle"];
    arrayTransferencia[12].valor = (const char *)zTransferenciaOrden["NumExterior"];
    arrayTransferencia[12].valor = (const char *)zTransferenciaOrden["NumInterior"];
    arrayTransferencia[14].valor = (const char *)zTransferenciaOrden["Colonia"];
    arrayTransferencia[15].valor = (const char *)zTransferenciaOrden["DelegMunic"];
    arrayTransferencia[16].valor = (const char *)zTransferenciaOrden["CodigoPostal"];
    arrayTransferencia[17].valor = (const char *)zTransferenciaOrden["InstruccionesE"];

}

void QtImprimeTransferencia::transferencia( QPainter *p, zTransferencia & zTransferenciaOrden )
{    
    int i = 0, x = 0, y = 0, lintTamanioFuenteImpresion;
    char lchrArrConcepto[100], *pchrArrRespuestaVarAmbiente;
    pchrArrRespuestaVarAmbiente = getenv("TAMANIO_FONT_IMPRESION");
    if(pchrArrRespuestaVarAmbiente != NULL)
        lintTamanioFuenteImpresion = atoi(pchrArrRespuestaVarAmbiente);
    else
        lintTamanioFuenteImpresion = 8;
    QFont font("Roman",lintTamanioFuenteImpresion);
    font.setBold(true);
    p->setFont(font);
    //Agregamos valores de zTransferencia
    while(arrayTransferencia[i].y)
    {
        if((i<20)&&(i>24))p->drawText(arrayTransferencia[i].x,arrayTransferencia[i].y,arrayTransferencia[i].valor);
        i++;
    }
    //Agregamos productos.
    zProductos *lzProductos=zTransferenciaOrden.Productos();
    zProducto *lzProducto;
    for(lzProducto=(zProducto *)lzProductos->Primer();
        lzProducto;
        lzProducto=(zProducto *)lzProductos->Siguiente())
    {
        p->drawText(arrayTransferencia[20].x,arrayTransferencia[20].y+y,(const char *)(*lzProducto)["codigobarras"]);
        p->drawText(arrayTransferencia[21].x,arrayTransferencia[21].y+y,"1");
        p->drawText(arrayTransferencia[22].x,arrayTransferencia[22].y+y,(const char *)(*lzProducto)["nombreproducto"]);
        p->drawText(arrayTransferencia[23].x,arrayTransferencia[23].y+y,(const char *)(*lzProducto)["idpreciogeneral"]);
        p->drawText(arrayTransferencia[24].x,arrayTransferencia[24].y+y,(const char *)(*lzProducto)["Importe"]);
        y+=15;
    }
}

