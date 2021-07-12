class Solution {
public:
    int ladderLength(string a, string b, vector<string>& wordList) {
        unordered_set<string> set;
        for(auto s : wordList){
            set.insert(s);
        }
        if(set.find(b) == set.end()){return 0;}
        int count = 2;
        queue<string> q;
        q.push(a);
        while(!q.empty()){
            int n = q.size();
            for(int x = 0; x<n; x++){
                string temp = q.front();
                q.pop();
                set.erase(temp);
                string ref = temp;
                for(int i = 0; i<temp.size(); i++){
                    for(int j = 0; j<26; j++){
                        temp[i] = 'a' + j;
                        if(set.find(temp) != set.end()){
                            q.push(temp);
                            if(temp == b){return count;}
                        }
                    }
                    temp[i] = ref[i];
                }
            }
            count++;
        }
        return 0;
    }
};