#include "StringReverser.h"


string server_side::StringReverser::solve(string problem) {
    string ans = "";
    for(int i = problem.length() - 1; i >= 0; i--) {
        ans += problem[i];
    }
    return ans;
}