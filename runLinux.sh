#!/bin/bash

g++ src/game.cpp src/setup.cpp src/guiComponents.cpp src/draw.cpp src/input.cpp src/editMode.cpp -o play -Iraylib/include -Lraylib/lib -lraylib -lGL -lm -lpthread -ldl -lrt
