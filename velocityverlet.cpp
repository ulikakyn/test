#include "velocityverlet.hpp"

VelocityVerlet::VelocityVerlet(World& W, Potential& Pot, Observer& O)
    : TimeDiscretization(W, Pot, O)
{
    // empty constructor
}

VelocityVerlet::VelocityVerlet(World& W, Potential* Pot, Observer& O)
    : TimeDiscretization(W, (*Pot), O)
{
    // empty constructor
}

void VelocityVerlet::simulate()
{
    std::cout << "Start." << std::endl;
    O.notify();
    compute_Force();
    // while simulation end time not reached
    while (W.t < W.t_end && W.particles.size() > 0) {
        timestep(W.delta_t);
    }
    std::cout << std::endl << "End." << std::endl;
}

void VelocityVerlet::timestep(real delta_t)
{
    std::cout << "\rTime: " << W.t << "        ";

    W.e_kin = 0.0;
    W.e_pot = 0.0;

    update_X();
    compute_Force();
    update_V();

    // increase time
    W.t += delta_t;

    // notify observer
    O.notify();
}

void VelocityVerlet::compute_Force()
{
}

void VelocityVerlet::update_V()
{
}

void VelocityVerlet::update_X()
{
}

// vim:set et sts=4 ts=4 sw=4 ai ci cin:
