#pragma once
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

Color LessOpacity(Color color, float opacity);

unsigned int colorToInt(Color color);

char *colorToHex(Color color);

Color IntToColor(unsigned int color);

Color HexToColor(const char *hex);