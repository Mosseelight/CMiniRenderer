#pragma once

#include "../Glad/include/glad/glad.h"
#include "../Glfw/include/GLFW/glfw3.h"

typedef struct
{
    uint8_t _majorVersion, _minorVersion;
    int _windowSizeX, _windowSizeY;
    char* _title;
} WindowSettings;

//  Struct to allow any type of vertex to be passed in
//  without having to define a Vertex struct with preset types and properties
typedef struct
{
    //  The number of types there is. Will index into numCounts and numOffsets
    //  Ex. a number of 3 would be for a vertex for pos, nor, and uv
    uint8_t numTypes;
    //  The number of inputs for each section of specified data in the vertex
    //  Ex. Position would be 3, then next would be Normals at 3, and Uv with a 2
    uint8_t* numCounts;
    //  The size of the type for each one of the types
    //  Ex. Position is in floats so 4 bytes and using half size it would be 2
    uint8_t* numOffsets;
    //  The total size of the vertex in bytes
    //  Ex. a vertex with pos, nor, and uv would be 30 bytes using a 4 byte float for each
    uint32_t totalSize;
    //  The type that will be inputed into the attrib pointer for opengl
    //  Will partly be determined from the size of the bytes but will need to
    //  be known if it is a int or float
    //  0 will be a float, 1 will be a signed int
    //  with the byte sizes determining if its half size or not
    uint8_t Type;
} VertexOffsets;

typedef struct
{
    //When we want to add a mesh we add it to these
    void* _allMeshVertexData;
    void* _allMeshIndiceData;
    uint32_t meshVertexSize;
    uint32_t meshIndiceSize;
} RendererData;

void InitMiniRenderer(WindowSettings settings, VertexOffsets* offset);
void UpdateMiniRenderer();
void CleanMiniRenderer();
int IsWindowOpen();

//  Quick testing for cube
void AddTriMesh();