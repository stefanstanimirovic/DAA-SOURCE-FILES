#include <iostream>
#include <vector>
using namespace std;

struct Building {
    int left;
    int ht;
    int right;
};

struct Strip {
    int left;
    int ht;
};

// stampanje siluete
void print(vector<Strip> skyline) {
    int n = skyline.size();
    for (int i = 0; i < n; i++) {
        cout << "(" << skyline[i].left << ", " << skyline[i].ht << ")"
            << (i < n - 1 ? ", " : "");
    }
    cout << "\n";
}

void append(vector<Strip>& sklyline, Strip st) {
    // Proveri da li je st redudantna traka
    int n = sklyline.size();
    if (n > 0 && sklyline[n - 1].ht == st.ht)
        return;
    if (n > 0 && sklyline[n - 1].left == st.left) {
        sklyline[n - 1].ht = max(sklyline[n - 1].ht, st.ht);
        return;
    }
    // Ako nije, dodaj je u siluetu
    sklyline.push_back(st);
}

// spajanje dve siluete u jednu, slicno kao i kod mergesort algoritma
vector<Strip> merge(vector<Strip> left, vector<Strip> right) {
    vector<Strip> result;
    int h1 = 0, h2 = 0;
    unsigned int i = 0, j = 0;
    unsigned int n = left.size();
    unsigned int m = right.size();
    while (i < n && j < m) {
        int x1 = left[i].left;
        int x2 = right[j].left;
        if (x1 < x2) {
            h1 = left[i].ht;
            int maxh = max(h1, h2);
            append(result, { x1, maxh });
            i++;
        }
        else {
            h2 = right[j].ht;
            int maxh = max(h1, h2);
            append(result, { x2, maxh });
            j++;
        }
    }

    while (i < n) {
        append(result, left[i]);
        i++;
    }
    while (j < m) {
        append(result, right[j]);
        j++;
    }

    return result;
}

// nalazi siluetu za zgrade arr[l, l + 1, ..., r]
vector<Strip> findSkyline(Building arr[], int l, int r) {
    if (l == r) {
        vector<Strip> res;
        res.push_back({ arr[l].left, arr[l].ht });
        res.push_back({ arr[l].right, 0 });
        return res;
    }

    int mid = (l + r) / 2;
    vector<Strip> sl = findSkyline(arr, l, mid);
    vector<Strip> sr = findSkyline(arr, mid + 1, r);
    vector<Strip> res = merge(sl, sr);
    return res;
}

int skyline_main() {
    Building arr[] = {
        { 1, 11, 5 }, { 2, 6, 7 }, { 3, 13, 9 }, { 12, 7, 16 },
        { 14, 3, 25 }, { 19, 18, 22 }, { 23, 13, 29 }, { 24, 4, 28 }
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<Strip> skyline = findSkyline(arr, 0, n - 1);
    print(skyline);
    return 0;
}