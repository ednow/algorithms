edges = ['AB', 'AC', 'AD', 'IL', 'MK', 'IM', 'IJ', 'ED', 'HG', 'HF', 'BG', 'DI']  # 边

parent = {chr(a): chr(a) for a in range(ord('A'), ord('M') + 1)}


def union(a, b):
    parent[find(a)] = find(b)


def find(a):
    if parent[a] != a:
        parent[a] = find(parent[a])
    return parent[a]


for edge in edges:
    union(edge[0], edge[1])

if __name__ == '__main__':
    print(parent)
