#include <cmath>
#include <string.h>
#include <iostream>

const int N = 10;
const double min_ = -1, max_ = 1; // у нас всё будет квадратное
const double dt = 0.001;
const double v = 1.0;

double coordinate(int index)
{
    return  min_ + (max_ - min_) / (double) (N * index);
}

double initState(double x, double y)
{
    return std::exp(-(x * x + y * y));
}

void printV(double state[N][N])
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
            std::cout << state[i][j] <<  " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{    
    double dy, dx;
    dx = dy = (max_ - min_) / N;
    double state[N][N];
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
        {
            double x = coordinate(i), y = coordinate(j);
            state[i][j] = initState(x, y);
        }
    double t = 0;
    const double maxT = 0.1;
    double prevState[N][N];
    do
    {
        memcpy(prevState, state, sizeof(prevState));
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
            {
                double x, y;
                x = (prevState[i == N - 1? 0 : i + 1][j] - 2 * prevState[i][j] + prevState[(i == 0) ? N - 1 : i - 1][j]) / dx / dx;
                y = (prevState[i][j == N - 1 ? 0 : j + 1] - 2 * prevState[i][j] + prevState[i][j == 0 ? N - 1 : j - 1]) / dy / dy;
                state[i][j] = prevState[i][j] + v * dt * (x + y);
            }

        printV(state);
        t += dt;
    } while(t < maxT);

    return 0;
}