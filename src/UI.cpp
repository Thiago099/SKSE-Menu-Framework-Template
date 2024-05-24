#include "UI.h"

void UI::Register() {
    Configuration::Example2::Buffer[0] = '\0';
    SKSEModHub::Init("SKSE Mod Hub Template 2");
    SKSEModHub::AddSection("Cheese Menu", Example1::Render);
    SKSEModHub::AddSection("Examples/Example 1", Example2::Render);
    SKSEModHub::AddSection("Examples/Example 2", Example3::Render);
}

void __stdcall UI::Example1::Render() {
    ImGui::Text("How much cheese would you like to add? Currently: %d", Configuration::Example1::Number);
    ImGui::SliderInt("number", &Configuration::Example1::Number, 1, 100);
    if (ImGui::Button("Add")) {
        auto player = RE::PlayerCharacter::GetSingleton()->As<RE::TESObjectREFR>();
        auto cheese = RE::TESForm::LookupByID(0x64B33)->As<RE::TESBoundObject>();
        player->AddObjectToContainer(cheese, nullptr, Configuration::Example1::Number, nullptr);
    }
}

void __stdcall UI::Example2::Render() {
    ImGui::InputText("string", Configuration::Example2::Buffer, 256);
    ImGui::ColorEdit4("Color", &Configuration::Example2::Color);
    float samples[100];
    for (int n = 0; n < 100; n++) samples[n] = sinf(n * 0.2f + ImGui::GetTime() * 1.5f);
    ImGui::PlotLines("Samples", samples, 100);
    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Important Stuff");
    ImGui::BeginChild("Scrolling");
    for (int n = 0; n < 50; n++) ImGui::Text("%04d: Some text", n);
    ImGui::EndChild();
}

void __stdcall UI::Example3::Render() {
    static ImGuiTableFlags flags = ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable |
                                   ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV |
                                   ImGuiTableFlags_NoBordersInBody | ImGuiTableFlags_ScrollY;

    if (ImGui::BeginTable("table1", 3, flags)) {
        ImGui::TableSetupColumn("One");
        ImGui::TableSetupColumn("Two");
        ImGui::TableSetupColumn("Three");
        ImGui::TableHeadersRow();

        for (int row = 0; row < 5; row++) {
            ImGui::TableNextRow();
            for (int column = 0; column < 3; column++) {
                ImGui::TableSetColumnIndex(column);
                char buf[32];
                sprintf(buf, "Hello %d,%d", column, row);
                if (column == 2) {
                    ImGui::Button(buf, ImVec2(-FLT_MIN, 0.0f));
                } else {
                    ImGui::TextUnformatted(buf);
                }
            }
        }
        ImGui::EndTable();
    }
}