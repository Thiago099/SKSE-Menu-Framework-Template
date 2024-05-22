#pragma once
#include <imgui.h>

#define EXTERNAL_FUNCTION extern "C" __declspec(dllimport) 

namespace SKSEModHubInternal {

    typedef void(__stdcall* RenderFunction)();

    inline std::string key;

    EXTERNAL_FUNCTION void AddSection(const char* path, SKSEModHubInternal::RenderFunction rendererFunction);

    EXTERNAL_FUNCTION void SetContextFetch(std::function<void(ImGuiContext*)> contextSetFunction);

}
namespace SKSEModHub{
     
    EXTERNAL_FUNCTION void AddWindow(const char* key, ImGuiWindowFlags flags,
                                     SKSEModHubInternal::RenderFunction rendererFunction);

    inline void AddSection(std::string menu, SKSEModHubInternal::RenderFunction rendererFunction) {
        SKSEModHubInternal::AddSection((SKSEModHubInternal::key + "/" + menu).c_str(),
                                       rendererFunction);
    }

    inline void Init(std::string key) {
        SKSEModHubInternal::key = key;
        SKSEModHubInternal::SetContextFetch([](ImGuiContext* ctx) {
            ImGui::SetCurrentContext(ctx);
        });
    }
}