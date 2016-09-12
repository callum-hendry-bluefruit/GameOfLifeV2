#ifndef LIFE_INCLUDED
#define LIFE_INCLUDED

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <chrono>
#include <thread>

class Grid
{
private:
    std::vector< std::vector<int>> m_grid;

    void InitaliseGrid();
    void PrintGrid();

    int m_size_y;
    int m_size_x;

public:
    Grid(int size_y, int size_x);

    std::vector< std::vector<int>> ReturnGrid();

    char GetGridValue(int y, int x);

    int GetSizeY();
    int GetSizeX();
    
    void ToggleCell(int y, int x);
    void UserChosenStartLocations();
};



class Life
{
private:
    std::vector< std::vector<int> > m_life_grid;
    std::vector< std::vector<int> > m_staging_grid;

    std::array<int, 8> m_current_surroundings;

    void ToggleCell(int y, int x);

    int m_size_x;
    int m_size_y;

    void StagingToActual();

    int ReturnLiveNeighboursCount(int y, int x);

    bool ScanCells();
    bool CheckForOneOrLessLiveNeighbours(int y, int x);
    bool CheckForFourOrMoreLiveNeighbours(int y, int x);
    bool CheckForThreeLiveNeighboursIfDead(int y, int x);

public:
    Life(std::vector< std::vector<int> >, int size_y, int size_x);
    ~Life();

    void Start(int num_of_generations = 1); //if no variable, assume 1 for testing purposes
    void PrintGrid();
    void PrintStagingGrid();

    char GetGridValue(int y, int x);
    char GetStagingGridValue(int y, int x);
};

static void waitForOneSecond()
{
    using namespace std::this_thread;
    using namespace std::chrono;
    sleep_until(system_clock::now() + milliseconds(500));
}

#endif