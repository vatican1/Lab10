#include <vector>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <iostream>

const int partsAmount = 10;
const double leftBoarder = -1.0, rightBoarder = 1.0;
const double dt = 0.001;
const double v = 2.0;
const double T = 0.1;

void printV(double state[partsAmount])
{
    for(int i = 0; i < partsAmount; ++i)
        std::cout << state[i] << " ";
    std::cout << std::endl;
}

int main()
{
    // напишем для положительного v
    const double dx = (rightBoarder - leftBoarder) / (double) partsAmount;
    double TNow = 0;

    double initState[partsAmount];
    for(int i = 0; i < partsAmount; ++i)
    {
        double x = leftBoarder + (rightBoarder - leftBoarder) / (double) partsAmount * (double) i;
        initState[i] = std::exp(- x * x);
    }
    double prevState[partsAmount];
    memcpy(prevState, initState, sizeof(prevState));
    double difference;
    do
    {
        double state[partsAmount];
        for(int i = 0; i < partsAmount; ++i)
        {
            state[i] = (prevState[i] - v * dt / dx * (prevState[i] - prevState[(i != 0) ? (i - 1) : (partsAmount - 1)]));
        }
	TNow += dt;
        printV(state); // расскоментировать, чтобы увидеть выввод работы алгоритма
        memcpy(prevState, state, sizeof(prevState));
    } while(TNow < T);

    return 0;
}
