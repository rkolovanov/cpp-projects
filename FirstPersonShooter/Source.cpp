#include <iostream>
#include <cstring>
#include <string.h>
#include <Windows.h>

using namespace std;

unsigned int nScreenWidth = 120;
unsigned int nScreenHeight = 40;
unsigned int nScreenSize = nScreenWidth * nScreenHeight;

float fPlayerX = 8.0;
float fPlayerY = 8.0;
float fPlayerAngle = 0.0;

int nMapWidth = 16;
int nMapHeight = 16;

float fFOV = 3.14159 / 4.0;
float fDepth = 16.0;

int main() {
	wchar_t* screen = new wchar_t[nScreenSize];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	wstring map;
	map += L"################";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"################";

	while (true) {
		for (int x = 0; x < nScreenWidth; x++) {
			float fRayAngle = (fPlayerAngle - fFOV / 2.0) + ((float)x / (float)nScreenWidth) * fFOV;
			float fDistanceToWall = 0;

			bool bHitWall = false;

			float fEyeX = sinf(fRayAngle);
			float fEyeY = cosf(fRayAngle);

			while (!bHitWall && fDistanceToWall < fDepth) {
				fDistanceToWall += 0.1;

				int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
				int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

				if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight) {
					bHitWall = true;
					fDistanceToWall = fDepth;
				}
				else {
					if (map[nTestY * nMapWidth + nTestX] == '#') {
						bHitWall = true;
					}
				}
			}

			int nCelling = (float)(nScreenHeight / 2.0) - nScreenWidth / fDistanceToWall;
			int nFloor = nScreenHeight - nCelling;

			for (int y = 0; y < nScreenHeight; y++) {
				if (y < nCelling) {
					screen[y * nScreenWidth + x] = ' ';
				}
				else if (y <= nFloor) {
					screen[y * nScreenWidth + x] = '#';
				}
				else {
					screen[y * nScreenWidth + x] = ' ';
				}
			}
		}

		screen[nScreenSize - 1] = '\0';
		WriteConsoleOutputCharacterW(hConsole, screen, nScreenSize, { 0, 0 }, &dwBytesWritten);
	}

	return 0;
}