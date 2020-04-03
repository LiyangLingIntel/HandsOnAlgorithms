// Given an expression such as expression = "e + 8 - a + 5" and an evaluation map such as {"e": 1} (given in terms of evalvars = ["e"] and evalints = [1]), return a list of tokens representing the simplified expression, such as ["-1*a","14"]

// An expression alternates chunks and symbols, with a space separating each chunk and symbol.
// A chunk is either an expression in parentheses, a variable, or a non-negative integer.
// A variable is a string of lowercase letters (not including digits.) Note that variables can be multiple letters, and note that variables never have a leading coefficient or unary operator like "2x" or "-x".
// Expressions are evaluated in the usual order: brackets first, then multiplication, then addition and subtraction. For example, expression = "1 + 2 * 3" has an answer of ["7"].

// The format of the output is as follows:

// For each term of free variables with non-zero coefficient, we write the free variables within a term in sorted order lexicographically. For example, we would never write a term like "b*a*c", only "a*b*c".
// Terms have degree equal to the number of free variables being multiplied, counting multiplicity. (For example, "a*a*b*c" has degree 4.) We write the largest degree terms of our answer first, breaking ties by lexicographic order ignoring the leading coefficient of the term.
// The leading coefficient of the term is placed directly to the left with an asterisk separating it from the variables (if they exist.)  A leading coefficient of 1 is still printed.
// An example of a well formatted answer is ["-2*a*a*a", "3*a*a*b", "3*b*b", "4*a", "5*c", "-6"] 
// Terms (including constant terms) with coefficient 0 are not included.  For example, an expression of "0" has an output of [].
// Examples:

// Input: expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
// Output: ["-1*a","14"]

// Input: expression = "e - 8 + temperature - pressure",
// evalvars = ["e", "temperature"], evalints = [1, 12]
// Output: ["-1*pressure","5"]

// Input: expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
// Output: ["1*e*e","-64"]

// Input: expression = "7 - 7", evalvars = [], evalints = []
// Output: []

// Input: expression = "a * b * c + b * a * c * 4", evalvars = [], evalints = []
// Output: ["5*a*b*c"]

// Input: expression = "((a - b) * (b - c) + (c - a)) * ((a - b) + (b - c) * (c - a))",
// evalvars = [], evalints = []
// Output: ["-1*a*a*b*b","2*a*a*b*c","-1*a*a*c*c","1*a*b*b*b","-1*a*b*b*c","-1*a*b*c*c","1*a*c*c*c","-1*b*b*b*c","2*b*b*c*c","-1*b*c*c*c","2*a*a*b","-2*a*a*c","-2*a*b*b","2*a*c*c","1*b*b*b","-1*b*b*c","1*b*c*c","-1*c*c*c","-1*a*a","1*a*b","1*a*c","-1*b*c"]
// Note:

// expression will have length in range [1, 250].
// evalvars, evalints will have equal lengths in range [0, 100].
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;


typedef pair<string, int> Term;
typedef map<string, int> Poly;
typedef unordered_map<string, int> Eval;

class Solution {
public:
    static vector<string> basicCalculatorIV(string expression,
                                            vector<string> &evalvars,
                                            vector<int> &evalints) {
        expression.erase(
                remove(expression.begin(), expression.end(), ' '),
                expression.end()
        );

        Eval evals;
        for (int i = 0; i < evalvars.size(); ++i)
            evals[evalvars[i]] = evalints[i];

        vector<string> res = clean(parse(expression, evals));

        return res;
    }

private:
    static bool compare(Term &a, Term &b) {
        string s1 = a.first, s2 = b.first;
        vector<string> left = split(s1, '*');
        vector<string> right = split(s2, '*');
        return left.size() > right.size() || (left.size() == right.size() && left < right);
    }

    static vector<string> clean(Poly term_map) {
        vector<Term> result_terms;
        for (auto term: term_map)
            result_terms.emplace_back(term);
        sort(result_terms.begin(), result_terms.end(), compare);

        vector<string> result_exp;
        for (auto term: result_terms) {
            if (term.second) {
                if (term.first.empty())
                    result_exp.emplace_back(to_string(term.second));
                else
                    result_exp.emplace_back(to_string(term.second) + '*' + term.first);
            }
        }
        return result_exp;
    }

    static vector<string> split(const string &s, char c) {
        vector<string> res;
        int i = 0, j = 0, n = s.length();
        while (j < n) {
            j = s.find(c, i);
            if (j == -1) j = n;
            res.emplace_back(s.substr(i, j - i));
            i = j + 1;
        }
        return res;
    }

    static Poly multip(const Poly &lhs, const Poly &rhs) {
        if (lhs.empty()) return rhs;
        if (rhs.empty()) return lhs;
        Poly res;
        for (auto &a: lhs) {
            for (auto &b: rhs) {
                auto vars = split(a.first, '*');
                for (auto &v: split(b.first, '*')) vars.emplace_back(v);
                sort(vars.begin(), vars.end());
                string var;
                for (auto &v: vars) var += v + '*';
                if (!var.empty()) var.pop_back();
                Term t = Term(var, a.second * b.second);
                res[t.first] += t.second;
            }
        }
        return res;
    }

    static Poly add(Poly &lhs, Poly &rhs, int sign) {
        for (auto &t: rhs)
            lhs[t.first] += sign * t.second;
        return lhs;
    }

    // replace eval vals to eval ints and break brackets
    static Poly parse(string &s, Eval &evals) {

        Poly prev, curr, res;
        char op = '+';
        s += '+';
        int n = s.length(), i = 0;
        while (i < n) {
            if (s[i] == '(') {
                int j = 0, cnt = 0;
                for (j = i; j < n; ++j) {
                    if (s[j] == '(') cnt += 1;
                    if (s[j] == ')') cnt -= 1;
                    if (cnt == 0) break;
                }
                string subs = s.substr(i + 1, j - i - 1);
                curr = parse(subs, evals);
                i = j + 1;
            } else if (isdigit(s[i]) || isalpha(s[i])) {
                int j = 0;
                bool is_number = true;
                // get the full expression of val or number
                for (j = i; j < n; ++j) {
                    if (isalpha(s[j])) is_number = false;
                    if (!isdigit(s[j]) && !isalpha(s[j]))
                        break;
                }
                string subs = s.substr(i, j - i);
                Term t("", 0);
                if (evals.count(subs)) {
                    t.first = "";
                    t.second = evals[subs];
                } else if (is_number) t.second = stoi(subs);
                else {
                    t.first = subs;
                    t.second = 1;
                }
                curr.insert(t);
                i = j;
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                switch (op) {
                    case '+':
                        prev = add(prev, curr, 1);
                        break;
                    case '-':
                        prev = add(prev, curr, -1);
                        break;
                    case '*':
                        prev = multip(prev, curr);
                        break;
                }
                if (s[i] == '+' || s[i] == '-' || i == n - 1) {
                    res = add(res, prev, 1);
                    prev.clear();
                }
                op = s[i++];
                curr.clear();
            }
        }
        return res;
    }
};