#pragma once
#include "raylib.h"
#include <vector>

// --------------------------------------------------------------------------------------------> Game Controls

#define GRID_MOVEMENT_CONTROL_CURSOR MOUSE_BUTTON_MIDDLE
//... other controls

// settings
#define MINIMUM_BLOCK_SIZE 30
#define ACTUAL_MODE DEVELOPMENT_MODE

// --------------------------------------------------------------------------------------------> Global

typedef struct size {
    float width;
    float height;
} Size;

typedef struct screen {
    int screenWidth;
    int screenHeight;
} Screen;

typedef struct block {
    Rectangle rec;
    Color color;
    Color colorAbsolute;
    int id;
    int layer;
} Block; // Each element of the grid

// --------------------------------------------------------------------------------------------> Edit Mode

typedef struct editmode_textures {
    Texture2D *arrowTexture;
} EditModeTexture;

typedef struct editmode_gui {
    Vector2 position;
    Size size;
} EditModeGUI;

typedef struct selectionBox {
    Vector2 origin;
    Vector2 position;
    Vector2 direction;
    Size size;
    std::vector<Block> selectedBlocks; // pointer to the selected blocks
    Rectangle rec;
} SelectionBox;

typedef struct scaleMode {
    int isScaling;
    int flag;
    Block *scaleSelectedBlock;
    Vector2 *positionArrows;
} ScaleMode;
#define SCALE_MODE_FLAG_STOP_SCALING 1

typedef struct color_picker {
    char hexBuffer[7];
    bool isTriggered;
} ColorPicker;

typedef struct editmode {
    int editModeState;
    int blockIdsNumber;
    std::vector<Block> blockList;
    EditModeGUI editModeInterface;
    SelectionBox selectionBox;
    Block *moveSelectedBlock;
    EditModeTexture textures;
    ScaleMode scaleMode;
    ColorPicker colorPicker;
} EditMode;

typedef enum {
    EDIT_MODE_STATE_SELECT = 0,
    EDIT_MODE_STATE_CREATE = 1,
    EDIT_MODE_STATE_MOVE = 2,
    EDIT_MODE_STATE_SCALE = 3
} EditModeState;

typedef enum {
    EDIT_MODE_INSPECT_MENU_HEIGHT = 300,
} EditModeMenuGUI;

// Number of buttons in the edit mode interface
// TODO: Change this to EDIT_MODE_BUTTONS_NUMBER
#define BUTTONS_NUMBER 4

// --------------------------------------------------------------------------------------------> GUI

typedef struct gui_textures {
    Texture2D *hamburguerMenuIconTexture;
} GUITextures;

typedef struct toggleButton {
    Size size;
    Vector2 position;
} GUIToggleButton;

typedef struct gui_button {
    Size size;
    Vector2 position;
    Color color;
    bool isOpened;
    int fileWasSavedResponse;
} GUIBottomMenu;

typedef struct gui {
    Color GUI_color;
    Color Button_color;
    Color Toggle_color;
    GUIToggleButton toggleButton;
    float width;
    Vector2 position;
    bool isOpened;
    int mouseState;
    GUITextures textures;
    GUIBottomMenu bottomMenu;
} GUI;

// Buttons
#define GUI_BUTTONS_NUMBER 1
#define GUI_BUTTON_HEIGHT 50
#define GUI_BUTTON_MARGIN 10.0f

#define GUI_HAMBURGUER_MENU_BUTTON_PADDING 5
#define GUI_BOTTOM_MENU_BUTTONS_NUMBER 1

// GUI cursor states
#define CURSOR_DEFAULT 1
#define CURSOR_CROSSHAIR 3
#define CURSOR_POINTING 4

// --------------------------------------------------------------------------------------------> Modes


typedef enum {
    DEBUG_MODE = 0,
    DEVELOPMENT_MODE = 1,
    EDIT_MODE = 2,
    PLAY_MODE = 3
} EngineModes;

typedef struct modes {
    int engine_mode;
    EditMode editMode;
} Modes;

// --------------------------------------------------------------------------------------------> Cursor

typedef struct cursor {
    int layer;
    int mouseState;
    Vector2 worldPosition;
    Vector2 screenPosition;
} Cursor;