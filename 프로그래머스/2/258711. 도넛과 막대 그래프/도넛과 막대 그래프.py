def solution(edges):
    n_node = max(max(edge) for edge in edges)
    
    indegrees = [0 for _ in range(n_node + 1)]
    outdegrees = [0 for _ in range(n_node + 1)]
    next_nodes = [[] for _ in range(n_node + 1)]
    
    for start, end in edges:
        outdegrees[start] += 1
        indegrees[end] += 1
        next_nodes[start].append(end)
    
    generated_node = 0
    for i in range(1, n_node + 1):
        if indegrees[i] == 0 and outdegrees[i] >= 2:
            generated_node = i
            break
    
    count_donut, count_stick, count_eight = 0, 0, 0
    for start_point in next_nodes[generated_node]:
        indegrees[start_point] -= 1
        is_donut = False
        is_stick = False
        is_eight = False
        queue = [start_point]
        while True:
            point = queue.pop(0)
            if outdegrees[point] == 0:
                is_stick = True
                break
            if indegrees[point] == 2 and outdegrees[point] == 2:
                is_eight = True
                break
            if point == start_point:
                if is_donut:
                    break
                else:
                    is_donut = True
            queue.append(*next_nodes[point])
        if is_eight:
            count_eight += 1
        elif is_stick:
            count_stick += 1
        elif is_donut:
            count_donut += 1
        
    answer = [generated_node, count_donut, count_stick, count_eight]
    return answer