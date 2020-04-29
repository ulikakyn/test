#ifndef POTENTIAL_HPP
#define POTENTIAL_HPP

#include "particle.hpp"
#include <math.h>

/**
 * @brief abstract Potential class
 */
class Potential
{
public:
    /**
     * @brief calculate the force bewteen the two particles and add it to p
     *
     * @param p particle p
     * @param q particl q
     *
     * @return potential energy
     */
    virtual real force(Particle& p, Particle& q) = 0;
};

#endif  // POTENTIAL_HPP
// vim:set et sts=4 ts=4 sw=4 ai ci cin:
