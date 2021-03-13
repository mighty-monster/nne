// File Name:     block_heap.hpp
// Author:        Arash Fatehi
// Date:          13th Mar 2021
// Description:   Block heap memory class
// ---------------------

// ---------------------
// Detail Description:
// An implementation of BlockMemory abstract class, in order to allocate enough memory,
// it needs a type as template argument in addition to it`s length and uses "new" and "delete"
// ---------------------

// ---------------------
// Note:
// Allocates one extra item per block to simplicity, the extra allocated memory will left
// empty at the end of last block
// ---------------------

// ---------------------
// Note:
// When allocated on RAM, BlockHeapMemory was approximately 3 times slower than LinearHeapMemory
// on x86_64, GCC 10.2.0, Linux 4.19, with 4 blocks due to the needed logic
// for addressing the correct block and offset
// ---------------------

// =====
// [LoadFromFile(p_file_path)]: Load content of memory from a binary file
// =====

// =====
// [Resize(p_length)]: Allocate or Deallocate blocks, no allocation will happen if current
// configuration (m_no_of_blocks * m_block_size) is suitable for storing p_length items of type T
// Allocate a new blocks if needs more memory, and Deallocates unnecessary blocks if p_length < m_length
// =====

// =====
// [Reshape(p_no_of_blocks)]: Changes the number of memory blockes, it is a very expensive operation
// when big amount of memory is allocated, despite the need for reallocations of blocks, the copy logic
// is also relatively complicated, but still the time complexity is O(n), so avoid unless necessary.
// =====

#ifndef MEMORY_BLOCK_HEAP_HPP
#define MEMORY_BLOCK_HEAP_HPP

#include "memory/block/block.hpp"
#include "memory/block/block.cpp"

namespace mnt {
  template <typename T>
  class BlockHeapMemory : public BlockMemory<T>
  {
  public:
    BlockHeapMemory() = default;
    BlockHeapMemory(const char* p_file_path);
    BlockHeapMemory(const char* p_file_path, const uint16_t p_no_of_blocks);
    BlockHeapMemory(const size_t p_length);
    BlockHeapMemory(const size_t p_length, const uint16_t p_no_of_blocks);
    ~BlockHeapMemory();

    void Allocate(const size_t p_length, const uint16_t p_no_of_blocks);
    void Deallocate() noexcept;

    virtual void LoadFromFile(const char* p_file_path) override;
    virtual void LoadFromFile(const char* p_file_path, const uint16_t p_no_of_blocks) override;

    void Resize(const size_t p_length) override;
    void Reshape(const uint16_t p_no_of_blocks) override;

  };

}

#endif
