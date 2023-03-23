#include <iostream>
#include <vector>
#include <climits>

class Solution
{
public:
    Solution(int pDistance, int pTankCapacity, std::vector<int> &pStationDistance);

    int getMinRefills();
    int distanceToTravel(int pDestination);
    int distanceToDestination();
    int distanceToStation(int pStation);

    void refill(int pStation);

private:
    int startPos;
    int destDistance;
    int tankCapacity;
    int fuelLeft;
    int numRefills;
    std::vector<int> stationDistance;
};

Solution::Solution(int pDistance, int pTankCapacity, std::vector<int> &pStationDistance)
{
    destDistance = pDistance;
    tankCapacity = pTankCapacity;
    stationDistance = pStationDistance;
    stationDistance.push_back(INT_MAX);
    startPos = 0;
    numRefills = 0;
    fuelLeft = tankCapacity;
}

int Solution::distanceToTravel(int pDestination)
{
    return pDestination - startPos;
}

int Solution::distanceToDestination()
{
    return distanceToTravel(destDistance);
}

int Solution::distanceToStation(int pStation)
{
    return distanceToTravel(stationDistance[pStation]);
}

void Solution::refill(int pStation)
{
    fuelLeft = tankCapacity;
    startPos = stationDistance[pStation];
    ++numRefills;
}

int Solution::getMinRefills()
{
    int cur_station = 0;

    // We can reach the desitnation as it is within the tank capacity
    if (distanceToDestination() <= tankCapacity)
        return 0;

    // We can not reach the destination, hence check if we can reach at least the first station
    if (distanceToStation(0) > tankCapacity)
        return -1;

    // Start travelling station by station
    for (cur_station = 0; cur_station < stationDistance.size(); ++cur_station)
    {

        // Fuel left after reaching the current station
        fuelLeft = fuelLeft - distanceToStation(cur_station);

        // Reached the current station
        startPos = stationDistance[cur_station];

        // Can we reach the next station?
        if (fuelLeft >= distanceToStation(cur_station + 1))
        {

            continue; // go to next station
        }

        // We can not reach the next station with the left fuel, hence re-fill at this station itself
        refill(cur_station);

        // After re-fuelling, can we reach the destination
        if (fuelLeft >= distanceToDestination())
            return numRefills;

        // After re-fuelling, we can not reach the desitnation and even the next station
        if (fuelLeft < distanceToStation(cur_station + 1))
            return -1;
    }
}

int main()
{
    int d = 0;
    std::cin >> d;
    int m = 0;
    std::cin >> m;
    int n = 0;
    std::cin >> n;

    std::vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> stops.at(i);

    Solution solution(d, m, stops);

    std::cout << solution.getMinRefills() << "\n";

    return 0;
}