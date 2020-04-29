#include "observer.hpp"

Observer::Observer(World& W) : W(W)
{
    // open statistics file
    std::string statistics_filename = W.name + ".statistics";
    // open file, overwrite existing files, take no prisioners
    statistics.open(statistics_filename.c_str());
    // and tell the world
    std::cout << "Opened " << statistics_filename << " for writing."
              << std::endl;
}

Observer::~Observer()
{
    // close the statistics file
    if (statistics.is_open())
        statistics.close();
}

void Observer::output_statistics()
{
    // write statistics into the filestream, seperated with tabulars
    statistics << W.t << "\t" << W.e_pot << "\t" << W.e_kin << "\t"
               << std::endl;
}

void Observer::output_coordinates()
{
}

void Observer::notify()
{
    // call output functions
    output_statistics();
    output_coordinates();
}

// vim:set et sts=4 ts=4 sw=4 ai ci cin:
