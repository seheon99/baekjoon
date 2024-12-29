#include <iostream>
#include <vector>
#include <cmath>

using number = long long;

static std::vector<number> inputs;
static std::vector<number> tree;

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = inputs[start];
    } else {
        init(node * 2 + 1, start, (start + end) / 2);
        init(node * 2 + 2, (start + end) / 2 + 1, end);
        tree[node] = std::min(tree[node * 2 + 1], tree[node * 2 + 2]);
    }
}

void init() {
    return init(0, 0, inputs.size() - 1);
}

number query(int from, int to, int node, int start, int end) {
    // <-> [ ] || [ ] <-> 
    if (to < start || end < from) {
        return 0;
    }
    
    // <-[ ]->
    if (from <= start && end <= to) {
        return tree[node];
    }

    // [ <-> ] 
    // <- [ -> ] || [ <- ] ->
    number left = query(from, to, node * 2 + 1, start, (start + end) / 2);
    number right = query(from, to, node * 2 + 2, (start + end) / 2 + 1, end);
    return left != 0 ? right != 0 ? std::min(left, right) : left : right;
}

number query(int from, int to) {
    return query(from, to, 0, 0, inputs.size() - 1);
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    inputs = std::vector<number>(n);
    tree = std::vector<number>(1 << ((int)ceil(log2(n)) + 1));

    for (auto& input : inputs) {
        std::cin >> input;
    }

    init();
    
    for (int i = 0; i < m; i++) {
        int from, to;
        std::cin >> from >> to;
        std::cout << query(from - 1, to - 1) << '\n';
    }

    return 0;
}