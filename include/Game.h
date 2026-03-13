#pragma once
#include <SDL3/SDL.h>
#include "Math.h"

class Game {
    public:
        Game();
        ~Game();

        bool Initialize();
        void RunLoop();
        void Shutdown();

    private:
};