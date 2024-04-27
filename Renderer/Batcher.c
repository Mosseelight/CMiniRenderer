#include "Batcher.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  use the renderset way but just have one for now
RenderSet _renderSet;

void InitRenderSet(const VertexOffsets* offsets)
{
    glGenVertexArrays(1, &_renderSet.vao);
    glBindVertexArray(_renderSet.vao);
    glGenBuffers(1, &_renderSet.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _renderSet.vbo);
    glGenBuffers(1, &_renderSet.ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _renderSet.ebo);

    for (uint8_t i = 0; i < offsets->numTypes; ++i)
    {
        glEnableVertexAttribArray(i);
        //  0 is for float and 1 is for ints
        switch (offsets->Type)
        {
            default:
                glVertexAttribPointer(i, offsets->numCounts[i], GL_FLOAT, 0, offsets->totalSize, (void*)(offsets->numCounts[i] * sizeof(float)));
            case 0:
            {
                //  full size float with 4 and half and a double
                if(offsets->numOffsets[i] == 4)
                    glVertexAttribPointer(i, offsets->numCounts[i], GL_FLOAT, 0, offsets->totalSize, (void*)(offsets->numCounts[i] * 4));
                else if(offsets->numOffsets[i] == 2)
                    glVertexAttribPointer(i, offsets->numCounts[i], GL_HALF_FLOAT, 0, offsets->totalSize, (void*)(offsets->numCounts[i] * 2));
                else if(offsets->numOffsets[i] == 8)
                    glVertexAttribPointer(i, offsets->numCounts[i], GL_DOUBLE, 0, offsets->totalSize, (void*)(offsets->numCounts[i] * 2));
            }
            case 1:
            {
                //  full size int with 4 and half with 2
                if(offsets->numOffsets[i] == 4)
                    glVertexAttribPointer(i, offsets->numCounts[i], GL_INT, 0, offsets->totalSize, (void*)(offsets->numCounts[i] * 4));
                else if(offsets->numOffsets[i] == 2)
                    glVertexAttribPointer(i, offsets->numCounts[i], GL_SHORT, 0, offsets->totalSize, (void*)(offsets->numCounts[i] * 2));
            }
        }
    }

    glBindVertexArray(0);
}

void UpdateRenderSet(const void* meshVertexData, const void* meshIndiceData, const uint32_t vertexSize, const uint32_t indiceSize)
{
    glBindVertexArray(_renderSet.vao);
    glBindBuffer(GL_ARRAY_BUFFER, _renderSet.vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _renderSet.ebo);

    glBufferData(GL_ARRAY_BUFFER, vertexSize, meshVertexData, GL_STREAM_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indiceSize, meshIndiceData, GL_STREAM_DRAW);

    glBindVertexArray(0);
}

void CleanRenderSet()
{
    glDeleteVertexArrays(1, &_renderSet.vao);
    glDeleteBuffers(1, &_renderSet.vbo);
    glDeleteBuffers(1, &_renderSet.ebo);
}
