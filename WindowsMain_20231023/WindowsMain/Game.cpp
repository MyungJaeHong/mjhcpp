#include "stdafx.h"
#include "Game.h"

void Game::Init()
{
	//---------------------------------------
	//	## �������۸� ����
	//---------------------------------------
	_hdc = GetDC(_hWnd);
	_hdcBack = CreateCompatibleDC(_hdc);
	_bmpBack = CreateCompatibleBitmap(_hdc, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT);
	HBITMAP prevBmp = (HBITMAP)SelectObject(_hdcBack, _bmpBack);
	DeleteObject(prevBmp);

	//---------------------------------------
	//	## Gdiplus ���� ==> �̹��� ���õ� ���̺귯��
	//---------------------------------------
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	Gdiplus::GdiplusStartup(&this->_gdiPlusToken, &gdiplusStartupInput, NULL);


	//---------------------------------------
	//	## �̱��� ����
	//---------------------------------------
	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(SceneManager)->Init();
	GET_SINGLE(KeyManager)->Init();
	GET_SINGLE(CollisionManager)->Init();
	GET_SINGLE(TargetingManager)->Init();

	//---------------------------------------
	//	## �����÷��� ����
	//---------------------------------------
	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev1Scene);
}
void Game::Update()
{
	//---------------------------------------
	//	## �̱��� ����
	//---------------------------------------
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(CollisionManager)->Update();
	GET_SINGLE(SceneManager)->Update();
}
void Game::Render()
{
	GET_SINGLE(SceneManager)->Render(_hdcBack);


	//������ ���
	unsigned int fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	char str[250];
	sprintf_s(str, "FPS(%d), DT(%f)", fps, deltaTime);
	TextOutA(_hdcBack, 0, 0, str, strlen(str));


	//---------------------------------------
	//	## �������۸� ����
	//---------------------------------------
	//Blt => ���Ӻ���
	//BitBlt => DC�� ���Ӻ���
	BitBlt(_hdc, 0, 0, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT, _hdcBack, 0, 0, SRCCOPY);

	//PatBlt => ������� �󸶳� ĥ�Ұ���
	PatBlt(_hdcBack, 0, 0, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT, WHITENESS);
}
void Game::Release()
{
	//---------------------------------------
	//	## �̱��� ����
	//---------------------------------------
	GET_SINGLE(TimeManager)->Release();
	GET_SINGLE(SceneManager)->Release();
	GET_SINGLE(KeyManager)->Release();
	GET_SINGLE(TargetingManager)->Release();
}