#include <iostream>
#include <cmath>
#include "Integrale.h"
#include "Funzioni.h"
#include "omp.h"
#include <stdlib.h>

using namespace std;

/* ========================================================
   
   Here I want to calculate the integrale of a FunzioneBase
   using a MC based techique ( the average function ) using
   n extractions. I will try to parallelise the code

   ======================================================== */

int main( int argc, char** argv) {
  
  FunzioneBase * FSeno = new FunzioneSeno();
  Integral Integrator;

  double xmin = 0. ;
  double xmax = M_PI ;

  // number of extraction

  int punti = 200000000 ;

  // compute the integral with the same number of points but
  // increasing number of cores 1-4 anche check timinig
  // The parallelisation is performed in IntegraleAVE method.

  for ( int ncores = 1 ; ncores < 10 ; ncores ++) {
    cout << Integrator.IntegraleAVE(xmin,xmax,FSeno, punti , ncores) << endl ;
  }

  return 0;
}
