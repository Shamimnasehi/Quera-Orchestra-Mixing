// Orchestra concert mixing — minimum total energy to merge all tracks.
//
// Idea (greedy, same as Huffman coding):
//   Merging two tracks costs (A + B), and the result is a new track of length A + B
//   that may be merged again. Every merge "re-pays" the lengths of the tracks inside it,
//   so short tracks should be merged first (they get re-paid the most times)
//   and long tracks should be merged last.
//   => At every step, always merge the two shortest tracks currently available.
//
// A min-heap gives us the two smallest elements in O(log n).
// Total complexity: O(n log n). Memory: O(n).

#include <cstdio>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;  // sums reach ~ 2e14 * log(n), which overflows int

// Min-heap: top() is always the smallest element.
typedef priority_queue<ll, vector<ll>, greater<ll> > MinHeap;

// Reads n track lengths from input and puts them into a min-heap.
MinHeap readTracks(int n) {
    MinHeap tracks;
    for (int i = 0; i < n; i++) {
        ll length;
        scanf("%lld", &length);
        tracks.push(length);
    }
    return tracks;
}

// Removes and returns the smallest element of the heap.
ll popSmallest(MinHeap &heap) {
    ll smallest = heap.top();
    heap.pop();
    return smallest;
}

// Repeatedly merges the two shortest tracks until one remains.
// Returns the total energy spent.
ll minimumMergeCost(MinHeap &tracks) {
    ll totalEnergy = 0;

    // With n == 1 the loop never runs, so the answer is 0 (as required).
    while (tracks.size() > 1) {
        ll first = popSmallest(tracks);
        ll second = popSmallest(tracks);

        ll mergedLength = first + second;
        totalEnergy += mergedLength;  // cost of this merge

        tracks.push(mergedLength);    // merged track can be mixed again later
    }
    return totalEnergy;
}

int main() {
    int n;
    scanf("%d", &n);

    MinHeap tracks = readTracks(n);
    printf("%lld\n", minimumMergeCost(tracks));

    return 0;
}
