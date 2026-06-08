*This activity has been created as part of the 42 curriculum by ctu, ahalifa.*

# Description  
**Push_swap** is an algorithmic project. The goal is to sort a list of integers stored in a stack called `a`, using a second auxiliary stack `b` and a restricted set of operations, while minimizing the total number of operations generated.

The program implements **four distinct sorting strategies** adapted to the push_swap operation model, and selects the most appropriate one depending on the input — either automatically (adaptive mode, based on a disorder metric) or manually via a flag.

# Instructions  
```bash
make
```

This compiles all source files and generates the `push_swap` executable.

```bash
./push_swap [--simple | --medium | --complex | --adaptive] <integers...>
```

| Flag | Strategy | Complexity |
|---|---|---|
| `--simple` | Selection sort | O(n²) |
| `--medium` | Chunk-based sort | O(n√n) |
| `--complex` | Radix sort | O(n log n) |
| `--adaptive` | Auto-select based on disorder | O(n) / O(n√n) / O(n log n) |

> If no flag is given, `--adaptive` is used by default.

Add `--bench` to display performance metrics (sent to `stderr`):

```bash
./push_swap --bench 4 67 3 87 23
```

Output example:
```
[bench] disorder:   40.00%
[bench] strategy:   Adaptive / O(n√n)
[bench] total_ops:  13
[bench] sa: 0  sb: 0  ss: 0  pa: 5  pb: 5
[bench] ra: 2  rb: 1  rr: 0  rra: 0  rrb: 0  rrr: 0
```

The program prints `Error` to `stderr` and exits in the following cases:
- A non-integer argument is passed
- Duplicate values are present
- Duplicate flags are present

# Resources  

- [Bitwise operations in C — GeeksforGeeks](https://www.geeksforgeeks.org/c/bitwise-operators-in-c-cpp/)
- [Bitwise operations in C — Wikipedia](https://en.wikipedia.org/wiki/Bitwise_operations_in_C)
- [Selection Sort — GeeksforGeeks](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)
- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Radix Sort — GeeksforGeeks](https://www.geeksforgeeks.org/dsa/radix-sort/)
- [Push_swap visualizer](https://push-swap42-visualizer.vercel.app/)  
AI was used to make the README

## Algorithms
All the types of algorithms given in the subject were researched upon before we settled on the ones we thought we could aprehend based on our current skills. 

### Simple algorithm — O(n²)

**Approach:** Selection sort adapted to the push_swap model.

The algorithm repeatedly finds the minimum element in stack `a`, rotates it to the top using `ra` or `rra` (whichever is shorter), then pushes it to `b`. Once all elements are in `b` in descending order, it pushes them back to `a` with `pa`.

### Medium algorithm — O(n√n)

**Approach:** Chunk-based sorting.

The sorted rank of each element is precomputed (coordinate compression). The n elements are divided into √n chunks of size √n. Elements are pushed to `b` chunk by chunk, always rotating `a` to find the next element belonging to the current chunk. Inside `b`, elements are maintained in a roughly sorted order. Finally, elements are pushed back from `b` to `a` by repeatedly extracting the maximum.

### Complex algorithm — O(n log n)

**Approach:** LSD Radix sort adapted to two stacks using bitwise operations.

Elements are first coordinate-compressed to indices `[0, n-1]`. The algorithm then sorts by bit, from the least significant bit to the most significant bit. For each bit position:
- Elements with a `0` bit are pushed to `b` (`pb`).
- Elements with a `1` bit are rotated to the bottom of `a` (`ra`).
- Then all elements are pushed back from `b` to `a` (`pa`).

After processing all `log₂(n)` bits, stack `a` is sorted.


# Contribution  

| Contributor | Responsibilities |
|---|---|
| **ctu** | Disorder metric, Simple sort, Complex sort, Operations, Initialisation, Benchmark |
| **ahalifa** | Parsing, Simple sort, Medium sort, Operations, Initialisation, Protections |