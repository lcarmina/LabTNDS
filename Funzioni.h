#ifndef __Funzioni_h__
#define __Funzioni_h__

#include <cmath>

// Classe astratta per una generica funzione
class FunzioneBase {
public:
  virtual double Eval(double x) const =0;
};

class FunzioneSeno : public FunzioneBase {
 public :
  virtual double Eval ( double x ) const {
    return sin(x);
  }
};

#endif

