#pragma once
#include "SKSEMenuFramework.h"
#include <imgui/imgui.h>
#include "Configuration.h"
namespace UI {
    void Register();
    namespace Example1 {
        inline uint32_t AddFormId = 0x64B33;
        inline RE::TESBoundObject* AddBoundObject = nullptr;
        void LookupForm();
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