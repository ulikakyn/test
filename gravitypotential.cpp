#include "gravitypotential.hpp"
#include<vector>

real abs(const std::vector<real> &v){ //Berechnet die 2-Norm eines Vektors
 real a;
 for(unsigned int i = 0; i < v.size(); i++){
   a += sqr(v[i]);
 }
 a = sqrt(a);
 return a;//sqrt takes double and x,y are reals
}
real GravityPotential::force(Particle& p, Particle& q){
  real r_ij[DIM]; //Richtungsvektor zwischen partikel p und q
  real r; //Betrag von r_ij
  real Ur; //Gravitationspotential
  real F_ij[DIM]; //Kraft die p auf q ausübt
  real D_ij[DIM]; //PLatzhalter für die alte Kraft

  for(unsigned int i = 0; i < DIM; i++){
    r_ij[i] = q.x[i] - p.x[i];
  } //Berechne den Richtungsvektor zwischen p und q

  r = abs(r_ij); //Betrag vom Richtungsvektor

  Ur = -p.m * q.m / r; //Gravitationspotential

  for(unsigned int i = 0; i < DIM; i++){
    F_ij[i] = r_ij[i]*Ur / sqr(r);
  } //Berechne die Kraft von p auf q

  for(unsigned int i = 0; i < DIM; i++){
    D_ij[i] = p.F[i];
    p.F[i] = p.F_old[0] + F_ij[i];
    p.F_old[i] = D_ij[i];
  } //Aktualisiere die Kraft von p

  return Ur;
}


// vim:set et sts=4 ts=4 sw=4 ai ci cin:
