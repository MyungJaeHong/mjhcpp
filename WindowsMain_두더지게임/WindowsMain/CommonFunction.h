#pragma once
//===========================================
//    ## 자주 사용하는 함수 정의 ##
//		(직접 추가해서 사용함)
//===========================================

// 사각형 관련된 함수
namespace Rect
{
	//x, y를 기준으로  width height를 만든다.
	inline RECT MakeRect(int x, int y, int width, int height)
	{
		RECT rc;
		rc.left = x;
		rc.top = y;
		rc.right = x + width;
		rc.bottom = y + height;

		return rc;
	}

	//x, y를 센터라고 가정했을때  width height로 사각형을 만든다.
	inline CenterRect MakeCenterRect(int x, int y, int width, int height)
	{
		CenterRect rc;
		rc.x = x;
		rc.y = y;
		rc.width = width;
		rc.height = height;

		return rc;
	}
}

namespace Draw
{
	inline void Rect(HDC hdc, RECT rc)
	{
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}

	inline void Rect(HDC hdc, CenterRect rc)
	{
		Rectangle(hdc, 
			rc.x - rc.width / 2,	//left
			rc.y - rc.height / 2,	//top
			rc.x + rc.width / 2,	//right
			rc.y + rc.height / 2	//bottom
		);
	}

	inline void Circle(HDC hdc, RECT rc)
	{
		Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}

	inline void Circle(HDC hdc, CenterRect rc)
	{
		Ellipse(hdc,
			rc.x - rc.width / 2,	//left
			rc.y - rc.height / 2,	//top
			rc.x + rc.width / 2,	//right
			rc.y + rc.height / 2	//bottom
		);
	}
}

namespace Random
{
	//from ~ to까지 랜덤생성해주는 함수 (from 은 나올수도있음, to는 안나옴)
	inline int GetInt(int fromInclude, int toExclude)
	{
		return rand() % (fromInclude + 1) + rand() % (toExclude - fromInclude);
	}
}

namespace Collision
{
	bool PtInRect(CenterRect rect, POINT pt);
	bool RectInRect(CenterRect rect1, CenterRect rect2);
}