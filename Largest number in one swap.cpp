class Solution {
  public:
    string largestSwap(string &s) {
        // code here
       int n = s.size();
    vector<int> last(10, -1);

        // store last occurrence
        for(int i = 0; i < n; i++){
            last[s[i] - '0'] = i;
        }

        // traverse string
        for(int i = 0; i < n; i++){

            for(char c = '9'; c > s[i]; c--){

                int idx = last[c - '0'];

                if(idx > i){
                    swap(s[i], s[idx]);
                    return s;
                }
            }
        }

        return s;
    }
};
