# Sorting Algorithm Implementations and Big O Analysis in C 

<br>

## Overview

This repository contains educational materials and implementations related to sorting algorithms and Big O analysis. It was created as part of the [low level programming C course](https://github.com/AhmadYousif89/alx-low_level_programming.git) to help understanding various sorting algorithms, analyze their time complexities (Big O), and gain hands-on experience with implementing and comparing these algorithms.

<br>

## Table of Contents

1. [Getting Started](#getting-started)
2. [Sorting Algorithms](#sorting-algorithms)
3. [Big O Notation](#big-o-notation)
5. [Auther](#auther)

<br>


## Getting Started

- Start by cloning this repository by following these steps:

```sh
git clone https://github.com/AhmadYousif89/sorting_algorithms.git

cd sorting_algorithms
```
<br>

### Sorting Algorithms
<hr>

Sorting algorithms are methods used to arrange elements in a specific order, often in ascending or descending order.

This repository includes implementations of the following sorting algorithms:

- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort

<br>

### Big O Notation

<hr>

**What is Big O notation?**

In simple terms, Big O notation is a way to measure how the time or space complexity of an algorithm grows as the input size approaches infinity. It helps us understand the efficiency and performance of an algorithm in the worst-case scenario. It provide us with the upper bound on a function by which we can make sure that the function at hand will never grow faster than this upper bound.

We can determine the time complexity by examining the dominant term or the term with the fastest growth rate in a given function. Here are some common types of Big O notation:

| Big O Notation	| Description	| Efficiency	|
|:-----------------:|---------------|:------------:|
| O(1)			| Constant Time - Efficiency remains constant regardless of the input size.	| Excellent	|
| O(log n)		| Logarithmic Time - Efficiency grows logarithmically, common in algorithms that divide the problem into smaller subproblems. | Very Good	|
| O(n)			| Linear Time - Efficiency grows linearly, and for every additional element in the input, the algorithm takes a constant amount of time or space. | Good	|
| O(n log n)	| Linearithmic Time - Efficiency grows linearithmically. Common in efficient sorting algorithms like **merge sort** or **quicksort**, where the problem is repeatedly divided and solved. | Acceptable	|
| O(n^2)		| Quadratic Time - Efficiency grows quadratically. Common in algorithms with nested loops.	| Fair	|
| O(n^c)		| Polynomial Time - Efficiency grows polynomially, and that's when generally **c** is a constant greater than 1.	| Fair to Poor	|
| O(2^n)		| Exponential Time - Efficiency grows exponentially. Common in algorithms with recursive solutions that result in an exponential number of function calls.	| Poor	|
| O(n!)			| Factorial Time - Efficiency grows factorially. Common in algorithms that generate permutations.	| Very Poor	|
<br>

#### How can we measure the Big O of a given function?

As a way to measure Big O notations, we can say if a two positive constants exist `c` and `n0` such that `f₁(n) ≤ c⋅f₂(n)` for all `n ≥ n₀`, then we can say that `f₁(n) = O(f₂(n))`

**Meaning:**

It implies that for large enough input sizes (`n ≥ n0`), the growth of `f1(n)` is **bounded above** by the growth rate of `f2(n)` when multiplied by a constant.

Essentially meaning that `f1(n)` **will never grow significantly faster** than `f2(n)` as the input size `n` increases towards infinity.

**Example:**

Let's say we have this function: `f(n)` that simply returns `2n + 3` now how can we determine the Big O of this function?

to answer this question we need to simplify `f(n)` and to do that we need to consider another function `g(n)`

Let's choose `g(n) = n` why is that ? because `n` represents the dominant grows factor in `f(n) = 2n + 3` *(In Big O analysis, we are interested in capturing the most significant term that contributes to the growth rate as n (the input size) becomes large.)*

now we should ask if `f(n) = O(g(n))` or not.

according to the definition `f₁(n) ≤ c⋅f₂(n)` for all `n ≥ n₀` we need to plug-in our two functions into the equation

`f(n) ≤ c⋅g(n)`​

`2n + 3 ≤ c⋅n`

Let's choose `c = 3` or any bigger number because we need a number greater then `2n` to fit in the equation

so `2n + 3 ≤ 3n` which means `3 ≤ 3n - 2n` which translate into `3 ≤ n`

So now 3 represents the `n₀` of the equation and therefore we can say that `f(n) ≤ c⋅g(n)` for all `n values ≥ 3` when the constant `c = 3` and `n₀ = 3`.

In the end we can say that `f(n)` will grow as fast but not worst than `O(g(n))` and it will grow linearly in the worst case scenario because `O(f(n)) is O(n)`.

**Why it matters:**

Big O notation helps us understand the asymptotic behavior of algorithms, focusing on their performance trends for very large inputs. It doesn't tell us the exact execution time or whether algorithm A will always behave better than algorithm B for all input sizes, but it helps comparing different algorithms and identify which one scales better with input size increases towards infinity.

### Auther

[Ahmad Yousif](https://github.com/AhmadYousif89)
