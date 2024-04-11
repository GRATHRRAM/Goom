#include <raylib.h>
#include <stdint.h>
#include <stdlib.h>
#include "core.h"
#include <stdio.h>

#define Window_Wight 800
#define Window_Hight 600
#define true  1
#define false 0

#define speed 1

void Draw_Player(Vector2 Player);

int main(void) {
  InitWindow(Window_Wight, Window_Hight, "Goom");
  SetTargetFPS(60);

  Vector2 Player = {300,300};

  Map map = {0};
  map.MapSizeX = 8;
  map.MapSizeY = 8;
  map.size   = map.MapSizeX * map.MapSizeY;
  map.MapArr = (uint8_t*) calloc(sizeof(uint8_t), map.size);
  printf("map.maparr == %p\n\n\n\n\n", map.MapArr);
  
  map.MapArr = (uint8_t*) {
    1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,1,1,1,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,
  };

  while(!WindowShouldClose()) {
    Move_Player(&Player, GetFrameTime()*GetFPS()*speed);

    BeginDrawing();
    ClearBackground(DARKBLUE);
    Draw_Map2D(&map);
    Draw_Player(Player);
    EndDrawing();
  }
  
  return 0;
}
