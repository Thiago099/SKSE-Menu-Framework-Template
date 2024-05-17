#include "UI.h"

void UI::Register() {
    Configuration::Example1::Buffer[0] = '\0';
    SKSEModHub::Init("SKSE Mod Hub Template 2");
    SKSEModHub::AddSection("Example 4", Example1::Render);
    SKSEModHub::AddSection("Group 2/Example 5", Example2::Render);
    SKSEModHub::AddSection("Group 2/Example 6", Example3::Render);
}

void UI::Example1::Render() 
{
    // Do not create pointers inside the render code
    // It will not crash right away but it might crash at some point
    // If you create them outside and use here is safe
    ImGui::Text("Example text %d", 123);
    if (ImGui::Button("Log Hello World")) {
        logger::trace("hello world");
    }
    ImGui::InputText("string", Configuration::Example1::Buffer, 256);
    ImGui::SliderFloat("float", Number, 0.0f, 1.0f);
}

void UI::Example2::Render() 
{
    // Do not create pointers inside the render code
    // It will not crash right away but it might crash at some point
    // If you create them outside and use here is safe
    ImGui::ColorEdit4("Color", Color);
    float samples[100];
    for (int n = 0; n < 100; n++) samples[n] = sinf(n * 0.2f + ImGui::GetTime() * 1.5f);
    ImGui::PlotLines("Samples", samples, 100);
    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Important Stuff");
    ImGui::BeginChild("Scrolling");
    for (int n = 0; n < 50; n++) ImGui::Text("%04d: Some text", n);
    ImGui::EndChild();
}

void UI::Example3::Render() 
{
    // Do not create pointers inside the render code
    // It will not crash right away but it might crash at some point
    // If you create them outside and use here is safe
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