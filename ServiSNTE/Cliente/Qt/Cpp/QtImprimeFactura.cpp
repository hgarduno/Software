#include <zSiscomDesarrollo4.h>
#include <QtImprimeFactura.h>

struct Registro{
    int x,y;
    const char *valor;
};

Registro arrayFactura[] = {
    {280,44,"Ven"}, /* 0.-Vendedor  */
    {330,44," "},    /* 1.-Factura #  */
    {20,150," "},    /* 2.-Dia  */
    {52,150," "},    /* 3.-Mes  */
    {90,150," "},    /* 4.-Anio  */
    {135,150," "},   /* 5.-Tienda  */
    {170,150," "},   /* 6.-Forma Pago : Contado  */
    {223,150," "},   /* 7.-Forma Pago : C.O.D.  */
    {260,150," "},   /* 8.-Forma Pago : Credito  */
    {340,150," "},   /* 9.-Apartado  */
    {395,150," "},   /* 10.-Autorizo  */
    {60,180," "},    /* 11.-Nombre completo  */
    {70,200," "},    /* 12.-Direccion : calle y numero  */
    {110,220," "},   /* 13.-Entre calles  */
    {60,240," "},    /* 14.-Colonia  */
    {90,260," "},    /* 15.-Poblacion : Delegacion o Municipio  */
    {395,260," "},   /* 16.-Codigo Postal  */
    {140,285," "},   /* 17.-Instruccion de entrega  */
    {350,285," "},   /* 18.-Telefono  */
    {120,310," "},   /* 19.-Tipo de entrega  */
    {20,345," "},    /* 20.-Producto: Codigo  */
    {87,345,"1"},    /* 21.-Producto: Cantidad  */
    {120,345," "},   /* 22.-Producto: Descripcion  */
    {330,345," "},   /* 23.-Producto: Precio Unitario  */
    {390,345," "},   /* 24.-Producto: Importe  */
    {390,510," "},   /* 25.-Suma de Importe*/
    {390,530," "},   /* 26.-Impuesto  */
    {390,550," "},   /* 27.-SubTotal  */
    {390,570," "},   /* 28.-Anticipo  */
    {390,590," "},   /* 29.-Total de Orden */
    {260,640," "},   /* 30.-Total de Orden con letra  */
    {310,670," "},   /* 31.-Dia  */
    {355,670," "},   /* 32.-Mes  */
    {445,670," "},   /* 33.-Anio  */
    {0,0,0}
};

QtImprimeFactura::QtImprimeFactura()
{
    setCaption( "Qt imprimir" );
    setBackgroundMode(PaletteBase);
    //connect( bgroup, SIGNAL(clicked(int)), SLOT(updateIt(int)) );

    printer = new QPrinter;
    printer->setMargins(32,18,0,0);
    LogSiscom("Margen inzquierdo: %d\n",printer->margins().width() );
    LogSiscom("Margen superior: %d\n",printer->margins().height() );
    printer->setPageSize(QPrinter::Letter);
    printer->setResolution(96);
    LogSiscom("Resolución: %d \n",printer->resolution());
}

QtImprimeFactura::~QtImprimeFactura()
{
#ifndef QT_NO_PRINTER
    delete printer;
#endif
}

void QtImprimeFactura::imprimir( zVenta & zVentaOrden )
{
    int lintDialogImpresion=0;
    char *pchrArrRespuestaVarAmbiente;
    pchrArrRespuestaVarAmbiente = getenv("DIALOG_IMPRESION");
    if(pchrArrRespuestaVarAmbiente != NULL)
        lintDialogImpresion = atoi(pchrArrRespuestaVarAmbiente);
    
    alistaDatos( zVentaOrden );
    LogSiscom("Se mando a imprimir!!\n");
    if(lintDialogImpresion)
    {
        if( printer->setup( this ) )
        {
            QPainter paint;
            if( !paint.begin( printer ) )
                return;
            factura( &paint, zVentaOrden );
        }
    }
    else
    {
        QPainter paint;
        if( !paint.begin( printer ) )
            return;
        factura( &paint, zVentaOrden );
    }

}

