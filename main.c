#include <stdio.h>
#include "raylib.h"
#include "raymath.h"

#define MAX_COLUMNS 20

// --- Types ---
typedef struct {
    Vector3 position;
    Camera3D camera;
    float speed;
} Player;

typedef struct {
    Vector3 position;
    Vector3 size;
    Color color;
} Wall;

// --- Globals ---
Player player = {0};
Wall walls[MAX_COLUMNS] = {0};

// --- Initialization ---
void InitGame() {
    // Initialize Player
    player.position = (Vector3){ 0.0f, 2.0f, 4.0f };
    player.speed = 0.2f; // Increased speed
    
    player.camera.position = player.position;
    player.camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
    player.camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    player.camera.fovy = 60.0f;
    player.camera.projection = CAMERA_PERSPECTIVE;

    // Initialize Walls (Procedural Generation)
    for (int i = 0; i < MAX_COLUMNS; i++) {
        walls[i].size = (Vector3){ 2.0f, (float)GetRandomValue(1, 12), 2.0f };
        walls[i].position = (Vector3){
            (float)GetRandomValue(-15, 15),
            walls[i].size.y / 2.0f, // Center vertically based on height
            (float)GetRandomValue(-15, 15)
        };
        walls[i].color = (Color){ 
            GetRandomValue(50, 200), 
            GetRandomValue(50, 200), 
            GetRandomValue(100, 250), 
            255 
        };
    }
}

// --- Update ---
void UpdateGame() {
    // 1. Mouse Look (First Person)
    UpdateCamera(&player.camera, CAMERA_FIRST_PERSON);

    // 2. Simple Floor collision (Don't fall through ground)
    // Note: Raylib's UpdateCamera handles basic movement, but we can clamp position here
    if (player.camera.position.y < 1.0f) player.camera.position.y = 1.0f;
}

// --- Draw ---
void DrawGame() {
    BeginDrawing();
    
    ClearBackground(RAYWHITE);

    BeginMode3D(player.camera);

        // Draw Ground
        DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY);
        DrawGrid(32, 1.0f);

        // Draw Walls
        for (int i = 0; i < MAX_COLUMNS; i++) {
            DrawCube(walls[i].position, walls[i].size.x, walls[i].size.y, walls[i].size.z, walls[i].color);
            DrawCubeWires(walls[i].position, walls[i].size.x, walls[i].size.y, walls[i].size.z, MAROON);
        }

        // Draw "Enemy" (Just a floating sphere for now)
        DrawSphere((Vector3){-5.0f, 2.0f, -5.0f}, 1.0f, RED);

    EndMode3D();

    // Draw UI
    DrawText("WASD to Move | Mouse to Look | ESC to Exit", 10, 10, 20, DARKGRAY);
    DrawFPS(10, 40);

    EndDrawing();
}

int main(void) {
    // Win32 / Linux Window Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "C 3D Dungeon Crawler - Raylib");
    
    // Lock mouse for FPS feel
    DisableCursor();
    SetTargetFPS(60);

    InitGame();

    // Main Game Loop
    while (!WindowShouldClose()) {
        UpdateGame();
        DrawGame();
    }

    CloseWindow();
    return 0;
}
