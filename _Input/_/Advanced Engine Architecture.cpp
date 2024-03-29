#pragma comment(lib , "..\\OpenAssetImportLibrary\\assimp-vc143-mt.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2main.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Image\\sdl2_image.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\Mixer\\sdl2_mixer.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\TrueTypeFont\\sdl2_ttf.lib")

#define GLAD_GL_IMPLEMENTATION

#include"Advanced Engine Architecture.hpp"
#include"Audio.hpp"
#include"Debug.hpp"
#include"Input.hpp"
#include"Space.hpp"
#include"Time.hpp"
#include"Video.hpp"

std::int32_t main(std::int32_t , char**)
{
    NAdvancedEngineArchitecture::GDebug.OSimpleDirectMediaLayerCodeError(SDL_Init(SDL_INIT_EVERYTHING));
    NAdvancedEngineArchitecture::GAudio.BInitialize();
    NAdvancedEngineArchitecture::GVideo.BInitialize();
    NAdvancedEngineArchitecture::GSpace.BInitialize();
    while(!NAdvancedEngineArchitecture::GInput.OIsKeyHeld(SDL_SCANCODE_ESCAPE))
    {
        NAdvancedEngineArchitecture::GInput.BUpdate();
        NAdvancedEngineArchitecture::GTime.BUpdate();
        NAdvancedEngineArchitecture::GVideo.BPreupdate();
        NAdvancedEngineArchitecture::GSpace.BUpdate();
        NAdvancedEngineArchitecture::GVideo.BPostupdate();
    };
    NAdvancedEngineArchitecture::GSpace.BDeinitialize();
    NAdvancedEngineArchitecture::GVideo.BDeinitialize();
    NAdvancedEngineArchitecture::GAudio.BDeinitialize();
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION , "Score" , std::to_string(NAdvancedEngineArchitecture::GSpace.FPlaneScore).c_str() , nullptr);
    SDL_Quit();
    return(0);
}