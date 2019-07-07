#include <cmath>
#include <utility>

long long rectangle_rotation(int a, int b) {
    float t = a/2/(std::sqrt(2));
    float x = b/2/(std::sqrt(2));

    std::pair<float, float> w1 = std::make_pair(t-x, t+x);
    std::pair<float, float> w2 = std::make_pair(t+x, t-x);
    std::pair<float, float> w3 = std::make_pair(-(t-x), -(t+x));
    std::pair<float, float> w4 = std::make_pair(-(t+x), -(t-x));

    float b14 = w1.second - w1.first;
    float b23 = w2.second - w2.first;
    float b12 = w1.second + w1.first;
    float b34 = w3.second + w3.first;

    int minx = w4.first;
    int maxx = w2.first;
    int miny = w3.second;
    int maxy = w1.second;

    long long result = 0;

    for(int j = minx; j <= maxx; j++) {
      for(int i = miny; i <= maxy; i++) {
        bool p12 = i <= ( -j + b12);
        bool p23 = i >= ( j + b23);
        bool p34 = i >= ( -j + b34);
        bool p14 = i <= ( j + b14);

        if(p12 && p23 && p34 && p14) result++;
      }
    }
    return result;
}

