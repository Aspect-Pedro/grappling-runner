#include "../includes/colors.hpp"

Color LessOpacity(Color color, float opacity) {
  return (Color){color.r, color.g, color.b, (unsigned char) opacity};
}

unsigned int colorToInt(Color color) {
  return (color.r << 24) | (color.g << 16) | (color.b << 8) | color.a;
}

char *colorToHex(Color color) {
  char *hex = (char *) malloc(7);
  sprintf(hex, "%02x%02x%02x", color.r, color.g, color.b);
  return hex;
}

Color IntToColor(unsigned int color) {
  unsigned char r = (color >> 24) & 0xFF;
  unsigned char g = (color >> 16) & 0xFF;
  unsigned char b = (color >> 8) & 0xFF;
  unsigned char a = color & 0xFF;
  return (Color){r, g, b, a};
}

Color HexToColor(const char *hex) {
  unsigned int r = 0;
  sprintf((char *) &r, "%c%c", hex[0], hex[1]);
  int numr = (int) strtol((char *) &r, NULL, 16);

  unsigned int g = 0;
  sprintf((char *) &g, "%c%c", hex[2], hex[3]);
  int numg = (int) strtol((char *) &g, NULL, 16);

  unsigned int b = 0;
  sprintf((char *) &b, "%c%c", hex[4], hex[5]);
  int numb = (int) strtol((char *) &b, NULL, 16);

  return (Color){(unsigned char) numr, (unsigned char) numg, (unsigned char) numb, 255};
}