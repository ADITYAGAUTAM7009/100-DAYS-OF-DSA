# Problem: Alien Dictionary using Topological Sort (Kahn's BFS)
# Name: Aditya Gautam

from collections import deque, defaultdict

class Solution:
    def findOrder(self, words):
        # Step 1: Initialize graph and indegree
        adj = defaultdict(set)
        indegree = {c: 0 for word in words for c in word}

        # Step 2: Build graph
        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i + 1]

            # Prefix invalid case
            if len(w1) > len(w2) and w1.startswith(w2):
                return ""

            # Find first mismatch
            for c1, c2 in zip(w1, w2):
                if c1 != c2:
                    if c2 not in adj[c1]:  # avoid duplicate edge
                        adj[c1].add(c2)
                        indegree[c2] += 1
                    break

        # Step 3: Kahn’s BFS
        queue = deque([c for c in indegree if indegree[c] == 0])
        topo = []

        while queue:
            node = queue.popleft()
            topo.append(node)

            for nei in adj[node]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    queue.append(nei)

        # Step 4: Cycle check
        if len(topo) != len(indegree):
            return ""

        return "".join(topo)