void QtImprimeFactura::alistaDatos( zVenta & zVentaOrden )
{
    char *pchrArrCalleYNumero=(char *) malloc(sizeof(char)*128);
    char *nombre = (char *) malloc(strlen((const char *)zVentaOrden["Nombre"])+strlen((const char *)zVentaOrden["APaterno"])+strlen((const char *)zVentaOrden["AMaterno"])+2);
    strcpy(nombre,(const char *)zVentaOrden["Nombre"]);
    strcat(nombre," ");
    strcat(nombre,(const char *)zVentaOrden["APaterno"]);
    strcat(nombre," ");
    strcat(nombre,(const char *)zVentaOrden["AMaterno"]);
    arrayFactura[0].valor = (const char *)zVentaOrden["NombreVendedor"];
    arrayFactura[1].valor = (const char *)zVentaOrden["Folio"];
    arrayFactura[2].valor = (const char *)zVentaOrden["Dia"];
    arrayFactura[3].valor = (const char *)zVentaOrden["Mes"];
    arrayFactura[4].valor = (const char *)zVentaOrden["Anio"];
    arrayFactura[5].valor = (const char *)zVentaOrden["IdTiendaEntrega"];
    arrayFactura[11].valor = (const char *)nombre;
    strcpy(pchrArrCalleYNumero,(const char *)zVentaOrden["Calle"]);
    if(zVentaOrden["NumExterior"]!=NULL)
    {
        strcat(pchrArrCalleYNumero," ext. ");
        strcat(pchrArrCalleYNumero,(const char *)zVentaOrden["NumExterior"]);
    }
    if(zVentaOrden["NumInterior"]!=NULL)
    {
        strcat(pchrArrCalleYNumero," int. ");
        strcat(pchrArrCalleYNumero,(const char *)zVentaOrden["NumInterior"]);
    }
    arrayFactura[12].valor = pchrArrCalleYNumero;
    arrayFactura[14].valor = (const char *)zVentaOrden["Colonia"];
    arrayFactura[15].valor = (const char *)zVentaOrden["DelegMunic"];
    arrayFactura[16].valor = (const char *)zVentaOrden["CodigoPostal"];
    arrayFactura[17].valor = (const char *)zVentaOrden["InstruccionesE"];
    arrayFactura[29].valor = (const char *)(*zVentaOrden.Orden())["Total"];
    arrayFactura[31].valor = (const char *)zVentaOrden["Dia"];
    arrayFactura[32].valor = (const char *)zVentaOrden["Mes"];
    arrayFactura[33].valor = (const char *)zVentaOrden["Anio"];
    int i;
    for(i=0;i<34;i++)
    {
        LogSiscom("Dato[%d] - %s",i,arrayFactura[i].valor);
    }
}

void QtImprimeFactura::factura( QPainter *p, zVenta & zVentaOrden )
{    
    int i = 0, y = 0,lintTamanioFuenteImpresion;
    char lchrArrConcepto[100], *pchrArrRespuestaVarAmbiente;
    pchrArrRespuestaVarAmbiente = getenv("TAMANIO_FONT_IMPRESION");
    if(pchrArrRespuestaVarAmbiente != NULL)
        lintTamanioFuenteImpresion = atoi(pchrArrRespuestaVarAmbiente);
    else 
        lintTamanioFuenteImpresion = 8;
    QFont font("Roman",lintTamanioFuenteImpresion);
    font.setBold(true);
    p->setFont(font);
    //Agregamos valores de zVenta
    
    while(arrayFactura[i].y)
    {
        if((i<20)||(i>24))p->drawText(arrayFactura[i].x,arrayFactura[i].y,arrayFactura[i].valor);
        i++;
    }
    //Agregamos productos.
    zProductos *lzProductos=zVentaOrden.Orden()->Productos();
    zProducto *lzProducto;
    for(lzProducto=(zProducto *)lzProductos->Primer();
        lzProducto;
        lzProducto=(zProducto *)lzProductos->Siguiente())
    {
        p->drawText(arrayFactura[20].x,arrayFactura[20].y+y,(const char *)(*lzProducto)["modelo"]);
        p->drawText(arrayFactura[21].x,arrayFactura[21].y+y,"1");
        strcpy(lchrArrConcepto,(const char *)(*lzProducto)["nombreproducto"]);
        if(strlen(lchrArrConcepto)>40) lchrArrConcepto[40]='\0';
        p->drawText(arrayFactura[22].x,arrayFactura[22].y+y,lchrArrConcepto);
        p->drawText(arrayFactura[23].x,arrayFactura[23].y+y,(const char *)(*lzProducto)["preciogeneral"]);
        p->drawText(arrayFactura[24].x,arrayFactura[24].y+y,(const char *)(*lzProducto)["Importe"]);
        y+=15;
    }
}

