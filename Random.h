#ifndef __RANDOM_H__
#define __RANDOM_H__

//#include "Vettore.h"

class Random {

public:
 Random(unsigned int seed=1);
 void SetA(unsigned int a) {m_a=a;}
 void SetC(unsigned int c) {m_c=c;}
 void SetM(unsigned int m) {m_m=m;}
 void SetSeed(unsigned int seed) {m_seed=seed;}

 double Rand(double xmin=0., double xmax=1.);   // distribuzione uniforme
 double Gaus(double mean=0., double sigma=1.);  // distribuzione gaussiana

private:
 unsigned int m_a, m_c, m_m;
 unsigned int m_seed;
};

#endif
