//
// Created by elsa on 13.04.2020.
//

#ifndef TREFUSISENGINE_FILEREADER_H
#define TREFUSISENGINE_FILEREADER_H

#include <string>
#include "../objects/Actor.h"
#include "../objects/EnviromentalActor.h"

Actor importActor(std::string fileName);
EnviromentalActor importEnviromentalActor(std::string fileName);

#endif //TREFUSISENGINE_FILEREADER_H
