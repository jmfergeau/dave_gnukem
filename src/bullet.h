/*!
\file    bullets.h
\brief   Bullet class
\author  David Joffe

Copyright (C) 2002-2022 David Joffe
*/
#ifndef _BULLET_H_
#define _BULLET_H_

// In DG1 bullet is 16x8, but we let this scale up/down if using different custom blocksize.
#define BULLET_WIDTH BLOCKW
#define BULLET_HEIGHT HALFBLOCKH

class CBullet
{
public:
	enum EType
	{
		BULLET_HERO,
		BULLET_MONSTER
	};
	CBullet();
	virtual ~CBullet();

	virtual void Tick(float fDeltaTime_ms);
	virtual void Draw(float fDeltaTime_ms);

	int x; // World (pixel) X coordinate
	int y; // World (pixel) Y coordinate
	int dx;
	int dy;
	bool bDrawnOnce;
	int nAnim;
	EType eType;
};

#endif
