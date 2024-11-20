#include "InputHelper.hpp"

#include <string>

std::string Prompt(const std::string& message) {
    std::string inputText;
    bool isEnteringText = true;

    while (isEnteringText && !WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawPrompt(message, inputText);

        // Capture user input
        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= 32) && (key <= 125)) {
                inputText += static_cast<char>(key);
            }
            key = GetCharPressed();
        }

        // Handle backspace
        if (IsKeyPressed(KEY_BACKSPACE) && !inputText.empty()) {
            inputText.pop_back();
        }

        // Finish input on Enter key
        if (IsKeyPressed(KEY_ENTER)) {
            isEnteringText = false;
        }

        EndDrawing();
    }

    return inputText;
}

void DrawPrompt(const std::string& message, const std::string& inputText) {
    DrawText(message.c_str(), 100, 200, 20, WHITE);
    DrawText(inputText.c_str(), 100, 250, 20, GREEN);
}
