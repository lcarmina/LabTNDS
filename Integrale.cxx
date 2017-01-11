#include "Integrale.h"
#include <iostream>
#include <cmath>
#include <omp.h>

using namespace std;

double Integral::IntegraleAVE(double xmin, double xmax, FunzioneBase * f, int punti, int ncores) {

  double I = 0;

  cout << "This machine has " <<  omp_get_num_procs() << " cores" << endl;
  cout << "Starting the integration using " << ncores << " threads" << endl;

  double startTime = omp_get_wtime();

  // open the parallel session

#pragma omp parallel num_threads( ncores ) 
  {  
    
    // this is the part I'm not very happy with. I need to create a generator here if
    // I want it to be private ( ie one generator per thread ) 
    // For the function I suspect all threads will still use the same causing the program
    // to slow down. Is this the only way to go ? Looks like openMP does not allow class
    // members to be passed as private : if I use _myrandom ( class memebr ) instead
    // of myrand below I slow down the program, I guess because all threads actually
    // uses the same generator
    
    // myf points to the same function for all threads ? I hope there are no problems
    // in having different threads accessing the same function but the performance 
    // is lower

    FunzioneBase * myf = f;
    Random myrand ( omp_get_thread_num() );
    double fmed=0;
    
#pragma omp for    
    
    for (int i=0; i<punti;  i++ ) {
      double x = myrand.Rand(xmin , xmax );
      fmed += myf->Eval(x) ;
      //fmed += x ;
    }
        
#pragma omp critical 
    {
      I = I + fmed;
    }    
    
  }

  I= I/ double(punti) * (xmax-xmin); 
  
  double stopTime = omp_get_wtime();
  double secsElapsed = stopTime - startTime;
  
  cout << "It took me " << secsElapsed << " seconds to compute the integral as " << I << endl;

  return I ;

}


