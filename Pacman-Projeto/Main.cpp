#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    bool isFullscreen = false;
    int x = 0;
    int y = 0;
    const float playerSpeed = 200.0f;
    Vector2 playerPosition =
    {
        (float)screenWidth / 2, (float)screenHeight / 2
    };

    InitWindow(screenWidth, screenHeight, "Pac-Man");

    SetTargetFPS(60);

    // Inicializar a posição do player
    // Como estamos em um jogo 2d, a posição do player é armazenada em um vetor de 2 dimensões X e Y

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update

        float deltaTime = GetFrameTime();

        if (IsKeyPressed(KEY_F11))
        {
            if (isFullscreen == false)
            {
                int currentMonitor = GetCurrentMonitor();
                int monitorWidth = GetMonitorWidth(currentMonitor);
                int monitorHeight = GetMonitorHeight(currentMonitor);
                SetWindowSize(monitorWidth, monitorHeight);
                ToggleFullscreen();
                isFullscreen = true;
            }
            else
            {
                ToggleFullscreen();
                SetWindowSize(screenWidth, screenHeight);
                isFullscreen = false;
            }
        }

        // Atualizar a posição do player a medida que ele aperta alguma tecla

        if (IsKeyPressed(KEY_A))
        {
            x = -1;
            y = 0;
        }
        
        if (IsKeyPressed(KEY_D))
        {
            x = 1;
            y = 0;
        }

        if (IsKeyPressed(KEY_W))
        {
            x = 0;
            y = -1;
        }

        if (IsKeyPressed(KEY_S))
        {
            x = 0;
            y = 1;
        }
        if (IsKeyPressed(KEY_SPACE))
        {
            x = 0;
            y = 0;
        }

        playerPosition.x += (playerSpeed * deltaTime) * x;
        playerPosition.y += (playerSpeed * deltaTime) * y;
            
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);
        DrawText("move with arrow keys", 10, 10, 20, WHITE);
        DrawCircleV(playerPosition, 10, YELLOW);

        // Desenhar o player na nova posição

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}