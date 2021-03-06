#ifndef OPENPP_PROJECTS_THESIS_GAME_LEVEL_SCREEN_H_
#define OPENPP_PROJECTS_THESIS_GAME_LEVEL_SCREEN_H_

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Level Screen in SDL based Games
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *  - Not Finished!
 *  - Needs to be Ported!
 *
\********************************************/

#include <SDL.h>
#include "../../Core/Input.h"
#include <Objects/IScreen.hpp>
#include <Objects/2D/SDL2/Globals.hpp>
#include <Objects/2D/SDL2/Button.hpp>
#include <Objects/2D/SDL2/Texture.hpp>
#include <Objects/2D/SDL2/Text.hpp>
#include <Objects/2D/Vector2.hpp>
#include <vector>
#include <functional>

namespace OO = Openpp::Objects;
namespace SDL = OO::SDL2;
typedef SDL::Globals SDLG;

namespace Game
{
    namespace Screens
    {
        namespace LevelScreenButtons
        {
            void BTN_Start();
            void BTN_QUIT();
        }

        class LevelScreen : public Openpp::IScreen
        {
        public:
            LevelScreen();
            void Init();

            void HandleInputs();

            void Update();

            void Render();

            void SetHighestLevel(int Level);

            int GetHighestLevel();

            std::string CurrentButtonText();

		protected:
			void Leave() {}
			void Enter() {}

        private:
            int mHighestLevel;
            std::vector< std::string > mPaths;

            std::vector< std::vector< SDL::Button > > mButtons;
            std::vector< SDL::Button > mButtonRow;
            SDL::Button mButtonDummy;
            OO::Vector2<int> mCurrentButton;
            int mSpace;

            int mButtons_Row_System;
            int mRows_System;
            OO::Vector2<int> mSystems;

            std::vector< SDL::Text > mTexts;
            SDL::Text mTextDummy;
            char mBuffer[64];

            std::shared_ptr< SDL_Texture > mpBackground;

            void BUTTON_Up();
            void BUTTON_Right();
            void BUTTON_Down();
            void BUTTON_Left();
        };
    }
}

#endif // OPENPP_PROJECTS_THESIS_GAME_LEVEL_SCREEN_H_
