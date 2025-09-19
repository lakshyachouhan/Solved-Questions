class Spreadsheet {
public:
    vector<vector<int>> v ;
    Spreadsheet(int rows) {
        
        v.resize(rows+1,vector<int>(28,0));
    }
    
    void setCell(string cell, int value) {
        
        int col = cell[0] - 'A' ;
        int row = stoi(cell.substr(1));

        v[row][col] = value ;
    }
    
    void resetCell(string cell) {
        
        int col = cell[0] - 'A' ;
        int row = stoi(cell.substr(1));

        v[row][col] = 0 ;
    }
    
    int getValue(string formula) {
        
        int val1 = 0, val2 = 0;
        int index = formula.find('+');

        // left operand
        string left = formula.substr(1, index - 1);
        if (isalpha(left[0])) {
            int col = left[0] - 'A';
            int row = stoi(left.substr(1));
            val1 = v[row][col];
        }
        
         else {
            val1 = stoi(left);
        }

        // right operand
        string right = formula.substr(index + 1);
        if (isalpha(right[0])) {
            int col = right[0] - 'A';
            int row = stoi(right.substr(1));
            val2 = v[row][col];
        } 
        
        else {
            val2 = stoi(right);
        }

        return val1 + val2 ;
    }

};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */