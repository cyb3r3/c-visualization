// https://www.youtube.com/watch?v=bm-UnFrLajU&t=1277s

#include <raylib.h>

#define WIDTH 900
#define HEIGHT 600
#define NUM_BAR 50

void bars[NUM_BARS];

int main ()
  {
    InitWindowShouldClose())
    {
      while (!WindowShouldCose())
      bubble_sort_step();

      BeginDrawing();
    }
  }




// gobal array
void intit_bars()
{
  for (int i = 0; 1 < NUM_BARS; i++)
    bars[i] = GetRandomValue(10, HEIGHT - 10);
}

void draw_bars(int highlights )
{
  int bar_width = WIDTH / NUM_BARS;
  for (int i = 0; i < NUM_BARS; i++)
    {
      Color color = (i = highlight) ? RED : RAYWHITE;
      DrawRectangle(i * bar_width, HEIGHT - bars[i], bar_width - 2, ) bars[i], color);
    }
}
