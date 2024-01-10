class Solution {

    int checkLetterRepetition(int charTab[])
    {
        int LetterRepetition = 0;

        for (int i = 0; i < 26; i++) 
        {         
            if(charTab[i] > 0)
            {
             LetterRepetition++;   
            }
        } 
        return LetterRepetition;
    }

    void PrepareLetterHistogram(string& word, int charTab[])
    {
        // Stores length of the string 
        int len = word.length(); 

        for (int i = 0; i < len; i++) 
        {         

            const int x = word[i] - 97; // x - offset 
            charTab[x]++;
        } 
    }

public:

    bool isItPossible(string word1, string word2) 
    {
    int charTab1[26] = {0}; 
    int charTab2[26] = {0};

    PrepareLetterHistogram(word1, charTab1);
    PrepareLetterHistogram(word2, charTab2);

    for (int i = 0; i < 26; i++) 
    {
        for (int j = 0; j < 26; j++) 
        {
            if((charTab1[i] > 0) && (charTab2[j] > 0))
            {
                // swap opperation
                //change in index i 
                charTab1[i]--;
                charTab2[i]++;
                //change in index j
                charTab2[j]--;
                charTab1[j]++;

                // check the number of letter repetition
                const int conut1 = checkLetterRepetition(charTab1);
                const int conut2 = checkLetterRepetition(charTab2);

                //check if equel
                if(conut1 == conut2)
                {
                    return true;
                }

                // revert the changes 
                // change in index i 
                charTab1[i]++;
                charTab2[i]--;
                // change in index j
                charTab2[j]++;
                charTab1[j]--;
            }
        }

        }
        return false;
    }
};
