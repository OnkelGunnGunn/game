#include "state.hpp"

int State::rng(int min, int max){
    static std::mt19937 generator(std::random_device{}());
    return std::uniform_int_distribution<>(min, max)(generator);
}

void State::clear_screen()
{
    std::cout << "\033[2J\033[1;1H" << std::flush;
}

void State::spacing()
{
    std::cout << std::endl;
    std::cout << std::endl;
}
