#ifndef FIGHT_H
#define FIGHT_H

#include "fighter.h"

void fight(Fighter &f1, Fighter &f2);
void start_tournament(Fighter fighters[], int fighter_count);
float compute_power(Fighter &f, Fighter &op);



#endif
