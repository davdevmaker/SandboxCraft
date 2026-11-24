#include <raylib.h>
#include "gameMain.h"
#include <asserts.h>
#include <assetManager.h>

// initialize your variables with values always, even if empty or 0.

struct gameData 
{
}gameData;

AssetManager assetManager;


bool initGame()
{
    assetManager.loadAll();

    return true;
}

bool updateGame()
{
    

	DrawFPS(10, 40);

    DrawTexturePro(assetManager.dirt, {0, 0,(float)assetManager.dirt.width, (float)assetManager.dirt.height} , {50, 50, 100, 100}, {}, 0, WHITE);
    DrawTexturePro(assetManager.smile, {0, 0,(float)assetManager.smile.width, (float)assetManager.smile.height} , {90, 90, 200, 200}, {}, 0, WHITE);

    

    
    return true;
}

void closeGame()
{

}