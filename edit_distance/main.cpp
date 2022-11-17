#include<vector>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Solution {
public:
    int minDistance(float* word1, float* word2) {
        int m = sizeof(word1)/sizeof(word1[0]), n = sizeof(word2)/sizeof(word2[0]);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    if(argc != 3)
    {
        cerr << endl << "Usage: ./ED path_to_graph1 path_to_graph2" << endl;
        return 1;
    }
    // read argv file
    ifstream in1(argv[1]);
    ifstream in2(argv[2]);
    float *graph1, *graph2;
    // read file to graph1
    int num1 = 0;
    while(!in1.eof())
    {
        in1 >> graph1[num1];
        num1++;
    }
    num1 = 0;
    while (!in2.eof())
    {
        in2 >> graph2[num1];
        num1++;
    }
    int minDistance = solution.minDistance(graph1, graph2);
    return 0;
}
