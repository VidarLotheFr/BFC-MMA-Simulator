// storage.h
#ifndef STORAGE_H
#define STORAGE_H

#include "fighter.h"
#include <string>

// Save all fighters to a file
void save_fighters(const Fighter fighters[], int count, const std::string &filename);

// Load fighters from a file
int load_fighters(Fighter fighters[], int max_count, const std::string &filename);


#endif
