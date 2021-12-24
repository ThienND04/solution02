#include<iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using lint = long long;

const size_t max_length = 200005;

struct ACM
{
    static const int root = 0;

    int total;
    int trie[max_length][26], tail_count[max_length], fail[max_length];
    lint sum[max_length], dp[max_length];

    ACM() : total(0)
    {
        memset(trie, 0, sizeof(trie));
        memset(tail_count, 0, sizeof(tail_count));
        memset(fail, 0, sizeof(fail));

        std::fill(sum, sum + max_length, 0);
        std::fill(dp, dp + max_length, -1);
    }

    inline int ascii(const char &c)
    {
        return (int)(c - 'a');
    }

    void insert(const char *s)
    {
        int len = strlen(s), cur = root;
        for (int i = 0; i < len; i++)
        {
            if (!trie[cur][ascii(s[i])])
            {
                trie[cur][ascii(s[i])] = ++total;
            }

            cur = trie[cur][ascii(s[i])];
        }

        tail_count[cur]++;
    }

    void build()
    {
        std::queue<int> queue;
        for (int i = 0; i < 26; i++)
        {
            if (trie[root][i])
            {
                queue.push(trie[root][i]);
            }
        }

        while (!queue.empty())
        {
            int cur = queue.front();
            queue.pop();

            for (int i = 0; i < 26; i++)
            {
                if (trie[cur][i])
                {
                    queue.push(trie[cur][i]);
                    fail[trie[cur][i]] = trie[fail[cur]][i];
                }
                else
                {
                    trie[cur][i] = trie[fail[cur]][i];
                }
            }
        }
    }

    lint search(const int &cur)
    {
        if (cur == root)
        {
            dp[cur] = 0;
        }
        else if (dp[cur] == -1)
        {
            dp[cur] = tail_count[cur] + search(fail[cur]);
        }

        return dp[cur];
    }

    void query(const char *s)
    {
        int len = strlen(s), cur = root;
        for (int i = 0; i < len; i++)
        {
            cur = trie[cur][ascii(s[i])];
            sum[i] = search(cur);
        }
    }
};

ACM left, right;

char str[max_length], temp[max_length];

int main()
{
    int count;
    scanf("%s%d", &str, &count);

    for (int i = 0; i < count; i++)
    {
        scanf("%s", &temp);

        int len = strlen(temp);
        left.insert(temp);
        std::reverse(temp, temp + len);
        right.insert(temp);
    }

    left.build();
    right.build();

    int len = strlen(str);

    left.query(str);
    std::reverse(str, str + len);
    right.query(str);

    lint res = 0;
    for (int i = 0; i < len - 1; i++)
    {
        res += left.sum[i] * right.sum[len - i - 2];
    }
    
    std::cout << res << std::endl;
    return 0;
}