#include "Logger.h"
#include "SkyrimImgui.h"
#include <imgui.h>

void OnMessage(SKSE::MessagingInterface::Message* message) {
    if (message->type == SKSE::MessagingInterface::kDataLoaded) {
        // Start
        SkyrimImgui::Init("Another Dll");
        SkyrimImgui::AddSection("screen4", []() { 
            ImGui::Text("Screen 4 data");
        });
        SkyrimImgui::AddSection("group1/screen5", []() { ImGui::Text("screen 5 data"); });
        SkyrimImgui::AddSection("group1/screen6", []() { ImGui::Text("screen 6 data"); });
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
    return true;
}