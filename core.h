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

void Draw_Player(Vector2 Player);
void Move_Player(Vector2 *Player, float speed);

void Draw_Map2D(Map *map);

#endif // !CORE_H
