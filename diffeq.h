#ifndef DIFFEQ_H
#define DIFFEQ_H

float euler(float (*)(float, float), float, float, float, int);
float modified_euler(float (*)(float, float), float, float, float, int);
float runge_kutta(float (*)(float, float), float, float, float, int);

#endif
