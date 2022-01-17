#include "pch.h"
#include "Tests.h"

int main(void)
{
	/*************************************************************
	*	Test Name : TestDrawQuad
	*	Description: Tests the primitive draw call function for 
	*				 Window.DrawQuad()
	*
	*   Expected Behavior: A cyan sqaure should appear in the 
	*					   center of the screen and a dark 
	*					   red square in the bottom left corner.
	* 
	* ***********************************************************/
	//TestDrawQuad();

	/*************************************************************
	*	Test Name : TestQuadTexture
	*	Description: Tests texture rendering on quads
	*
	*   Expected Behavior: 2 images should appear on the screen 
	*					   with a colored sqaure below them.
	*
	* ***********************************************************/
	//TestQuadTexture();

	/*************************************************************
	*	Test Name : TestQuadRotationTranslation
	*	Description: Tests rotation and translation calls for quads
	*
	*   Expected Behavior: Spinning pink square should fly 
	*					   across screen
	*
	* ***********************************************************/
	TestQuadRotationTranslation();

	return 0;
}