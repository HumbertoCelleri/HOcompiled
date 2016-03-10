# Respuestas a la tercera parte de wtpc2016 Dia 3: HOcompiled


Lo importante es corroborar en los objetos:
  1. **memory management**
  2. symbol ID (**Decoradores**)

Teniendo en cuenta que: *Fortran pasa todo por punteros!*

## Ejercicios

### c from f
En este caso queremos utilizar una subrutina de suma en c y utilizarla en codigo en fortran.

Debemos dar especial cuidado al decocador de la subrutina en c:
```
nm f-main_f90.o
                 U _gfortran_set_args
                 U _gfortran_set_options
                 U _gfortran_st_write
                 U _gfortran_st_write_done
                 U _gfortran_transfer_character_write
                 U _gfortran_transfer_integer_write
00000000000000e2 T main
0000000000000000 t MAIN__
0000000000000020 r options.1.1891
                 U sum_abs_

```
```
nm c-sum_c.o
0000000000000000 T sum_abs

```
y a que Fortran utiliza punteros. Por lo tanto se debe definir la sub-rutina con punteros:
```
int sum_abs_(int *in, int *num, int *asum)
```



### f from c
En este caso queremos utilizar una subrutina de suma en f y utilizarla en codigo en C. (Como en el ejemplo de la teoría)


### cpp from c
En este caso queremos utilizar una subrutina de suma en C++ y utilizarla en codigo en C.

```
                 U __cxa_atexit
                 U __dso_handle
00000000000000e7 t _GLOBAL__sub_I_main
0000000000000000 T main
00000000000000aa t _Z41__static_initialization_and_destruction_0ii
                 U _Z7sum_absPKii
0000000000000008 r _ZL3NUM
                 U _ZNSolsEi
                 U _ZNSolsEPFRSoS_E
                 U _ZNSt8ios_base4InitC1Ev
                 U _ZNSt8ios_base4InitD1Ev
                 U _ZSt4cout
                 U _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
0000000000000000 b _ZStL8__ioinit
                 U _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc

```

```
0000000000000000 T main
                 U printf
                 U sum_abs

```
