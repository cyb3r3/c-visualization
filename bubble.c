//#include "bubble.h"


//TODO:
//needs tbe set in a seperate file.... or keep it here idk
void bubble_sort_step() {
    if (sorted) return;
    int swapped = 0;
    for (int i = 0; i < NUM_BARS - 1 - pass; i++) {
        if (bars[i] > bars[i + 1]) {
            int tmp  = bars[i];
            bars[i]  = bars[i + 1];
            bars[i + 1] = tmp;
            swapped  = 1;
        }
    }
    pass++;
    if (!swapped) sorted = 1;
}
