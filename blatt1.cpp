#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "gravitypotential.hpp"
#include "observer.hpp"
#include "velocityverlet.hpp"
#include "world.hpp"

int main(int argc, char* argv[])
{

    // check arguments
    if (argc < 2) {
        std::cerr << "error: missing arguments" << std::endl;
        std::cerr << "usage: " << std::endl
                  << "\t" << argv[0] << " parameterfile particledatafile"
                  << std::endl;
        return EXIT_FAILURE;
    }

    // instanciate Potential
    GravityPotential Pot;

    // create World
    World W;

    // read Parameters
    W.read_Parameter(argv[1]);

    // read Particles
    W.read_Particles(argv[2]);

    std::cout << W << std::endl;

    // create the Observer
    Observer O(W);

    // instanciate timediscretization
    // remark: & is used to get the address of Pot
    VelocityVerlet Verlet(W, &Pot, O);

    // run the simulation
    Verlet.simulate();

    return EXIT_SUCCESS;
}

// vim:set et sts=2 ts=2 sw=2 ai ci cin:
