int numTrees(int n)
{

    int G[n + 1];

    G[0] = 1;
    G[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        G[i] = 0;
        for (int j = 1; j <= i; j++)
        {
            // G[j-1] são os nós à esquerda
            // G[i-j] são os nós à direita
            G[i] += G[j - 1] * G[i - j];
        }
    }

    return G[n];
}