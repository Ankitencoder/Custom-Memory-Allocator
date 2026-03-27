# 🚀 Custom Memory Allocator (C++)

---

## 📌 1. Overview

This project implements a **custom memory allocator** similar to `malloc` and `free`.

It provides a deeper understanding of:

* Heap memory management
* Pointer arithmetic
* Fragmentation and allocation strategies

---

## 🎯 2. Goals

* Understand how memory allocation works internally
* Implement a **free list allocator**
* Explore **fragmentation issues**
* Learn low-level memory control

---

## ⚙️ 3. Key Features

### 🧠 Custom Allocation

* Implements `allocate()` similar to `malloc`
* Uses `sbrk()` to request memory from OS

---

### 🔁 Free List Management

* Maintains linked list of memory blocks
* Reuses freed blocks

---

### ✂️ Block Splitting

* Large blocks are split into smaller ones
* Reduces wasted memory

---

### 🔗 Coalescing

* Adjacent free blocks are merged
* Reduces fragmentation

---

### 🧪 Debugging

* Visualizes memory layout

---

## 🏗️ 4. Architecture

Heap Memory
↓
Linked List of Blocks
↓
Allocation / Deallocation

---

## 🔄 5. Step-by-Step Execution Flow

### Step 1: Allocation Request

```cpp
alloc.allocate(size);
```

---

### Step 2: Find Free Block

* Search free list
* If found → reuse

---

### Step 3: Request Memory (if needed)

```cpp
sbrk()
```

* Expands heap
* Creates new block

---

### Step 4: Split Block

* If block is larger than needed
* Split into:

  * Allocated block
  * Remaining free block

---

### Step 5: Return Pointer

* Return usable memory (after metadata)

---

### Step 6: Deallocation

```cpp
alloc.deallocate(ptr);
```

---

### Step 7: Mark Block Free

* Update free flag

---

### Step 8: Coalescing

* Merge adjacent free blocks
* Prevent fragmentation

---

## ⚡ 6. Memory Design

| Component    | Purpose        |
| ------------ | -------------- |
| Block struct | Metadata       |
| Free list    | Track memory   |
| sbrk()       | Heap expansion |

---

## 📊 7. Trade-offs

| Strategy   | Pros                  | Cons              |
| ---------- | --------------------- | ----------------- |
| Free List  | Simple                | Fragmentation     |
| Splitting  | Efficient usage       | Overhead          |
| Coalescing | Reduces fragmentation | Extra computation |

---

## 🛠️ 8. How to Run

### Build

```bash
make
```

### Run

```bash
./allocator
```

---

## 🧪 9. Example Output

```
Memory allocated and freed successfully
```

---

## 🧠 10. Key Learnings

* Memory layout and heap internals
* Pointer arithmetic
* Fragmentation handling
* Low-level system programming
* Debugging memory issues

---

## 🚀 11. Future Improvements

* Memory alignment (8/16 bytes)
* Thread-safe allocator
* Slab allocator
* Buddy allocator system
* Garbage collection concepts

---

## 🔗 12. GitHub
https://github.com/Ankitencoder/Custom-Memory-Allocator

