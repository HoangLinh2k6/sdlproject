#ifndef ENERGY_H
#define ENERGY_H

struct Energy{
    int energy = 0;
    bool useEnergy = false;
    void use();
    void updateEnergy();

};

#endif // ENERGY_H
