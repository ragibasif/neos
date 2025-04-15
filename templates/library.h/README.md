# 🦄 DEFAULT

DEFAULT is a single-header C library that [brief description of what your program does]. All the code is contained in `DEFAULT.h` file making it easy to distribute and deploy.

It's written in standard C (C99) and uses GNU Make for building. The goal of this project is to [insert goal or motivation, e.g., build a simple CLI tool, implement data structures from scratch, etc.].


## 🛠️ Usage

Select exactly **one** C/C++ source file to define the specific macro to enable the function definitions.

```c
#define DEFAULT_IMPLEMENTATION
#include "DEFAULT.h"
```

To include the library in other source files, include the header file normally.

```c
#include "DEFAULT.h"
```

### 💻 Installation

Clone the repository.

```bash
git clone git@github.com:ragibasif/DEFAULT.git
```

Make sure you have `gcc` and `make` installed.

### 🔧 Build the project

```bash
make
```

### 🧹 Clean build files

```bash
make clean
```

### 🏃 Run the executable

```bash
./DEFAULT
```
