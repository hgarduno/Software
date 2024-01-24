#!/bin/sh


cat > Prueba.c << EOF
int main()
{

printf("Hola Mundo\n");

}
EOF

cc -o Prueba Prueba.c 
