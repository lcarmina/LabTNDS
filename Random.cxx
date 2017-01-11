#include "Random.h"

#include <cmath>
#include <cstdlib>
#include <iostream>

Random::Random(unsigned int seed) {
  m_a = 1664525;
  m_c = 1013904223;
  m_m = 1<<31;
  m_seed = seed;
}

double Random::Rand(double xmin, double xmax) {
  m_seed = (m_a*m_seed+m_c)%m_m;
  return xmin+(xmax-xmin)*double(m_seed)/double(m_m);
}

double Random::Gaus(double mean, double sigma) {
  double s=Rand();
  double t=Rand();
  double x=sqrt(-2.*log(s))*cos(2.*M_PI*t);
  return mean+x*sigma; 
}
