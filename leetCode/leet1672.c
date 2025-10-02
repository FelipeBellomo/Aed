int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int result = 0;
    int total = 0;

    for(int i = 0; i < accountsSize;i++){
        total = 0;
        for(int j  = 0; j < *accountsColSize;j++){
            total = total + accounts[i][j];
        }

    if(total > result)
        result = total;
    }

    return result;
}