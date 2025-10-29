Team Project Selection
By Ethan Andre Dalocanog

DSA
Categories:

Sets
You're managing a university project team with three departments:
   - Design
   - Programming
   - Marketing

Each department submitted a list of tools they want to use for the project. However, you can't use every tool — you need to decide which ones will actually be part of the final approved toolset.

Each tool is represented by a bit (1 = wants to use it, 0 = doesn't want it):
   - Index 0: Canva
   - Index 1: Figma
   - Index 2: GitHub
   - Index 3: Trello
   - Index 4: ChatGPT


Main Task:
Write a function called FindApprovedTools() that determines which tools will be officially approved, following these rules:
 
1. The Programming team's tools are mandatory — every approved tool must at least include everything Programming wants.
2. Tools that Design and Marketing both want are also automatically approved.
3. However, if Programming doesn't want a tool, and only Marketing wants it, that tool should NOT be approved. This means that Marketing-only choices are rejected.

This function should return a new SET representing all approved tools.


Implementation Rules:

You must use the provided Set Operations:
   - Union(A, B)
   - Intersection(A, B)
   - Difference(A, B)

Do NOT use loops or arithmetic to compute the logic directly inside FindApprovedTools().