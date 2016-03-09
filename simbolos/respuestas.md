# Respuestas a la segunda parte de wtpc2016 Dia 3: HOcompiled

Se realiza la compilacion II (generamos los objetos).

```
$ nm visibility.o
0000000000000000 t add_abs
000000000000002a T main
                 U printf
0000000000000000 r val1
0000000000000004 R val2
0000000000000000 d val3
0000000000000004 D val4

```
1. Se pueden observar:
    1. **Distancia de memoria** desde el comienzo (0000000000000000)
    2. **Descriptores**
        Mayusculas para Descriptores accesibles desde el exterior del objeto. (Fuente:
           [https://sourceware.org/binutils/docs/binutils/nm.html] )
        1. t The symbol is in the text (code) section.
        2. u The symbol is undefined.
        3. r The symbol is in a read only data section.
        4. d The symbol is in the initialized data section.
    3. **Entrada** corresponde a la identificación (nombre) de cada "seccion/simbolo"
