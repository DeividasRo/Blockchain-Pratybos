#ifndef TESTS_H
#define TESTS_H

#include <random>
#include <string>
#include <sstream>
#include <bitset>
#include <time.h>
#include <algorithm>
#include <random>
#include <chrono>
#include <numeric>

int CollisionTest(std::string (*)(std::string), int);

void AvalancheTest(std::string (*)(std::string), int, int[]);

#endif