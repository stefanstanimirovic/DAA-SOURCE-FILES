#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Promotion {
    int start_hour, start_minute;
    int end_hour, end_minute;

    Promotion(int sh, int sm, int eh, int em)
        : start_hour(sh), start_minute(sm), end_hour(eh), end_minute(em)
    {}
};

bool compare(const Promotion& p1, const Promotion& p2) {
    return (p1.end_hour < p2.end_hour) || (p1.end_hour == p2.end_hour && p1.end_minute < p2.end_minute);
}

bool overlaps(const Promotion& p1, const Promotion& p2) {
    return !(p1.end_hour < p2.start_hour ||
        (p1.end_hour == p2.start_hour && p1.end_minute < p2.start_minute) ||
        p2.end_hour < p1.start_hour ||
        (p2.end_hour == p1.start_hour && p2.end_minute < p1.start_minute));
}

int numberOfPromotions(vector<Promotion> promotions) {
    sort(promotions.begin(), promotions.end(), compare);

    int max_promotions = 1;
    Promotion right_end = promotions[0];

    for (Promotion p : promotions) {
        if (!overlaps(p, right_end)) {
            right_end = p;
            max_promotions++;
        }
    }
    return max_promotions;
}

int IntervalOverlaps_main() {
    int n;
    cin >> n;

    vector<Promotion> promotions;
    for (int i = 0; i < n; i++) {
        int start_hour, start_minute, end_hour, end_minute;
        cin >> start_hour >> start_minute >> end_hour >> end_minute;
        promotions.push_back(Promotion(start_hour, start_minute, end_hour, end_minute));
    }
    cout << numberOfPromotions(promotions) << endl;

    return 0;
}