#include "world.hpp"
#include <sstream>
#include <stdexcept>

World::World()
    : name("unknown"), t(0), delta_t(0), t_end(0), e_kin(0), e_pot(0), e_tot(0)
{
    // empty constructor
}

void World::read_Parameter(const std::string& filename)
{
    // create input filestream
    std::ifstream parfile(filename.c_str());
    // check if file is open
    if (!parfile.is_open())
        throw std::runtime_error("read_Parameter(): Can't open file '" +
                                 filename + "' for reading.");

    // helper strings
    std::string line, option;

    // read file till eof
    while (parfile.good()) {
        // init empty option
        option = "";
        // read line from file
        getline(parfile, line);
        // create a string stream
        std::stringstream strstr;
        // put line into string stream
        strstr << line;
        // read option and value from stringstream
        strstr >> option;
        // check options and read values
        if (option == "delta_t")
            strstr >> delta_t;
        else if (option == "t_end")
            strstr >> t_end;
    }
    // close file
    parfile.close();
}

void World::read_Particles(const std::string& filename)
{
    int i = 0;

    std::ifstream parfile(filename.c_str());
    if (!parfile.is_open())
        throw std::runtime_error("read_Particles(): Can't open file '" +
                                 filename + "' for reading.");
}

std::ostream& operator<<(std::ostream& os, World& W)
{
    os << "t=" << W.t << " delta_t=" << W.delta_t << " t_end=" << W.t_end
       << " Number of Particles=" << W.particles.size() << std::endl;

    return os;
}
// vim:set et sts=4 ts=4 sw=4 ai ci cin:
