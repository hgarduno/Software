#include "QBarCode.h"

const char barras_128b[][6] = {
        {2,1,2,2,2,2},//SP
        {2,2,2,1,2,2},//!
        {2,2,2,2,2,1},//"
        {1,2,1,2,2,3},//#
        {1,2,1,3,2,2},//$
        {1,3,1,2,2,2},//%
        {1,2,2,2,1,3},//&
        {1,2,2,3,1,2},//'
        {1,3,2,2,1,2},//(
        {2,2,1,2,1,3},//)
        {2,2,1,3,1,2},//*
        {2,3,1,2,1,2},//+
        {1,1,2,2,3,2},//´
        {1,2,2,1,3,2},//-
        {1,2,2,2,3,1},//.
        {1,1,3,2,2,2},///
        {1,2,3,1,2,2},//0
        {1,2,3,2,2,1},//1
        {2,2,3,2,1,1},//2
        {2,2,1,1,3,2},//3
        {2,2,1,2,3,1},//4
        {2,1,3,2,1,2},//5
        {2,2,3,1,1,2},//6
        {3,1,2,1,3,1},//7
        {3,1,1,2,2,2},//8
        {3,2,1,1,2,2},//9
        {3,2,1,2,2,1},//:
        {3,1,2,2,1,2},//;
        {3,2,2,1,1,2},//<
        {3,2,2,2,1,1},//=
        {2,1,2,1,2,3},//>
        {2,1,2,3,2,1},//?
        {2,3,2,1,2,1},//@
        {1,1,1,3,2,3},//A
        {1,3,1,1,2,3},//B
        {1,3,1,3,2,1},//C
        {1,1,2,3,1,3},//D
        {1,3,2,1,1,3},//E
        {1,3,2,3,1,1},//F
        {2,1,1,3,1,3},//G
        {2,3,1,1,1,3},//H
        {2,3,1,3,1,1},//I
        {1,1,2,1,3,3},//J
        {1,1,2,3,3,1},//K
        {1,3,2,1,3,1},//L
        {1,1,3,1,2,3},//M
        {1,1,3,3,2,1},//N
        {1,3,3,1,2,1},//O
        {3,1,3,1,2,1},//P
        {2,1,1,3,3,1},//Q
        {2,3,1,1,3,1},//R
        {2,1,3,1,1,3},//S
        {2,1,3,3,1,1},//T
        {2,1,3,1,3,1},//U
        {3,1,1,1,2,3},//V
        {3,1,1,3,2,1},//W
        {3,3,1,1,2,1},//X
        {3,1,2,1,1,3},//Y
        {3,1,2,3,1,1},//Z
        {3,3,2,1,1,1},//[
        {3,1,4,1,1,1},//\/
        {2,2,1,4,1,1},//]
        {4,3,1,1,1,1},//^
        {1,1,1,2,2,4},//_
        {1,1,1,4,2,2},//`
        {1,2,1,1,2,4},//a
        {1,2,1,4,2,1},//b
        {1,4,1,1,2,2},//c
        {1,4,1,2,2,1},//d
        {1,1,2,2,1,4},//e
        {1,1,2,4,1,2},//f
        {1,2,2,1,1,4},//g
        {1,2,2,4,1,1},//h
        {1,4,2,1,1,2},//i
        {1,4,2,2,1,1},//j
        {2,4,1,2,1,1},//k
        {2,2,1,1,1,4},//l
        {4,1,3,1,1,1},//m
        {2,4,1,1,1,2},//n
        {1,3,4,1,1,1},//o
        {1,1,1,2,4,2},//p
        {1,2,1,1,4,2},//q
        {1,2,1,2,4,1},//r
        {1,1,4,2,1,2},//s
        {1,2,4,1,1,2},//t
        {1,2,4,2,1,1},//u
        {4,1,1,2,1,2},//v
        {4,2,1,1,1,2},//w
        {4,2,1,2,1,1},//x
        {2,1,2,1,4,1},//y
        {2,1,4,1,2,1},//z
        {4,1,2,1,2,1},//{
        {1,1,1,1,4,3},//|
        {1,1,1,3,4,1},//}
        {1,3,1,1,4,1},//%
        {1,1,4,1,1,3},//DEL
        {1,1,4,3,1,1},//F3
        {4,1,1,1,1,3},//F2
        {4,1,1,3,1,1},//CMB
        {1,1,3,1,4,1},//C-C
        {1,1,4,1,3,1},//F4
        {3,1,1,1,4,1},//C-A
        {4,1,1,1,3,1},//F1
        {2,1,1,4,1,2},//INICIO CODIGO A
        {2,1,1,2,1,4},//INICIO CODIGO B
        {2,1,1,2,3,2},//INICIO CODIGO C
        {5,3,1,1,1,2} //FINAL DE CODIGO
    };

char finalBarra[] = {2,3,3,1,1,1,2};

QBarCode::QBarCode( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
    IniciaVariables();
    //ConectaSlots();
}

