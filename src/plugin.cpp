#include "Logger.h"
#include "SkyrimImgui.h"
#include <imgui.h>

void OnMessage(SKSE::MessagingInterface::Message* message) {
    if (message->type == SKSE::MessagingInterface::kDataLoaded) {
        // Start
        logger::info("hello world");
        Init();
        AddRenderer("test", []() { 
            ImGui::Text("Hello, from client program");
        });
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