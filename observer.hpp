#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "world.hpp"
#include <fstream>
#include <iostream>

/**
 * @brief an observer for the timediscretization
 */
class Observer
{
public:
    /**
     * @brief constructor
     *
     * opens and creates the files written during observation
     *
     * @param W
     */
    Observer(World& W);

    /**
     * @brief destructor
     *
     * closes the files written during the obervation
     */
    ~Observer();

    /**
     * @brief notify the observer that the world has changed
     */
    void notify();

    /**
     * @brief output statistics like kinetic, potential and total energy
     */
    void output_statistics();

    /**
     * @brief output the coordinates of the particles
     */
    void output_coordinates();

protected:
    /// The world we are observing
    World& W;
    /// Statistics filestream
    std::ofstream statistics;
    /// coordiantes filestream
    std::ofstream coordinates;
    /// xyz filestream
    std::ofstream xyz;

private:
    /// Disabled Constructor
    Observer();
};

#endif  // OBSERVER_HPP
// vim:set et sts=4 ts=4 sw=4 ai ci cin:
