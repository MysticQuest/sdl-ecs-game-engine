#include "MyMath.h"
#include <random>

std::mt19937& RNG::getGenerator()
{
    static std::mt19937 gen(std::random_device{}());
    return gen;
}

int RNG::Int(int lower, int upper)
{
    return std::uniform_int_distribution<>(lower, upper)(getGenerator());
}

float RNG::Float(float lower, float upper)
{
    return std::uniform_real_distribution<float>(lower, upper)(getGenerator());
}


