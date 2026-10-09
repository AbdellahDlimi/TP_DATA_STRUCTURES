# Data Structures in C (TP Data Structures)

A comprehensive collection of practical exercises and implementations of fundamental data structures and algorithms in C, including singly linked lists, doubly linked lists, stacks, polynomial arithmetic, maze pathfinding, and delimiter validation.

---

## 📚 Contents

| File | Description |
| :--- | :--- |
| `TP1.c` | **Singly Linked Lists**: Core operations including insertion (head/tail), deletion (first/last), searching, computing the mean value, and creating descending lists. |
| `TP2.c` | **Polynomial Arithmetic with Linked Lists**: Representation of polynomials using linked lists, sorted monomial insertion, addition, differentiation, reversal, and polynomial evaluation. |
| `TP3_labyrinthe.c` | **Stack & Maze Exploration**: Dynamic stack implementation applied to pathfinding and counting valid paths through a 2D maze matrix. |
| `TP4_verifivation .c` | **Delimiter & Parentheses Validator**: Stack-based syntax verification checking balanced parentheses, brackets, and braces `()`, `[]`, `{}` from a file with line and column reporting. |
| `exam.c` | **Linked List Algorithms (Exam Exercises)**: Merging sorted lists, equality verification, finding minimum values, frequency counting, and calculating averages. |
| `examen2.c` | **Doubly Linked Lists**: Doubly linked list implementation with head insertion, tail deletion, and conditional element pruning based on threshold values. |
| `try.c` | **C Pointers & Memory Basics**: Practical demonstration of pointer dereferencing, memory addresses, and pass-by-value vs. pass-by-reference. |
| `TP2-ListesChaînées.pdf` | Course & lab assignment document covering linked list specifications and problems. |
| `TP1.jpeg`, `TP3.jpeg`, `TP4.jpeg`, `TP_Labyrinthe.jpeg` | Lab diagrams, subject sheets, and maze problem visualizations. |

---

## 🛠️ Requirements

- **C Compiler**: GCC, Clang, or MSVC supporting C99 or later.
- **C Standard Library**: Standard libraries (`stdio.h`, `stdlib.h`, `math.h`, `stdbool.h`).
- *Note for Linux/macOS users*: When compiling files that include `math.h` (such as `TP2.c`), link the math library with `-lm`.

---

## 🚀 How to Run

Compile any of the C source files using `gcc`:

### 1. Compile

```bash
# Example: Compile TP1
gcc TP1.c -o tp1

# Example: Compile TP2 (linking math library)
gcc TP2.c -o tp2 -lm

# Example: Compile Maze solver
gcc TP3_labyrinthe.c -o labyrinthe

# Example: Compile Parentheses validator
gcc "TP4_verifivation .c" -o verifier
```

### 2. Run

On Linux / macOS:
```bash
./tp1
```

On Windows (Command Prompt / PowerShell):
```powershell
.\tp1.exe
```

---

## 👤 Author

**Abdellah Dlimi**
- GitHub: [@AbdellahDlimi](https://github.com/AbdellahDlimi)
