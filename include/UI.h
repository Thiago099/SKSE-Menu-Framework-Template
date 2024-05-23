#pragma once
#include "SKSEModHub.h"
#include <imgui/imgui.h>
#include "Configuration.h"
namespace UI {
    void Register();
    namespace Example1 {
        static void Render();
    }
    namespace Example2 {
        static void Render();
    }
    namespace Example3 {
        static void Render();
    }
};