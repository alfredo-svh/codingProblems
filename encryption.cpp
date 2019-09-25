string encryption(string s) {
    string encrypted;
    int row, column;

    //deleting spaces in encrypted string
    for(unsigned i =0;i<s.size();i++){
        if(s[i]!= ' '){
            encrypted.push_back(s[i]);
        }
    }

    //getting row and column size
    row=floor(sqrt(encrypted.size()));
    column = ceil(sqrt(encrypted.size()));

    if(row*column <=encrypted.size())
        row++;

    //creating the grid
    vector<vector<char>> grid(row);

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(i*column+j<encrypted.size()){
                grid[i].push_back(encrypted[i*column+j]);
            }
            else
                grid[i].push_back(' ');

        }
    }

    //using the grid to create encrypted string
    encrypted = "";

    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            if(grid[j][i]!=' ')
                encrypted.push_back(grid[j][i]);
        }
        encrypted.push_back(' ');
    }


    return encrypted;
}