void QBarCode::IniciaVariables()
{
    setBackgroundMode(PaletteBase);
    code = new QLabel(this);
    code->setBackgroundMode(PaletteBase);
    code->setText("Sin codigo");
    code->setAutoResize(true);
}

void QBarCode::ConectaSlots()
{
    //connect(QCBEjemplo,
    // SIGNAL(activated(const QString &)),
    // SLOT(SlotSelecciono(const QString &)));
}

void QBarCode::SlotMuestraCode(const QString &pQStr)
{ 
    //printf("Cambio el texto\n");
    QImage codigo;
    codigo = generaCodeBar128B(pQStr,2,25);
    code->setPixmap(codigo);
}

QPixmap QBarCode::generaCodeBar128B(const char* datos, int pixelBarra, int alto)
{
    int i, ancho, verificador,x,y,j,w;
    const char *ptr;
    ptr = datos;
    verificador = 0;
    j = 0;
    while(*ptr)
    {
        //printf("%c -> %3d", *ptr, *ptr-32);
        for(i=0; i<6 ; i++)
        {
            //printf(" %d", barras_128b[*ptr-32][i]);
        }
        verificador+=(*ptr-32)*(j+1);
        //printf(" -- Acumulador: %d\n",(*ptr-32)*(j+1));
        j++;
        ptr++;
    }
    //printf("Verificador%d - mod 103: %d\n", verificador, verificador%103);
    verificador%=103;

    ancho = 11+(strlen(datos)*11)+11+13;    //Inicio+Datos+Verificador+Final
    //printf("barras: %d\n", ancho);
    //printf("Pixeles del codigo: %d\n", ancho*pixelBarra);
    QPixmap imagen(ancho*pixelBarra,alto,1);
    QImage imageCodeBar(imagen.convertToImage());   //Convertimos QPixmap en QImagen para tratar pixeles.
    QRgb px;
    ptr = datos;    //Apuntamos al caracter inicial
    for (x = 0; x < imageCodeBar.width(); x++)
    {
        if (imageCodeBar.valid(x,0))
        {
            if(x < (11*pixelBarra))
            {
                /* Códificamos carácter inicial */
                //printf("Valor de X: %d (Inicio)\n", x);
                for(j=0;j<6;j++)
                {
                    for(w=0;w<(pixelBarra*barras_128b[inicioCodigo][j]);w++,x++) {
                        //printf("Barras %d - Color: %d -> x:%3d\n", barras_128b[inicioCodigo][j], j%2, x);
                        if(j%2) imageCodeBar.setPixel(x,0,PIXEL_BLANCO);
                        else imageCodeBar.setPixel(x,0,PIXEL_NEGRO);
                    }
                }
                x--;
            }
            else if(x>=((imageCodeBar.width()-(13*pixelBarra))))
            {
                /* Códificamos carácter de final de código */
                //printf("Valor de X: %d (Ultimo paso)\n", x);
                for(j=0;j<7;j++)
                {
                    for(w=0;w<(pixelBarra*finalBarra[j]);w++,x++) {
                        //printf("Barras %d - Color: %d \n", barras_128b[inicioCodigo][j], j%2);
                        if(j%2) imageCodeBar.setPixel(x,0,PIXEL_BLANCO);
                        else imageCodeBar.setPixel(x,0,PIXEL_NEGRO);
                    }
                }
            }
            else
            {
                /* Códificamos carácteres deseados */
                while(*ptr)
                {
                    //printf("Valor de X: %d (Caracter %c)\n", x, *ptr);
                    for(j=0;j<6;j++)
                    {
                        for(w=0;w<(pixelBarra*barras_128b[*ptr-32][j]);w++,x++) {
                            //printf("Barras %d - Color: %d \n", barras_128b[*ptr-33][j], j%2);
                            if(j%2) imageCodeBar.setPixel(x,0,PIXEL_BLANCO);
                            else imageCodeBar.setPixel(x,0,PIXEL_NEGRO);
                        }
                    }
                    ptr++;
                }
                /* Códificamos carácter verificador */
                //printf("Valor de X: %d (Caracter %c)\n", x, verificador+33);
                for(j=0;j<6;j++)
                {
                    for(w=0;w<(pixelBarra*barras_128b[verificador+1][j]);w++,x++) {
                        //printf("Barras %d - Color: %d \n", barras_128b[*ptr-33][j], j%2);
                        if(j%2) imageCodeBar.setPixel(x,0,PIXEL_BLANCO);
                        else imageCodeBar.setPixel(x,0,PIXEL_NEGRO);
                    }
                }
                x--;
            }
        }
    }
    //Rellenamos imagen, con datos e la primera fila de la imagen para crear las barras.
    for (y = 1; y < imageCodeBar.height(); y++)
    {
        for (x = 0; x < imageCodeBar.width(); x++)
        {
            if (imageCodeBar.valid(x,y))
            {
                px = imageCodeBar.pixel(x,0);
                //printf("Pixel[%d][%d]: %d\n",y,x,qGray(px));
                imageCodeBar.setPixel(x,y,(qGray(px))? PIXEL_BLANCO: PIXEL_NEGRO);
            }
        }
    }
    if(imageCodeBar!=NULL) printf("Codigo creado: \"%s\"\n",datos);
    QPixmap codBar(imageCodeBar);
    return codBar;
}

