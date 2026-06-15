# Competitive Programming Roadmap for an Intermediate DSA Learner

## Background

Current situation:

- Intermediate DSA knowledge from interview preparation.
- Solving LeetCode regularly.
- Starting Competitive Programming through Codeforces.
- Following Striver's CP Sheet.
- Can commit approximately:
  - 1 LeetCode POTD daily
  - 1 Codeforces problem daily

---

# Mindset Shift: LeetCode vs Codeforces

The biggest adjustment is not learning new data structures.

It is changing the way you think.

## LeetCode focuses on:

- Known patterns
- Communication
- Clean code
- Standard algorithms

Examples:
- Sliding Window
- Binary Search
- Dynamic Programming
- Two Pointers

## Codeforces focuses on:

- Observations
- Mathematical reasoning
- Greedy insights
- Constructive algorithms
- Fast implementation

Many Codeforces problems are solved because of a clever observation rather than a complex algorithm.

---

# Problem Solving Framework

Whenever you encounter a new problem, follow this framework.

---

## Step 1: Ignore the Story

Most CP problems hide the actual problem behind a story.

Example:

Instead of reading:

> Alice and Bob are playing a game involving candies...

Translate immediately into:

- Input
- Output
- Constraints
- Allowed Operations

Ask:

- What is changing?
- What is fixed?
- What am I optimizing?

---

## Step 2: Check Constraints First

Before thinking about algorithms, determine what complexity is expected.

### Complexity Guide

| Constraint | Typical Complexity |
|------------|-------------------|
| n ≤ 20 | Brute Force / Bitmask |
| n ≤ 100 | O(n³) |
| n ≤ 1000 | O(n²) |
| n ≤ 2e5 | O(n log n) |
| n ≤ 1e6 | O(n) |

### Questions to Ask

- Can I afford nested loops?
- Is sorting allowed?
- Do I need linear time?

The constraints often reveal the intended solution.

---

## Step 3: Simulate Examples Manually

Take the sample input.

Do not code yet.

Work through the process by hand.

Ask:

- What changes?
- What remains constant?
- What patterns appear?

Many Codeforces solutions emerge from manual simulation.

---

## Step 4: Search for Observations Before Patterns

A common mistake:

LeetCode mindset:

> Is this Sliding Window?

> Is this DP?

Codeforces mindset:

> What property always holds?

Look for:

### Common Observations

- Parity (odd/even)
- Frequency counts
- Sorting effects
- Prefix sums
- GCD relationships
- Invariants
- Monotonicity
- Symmetry

The observation usually comes first.

The data structure comes second.

---

## Step 5: Derive the Solution Before Coding

Before writing code, be able to explain:

### Why it works

What observation makes it correct?

### Why it is fast enough

What is the time complexity?

If you cannot explain both in a few sentences, continue thinking.

---

# What To Do When Stuck

---

## First 20 Minutes

Try solving independently.

Do:

- Draw examples
- Write observations
- Test ideas

Avoid opening the editorial immediately.

---

## Next 10 Minutes

Look only for hints.

Possible hints:

- Greedy
- Binary Search
- Prefix Sums
- Math
- Graph

Avoid reading the full solution.

---

## After 30 Minutes

Read the editorial.

Important:

Do not consider this failure.

The goal is:

- Learn patterns
- Learn observations
- Build intuition

---

# How To Read Editorials Correctly

Bad approach:

1. Open editorial
2. Read code
3. Copy solution

Good approach:

### Step 1

Read the observation.

### Step 2

Understand the proof.

### Step 3

Understand complexity.

### Step 4

Close the editorial.

### Step 5

Implement from scratch.

This is where most learning occurs.

---

# Building Pattern Recognition

Maintain a CP notebook.

For every solved problem, write:

---

## Template

### Problem

CF Round #XXX Problem B

### Key Observation

Example:

Only parity matters.

### Technique Used

Example:

Frequency counting.

### Signal

Example:

Whenever operations preserve parity,
consider separating odd and even numbers.

### Complexity

O(n)

---

Over time this becomes your personal pattern library.

Much more valuable than memorizing solutions.

---

# Daily Practice Plan

Since you:

- Have a full-time job
- Solve LeetCode POTD
- Follow Striver CP Sheet

A sustainable schedule is more important than an aggressive schedule.

---

## LeetCode POTD

Time:

20–30 minutes

Goal:

Maintain interview readiness.

---

## Codeforces Problem

Time:

45–60 minutes

Recommended breakdown:

### 20 Minutes

Independent attempt.

### 10 Minutes

Hints or editorial if needed.

### 20 Minutes

Re-implementation.

### 10 Minutes

Write notes.

---

# Rating Progression Roadmap

---

## Phase 1: 800–1000

Goal:

Become comfortable with contest thinking.

Focus:

- Implementation
- Basic observations
- Easy greedy

---

## Phase 2: 1000–1200

Goal:

Strengthen fundamentals.

Focus:

- Constructive algorithms
- Frequency counting
- Sorting observations

---

## Phase 3: 1200–1400

Goal:

Develop pattern recognition.

Focus:

- Prefix sums
- Binary search
- Two pointers
- Basic mathematics

---

## Phase 4: 1400–1600

Goal:

Become a strong problem solver.

Focus:

- Greedy proofs
- Advanced observations
- Combined techniques

---

# Contest Strategy

Practice alone is not enough.

Participate in at least one Codeforces contest every week.

Even if you solve only Problem A and Problem B.

Contests teach:

- Reading speed
- Time management
- Debugging under pressure
- Ranking psychology
- Stress management

Skills that normal practice cannot develop.

---

# Golden Rules

1. Read constraints before solving.
2. Simulate examples manually.
3. Search for observations before algorithms.
4. Give yourself 20 minutes before opening hints.
5. Implement editorials from scratch.
6. Maintain a pattern notebook.
7. Focus on consistency, not volume.
8. Participate in weekly contests.
9. Learn one idea per problem.
10. Trust long-term accumulation.

---

# Long-Term Goal

Do not aim to solve every problem.

Aim to become the type of programmer who can discover observations quickly.

That is the core skill Competitive Programming develops.
