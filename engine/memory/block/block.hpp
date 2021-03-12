#ifndef MEMORY_BLOCK_HPP
#define MEMORY_BLOCK_HPP

#include "memory/memory.hpp"
#include "memory/memory.cpp"
#include "memory/allocator/blueprint.hpp"

#include <cinttypes>
#include <string>

#define BLOCKMEMORY_DEFAULT_NO_OF_BLOCKS  4

namespace mnt {
  template <typename T>
  class BlockMemory : public MNTMemory<T>
  {
  public:
    inline uint16_t NoOfBlocks() {return m_no_of_blocks;};

    virtual void SaveToFile(const char* p_file_path);
    virtual void LoadFromFile(const char* p_file_path) = 0;
    virtual void LoadFromFile(const char* p_file_path, const uint16_t p_no_of_blocks) = 0;

    virtual void Reshape(const uint16_t no_of_blocks) = 0;

    virtual std::string ToHex();

    template<typename U>
    U& GetAsType(const size_t p_index);

    template<typename U>
    void SetAsType(const size_t p_index, const U& p_value);

  protected:
    BlockMemory(Allocator* p_allocator = nullptr);
    virtual ~BlockMemory() noexcept = default;
    size_t m_block_size;
    size_t m_block_length;
    void** m_block_array;
    uint16_t m_no_of_blocks = BLOCKMEMORY_DEFAULT_NO_OF_BLOCKS;
  };
}

#endif