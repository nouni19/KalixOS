# KalixOS

Kalix is an x86_64 OS (work in progress)
I'm rewritting old kalix code from scratch, because of the many mistakes I did


## Features

#### Part 1: Kernel

* [x] Booting using Limine
* [x] Graphics driver using Limine's frame buffer
* [ ] Page allocator
* [ ] Kmalloc
* [ ] Interrupts
* [ ] Scheduling
* [ ] SMP
* [ ] VFS
* [ ] FAT32

#### Part 2: Userspace

* [ ] System calls
* [ ] Standard C library and cross-compiler
* [ ] GUI

## Some details

#### Naming convention

Variable names are written using snake_case, and function names are written using camelCase

#### Physical memory allocation

I use a linked list for most of the memory, and an array for the rest for some special cases
