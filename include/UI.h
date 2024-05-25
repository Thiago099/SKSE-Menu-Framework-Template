#pragma once
#include "SKSEMenuFramework.h"
#include <imgui/imgui.h>
#include "Configuration.h"
namespace UI {
    void Register();
    namespace Example1 {
        void __stdcall Render();
    }
    namespace Example2{
        void __stdcall Render();
        void __stdcall RenderWindow();
        inline MENU_WINDOW ExampleWindow;
    }
    namespace Example3 {
        void __stdcall Render();
    }
};