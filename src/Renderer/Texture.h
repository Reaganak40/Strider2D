#ifndef S2D_TEXTURE_H
#define S2D_TEXTURE_H

#include <string>
#include <iostream>
#include <fstream>

namespace Strider2D
{

	void ResetTextureMap(void);
	int GetTextureFromMap(std::string texture_loc);

}

#endif // !S2D_TEXTURE_H