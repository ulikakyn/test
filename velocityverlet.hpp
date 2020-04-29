#ifndef VELOCITYVERLET_HPP
#define VELOCITYVERLET_HPP

#include "timediscretization.hpp"

/**
 * @brief Implementation of the Velocity Verlet Algorithm
 */
class VelocityVerlet : public TimeDiscretization
{
public:
    /**
     * @brief constructor
     *
     * @param W world configuration
     * @param Pot potential used for force calculation
     * @param O Observer of the simulation
     */
    VelocityVerlet(World& W, Potential& Pot, Observer& O);

    /**
     * @brief constructor
     *
     * This is an example for Constructor overloading. If you have read until
     * here you can use the other constructor and change the blatt1 main
     * function.
     *
     * @param W world configuration
     * @param Pot potential used for force calculation
     * @param O Observer of the simulation
     */
    VelocityVerlet(World& W, Potential* Pot, Observer& O);

    /**
     * @brief run a single timestep
     *
     * @param delta_t length of the timestep
     */
    virtual void timestep(real delta_t);

    /**
     * @brief run the simulation
     */
    virtual void simulate();

    /**
     * @brief calculares the forces affecting the particles at the current time
     */
    virtual void compute_Force();

    /**
     * @brief calculates the new velocity of the particles
     */
    virtual void update_V();

    /**
     * @brief calculate the new position of all particles according to their
     * velocity
     */
    virtual void update_X();

protected:
    // data structures inherited from TimeDiscretization

private:
    VelocityVerlet();
};

#endif  // VELOCITYVERLET_HPP
// vim:set et sts=4 ts=4 sw=4 ai ci cin:
