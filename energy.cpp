#include "energy.h"

void Energy::use(){
    if( energy == 100 ){ useEnergy = true; }
}

void Energy::updateEnergy(){
    if( !useEnergy && energy < 100 ){ energy ++; }
    if( useEnergy ){ energy--; }
}
