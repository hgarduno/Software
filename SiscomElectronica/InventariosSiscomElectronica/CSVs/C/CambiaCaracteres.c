#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        // Detecta el primer byte de la secuencia (0xE7 / -25)
        if ((unsigned char)c == 0xE7) {
            int c2 = getchar();
            int c3 = getchar();

            // Si coincide la secuencia completa de 3 bytes: 0xE7 0x95 0xAA
            if (c2 != EOF && c3 != EOF && (unsigned char)c2 == 0x95 && (unsigned char)c3 == 0xAA) {
                // Escribe 'μ' en UTF-8 (0xCE 0xBC)
		//printf("%s","µf");
		 putchar(0xb5); 
		 putchar(0x66); //pongo la f
            } else {
                // Si no coincide, imprime los bytes tal cual
                putchar(c);
                if (c2 != EOF) putchar(c2);
                if (c3 != EOF) putchar(c3);
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}
