/*********
  credits.cpp

  Copyright (C) 1999-2023 David Joffe
*********/

#include <stdlib.h> // for NULL
#include "djtypes.h"
#include "credits.h"
#include "menu.h"
#include "graph.h"

djImage *pImageCredits = NULL;

// todo this should just be a generic "DoOK" or "DoDialog" or something?
const struct SMenuItem creditsMenuItems[] =
{
   { false, "        " },
   { true,  "   OK   " },
   { false, "        " },
   { false, "" }
};
unsigned char creditsMenuCursor[] = { 128, 129, 130, 131, 0 };
CMenu creditsMenu ( "credits.cpp:creditsMenu" );

void InitCredits()
{
	// Load credits bitmap
	pImageCredits = new djImage;
	pImageCredits->Load(djDATAPATHc(DATAFILE_IMG_CREDITS));
	djCreateImageHWSurface( pImageCredits );

	creditsMenu.setSize ( 0 );
	creditsMenu.setItems ( creditsMenuItems );
	creditsMenu.setMenuCursor (creditsMenuCursor);
	creditsMenu.setClrBack( djColor(0,0,0) );
	creditsMenu.setXOffset (240);
	creditsMenu.setYOffset (92);
}

void KillCredits()
{
	djDestroyImageHWSurface(pImageCredits);
	djDEL(pImageCredits);
}

void ShowCredits()
{
	// First time?
	if ( !pImageCredits )
		InitCredits();

	// Display credits bitmap
	djgDrawImage( pVisBack, pImageCredits, 0, 0, pImageCredits->Width(), pImageCredits->Height() );
	GraphFlip(true);

	// Pop up credits menu
	do_menu( &creditsMenu );
}
