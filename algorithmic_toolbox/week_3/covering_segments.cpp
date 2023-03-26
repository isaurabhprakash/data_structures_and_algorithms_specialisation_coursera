#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

struct Segment
{
  int start, end;
};

std::vector<int> optimal_points(std::vector<Segment> &segments)
{

  int point;
  std::vector<int> points;

  std::sort(segments.begin(), segments.end(),
            // Lambda function to sort. Since we want to change the values, passing
            // the variables of the surrounding space by reference.
            [&](Segment seg1, Segment seg2)
            {
              return seg1.end < seg2.end;
            });

  points.push_back(segments[0].end);
  point = points[0];

  // write your code here
  for (size_t i = 0; i < segments.size(); ++i)
  {

    // Ponit lies before or after the segment starts/ends
    if (point < segments[i].start || point > segments[i].end)
    {

      point = segments[i].end;
      points.push_back(point);
    }
  }
  return points;
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }
  std::vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
}