QPixmap QBarCode::generaCodeBar128BImprimir(const char* datos, int pixelBarra, int alto){
    int i, ancho, verificador,x,y,j,w;
    const char *ptr;
    ptr = datos;
    verificador = 0;
    j = 0;
    while(*ptr)
    {
        //printf("%c -> %3d", *ptr, *ptr-32);
        for(i=0; i<6 ; i++)
        {
            //printf(" %d", barras_128b[*ptr-32][i]);
        }
        verificador+=(*ptr-32)*(j+1);
        //printf(" -- Acumulador: %d\n",(*ptr-32)*(j+1));
        j++;
        ptr++;
    }
    //printf("Verificador%d - mod 103: %d\n", verificador, verificador%103);
    verificador%=103;

    ancho = 11+(strlen(datos)*11)+11+13;    //Inicio+Datos+Verificador+Final
    //printf("barras: %d\n", ancho);
    //printf("Pixeles del codigo: %d\n", ancho*pixelBarra);
    QPixmap imagen(ancho*pixelBarra,alto,1);
    QImage imageCodeBar(imagen.convertToImage());   //Convertimos QPixmap en QImagen para tratar pixeles.
    QRgb px;
    ptr = datos;    //Apuntamos al caracter inicial
    for (x = 0; x < imageCodeBar.width(); x++)
    {
        if (imageCodeBar.valid(x,0))
        {
            if(x < (11*pixelBarra))
            {
                /* Códificamos carácter inicial */
                //printf("Valor de X: %d (Inicio)\n", x);
                for(j=0;j<6;j++)
                {
                    for(w=0;w<(pixelBarra*barras_128b[inicioCodigo][j]);w++,x++) {
                        //printf("Barras %d - Color: %d -> x:%3d\n", barras_128b[inicioCodigo][j], j%2, x);
                        if(j%2) imageCodeBar.setPixel(x,0,PIXEL_BLANCO);
                        else imageCodeBar.setPixel(x,0,PIXEL_NEGRO);
                    }
                }
                x--;
            }
            else if(x>=((imageCodeBar.width()-(13*pixelBarra))))
            {
                /* Códificamos carácter de final de código */
                //printf("Valor de X: %d (Ultimo paso)\n", x);
                for(j=0;j<7;j++)
                {
                    for(w=0;w<(pixelBarra*finalBarra[j]);w++,x++) {
                        //printf("Barras %d - Color: %d \n", barras_128b[inicioCodigo][j], j%2);
                        if(j%2) imageCodeBar.setPixel(x,0,PIXEL_BLANCO);
                        else imageCodeBar.setPixel(x,0,PIXEL_NEGRO);
                    }
                }
            }
            else
            {
                /* Códificamos carácteres deseados */
                while(*ptr)
                {
                    //printf("Valor de X: %d (Caracter %c)\n", x, *ptr);
                    for(j=0;j<6;j++)
                    {
                        for(w=0;w<(pixelBarra*barras_128b[*ptr-32][j]);w++,x++) {
                            //printf("Barras %d - Color: %d \n", barras_128b[*ptr-33][j], j%2);
                            if(j%2) imageCodeBar.setPixel(x,0,PIXEL_BLANCO);
                            else imageCodeBar.setPixel(x,0,PIXEL_NEGRO);
                        }
                    }
                    ptr++;
                }
                /* Códificamos carácter verificador */
                //printf("Valor de X: %d (Caracter %c)\n", x, verificador+33);
                for(j=0;j<6;j++)
                {
                    for(w=0;w<(pixelBarra*barras_128b[verificador+1][j]);w++,x++) {
                        //printf("Barras %d - Color: %d \n", barras_128b[*ptr-33][j], j%2);
                        if(j%2) imageCodeBar.setPixel(x,0,PIXEL_BLANCO);
                        else imageCodeBar.setPixel(x,0,PIXEL_NEGRO);
                    }
                }
                x--;
            }
        }
    }
    //Rellenamos imagen, con datos e la primera fila de la imagen para crear las barras.
    for (y = 1; y < imageCodeBar.height(); y++)
    {
        for (x = 0; x < imageCodeBar.width(); x++)
        {
            if (imageCodeBar.valid(x,y))
            {
                px = imageCodeBar.pixel(x,0);
                //printf("Pixel[%d][%d]: %d\n",y,x,qGray(px));
                if((y>(imageCodeBar.height()*.6))&&((x>10)&&(x<(imageCodeBar.width()-10))))
                    imageCodeBar.setPixel(x,y,PIXEL_BLANCO);
                else imageCodeBar.setPixel(x,y,(qGray(px))? PIXEL_BLANCO: PIXEL_NEGRO);
            }
        }
    }
    if(imageCodeBar!=NULL) printf("Codigo creado: \"%s\"\n",datos);
    QPixmap codBar(imageCodeBar);
    return codBar;
}

