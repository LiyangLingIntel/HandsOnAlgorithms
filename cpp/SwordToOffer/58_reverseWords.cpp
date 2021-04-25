// 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I
// am a student. "，则输出"student. a am I"。

class Solution {
public:
  string reverseWords(string s) {
    stack<char> word;
    string res = "";
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] != ' ') {
        word.push(s[i]);
      }
      if (s[i] == ' ' || i == 0) {
        bool flag = false;
        while (word.empty() == false) {
          res.push_back(word.top());
          word.pop();
          flag = true;
        }
        if (flag) {
          res += " ";
        }
      }
    }
    return res.substr(0, res.size() - 1);
  }
}
