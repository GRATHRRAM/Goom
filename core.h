#ifndef CORE_H 
#define CORE_H

#include <raylib.h>
#include <stdint.h>

typedef struct Map {
  uint16_t MapSizeX;
  uint16_t MapSizeY;
  uint16_t size;
uint8_t *MapArr;
} Map;

typedef struct Player {
  float x;
  float y;
  float DeltaX;
  float DeltaY;
  float Angle;
} Player;

void Draw_Player(Player *player);
void Move_Player(Player *player, float speed);

void Draw_Map2D(Map *map);

void Set_map_alloc(Map *map, const uint8_t *level); 
#endif // !CORE_H
