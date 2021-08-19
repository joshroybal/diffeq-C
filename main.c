#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diffeq.h"

int main(int argc, char *argv[])
{
   float a, b, n, dx, y0, y;

   float f(float, float);
   float g(float, float);
   float (*pf)(float (*)(float, float), float, float, float, int);

   if (argc < 5) {
      fprintf(stderr, "Usage: %s y0 a b n Euler|Modified-Euler|Runge-Kutta\n",
            argv[0]);
      exit(1);
   }

   y0 = atof(argv[1]);
   a = atof(argv[2]);
   b = atof(argv[3]);
   n = atoi(argv[4]);
   
   if (strcmp(argv[5], "Runge-Kutta") == 0)
      pf = &runge_kutta;
   else if (strcmp(argv[5], "Modified-Euler") == 0)
      pf = &modified_euler;
   else
      pf = &euler;

   dx = (b - a) / n;
   printf("dx = %f\n", dx);

   y = pf(&f, a, y0, dx, n);
   printf("y(%f) = %f\n", b, y);
   return(0);
}

float f(float x, float y)
{
   return(x - y);
}

float g(float x, float y)
{
   return(x + y);
}
