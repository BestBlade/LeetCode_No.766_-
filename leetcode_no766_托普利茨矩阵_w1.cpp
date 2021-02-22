/* ------------------------------------------------------------------|
给你一个 m x n 的矩阵 matrix 。如果这个矩阵是托普利茨矩阵，返回 true ；否则，返回 false 。

如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵 。

 

示例 1：


输入：matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
输出：true
解释：
在上述矩阵中, 其对角线为:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。
各条对角线上的所有元素均相同, 因此答案是 True 。
示例 2：


输入：matrix = [[1,2],[2,2]]
输出：false
解释：
对角线 "[1, 2]" 上的元素不同。
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 20
0 <= matrix[i][j] <= 99
 

进阶：

如果矩阵存储在磁盘上，并且内存有限，以至于一次最多只能将矩阵的一行加载到内存中，该怎么办？
如果矩阵太大，以至于一次只能将不完整的一行加载到内存中，该怎么办？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/toeplitz-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*
*	执行用时：16 ms, 在所有 C++ 提交中击败了90.19%的用户
*	内存消耗：17 MB, 在所有 C++ 提交中击败了77.07%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//遍历法
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[i][j] != matrix[i - 1][j - 1]) {
                return false;
            }
        }
    }
    return true;
}

//进阶问题解法
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    if (m == 1 || n == 1) {
        return true;
    }
    vector<int> row;
    vector<int> col;
    for (int i = 0; i < m; i++) {
        row.emplace_back(matrix[i][0]);
    }
    for (int i = 0; i < n; i++) {
        col.emplace_back(matrix[0][i]);
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (j >= i) {
                if (matrix[i][j] != col[j - i]) {
                    return false;
                }
            }
            else {
                if (matrix[i][j] != row[i - j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> matrix = { {1,2,3,4},{5,1,2,3},{9,5,1,2} };
    isToeplitzMatrix(matrix);
}