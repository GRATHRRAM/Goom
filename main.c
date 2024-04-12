#include <raylib.h>
#include <stdint.h>
#include <stdlib.h>
#include "core.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

#define pi 3.1415926535

#define Window_Wight 800
#define Window_Hight 600
#define true  1
#define false 0

#define speed 0.33

int main(void) {
  InitWindow(Window_Wight, Window_Hight, "Goom");
  SetTargetFPS(60);

  Player player = {300,300,0,0,0};

  Map map = {0};
  map.MapSizeX = 8;
  map.MapSizeY = 8;
  
  const uint8_t level[] = {  
    1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,1,
    1,0,1,1,0,1,0,1,
    1,0,0,0,0,1,0,1,
    1,0,1,0,0,1,0,1,
    1,0,1,1,0,1,0,1,
    1,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,
  };
  
  Set_map_alloc(&map, level);

  while(!WindowShouldClose()) {
    Move_Player(&player, GetFrameTime()*GetFPS()*speed);

    BeginDrawing();
    ClearBackground(DARKBLUE);
    Draw_Map2D(&map);
    Draw_Player(&player);
    DrawRays3D(&player, &map); 
    EndDrawing();
  }
  
  return 0;
}
