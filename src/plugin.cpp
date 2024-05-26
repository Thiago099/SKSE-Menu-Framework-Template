#include "Plugin.h"

void OnMessage(SKSE::MessagingInterface::Message* message) {
    if (message->type == SKSE::MessagingInterface::kDataLoaded) {
        UI::Example1::LookupForm();
    }
    if (message->type == SKSE::MessagingInterface::kPostLoad) {
        UI::Register();
    }
    if (message->type == SKSE::MessagingInterface::kPostLoadGame) {
    }
}

SKSEPluginLoad(const SKSE::LoadInterface *skse) {
    SKSE::Init(skse);
    SKSE::GetMessagingInterface()->RegisterListener(OnMessage);
    SetupLog();
    logger::info("Plugin loaded");
    return true;
}