#include "core.h"
#include <stdint.h>
#include <stdio.h>
#define CORE_C
#include <raylib.h>

void Draw_Player(Vector2 Player);
void Move_Player(Vector2 *Player, float speed);
void Draw_Map2D(Map *map);

void Draw_Player(Vector2 Player) {
  DrawRectangleV(Player, (Vector2){10,10}, YELLOW);
}

void Move_Player(Vector2 *Player, float speed) {
  if(IsKeyDown(KEY_A)) Player->x -= speed;
  if(IsKeyDown(KEY_D)) Player->x += speed;
  if(IsKeyDown(KEY_W)) Player->y -= speed;
  if(IsKeyDown(KEY_S)) Player->y += speed;
}

void Draw_Map2D(Map *map) {
  uint16_t i = 0;

  printf("*map.maparr == %p\n\n\n\n\n",map->MapArr);

  for(uint16_t y = 0; y < map->MapSizeY; ++y) {
    for(uint16_t x = 0; x < map->MapSizeX; ++x) {
      uint16_t xo = x*map->size, yo = y*map->size;
      if(map->MapArr[i] ==1)
        DrawRectangle(xo, yo, xo+map->size, yo+map->size, GRAY);
      else DrawRectangle(xo, yo, xo+map->size, yo+map->size, BLACK);
      i++;
    }
  }
}
