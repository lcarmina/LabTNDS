#ifndef __INTEGRALE_H__
#define __INTEGRALE_H__

#include "Funzioni.h" 
#include "Random.h"

class Integral {
  
 public:
  Integral (): _myrand(4){ ;};
  ~Integral() {;};

  double IntegraleAVE(double xmin, double xmax, FunzioneBase * f, int punti, int ncores) ;

 private:

  Random _myrand ;

};

#endif // __INTEGRALE_H__
