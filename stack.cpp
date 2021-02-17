#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

const double EPS = 1e-12;

// Stack1 is implemented using primitive array
class Stack1 {
private:
    int top_idx = 0;
    int* array;

public:
    // constructor
    Stack1(int max_size)
    {
        array = new int[max_size];
    }

    // destructor
    ~Stack1()
    {
        delete[] array;
    }

    void push(int x)
    {
        array[++top_idx] = x;
    }
    bool isEmpty()
    {
        return top_idx == 0;
    }
    int top()
    {
        if (isEmpty()) {
            throw std::runtime_error("error!");
        }
        return array[top_idx];
    }
    bool pop()
    {
        if (isEmpty())
            return false;
        top_idx--;
        return true;
    }
};
// Stack2 is implemented using dynamic array (variable length array)
class Stack2 {
private:
    vector<int> data;

public:
    // insert an element into the stack
    void push(int x)
    {
        data.push_back(x);
    }

    // checks whether the stack is empty or not
    bool isEmpty()
    {
        return data.empty();
    }

    // Get the top item from the stack
    int top()
    {
        if (isEmpty())
            return -1;
        return data.back();
    }

    // Delete an element from the stack. Return true if the operation is successful
    bool pop()
    {
        if (isEmpty())
            return false;
        data.pop_back();
        return true;
    }
};

int main()
{
    Stack2 stack;
    stack.push(2);
    stack.push(5);
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    stack.pop();
    if (stack.isEmpty())
        cout << "empty now" << endl;

    return 0;
}