class Solution {
public:
    vector<string> temp;
    vector<string> generateParenthesis(int n) {
        //your code goes here

        generate("", 0, 0,n);
        return temp;
        
        
    }

    void generate(string currStr, int open, int close, int n){
        //base condtion
        if(open+close == 2*n){
            temp.push_back(currStr);
            return ;

        }
        if(open<n){
            generate(currStr+"(", open+1, close, n);
        }
        if(close<open){
            generate(currStr+")", open, close+1, n);
        }
    }
};
