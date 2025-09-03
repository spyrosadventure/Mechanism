#include "ImGuiStyles.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <PKPackageMgr.h>
#include "Panels/ChunkPanel.h"
#include "Panels/ViewerPanel.h"
#include "Config.h"

// cant think of a better way to do this smh
struct OpenedFile {
    std::string path;
    std::string name;
    ChunkPanel chunkPanel;
    ViewerPanel viewerPanel;
};

void glfw_error_callback(int error, const char* description) {
    std::cerr << "GLFW Error " << error << ": " << description << std::endl;
}

const char* windowTitle = "Mechanism | Chunk Viewer for Goliath";
std::filesystem::path configPath;

// sorry if you have to read through all of this, I really don't like how I made this, I am still learning C++ though so I'll improve this someday!
int main() {
    configPath = GetAppDataPath() / "config.ini"; // this is so ass, but it should go to AppData/Local/Mechanism hopefully.

    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) return 1;

    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(1280, 720, windowTitle, nullptr, nullptr);
    if (!window) return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize OpenGL loader!" << std::endl;
        return -1;
    }

    // Literally all of my ImGui code is all over the place, gonna fix this eventually
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::LoadIniSettingsFromDisk(configPath.string().c_str());
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.Fonts->AddFontDefault();
    io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/seguiemj.ttf", 16.0f, nullptr, io.Fonts->GetGlyphRangesDefault());
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    SetupStyles();

    // idk if this is supposed to be a vector or not. probably not but whoops
    std::vector<OpenedFile> openedFiles;
    char folderPath[256] = "";
    char fileName[128] = "";

    if (auto lastPath = LoadLastOpenedPath(); !lastPath.empty()) {
        std::cout << "Restored last opened path: " << lastPath << std::endl;
        std::filesystem::path p(lastPath);
        strcpy_s(folderPath, sizeof(folderPath), p.parent_path().string().c_str()); // strcpy_s cause compiler doesnt like strcpy
        strcpy_s(fileName, sizeof(fileName), p.filename().string().c_str());
    }

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::Begin("MainWindow", nullptr,
            ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus);

        // Whole tab system sucks, I will be re-doing this when I start making GSX's Level System lol

        if (ImGui::BeginTabBar("MainTabs", ImGuiTabBarFlags_FittingPolicyScroll)) {

            if (ImGui::BeginTabItem("Launcher")) {
                ImGui::BeginChild("LauncherChild", ImGui::GetContentRegionAvail(), false);

                ImGui::TextWrapped("Open a file:");
                ImGui::Spacing();
                ImGui::InputText("Folder Path", folderPath, sizeof(folderPath));
                ImGui::InputText("File Name", fileName, sizeof(fileName));

                static GoliathGame currentGame = GoliathGame::MonstersVsAliens;
                if (ImGui::BeginCombo("Select Game", GoliathGameToString(currentGame))) { // I dislike the GoliathGame stuff, it just feels overly complicated.
                    for (int i = 0; i <= (int)GoliathGame::SuperChargersRacing; i++) {
                        GoliathGame game = static_cast<GoliathGame>(i);
                        bool isSelected = (currentGame == game);
                        if (ImGui::Selectable(GoliathGameToString(game), isSelected))
                            currentGame = game;
                        if (isSelected) ImGui::SetItemDefaultFocus();
                    }
                    ImGui::EndCombo();
                }

                ImGui::Spacing();
                if (ImGui::Button("Open File")) {
                    std::string fullPath = std::string(folderPath) + "/" + std::string(fileName);
                    PKPackageMgr package;
                    package.is64bit = Check64BitGame(currentGame); // This is the only good part of GoliathGame, makes stuff much simpler for me.
                    package.isBigEndian = true; // lmao wtf?? this gets overwritten i think

                    if (package.ReadFile(fullPath)) {
                        SaveLastOpenedPath(fullPath);
                        openedFiles.push_back({ folderPath, fileName, {}, {} });
                        OpenedFile& of = openedFiles.back();
                        of.chunkPanel.chunks = package.chunks;

                        if (!of.chunkPanel.chunks.empty()) { // this caused so many errors before i added this check!
                            of.chunkPanel.selectedChunk = &of.chunkPanel.chunks[0];
                            of.viewerPanel.selectedChunk = of.chunkPanel.selectedChunk;
                        }
                    }
                }

                ImGui::EndChild();
                ImGui::EndTabItem();
            }

            for (size_t i = 0; i < openedFiles.size(); ++i) {
                OpenedFile& of = openedFiles[i];
                if (ImGui::BeginTabItem(of.name.c_str())) {
                    ImGui::BeginChild(("FileChild" + std::to_string(i)).c_str(), ImGui::GetContentRegionAvail(), false);

                    ImGui::DockSpace(ImGui::GetID(("DockSpace" + std::to_string(i)).c_str()));
                    of.chunkPanel.Render();
                    of.viewerPanel.selectedChunk = of.chunkPanel.selectedChunk;
                    of.viewerPanel.Render();

                    ImGui::EndChild();
                    ImGui::EndTabItem();
                }
            }
            ImGui::EndTabBar();
        }
        ImGui::End();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    ImGui::SaveIniSettingsToDisk(configPath.string().c_str());
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
