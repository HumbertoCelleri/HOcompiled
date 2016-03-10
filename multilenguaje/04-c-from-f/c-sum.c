#include <stdlib.h>
#include "c-sum.h"

int sum_abs_(int *in, int *num, int *asum) {
   int i;

   for (i=0,*asum=0; i < *num; ++i) {
       *asum += abs(in[i]); // al entrar a la lista ya Des-referencia
   }
   return 0;
}
