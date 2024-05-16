#include "Logger.h"
#include "SkyrimImgui.h"
#include <imgui.h>

void OnMessage(SKSE::MessagingInterface::Message* message) {
    if (message->type == SKSE::MessagingInterface::kDataLoaded) {
        // Start
    }
    if (message->type == SKSE::MessagingInterface::kPostLoadGame) {
        // Post-load
    }
}

SKSEPluginLoad(const SKSE::LoadInterface *skse) {

    SetupLog();
    logger::info("Plugin loaded");

    SKSE::Init(skse);
    SKSE::GetMessagingInterface()->RegisterListener(OnMessage);

    SkyrimImgui::Init("Another Dll");
    SkyrimImgui::AddSection("screen4", "Screen 4", []() { ImGui::Text("Screen 4 data"); });
    SkyrimImgui::AddSection("group1/screen5", "Screen 5", []() { ImGui::Text("screen 5 data"); });
    SkyrimImgui::AddSection("group1/screen6", "Screen 6", []() { ImGui::Text("screen 6 data"); });

    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoCollapse;

    //SkyrimImgui::AddWindow("MyVeryOwnWindow", window_flags, []() { ImGui::Text("screen 64 data"); });

    return true;
}