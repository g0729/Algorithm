#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> v) {
    vector<int> answer(v.size());
    
    stack<int>st;
    for(int i =v.size()-1;i>=0;i--){
        if(st.empty()){
            st.push(v[i]);
            answer[i]=-1;
        }
        else{
            if(v[i]>=st.top()){
                while(!st.empty() &&v[i]>=st.top())
                    st.pop();
                if(st.empty()){
                    answer[i]=-1;
                }
                else{
                    answer[i]=st.top();
                }
                st.push(v[i]);
            }
            else{
                answer[i]=st.top();
                st.push(v[i]);
            }
        }
    }
    return answer;
}