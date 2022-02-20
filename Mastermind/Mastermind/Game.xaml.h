#pragma once

#include "Game.g.h"

namespace winrt::Mastermind::implementation
{
    struct Game : GameT<Game>
    {
        Game();
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct Game : GameT<Game, implementation::Game>
    {
    };
}
