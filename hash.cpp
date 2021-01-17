#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    vector<int> p_code, c_code; 
    string answer = "";
    vector<string>::iterator finder;

    for (vector<string>::iterator iter = completion.begin(); iter != completion.end(); ++iter) {

        finder = find(participant.begin(), participant.end(), *iter);
        if (finder != participant.end())
        {
            participant.erase(finder);
        }
    }
    
    answer = participant[0];
    return answer;
}

int main() {
    vector<string> p_vector = { "leo","kiki","eden" };
    vector<string> c_vector = { "eden", "kiki" };

    vector<string> p2_vector = { "marina", "josipa", "nikola", "vinko", "filipa" };
    vector<string> c2_vector = { "josipa", "filipa", "marina", "nikola" };


    vector<string> p3_vector = { "mislav", "stanko", "mislav", "ana" };
    vector<string> c3_vector = { "stanko","ana","mislav" };

    cout << solution(p_vector, c_vector) << endl;
    cout << solution(p2_vector, c2_vector) << endl;
    cout << solution(p3_vector, c3_vector) << endl;
    return 0;
}