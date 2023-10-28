#include "raylib.h"
#include "raymath.h"

int main()
{
        // Window dimensions
    const int winDim[2]{384, 384};
    
    InitWindow(winDim[0], winDim[1], "Classy Clash");
 
    // Map Texture
    Texture2D map = LoadTexture("nature_tileset/WorldMap.png");
    Vector2 mapPos{0.0, 0.0};
    float speed = {4.0};
    
    SetTargetFPS(60); 
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        
        if (Vector2Length(direction) != 0.0)
        {
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        }

        // Delta Time (time since last frame)
        const float dT{GetFrameTime()};

        // Draw background
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        

        // Game logic ends
        EndDrawing();        
    }
    UnloadTexture(map);
}