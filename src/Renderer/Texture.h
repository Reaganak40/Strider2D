#ifndef S2D_TEXTURE_H
#define S2D_TEXTURE_H

#include "core.h"
#include <string>
#include <iostream>
#include <fstream>
#include "stb_image/stb_image.h"

namespace Strider2D
{

	void ResetTextureMap(void);
	int GetTextureFromMap(std::string texture_loc);
	int* GetSamplers(int* returned_size);
	std::string GetTextureFromMap(int texture_id);

	namespace Renderer
	{
		class Texture
		{
		private:

			unsigned int m_RendererID;
			std::string m_Filepath;
			unsigned char* m_LocalBuffer;
			int m_Width, m_Height, m_BPP;

		public:

			Texture(const std::string& path);
			~Texture();

			void Bind(unsigned int slot = 0) const;
			void Unbind() const;

			inline int GetWidth() const { return m_Width; }
			inline int GetHeight() const { return m_Height; }
			inline int GetRendererID() const { return m_RendererID; }
			inline std::string getFilepath() const { return m_Filepath; }


		};
	}
}

#endif // !S2D_TEXTURE_H