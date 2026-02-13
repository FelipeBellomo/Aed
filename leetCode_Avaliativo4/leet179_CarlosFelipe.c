// Carlos Felipe Pereira Bellomo - M2

int concatena(int a, int b)
{
    char s1[22], s2[22];
    sprintf(s1, "%d%d", a, b);
    sprintf(s2, "%d%d", b, a);
    return strcmp(s1, s2) > 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int v[], int inicio, int final)
{

    int pivo = v[inicio + (final - inicio) / 2];
    int i = inicio - 1;
    int j = final + 1;

    while (1)
    {
        do
        {
            i++;
        } while (concatena(v[i], pivo));

        do
        {
            j--;
        } while (concatena(pivo, v[j]));

        if (i >= j)
            return j;
        swap(&v[i], &v[j]);
    }
}

void quickSort(int v[], int inicio, int fim)
{
    if (inicio < fim)
    {

        int p = particionar(v, inicio, fim);
        quickSort(v, inicio, p);
        quickSort(v, p + 1, fim);
    }
}

char *largestNumber(int *nums, int numsSize)
{
    if (numsSize == 0)
        return "";

    quickSort(nums, 0, numsSize - 1);

    if (nums[0] == 0)
    {
        char *zero = malloc(2);
        strcpy(zero, "0");
        return zero;
    }

    char *resultado = malloc(numsSize * 12 * sizeof(char));
    resultado[0] = '\0';
    char temp[12];

    for (int i = 0; i < numsSize; i++)
    {
        sprintf(temp, "%d", nums[i]);
        strcat(resultado, temp);
    }

    return resultado;
}