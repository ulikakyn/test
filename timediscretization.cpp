#include "timediscretization.hpp"

TimeDiscretization::TimeDiscretization(World& W, Potential& Pot, Observer& O)
    : W(W), Pot(Pot), O(O)
{
}

// vim:set et sts=4 ts=4 sw=4 ai ci cin:
