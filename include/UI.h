#pragma once
#include "SKSEModHub.h"
#include <imgui/imgui.h>
#include "Configuration.h"
namespace UI {
    void Register();
    namespace Example1 {
        static void __stdcall Render();
    }
    namespace Example2 {
        static void __stdcall Render();
    }
    namespace Example3 {
        static void __stdcall Render();
    }
};