#include <iostream>
#include <fstream>

#include "Strider2D.h"

// Copies the contents of a Vector src to the new Vector dst
void Strider2D::CopyVector(const Vector src, Vector& dst)
{
    dst.Position[0] = src.Position[0];
    dst.Position[1] = src.Position[1];

    dst.Color[0] = src.Color[0];
    dst.Color[1] = src.Color[1];
    dst.Color[2] = src.Color[2];
    dst.Color[3] = src.Color[3];

    dst.TextureCoords[0] = src.TextureCoords[0];
    dst.TextureCoords[1] = src.TextureCoords[1];

    dst.TextureID = src.TextureID;

}

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
