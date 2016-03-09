# Answers

## Pregunta 1
1. Los pasos del proceso de Compilacion son:
  1. *Pre-procesador*: Sintaxis:"gcc -E .c -o .pp_c" Hace un chequeo de las sentencias y procesa las directivas como #include.
  2. Compilacion I:  Sintaxis:"gcc -masm=intel -S .c -o .asm" Hace un "transpiler" desde C a Assember.
                     Genera un archivo en codigo assember .asm
  3. *Compilacion II*: Sintaxis: "gcc -c .c -o .o"  Hace un pasaje de código de assembler a lenguaje de máquina binario.
                      Genera un objeto a partír del código en assembler.
                      Aun se puede observar algunas entidades con "nm"
  4. *Linkeo*:         Sintaxis: "gcc OBJECTS -o .e" Hace un linkeo de entre las librerias necesarias
                      (que pueden contener funciones, etc) y el código binario.
                      Genera un archivo ejecutable a partír de los archivos objetos
## Pregunta 2
2. El preproceso agrego un archivo de c preprocesado, donde se encarga de los #, por ejemplo, incluye todo el codigo de #include de manera recursiva.
  Por lo tanto, incluye todo el codigo que se encuentra en "calculator.h" y en "stdio.h".
  *Osea, copia y pega codigo*.

## Pregunta 3
3. Las funciones en c son main y add_numbers
      1. *main*
      Linea 10: Se define main: main:

      2. *add_numbers*
      Linea 23 llama a add_numbers:   call	add_numbers
      Linea 39 se define add_numbers: add_numbers:

## Pregunta 4
4. Los simbolos que se crean en el objeto son funciones. Las mayusculas significan
que son accesibles desde fuera del programa.
   Las u corresponden a variables no definidas.
        000000000000003c T add_numbers
        0000000000000000 T main
                         U printf
## Pregunta 5
5. A primera vista (Usando "nm") pueden verse muchos más simbolos, entre los que se encuentran los del .o. Por ejemplo, U printf, ahora contiene el @ y donde buscarla.
   El resto de los simbolos corresponden a funciones necesarias para que el programa en binario pueda ser ejecutado por el sistema operativo para que fue compilado.

```
0000000000400569 T add_numbers
0000000000601040 B __bss_start
0000000000601040 b completed.6973
0000000000601030 D __data_start
0000000000601030 W data_start
0000000000400470 t deregister_tm_clones
00000000004004e0 t __do_global_dtors_aux
0000000000600e18 t __do_global_dtors_aux_fini_array_entry
0000000000601038 D __dso_handle
0000000000600e28 d _DYNAMIC
0000000000601040 D _edata
0000000000601048 B _end
00000000004005f4 T _fini
0000000000400500 t frame_dummy
0000000000600e10 t __frame_dummy_init_array_entry
0000000000400778 r __FRAME_END__
0000000000601000 d _GLOBAL_OFFSET_TABLE_
                 w __gmon_start__
00000000004003e0 T _init
0000000000600e18 t __init_array_end
0000000000600e10 t __init_array_start
0000000000400600 R _IO_stdin_used
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
0000000000600e20 d __JCR_END__
0000000000600e20 d __JCR_LIST__
                 w _Jv_RegisterClasses
00000000004005f0 T __libc_csu_fini
0000000000400580 T __libc_csu_init
                 U __libc_start_main@@GLIBC_2.2.5
000000000040052d T main
                 U printf@@GLIBC_2.2.5
00000000004004a0 t register_tm_clones
0000000000400440 T _start
0000000000601040 D __TMC_END__
```
