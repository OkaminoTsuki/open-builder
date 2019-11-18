#include "chunk.h"

namespace client {
    Chunk::Chunk(int x, int z)
    :   m_position(x, z)
    {
    }

    void Chunk::addSection(int chunkY)
    {
        if (chunkY >= 0) {
            while (static_cast<unsigned>(chunkY) > m_sections.size() - 1) {
                m_sections.emplace_back(m_position.x, m_sections.size(),
                                        m_position.y);
            }
        }
    }

    Block Chunk::getBlock(int x, int y, int z)
    {
        if (y < 0) {
            return BlockType::Air;
        }

        int blockY = y % CHUNK_SIZE;
        unsigned sectionIndex = y / CHUNK_SIZE;

        if (sectionIndex >= m_sections.size())
        {
            return BlockType::Air;
        }

        return m_sections[sectionIndex].getBlock({x, blockY, z});
    }
} // namespace client
