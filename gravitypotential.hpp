#ifndef GRAVITYPOTENTIAL_HPP
#define GRAVITYPOTENTIAL_HPP

#include "potential.hpp"

/**
 * @brief TODO add the documentation
 */
class GravityPotential : public Potential
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
    virtual real force(Particle& p, Particle& q);
};

#endif  // GRAVITYPOTENTIAL_HPP
// vim:set et sts=4 ts=4 sw=4 ai ci cin:
