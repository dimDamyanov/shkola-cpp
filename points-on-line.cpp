#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
  
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const std::pair<T1, T2>& p) const { 
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;
    } 
};

int maxPointsLine(std::vector<std::pair<int, int>> points) {
    int N = points.size();
    if (N < 2)
        return N;
    
    int maxPoint = 0;
    int currentMax, overlapingPoints, verticalPoints;
    std::unordered_map<std::pair<int, int>, int, hash_pair> slopeMap;
    for (int i = 0; i < N; i++) {
        currentMax = overlapingPoints = verticalPoints = 0;
        for (int j = i + 1; j < N; j++) {
            if (points[i] == points[j])
                overlapingPoints++;
            else if (points[i].first == points[j].first)
                verticalPoints++;
            else {
                int deltaY = points[j].second - points[i].second;
                int deltaX = points[j].first - points[i].first;
                int g = std::__gcd(deltaX, deltaY);
                deltaY /= g;
                deltaX /= g;
                slopeMap[std::make_pair(deltaY, deltaX)]++;
                currentMax = std::max(currentMax, slopeMap[std::make_pair(deltaY, deltaX)]); 
            }
            currentMax = std::max(currentMax, verticalPoints);
        }
        maxPoint = std::max(maxPoint, currentMax + overlapingPoints + 1);
        slopeMap.clear();
    }
    return maxPoint;
}

int main() {
    int n, x, y;
    std::cin >> n;
    int pointsArr [n][2];
    for (int i = 0; i < n; i++)
        std::cin >> pointsArr[i][0] >> pointsArr[i][1];
    std::vector<std::pair<int, int>> points;
    for (int i = 0; i < n; i++)
        points.push_back(std::make_pair(pointsArr[i][0], pointsArr[i][1]));
    std::cout << maxPointsLine(points) << std::endl;
    return 0;
}