#include <iostream>
#include <cstring>
using namespace std;

int areAnagrams(char str1[100], char str2[100])
{

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2)
        return 0;
    int freq[26] = {0};
    for (int i = 0; i < len1; i++)
    {
        freq[str1[i] - 'a']++;
        freq[str2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
            return 0;
    }
    return 1;
}

int main()
{
    char str1[100] = "listen";
    char str2[100] = "silent";
    int result = areAnagrams(str1, str2);
    cout << result << endl;
    return 0;
}