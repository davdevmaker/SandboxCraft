#include "assetManager.h"

void AssetManager::loadAll()
{
    dirt = LoadTexture(RESOURCES_PATH "dirt.png");
    smile = LoadTexture(RESOURCES_PATH "tile_0012.png");

} 

//steps to add textures:
// #1: define the texture in the struct AssetManager ex:    Texture2D smile = {};
// #2: load the texture in void AssetManager ex:        smile = LoadTexture(RESOURCES_PATH "tile_0012.png");
// #3: draw the texture inside updateGame() in gameMain.cpp 
// ex: DrawTexturePro(assetManager.smile, {0, 0,(float)assetManager.smile.width, (float)assetManager.smile.height} , {90, 90, 200, 200}, {}, 0, WHITE);

// Question?: wouldnt it be awesome to make a function that automatically does this? what about animation?

