#include <iostream>
#include <cstring>

const int N_MAX = 1001;
const int M_MAX = 10000;
const int D_MAX = 100;
const int D_INF = M_MAX * D_MAX + 1;

static unsigned int distances[N_MAX][N_MAX];
static int N, M, X;

int get_next(unsigned int *distances, bool *visited)
{
    unsigned int min_distance = UINT32_MAX;
    int next = -1;

    for (int x = 1; x <= N; x++)
    {
        if (visited[x])
        {
            continue;
        }

        if (distances[x] < min_distance)
        {
            min_distance = distances[x];
            next = x;
        }
    }
    return next;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M >> X;
    for (int from = 1; from <= N; from++)
    {
        for (int to = 1; to <= N; to++)
        {
            distances[from][to] = from == to ? 0 : D_INF;
        }
    }
    for (int i = 0; i < M; i++)
    {
        int from, to, distance;
        std::cin >> from >> to >> distance;
        distances[from][to] = distance;
    }

    unsigned int inbound_distances[N_MAX];
    unsigned int outbound_distances[N_MAX];
    for (int i = 1; i <= N; i++)
    {
        inbound_distances[i] = distances[i][X];
        outbound_distances[i] = distances[X][i];
    }

    {
        int next;
        bool visited[N_MAX] = {false};

        visited[X] = true;
        while ((next = get_next(inbound_distances, visited)) != -1)
        {
            visited[next] = true;
            for (int i = 1; i <= N; i++)
            {
                inbound_distances[i] = std::min(inbound_distances[i],
                                                distances[i][next] + inbound_distances[next]);
            }
        }
    }
    {
        int next;
        bool visited[N_MAX] = {false};

        visited[X] = true;
        while ((next = get_next(outbound_distances, visited)) != -1)
        {
            visited[next] = true;
            for (int i = 1; i <= N; i++)
            {
                outbound_distances[i] = std::min(outbound_distances[i],
                                                 outbound_distances[next] + distances[next][i]);
            }
        }
    }

    unsigned int result = 0;
    for (int i = 1; i <= N; i++)
    {
        result = std::max(result, inbound_distances[i] + outbound_distances[i]);
    }
    std::cout << result;
    return 0;
}