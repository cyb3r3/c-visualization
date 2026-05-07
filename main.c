 // menu.c — Main Menu for Sorting Visualizer



#include <raylib.h>

#define WIDTH  900
#define HEIGHT 600

typedef enum {
    SCREEN_MENU,
    SCREEN_SORT,
    SCREEN_QUIT,
} Screen;

typedef struct {
    const char *label;
    int         x, y, w, h;
} Button;


int button_hovered(Button b) {
    int mx = GetMouseX(), my = GetMouseY();
    return mx >= b.x && mx <= b.x + b.w &&
           my >= b.y && my <= b.y + b.h;
}

void draw_button(Button b) {
    Color bg   = button_hovered(b) ? (Color){80, 80, 80, 255} : (Color){40, 40, 40, 255};
    Color text = button_hovered(b) ? WHITE : LIGHTGRAY;
    Color border = button_hovered(b) ? WHITE : DARKGRAY;

    DrawRectangle(b.x, b.y, b.w, b.h, bg);
    DrawRectangleLines(b.x, b.y, b.w, b.h, border);

    int font_size = 20;
    int text_w    = MeasureText(b.label, font_size);
    DrawText(b.label, b.x + (b.w - text_w) / 2,
                      b.y + (b.h - font_size) / 2, font_size, text);
}




Screen run_menu() {
    Button buttons[] = {
        { "Start", WIDTH/2 - 120, 250, 240, 50 },
        { "Quit",  WIDTH/2 - 120, 320, 240, 50 },
    };
    int num_buttons = 2;

    while (!WindowShouldClose()) {

        // input
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (button_hovered(buttons[0])) return SCREEN_SORT;
            if (button_hovered(buttons[1])) return SCREEN_QUIT;
        }

        // draw
        BeginDrawing();
            ClearBackground(BLACK);

            // title
            const char *title = "c-visualization";
            int title_size = 40;
            int title_w = MeasureText(title, title_size);
            DrawText(title, (WIDTH - title_w) / 2, 140, title_size, WHITE);

            // subtitle
            const char *sub = "by: cyb3r@debian";
            int sub_w = MeasureText(sub, 18);
            DrawText(sub, (WIDTH - sub_w) / 2, 195, 18, DARKGRAY);

            // buttons
            for (int i = 0; i < num_buttons; i++)
                draw_button(buttons[i]);

            // footer
            DrawText("ESC: quit", 10, HEIGHT - 24, 14, DARKGRAY);

        EndDrawing();
    }

    return SCREEN_QUIT;
}




int main() {
    InitWindow(WIDTH, HEIGHT, "Sorting Visualizer");
    SetTargetFPS(60);

    Screen screen = run_menu();

    if (screen == SCREEN_SORT) {
        // swap to your sort-vis logic here
        // e.g. call run_sort_visualizer();
        DrawText("Sort screen would load here", 100, 100, 20, WHITE);
    }

    CloseWindow();
    return 0;
}
