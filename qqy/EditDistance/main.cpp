#include<iostream>
#include<algorithm>
using namespace std;

class Solution {

    public:

        int minDistance(string word1, string word2) {

            int **dp = createMatrix(word1.size()+1, word2.size()+1);



            //init matrix

            for(int i=0; i<=word1.size();i++){

                dp[i][0] = i;

                dp[0][i] = i;

            }



            //perform dp

            for(int i=1; i<=word1.size();i++){

                for(int j=1;j<=word2.size();j++){

                    dp[i][j] = 

                        dp[i][j-1] + 1 < dp[i-1][j] + 1 ? 

                        min(dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1), dp[i][j-1] + 1) :

                        min(dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1), dp[i-1][j] + 1);

                }

            }



            return dp[word1.size()][word2.size()];

        }

    private:

        int** createMatrix(int sizeX, int sizeY){

            int **res = new int*[sizeX];

            for(int i=0; i<sizeX; i++){

                res[i] = new int[sizeY];

                //init all cell to be -1



                for(int j=0;j<sizeY;j++){

                    res[i][j] = -1;

                }

            }

            return res;

        }

};


int main()
{

    Solution s;
    cout<< s.minDistance("pneumonoultramicroscopicsilicovolcanoconiosis","ultramicroscopic") << endl;
    cout<< s.minDistance("abc","cba") << endl;
}
