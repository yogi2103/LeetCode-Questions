class Solution {
public:
    
    int maxScoreWordsHelper(vector<string>& words, int* freq, vector<int>& score,int index) {
        
        if(index==words.size()){
            return 0;
        }
        
        //call for no
        int sno=0 + maxScoreWordsHelper(words,freq,score,index+1);
        //include yes
        int sword=0;
        string word=words[index];
        bool flag=true;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(freq[ch-'a']==0){
                flag=false;
            }
            freq[ch-'a']--;
            sword+=score[ch-'a'];
        }
        
        int syes=0;
        if(flag){
            syes=sword+maxScoreWordsHelper(words,freq,score,index+1);
        }
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            freq[ch-'a']++;
        }
        
        return max(sno,syes);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        //making the frequency array
        int* freq=new int[26];
        for(int i=0;i<26;i++){
            freq[i]=0;
        }
        for(int i=0;i<letters.size();i++){
            freq[letters[i]-'a']++;
        }
        return maxScoreWordsHelper(words,freq,score,0);
    }
};
