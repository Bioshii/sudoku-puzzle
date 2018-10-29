void addGuess(row, col, value){
    if (!start[row][col]){
        board[row][col]=value;
    }
}
bool checkPuzzle(){
    int i,j,k,l,m,n;

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            for(k=j+1;k<9;k++){
            if (board[i][j]==board[i][k]||board[j][i]==board[k][i]){
                return false;
            }
        }
    }

    for(i=0;i<9;i+=3){
        for(j=0;j<9;j+=3){
            for(k=i;k<3;k++){
                for(l=j;l<3;l++){
                    for(m=k+1;m<3;m++){
                        for(n=l+1;n<3;n++){
                            if(board[k][l]==board[m][n]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}


int getValueIn(int row, int col){
    return board[row][col];
}

bool isFull(){
    int i, j;
    for(i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if (board[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

void reset(){
    return defaultBoard;
}

getAllowedValues(int row, int col){
    int old=board[row][col];
    int i;
    bool arr=bool[10];
    for(i=0;i<9;i++){
        board[row][col]=i;
        if(checkPuzzle){
            arr[i]=true;
        }else{
            arr[i]=false;
        }
    }
    return arr;
}

