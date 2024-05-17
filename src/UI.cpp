#include "UI.h"
char* example1buffer = new char[256];
float example1Number = 0;
float example2color = 0;
bool example2toolActive = true;

void Example1() 
{
    ImGui::Text("Example text %d", 123);
    if (ImGui::Button("Log Hello World")) {
        logger::trace("hello world");
    }
    ImGui::InputText("string", example1buffer, 256);
    ImGui::SliderFloat("float", &example1Number, 0.0f, 1.0f);
}

void Example2() 
{
    // Edit a color stored as 4 floats
    ImGui::ColorEdit4("Color", &example2color);

    // Generate samples and plot them
    float samples[100];
    for (int n = 0; n < 100; n++) samples[n] = sinf(n * 0.2f + ImGui::GetTime() * 1.5f);
    ImGui::PlotLines("Samples", samples, 100);

    // Display contents in a scrolling region
    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Important Stuff");
    ImGui::BeginChild("Scrolling");
    for (int n = 0; n < 50; n++) ImGui::Text("%04d: Some text", n);
    ImGui::EndChild();
}

void Example3() 
{
    static ImGuiTableFlags flags = ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable |
                                   ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV |
                                   ImGuiTableFlags_NoBordersInBody | ImGuiTableFlags_ScrollY;

    if (ImGui::BeginTable("table1", 3, flags)) {
        // Display headers so we can inspect their interaction with borders
        // (Headers are not the main purpose of this section of the demo, so we are not elaborating on them now.
        // See other sections for details)
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

void UI::Register() {
    example1buffer[0] = '\0';
    SKSEModHub::Init("SKSE Mod Hub Template");
    SKSEModHub::AddSection("Example 1", Example1);
    SKSEModHub::AddSection("Group 1/Example 2", Example2);
    SKSEModHub::AddSection("Group 1/Example 3", Example3);
}