void funcionRotacion(int *apuntadorVectorEnteros, int tamanioVector, int valorK)
{
    int i = 0, j = 0, elementoInicialVec;
    while (i < valorK)
    {
        j = 0;
        elementoInicialVec = apuntadorVectorEnteros[0];
        while (j < tamanioVector)
        {
            if (j != tamanioVector - 1)
            {
                if (apuntadorVectorEnteros[j + 1] < 0)
                {
                    apuntadorVectorEnteros[j] <<= 1;
                    apuntadorVectorEnteros[j] |= 1;
                }
                else
                {
                    apuntadorVectorEnteros[j] <<= 1;
                }
            }
            else
            {
                if (elementoInicialVec < 0)
                {
                    apuntadorVectorEnteros[j] <<= 1;
                    apuntadorVectorEnteros[j] |= 1;
                }
                else
                {
                    apuntadorVectorEnteros[j] <<= 1;
                }
            }
            j += 1;
        }
        i += 1;
    }
}