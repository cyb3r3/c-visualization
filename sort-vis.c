// https://www.youtube.com/watch?v=bm-UnFrLajU&t=1277s

#include <stdlib.h>
#include <raylib.h>

#define WIDTH   900
#define HEIGHT  600
#define NUM_BARS 50

// prototypes
void init_bars();
void draw_bars(int highlight);
void bubble_sort_step();

int bars[NUM_BARS];
int sorted = 0;
int pass   = 0;

int main() {
    InitWindow(WIDTH, HEIGHT, "Sort");
    SetTargetFPS(10);
    init_bars();

    while (!WindowShouldClose()) {
        bubble_sort_step();

        BeginDrawing();
            ClearBackground(BLACK);
            draw_bars(pass);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

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

void init_bars() {
    for (int i = 0; i < NUM_BARS; i++)
        bars[i] = GetRandomValue(10, HEIGHT - 10);
}

void draw_bars(int highlight) {
    int bar_width = WIDTH / NUM_BARS;
    for (int i = 0; i < NUM_BARS; i++) {
        Color color = (i == highlight) ? ORANGE : RAYWHITE;
        DrawRectangle(i * bar_width, HEIGHT - bars[i], bar_width - 2, bars[i], color);
    }
}
