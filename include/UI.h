#pragma once
#include "SKSEModHub.h"
#include <imgui/imgui.h>
#include "Configuration.h"
namespace UI {
    void Register();
    namespace Example1 {
        inline float* Number = &Configuration::Example1::Number;
        static void Render();
    }
    namespace Example2 {
        inline float* Color = &Configuration::Example2::Color;
        static void Render();
    }
    namespace Example3 {
        static void Render();
    }
};