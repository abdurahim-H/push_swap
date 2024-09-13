
<div align="center">
  
# 🧑‍💻 **push_swap**  
![Push Swap](https://img.shields.io/badge/Sorting-Algorithm-Blue?style=for-the-badge) ![Language](https://img.shields.io/badge/C-Language-orange?style=for-the-badge)

![Project Banner](https://i.imgur.com/qGImAuG.png)

</div>

A minimalistic yet challenging sorting algorithm project that pushes the limits of algorithmic thinking and stack manipulation. The goal of this project is to sort data on a stack with a limited set of operations. Let's dive into the details and understand how `push_swap` solves the sorting puzzle efficiently!

---

## 🚀 **Project Overview**  
![Project](https://img.shields.io/badge/Stack-Operations-blueviolet?style=flat-square)  
`push_swap` is a sorting project developed as part of the **42 School** curriculum. The challenge is to sort a stack of integers using two stacks (`A` and `B`) with only a limited number of operations allowed: **swap**, **push**, **rotate**, and **reverse rotate**.

The goal? To sort the data in as few operations as possible.  
But, that’s not all! The project is evaluated based on efficiency and the number of operations used, making it not only a sorting challenge but also an optimization challenge.

---

## 🛠 **Features**  
![Features](https://img.shields.io/badge/Features-Stack%20Sorting-brightgreen?style=flat-square)

- **Efficient Sorting Algorithms:**  
  Includes both **intro-sort** (a hybrid sorting algorithm) for large stacks and **specialized algorithms** for small stack sizes.

- **Two Stack Management:**  
  Perform sorting using operations that manipulate two stacks (`A` and `B`).

- **Checker Program:**  
  A `checker` program verifies the correctness of the sorting by comparing the operations executed on the stack.  
  ```bash
  ARG="4 67 3 87"; ./push_swap $ARG | ./checker_Mac $ARG
  ```
  The `checker` will return `OK` if sorting was correct and `KO` otherwise.

- **Memory Management:**  
  All dynamic memory is handled safely with functions to clean up after sorting is done.

---

## 🧠 **Algorithm Breakdown**  
![Algorithm](https://img.shields.io/badge/Algorithm%20Flow-Intuitive-ff69b4?style=flat-square)

| Stack Size | Sorting Strategy        |
|------------|-------------------------|
| 2 Numbers  | Simple swap (sa)         |
| 3 Numbers  | Optimized minimal swaps  |
| 4-5 Numbers| Hybrid strategy using `B`|
| Large Stack| Intro-sort algorithm     |

1. **Small Stack Sorting**:
   - Uses specific algorithms for stack sizes up to 5.
   - For 2 numbers: simple swap (`sa`), and for 3-5 numbers, hybrid approaches are used.

2. **Large Stack Sorting**:
   - **Intro-sort**: A hybrid algorithm that combines quicksort, heapsort, and insertion sort to handle larger stacks efficiently.

3. **Stack Operations**:
   - **sa / sb / ss**: Swap the first two elements of stack `A` or `B`.
   - **pa / pb**: Push the first element of stack `A` to stack `B` or vice versa.
   - **ra / rb / rr**: Rotate stack `A` or `B` upwards.
   - **rra / rrb / rrr**: Reverse rotate stack `A` or `B` downwards.

---

## 📂 **How to Compile and Run**  
![Compile](https://img.shields.io/badge/Build-Makefile%20System-lightgrey?style=flat-square)

### **Compilation**

To compile the `push_swap` program and the `checker`:

```bash
make
```

### **Running the program**

Sort a set of numbers:
```bash
ARG="4 3 2 1"; ./push_swap $ARG
```

Check if your solution is correct:
```bash
ARG="4 3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
```

### **Testing with Random Numbers**
You can generate random numbers and test the sorting:
```bash
ARG=$(seq 1 100 | sort -R | tr '\n' ' '); ./push_swap $ARG | ./checker_Mac $ARG
```

---

## 🧩 **Error Handling**  
![Error Handling](https://img.shields.io/badge/Error%20Management-Essential-red?style=flat-square)

The program gracefully exits and logs errors to a file `error_log.txt` for easier debugging. Invalid inputs, like duplicates or non-integer values, are caught before executing.

---

## 📈 **Performance Optimization**  
![Performance](https://img.shields.io/badge/Performance-Optimized-blue?style=flat-square)

The number of operations executed by the program is optimized. For smaller stacks, operations like `pb`, `ra`, and `rra` are used efficiently to minimize the operation count.

For larger stacks, the `intro-sort` algorithm ensures optimal performance with its hybrid nature.

---

## 🛡 **License**  
![License](https://img.shields.io/badge/License-GPLv3-yellow?style=flat-square)

This project is released under the **GPLv3 License**. See the [LICENSE](LICENSE) file for details.

---

## 🧑‍💻 **Contributions**  
![Contributions](https://img.shields.io/badge/Contributions-Welcome-brightgreen?style=flat-square)

Contributions, issues, and feature requests are welcome! Feel free to check the [issues page](https://github.com/abdurahim-H/push_swap/issues).

---

## 👨‍💻 **Author**  
![Author](https://img.shields.io/badge/Author-Abdurahim-blue?style=flat-square)

Developed by **Abdurahim** | [GitHub](https://github.com/abdurahim-H)

---

## 💡 **Inspiration**  
![Inspiration](https://img.shields.io/badge/Inspiration-42%20School-orange?style=flat-square)

This project was inspired by the curriculum at [42 School](https://www.42heilbronn.de/) and aims to sharpen algorithmic thinking and code optimization.

