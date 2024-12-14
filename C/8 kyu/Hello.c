#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// allocate memory for and then return a NULL-terminated C-string

char *hello(const char *name)
{
    char *Saludo = "Hello, ";

    if (name == NULL || name[0] == '\0')
    {
        char *last = "World!";
        char *definitive = (char *)malloc((strlen(Saludo) + strlen(last)) * sizeof(char));

        strncpy(definitive, Saludo, strlen(Saludo));
        strncat(definitive, last, strlen(last));

        return definitive;
    }
    else
    {
        int size = strlen(name);
        int i = 0;

        //Reservo memoria para una cadena del tamaño de size + 1
        char *n = (char *)malloc((size + 1) * sizeof(char));

        //Copio la cadena name a n y le pongo el caracter nulo
        strncpy(n, name, size);
        n[size] = '\0';

        //Paso toda la cadena a minusculas
        while(n[i] != '\0')
        {
            n[i] = tolower(n[i]);
            i++;
        }
        n[0] = toupper(n[0]);

        //Creo la cadena definitiva
        char *definitive = (char *)malloc((strlen(Saludo) + size + 1 + 1) * sizeof(char));

        //Añado el saludo
        strncpy(definitive, Saludo, strlen(Saludo));

        //Añado el nombre y la exclamacion
        char c = '!';
        strncat(definitive, n, size);
        size_t len = strlen(definitive);
        definitive[len] = c;
        definitive[len + 1] = '\0';

        free(n);

        return definitive;
    }
}

/*
int main(void)
{
    char *texto = hello("");

    printf("%s\n", texto);

     free(texto);
}
*/