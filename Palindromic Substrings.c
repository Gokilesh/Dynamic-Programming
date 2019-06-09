Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Note:

The input string length won't exceed 1000.



https://leetcode.com/problems/palindromic-substrings/
--------------------------------------------------------------------------------------------------
 
 int countSubstrings(char * s){
    int length=strlen(s);
    int matrix[length][length];
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            matrix[i][j] = 0;
        }
    }
    int count=0;
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            int t = j-i;
            if(t >= 0)
            {                
                    int sum=0;
                    int start=j;
                    int end = t;
                    while((end<=start))
                    {
                        if(s[end]==s[start])
                        {
                            if(end==start)
                            {
                                sum = sum + 1;
                            }
                            else
                            {
                                sum = sum + 2;
                            }
                            end++;
                            start--;
                        }
                        else
                        {
                            if(matrix[t][j-1]>matrix[t+1][j])
                            {
                                sum = matrix[t][j-1];
                            }
                            else
                            {
                                sum = matrix[t+1][j];
                            }
                            break;
                        }  
                    }
                    matrix[t][j]=sum;
                    if(sum == i+1)
                    {   
                        count++;
                    }
             } 
        }  
    }
    return count;   
}
