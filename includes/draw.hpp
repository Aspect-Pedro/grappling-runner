#pragma once
#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"
#include <cmath>
#include "setup.hpp"
#include "globals.hpp"
#include "guiComponents.hpp"

void DrawDebugBoard(Camera2D camera);

void DrawEngineGrid2D(int gridSize, int gridSpacing, Screen screen, Camera2D *camera, Vector2 mousePosition, GUI *interface);

void DrawGUI(Camera2D camera, Vector2 mousePosition, GUI *interface, Screen screen, Font font, int *engine_mode);

void DrawPlayCameraSilhouette(Camera2D camera, Screen screen);
