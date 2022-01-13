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

