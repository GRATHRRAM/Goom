#include "core.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#define CORE_C
#include <raylib.h>
#include <string.h>
#include <stdlib.h>

#define pi 3.1415926535

void Draw_Player(Player *player);
void Move_Player(Player *player, float speed);
void Draw_Map2D(Map *map);
void DrawRays3D(Player *player, Map *map); 

void Draw_Player(Player *player) {
  DrawRectangleV((Vector2){player->x-5,player->y-5}, (Vector2){10,10}, YELLOW);
  DrawLine(player->x, player->y, player->x+player->DeltaX*5, player->y+player->DeltaY*5, GREEN);
}

void Move_Player(Player *player, float speed) {
  if(IsKeyDown(KEY_A)) {
    player->Angle -= 0.1;
    if(player->Angle < 0) {
      player->Angle += 2*pi;
    } 
    player->DeltaX=cos(player->Angle)*5;
    player->DeltaY=sin(player->Angle)*5;
  }
  if(IsKeyDown(KEY_D)) {
    player->Angle += 0.1;
    if(player->Angle > 2*pi) {
      player->Angle -= 2*pi;
    } 
    player->DeltaX=cos(player->Angle)*5;
    player->DeltaY=sin(player->Angle)*5;
  }
  if(IsKeyDown(KEY_W)) {player->x += player->DeltaX * speed;player->y += player->DeltaY * speed;}
  if(IsKeyDown(KEY_S)) {player->x -= player->DeltaX * speed;player->y -= player->DeltaY * speed;}
}

void Draw_Map2D(Map *map) {
  uint16_t i = 0;

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

void Set_map_alloc(Map *map, const uint8_t *level) {
  map->size   = map->MapSizeX * map->MapSizeY;
  map->MapArr = (uint8_t*) calloc(sizeof(uint8_t), map->size);
  memcpy(map->MapArr, level, map->size);
}

void DrawRays3D(Player *player, Map *map) {
  int r,mx,my,mp,dof;
  float rx,ry,ra,xo,yo;
  ra=player->Angle;
  for(r=0;r<1;++r) {
    dof=0;
    float aTan=-1/tan(ra);
    if(ra>pi) {
      ry=(((int)player->y>>6)<<6)-0.0001;
      rx=(player->y-ry) * aTan+player->x;
      yo=-64;
      xo=-yo*aTan;
    }
    if(ra<pi) {
      ry=(((int)player->y>>6)<<6)+64;
      rx=(player->y-ry) * aTan+player->x;
      yo=64;
      xo=-yo*aTan;
    }
    if(ra==0 || ra==pi) {
      rx=player->x;
      ry=player->y;
      dof=8;
    }
    while(dof<8) {
      mx=(int) (rx)>>6;
      my=(int) (ry)>>6;
      mp=my*map->MapSizeX+mx;
      if(mp<map->size && map->MapArr[mp]==1) dof=8;
      else {rx+=xo; ry+=yo; dof+=1;}
    }
    DrawLine(player->x-5, player->y-5, rx, ry, GREEN);
  }
}
