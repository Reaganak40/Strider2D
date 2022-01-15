#include "Texture.h"

// Reset the TextureMap.txt file which stores TextureIDs globally 
// (Note: Most of the time this is just called on program exit)
void Strider2D::ResetTextureMap(void)
{
    std::ofstream ostream;
    ostream.open("data/TextureMap.txt", std::ofstream::out | std::ofstream::trunc);
    ostream << "NoTexture = " << 0;
    ostream.close();
}

// Gets a textureID from the TextureMap, adds to map if not there
int Strider2D::GetTextureFromMap(std::string texture_loc)
{
    std::ifstream stream("data/TextureMap.txt");

    if (!stream) std::cerr << "Could not open the file!" << std::endl;

    std::string line;
    std::string texture;
    std::string textureID;

    // find the ID for this texture
    while (getline(stream, line))
    {
        int seperator = line.find(" = ");
        texture = line.substr(0, seperator);
        textureID = line.substr(seperator + 3);

        if (texture == texture_loc)
        {
            stream.close();
            return std::stoi(textureID);
        }
    }

    // If reached: texture not in TextureMap
    // Add it
    stream.close();

    std::ofstream ostream;
    ostream.open("data/TextureMap.txt", std::ios::app);
    ostream << std::endl << texture_loc << " = " << (std::stoi(textureID) + 1);
    ostream.close();
    return (std::stoi(textureID) + 1);
}

int* Strider2D::GetSamplers(int* returned_size)
{
    std::ifstream stream("data/TextureMap.txt");

    if (!stream) std::cerr << "Could not open the file!" << std::endl;

    std::string line;
    std::string texture;
    std::string textureID;

    int temp_samplers[32] = { 0 }; // OpenGL only supports 32 active textures
    int current_index = 0;

    // traverse through the texure map and get all the ids
    while (getline(stream, line))
    {
        int seperator = line.find(" = ");
        texture = line.substr(0, seperator);
        textureID = line.substr(seperator + 3);

        temp_samplers[current_index] = std::stoi(textureID);
        current_index++;

        if (current_index == 32)
            break;
    }

    int* samplers = new int[current_index];
    for (int i = 0; i < current_index; i++)
        samplers[i] = temp_samplers[i];

    *returned_size = current_index;

    // return all ids
    stream.close();
    return samplers;
}

std::string Strider2D::GetTextureFromMap(int texture_id)
{
    std::ifstream stream("data/TextureMap.txt");

    if (!stream) std::cerr << "Could not open the file!" << std::endl;

    std::string line;
    std::string texture;
    std::string textureID;

    // find the ID for this texture
    while (getline(stream, line))
    {
        int seperator = line.find(" = ");
        texture = line.substr(0, seperator);
        textureID = line.substr(seperator + 3);

        if (std::stoi(textureID) == texture_id)
        {
            stream.close();
            return texture;
        }
    }

    stream.close();
    return "NoTexture";
}

namespace Strider2D
{
    namespace Renderer
    {
        Texture::Texture(const std::string& path)
            : m_RendererID(0), m_Filepath(path), m_LocalBuffer(nullptr),
            m_Width(0), m_Height(0), m_BPP(0)
        {

            stbi_set_flip_vertically_on_load(1);
            m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

            GLCall(glGenTextures(1, &m_RendererID));
            GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));

            // bind textures
            GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
            GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
            GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
            GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

            GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));
            GLCall(glBindTexture(GL_TEXTURE_2D, 0));

            if (m_LocalBuffer) {
                stbi_image_free(m_LocalBuffer);
            }
        }

        Texture::~Texture()
        {
            GLCall(glDeleteTextures(1, &m_RendererID));
        }

        void Texture::Bind(unsigned int slot) const
        {
            GLCall(glActiveTexture(GL_TEXTURE0 + slot));
            GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));

        }

        void Texture::Unbind() const
        {
            GLCall(glBindTexture(GL_TEXTURE_2D, 0));
        }
    }
}

