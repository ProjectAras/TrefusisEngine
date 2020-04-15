//
// Created by elsa on 13.04.2020.
//

#ifndef TREFUSISENGINE_CHARACTER_H
#define TREFUSISENGINE_CHARACTER_H


class Character {
private:
    float baseHealth;
    float baseSpeed;
public:
    int x;
    int y;
    void track(Character other);
};


#endif //TREFUSISENGINE_CHARACTER_H
