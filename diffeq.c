#include "diffeq.h"

float euler(float (*pf)(float, float), float xi, float yi, float dx, int n)
{
   if (n == 0)
      return yi;

   return( euler(pf, xi + dx, yi + pf(xi, yi) * dx, dx, n - 1) );
}

float modified_euler(float (*pf)(float, float), float xi, float yi, float dx, int n)
{
   if (n == 0)
      return yi;

   return( modified_euler(pf, xi+dx, yi+dx/2*(pf(xi, yi)+pf(xi+dx, yi+pf(xi, yi)*dx)), dx, n-1) );
}

float runge_kutta(float (*pf)(float, float), float xi, float yi, float dx, int n)
{
   float k1, k2, k3, k4, xnext, ynext;

   if (n == 0)
      return yi;

   k1 = pf(xi, yi) * dx;
   k2 = pf(xi + dx/2, yi + k1/2) * dx;
   k3 = pf(xi + dx/2, yi + k2/2) * dx;
   k4 = pf(xi + dx, yi + k3) * dx;
   xnext = xi + dx;
   ynext = yi + (k1 + 2*k2 + 2*k3 + k4) / 6;
   return( runge_kutta(pf, xnext, ynext, dx, n - 1) );
}
