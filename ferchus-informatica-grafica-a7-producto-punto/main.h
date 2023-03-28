#pragma once

void changeWindowSize(int w, int h);

void Initialization();

void processNormalKeys(unsigned char key, int x, int y);

void InputDown(int key, int xx, int yy);

void InputUp(int key, int xx, int yy);

void renderScene(void);

int main(int argc, char* argv[]);

#pragma region Exercise

void DrawCircle(int segments, float amplitude);

#pragma endregion