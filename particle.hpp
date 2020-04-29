#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "defines.hpp"

/**
 * @brief Particle data
 *
 * this class contains the particle data
 */
class Particle
{
public:
    /// Mass
    real m;
    /// Position
    real x[DIM];
    /// Velocity
    real v[DIM];
    /// Force
    real F[DIM];
    /// Force (previous step)
    real F_old[DIM];
};

#endif  // PARTICLE_HPP
// vim:set et sts=4 ts=4 sw=4 ai ci cin:
