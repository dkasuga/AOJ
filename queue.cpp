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
const int M = 1046527;

/*
AOJ 4.3
ラウンドロビンスケジューリングは，プロセスを格納（管理）するキューを用いてシミュレートできる．まず，初期状態のプロセスを順番にキューに入れる．次にキューが空になるまで，「先頭からプロセスを取り出し，最大でもクオンタムだけ処理を行い，まだ必要な処理（時間）が残っている場合は再びキューに追加する」処理を繰り返す．

キューの実装をプリミティブな配列で行う場合：
リングバッファを使ってキューを実装する
circular queue
[head, tail)で示された範囲が現在格納している要素のリスト
*/

template <typename T>
class CircularQueue {
private:
    T* data;
    int head, tail;
    int size;

public:
    // initialize your data structure here. Set the size of the queue to be k.
    CircularQueue(int k)
    {
        data = new T[k];
        head = 0;
        tail = 0;
        size = k;
    }

    // Insert an element into the circular queue. Return true if the operation is successful.
    bool push(T val)
    {
        if (isFull())
            return false;
        data[tail] = val;
        tail = (tail + 1) % size;
        return true;
    }

    // Delete an element from the circular queue. Return true if the operation is successful.
    bool pop()
    {
        if (isEmpty())
            return false;
        head = (head + 1) % size;
        return true;
    }

    T front()
    {
        if (isEmpty())
            throw "exception\n";
        return data[head];
    }

    // checks whether the circular queue is empty or not
    bool isEmpty()
    {
        return head == tail;
    }

    // checks whether the circular queue is full or not
    bool isFull()
    {
        return head == (tail + 1) % size;
    }
};
int main()
{
    CircularQueue<vector<int>> que(1000);
    que.push(2);
    que.push(3);
    que.push(4);
    cout << que.front() << endl;
    que.pop();
    cout << que.front() << endl;
    que.pop();
    cout << que.front() << endl;
    que.pop();

    return 0;
}