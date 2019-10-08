#include <iostream>
#include <string>
#include <algorithm>

#include "olcConsoleGameEngine.h"

using namespace std;

class FirstPersonConsoleGame: public olcConsoleGameEngine {
public:

	FirstPersonConsoleGame() {
		m_sAppName = L"FirstPersonConsoleGame";
	}

	virtual bool OnUserCreate() {
		map += L"################################";
		map += L"#..............................#";
		map += L"#..............................#";
		map += L"#..................##..........#";
		map += L"#...##.............##..........#";
		map += L"#...##.........................#";
		map += L"#.........#....................#";
		map += L"#.........#....................#";
		map += L"#.........#....................#";
		map += L"#.........#....................#";
		map += L"#.........#....................#";
		map += L"#........##............#########";
		map += L"#........##....................#";
		map += L"#..............................#";
		map += L"#..............................#";
		map += L"#..............................#";
		map += L"#..............######.....######";
		map += L"#..............................#";
		map += L"#..............................#";
		map += L"#..................##..........#";
		map += L"#...###............##..........#";
		map += L"#...##.........................#";
		map += L"#.........#....................#";
		map += L"#.........#....................#";
		map += L"#.........#....................#";
		map += L"#.........#....................#";
		map += L"#.........#....................#";
		map += L"#........##............#########";
		map += L"#........##....................#";
		map += L"#..............................#";
		map += L"#..............................#";
		map += L"################################";

		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime) {
		if (m_keys[L'A'].bHeld) {
			fPlayerAngle -= 1.5 * fElapsedTime;
		}

		if (m_keys[L'D'].bHeld) {
			fPlayerAngle += 1.5 * fElapsedTime;
		}

		if (m_keys[L'W'].bHeld) {
			float fDeltaX = sinf(fPlayerAngle) * 5.0 * fElapsedTime;
			float fDeltaY = cosf(fPlayerAngle) * 5.0 * fElapsedTime;

			fPlayerX += fDeltaX;
			fPlayerY += fDeltaY;

			if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#') {
				fPlayerX -= fDeltaX;
				fPlayerY -= fDeltaY;
			}
		}

		if (m_keys[L'S'].bHeld) {
			float fDeltaX = sinf(fPlayerAngle) * 5.0 * fElapsedTime;
			float fDeltaY = cosf(fPlayerAngle) * 5.0 * fElapsedTime;

			fPlayerX -= fDeltaX;
			fPlayerY -= fDeltaY;

			if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#') {
				fPlayerX += fDeltaX;
				fPlayerY += fDeltaY;
			}
		}

		if (m_keys[L'Q'].bHeld) {
			float fDeltaX = sinf(fPlayerAngle) * 5.0 * fElapsedTime;
			float fDeltaY = cosf(fPlayerAngle) * 5.0 * fElapsedTime;

			fPlayerX += fDeltaY;
			fPlayerY -= fDeltaX;

			if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#') {
				fPlayerX -= fDeltaY;
				fPlayerY += fDeltaX;
			}
		}

		if (m_keys[L'E'].bHeld) {
			float fDeltaX = sinf(fPlayerAngle) * 5.0 * fElapsedTime;
			float fDeltaY = cosf(fPlayerAngle) * 5.0 * fElapsedTime;

			fPlayerX -= fDeltaY;
			fPlayerY += fDeltaX;

			if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#') {
				fPlayerX += fDeltaY;
				fPlayerY -= fDeltaX;
			}
		}

		for (int x = 0; x < ScreenWidth(); x++) {
			float fRayAngle = (fPlayerAngle - fFOV / 2.0) + ((float)x / (float)ScreenWidth()) * fFOV;
			float fDistanceToWall = 0;

			bool bHitWall = false;
			bool bBoundary = false;

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

						vector<pair<float, float>> dots;

						for (int tx = 0; tx < 2; tx++) {
							for (int ty = 0; ty < 2; ty++) {
								float vx = (float)nTestX + tx - fPlayerX;
								float vy = (float)nTestY + ty - fPlayerY;
								float distance = sqrt(vx * vx + vy * vy);
								float dot = (fEyeX * vx / distance) + (fEyeY * vy / distance);

								dots.push_back(make_pair(distance, dot));
							}
						}

						sort(dots.begin(), dots.end(), [](const pair<float, float>& left, const pair<float, float>& right) { return left.first < right.first; });

						float fBound = 0.005;
						if (acos(dots.at(0).second) < fBound) {
							bBoundary = true;
						}
						if (acos(dots.at(1).second) < fBound) {
							bBoundary = true;
						}

					}
				}
			}

			int nCelling = (float)(ScreenHeight() / 2.0) - ScreenHeight() / fDistanceToWall;
			int nFloor = ScreenHeight() - nCelling;

			short int nShade = ' ';

			if (fDistanceToWall <= fDepth / 4.0) {
				nShade = 0x2588;
			}
			else if (fDistanceToWall <= fDepth / 3.0) {
				nShade = 0x2593;
			}
			else if (fDistanceToWall <= fDepth / 2.0) {
				nShade = 0x2592;
			}
			else if (fDistanceToWall <= fDepth) {
				nShade = 0x2591;
			}

			if (bBoundary) {
				nShade = ' ';
			}

			for (int y = 0; y < ScreenHeight(); y++) {
				if (y < nCelling) {
					Draw(x, y, ' ');
				}
				else if (y <= nFloor) {
					Draw(x, y, nShade);
				}
				else {
					float b = 1.0 - ((float)y - ScreenHeight() / 2.0) / ((float)ScreenHeight() / 2.0);
					if (b < 0.25) {
						nShade = '#';
					}
					else if (b < 0.5) {
						nShade = 'x';
					}
					else if (b < 0.75) {
						nShade = '-';
					}
					else if (b < 0.9) {
						nShade = '.';
					}
					else {
						nShade = ' ';
					}
					Draw(x, y, nShade);
				}
			}
		}

		for (int mx = 0; mx < nMapWidth; mx++) {
			for (int my = 0; my < nMapHeight; my++) {
				Draw(mx + 1, my + 1, map[my * nMapWidth + mx]);
			}
		}

		Draw(fPlayerX + 1, fPlayerY + 1, 'P');

		return true;
	}

private:

	wstring map;

	int nMapWidth = 32;
	int nMapHeight = 32;

	float fPlayerX = 8.0;
	float fPlayerY = 8.0;
	float fPlayerAngle = 0.0;
	float fFOV = 3.14159 / 4.0;
	float fDepth = 16.0;

};


int main() {
	FirstPersonConsoleGame game;
	game.ConstructConsole(320, 160, 4, 4);
	game.Start();

	return 0;
}