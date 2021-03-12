// File Name:     simple_heap.hpp
// Author:        Arash Fatehi
// Date:          27th Feb 2021
// Description:   Typed linear heap memory class
// ---------------------
// Detail Description:
// An implementation of LinearMemory abstract class, allocates using "new" and deallocates
// using "delete" operations, it needs a type as template argument in addition to it`s length
// in order to allocate enough memory.
// =====================
// [LinearHeapMemory]: Create an object without allocating memory for m_memory
// -----
// [LinearHeapMemory(p_file_path)]: Load the content of memory from a binary file
// -----
// [LinearHeapMemory(p_length)]: Allocate memory for an array with length of p_length of type T
// -----
// [Allocate]: Alocates p_length * sizeof(T) bytes of memory to m_memory
// -----
// [Deallocate]: Frees the allocated memory if allocated
// -----
// [LoadFromFile(p_file_path)]: Load content of memory from a binary file
// -----
// [Resize(p_length)]: Allocates new memory, copies the content and deallocates old one
// It is a heavy operation, should be avoided unless necessary or harmless
// -----
// [operator []]: Returns the p_index`th item of the array

#ifndef MEMORY_LINEAR_HEAP_HPP
#define MEMORY_LINEAR_HEAP_HPP

#include "memory/linear/linear.hpp"
#include "memory/linear/linear.cpp"

#include <cstddef>
#include <cstdint>

namespace mnt {
  template <typename T>
  class LinearHeapMemory : public LinearMemory<T>
  {
  public:
    LinearHeapMemory(Allocator* p_allocator = nullptr) noexcept;
    LinearHeapMemory(const char* p_file_path, Allocator* p_allocator = nullptr);
    LinearHeapMemory(const size_t p_length, Allocator* p_allocator = nullptr);
    ~LinearHeapMemory() noexcept;

    void LoadFromFile(const char* p_file_path) override;
    void Resize(const size_t p_length) override;

    T& operator [] (const size_t p_index) noexcept override;
    const T& operator [] (const size_t p_index) const noexcept override;

  protected:
    void Allocate(const size_t p_length);
    void Deallocate() noexcept;

  };
}

#endif

