# Orchestra Concert Mixing (میکس قطعات کنسرت ارکستر)

A greedy + heap solution in C++ for the Quera problem **"میکس قطعات کنسرت ارکستر"**
(Assignment 2 — Heap & Greedy Algorithms).

[English](#english) | [فارسی](#فارسی)

---

## English

### Problem
There are `n` audio tracks with lengths `a1, a2, ..., an` seconds. In each step you pick
exactly two tracks of lengths `A` and `B` and merge them:

- the cost of the step is `A + B` units of energy;
- the result is a new track of length `A + B`, which can be merged again later.

Repeat until a single track remains. Find the **minimum total energy** needed.
If `n = 1`, no merge is needed and the answer is `0`.

**Input**
- Line 1: integer `n` (`1 ≤ n ≤ 200 000`)
- Line 2: `n` integers `a1 ... an` (`1 ≤ ai ≤ 10^9`)

**Output**
- A single integer: the minimum total energy.

### Example
```
Input:
4
1 2 3 4

Output:
19
```
Merge `1+2=3` (cost 3), then `3+3=6` (cost 6), then `4+6=10` (cost 10). Total: `3 + 6 + 10 = 19`.

### Solution idea
Every merge "re-pays" the lengths of all tracks inside the merged track. So short tracks
should be merged early (they are paid for many times) and long tracks should be merged late.

This is exactly the **Huffman coding** strategy:

1. Put all track lengths in a **min-heap**.
2. While more than one track remains:
   - pop the two smallest tracks,
   - add their sum to the answer,
   - push the sum back into the heap.
3. Print the answer.

### Complexity
- Time: `O(n log n)`
- Memory: `O(n)`

The answer can be as large as about `2·10^14 · log n`, so `long long` is required.

### Build & run
```bash
g++ -O2 -std=c++17 -o main main.cpp
./main < input.txt
```
Or interactively:
```bash
echo "4
1 2 3 4" | ./main
```

---

## فارسی

### صورت مسئله
`n` قطعه صوتی با طول‌های `a1, a2, ..., an` ثانیه داریم. در هر مرحله دقیقاً دو قطعه با طول‌های
`A` و `B` را انتخاب و ادغام می‌کنیم:

- هزینه این مرحله `A + B` واحد انرژی است.
- خروجی یک قطعه جدید به طول `A + B` است که می‌تواند بعداً دوباره ادغام شود.

این کار را تا زمانی که یک قطعه باقی بماند ادامه می‌دهیم. کمینه مجموع انرژی مصرف‌شده را پیدا کنید.
اگر `n = 1` باشد، نیازی به ادغام نیست و پاسخ `0` است.

### ایده حل
هر ادغام، طول همه قطعه‌های داخل قطعه ادغام‌شده را دوباره هزینه می‌کند. بنابراین قطعه‌های کوتاه
باید زودتر و قطعه‌های بلند دیرتر ادغام شوند. این دقیقاً همان روش **کدگذاری هافمن** است:

1. همه طول‌ها را در یک **min-heap** می‌ریزیم.
2. تا وقتی بیش از یک قطعه مانده است، دو قطعه کوچک‌تر را برمی‌داریم، مجموعشان را به پاسخ اضافه
   می‌کنیم و مجموع را دوباره در heap قرار می‌دهیم.
3. پاسخ را چاپ می‌کنیم.

### پیچیدگی
- زمانی: `O(n log n)`
- حافظه: `O(n)`

برای جلوگیری از سرریز باید از `long long` استفاده کرد.

### کامپایل و اجرا
```bash
g++ -O2 -std=c++17 -o main main.cpp
./main < input.txt
```
