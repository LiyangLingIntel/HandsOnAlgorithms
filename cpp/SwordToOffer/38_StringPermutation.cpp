
// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
// 输入描述:
// 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        Permutation(res, str, 0);
        sort(res.begin(), res.end());
        return res;
    }
    
    void Permutation(vector<string> &res, string str, int begin) {
        if(begin==str.size()-1)
            res.push_back(str);
        for(int i=begin; i<str.size(); i++) {
            if(i!=begin && str[i]==str[begin]) //有重复字符时，跳过
                continue;
            swap(str[i], str[begin]);
            Permutation(res, str, begin+1);
            swap(str[i], str[begin]);
        }
    }
};