#include <vector>
using namespace std;

// Spoji dva podniza, `arr[low… mid]` i `arr[mid+1… high]`,
// tako da su svi negativni brojevi ispred pozitivnih brojeva
void mergePosNeg(int arr[], int low, int mid, int high) {
    int k = 0;
    vector<int> aux(high - low + 1);

    // kopiranje negativnih elemenata iz levog podniza
    for (int i = low; i <= mid; i++) {
        if (arr[i] < 0) {
            aux[k++] = arr[i];
        }
    }

    // kopiranje negativnih elemenata iz desnog podniza
    for (int j = mid + 1; j <= high; j++) {
        if (arr[j] < 0) {
            aux[k++] = arr[j];
        }
    }

    // kopiranje pozitivnih elemenata iz levog podniza
    for (int i = low; i <= mid; i++)
    {
        if (arr[i] >= 0) {
            aux[k++] = arr[i];
        }
    }

    // kopiranje pozitivnih elemenata iz desnog podniza
    for (int j = mid + 1; j <= high; j++)
    {
        if (arr[j] >= 0) {
            aux[k++] = arr[j];
        }
    }

    // vracanje elemenata u originalni niz
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i - low];
    }
}

// Odvajanje pozitivnih i negativnih elemenata uz pomoc logike merge sort-a
void partitionMerge(int arr[], int low, int high)
{
    if (high <= low) {
        return;
    }

    int mid = low + (high - low) / 2;

    partitionMerge(arr, low, mid);          // split/merge left half
    partitionMerge(arr, mid + 1, high);     // split/merge right half

    mergePosNeg(arr, low, mid, high);        // join the two half runs
}