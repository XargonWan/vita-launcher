#ifndef LAUNCHER_WINDOWS_H
#define LAUNCHER_WINDOWS_H

#include <imgui_vita2d/imgui_vita.h>
#include <imgui_vita2d/imgui_internal.h>

extern int view_mode;

namespace Windows {
    inline void SetupWindow(void) {
        ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Once);
        ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y), ImGuiCond_Once);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    };

    inline void SetTabActive(const char* tab_bar, const char* tab_name)
    {
        GImGui->TabBars.GetByKey(ImGui::GetID(tab_bar))->SelectedTabId = ImGui::GetID(tab_name);
    }

    inline void SetNavFocusHere()
    {
        GImGui->NavId = GImGui->CurrentWindow->DC.LastItemId;
    }

    inline void ClearNavFocus()
    {
        GImGui->NavId = 0;
    }

    void Init();
    void HandleLauncherWindowInput();
    void LauncherWindow();
    void ShowGridViewWindow();
    void ShowListViewWindow();
    void ShowSettingsDialog();
    void GameScanWindow();
    void ShowTabBar();
    void HandleAddNewGame();
    void HandleAdrenalineGame();
    void HandleImeInput();
    void MultiValueImeCallback(int ime_result);
    void SingleValueImeCallback(int ime_result);
    void NullCallback(int ime_result);
    void AfterTitleChangeCallback(int ime_result);
    void BeforeTitleChangeCallback(int ime_result);
}

#endif
